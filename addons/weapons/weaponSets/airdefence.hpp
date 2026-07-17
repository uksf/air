// Air-defence engagement overhaul — enemy AA weapon tuning.
// Goal: AI commits at realistic ranges, missiles can't ripple-spam, AAA stops being a laser-beam.
// Scope: ENEMY-exclusive classes only. UKSF kit (missiles_ASRAAM / weapon_AMRAAMLauncher chains,
// M_Air_AA, AMRAAM-D, Meteor) is deliberately untouched.
// Included inside class CfgWeapons {}. Values resolved against config_5.23.11.cpp.
// reloadTime/range/probab tunable; see docs/plans/2026-06-01-air-defence-engagement-overhaul.md.

// ─────────────────────────────────────────────────────────────────────────────
// GROUP A — Enemy air-to-air missile launchers (range commitment + anti-spam reload)
// ─────────────────────────────────────────────────────────────────────────────

// R-73 Archer (To-201 Shikra) — IR WVR. Single weapon-level fire mode.
class weapon_R73Launcher : MissileLauncher {
    reloadTime = 3;
    midRange = 3500;
    midRangeProbab = 0.95;
    maxRange = 5500;
    maxRangeProbab = 0.7;
};

// R-77 Adder (Shikra) — active-radar BVR. Already fires at 12 km (maxRangeProbab 1); only de-spam + push midRange.
// LoalDistance is the active mode (modes[]={LoalDistance}); set values there (real parent MissileLauncher).
class weapon_R77Launcher : MissileLauncher {
    reloadTime = 4;
    midRange = 8000;
    class LoalDistance : MissileLauncher {
        reloadTime = 4;
        midRange = 8000;
    };
};

// AIM-120A "Zephyr" (A-143 Buzzard AA) — radar MR. Also the parent of CUP_Vmlauncher_AIM120_veh (CUP jets inherit).
class missiles_Zephyr : MissileLauncher {
    reloadTime = 4;
    midRange = 7000;
};

// AIM-9L Sidewinder (CUP F-15/F-16/A-10/AV-8B/AH) — IR WVR.
// Patch the _4Rnd ROOT (not CUP_Vmlauncher_AIM9L_veh leaf) so _2Rnd/_1Rnd/_Int and *_W aliases inherit reload+range.
class CUP_Vmlauncher_AIM9L_veh_4Rnd : MissileLauncher {
    reloadTime = 3;
    minRangeProbab = 0.3;
    midRange = 3500;
    midRangeProbab = 0.85;
    maxRange = 5500;
    maxRangeProbab = 0.6;
};

// CUP R-73 on L-39 / Su-25 / Su-34 (separate line from vanilla weapon_R73Launcher / Shikra).
// Parent chain: RocketPods <- Missile_AA_04 <- Missile_AA_03 <- CUP_Vmlauncher_R73_veh.
class CUP_Vmlauncher_R73_veh : Missile_AA_03_Plane_CAS_02_F {
    reloadTime = 3;
    midRange = 3500;
    midRangeProbab = 0.85;
    maxRange = 5500;
    maxRangeProbab = 0.7;
};

// ─────────────────────────────────────────────────────────────────────────────
// GROUP B — Enemy SAM launchers (anti-spam reload + range commitment)
// ─────────────────────────────────────────────────────────────────────────────

// 2S6 Tunguska 9M311 (radar SAM). NB: base inherits missiles_titan's modes[]={Player,TopDown} and
// never set modes[]={"this"}, so its top-level ranges were dead — pin modes[]={"this"} to make them
// authoritative (engage to the intended 8 km). 9M311M inherits this + keeps its longer reach.
class CUP_Vmlauncher_9M311_veh : missiles_titan {
    modes[] = {"this"};
    reloadTime = 5;
    midRange = 6500;
    maxRangeProbab = 0.6;
};
class CUP_Vmlauncher_9M311M_veh : CUP_Vmlauncher_9M311_veh {
    midRange = 8000;
    maxRange = 10000;
};

// Avenger / Linebacker FIM-92 Stinger (IR SAM). Already fires to 6 km @ 0.9 — real limiter was the
// 2.5 km platform IR sensor (raised in CfgVehicles). Here: de-spam + push midRange out.
class CUP_Vmlauncher_Stinger_vehicle_veh : missiles_titan {
    reloadTime = 5;
    midRange = 3500;
};
class CUP_Vmlauncher_Stinger_twice_veh : CUP_Vmlauncher_Stinger_vehicle_veh {
    reloadTime = 5;
};

// Ka-50 9K38 Igla (IR SAM on helicopter mount). Platform IR sensor raised in CfgVehicles.
class CUP_Vmlauncher_Igla_twice_veh : missiles_titan {
    reloadTime = 5;
    midRange = 3500;
};

// RBS-70 (laser beam-rider, static). Visual/LOS limited; push commitment range + de-spam.
class CUP_Vmlauncher_RBS70_veh : MissileLauncher {
    reloadTime = 5;
    midRange = 5000;
    maxRange = 6500;
    maxRangeProbab = 0.6;
};

// Vanilla static Titan AA (B/O/I_static_AA_F): its Player mode already reaches 5 km @ 0.9 — the real
// limiter is the IR seeker (3.5 km + can't lock >250 m/s jets), fixed in CfgAmmo (M_Titan_AA_static).
// No weapon change needed here (avoids a deep Player-mode override on the shared missiles_titan chain).

