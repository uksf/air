import os, sys, json
import numpy as np
import scipy.sparse as sp
import scipy.sparse.linalg as sla
import scipy.sparse.csgraph
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from plan_lib import load, islands as islands_pos

def islands(V, T, F, pred):
    # islands by shared vertex index only: split vertices (hard edges) become free seams
    par = {}
    def find(x):
        par.setdefault(x, x)
        while par[x] != x: par[x] = par[par[x]]; x = par[x]
        return x
    idx = [i for i, f in enumerate(F) if pred(f)]
    for i in idx:
        for v in F[i]['v'][1:]: par[find(v)] = find(F[i]['v'][0])
    comp = {}
    for i in idx: comp.setdefault(find(F[i]['v'][0]), []).append(i)
    return [dict(faces=fs, verts=sorted({v for i in fs for v in F[i]['v']})) for fs in comp.values()]

# Re-flattens every camo UV island of LOD 0: LSCM start, ARAP refine, in metres.
# Island membership and seams stay as they are, so no vertex is added or split.

def local_frames(P, W):
    a, b, c = P[W[:, 0]], P[W[:, 1]], P[W[:, 2]]
    e1 = b - a; e2 = c - a
    n = np.cross(e1, e2); A = np.linalg.norm(n, axis=1) / 2
    x = e1 / np.linalg.norm(e1, axis=1)[:, None]
    y = np.cross(n / (2 * A)[:, None], x)
    q = np.zeros((len(W), 3, 2))
    q[:, 1] = np.c_[(e1 * x).sum(1), (e1 * y).sum(1)]
    q[:, 2] = np.c_[(e2 * x).sum(1), (e2 * y).sum(1)]
    return q, A

def grad_op(q, A, W, n):
    # rows 2t, 2t+1: d/dx and d/dy of a linear function on triangle t
    rows, cols, vals = [], [], []
    for j in range(3):
        o1 = q[:, (j + 1) % 3]; o2 = q[:, (j + 2) % 3]
        ed = o2 - o1                                            # edge opposite j
        g = np.c_[-ed[:, 1], ed[:, 0]] / (2 * A)[:, None]       # rotated, scaled
        # orientation: q is counter-clockwise by construction, so g points into the triangle
        t = np.arange(len(W))
        rows += [2 * t, 2 * t + 1]; cols += [W[:, j], W[:, j]]; vals += [g[:, 0], g[:, 1]]
    return sp.csr_matrix((np.concatenate(vals), (np.concatenate(rows), np.concatenate(cols))), shape=(2 * len(W), n))

def lscm(P, W):
    n = len(P); q, A = local_frames(P, W); G = grad_op(q, A, W, n)
    Gx, Gy = G[0::2], G[1::2]
    s = sp.diags(np.sqrt(A))
    # conformal: grad v = rot90(grad u)  ->  u_x - v_y = 0, u_y + v_x = 0
    M = sp.vstack([sp.hstack([s @ Gx, -s @ Gy]), sp.hstack([s @ Gy, s @ Gx])]).tocsc()
    # pin the two farthest-apart vertices along the principal axis
    c = P - P.mean(0); ax = np.linalg.svd(c, full_matrices=False)[2][0]; d = c @ ax
    i0, i1 = int(d.argmin()), int(d.argmax()); L = np.linalg.norm(P[i1] - P[i0])
    fixed = {i0: (0.0, 0.0), i1: (L, 0.0)}
    free = np.array([i for i in range(n) if i not in fixed])
    idx_free = np.r_[free, free + n]; idx_fix = np.array([i0, i1, i0 + n, i1 + n])
    val_fix = np.array([0.0, L, 0.0, 0.0])
    rhs = -(M[:, idx_fix] @ val_fix)
    Mf = M[:, idx_free]
    N_ = (Mf.T @ Mf).tocsc(); N_ = N_ + sp.eye(N_.shape[0]) * (1e-9 * N_.diagonal().mean())
    sol = sla.spsolve(N_.tocsc(), Mf.T @ rhs)
    uv = np.zeros(2 * n); uv[idx_free] = sol; uv[idx_fix] = val_fix
    return np.c_[uv[:n], uv[n:]], q, A, G

