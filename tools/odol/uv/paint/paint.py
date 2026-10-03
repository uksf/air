import sys, numpy as np
from PIL import Image
from scipy.ndimage import gaussian_filter, distance_transform_edt, map_coordinates
import splat as S
import decals as D
import apu_decal as A

# Composes the Typhoon camo sheets (upper, lower, pilot) from layers defined in 3D, so every target
# gets the same paint: base grey, ambient occlusion, panel lines (RKSL positions + our part
# outlines), weathering, and markings. Writes <target>_co/_nohq/_smdi PNGs into out/.
from paths import WORK as W, SRC
H = W
N = S.N
BASE = np.array([126, 129, 132], np.float32) / 255

# --- markings: (image, anchor, outward direction to snap to, up, width, height) -----------------
def mk_list():
    out = []
    for side in (1, -1):                                   # +1 port, -1 starboard
        X = np.array([side, 0, 0.])
        # positions from the RKSL RAF sheet carried through the RKSL model, checked against photos
        out.append((D.roundel(0.40), [side * 0.8, 0.42, -1.85], X, [0, 1, 0], 0.40, 0.40))
        out.append((D.roundel(0.40), [side * 3.5, -0.1, 2.75], [0, 1, 0], [0, 0, -1], 0.40, 0.40))
        out.append((D.roundel(0.40), [side * 4.0, -0.4, 3.0], [0, -1, 0], [0, 0, -1], 0.40, 0.40))
        out.append((D.fin_flash(0.30, 0.38), [side * 0.3, 1.38, 5.04], X, [0, 1, 0], 0.30, 0.38))
        img, w, h = D.text('ZK306', 0.11, (64, 67, 70, 255)); out.append((img, [side * 0.8, 0.30, 3.95], X, [0, 1, 0], w, h))
        out.append((D.triangle(0.14), [side * 0.6, 0.55, -3.55], X, [0, 1, 0], 0.14, 0.126))
        for ax, az in ((1.55, 0.3), (1.55, 2.4), (2.6, 2.7)):
            img, w, h = D.text('NO STEP', 0.05); out.append((img, [side * ax, 0.2, az], [0, 1, 0], [0, 0, -1], w, h))
    # arrows point aft on both sides: towards the viewer's right on the port side, left on starboard
    out.append((D.rescue(0.42, 0.075, 'right'), [0.75, 0.45, -4.15], [1, 0, 0], [0, 1, 0], 0.42, 0.075))
    out.append((D.rescue(0.42, 0.075, 'left'), [-0.75, 0.45, -4.15], [-1, 0, 0], [0, 1, 0], 0.42, 0.075))
    # APU outlet on the port wing-body fillet (photo: ZJ923). fnc_apuSmoke emits from it.
    # a dark hole on the wing-body fillet, soot rising from it up the fuselage side (ZJ923)
    out.append((A.soot_column(0.7, 0.5), [0.98, APU[1] + 0.25, APU[2] + 0.03], [0.97, 0.25, 0], [0, 1, 0], 0.7, 0.5))
    out.append((A.apu_hole(), APU, [0.6, 0.8, 0], [0, 1, 0], 0.15, 0.15))
    return out


APU = [1.09, -0.118, 0.67]
APU_R = 0.054                                              # painted hole radius: 0.36 of the 0.15 m decal


def snap(anchor, nd, lod0):
    """Nearest LOD 0 texel to the anchor that faces along nd: decal origin and normal."""
    nd = np.asarray(nd, float); nd /= np.linalg.norm(nd)
    best = None
    for g in lod0:
        d, j = g['tree'].query(anchor, k=400)
        j = j[np.isfinite(d)]
        ok = j[(g['N'][j] @ nd) > 0.5]
        if len(ok) and (best is None or np.linalg.norm(g['P'][ok[0]] - anchor) < best[0]):
            best = (np.linalg.norm(g['P'][ok[0]] - anchor), g['P'][ok[0]], g['N'][ok[0]])
    if best is None: raise RuntimeError(f'no surface near {anchor}')
    return best[1], best[2] / np.linalg.norm(best[2])


def noise3(P, seed, scale, stretch=(1, 1, 1), n=24):
    rng = np.random.default_rng(seed)
    k = rng.normal(0, 1, (n, 3)) / np.asarray(stretch) / scale
    ph = rng.uniform(0, 2 * np.pi, n)
    return (np.sin(P @ k.T + ph)).sum(1) / np.sqrt(n / 2)


def to_img(g, v, fill=0):
    shape = (N, N) + v.shape[1:]
    im = np.full(shape, fill, np.float32); im[g['r'], g['c']] = v
    return im


