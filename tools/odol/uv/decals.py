import math
import numpy as np
from PIL import Image, ImageDraw, ImageFont, ImageFilter

# Redraws the visible stencils of the EAWS decal sheets as vector art at 4096. Coordinates are in the
# original 2048 sheet; everything is drawn at 8192 and downsampled. Areas not redrawn keep a Lanczos
# upscale of the original, so faces that sample them still find the same content.
K = 4                                   # 2048 -> 8192
FONT = 'C:/Windows/Fonts/bahnschrift.ttf'
RED = (150, 12, 18, 236)
WHITE = (238, 238, 236, 236)
DARK = (38, 38, 40, 236)

def font(px, style=b'Bold'):
    f = ImageFont.truetype(FONT, max(4, int(px * K)))
    f.set_variation_by_name(style)
    return f

def P(*xy): return [(x * K, y * K) for x, y in zip(xy[0::2], xy[1::2])]

def text(d, s, cx, cy, h, fill, style=b'Bold', maxw=None):
    """Centre text on (cx, cy), cap height about h, squeezed horizontally to fit maxw if needed."""
    f = font(h * 1.38, style)
    l, t, r, b = d.textbbox((0, 0), s, font=f, anchor='ls')
    w = r - l
    if maxw and w > maxw * K:
        f = font(h * 1.38 * maxw * K / w, style); l, t, r, b = d.textbbox((0, 0), s, font=f, anchor='ls'); w = r - l
    d.text((cx * K - w / 2 - l, cy * K + (b - t) / 2 - b), s, font=f, fill=fill, anchor='ls')

def fit(img, s, x0, x1, cy, h, fill, style=b'SemiBold'):
    """Draw text stretched to span x0..x1, cap height about h, centred on cy."""
    f = font(h * 1.38, style)
    l, t, r, b = ImageDraw.Draw(img).textbbox((0, 0), s, font=f, anchor='ls')
    tmp = Image.new('RGBA', (r - l + 4, b - t + 4), (0, 0, 0, 0))
    ImageDraw.Draw(tmp).text((2 - l, 2 - t), s, font=f, fill=fill, anchor='ls')
    tmp = tmp.resize((int((x1 - x0) * K), tmp.height), Image.LANCZOS)
    img.alpha_composite(tmp, (int(x0 * K), int(cy * K - tmp.height / 2)))

def clear(img, box, fill=(0, 0, 0, 0)):
    ImageDraw.Draw(img).rectangle([v * K for v in box], fill=fill)

def triangle(d, ox, oy, lines):
    # measured on the top triangle: outer (1022,172) (1531,172) (1277,612); inner (1123,225) (1432,225) (1276,503)
    o = P(1022 + ox, 172 + oy, 1531 + ox, 172 + oy, 1277 + ox, 612 + oy)
    d.line(o + [o[0]], fill=RED, width=8 * K, joint='curve')
    d.polygon(P(1123 + ox, 225 + oy, 1432 + ox, 225 + oy, 1276 + ox, 503 + oy), fill=RED)
    text(d, 'DANGER', 1277 + ox, 199 + oy, 22, RED, maxw=200)
    y = 252 + oy
    for s in lines:
        text(d, s, 1277 + ox, y, 19, WHITE, maxw=200 - (y - 225 - oy) * 1.05)
        y += 32

def plate(d, box, lines):
    x0, y0, x1, y1 = box
    d.rounded_rectangle([v * K for v in box], radius=4 * K, fill=(176, 178, 176, 236), outline=(90, 90, 92, 236), width=2 * K)
    h = (y1 - y0 - 8) / len(lines)
    for i, s in enumerate(lines):
        f = font(h * 0.62, b'SemiBold Condensed')
        d.text(((x0 + 6) * K, (y0 + 5 + h * (i + 0.75)) * K), s, font=f, fill=DARK, anchor='ls')

def arrow(d, pts, cx, cy):
    poly = P(*pts)
    d.polygon(poly, fill=(152, 156, 160, 236))
    d.line(poly + [poly[0]], fill=(232, 188, 22, 236), width=10 * K, joint='curve')
    text(d, 'RESCUE', cx, cy, 40, (70, 72, 76, 236), maxw=300)

