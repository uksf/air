import sys
import numpy as np
import cv2
from PIL import Image
from scipy import ndimage as ndi
from skimage.morphology import skeletonize, remove_small_objects
from skimage.measure import find_contours

# Rebuilds a camo sheet at full detail from its baked (upscaled) version:
# crisp panel lines with a highlight edge, rivet rows, per-panel tone, light weathering,
# palette-smoothed markings, plus matching normal (_nohq, DirectX) and specular (_smdi) maps.
# usage: art.py <sheet> [seed]   reads <sheet>.png and <sheet>_mask.png
name = sys.argv[1]
rng = np.random.default_rng(int(sys.argv[2]) if len(sys.argv) > 2 else 7)
src = np.asarray(Image.open(name + '.png').convert('RGB')).astype(np.float32)
mask = np.asarray(Image.open(name + '_mask.png')) > 0
N = src.shape[0]
L = src @ np.array([0.299, 0.587, 0.114], np.float32)
sat = src.max(2) - src.min(2)

# markings: saturated colour plus white/black parts touching them
marking = ndi.binary_dilation((sat > 35) & mask, iterations=6)
marking = remove_small_objects(marking, max_size=60)

# panel lines: darker than the local background, thinned to a 1 px centre line
bg = cv2.medianBlur(L.astype(np.uint8), 21).astype(np.float32)
cand = ((bg - L) > 7) & mask & ~marking
inner = ndi.binary_erosion(mask, iterations=5)                    # drop island-outline artefacts
skel = skeletonize(cand & inner)
skel = remove_small_objects(skel, max_size=24, connectivity=2)
# trace the skeleton, straighten it to within ~1 px, and draw it anti-aliased at 2x
cs, _ = cv2.findContours(skel.astype(np.uint8), cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)
canvas = np.zeros((2 * N, 2 * N), np.uint8)
for c in cs:
    if len(c) < 12: continue
    a = cv2.approxPolyDP(c, 0.6, False)
    cv2.polylines(canvas, [a * 2], False, 255, 2, cv2.LINE_AA)
ink = cv2.resize(canvas.astype(np.float32) / 255, (N, N), interpolation=cv2.INTER_AREA)
ink = np.clip(ink * 1.5, 0, 1)
dist = ndi.distance_transform_edt(ink < 0.5).astype(np.float32)
hl = np.roll(np.roll(ink, 2, 0), 2, 1) * (1 - ink)                # lit lip on one side of the seam

# rivet rows: dots every 12 px along both sides of each seam
riv = np.zeros((N, N), np.float32)
for c in find_contours(dist, 5.5):
    if len(c) < 30: continue
    seg = np.r_[0, np.cumsum(np.hypot(*np.diff(c, axis=0).T))]
    for t in np.arange(6, seg[-1], 12):
        y, x = c[np.searchsorted(seg, t)]
        iy, ix = int(round(y)), int(round(x))
        if 0 <= iy < N and 0 <= ix < N and inner[iy, ix] and not marking[iy, ix]: riv[iy, ix] = 1
riv = cv2.GaussianBlur(riv, (0, 0), 0.8); riv /= max(riv.max(), 1e-6)

# base colour without lines; per-panel tone; low- and high-frequency weathering
base = cv2.medianBlur(src.astype(np.uint8), 25).astype(np.float32)
panels, n = ndi.label(mask & (dist > 2.5))
tone = np.r_[1.0, 1 + rng.uniform(-0.022, 0.022, n)].astype(np.float32)[panels]
tone = cv2.GaussianBlur(tone, (0, 0), 1.2)
low = cv2.GaussianBlur(rng.standard_normal((N, N)).astype(np.float32), (0, 0), 48); low /= np.abs(low).max()
fine = cv2.GaussianBlur(rng.standard_normal((N, N)).astype(np.float32), (0, 0), 0.9); fine /= np.abs(fine).max()
col = base * (tone * (1 + 0.018 * low + 0.012 * fine))[..., None]
col = col * (1 - 0.30 * ink[..., None]) + 18 * hl[..., None] - 17 * riv[..., None]

