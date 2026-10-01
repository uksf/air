import sys
import numpy as np
from PIL import Image
from scipy.ndimage import distance_transform_edt
from plan_lib import load

# Bakes a texture from an old UV layout into a new one, face by face: every face has the same
# vertices in both OBJ exports, so each new-UV triangle samples the old texture through its old UVs.
# usage: bake.py old.obj new.obj src.png out.png size material [material...]
old_obj, new_obj, src_png, out_png, size = sys.argv[1:6]
mats = set(sys.argv[6:])
N = int(size)
_, To, Fo = load(old_obj)
_, Tn, Fn = load(new_obj)
src = np.asarray(Image.open(src_png).convert('RGBA'), dtype=np.float32)
H, W = src.shape[:2]
out = np.zeros((N, N, 4), dtype=np.float32)
filled = np.zeros((N, N), dtype=bool)

def sample(u, v):
    x = (u % 1.0) * W - 0.5; y = (v % 1.0) * H - 0.5
    x0 = np.floor(x).astype(int); y0 = np.floor(y).astype(int); fx = (x - x0)[:, None]; fy = (y - y0)[:, None]
    x0 %= W; y0 %= H; x1 = (x0 + 1) % W; y1 = (y0 + 1) % H
    return (src[y0, x0] * (1 - fx) * (1 - fy) + src[y0, x1] * fx * (1 - fy) + src[y1, x0] * (1 - fx) * fy + src[y1, x1] * fx * fy)

n = 0
for fo, fn in zip(sorted(Fo, key=lambda f: tuple(sorted(f['v']))), sorted(Fn, key=lambda f: tuple(sorted(f['v'])))):
    if fn['mat'] not in mats: continue
    vs = fn['v']
    for k in range(1, len(vs) - 1):
        tri = (vs[0], vs[k], vs[k + 1])
        P = np.array([(Tn[v][0] * N, (1 - Tn[v][1]) * N) for v in tri])     # new UV in pixels (v down)
        Q = np.array([(To[v][0], 1 - To[v][1]) for v in tri])                # old UV (v down)
        x0, y0 = np.floor(P.min(0)).astype(int); x1, y1 = np.ceil(P.max(0)).astype(int)
        x0, y0 = max(x0, 0), max(y0, 0); x1, y1 = min(x1, N - 1), min(y1, N - 1)
        if x1 < x0 or y1 < y0: continue
        ys, xs = np.mgrid[y0:y1 + 1, x0:x1 + 1]
        px = xs.ravel() + 0.5; py = ys.ravel() + 0.5
        (ax, ay), (bx, by), (cx, cy) = P
        d = (by - cy) * (ax - cx) + (cx - bx) * (ay - cy)
        if abs(d) < 1e-12: continue
        l1 = ((by - cy) * (px - cx) + (cx - bx) * (py - cy)) / d
        l2 = ((cy - ay) * (px - cx) + (ax - cx) * (py - cy)) / d
        l3 = 1 - l1 - l2
        e = -0.6 / max(abs(d) ** 0.5, 1)                                       # take edge pixels too
        inside = (l1 >= e) & (l2 >= e) & (l3 >= e)
        if not inside.any(): continue
        u = l1[inside] * Q[0, 0] + l2[inside] * Q[1, 0] + l3[inside] * Q[2, 0]
        v = l1[inside] * Q[0, 1] + l2[inside] * Q[1, 1] + l3[inside] * Q[2, 1]
        out[py[inside].astype(int), px[inside].astype(int)] = sample(u, v)
        filled[py[inside].astype(int), px[inside].astype(int)] = True
    n += 1
# pad: unfilled texels take the nearest baked texel, so mips and filtering do not bleed background in
idx = distance_transform_edt(~filled, return_distances=False, return_indices=True)
out = out[idx[0], idx[1]]
Image.fromarray(np.clip(out, 0, 255).astype(np.uint8), 'RGBA').save(out_png)
Image.fromarray((filled * 255).astype(np.uint8)).save(out_png.replace('.png', '_mask.png'))
print(f'{out_png}: {n} faces baked, {filled.mean() * 100:.1f}% of texels covered')
