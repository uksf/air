import numpy as np
from PIL import Image, ImageDraw, ImageFont

# Vector markings, drawn at 4x and kept as float RGBA arrays. A decal is placed in 3D (model file
# space: +X port, +Y up, +Z aft) by an anchor near the surface, the outward direction to snap to,
# an up direction, and its size in metres.
PPM = 1600                         # drawing pixels per metre


def canvas(w, h):
    im = Image.new('RGBA', (max(4, int(w * PPM)), max(4, int(h * PPM))), (0, 0, 0, 0))
    return im, ImageDraw.Draw(im)


def font(px, bold=True):
    for f in (('arialbd.ttf' if bold else 'arial.ttf'), 'DejaVuSans-Bold.ttf'):
        try: return ImageFont.truetype(f, int(px))
        except OSError: pass
    return ImageFont.load_default()


def arr(im): return np.asarray(im, np.float32) / 255


# Low-visibility RAF colours: pale red and pale blue on the grey.
LV_RED, LV_BLUE = (196, 140, 146, 255), (138, 154, 186, 255)
STENCIL = (74, 78, 82, 255)


def roundel(d):
    im, g = canvas(d, d); s = im.size[0]
    g.ellipse((0, 0, s - 1, s - 1), fill=LV_BLUE)
    r = s * 0.3; g.ellipse((s / 2 - r, s / 2 - r, s / 2 + r, s / 2 + r), fill=LV_RED)
    return arr(im)


def fin_flash(w, h):
    im, g = canvas(w, h); W, H = im.size
    g.rectangle((0, 0, W / 2, H), fill=LV_RED); g.rectangle((W / 2, 0, W, H), fill=LV_BLUE)
    return arr(im)


def text(s, h, colour=STENCIL, w=None):
    f = font(h * PPM * 1.25)
    box = f.getbbox(s); tw = box[2] - box[0]; th = box[3] - box[1]
    W = int(w * PPM) if w else tw + 8
    im = Image.new('RGBA', (W, int(h * PPM) + 8), (0, 0, 0, 0))
    ImageDraw.Draw(im).text(((W - tw) / 2 - box[0], (im.size[1] - th) / 2 - box[1]), s, font=f, fill=colour)
    return arr(im), W / PPM, im.size[1] / PPM


def rescue(w=0.5, h=0.09, point='right'):
    im, g = canvas(w, h); W, H = im.size
    g.polygon([(0, H * .2), (W * .82, H * .2), (W * .82, 0), (W, H / 2), (W * .82, H), (W * .82, H * .8), (0, H * .8)], fill=(214, 176, 40, 255))
    if point == 'left': im = im.transpose(Image.FLIP_LEFT_RIGHT); g = ImageDraw.Draw(im)
    f = font(H * 0.62); x = W * .06 if point == 'right' else W * .26
    g.text((x, H * .17), 'RESCUE', font=f, fill=(20, 20, 20, 255))
    return arr(im)


def triangle(s=0.14):
    im, g = canvas(s, s * .9); W, H = im.size
    g.polygon([(W / 2, 0), (W, H), (0, H)], fill=(186, 44, 40, 255))
    g.polygon([(W / 2, H * .3), (W * .72, H * .86), (W * .28, H * .86)], fill=(238, 238, 236, 255))
    return arr(im)


def apu_port(w=0.18, h=0.075):
    """APU outlet at the wing root: a slot along the airflow (image right = aft) under a light lip."""
    im, g = canvas(w, h); W, H = im.size
    g.rounded_rectangle((0, H * .18, W - 1, H - 1), radius=H * .35, fill=(84, 86, 88, 255))
    g.rounded_rectangle((W * .06, H * .36, W * .97, H * .9), radius=H * .25, fill=(22, 22, 23, 255))
    g.rounded_rectangle((W * .02, 0, W * .98, H * .2), radius=H * .1, fill=(168, 171, 174, 255))
    return arr(im)


def soot_smudge(w, h, strength=0.75):
    """Soot above the APU outlet: densest at the bottom-left (outlet, image right = aft), spreading
    up and aft, with streaky edges."""
    H, W = int(h * PPM / 4), int(w * PPM / 4)
    y = np.linspace(1, 0, H)[:, None]; x = np.linspace(0, 1, W)[None]       # y = 0 at the bottom
    d = np.hypot((x - 0.18) / 0.55, (y - 0.08) / 0.75)
    a = np.clip(1 - d, 0, 1) ** 1.6
    rng = np.random.default_rng(11)
    noise = rng.normal(0, 1, (H // 6 + 1, W // 6 + 1))
    from scipy.ndimage import zoom, gaussian_filter
    n = zoom(gaussian_filter(noise, 1), (H / noise.shape[0], W / noise.shape[1]), order=1)[:H, :W]
    a = np.clip(a * (0.8 + 0.35 * n) * strength, 0, 1)
    out = np.zeros((H, W, 4), np.float32); out[..., :3] = 0.08; out[..., 3] = a
    return out


def soot(w, h, strength=0.55):
    """Soft streak: dense at the top row (the source), fading downstream (towards the bottom)."""
    H, W = int(h * PPM / 4), int(w * PPM / 4)
    y = np.linspace(0, 1, H)[:, None]; x = np.linspace(-1, 1, W)[None]
    spread = 0.35 + 0.65 * y
    a = np.exp(-(x / spread) ** 2 * 2.5) * (1 - y) ** 1.4 * strength
    rng = np.random.default_rng(7)
    streaks = np.repeat(rng.normal(1, 0.25, (1, W)), H, 0)
    a = np.clip(a * streaks, 0, 1)
    out = np.zeros((H, W, 4), np.float32); out[..., :3] = 0.10; out[..., 3] = a
    return out