# markings: k-means palette, then each colour's coverage smoothed at 2x and the strongest wins
if marking.any():
    ys, xs = np.nonzero(marking)
    y0, y1, x0, x1 = ys.min(), ys.max() + 1, xs.min(), xs.max() + 1
    lab, nm = ndi.label(marking)
    for i, sl in enumerate(ndi.find_objects(lab)):
        reg = lab[sl] == i + 1
        px = src[sl][reg].reshape(-1, 3)
        k = int(min(6, max(2, len(np.unique((px // 24).astype(int), axis=0)))))
        _, lbl, cen = cv2.kmeans(px.astype(np.float32), k, None, (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.5), 4, cv2.KMEANS_PP_CENTERS)
        full = np.zeros(reg.shape, np.int32); full[reg] = lbl.ravel()
        h, w = reg.shape
        votes = []
        for j in range(k):
            ind = cv2.resize(((full == j) & reg).astype(np.float32), (w * 2, h * 2), interpolation=cv2.INTER_LINEAR)
            votes.append(cv2.GaussianBlur(ind, (0, 0), 2.0))
        # artwork with many small colour islands (badges) keeps its detail: sharpened, not flattened
        specks = sum(int(((np.bincount(ndi.label((full == j) & reg)[0].ravel())[1:]) < 30).sum()) for j in range(k))
        if specks > 25:
            blur = cv2.GaussianBlur(src[sl], (0, 0), 1.2)
            lo = np.clip(src[sl] * 1.6 - blur * 0.6, 0, 255)
            feather = cv2.GaussianBlur(reg.astype(np.float32), (0, 0), 1.0)[..., None]
            col[sl] = col[sl] * (1 - feather) + lo * feather
            continue
        win = np.argmax(np.stack(votes), 0)
        hi = cen[win]                                              # 2x render
        lo = cv2.resize(hi, (w, h), interpolation=cv2.INTER_AREA)
        feather = cv2.GaussianBlur(ndi.binary_erosion(reg, iterations=2).astype(np.float32), (0, 0), 1.0)[..., None]
        col[sl] = col[sl] * (1 - feather) + lo * feather
    print(f'{nm} markings')

# padding outside the islands takes the nearest island texel
idx = ndi.distance_transform_edt(~mask, return_distances=False, return_indices=True)
def pad(a): return a[idx[0], idx[1]]
co = pad(np.clip(col, 0, 255)).astype(np.uint8)

# normal map from a height field: seams recessed, rivet heads raised
H = cv2.GaussianBlur(-1.0 * ink + 0.55 * riv + 0.04 * fine, (0, 0), 0.6)
gx = cv2.Sobel(H, cv2.CV_32F, 1, 0, ksize=3) / 8; gy = cv2.Sobel(H, cv2.CV_32F, 0, 1, ksize=3) / 8
k = 3.0
nrm = np.dstack([-gx * k, gy * k, np.ones_like(H)])               # x right; DirectX y points down the image
nrm /= np.linalg.norm(nrm, axis=2, keepdims=True)
nohq = pad(((nrm * 0.5 + 0.5) * 255).astype(np.uint8))
# specular: R unused, G intensity, B glossiness; seams and rivets duller
spec = np.clip(122 - 55 * ink - 12 * riv + 8 * low, 0, 255)
gloss = np.clip(150 - 45 * ink - 10 * riv + 10 * low, 0, 255)
smdi = pad(np.dstack([np.full_like(spec, 255), spec, gloss]).astype(np.uint8))

Image.fromarray(co).save(name + '_art.png')
Image.fromarray(nohq).save(name.replace('_co', '') + '_nohq.png')
Image.fromarray(smdi).save(name.replace('_co', '') + '_smdi.png')
print(f'{name}: {int(skel.sum())} seam px, {n} panels, {int((riv > 0.5).sum())} rivets')
