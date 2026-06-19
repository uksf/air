# CLAUDE.md — UKSF Air

UKSF custom aircraft addon set. Standalone repo (`uksf/air`), part of the UKSF modpack stack — same CBA/HEMTT conventions as `D:/arma/modpack`. Prefix `uksf_air`, mainprefix `u` → `\u\uksf_air\addons\<component>\`. **UKSF-owned** (no upstream).

Custom aircraft (Apache, C-130, F-35, Reaper), shared `common/` systems (RWR, AAE camshake, per-seat flares), and `weapons/` (missile guidance overrides, A2A/SAM config).

## Build

```bash
hemtt dev      # dev PBOs (symlinks into Arma)
hemtt check    # SQF + config lint (run before commit)
hemtt build    # release build
```
`hemtt` is on PATH. CI runs `hemtt check` + `hemtt build` on push/PR.

## Key dirs

```
addons/
  loadorder/   external dep ordering    main/        macros, version
  common/      RWR, AAE, flares         weapons/     missile guidance, A2A/SAM (CfgAmmo/Weapons/Vehicles, ammoSets/, weaponSets/)
  apache/ c130/ f35/ reaper/ slingloading/ tracking/ equipment/ radios/ patches/
```
CBA macro conventions (`GVAR`/`QGVAR`/`FUNC`/`EGVAR`, `ADDON=false/…/true`, `PREP`) are identical to modpack — see modpack `CLAUDE.md`.

## Gotchas

- **Active branch is `feature/air-defence-engagement-overhaul`, not `main`.** `main` is behind. Check which branch before assuming what's shipped.
- **Config overrides must onion-walk** 3rd-party parent chains (forward-decl every non-overridden ancestor, `: Parent` on the override path). `hemtt check` enforces parent-present (L-C04) but **misses runtime config-merge failures** — verify real parent chains against the config cache.
- **PROTECTED classes — never modify** (UKSF kit inherits from them): `missiles_ASRAAM`, `weapon_AMRAAMLauncher`, `M_Air_AA*`, `ammo_Missile_AMRAAM_*`, `rksla3_ammo_meteor`, `ace_missile_aim9_aim132`, `ace_missile_aim120_aim120Launcher`, `M_Titan_AA` base. Enemy-AA overrides must stay under the UKSF range envelope (BVR ~12–13 km, WVR IR ~5–6 km, radar SAM ~8–10 km, AAA ~2.5–4 km).
- ACE-side ammo edits for air weapons live in the **UKSF ACE fork** (`D:/arma/ace`, branch `uksfcustom`) — safe to patch, but commit them there too.

## Brain & skills

Brain vault (`E:/Workspace/workshop/Brain`, via `mcp__brain__*`) — read before non-trivial work:
- `work/arma-uksf_air/index.md` + `backlog.md` — work hub, in-flight overhaul tasks, full PROTECTED-class list & range envelope
- `concepts/ace-missileguidance-seeker-params-under-subclass.md`, `concepts/meteor-config-tuning-head-on.md`, `concepts/arma-config-patch-merge-semantics.md`
- `decisions/ace-missileguidance-route2-in-place-patch.md` — patch base class, never duplicate ammo classes
- `entities/arma3-modpack-stack.md`, `entities/uksf-workspace-layout.md`

Skills: `arma-config-syntax` (before any `.cpp`/`.hpp` edit), `arma-config-cache` (class/inheritance lookups), `sqf-deep-review`, `sqf-command-lookup`, `arma-dev-test-server`, `uksf-server`.
