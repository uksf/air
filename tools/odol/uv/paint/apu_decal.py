import numpy as np
from PIL import Image, ImageDraw, ImageFilter
from decals import canvas, arr, PPM

def apu_port(w=0.22, h=0.17):
    """APU outlet as on ZJ923: a short round hooded duct. A dark round opening facing aft and down,
    under a bright curved hood lip, with a soft shadow below. Image right = aft, up = up."""
    S = 4
    W, H = int(w * PPM), int(h * PPM)
    im = Image.new('RGBA', (W * S, H * S), (0, 0, 0, 0)); g = ImageDraw.Draw(im)
    cx, cy, r = W * S * 0.45, H * S * 0.5, H * S * 0.2
    # soft shadow cast below and aft of the duct
    sh = Image.new('L', im.size, 0); ImageDraw.Draw(sh).ellipse((cx - r * 1.2, cy - r * 0.2, cx + r * 1.9, cy + r * 1.35), fill=150)
    sh = sh.filter(ImageFilter.GaussianBlur(r * 0.35))
    im.paste(Image.new('RGBA', im.size, (40, 42, 44, 255)), (0, 0), sh)
    # duct body (lighter metal ring)
    g.ellipse((cx - r * 1.25, cy - r * 1.15, cx + r * 1.15, cy + r * 1.05), fill=(128, 131, 134, 255))
    # opening: dark ellipse, slightly aft and down in the ring
    g.ellipse((cx - r * 0.85, cy - r * 0.6, cx + r * 1.0, cy + r * 0.85), fill=(18, 18, 19, 255))
    # hood lip: bright crescent over the top
    lip = Image.new('L', im.size, 0); d = ImageDraw.Draw(lip)
    d.ellipse((cx - r * 1.3, cy - r * 1.25, cx + r * 1.2, cy + r * 0.7), fill=255)
    d.ellipse((cx - r * 1.0, cy - r * 0.75, cx + r * 1.25, cy + r * 1.1), fill=0)
    im.paste(Image.new('RGBA', im.size, (214, 217, 220, 255)), (0, 0), lip)
    return arr(im.resize((W, H), Image.LANCZOS))

def soot_column(w=0.36, h=0.42, strength=1.5):
    """Soot above the outlet: a column rising from the bottom centre, darkest at the outlet,
    widening and fading upward, drifting a little aft (image right)."""
    H, W = int(h * PPM / 4), int(w * PPM / 4)
    y = np.linspace(1, 0, H)[:, None]                      # 0 at the bottom (outlet)
    x = np.linspace(-1, 1, W)[None]
    centre = -0.05 + 0.18 * y                              # slight aft drift as it rises
    width = 0.55 + 0.35 * y
    a = np.exp(-((x - centre) / width) ** 2 * 2.0) * np.exp(-y * 2.2)
    a *= np.clip(y / 0.06, 0, 1) * 0.6 + 0.4               # thinner right at the lip
    a *= (1 - x ** 2) ** 2 * (1 - y ** 3)                   # fade to nothing at the canvas edges
    rng = np.random.default_rng(5)
    from scipy.ndimage import gaussian_filter
    n = gaussian_filter(rng.normal(0, 1, (H, W)), (9, 5))
    n /= n.std() + 1e-9
    a = np.clip(a * (1 + 0.15 * n) * strength, 0, 1)
    out = np.zeros((H, W, 4), np.float32); out[..., :3] = 0.07; out[..., 3] = a
    return out

if __name__ == '__main__':
    bg = np.ones((800, 1000, 3), np.float32) * np.array([126, 129, 132]) / 255
    def comp(img, x0, y0, sc):
        im = Image.fromarray((img * 255).astype(np.uint8)).resize((int(img.shape[1] * sc), int(img.shape[0] * sc)))
        a = np.asarray(im, np.float32) / 255
        h, w = a.shape[:2]; bg[y0:y0+h, x0:x0+w] = bg[y0:y0+h, x0:x0+w] * (1 - a[..., 3:]) + a[..., :3] * a[..., 3:]
    s = soot_column(); comp(s, 500 - int(s.shape[1] * 4 * 0.6) // 2, 620 - int(s.shape[0] * 4 * 0.6), 4 * 0.6)
    p = apu_port(); comp(p, 500 - int(p.shape[1] * 0.6) // 2, 600 - int(p.shape[0] * 0.6) // 2, 0.6)
    Image.fromarray((bg * 255).astype(np.uint8)).save('apu_decal_preview3.png')


def apu_hole(w=0.15, h=0.15):
    """APU outlet as Tim describes it from ZJ923: a round dark hole with minimal edging,
    soft-edged so it sits in the paint."""
    S = 4
    W, H = int(w * PPM), int(h * PPM)
    im = Image.new('RGBA', (W * S, H * S), (0, 0, 0, 0)); g = ImageDraw.Draw(im)
    cx, cy, rx, ry = W * S * 0.5, H * S * 0.5, W * S * 0.36, H * S * 0.36
    g.ellipse((cx - rx * 1.12, cy - ry * 1.12, cx + rx * 1.12, cy + ry * 1.12), fill=(92, 94, 96, 255))   # thin edge
    g.ellipse((cx - rx, cy - ry, cx + rx, cy + ry), fill=(16, 16, 17, 255))
    im = im.filter(ImageFilter.GaussianBlur(S * 1.2))
    return arr(im.resize((W, H), Image.LANCZOS))
