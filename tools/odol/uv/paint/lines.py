import os, sys, json, numpy as np
from PIL import Image
from scipy.spatial import cKDTree
from scipy.ndimage import gaussian_filter, label, zoom
from skimage.morphology import black_tophat, disk, skeletonize
from paths import WORK as W, SRC
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from plan_lib import load

# RKSL panel lines as 3D points: thin dark lines on the RKSL colour sheet are skeletonised at 3x,
# carried through the RKSL model to 3D, and moved into our model space by the RKSL->EAWS fit.
# Output lines3d.npz: P (points in our space), Nrk (RKSL face normal there).
UP = 3
A = json.load(open(SRC + 'align.json')); s, R, t = A['s'], np.array(A['R']), np.array(A['t'])

col = np.asarray(Image.open(SRC + 'rksl/png/efa_ext1_co.png').convert('L'), np.float32)
big = zoom(col, UP, order=3)
th = black_tophat(big, disk(2 * UP))
mask = th > 14
sk = skeletonize(mask)
lab, n = label(sk, structure=np.ones((3, 3)))
size = np.bincount(lab.ravel()); keep = size >= 30 * UP; keep[0] = False   # drop rivets and specks
# lettering has many stroke ends for its length; panel lines and hatch outlines have few
from scipy.ndimage import convolve
nb = convolve(sk.astype(np.uint8), np.ones((3, 3), np.uint8), mode='constant') - 1
ends = np.bincount(lab[(sk) & (nb == 1)], minlength=n + 1)
keep &= ends / np.maximum(size, 1) * 100 * UP < 2.0
sk = keep[lab]
# vectorise the traced lines into straight segments (keeps real joggles, drops pixel wobble) and
# drop zig-zag pieces such as leftover lettering and symbols
import vectorise as VZ
LX, LY, LID, _st = VZ.vectorise(sk, tol=1.5 * UP, step=1.0, max_turn_density=1 / (6.0 * UP))
ltree = cKDTree(np.c_[LX, LY])
print('vector points', len(LX))
Image.fromarray((sk * 255).astype(np.uint8)).resize((2048, 2048), Image.BOX).save(W + 'rk_lines.png')
print('skeleton pixels', int(sk.sum()), 'components', int(keep.sum()))

V, T, F = load(SRC + 'rksl/rk0.obj'); V = np.array(V); T = np.array(T)
M = sk.shape[0]
# RKSL winding is inconsistent, but each UV island is one skin. Orient every island as a whole by
# an area-weighted vote of its faces against the nearest surface of our model (consistent winding).
skin = [i for i, f in enumerate(F) if f['mat'] in ('efa_ext1_co.paa', 'none')]
par = {}
def find(x):
    par.setdefault(x, x)
    while par[x] != x: par[x] = par[par[x]]; x = par[x]
    return x
for i in skin:
    for v in F[i]['v'][1:]: par[find(v)] = find(F[i]['v'][0])
gs = [dict(np.load(W + f'g_{t}.npz')) for t in ('upper', 'lower')]
GP = np.concatenate([g['P'] for g in gs])[::7]; GN = np.concatenate([g['N'] for g in gs])[::7]
gt = cKDTree(GP)
Vt = s * V @ R.T + t
cent, fn, isl = [], [], []
for i in skin:
    v = F[i]['v']; p = Vt[v]
    n_ = sum(np.cross(p[k] - p[0], p[k + 1] - p[0]) for k in range(1, len(v) - 1))
    cent.append(p.mean(0)); fn.append(n_); isl.append(find(v[0]))
cent = np.array(cent); fn = np.array(fn); isl = np.array(isl)
d, j = gt.query(cent, workers=-1)
w = np.linalg.norm(fn, axis=1) * (d < 0.08)
vote = np.sign((fn * GN[j]).sum(1)) * w
flip = {}
for k in np.unique(isl):
    m = isl == k; flip[k] = vote[m].sum() < 0
print('RKSL islands', len(flip), 'flipped', sum(flip.values()))
pts, nrm = [], []
for i in skin:
    f = F[i]
    v = f['v']
    sgn = -1.0 if flip[find(v[0])] else 1.0
    for i in range(1, len(v) - 1):
        tri = [v[0], v[i], v[i + 1]]
        uv = np.c_[T[tri, 0] % 1 * M, (1 - T[tri, 1] % 1) * M]
        x0, y0 = np.maximum(np.floor(uv.min(0)).astype(int), 0); x1, y1 = np.minimum(np.ceil(uv.max(0)).astype(int), M - 1)
        if x1 < x0 or y1 < y0: continue
        cand = ltree.query_ball_point([(x0 + x1) / 2 + .5, (y0 + y1) / 2 + .5], r=np.hypot(x1 - x0, y1 - y0) / 2 + 1)
        if not cand: continue
        cand = np.array(cand); qx = LX[cand]; qy = LY[cand]
        (ax, ay), (bx, by), (cx, cy) = uv
        d = (by - cy) * (ax - cx) + (cx - bx) * (ay - cy)
        if abs(d) < 1e-9: continue
        l1 = ((by - cy) * (qx - cx) + (cx - bx) * (qy - cy)) / d
        l2 = ((cy - ay) * (qx - cx) + (ax - cx) * (qy - cy)) / d
        l3 = 1 - l1 - l2
        m = (l1 >= -0.02) & (l2 >= -0.02) & (l3 >= -0.02)
        if not m.any(): continue
        p = V[tri]
        nn = np.cross(p[1] - p[0], p[2] - p[0]); ln = np.linalg.norm(nn)
        if ln < 1e-12: continue
        pts.append(l1[m, None] * p[0] + l2[m, None] * p[1] + l3[m, None] * p[2])
        nrm.append(np.repeat((sgn * nn / ln)[None], int(m.sum()), 0))
P = np.concatenate(pts); Nr = np.concatenate(nrm)
P = s * P @ R.T + t; Nr = Nr @ R.T
np.savez(W + 'lines3d.npz', P=P.astype(np.float32), N=Nr.astype(np.float32))
print('3D line points', len(P))

# drop fragments and the RKSL symbols and stencil scribbles: short clusters anywhere, and dense
# compact clusters on the wings (a straight line carries about 1000 points per metre)
from scipy.sparse import coo_matrix
from scipy.sparse.csgraph import connected_components
pr = cKDTree(P).query_pairs(0.012, output_type='ndarray')
nc, lab = connected_components(coo_matrix((np.ones(len(pr)), (pr[:, 0], pr[:, 1])), shape=(len(P),) * 2), directed=False)
lo = np.full((nc, 3), np.inf); hi = np.full((nc, 3), -np.inf); np.minimum.at(lo, lab, P); np.maximum.at(hi, lab, P)
ext = np.linalg.norm(hi - lo, axis=1); cen = (lo + hi) / 2; cnt = np.bincount(lab, minlength=nc)
drop = (ext < 0.25) | ((np.abs(cen[:, 0]) > 1.4) & (ext < 0.6) & (cnt / np.maximum(ext, 1e-3) > 3000))
keep = ~drop[lab]
np.savez(W + 'lines3d_f.npz', P=P[keep].astype(np.float32), N=Nr[keep].astype(np.float32))
print('kept', keep.sum(), 'of', len(P), 'line points')
