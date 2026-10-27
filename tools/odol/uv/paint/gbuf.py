import os, sys, numpy as np
from paths import WORK as W, SRC
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from plan_lib import load

N = 4096


def uv_frames(P0, P1, P2, U0, U1, U2):
    e1, e2 = P1 - P0, P2 - P0
    d1, d2 = (U1 - U0) * [1, -1], (U2 - U0) * [1, -1]
    det = d1[:, 0] * d2[:, 1] - d2[:, 0] * d1[:, 1]
    det = np.where(np.abs(det) < 1e-12, 1e-12, det)
    return (e1 * d2[:, 1:2] - e2 * d1[:, 1:2]) / det[:, None], (e2 * d1[:, 0:1] - e1 * d2[:, 0:1]) / det[:, None]


def corner_normals(V, F, crease_deg=35):
    key = np.unique(np.round(V, 4), axis=0, return_inverse=True)[1].ravel()
    fn = []
    for f in F:
        p = V[f['v']]; n = np.zeros(3)
        for i in range(1, len(p) - 1): n += np.cross(p[i] - p[0], p[i + 1] - p[0])
        fn.append(n)
    fn = np.array(fn); unit = fn / np.maximum(np.linalg.norm(fn, axis=1, keepdims=True), 1e-12)
    at = {}
    for fi, f in enumerate(F):
        for v in f['v']: at.setdefault(key[v], []).append(fi)
    cos = np.cos(np.radians(crease_deg)); out = []
    for fi, f in enumerate(F):
        cn = []
        for v in f['v']:
            nb = np.array(at[key[v]]); nb = nb[unit[nb] @ unit[fi] > cos]
            s = fn[nb].sum(0); cn.append(s / max(np.linalg.norm(s), 1e-12))
        out.append(np.array(cn))
    return out


def build(obj, mats):
    V, T, F = load(obj); V = np.array(V); T = np.array(T)
    CN = corner_normals(V, F)
    out = {k: [] for k in ('r', 'c', 'P', 'N', 'Ns', 'Pu', 'Pv', 'f')}
    for fi, f in enumerate(F):
        if f['mat'] not in mats: continue
        v = f['v']
        for i in range(1, len(v) - 1):
            tri = [v[0], v[i], v[i + 1]]; cn = CN[fi][[0, i, i + 1]]
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
            out['N'].append(np.repeat((n / ln)[None], k, 0))
            ns = l1[m, None] * cn[0] + l2[m, None] * cn[1] + l3[m, None] * cn[2]
            out['Ns'].append(ns / np.maximum(np.linalg.norm(ns, axis=1, keepdims=True), 1e-12)); out['Pu'].append(np.repeat(pu, k, 0)); out['Pv'].append(np.repeat(pv, k, 0))
            out['f'].append(np.full(k, fi))
    g = {k: np.concatenate(x) for k, x in out.items()}
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