// ─────────────────────────────────────────────────────────────────────────────
// GROUP C — MANPADS infantry (probability only — single-shot disposable, no reload change)
// Patch the scope=1 *_Loaded bases; the usable launchers inherit.
// ─────────────────────────────────────────────────────────────────────────────

// FIM-92 Stinger
class CUP_launch_FIM92Stinger_Loaded : Launcher_Base_F {
    midRange = 3800;
    midRangeProbab = 0.85;
    maxRangeProbab = 0.5;
};
// 9K38 Igla
class CUP_launch_Igla_Loaded : Launcher_Base_F {
    midRange = 4200;
    midRangeProbab = 0.85;
    maxRangeProbab = 0.5;
};
// 9K32 Strela-2 (seeker caps ~3.7 km — keep midRange inside that)
class CUP_launch_9K32Strela_Loaded : Launcher_Base_F {
    midRange = 3200;
    midRangeProbab = 0.85;
    maxRangeProbab = 0.5;
};

// ─────────────────────────────────────────────────────────────────────────────
// GROUP F — AAA guns: aiDispersionCoefX/Y = AI aim-error multiplier (engine default 1 = laser).
// Set to 8 to match the in-game Tunguska 2A38M AA autocannon. Plus far-mode range/commitment.
// aiDispersionCoefX/Y is read at weapon top level (vanilla GAU-8 precedent).
// ─────────────────────────────────────────────────────────────────────────────

// aiDispersionCoefX/Y is read from the FIRING MODE (verified: Tunguska 2A38M carries 8/8 only in its
// LowROF mode, its weapon-level value is 1). So set it on the base mode every combat mode inherits
// (manual/Manual), AND weapon-level as a belt-and-braces fallback. 8 matches the Tunguska precedent.

// Vanilla 35 mm GDF (AMV-7 Cheetah / ZSU-39 Tigris). Modes lowercase manual/close/far (far:close:manual).
class autocannon_35mm : CannonCore {
    aiDispersionCoefX = 8;
    aiDispersionCoefY = 8;
    class manual;
    class close : manual {
        aiDispersionCoefX = 8;
        aiDispersionCoefY = 8;
    };
    class far : close {
        midRange = 2500;
        midRangeProbab = 0.8;
        maxRange = 3500;
        maxRangeProbab = 0.5;
    };
};

// Vanilla Praetorian 1C CIWS. Range already 3 km; raise commitment + scatter. Modes manual/close/far.
class weapon_Cannon_Phalanx : CannonCore {
    aiDispersionCoefX = 8;
    aiDispersionCoefY = 8;
    class manual;
    class close : manual {
        aiDispersionCoefX = 8;
        aiDispersionCoefY = 8;
    };
    class far : close {
        maxRangeProbab = 0.5;
    };
};

// CUP ZSU-23-4 Shilka / ZU-23-2 (AZP-23 Amur). Modes Manual/Close/Far (Far:Close:Manual). _2_veh inherits.
class CUP_Vacannon_AZP23_veh : CannonCore {
    aiDispersionCoefX = 8;
    aiDispersionCoefY = 8;
    class Manual;
    class Close : Manual {
        aiDispersionCoefX = 8;
        aiDispersionCoefY = 8;
    };
    class Far : Close {
        midRange = 2000;
        midRangeProbab = 0.6;
        maxRange = 2500;
        maxRangeProbab = 0.5;
    };
};
// Towed / Hilux ZU-23-2 (separate class : CannonCore, identical fire table).
class CUP_Vacannon_2A14_veh : CannonCore {
    aiDispersionCoefX = 8;
    aiDispersionCoefY = 8;
    class Manual;
    class Close : Manual {
        aiDispersionCoefX = 8;
        aiDispersionCoefY = 8;
    };
    class Far : Close {
        midRange = 2000;
        midRangeProbab = 0.6;
        maxRange = 2500;
        maxRangeProbab = 0.5;
    };
};

// CUP 2S6 Tunguska 2A38M 30 mm gun. Modes inherit LowROF (already 8/8 from GSh302K) — add weapon-level
// fallback and extend the Far-mode commitment range. Modes Close/Far (Far:Close:LowROF).
class CUP_Vacannon_2A38M_veh : CUP_Vacannon_GSh302K_veh {
    aiDispersionCoefX = 8;
    aiDispersionCoefY = 8;
    class Close;
    class Far : Close {
        midRange = 1800;
        midRangeProbab = 0.6;
        maxRange = 2500;
        maxRangeProbab = 0.5;
    };
};

// CUP M163 VADS M168 Vulcan 20 mm. Modes Manual/close/short/medium/Far. Naval Phalanx inherits this.
class CUP_Vacannon_M168_M163VADS : CannonCore {
    aiDispersionCoefX = 8;
    aiDispersionCoefY = 8;
    class Manual;
    class close : Manual {
        aiDispersionCoefX = 8;
        aiDispersionCoefY = 8;
    };
    class Far : close {
        midRange = 1500;
        midRangeProbab = 0.6;
        maxRange = 2500;
        maxRangeProbab = 0.4;
    };
};