def clear_sheet():
    src = Image.open('decals_clear.png').convert('RGBA')
    img = src.resize((2048 * K, 2048 * K), Image.LANCZOS)
    d = ImageDraw.Draw(img)
    # break-glass instruction strip
    clear(img, (1546, 4, 1866, 95))
    text(d, 'BREAK GLASS - PULL HANDLE', 1706, 30, 15, DARK, b'SemiBold Condensed', maxw=300)
    text(d, 'TO EXTEND CABLE THEN TUG', 1706, 68, 15, DARK, b'SemiBold Condensed', maxw=300)
    # fire access door
    clear(img, (566, 6, 962, 470))
    d.rounded_rectangle(P(587, 24, 941, 441), radius=64 * K, outline=(8, 8, 8, 236), width=26 * K)
    d.ellipse(P(670, 152, 860, 342), fill=(8, 8, 8, 236))
    text(d, 'BREAK IN', 765, 248, 20, WHITE, maxw=150)
    text(d, 'FIRE ACCESS DOOR', 765, 377, 19, (8, 8, 8, 236), maxw=230)
    # ground point
    clear(img, (1780, 100, 2044, 362))
    for x0, y0, x1, y1 in ((1894, 109, 1916, 170), (1827, 168, 1983, 192), (1853, 212, 1957, 234), (1879, 256, 1931, 278)):
        d.rectangle(P(x0, y0, x1, y1), fill=(8, 8, 8, 236))
    text(d, 'GROUND HERE', 1910, 340, 20, (8, 8, 8, 236), maxw=245)
    # danger triangles and data plates
    clear(img, (1015, 165, 1540, 620)); clear(img, (1530, 398, 2048, 1340))
    triangle(d, 0, 0, ['EXPLOSIVE', 'CANOPY', 'AND', 'SEAT'])
    triangle(d, 512, 232, ['EJECTION', 'SEAT AND', 'CANOPY'])
    triangle(d, 512, 718, ['EJECTOR', 'LAUNCHER'])
    plate(d, (1366, 578, 1568, 674), ['EUROFIGHTER TYPHOON FGR4', 'BAE SYSTEMS  WARTON', 'SERIAL ZK315', 'FUEL JP-8 / F-34'])
    plate(d, (1900, 812, 2038, 864), ['ATTACH POINT', 'MAX LOAD 450 KG'])
    # rescue arrows
    clear(img, (4, 476, 1016, 724))
    arrow(d, (18, 558, 376, 558, 376, 531, 500, 618, 376, 706, 376, 678, 18, 678), 197, 618)
    arrow(d, (1005, 516, 646, 516, 646, 488, 524, 577, 646, 666, 646, 636, 1005, 636), 826, 576)
    # intake caution
    clear(img, (700, 662, 1434, 880))
    fit(img, 'CAUTION', 904, 1225, 713, 50, RED, b'Bold')
    fit(img, 'THE INLET DUCT AND A 25 FOOT ADJACENT AREA', 774, 1425, 785, 20, RED)
    fit(img, 'MUST BE FREE OF ALL LOOSE OBJECTS PRIOR', 729, 1408, 822, 20, RED)
    fit(img, 'TO AND DURING ENGINE OPERATION', 801, 1319, 851, 20, RED)
    # intake blanking cover
    clear(img, (436, 728, 652, 1002))
    d.ellipse(P(446, 742, 640, 990), fill=(126, 18, 20, 240), outline=(84, 10, 12, 240), width=5 * K)
    for i in range(8):
        a = i * math.pi / 4 + math.pi / 8
        x, y = 543 + 78 * math.cos(a), 866 + 105 * math.sin(a)
        d.ellipse(P(x - 4, y - 4, x + 4, y + 4), fill=(190, 190, 186, 240))
    for x0, y0, x1, y1 in ((534, 734, 552, 756), (534, 976, 552, 998), (440, 856, 458, 876), (628, 856, 646, 876)):
        d.rectangle(P(x0, y0, x1, y1), fill=(12, 12, 12, 240))
    return img

