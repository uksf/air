import numpy as np

# APU outlet on the port wing-body fillet, painted on the surface in 3D (photo: ZJ923). A planar
# decal cannot follow the fillet's curve, so the soot and the hole are functions of texel position.
R = 0.054                                  # hole radius, metres
SOOT_LEN, SOOT_BEND = 0.42, 0.30           # soot rises this far, drifting this far aft at the top
HOLE_DARK, EDGE = 0.063, 0.36


def frame(n0):
    """Surface frame at the outlet: up (+Y) and aft (+Z, file space) flattened onto the surface."""
    up = np.array([0, 1, 0.]) - n0[1] * n0; up /= np.linalg.norm(up)
    aft = np.cross(n0, up)
    if aft[2] < 0: aft = -aft
    return up, aft


def apu(P, Nn, P0, n0, noise):
    """Per texel: soot alpha, and hole colour and alpha. noise(P) is smooth noise near unit scale."""
    q = P - P0
    # the soot climbs the near-vertical fuselage side: measure it by model height and aft distance
    v, u = q[:, 1], q[:, 2]
    near = (P[:, 0] > 0.5) & (Nn[:, 0] > 0.1) & (np.abs(u) < 0.6) & (v > -0.15) & (v < SOOT_LEN + 0.1)
    # soot: a wide teardrop, as wide as the hole at its base, leaning aft, with a short tail
    t = np.clip(v / SOOT_LEN, 0, 1)
    centre = SOOT_BEND * t ** 1.4
    width = R * 1.1 + 0.12 * np.sin(np.pi * np.clip(t * 0.8, 0, 1)) ** 0.7
    soot = np.exp(-np.abs((u - centre) / width) ** 2.6) * (1 - t) ** 0.8 * (1 - 0.5 * t)
    soot *= np.clip(v / (0.5 * R) + 0.6, 0, 1) * (Nn[:, 0] > 0.45)   # starts at the hole's top edge, not on the wing
    soot *= 1 + 0.12 * noise(P)
    soot = np.clip(soot * 1.05, 0, 0.9) * near
    # hole: a dark disc with a thin grey edge; the normal map gives it depth
    up, aft = frame(n0)
    v, u, z = q @ up, q @ aft, q @ n0
    near = near & (np.abs(z) < 0.1)
    r = np.sqrt(u ** 2 + v ** 2) / R
    edge = np.clip(1 - np.abs(r - 1.06) / 0.06, 0, 1)
    shade = HOLE_DARK * (1 - edge) + EDGE * edge
    rgb = np.repeat(shade[:, None], 3, 1)
    a = np.clip((1.12 - r) / 0.04, 0, 1) * near
    return soot, rgb, a
