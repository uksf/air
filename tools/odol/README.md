# odol

Inspects and edits binarized (ODOL) Arma 3 models in place, for third-party aircraft that ship without source MLODs. Built on [UKSFTA-BIS](https://github.com/UKSFTA/UKSFTA-BIS) (MIT), pinned in `build.sh`.

Used to give the EAWS Typhoon dynamic pylons: `recipes/typhoon.sh` rebuilds the PBO that the `typhoon` addon expects from the Workshop release.

## Build

```bash
tools/odol/build.sh        # clones UKSFTA-BIS into .deps at the pinned commit, builds bin/Release/net10.0/odol.exe
tools/odol/bin/Release/net10.0/odol.exe --help
```

Needs the .NET 10 SDK, `git`, `hemtt` and `node`.

## Workflow

1. Extract the model: `hemtt utils pbo extract <addon.pbo> <model.p3d> <out.p3d>`.
2. Inspect it: `info`, `proxies`, `points <lod>`, `anims`. Compare with a working vanilla or UKSF model the same way.
3. Edit with a chain of commands, one output feeding the next. Every write re-reads the output and fails unless it serializes to the same bytes.
4. Put the model back: `node tools/pbo-replace.js <in.pbo> <out.pbo> <model.p3d> <edited.p3d>`. The rebuilt PBO is unsigned.
5. Test in the dev-server harness, then on a client. Put the chain in `recipes/` so the result can be rebuilt when the mod updates.

Run `odol roundtrip <model>` on any new model first. Zero differing bytes means the reader and writer handle that file; anything else means do not edit it.

## What the edits mean

- `remap` retargets proxies and renames their selections. Dynamic pylons need a `pylonpod` proxy per pylon in the visual LODs, numbered to match `TransportPylonsComponent` pylon N. Other proxy types do not take pylon stores.
- `add-proxies` copies matching LOD 0 proxies into the memory LOD. The engine reads store and launch positions from memory-LOD proxies, so pylons without them load but fire from a fallback point.
- `add-point` adds a named memory point, for example `doplnovani` (inventory and supply position), `pos_eject`, or `wheel_N_contact` for AAE.
- `set-source` points a model animation at another source: an engine source such as `rotor`, or a config `AnimationSources` entry the config defines. Continuously rising sources such as `rotor` need address `loop`; `clamp` stops after one turn. `anims` shows each animation's source, address and bound LODs.
- The memory-LOD edits copy their structure from a template model. The A-143 Buzzard (`air_f_gamma.pbo`, `Plane_Fighter_03\Plane_Fighter_03_F.p3d`) works. `add-proxies` only supports a memory LOD that has no faces yet.

## Pylon-menu picture

`odol export-obj <model> 0 v.obj`, `odol export-obj <model> geometry g.obj`, then `node tools/odol/silhouette.js v.obj out.png --clip g.obj --points points.json` renders a vanilla-style top view (2048x1024, nose left) and prints a `UIposition` for each pylon proxy position. Convert with `hemtt utils paa convert out.png loadout_ca.paa`. Spread boxes that land within about 0.05 of each other.

## Limits

- Tested on ODOL v73 (the EAWS Typhoon and the UKSF F-35). Other versions may read but have not been edited.
- `Odol.cs` reaches BIS.P3D internals by reflection. Before moving the pin, run `roundtrip` and `recipes/typhoon.sh` and compare the output with the previous build.
- Do not use UKSFTA-BIS's ODOL-to-MLOD conversion as a check: it loses visual-LOD selection weights.
- The dedicated-server harness cannot check launch positions. It reports centred launches even for the F-35, so check store placement and launches on a client.
- The harness does not run probe SQF that contains `//` comments.