def pictogram(d, img):
    # seat-ejection hazard: amber field, black border, a seat firing up its rail and a person kept clear
    B = (14, 14, 14, 255)
    d.rectangle(P(33, 773, 407, 1004), fill=(236, 236, 232, 255))
    d.rectangle(P(44, 784, 396, 993), fill=B)
    d.rectangle(P(56, 796, 384, 981), fill=(228, 156, 28, 255))
    # canopy sill and rail
    d.line(P(70, 960, 250, 960), fill=B, width=9 * K)
    d.line(P(150, 960, 196, 820), fill=B, width=7 * K)
    # seat: back, pan, occupant head, rocket plume
    d.polygon(P(176, 850, 196, 856, 178, 922, 158, 916), fill=B)
    d.polygon(P(158, 916, 214, 926, 210, 940, 154, 930), fill=B)
    d.ellipse(P(190, 832, 214, 856), fill=B)
    d.polygon(P(168, 934, 186, 938, 172, 972, 160, 968), fill=B)
    # direction of travel
    d.polygon(P(246, 800, 268, 842, 253, 839, 243, 884, 231, 881, 241, 836, 226, 833), fill=B)
    # person standing clear, and the hazard boundary
    d.ellipse(P(318, 846, 340, 868), fill=B)
    d.polygon(P(320, 872, 340, 872, 344, 924, 336, 924, 334, 962, 326, 962, 324, 924, 316, 924), fill=B)
    for y in range(806, 972, 22):
        d.line(P(284, y, 284, y + 11), fill=B, width=5 * K)

def solid_sheet():
    src = Image.open('decals_solid.png').convert('RGBA')
    img = src.resize((2048 * K, 2048 * K), Image.LANCZOS)
    d = ImageDraw.Draw(img)
    pictogram(d, img)
    # no-paint area
    d.rectangle(P(1404, 1120, 1661, 1379), fill=(236, 236, 232, 255))
    d.rounded_rectangle(P(1410, 1126, 1655, 1373), radius=26 * K, fill=(126, 98, 70, 255))
    d.rounded_rectangle(P(1428, 1144, 1637, 1355), radius=16 * K, fill=(242, 246, 248, 255))
    text(d, 'NO PAINT', 1532, 1249, 26, (64, 64, 68, 255), maxw=180)
    # canopy jettison handle placard
    d.rectangle(P(1973, 1150, 2037, 1374), fill=(206, 34, 34, 255))
    for i, s in enumerate(('DO', 'NOT', 'PULL')):
        text(d, s, 2018, 1162 + i * 13, 8, (250, 250, 250, 255), maxw=30)
    for i, ch in enumerate('DANGER'):
        text(d, ch, 1988, 1215 + i * 24, 18, (250, 250, 250, 255))
    stripes = Image.new('RGBA', (26 * K, 150 * K), (240, 196, 20, 255)); sd = ImageDraw.Draw(stripes)
    for y in range(-30, 180, 18):
        sd.polygon(P(0, y, 26, y - 13, 26, y - 4, 0, y + 9), fill=(12, 12, 12, 255))
    img.alpha_composite(stripes, (2004 * K, 1203 * K))
    text(d, 'HANDLE', 2005, 1362, 8, (250, 250, 250, 255), maxw=56)
    # canopy jettison handle
    d.rectangle(P(674, 1461, 918, 1689), fill=(196, 198, 200, 255))
    c = (796, 1575)
    d.ellipse(P(c[0] - 112, c[1] - 112, c[0] + 112, c[1] + 112), fill=(92, 94, 98, 255))
    d.ellipse(P(c[0] - 98, c[1] - 98, c[0] + 98, c[1] + 98), fill=(214, 216, 218, 255))
    disc = Image.new('RGBA', (200 * K, 200 * K), (240, 196, 20, 255)); dd = ImageDraw.Draw(disc)
    for y in range(-200, 400, 34):
        dd.polygon(P(0, y, 200, y - 200, 200, y - 183, 0, y + 17), fill=(14, 14, 14, 255))
    mask = Image.new('L', disc.size, 0); ImageDraw.Draw(mask).ellipse((6 * K, 6 * K, 194 * K, 194 * K), fill=255)
    img.paste(disc, ((c[0] - 100) * K, (c[1] - 100) * K), mask)
    for i in range(8):
        a = i * math.pi / 4
        d.line(P(c[0] + 26 * math.cos(a), c[1] + 26 * math.sin(a), c[0] + 98 * math.cos(a), c[1] + 98 * math.sin(a)), fill=(206, 208, 210, 255), width=11 * K)
    d.ellipse(P(c[0] - 30, c[1] - 30, c[0] + 30, c[1] + 30), fill=(150, 152, 156, 255), outline=(70, 72, 76, 255), width=4 * K)
    return img

for name, fn in (('decals_clear', clear_sheet), ('decals_solid', solid_sheet)):
    fn().resize((4096, 4096), Image.LANCZOS).save(f'{name}_new.png')
    print('wrote', f'{name}_new.png')