def paint(name, decal_list, lod0):
    g = S.target(name)
    P, Nn = g['P'], g['N']
    cov = np.zeros((N, N), bool); cov[g['r'], g['c']] = True
    if name == 'sides':                                    # profile paintings only, not the photo crops
        keep = (g['r'] < 0.27 * N) | ((g['r'] > 0.72 * N) & (g['c'] < 0.86 * N))
        cov[:] = False; cov[g['r'][keep], g['c'][keep]] = True
    col = np.repeat(BASE[None], len(P), 0)
    # weathering: broad tonal mottling, and fine streaks along the airflow (+Z)
    col *= (1 + 0.025 * noise3(P, 1, 0.9))[:, None]
    col *= (1 + 0.018 * noise3(P, 2, 0.05, (1, 1, 14)))[:, None]
    # exhaust soot on the rear fuselage around the nozzles
    rear = np.clip((P[:, 2] - 4.9) / 0.9, 0, 1) * (np.abs(P[:, 0]) < 1.05) * (P[:, 1] < 0.7)
    col *= (1 - 0.32 * rear * (0.8 + 0.2 * noise3(P, 3, 0.04, (1, 1, 6))))[:, None]
    # ambient occlusion
    if name == 'sides':                                    # overlay faces on the skin: use the skin's AO
        aov = np.ones(len(P), np.float32)
        for t in ('upper', 'lower'):
            gt = S.target(t); d, j = gt['tree'].query(P, distance_upper_bound=0.05, workers=-1)
            ok = np.isfinite(d); j = np.where(ok, j, 0); a_ = np.load(H + f'ao_{t}.npy')[j]
            better = ok & ((aov == 1) | (d < 0.05)); aov[better] = a_[better]
    else:
        aov = np.load(H + f'ao_{name}.npy')
    ao = to_img(g, aov, 1)
    ao = gaussian_filter(ao, 1.2)[g['r'], g['c']]
    col *= (0.45 + 0.55 * ao)[:, None]
    colI = to_img(g, col)
    # panel lines and part outlines
    L = np.load(H + 'lines3d_f.npz'); E = np.load(H + 'edges3d.npz')
    r, c, _ = S.project(name, L['P'], L['N'], max_dist=0.06, min_dot=0.7, signed=True); la = S.splat(r, c)
    r, c, _ = S.project(name, E['P'], E['N'], max_dist=0.005, min_dot=0.5); ea = S.splat(r, c)
    def norm(a):
        p = np.percentile(a[a > 1e-4], 90) if (a > 1e-4).any() else 1
        return np.clip(a / p, 0, 1)
    from scipy.ndimage import label, find_objects
    lab, nl = label(norm(la) > 0.25, structure=np.ones((3, 3)))
    small = np.zeros(nl + 1, bool)
    for i, sl in enumerate(find_objects(lab), 1):
        if max(sl[0].stop - sl[0].start, sl[1].stop - sl[1].start) < 0.25 * 330: small[i] = True
    la = la * ~small[lab]
    lines = np.maximum(norm(la), 0.8 * norm(ea)) * cov
    colI *= (1 - 0.42 * lines)[..., None]
    # markings
    for img, anchor, nd, up, w, h in decal_list:
        P0, n0 = snap(np.asarray(anchor, float), nd, lod0)
        upv = np.asarray(up, float); upv = upv - (upv @ n0) * n0; upv /= np.linalg.norm(upv)
        right = np.cross(n0, upv)                          # model space is left-handed
        Q = P - P0
        x, y, z = Q @ right, Q @ upv, Q @ n0
        m = (np.abs(x) < w / 2) & (np.abs(y) < h / 2) & (np.abs(z) < 0.15) & ((Nn @ n0) > 0.6)
        if not m.any(): continue
        ih, iw = img.shape[:2]
        rr = (0.5 - y[m] / h) * ih - 0.5; cc = (x[m] / w + 0.5) * iw - 0.5
        s = np.stack([map_coordinates(img[..., k], [rr, cc], order=1) for k in range(4)], 1)
        a = s[:, 3:4]
        rows, cols = g['r'][m], g['c'][m]
        colI[rows, cols] = colI[rows, cols] * (1 - a) + s[:, :3] * a
    # normal map: panel lines as shallow grooves; tangent frame u right, v down the image
    hgt = -gaussian_filter(lines, 0.6) * 1.6
    # APU outlet: a bowl, steep at the edge and flat at the bottom, so the hole reads as having depth
    P0, n0 = snap(np.asarray(APU, float), [0.6, 0.8, 0], lod0)
    d = P - P0; dz = d @ n0; rr = np.linalg.norm(d - dz[:, None] * n0, axis=1) / APU_R
    hole = (rr < 1) & (np.abs(dz) < 0.1)
    hv = np.zeros(len(P), np.float32); hv[hole] = -8 * (1 - rr[hole] ** 4)
    hgt += gaussian_filter(to_img(g, hv, 0), 0.8)
    gy, gx = np.gradient(hgt)
    nrm = np.stack([-gx, -gy, np.ones_like(gx)], -1); nrm /= np.linalg.norm(nrm, axis=-1, keepdims=True)
    # specular: matte paint, lower still in lines and soot
    lum = colI.mean(-1) / BASE.mean()
    spec = np.clip(0.17 * lum, 0.05, 0.22) * np.clip((lum - 0.25) / 0.25, 0, 1)    # holes and openings do not reflect
    smdi = np.stack([np.ones_like(lum), spec, np.full_like(lum, 0.22) * (spec > 0)], -1)
    # pad islands outward so mip levels do not pick up the empty background
    idx = distance_transform_edt(~cov, return_distances=False, return_indices=True)
    out = {}
    if name == 'sides':                                    # composite over the original sheet
        orig = np.asarray(Image.open(W + 'sides.png').convert('RGB').resize((N, N), Image.LANCZOS), np.float32) / 255
        grow = distance_transform_edt(~cov) < 3
        im = np.where(grow[..., None], colI[idx[0], idx[1]], orig)
        out = {'co': np.clip(im * 255 + 0.5, 0, 255).astype(np.uint8)}
        Image.fromarray(out['co']).save(H + 'out/sides_co.png'); print(name, 'done', flush=True)
        return out
    for k, im in (('co', colI), ('nohq', (nrm + 1) / 2), ('smdi', smdi)):
        im = im[idx[0], idx[1]]
        out[k] = np.clip(im * 255 + 0.5, 0, 255).astype(np.uint8)
        Image.fromarray(out[k]).save(H + f'out/{name}_{k}.png')
    print(name, 'done', flush=True)
    return out


if __name__ == '__main__':
    import os; os.makedirs(H + 'out', exist_ok=True)
    lod0 = [S.target('upper'), S.target('lower')]
    dl = mk_list()
    for t in (sys.argv[1:] or ['upper', 'lower', 'pilot']):
        paint(t, dl, lod0)
