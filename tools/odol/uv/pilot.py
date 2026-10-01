import sys
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
from plan_lib import load

# Builds the pilot-view LOD's textures on the original UV layout from the two new sheets.
# The pilot LOD kept its UVs, so every original-layout texel is looked up through the LOD 0 face
# that covered it before the repack: same old UV, new UV and sheet from that face.
# usage: pilot.py old.obj new.obj <suffix>   e.g. "_co" reads camo_upper_co_art.png / camo_lower_co_art.png
old_obj, new_obj, kind = sys.argv[1:4]
N = 4096
src = {'top.paa': f'camo_upper{kind}', 'camo_lower_co.paa': f'camo_lower{kind}'}
sheets = {k: np.asarray(Image.open(v + ('_art.png' if kind == '_co' else '.png')).convert('RGB')).astype(np.float32) for k, v in src.items()}
_, To, Fo = load(old_obj)
_, Tn, Fn = load(new_obj)
out = np.zeros((N, N, 3), np.float32)
hit = np.zeros((N, N), bool)
key = lambda f: tuple(sorted(f['v']))
for fo, fn in zip(sorted(Fo, key=key), sorted(Fn, key=key)):
    if fn['mat'] not in sheets: continue
    sheet = sheets[fn['mat']]
    vs = fn['v']
    for k in range(1, len(vs) - 1):
        t = (vs[0], vs[k], vs[k + 1])
        P = np.array([((To[v][0] % 1) * N, ((1 - To[v][1]) % 1) * N) for v in t])
        if np.ptp(P[:, 0]) > N / 2 or np.ptp(P[:, 1]) > N / 2: continue     # wraps the tile edge; neighbours cover it
        Q = np.array([(Tn[v][0] * N, (1 - Tn[v][1]) * N) for v in t])
        x0, y0 = np.maximum(np.floor(P.min(0)).astype(int), 0); x1, y1 = np.minimum(np.ceil(P.max(0)).astype(int), N - 1)
        if x1 < x0 or y1 < y0: continue
        ys, xs = np.mgrid[y0:y1 + 1, x0:x1 + 1]
        px = xs.ravel() + .5; py = ys.ravel() + .5
        (ax, ay), (bx, by), (cx, cy) = P
        d = (by - cy) * (ax - cx) + (cx - bx) * (ay - cy)
        if abs(d) < 1e-9: continue
        l1 = ((by - cy) * (px - cx) + (cx - bx) * (py - cy)) / d
        l2 = ((cy - ay) * (px - cx) + (ax - cx) * (py - cy)) / d
        l3 = 1 - l1 - l2
        m = (l1 >= -0.02) & (l2 >= -0.02) & (l3 >= -0.02)
        if not m.any(): continue
        u = l1[m] * Q[0, 0] + l2[m] * Q[1, 0] + l3[m] * Q[2, 0]
        v = l1[m] * Q[0, 1] + l2[m] * Q[1, 1] + l3[m] * Q[2, 1]
        X = px[m].astype(int); Y = py[m].astype(int)
        out[Y, X] = sheet[np.clip(v.astype(int), 0, N - 1), np.clip(u.astype(int), 0, N - 1)]
        hit[Y, X] = True
idx = ndi.distance_transform_edt(~hit, return_distances=False, return_indices=True)
out = out[idx[0], idx[1]]
Image.fromarray(out.astype(np.uint8)).save(f'camo_pilot{kind}{"_art" if kind == "_co" else ""}.png')
print(f'camo_pilot{kind}: {hit.mean() * 100:.1f}% of texels from LOD 0 faces')
