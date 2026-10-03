import numpy as np
from PIL import Image, ImageDraw, ImageFilter
from decals import canvas, arr, PPM

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

def apu_hole(w=0.15, h=0.15):
    """APU outlet as on ZJ923: a round dark hole with minimal edging,
    soft-edged so it sits in the paint."""
    S = 4
    W, H = int(w * PPM), int(h * PPM)
    im = Image.new('RGBA', (W * S, H * S), (0, 0, 0, 0)); g = ImageDraw.Draw(im)
    cx, cy, rx, ry = W * S * 0.5, H * S * 0.5, W * S * 0.36, H * S * 0.36
    g.ellipse((cx - rx * 1.12, cy - ry * 1.12, cx + rx * 1.12, cy + ry * 1.12), fill=(92, 94, 96, 255))   # thin edge
    g.ellipse((cx - rx, cy - ry, cx + rx, cy + ry), fill=(16, 16, 17, 255))
    im = im.filter(ImageFilter.GaussianBlur(S * 1.2))
    return arr(im.resize((W, H), Image.LANCZOS))
