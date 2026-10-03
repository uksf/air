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
- `bind` weights an unweighted sectional selection to a bone, so the bone's animation moves it. Each section can only reference a window of bones, so `bind` also moves the section's window. If an animation cycles but nothing moves, check `bones <lod>` for a bone with 0 vertices and `selection <lod> <name>` for the geometry that should follow it. Visual-LOD selections are sectional, so `points` shows 0 vertices for them. When the geometry has no selection, `sections <lod> <box>` finds its section; bind it as `#N`, with a box to take only part of it.
- The memory-LOD edits copy their structure from a template model. The A-143 Buzzard (`air_f_gamma.pbo`, `Plane_Fighter_03\Plane_Fighter_03_F.p3d`) works. `add-proxies` only supports a memory LOD that has no faces yet.

## Pylon-menu picture

`odol export-obj <model> 0 v.obj`, `odol export-obj <model> geometry g.obj`, then `node tools/odol/silhouette.js v.obj out.png --clip g.obj --points points.json` renders a vanilla-style top view (2048x1024, nose left) and prints a `UIposition` for each pylon proxy position. Convert with `hemtt utils paa convert out.png loadout_ca.paa`. Spread boxes that land within about 0.05 of each other.

## Texture layout and art

The EAWS camo was one planar top/bottom projection on a single sheet. The recipe moves it onto two 4096 sheets and ships redrawn art in the `typhoon` addon.

- `uv-split` applies a layout plan to one LOD: each UV island either moves to `(old - box) * s + pos`, which keeps the stored tangents valid, or takes explicit per-vertex UVs and tangents. Sheet-B faces are reordered behind the sheet-A faces of their section, which is then split; the new sections take the new texture and selection, and every face, section and proxy reference is remapped. `AreaOverTex` is scaled by the change in total UV area, because the engine picks mips from it. A section whose UVs repeat past 0..1 is switched to wrapped addressing.
- `move-sections` gives the pilot-view LOD its own selection. That LOD is a separately simplified mesh whose islands do not match LOD 0, so it keeps its UVs and `uv/paint` paints its own sheet on the original layout.
- `retexture` points a model texture at another path, for art shipped in the addon.

The Python scripts in `uv/` build the layout plan, and `uv/paint/` paints the sheets. They need `numpy`, `scipy`, `pillow`, `opencv-python-headless`, `scikit-image` and `rectpack`.

1. `plan.py lod0.obj` assigns true UV islands (vertices joined by position and UV) to the upper or underside sheet and packs them by shape. `charts.py` re-flattens distorted islands into charts and writes the plan and seam cuts, `recipes/typhoon-camo.json` and `recipes/typhoon-cuts.json`.
2. `uv/paint/` builds the camo sheets from geometry: g-buffers, ambient occlusion, part outlines, panel lines, markings, and `_co`, `_nohq` (DirectX) and `_smdi` maps. `paint/paths.py` lists the run order, the `TYPHOON_WORK` and `TYPHOON_SRC` folders and the OBJ exports it needs. Third-party reference sheets stay in `TYPHOON_SRC` and are never committed.
3. `render.py` renders an OBJ with its textures from above, below and the side. Compare old and new renders to check a layout change before it reaches the engine.

`export-obj` writes V flipped (OBJ v = 1 - ODOL v). Build a UV plan from `vertices` output, which gives the stored UVs, or flip V back.

Convert with Arma 3 Tools `ImageToPAA`, which applies the `_co`, `_ca`, `_nohq` and `_smdi` formats.

## Limits

- Tested on ODOL v73 (the EAWS Typhoon and the UKSF F-35). Other versions may read but have not been edited.
- `Odol.cs` reaches BIS.P3D internals by reflection. Before moving the pin, run `roundtrip` and `recipes/typhoon.sh` and compare the output with the previous build.
- Do not use UKSFTA-BIS's ODOL-to-MLOD conversion as a check: it loses visual-LOD selection weights.
- The dedicated-server harness cannot check launch positions. It reports centred launches even for the F-35, so check store placement and launches on a client.
- The harness does not run probe SQF that contains `//` comments.
