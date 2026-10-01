import sys
import numpy as np
from PIL import Image
from plan_lib import load

# Orthographic software render of the camo faces of an OBJ export, textured per material.
# usage: render.py model.obj out.png mat=texture.png [mat=texture.png ...]
obj, out = sys.argv[1:3]
texmap = {a.split('=')[0]: np.asarray(Image.open(a.split('=')[1]).convert('RGB'), dtype=np.float32) for a in sys.argv[3:]}
V, T, F = load(obj)
V = np.array(V); T = np.array(T)
R = 700

def view(axis):
    # (screen x, screen y, depth toward the viewer)
    if axis == 'top': return V[:, 2], V[:, 0], V[:, 1]
    if axis == 'bottom': return V[:, 2], -V[:, 0], -V[:, 1]
    return V[:, 2], -V[:, 1], -V[:, 0]                       # left side

panels = []
for axis in ('top', 'bottom', 'side'):
    sx, sy, sz = view(axis)
    lo = min(sx.min(), sy.min()); span = max(sx.max() - sx.min(), sy.max() - sy.min())
    px = (sx - sx.min()) / span * (R - 1); py = (sy - sy.min()) / span * (R - 1)
    img = np.full((R, R, 3), 255, np.float32); zb = np.full((R, R), -1e9)
    for f in F:
        tex = texmap.get(f['mat'])
        if tex is None: continue
        H, W = tex.shape[:2]
        vs = f['v']
        for k in range(1, len(vs) - 1):
            t = (vs[0], vs[k], vs[k + 1])
            P = np.array([(px[i], py[i]) for i in t]); Z = np.array([sz[i] for i in t])
            x0, y0 = np.floor(P.min(0)).astype(int); x1, y1 = np.ceil(P.max(0)).astype(int)
            ys, xs = np.mgrid[max(y0, 0):min(y1, R - 1) + 1, max(x0, 0):min(x1, R - 1) + 1]
            qx = xs.ravel() + .5; qy = ys.ravel() + .5
            (ax, ay), (bx, by), (cx, cy) = P
            d = (by - cy) * (ax - cx) + (cx - bx) * (ay - cy)
            if abs(d) < 1e-9: continue
            l1 = ((by - cy) * (qx - cx) + (cx - bx) * (qy - cy)) / d
            l2 = ((cy - ay) * (qx - cx) + (ax - cx) * (qy - cy)) / d
            l3 = 1 - l1 - l2
            m = (l1 >= 0) & (l2 >= 0) & (l3 >= 0)
            if not m.any(): continue
            z = l1[m] * Z[0] + l2[m] * Z[1] + l3[m] * Z[2]
            X = qx[m].astype(int); Y = qy[m].astype(int)
            near = z > zb[Y, X]
            if not near.any(): continue
            u = (l1[m] * T[t[0], 0] + l2[m] * T[t[1], 0] + l3[m] * T[t[2], 0])[near]
            v = 1 - (l1[m] * T[t[0], 1] + l2[m] * T[t[1], 1] + l3[m] * T[t[2], 1])[near]
            img[Y[near], X[near]] = tex[((v % 1) * H).astype(int) % H, ((u % 1) * W).astype(int) % W]
            zb[Y[near], X[near]] = z[near]
    panels.append(img)
Image.fromarray(np.hstack(panels).astype(np.uint8)).save(out)
print('wrote', out)
