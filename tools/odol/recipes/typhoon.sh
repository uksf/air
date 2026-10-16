#!/usr/bin/env bash
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

rm -f "$work/0.p3d" "$work/p0.p3d"
hemtt utils pbo extract "$EAWS" EAWS_EF2000.p3d "$work/0.p3d" >/dev/null
hemtt utils pbo extract "$ARMA/Addons/air_f_gamma.pbo" 'Plane_Fighter_03\Plane_Fighter_03_F.p3d' "$work/buzzard.p3d" >/dev/null

"$odol" set-source "$work/0.p3d" "$work/1.p3d" towhook hook
"$odol" set-source "$work/1.p3d" "$work/1a.p3d" rotor_L rotor loop
"$odol" set-source "$work/1a.p3d" "$work/1b.p3d" rotor_R rotor loop
"$odol" set-source "$work/1b.p3d" "$work/1c.p3d" vrtule_0 rotor loop
"$odol" set-source "$work/1c.p3d" "$work/1d.p3d" vrtule_1 rotor loop
"$odol" bind "$work/1d.p3d" "$work/1e.p3d" 0 burner_fire_1_left "vrtule 0"
"$odol" bind "$work/1e.p3d" "$work/1f.p3d" 0 burner_fire_1_right "vrtule 1"
"$odol" bind "$work/1f.p3d" "$work/1g.p3d" 0 "#8" "vrtule 0" 0 1.2 -1 1 4 4.4
"$odol" bind "$work/1g.p3d" "$work/1h.p3d" 0 "#8" "vrtule 1" -1.2 0 -1 1 4 4.4
"$odol" move "$work/1h.p3d" "$work/1i.p3d" 0 burner_fire_1_left 0 0 -1.44
"$odol" move "$work/1i.p3d" "$work/1j.p3d" 0 burner_fire_1_right 0 0 -1.44
"$odol" move "$work/1j.p3d" "$work/1k.p3d" 0 "#46" 0 0 -1.44
"$odol" remap "$work/1k.p3d" "$work/2.p3d" "@$here/typhoon.rules"
"$odol" add-proxies "$work/2.p3d" "$work/3.p3d" "$work/buzzard.p3d" pylonpod

"$odol" add-point "$work/3.p3d" "$work/4.p3d" "$work/buzzard.p3d" doplnovani 0 0.7 -4.2
"$odol" add-point "$work/4.p3d" "$work/5.p3d" "$work/buzzard.p3d" pos_eject 0 0.2 -4.1
"$odol" add-point "$work/5.p3d" "$work/6.p3d" "$work/buzzard.p3d" wheel_1_contact -0.008 -0.707 -0.891
"$odol" add-point "$work/6.p3d" "$work/7.p3d" "$work/buzzard.p3d" wheel_2_contact 0.331 -0.581 1.057
"$odol" add-point "$work/7.p3d" "$work/8.p3d" "$work/buzzard.p3d" wheel_3_contact -0.322 -0.580 1.057

if [ -f "$cuts" ]; then "$odol" cut-seams "$work/8.p3d" "$work/8c.p3d" 0 "$cuts"; else cp "$work/8.p3d" "$work/8c.p3d"; fi
"$odol" uv-split "$work/8c.p3d" "$work/9.p3d" 0 "$plan" camo1 camo_lower 'u\uksf_air\addons\typhoon\data\camo_lower_co.paa'
"$odol" move-sections "$work/9.p3d" "$work/10.p3d" 1100 'eaws_ef2000\data\top.paa' camo_pilot camo1,pylons
"$odol" retexture "$work/10.p3d" "$work/11.p3d" 'eaws_ef2000\data\decals_clear.paa' 'u\uksf_air\addons\typhoon\data\decals_clear_ca.paa'
"$odol" retexture "$work/11.p3d" "$work/12.p3d" 'eaws_ef2000\data\decals_solid.paa' 'u\uksf_air\addons\typhoon\data\decals_solid_ca.paa'
"$odol" retexture "$work/12.p3d" "$work/13.p3d" 'eaws_ef2000\data\sides.paa' 'u\uksf_air\addons\typhoon\data\sides_co.paa'
"$odol" retexture "$work/13.p3d" "$work/14.p3d" 'eaws_ef2000\data\night_markers.paa' 'u\uksf_air\addons\typhoon\data\formation_off_co.paa'
"$odol" uv-split "$work/14.p3d" "$work/15.p3d" 0 "$here/typhoon-formation.json" zbytek formation_on 'u\uksf_air\addons\typhoon\data\formation_on_co.paa'

hemtt utils pbo extract "$EAWS" EAWS_EF2000parts.p3d "$work/p0.p3d" >/dev/null
"$odol" retexture "$work/p0.p3d" "$work/p1.p3d" 'eaws_ef2000\data\top.paa' 'u\uksf_air\addons\typhoon\data\parts_co.paa'

"$odol" add-physx "$work/15.p3d" "$work/16.p3d" 11000
w="$work/16.p3d"; n=16
for spec in "Wheel_1 -0.005 -1.649 -2.486 0.236" "Wheel_2 1.929 -1.371 1.119 0.363" "Wheel_3 -1.928 -1.372 1.119 0.363"; do
    set -- $spec
    "$odol" add-point "$w" "$work/$((n+1)).p3d" "$work/buzzard.p3d" "${1}_center" "$2" "$3" "$4"
    rim_y=$(awk "BEGIN { print $3 - $5 }")
    "$odol" add-point "$work/$((n+1)).p3d" "$work/$((n+2)).p3d" "$work/buzzard.p3d" "${1}_rim" "$2" "$rim_y" "$4"
    w="$work/$((n+2)).p3d"; n=$((n+2))
done

node "$here/../../pbo-replace.js" "$EAWS" "$work/a.pbo" EAWS_EF2000.p3d "$w"
node "$here/../../pbo-replace.js" "$work/a.pbo" "$out" EAWS_EF2000parts.p3d "$work/p1.p3d"
