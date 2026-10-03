import os, sys, numpy as np
from paths import WORK as W, SRC
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from plan_lib import load

# Per-texel geometry for one texture target: every texel covered by the given materials gets its
# 3D position (model file space: +X port, +Y up, +Z aft), face normal, and dP/du, dP/dv (v down
# the image). Row = (1 - v) * N, col = u * N. Saved as npz of flat arrays.
N = 4096


def uv_frames(P0, P1, P2, U0, U1, U2):
    e1, e2 = P1 - P0, P2 - P0
    d1, d2 = (U1 - U0) * [1, -1], (U2 - U0) * [1, -1]
    det = d1[:, 0] * d2[:, 1] - d2[:, 0] * d1[:, 1]
    det = np.where(np.abs(det) < 1e-12, 1e-12, det)
    return (e1 * d2[:, 1:2] - e2 * d1[:, 1:2]) / det[:, None], (e2 * d1[:, 0:1] - e1 * d2[:, 0:1]) / det[:, None]


def build(obj, mats):
    V, T, F = load(obj); V = np.array(V); T = np.array(T)
    out = {k: [] for k in ('r', 'c', 'P', 'N', 'Pu', 'Pv', 'f')}
    for fi, f in enumerate(F):
        if f['mat'] not in mats: continue
        v = f['v']
        for i in range(1, len(v) - 1):
            tri = [v[0], v[i], v[i + 1]]
            uv = np.c_[T[tri, 0] * N, (1 - T[tri, 1]) * N]; p3 = V[tri]
            x0, y0 = np.maximum(np.floor(uv.min(0)).astype(int), 0); x1, y1 = np.minimum(np.ceil(uv.max(0)).astype(int), N - 1)
            if x1 < x0 or y1 < y0: continue
            ys, xs = np.mgrid[y0:y1 + 1, x0:x1 + 1]; qx = xs.ravel() + .5; qy = ys.ravel() + .5
            (ax, ay), (bx, by), (cx, cy) = uv
            d = (by - cy) * (ax - cx) + (cx - bx) * (ay - cy)
            if abs(d) < 1e-12: continue
            l1 = ((by - cy) * (qx - cx) + (cx - bx) * (qy - cy)) / d
            l2 = ((cy - ay) * (qx - cx) + (ax - cx) * (qy - cy)) / d
            l3 = 1 - l1 - l2
            m = (l1 >= -1e-3) & (l2 >= -1e-3) & (l3 >= -1e-3)
            if not m.any(): continue
            n = np.cross(p3[1] - p3[0], p3[2] - p3[0]); ln = np.linalg.norm(n)
            if ln < 1e-12: continue
            pu, pv = uv_frames(p3[0:1], p3[1:2], p3[2:3], T[tri[0]:tri[0] + 1], T[tri[1]:tri[1] + 1], T[tri[2]:tri[2] + 1])
            k = int(m.sum())
            out['r'].append(ys.ravel()[m]); out['c'].append(xs.ravel()[m])
            out['P'].append(l1[m, None] * p3[0] + l2[m, None] * p3[1] + l3[m, None] * p3[2])
            out['N'].append(np.repeat((n / ln)[None], k, 0)); out['Pu'].append(np.repeat(pu, k, 0)); out['Pv'].append(np.repeat(pv, k, 0))
            out['f'].append(np.full(k, fi))
    g = {k: np.concatenate(x) for k, x in out.items()}
    # one record per texel: the last face written wins, as in a rasteriser
    key = g['r'].astype(np.int64) * N + g['c']
    _, last = np.unique(key[::-1], return_index=True); keep = len(key) - 1 - last
    return {k: (x[keep].astype(np.float32) if x.dtype.kind == 'f' else x[keep]) for k, x in g.items()}


if __name__ == '__main__':
    H = W
    for name, obj, mats in (('upper', H + 't3.obj', {'top.paa'}), ('lower', H + 't3.obj', {'camo_lower_co.paa'}),
                            ('pilot', H + 'p3.obj', {'top.paa'})):
        g = build(obj, mats)
        np.savez(W + 'g_' + name + '.npz', **g)
        print(name, 'texels', len(g['r']), f"{len(g['r']) / N / N:.1%}")
