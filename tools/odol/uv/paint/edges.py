import os, sys, numpy as np
from paths import WORK as W, SRC
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from plan_lib import load

# Part outlines from our own model: camo-face edges that are open (no other face shares the
# position-welded edge) or that border a face with another texture. Seams cut for UV layout are
# welded back by position, so they never count. Points every 1.5 mm, with the face normal.
CAMO = {'top.paa', 'camo_lower_co.paa'}
V, T, F = load(W + 't3.obj'); V = np.array(V)
key = np.unique(np.round(V / 0.0005).astype(np.int64), axis=0, return_inverse=True)[1].ravel()
edges = {}
for fi, f in enumerate(F):
    v = f['v']
    for k in range(len(v)):
        a, b = key[v[k]], key[v[(k + 1) % len(v)]]
        if a != b: edges.setdefault((min(a, b), max(a, b)), []).append((fi, v[k], v[(k + 1) % len(v)]))
# separate parts (control surfaces, canards, fin, pylons, doors) are closed meshes: outline them on
# their sharp edges. The largest component is the airframe itself.
import scipy.sparse as sp
from scipy.sparse.csgraph import connected_components
cf = [i for i, f in enumerate(F) if f['mat'] in CAMO]
ee = np.array([(key[F[i]['v'][k]], key[F[i]['v'][(k + 1) % len(F[i]['v'])]]) for i in cf for k in range(len(F[i]['v']))])
_, lab = connected_components(sp.coo_matrix((np.ones(len(ee)), (ee[:, 0], ee[:, 1])), shape=(key.max() + 1,) * 2), directed=False)
main = np.bincount(lab[key[[F[i]['v'][0] for i in cf]]]).argmax()


def fnorm(fi):
    v = F[fi]['v']; n = np.cross(V[v[1]] - V[v[0]], V[v[2]] - V[v[0]]); l = np.linalg.norm(n)
    return n / l if l > 1e-12 else n


pts, nrm, kinds = [], [], {'open': 0, 'material': 0, 'part': 0}
for e, fs in edges.items():
    camo = [x for x in fs if F[x[0]]['mat'] in CAMO]
    if not camo: continue
    if len(fs) == 1: kind = 'open'
    elif any(F[x[0]]['mat'] not in CAMO and F[x[0]]['mat'] != 'none' for x in fs): kind = 'material'
    elif lab[e[0]] != main and len(camo) == 2 and fnorm(camo[0][0]) @ fnorm(camo[1][0]) < 0.7: kind = 'part'
    else: continue
    fi, a, b = camo[0]
    v = F[fi]['v']; n = np.cross(V[v[1]] - V[v[0]], V[v[2]] - V[v[0]]); ln = np.linalg.norm(n)
    if ln < 1e-12: continue
    L = np.linalg.norm(V[b] - V[a]); k = max(2, int(L / 0.0015) + 1)
    t = np.linspace(0, 1, k)[:, None]
    pts.append(V[a] + t * (V[b] - V[a])); nrm.append(np.repeat((n / ln)[None], k, 0)); kinds[kind] += 1
P = np.concatenate(pts); Nn = np.concatenate(nrm)
np.savez(W + 'edges3d.npz', P=P.astype(np.float32), N=Nn.astype(np.float32))
print('edges', kinds, 'points', len(P))
