import numpy as np
from scipy.ndimage import convolve

# Skeleton -> straight polylines. Branches run between end points and junctions; each branch is
# simplified with Douglas-Peucker and resampled every `step` pixels. Returns float (x, y) points
# (pixel centres at +0.5) and a per-point branch id.
NB = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]


def branches(sk):
    deg = convolve(sk.astype(np.uint8), np.ones((3, 3), np.uint8), mode='constant') - 1
    deg = deg * sk
    node = sk & (deg != 2)
    H, W = sk.shape
    seen_edge = set()
    out = []

    def nbrs(y, x):
        for dy, dx in NB:
            yy, xx = y + dy, x + dx
            if 0 <= yy < H and 0 <= xx < W and sk[yy, xx]: yield yy, xx

    starts = list(zip(*np.nonzero(node)))
    for y0, x0 in starts:
        for y1, x1 in nbrs(y0, x0):
            e = ((y0, x0), (y1, x1))
            if e in seen_edge: continue
            path = [(y0, x0)]; py, px, y, x = y0, x0, y1, x1
            while True:
                path.append((y, x)); seen_edge.add(((py, px), (y, x))); seen_edge.add(((y, x), (py, px)))
                if node[y, x]: break
                nxt = [p for p in nbrs(y, x) if p != (py, px) and ((y, x), p) not in seen_edge]
                if not nxt: break
                py, px, (y, x) = y, x, nxt[0]
            out.append(np.array(path, np.float32))
    # closed loops without nodes
    rest = sk.copy()
    for p in out: rest[p[:, 0].astype(int), p[:, 1].astype(int)] = False
    while rest.any():
        y0, x0 = map(int, np.argwhere(rest)[0])
        path = [(y0, x0)]; rest[y0, x0] = False; y, x = y0, x0
        while True:
            nxt = [p for p in nbrs(y, x) if rest[p]]
            if not nxt: break
            y, x = nxt[0]; rest[y, x] = False; path.append((y, x))
        if len(path) > 2: out.append(np.array(path + [path[0]], np.float32))
    return out


def dp(P, tol):
    if len(P) < 3: return P
    a, b = P[0], P[-1]; d = b - a; L = np.hypot(*d)
    if L < 1e-9: dist = np.hypot(*(P - a).T)
    else: dist = np.abs(d[0] * (P[:, 1] - a[1]) - d[1] * (P[:, 0] - a[0])) / L
    i = int(dist.argmax())
    if dist[i] <= tol: return np.array([a, b])
    return np.vstack([dp(P[:i + 1], tol)[:-1], dp(P[i:], tol)])


def vectorise(sk, tol=4.0, step=1.0, max_turn_density=None):
    pts, ids, stats = [], [], []
    for k, br in enumerate(branches(sk)):
        s = dp(br, tol)
        seg = np.diff(s, axis=0); L = np.hypot(seg[:, 0], seg[:, 1]).sum()
        stats.append((len(s), L))
        if max_turn_density and len(s) > 3 and (len(s) - 1) / max(L, 1) > max_turn_density: continue
        for p, q in zip(s[:-1], s[1:]):
            n = max(1, int(np.ceil(np.hypot(*(q - p)) / step)))
            t = np.linspace(0, 1, n, endpoint=False)[:, None]
            pts.append(p + t * (q - p)); ids.append(np.full(n, k))
        pts.append(s[-1:]); ids.append(np.array([k]))
    P = np.concatenate(pts) + 0.5
    return P[:, 1], P[:, 0], np.concatenate(ids), stats
