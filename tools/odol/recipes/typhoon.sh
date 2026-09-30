#!/usr/bin/env bash
# Rebuilds the Typhoon PBO that uksf_air's typhoon addon expects, from the Workshop EAWS release
# (item 1337653467): hook on its own animation source, 13 dynamic pylons, and the memory points
# the addon uses. Everything else in the PBO is copied unchanged.
#
# usage: recipes/typhoon.sh <out.pbo>
# env:   ARMA (Arma 3 install), EAWS (Workshop EAWS_EF2000.pbo)
set -euo pipefail
here="$(cd "$(dirname "$0")" && pwd)"
odol="$here/../bin/Release/net10.0/odol.exe"
[ -x "$odol" ] || { echo "run tools/odol/build.sh first" >&2; exit 1; }
ARMA="${ARMA:-B:/Steam/steamapps/common/Arma 3}"
EAWS="${EAWS:-B:/Steam/steamapps/workshop/content/107410/1337653467/addons/EAWS_EF2000.pbo}"
out="${1:?usage: typhoon.sh <out.pbo>}"
work="$(mktemp -d)"
trap 'rm -rf "$work"' EXIT

hemtt utils pbo extract "$EAWS" EAWS_EF2000.p3d "$work/0.p3d" >/dev/null
hemtt utils pbo extract "$ARMA/Addons/air_f_gamma.pbo" 'Plane_Fighter_03\Plane_Fighter_03_F.p3d' "$work/buzzard.p3d" >/dev/null

# The tail hook follows the gear by default; uksf_air defines the "hook" source and holds it stowed.
"$odol" set-source "$work/0.p3d" "$work/1.p3d" towhook hook
# Engine fans. rotor rises continuously, so clamp stops them after one turn; vrtule_0/1 used
# sources that do not exist.
"$odol" set-source "$work/1.p3d" "$work/1a.p3d" rotor_L rotor loop
"$odol" set-source "$work/1a.p3d" "$work/1b.p3d" rotor_R rotor loop
"$odol" set-source "$work/1b.p3d" "$work/1c.p3d" vrtule_0 rotor loop
"$odol" set-source "$work/1c.p3d" "$work/1d.p3d" vrtule_1 rotor loop
"$odol" remap "$work/1d.p3d" "$work/2.p3d" "@$here/typhoon.rules"
"$odol" add-proxies "$work/2.p3d" "$work/3.p3d" "$work/buzzard.p3d" pylonpod

# Model +Z points aft. Cockpit supply point, ejection seat start, and landing-gear contacts for AAE.
"$odol" add-point "$work/3.p3d" "$work/4.p3d" "$work/buzzard.p3d" doplnovani 0 0.7 -4.2
"$odol" add-point "$work/4.p3d" "$work/5.p3d" "$work/buzzard.p3d" pos_eject 0 0.2 -4.1
"$odol" add-point "$work/5.p3d" "$work/6.p3d" "$work/buzzard.p3d" wheel_1_contact -0.008 -0.707 -0.891
"$odol" add-point "$work/6.p3d" "$work/7.p3d" "$work/buzzard.p3d" wheel_2_contact 0.331 -0.581 1.057
"$odol" add-point "$work/7.p3d" "$work/8.p3d" "$work/buzzard.p3d" wheel_3_contact -0.322 -0.580 1.057

node "$here/../../pbo-replace.js" "$EAWS" "$out" EAWS_EF2000.p3d "$work/8.p3d"
