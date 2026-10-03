import numpy as np
from scipy.spatial import cKDTree
from scipy.ndimage import gaussian_filter

# Draws 3D points onto a texture target. Each point lands on the nearest texel of the target surface
# (within max_dist, facing the same way) at sub-texel precision, and is splatted at 2x supersampling.
from paths import WORK as W, SRC
N = 4096
_trees = {}


def target(name):
    if name not in _trees:
        g = dict(np.load(W + f'g_{name}.npz'))
        g['tree'] = cKDTree(g['P'])
        _trees[name] = g
    return _trees[name]


def project(name, P, Nrm=None, max_dist=0.02, min_dot=0.8, signed=False):
    """3D points -> (row, col) float pixel positions on the target, for points that land."""
    g = target(name)
    d, j = g['tree'].query(P, k=1, workers=-1, distance_upper_bound=max_dist)
    ok = np.isfinite(d)
    j = np.where(ok, j, 0)
    if Nrm is not None:
        dot = (g['N'][j] * Nrm).sum(1)
        ok &= (dot if signed else np.abs(dot)) > min_dot
    j = j[ok]; Q = P[ok] - g['P'][j]
    Pu, Pv = g['Pu'][j], g['Pv'][j]
    # least squares Q = du*Pu + dv*Pv
    a, b, c = (Pu * Pu).sum(1), (Pu * Pv).sum(1), (Pv * Pv).sum(1)
    e, f = (Q * Pu).sum(1), (Q * Pv).sum(1)
    det = np.maximum(a * c - b * b, 1e-20)
    du, dv = (c * e - b * f) / det, (a * f - b * e) / det
    row = g['r'][j] + 0.5 + dv * N; col = g['c'][j] + 0.5 + du * N
    return row, col, ok


def splat(row, col, weight=1.0, sigma=0.55, ss=2):
    """Sum of small Gaussians at the points, at ss x resolution, returned at N x N."""
    M = N * ss
    acc = np.zeros((M, M), np.float32)
    y = row * ss - 0.5; x = col * ss - 0.5
    y0 = np.floor(y).astype(int); x0 = np.floor(x).astype(int); fy = y - y0; fx = x - x0
    w = np.broadcast_to(np.float32(weight), y.shape)
    for dy, wy in ((0, 1 - fy), (1, fy)):
        for dx, wx in ((0, 1 - fx), (1, fx)):
            yy = np.clip(y0 + dy, 0, M - 1); xx = np.clip(x0 + dx, 0, M - 1)
            np.add.at(acc, (yy, xx), (w * wy * wx).astype(np.float32))
    acc = gaussian_filter(acc, sigma * ss)
    return acc.reshape(N, ss, N, ss).mean((1, 3))


def coverage(name):
    g = target(name)
    m = np.zeros((N, N), bool); m[g['r'], g['c']] = True
    return m
