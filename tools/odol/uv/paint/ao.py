import os, sys, numpy as np
from scipy.ndimage import minimum_filter
from paths import WORK as W, SRC
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from plan_lib import load

# Ambient occlusion per texel from our own LOD 0: orthographic depth maps from many directions
# (dense surface points splatted with a minimum), then each texel tests whether it is the nearest
# surface towards each direction. Saves ao_<target>.npy as a flat array matching the gbuffer.
H = W
SKIP = {'chute.paa', 'su35_afterburner_ca.paa', 'su35_engine_fire_ca.paa', 'av8b_glass_ca.paa', 'none',
        'car_light_flare2.paa', 'burner.paa'}
V, T, F = load(W + 't3.obj'); V = np.array(V)
tri = np.array([(f['v'][0], f['v'][k], f['v'][k + 1]) for f in F if f['mat'] not in SKIP for k in range(1, len(f['v']) - 1)])
a, b, c = V[tri[:, 0]], V[tri[:, 1]], V[tri[:, 2]]
area = np.linalg.norm(np.cross(b - a, c - a), axis=1) / 2
rng = np.random.default_rng(3)
n = 10_000_000
k = rng.choice(len(tri), n, p=area / area.sum()); r1, r2 = rng.random(n), rng.random(n); s = np.sqrt(r1)
S = ((1 - s)[:, None] * a[k] + (s * (1 - r2))[:, None] * b[k] + (s * r2)[:, None] * c[k]).astype(np.float32)
lo, hi = V.min(0) - 0.5, V.max(0) + 0.5
R = 2048; px = (hi - lo).max() * 1.75 / R            # depth map pixel, covers any rotation
centre = (lo + hi) / 2


def dirs(m):
    i = np.arange(m) + 0.5; phi = np.arccos(1 - 2 * i / m); th = np.pi * (1 + 5 ** 0.5) * i
    return np.c_[np.cos(th) * np.sin(phi), np.cos(phi), np.sin(th) * np.sin(phi)]


def basis(d):
    u = np.cross(d, [0, 1, 0] if abs(d[1]) < 0.9 else [1, 0, 0]); u /= np.linalg.norm(u)
    return u, np.cross(d, u)


def bake(targets, m=160, bias=0.012):
    acc = {t: np.zeros(len(g['P']), np.float32) for t, g in targets.items()}
    wsum = {t: np.zeros(len(g['P']), np.float32) for t, g in targets.items()}
    for d in dirs(m):
        u, w = basis(d)
        q = S - centre
        x = np.clip((q @ u / px + R / 2).astype(int), 0, R - 1); y = np.clip((q @ w / px + R / 2).astype(int), 0, R - 1)
        depth = np.full((R, R), np.inf, np.float32)
        np.minimum.at(depth, (y, x), -(q @ d))          # distance from a camera far along +d
        for t, g in targets.items():
            P, N = g['P'], g['N']
            cos = N @ d
            m_ = cos > 0
            q = P[m_] + N[m_] * 0.03 - centre             # normal offset against self-occlusion
            xx = np.clip((q @ u / px + R / 2).astype(int), 0, R - 1); yy = np.clip((q @ w / px + R / 2).astype(int), 0, R - 1)
            vis = (-(q @ d)) <= depth[yy, xx] + bias
            acc[t][m_] += cos[m_] * vis; wsum[t][m_] += cos[m_]
    return {t: acc[t] / np.maximum(wsum[t], 1e-6) for t in targets}


if __name__ == '__main__':
    tg = {t: dict(np.load(H + f'g_{t}.npz')) for t in (sys.argv[1:] or ['upper', 'lower', 'pilot'])}
    res = bake(tg)
    for t, v in res.items():
        np.save(H + f'ao_{t}.npy', v.astype(np.float32)); print(t, 'ao p5/p50/p95', np.percentile(v, [5, 50, 95]).round(3))
