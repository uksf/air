import os, sys, numpy as np
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from plan_lib import load
def compute(P, N, UV, faces):
    # per-vertex accumulated gradients of u and v, projected to the tangent plane
    du = np.zeros_like(P); dv = np.zeros_like(P)
    for f in faces:
        for k in range(1, len(f) - 1):
            a, b, c = f[0], f[k], f[k + 1]
            e1, e2 = P[b] - P[a], P[c] - P[a]
            t1, t2 = UV[b] - UV[a], UV[c] - UV[a]
            det = t1[0] * t2[1] - t2[0] * t1[1]
            if abs(det) < 1e-14: continue
            Tu = (e1 * t2[1] - e2 * t1[1]) / det          # dP/du
            Tv = (e2 * t1[0] - e1 * t2[0]) / det          # dP/dv
            w = np.linalg.norm(np.cross(e1, e2))
            for v in (a, b, c): du[v] += Tu * w; dv[v] += Tv * w
    def ortho(x):
        x = x - (x * N).sum(1)[:, None] * N
        n = np.linalg.norm(x, axis=1); n[n == 0] = 1
        return x / n[:, None]
    return ortho(du), ortho(dv)
if __name__ == '__main__':
    d = np.loadtxt('v0.txt'); P, N, S, Tt, UV = d[:, :3], d[:, 3:6], d[:, 6:9], d[:, 9:12], d[:, 12:14]
    _, _, F = load('old.obj')
    faces = [f['v'] for f in F if f['mat'] == 'top.paa']
    used = sorted({v for f in faces for v in f})
    Nn = N / np.maximum(np.linalg.norm(N, axis=1), 1e-9)[:, None]
    for name, sgnN in (('N', 1), ('-N', -1)):
        Tu, Tv = compute(P, Nn * sgnN, UV, faces)
        for la, X in (('S', S), ('T', Tt)):
            for lb, Y in (('dP/du', Tu), ('dP/dv', Tv)):
                c = (X[used] * Y[used]).sum(1) / np.maximum(np.linalg.norm(X[used], axis=1), 1e-9)
                print(f'{name:2} {la} vs {lb}: median cos {np.median(c):+.3f}, |cos|>0.9: {(abs(c) > 0.9).mean():.2f}')
