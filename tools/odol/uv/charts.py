import os, sys, json, math
import numpy as np
from scipy.signal import fftconvolve
from scipy.ndimage import binary_dilation
from PIL import Image, ImageDraw
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from plan_lib import load
from flatten import islands, lscm, arap
import scipy.sparse as sp
import scipy.sparse.csgraph
from tangents import compute

# Camo layout v3. As v2 (every island flattened isometrically, packed at one texel density on the
# upper (A) or underside (B) 4096 sheet), but an island that will not flatten cleanly is split into
# charts by surface direction, with seams cut by duplicating vertices.
# usage: plan3.py <lod0.obj> <vertices.txt> <plan.json> <cuts.json>
SHEET, N, PADC = 4096, 512, 1
PYLON_SECTIONS = {49, 50}
MAX_STRETCH, ANGLES = 2.0, (60, 45, 32, 22)
HAND = float(__import__('os').environ.get('HAND', 1))

V, T, F = load(sys.argv[1]); V = np.array(V)
vtx = np.loadtxt(sys.argv[2])
n0 = len(V)
copies = []                                   # source vertex per new vertex n0 + k
face_maps = {}                                # face index -> {old: new}


def tri_list(faces, idx, FF):
    t = []
    for fi in faces:
        f = FF[fi]
        for m in range(1, len(f) - 1): t.append([idx[f[0]], idx[f[m]], idx[f[m + 1]]])
    return np.array(t, dtype=np.int64)


def signed(uv, W):
    e1 = uv[W[:, 1]] - uv[W[:, 0]]; e2 = uv[W[:, 2]] - uv[W[:, 0]]
    return (e1[:, 0] * e2[:, 1] - e1[:, 1] * e2[:, 0]) / 2


def quality(P, uv, W):
    """Area of triangles stretched beyond MAX_STRETCH, and area flipped against the majority."""
    a, b, c = P[W[:, 0]], P[W[:, 1]], P[W[:, 2]]
    e1, e2 = b - a, c - a; n = np.cross(e1, e2); A = np.linalg.norm(n, axis=1) / 2
    ok = A > 1e-9
    x = e1 / np.maximum(np.linalg.norm(e1, axis=1), 1e-12)[:, None]
    y = np.cross(n / np.maximum(2 * A, 1e-12)[:, None], x)
    Pm = np.stack([np.c_[(e1 * x).sum(1), (e2 * x).sum(1)], np.c_[(e1 * y).sum(1), (e2 * y).sum(1)]], 1)
    Q = np.stack([uv[W[:, 1]] - uv[W[:, 0]], uv[W[:, 2]] - uv[W[:, 0]]], 2)
    bad_str = 0.0
    for t in np.where(ok)[0]:
        try: J = Q[t] @ np.linalg.inv(Pm[t])
        except np.linalg.LinAlgError: continue
        s = np.linalg.svd(J, compute_uv=False)
        if s[1] < 1e-9 or s[0] / s[1] > MAX_STRETCH: bad_str += A[t]
    sg = signed(uv, W)
    flipped = min(A[sg > 0].sum(), A[sg < 0].sum())
    return bad_str, flipped, A.sum()


def flatten_faces(faces, FF, Vx):
    """LSCM + ARAP for one connected set of faces. Returns verts, uv (metres) or None if it fails."""
    vs = np.array(sorted({v for fi in faces for v in FF[fi]})); idx = {v: j for j, v in enumerate(vs)}
    P = Vx[vs]; W = tri_list(faces, idx, FF)
    area = np.linalg.norm(np.cross(P[W[:, 1]] - P[W[:, 0]], P[W[:, 2]] - P[W[:, 0]]), axis=1) / 2
    Wg = W[area > 1e-8]
    if len(Wg) == 0: return vs, np.zeros((len(vs), 2)), W, P
    used = np.unique(Wg); rm = -np.ones(len(vs), int); rm[used] = np.arange(len(used))
    u, q, A, G = lscm(P[used], rm[Wg])
    if not np.isfinite(u).all():
        cc = P[used] - P[used].mean(0); u = cc @ np.linalg.svd(cc, full_matrices=False)[2][:2].T
    try:
        u2 = arap(u, q, A, G, rm[Wg])
        if np.isfinite(u2).all() and quality(P[used], u2, rm[Wg])[1] <= quality(P[used], u, rm[Wg])[1] + 1e-6: u = u2
    except np.linalg.LinAlgError: pass
    uv = np.zeros((len(vs), 2)); uv[used] = u
    for j in np.setdiff1d(np.arange(len(vs)), used):
        uv[j] = uv[used][np.argmin(np.linalg.norm(P[used] - P[j], axis=1))]
    return vs, uv, W, P


