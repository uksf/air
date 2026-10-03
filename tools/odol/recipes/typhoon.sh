#!/usr/bin/env bash
# Rebuilds the Typhoon PBO that uksf_air's typhoon addon expects, from the Workshop EAWS release
# (item 1337653467): hook on its own animation source, 13 dynamic pylons, and the memory points
# the addon uses. Everything else in the PBO is copied unchanged.
#
# usage: recipes/typhoon.sh <out.pbo>
# env:   ARMA (Arma 3 install), EAWS (Workshop EAWS_EF2000.pbo), WORK (keep intermediates there),
#        PLAN and CUTS (override the camo layout plan and its seam cuts, for layout work)
set -euo pipefail
here="$(cd "$(dirname "$0")" && pwd)"
odol="$here/../bin/Release/net10.0/odol.exe"
[ -x "$odol" ] || { echo "run tools/odol/build.sh first" >&2; exit 1; }
ARMA="${ARMA:-B:/Steam/steamapps/common/Arma 3}"
EAWS="${EAWS:-B:/Steam/steamapps/workshop/content/107410/1337653467/addons/EAWS_EF2000.pbo}"
out="${1:?usage: typhoon.sh <out.pbo>}"
plan="${PLAN:-$here/typhoon-camo.json}"
cuts="${CUTS:-$here/typhoon-cuts.json}"
if [ -n "${WORK:-}" ]; then work="$WORK"; mkdir -p "$work"; else work="$(mktemp -d)"; trap 'rm -rf "$work"' EXIT; fi

rm -f "$work/0.p3d" "$work/p0.p3d"   # hemtt extract keeps an existing output file
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
# The flame discs inside each nozzle were never weighted to their vrtule bones, so they never spun.
"$odol" bind "$work/1d.p3d" "$work/1e.p3d" 0 burner_fire_1_left "vrtule 0"
"$odol" bind "$work/1e.p3d" "$work/1f.p3d" 0 burner_fire_1_right "vrtule 1"
"$odol" remap "$work/1f.p3d" "$work/2.p3d" "@$here/typhoon.rules"
"$odol" add-proxies "$work/2.p3d" "$work/3.p3d" "$work/buzzard.p3d" pylonpod

# Model +Z points aft. Cockpit supply point, ejection seat start, and landing-gear contacts for AAE.
"$odol" add-point "$work/3.p3d" "$work/4.p3d" "$work/buzzard.p3d" doplnovani 0 0.7 -4.2
"$odol" add-point "$work/4.p3d" "$work/5.p3d" "$work/buzzard.p3d" pos_eject 0 0.2 -4.1
"$odol" add-point "$work/5.p3d" "$work/6.p3d" "$work/buzzard.p3d" wheel_1_contact -0.008 -0.707 -0.891
"$odol" add-point "$work/6.p3d" "$work/7.p3d" "$work/buzzard.p3d" wheel_2_contact 0.331 -0.581 1.057
"$odol" add-point "$work/7.p3d" "$work/8.p3d" "$work/buzzard.p3d" wheel_3_contact -0.322 -0.580 1.057

# Camo on two 4096 sheets: upper surfaces stay in camo1 and the underside moves to camo_lower, with
# the UV islands repacked by tools/odol/uv/plan.py. The pilot-view LOD keeps its UVs, under camo_pilot.
# Seams cut first so closed and strongly curved islands can be flattened in pieces.
if [ -f "$cuts" ]; then "$odol" cut-seams "$work/8.p3d" "$work/8c.p3d" 0 "$cuts"; else cp "$work/8.p3d" "$work/8c.p3d"; fi
"$odol" uv-split "$work/8c.p3d" "$work/9.p3d" 0 "$plan" camo1 camo_lower 'u\uksf_air\addons\typhoon\data\camo_lower_co.paa'
"$odol" move-sections "$work/9.p3d" "$work/10.p3d" 1100 'eaws_ef2000\data\top.paa' camo_pilot camo1,pylons
# Stencil sheets redrawn at 4096 in uksf_air, same layout.
"$odol" retexture "$work/10.p3d" "$work/11.p3d" 'eaws_ef2000\data\decals_clear.paa' 'u\uksf_air\addons\typhoon\data\decals_clear_ca.paa'
"$odol" retexture "$work/11.p3d" "$work/12.p3d" 'eaws_ef2000\data\decals_solid.paa' 'u\uksf_air\addons\typhoon\data\decals_solid_ca.paa'
# The drag-chute door samples a photo crop of sides.paa; the uksf_air copy paints that patch grey.
"$odol" retexture "$work/12.p3d" "$work/13.p3d" 'eaws_ef2000\data\sides.paa' 'u\uksf_air\addons\typhoon\data\sides_co.paa'
# Unlit formation-light strips: pale yellow-green instead of the EAWS white.
"$odol" retexture "$work/13.p3d" "$work/14.p3d" 'eaws_ef2000\data\night_markers.paa' 'u\uksf_air\addons\typhoon\data\formation_off_co.paa'
# Lit strips sampled one flat spot of the EAWS compass texture; give them the unlit strips' UVs and
# a lit copy of that texture, so the segments show in both states.
"$odol" uv-split "$work/14.p3d" "$work/15.p3d" 0 "$here/typhoon-formation.json" zbytek formation_on 'u\uksf_air\addons\typhoon\data\formation_on_co.paa'

# Antennas, sensor fairings and the tail tubes are a separate proxy model on the old EAWS top.paa,
# which hidden selections cannot reach: point it at plain airframe grey.
hemtt utils pbo extract "$EAWS" EAWS_EF2000parts.p3d "$work/p0.p3d" >/dev/null
"$odol" retexture "$work/p0.p3d" "$work/p1.p3d" 'eaws_ef2000\data\top.paa' 'u\uksf_air\addons\typhoon\data\parts_co.paa'

node "$here/../../pbo-replace.js" "$EAWS" "$work/a.pbo" EAWS_EF2000.p3d "$work/15.p3d"
node "$here/../../pbo-replace.js" "$work/a.pbo" "$out" EAWS_EF2000parts.p3d "$work/p1.p3d"