def arap(uv, q, A, G, W, iters=25):
    n = len(uv); Gx, Gy = G[0::2], G[1::2]
    Aw = sp.diags(np.repeat(A, 1))
    L = (Gx.T @ Aw @ Gx + Gy.T @ Aw @ Gy).tocsc()
    L = L + sp.eye(n) * 1e-9
    L[0, 0] += 1.0                                               # pin vertex 0 softly
    solve = sla.factorized(L.tocsc())
    for _ in range(iters):
        # per-triangle Jacobian of the map (local 2D -> uv), closest rotation
        Ju = np.c_[Gx @ uv[:, 0], Gy @ uv[:, 0]]; Jv = np.c_[Gx @ uv[:, 1], Gy @ uv[:, 1]]
        J = np.stack([Ju, Jv], 1)                                # rows: u, v
        U, S, Vt = np.linalg.svd(J)
        R = U @ Vt
        bad = np.linalg.det(R) < 0
        U[bad, :, 1] *= -1; R[bad] = U[bad] @ Vt[bad]
        bu = Gx.T @ (A * R[:, 0, 0]) + Gy.T @ (A * R[:, 0, 1])
        bv = Gx.T @ (A * R[:, 1, 0]) + Gy.T @ (A * R[:, 1, 1])
        bu[0] += uv[0, 0]; bv[0] += uv[0, 1]
        uv = np.c_[solve(bu), solve(bv)]
    return uv

if __name__ == '__main__':
    V, T, F = load(sys.argv[1] if len(sys.argv) > 1 else 'old.obj'); V = np.array(V); T = np.array(T)
    isl = islands(V.tolist(), T.tolist(), F, lambda f: f['mat'] == 'top.paa')
    out = {}; report = []
    for k, i in enumerate(isl):
        vs = np.array(i['verts']); idx = {v: j for j, v in enumerate(vs)}
        tris = []
        for fi in i['faces']:
            f = F[fi]['v']
            for m in range(1, len(f) - 1): tris.append([idx[f[0]], idx[f[m]], idx[f[m + 1]]])
        tris = np.array(tris, dtype=np.int64)
        # weld duplicates (normal splits) and keep only referenced, non-degenerate triangles
        weld = np.arange(len(vs)); U = V[vs]; W = tris
        ok = (W[:, 0] != W[:, 1]) & (W[:, 1] != W[:, 2]) & (W[:, 0] != W[:, 2])
        area = np.zeros(len(W)); Wk = W[ok]
        area[ok] = np.linalg.norm(np.cross(U[Wk[:, 1]] - U[Wk[:, 0]], U[Wk[:, 2]] - U[Wk[:, 0]]), axis=1) / 2
        W = W[area > 1e-8]
        if len(W) == 0: continue
        # solve each connected piece on its own; pieces are laid side by side
        nU = len(U)
        adj = sp.coo_matrix((np.ones(3 * len(W)), (np.r_[W[:, 0], W[:, 1], W[:, 2]], np.r_[W[:, 1], W[:, 2], W[:, 0]])), shape=(nU, nU))
        ncomp, lab = sp.csgraph.connected_components(adj, directed=False)
        full = np.full((nU, 2), np.nan); off = 0.0; Asum = 0.0
        for cpt in range(ncomp):
            Wc = W[lab[W[:, 0]] == cpt]
            if len(Wc) == 0: continue
            used = np.unique(Wc); remap = -np.ones(nU, int); remap[used] = np.arange(len(used))
            Uu = U[used]; Wu = remap[Wc]
            uv, q, A, G = lscm(Uu, Wu)
            if not np.isfinite(uv).all():
                c_ = Uu - Uu.mean(0); ax_ = np.linalg.svd(c_, full_matrices=False)[2]; uv = c_ @ ax_[:2].T
            try:
                uv2 = arap(uv, q, A, G, Wu)
                if np.isfinite(uv2).all(): uv = uv2
            except np.linalg.LinAlgError:
                pass
            uv -= uv.min(0); uv[:, 0] += off; off = uv[:, 0].max() + 0.05; Asum += A.sum()
            full[used] = uv
        good = ~np.isnan(full[:, 0])
        for u in np.where(~good)[0]:
            full[u] = full[good][np.argmin(np.linalg.norm(U[good] - U[u], axis=1))]
        A = np.array([Asum])
        nuv = full[weld]
        # match the old island's handedness so mirrored art stays readable
        s_old = np.cross(T[vs][tris[:, 1]] - T[vs][tris[:, 0]], T[vs][tris[:, 2]] - T[vs][tris[:, 0]]).sum()
        s_new = np.cross(nuv[tris[:, 1]] - nuv[tris[:, 0]], nuv[tris[:, 2]] - nuv[tris[:, 0]]).sum()
        if s_old * s_new < 0: nuv[:, 0] *= -1
        s = np.cross(nuv[tris[:, 1]] - nuv[tris[:, 0]], nuv[tris[:, 2]] - nuv[tris[:, 0]])
        flips = int(((np.sign(s) != np.sign(s.sum())) & (np.abs(s) > 1e-10)).sum())
        out[k] = dict(verts=vs.tolist(), uv=nuv.tolist(), A=float(A.sum()))
        report.append((k, len(vs), round(float(A.sum()), 2), flips))
    json.dump(out, open('flat.json', 'w'))
    print(len(isl), 'islands,', len(out), 'flattened, flipped triangles:', sum(r[3] for r in report))
    for r in sorted(report, key=lambda r: -r[2])[:8]: print('  island %d: %d verts %.2f m2 flips %d' % r)