def face_normal(fv, Vx):
    n = sum(np.cross(Vx[fv[k]] - Vx[fv[0]], Vx[fv[k + 1]] - Vx[fv[0]]) for k in range(1, len(fv) - 1)); l = np.linalg.norm(n)
    return n / l if l > 0 else n, l / 2


def charts(faces, FF, Vx, angle):
    """Region growing over edge-adjacent faces: a face joins the chart if it is within angle of its mean normal."""
    cosv = math.cos(math.radians(angle))
    nrm = {f: face_normal(FF[f], Vx) for f in faces}
    edges = {}
    for f in faces:
        v = FF[f]
        for k in range(len(v)):
            edges.setdefault(tuple(sorted((v[k], v[(k + 1) % len(v)]))), []).append(f)
    nb = {f: set() for f in faces}
    for fs in edges.values():
        for a in fs:
            nb[a].update(x for x in fs if x != a)
    left = set(faces); out = []
    while left:
        seed = max(left, key=lambda f: nrm[f][1]); chart = [seed]; left.discard(seed)
        acc = nrm[seed][0] * nrm[seed][1]; front = [seed]
        while front:
            f = front.pop()
            for g in nb[f]:
                if g in left:
                    m = acc / max(np.linalg.norm(acc), 1e-12)
                    if nrm[g][0] @ m >= cosv:
                        left.discard(g); chart.append(g); front.append(g); acc = acc + nrm[g][0] * nrm[g][1]
        out.append(chart)
    # fold tiny charts into the neighbour they share most edges with
    owner = {f: i for i, c in enumerate(out) for f in c}
    for i, c in enumerate(out):
        if len(c) > 2: continue
        cnt = {}
        for f in c:
            for g in nb[f]:
                if owner[g] != i: cnt[owner[g]] = cnt.get(owner[g], 0) + 1
        if cnt:
            j = max(cnt, key=cnt.get)
            out[j] += c; out[i] = []
            for f in c: owner[f] = j
    return [c for c in out if c]


FF = [list(f['v']) for f in F]                # face vertex lists, edited in place by cuts
Vlist = list(V); vtx_list = list(vtx)


def cut(chart_list):
    """Give each chart after the first its own copies of vertices it shares with earlier charts."""
    seen = set()
    for c in chart_list:
        mine = {v for f in c for v in FF[f]}
        clash = mine & seen
        remap = {}
        for v in clash:
            src = v if v < n0 else copies[v - n0]
            remap[v] = n0 + len(copies); copies.append(src)
            Vlist.append(Vlist[src]); vtx_list.append(vtx_list[src])
        for f in c:
            if any(v in remap for v in FF[f]):
                m = face_maps.setdefault(f, {})
                for k, v in enumerate(FF[f]):
                    if v in remap:
                        orig = v if v < n0 else copies[v - n0]
                        # map is keyed by the face's original vertex at this corner
                        m[F[f]['v'][k]] = remap[v]
                        FF[f][k] = remap[v]
        seen |= {v for f in c for v in FF[f]}


def finish(vs, uv, faces):
    """Rotate to the longest axis, keep the old handedness, record sheet and size."""
    cc = uv - uv.mean(0)
    if len(vs) > 2 and np.ptp(cc, 0).max() > 0:
        R = np.linalg.svd(cc, full_matrices=False)[2]
        if np.linalg.det(R) < 0: R[1] *= -1
        uv = cc @ R.T
    Vx = np.array(Vlist); vx = np.array(vtx_list); idx = {v: j for j, v in enumerate(vs)}
    W = tri_list(faces, idx, FF)
    # one handedness for every island, so painted text never reads mirrored
    if signed(uv, W).sum() * HAND < 0: uv[:, 0] *= -1
    A = up = dn = 0.0; secs = set()
    for fi in faces:
        n, a = face_normal(FF[fi], Vx); A += a; secs.add(F[fi]['sec'])
        if n[1] > 0.3: up += a
        elif n[1] < -0.3: dn += a
    return dict(verts=[int(v) for v in vs], faces=faces, uvm=uv - uv.min(0), A=A,
                sheet='A' if (secs & PYLON_SECTIONS or up >= dn) else 'B', locked=bool(secs & PYLON_SECTIONS), upfrac=up / max(A, 1e-9))


out_islands = []; stats = dict(split=0, charts=0, unresolved=[])
for isl in islands(V, None, F, lambda f: f['mat'] == 'top.paa'):
    faces = isl['faces']
    vs, uv, W, P = flatten_faces(faces, FF, np.array(Vlist))
    s_, fl, tot = quality(P, uv, W)
    if s_ <= 0.01 * tot and fl <= 0.002 * tot:
        out_islands.append(finish(vs, uv, faces)); continue
    stats['split'] += 1
    for ang in ANGLES:
        parts = charts(faces, FF, np.array(Vlist), ang)
        flat = [flatten_faces(c, FF, np.array(Vlist)) for c in parts]
        worst = max(quality(p_[3], p_[1], p_[2])[1] + quality(p_[3], p_[1], p_[2])[0] for p_ in flat)
        if worst <= 0.002 or ang == ANGLES[-1]: break
    if worst > 0.002: stats['unresolved'].append((len(faces), round(worst, 4)))
    cut(parts); stats['charts'] += len(parts)
    for c in parts:
        vs, uv, W, P = flatten_faces(c, FF, np.array(Vlist))
        out_islands.append(finish(vs, uv, c))
