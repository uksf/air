# Plans the two-sheet camo layout: assigns each UV island of LOD 0 to the upper or underside sheet
# and packs the islands by shape (rasterised on a grid), scale and offset only, so tangents stay valid.
# usage: plan.py lod0.obj   writes plan0.json (the recipe's typhoon-camo.json)
import json, math, sys
import numpy as np
from scipy.signal import fftconvolve
from scipy.ndimage import binary_dilation
from PIL import Image, ImageDraw
from plan_lib import *

SHEET = 4096
N = 512                 # packing grid
PADC = 1                # padding in grid cells: 8 px at 4096
BOOST = 1.5             # islands below the sheet's median texel density are scaled up to 1.5x
SIDES_B = True          # side-facing islands go to the underside sheet, which balances the two

V, T, F = load(sys.argv[1])
T = [(u, 1 - v) for u, v in T]
cam = lambda f: f['mat'] == 'top.paa'
isl = islands(V, T, F, cam)
# Typhoon LOD 0 sections 49 and 50 are pylons and misc_parts, textured with the upper sheet in config.
for i in isl:
    side = i['A'] - i['up'] - i['dn']
    i['sheet'] = 'B' if (i['dn'] > i['up'] or (SIDES_B and side > i['up'])) and not set(i['secs']) & {49, 50} else 'A'
    i['d'] = math.sqrt(i['U'] * SHEET * SHEET / i['A']) if i['A'] > 1e-6 and i['U'] > 0 else 0

def wq(pairs, q):
    pairs = sorted(pairs); t = sum(w for _, w in pairs); a = 0
    for d, w in pairs:
        a += w
        if a >= q * t: return d

def mask(i, s):
    bx, by = i['box'][0], i['box'][1]
    w = max(1, math.ceil((i['box'][2] - bx) * s * N)) + 1
    h = max(1, math.ceil((i['box'][3] - by) * s * N)) + 1
    im = Image.new('1', (w, h)); dr = ImageDraw.Draw(im)
    for fi in i['faces']:
        pts = [((T[v][0] - bx) * s * N, (T[v][1] - by) * s * N) for v in F[fi]['v']]
        dr.polygon(pts, fill=1, outline=1)
    m = np.array(im, dtype=bool)
    m = np.pad(m, PADC)
    return binary_dilation(m, iterations=PADC) if PADC else m

def pack(items, g):
    occ = np.zeros((N, N), dtype=np.float32)
    out = {}
    for k in sorted(range(len(items)), key=lambda k: -(items[k]['box'][2] - items[k]['box'][0]) * (items[k]['box'][3] - items[k]['box'][1]) * items[k]['k'] ** 2):
        i = items[k]; s = i['k'] * g
        m = mask(i, s)
        h, w = m.shape
        if h > N or w > N: return None
        ov = fftconvolve(occ, m[::-1, ::-1].astype(np.float32), mode='valid')
        free = np.argwhere(ov < 0.5)
        if len(free) == 0: return None
        y, x = free[np.lexsort((free[:, 1], free[:, 0]))[0]]   # lowest row, then leftmost
        occ[y:y + h, x:x + w] += m
        out[k] = ((x + PADC) / N, (y + PADC) / N)
    return out

result = {}
for s in 'AB':
    items = [i for i in isl if i['sheet'] == s]
    dm = wq([(i['d'], i['A']) for i in items if i['d'] > 0], .5)
    for i in items: i['k'] = min(BOOST, max(1, dm / i['d'])) if i['d'] > 0 else 1
    lo, hi = 0.8, 3.0
    best = None
    for _ in range(9):
        g = (lo + hi) / 2
        r = pack(items, g)
        if r: lo, best = g, r
        else: hi = g
    for k, pos in best.items():
        items[k]['s'] = items[k]['k'] * lo; items[k]['pos'] = pos
    nd = [(i['d'] * i['s'], i['A']) for i in items if i['d'] > 0]
    print(f"sheet {s}: {len(items)} islands {sum(i['A'] for i in items):.0f} m2 x{lo:.2f}: median {dm:.0f} -> {wq(nd, .5):.0f}, p10 {wq([(i['d'], i['A']) for i in items if i['d'] > 0], .1):.0f} -> {wq(nd, .1):.0f} texels/m")
json.dump({'islands': [dict(sheet=i['sheet'], s=i['s'], box=i['box'][:2], pos=i['pos'], verts=i['verts']) for i in isl]}, open('plan0.json', 'w'))
