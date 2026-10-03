"""Typhoon camo sheet painter. Run from this folder, in order:

    odol export-obj <recipe model before uv-split> 0 $TYPHOON_WORK/t3.obj   (and 1100 -> p3.obj)
    gbuf.py    texel g-buffers (position, normal) for the upper, lower and pilot sheets
    ao.py      ambient occlusion per texel
    edges.py   part outlines from mesh boundaries
    lines.py   RKSL panel lines projected onto the EAWS airframe, filtered
    paint.py   colour, normal and specular sheets into $TYPHOON_WORK/out
    then ImageToPAA each out/<sheet>_<co|nohq|smdi>.png to addons/typhoon/data/camo_<sheet>_*.paa

Also in WORK: sides.png (EAWS sides.paa as PNG). In SRC: align.json (RKSL to EAWS fit),
rksl/rk0.obj and rksl/png/efa_ext1_co.png. RKSL files are a positional reference only.
"""
import os
# WORK holds generated data (OBJ exports, g-buffers, AO, line sets, output sheets); SRC holds the
# third-party reference material (RKSL and CJ sheets, alignment), which is never committed.
WORK = os.environ.get('TYPHOON_WORK', os.path.expanduser('~/.agent-scratch/typhoon-work')).rstrip('/') + '/'
SRC = os.environ.get('TYPHOON_SRC', os.path.expanduser('~/.agent-scratch/typhoon-src')).rstrip('/') + '/'