print('islands', len(out_islands), 'split', stats['split'], 'into charts', stats['charts'], 'copies', len(copies), 'unresolved', stats['unresolved'])

# balance sheets: least upward-facing upper islands move to the underside sheet
for i in sorted([i for i in out_islands if i['sheet'] == 'A' and not i['locked']], key=lambda i: i['upfrac']):
    a = sum(j['A'] for j in out_islands if j['sheet'] == 'A'); b = sum(j['A'] for j in out_islands if j['sheet'] == 'B')
    if a - i['A'] < b + i['A']: break
    i['sheet'] = 'B'


def mask(i, s):
    w = max(1, math.ceil(np.ptp(i['uvm'][:, 0]) * s * N)) + 1
    h = max(1, math.ceil(np.ptp(i['uvm'][:, 1]) * s * N)) + 1
    im = Image.new('1', (w, h)); d = ImageDraw.Draw(im); idx = {v: j for j, v in enumerate(i['verts'])}
    for fi in i['faces']:
        d.polygon([tuple(i['uvm'][idx[v]] * s * N) for v in FF[fi]], fill=1, outline=1)
    return binary_dilation(np.pad(np.array(im, bool), PADC), iterations=PADC)


def pack(items, g):
    occ = np.zeros((N, N), np.float32); res = {}
    for k in sorted(range(len(items)), key=lambda k: -np.prod(np.ptp(items[k]['uvm'], 0) + 1e-3)):
        best = None
        for rot in (0, 1):
            it = dict(items[k]); it['uvm'] = items[k]['uvm'][:, ::-1] if rot else items[k]['uvm']
            m = mask(it, g); h, w = m.shape
            if h > N or w > N: continue
            ov = fftconvolve(occ, m[::-1, ::-1].astype(np.float32), mode='valid')
            free = np.argwhere(ov < 0.5)
            if len(free) == 0: continue
            y, x = free[np.lexsort((free[:, 1], free[:, 0]))[0]]
            if best is None or (y, x) < best[:2]: best = (y, x, rot, m)
        if best is None: return None
        y, x, rot, m = best; occ[y:y + m.shape[0], x:x + m.shape[1]] += m; res[k] = (x + PADC, y + PADC, rot)
    return res


plan = []
for sheet in 'AB':
    items = [i for i in out_islands if i['sheet'] == sheet]
    total = sum(i['A'] for i in items); lo, hi = 0.3 / math.sqrt(total), 1.2 / math.sqrt(total); best = None
    for _ in range(10):
        g = (lo + hi) / 2; r = pack(items, g)
        if r: lo, best = g, r
        else: hi = g
    print(f'sheet {sheet}: {len(items)} islands, {total:.0f} m2, {lo * SHEET:.0f} texels/m')
    for k, (x, y, rot) in best.items():
        i = items[k]; u = i['uvm'][:, ::-1] if rot else i['uvm']
        i['uv'] = u * lo + np.array([x / N, y / N]); plan.append(i)

Vx = np.array(Vlist); vx = np.array(vtx_list)
Nrm = vx[:, 3:6] / np.maximum(np.linalg.norm(vx[:, 3:6], axis=1), 1e-9)[:, None]
UVall = vx[:, 12:14].copy()
for i in plan: UVall[i['verts']] = i['uv']
Su, Tv = compute(Vx, Nrm, UVall, [FF[f] for f, x in enumerate(F) if x['mat'] == 'top.paa'])
Tv = Tv - (Tv * Su).sum(1)[:, None] * Su; Tv /= np.maximum(np.linalg.norm(Tv, axis=1), 1e-9)[:, None]
json.dump({'islands': [dict(sheet=i['sheet'], verts=i['verts'], uv=np.round(i['uv'], 6).tolist(),
                            st=np.round(np.c_[Su[i['verts']], Tv[i['verts']]], 4).tolist()) for i in plan]},
          open(sys.argv[3], 'w'), separators=(',', ':'))
json.dump({'copies': copies, 'faces': [{'verts': F[f]['v'], 'map': {str(k): v for k, v in m.items()}} for f, m in face_maps.items()]},
          open(sys.argv[4], 'w'), separators=(',', ':'))
print('plan islands', len(plan), 'cut faces', len(face_maps))
