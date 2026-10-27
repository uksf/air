import sys, numpy as np, pandas as pd
from PIL import Image
from scipy.spatial import cKDTree
from scipy.ndimage import gaussian_filter
from paths import WORK as W

VOX, RADIUS, SAME_SURFACE, CAP, FEATURE, PASSES = 0.02, 0.10, 0.9, 0.10, 0.15, 2
N = 4096


def normal_bucket(Ns):
    a = np.abs(Ns).argmax(1)
    return a * 2 + (Ns[np.arange(len(Ns)), a] > 0)


def voxel_levels(P, Ns, lum):
    cell = np.floor(P / VOX).astype(np.int64) + 2000
    key = ((cell[:, 0] * 4000 + cell[:, 1]) * 4000 + cell[:, 2]) * 6 + normal_bucket(Ns)
    df = pd.DataFrame({'k': key, 'l': lum, 'x': P[:, 0], 'y': P[:, 1], 'z': P[:, 2], 'nx': Ns[:, 0], 'ny': Ns[:, 1], 'nz': Ns[:, 2]})
    agg = df.groupby('k').agg(l=('l', 'median'), x=('x', 'mean'), y=('y', 'mean'), z=('z', 'mean'),
                              nx=('nx', 'mean'), ny=('ny', 'mean'), nz=('nz', 'mean'))
    C = agg[['x', 'y', 'z']].to_numpy(); Cn = agg[['nx', 'ny', 'nz']].to_numpy()
    return C, Cn / np.maximum(np.linalg.norm(Cn, axis=1, keepdims=True), 1e-9), agg['l'].to_numpy()


def correction(g, rgb):
    P, Ns = g['P'], g['Ns']
    lum = np.log(np.maximum(rgb.mean(2)[g['r'], g['c']], 1))
    C, Cn, level = voxel_levels(P, Ns, lum)
    tree = cKDTree(C)
    smooth = np.empty(len(C))
    for i, js in enumerate(tree.query_ball_point(C, RADIUS, workers=-1)):
        js = np.asarray(js); js = js[(Cn[js] @ Cn[i]) > SAME_SURFACE]
        smooth[i] = np.median(level[js])
    step = smooth - level
    step[np.abs(step) > FEATURE] = 0
    step = np.clip(step, -CAP, CAP)
    dist, near = tree.query(P, k=4, workers=-1)
    same = (Cn[near] * Ns[:, None, :]).sum(2) > SAME_SURFACE
    same[:, 0] |= ~same.any(1)
    w = same / np.maximum(dist, 0.002)
    texel = (w * step[near]).sum(1) / w.sum(1)
    img = np.zeros((N, N), np.float32); img[g['r'], g['c']] = texel
    cov = np.zeros((N, N), np.float32); cov[g['r'], g['c']] = 1
    return (gaussian_filter(img, 2) / np.maximum(gaussian_filter(cov, 2), 1e-6))[g['r'], g['c']]


def destripe(name, src, dst):
    g = np.load(W + f'g_{name}.npz')
    rgb = np.asarray(Image.open(src).convert('RGB')).astype(np.float32)
    for _ in range(PASSES):
        rgb[g['r'], g['c']] *= np.exp(correction(g, rgb))[:, None]
        rgb = rgb.clip(0, 255)
    Image.fromarray(rgb.round().astype(np.uint8), 'RGB').save(dst)


if __name__ == '__main__':
    for name in sys.argv[1:] or ['upper', 'lower']:
        destripe(name, W + f'out/{name}_co.png', W + f'out/{name}_co.png')
        print(name, 'destriped')
