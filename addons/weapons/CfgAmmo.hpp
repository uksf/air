// A2A patch macros — frag warhead block + ACE guidance binding.
#define A2A_FRAG(charge,metal,fragSize) \
    ace_frag_skip = 0; \
    ace_frag_force = 1; \
    ace_frag_charge = charge; \
    ace_frag_metal = metal; \
    ace_frag_gurney_c = 2700; \
    ace_frag_gurney_k = 0.5; \
    ace_frag_classes[] = { QGVAR(frag_a2a_##fragSize) }

#define ACE_GUIDANCE(t) class ace_missileguidance : ace_missileguidance_type_##t { enabled = 1; }

class CfgAmmo {
    class MissileCore;
    class MissileBase : MissileCore {
        timeToLive = 60;
    };
    class ammo_Missile_LongRangeAABase;
    class CUP_R_70mm_Hydra_HE;
    class CUP_R_CRV7_C18_HE : CUP_R_70mm_Hydra_HE {
        ace_rearm_dummy = QGVAR(crv7);
        ACE_caliber = 70;
        ACE_hearing_caliber = 15;
        model = "\rksla3\rksla3-cvwp\rockets\rksl_crv7_m151_fired.p3d";
    };
    class UK3CB_BAF_M_CRV7_Base : MissileBase {
        ace_rearm_dummy = QGVAR(crv7);
        ACE_caliber = 70;
        ACE_hearing_caliber = 15;
        model = "\rksla3\rksla3-cvwp\rockets\rksl_crv7_m151_fired.p3d";
    };
    class M_AT;
    class rksla3_aw159_crv7_amo_M151 : M_AT {
        ace_rearm_dummy = QGVAR(crv7);
        ACE_caliber = 70;
        ACE_hearing_caliber = 15;
    };
    class ammo_Missile_ShortRangeAABase : MissileBase {
        hit = 400; // 130
    };
    // AIM-9X Sidewinder: ~9.4kg WDU-17 annular blast-frag. Vanilla short-range base
    // reference: iH=85 iHR=10. Tightened iHR for frag-dominant kill profile.
    class ammo_Missile_BIM9X : ammo_Missile_ShortRangeAABase {
        ace_rearm_dummy = QGVAR(ammo_Missile_BIM9X);
        indirectHit = 85;
        indirectHitRange = 4;
        A2A_FRAG(1700,3600,sr);
        ACE_GUIDANCE(Sidewinder);
    };
    class ammo_Missile_MediumRangeAABase : MissileBase {
        hit = 600; // 200
    };
    // AIM-120D AMRAAM: ~22kg WDU-33 blast-frag. Vanilla medium-range base reference:
    // hit=600 iH=125 iHR=13. Tightened iHR for frag-dominant kill profile.
    class ammo_Missile_AMRAAM_D : ammo_Missile_MediumRangeAABase {
        ace_rearm_dummy = QGVAR(ammo_Missile_AMRAAM_D);
        indirectHit = 125;
        indirectHitRange = 5;
        A2A_FRAG(3800,8000,mr);
        ACE_GUIDANCE(AMRAAM);
    };
    // AIM-120C AMRAAM: same WDU-33 ~22kg blast-frag warhead family as D.
    class ammo_Missile_AMRAAM_C : ammo_Missile_MediumRangeAABase {
        indirectHit = 120;
        indirectHitRange = 5;
        A2A_FRAG(3600,7800,mr);
        ACE_GUIDANCE(AMRAAM);
    };
    // FIM-92 Stinger family - vanilla NATO Titan MANPADS. RHS Stinger
    // (rhs_ammo_fim92_missile) inherits this and picks up Stinger guidance + frag.
    // CUP/RHS Strela-2 + Igla are leaf-overridden in sam.hpp because their warheads
    // are smaller than Stinger. Defined here (not in sam.hpp) because M_Zephyr below
    // extends it and HEMTT requires the parent to be declared in the same file.
    class M_Titan_AA : MissileBase {
        indirectHit = 50;
        indirectHitRange = 3;
        A2A_FRAG(1000,2000,manpad);
        ACE_GUIDANCE(Stinger);
    };
    // AIM-120A AMRAAM (BIS "Zephyr"): vanilla MR base for AAF Buzzard etc. Inherits from
    // M_Titan_AA; explicit ace_missileguidance override needed so it doesn't fall through
    // to the type_Stinger we attach to M_Titan_AA.
    class M_Zephyr : M_Titan_AA {
        indirectHit = 120;
        indirectHitRange = 5;
        A2A_FRAG(3400,7600,mr);
        ACE_GUIDANCE(AMRAAM);
    };
    // R-77 (AA-12 Adder): ~22.5kg expanding-rod blast-frag, BVR active radar.
    class ammo_Missile_AA_R77 : ammo_Missile_MediumRangeAABase {
        indirectHit = 120;
        indirectHitRange = 5;
        A2A_FRAG(3500,7500,mr);
        ACE_GUIDANCE(R77);
    };
    // Vanilla short-range AA missile (Cheetah/Tigris secondary, AIM-9M analog):
    // 9.4kg WDU-17 family; matches BIM9X warhead chemistry.
    class Missile_AA_04_F : MissileBase {
        indirectHit = 85;
        indirectHitRange = 4;
        A2A_FRAG(1700,3600,sr);
        ACE_GUIDANCE(Sidewinder);
    };
    // R-74 derivative (vanilla CSAT short-range AA, R-73 family successor).
    class Missile_AA_03_F : Missile_AA_04_F {
        ace_frag_charge = 1800;
        ace_frag_metal = 4000;
        ACE_GUIDANCE(R74);
    };
    // R-73 (AA-11 Archer): ~7.4kg blast-frag short-range A2A, IR seeker.
    class ammo_Missile_AA_R73 : ammo_Missile_ShortRangeAABase {
        indirectHit = 85;
        indirectHitRange = 4;
        A2A_FRAG(1800,4000,sr);
        ACE_GUIDANCE(R73);
    };
    // RIM-116 RAM: 9.1kg WDU-17/B annular blast-frag, naval CIWS.
    class ammo_Missile_rim116 : ammo_Missile_ShortRangeAABase {
        indirectHit = 110;
        indirectHitRange = 5;
        A2A_FRAG(3600,5500,naval_ciws);
        ACE_GUIDANCE(RAM);
    };
    // RIM-162 ESSM: ~39kg blast-frag warhead, naval medium-range SAM.
    class ammo_Missile_rim162 : ammo_Missile_MediumRangeAABase {
        indirectHit = 240;
        indirectHitRange = 8;
        A2A_FRAG(10000,28000,naval_mr);
        ACE_GUIDANCE(ESSM);
    };
    // MIM-104 Patriot PAC-2: M248 ~91kg blast-frag, long-range strategic SAM.
    class ammo_Missile_mim145 : ammo_Missile_LongRangeAABase {
        indirectHit = 400;
        indirectHitRange = 10;
        A2A_FRAG(24000,67000,sam_lr);
        ACE_GUIDANCE(Patriot);
    };
    // S-400 family (vanilla "s750"): treat as 48N6/9M96 mid-tier - large blast-frag warhead.
    class ammo_Missile_s750 : ammo_Missile_mim145 {
        ace_frag_charge = 15000;
        ace_frag_metal = 35000;
        ACE_GUIDANCE(S400);
    };
    // M_70mm_SAAMI: helo-launched Stinger (Pawnee/Hellcat). FIM-92 3kg annular blast-frag.
    class M_70mm_SAAMI : MissileBase {
        indirectHit = 50;
        indirectHitRange = 3;
        A2A_FRAG(1000,2000,manpad);
        ACE_GUIDANCE(Stinger);
    };

class BulletBase;
class ammo_Penetrator_Base;
class LaserBombCore;
class M_Scalpel_AT;
class B_35mm_AA;

#include "ammoSets\rockets.hpp"
#include "ammoSets\a2a.hpp"
#include "ammoSets\bombs.hpp"
#include "ammoSets\bullets.hpp"
#include "ammoSets\hellfire.hpp"
#include "ammoSets\brimstone.hpp"
#include "ammoSets\meteor.hpp"
#include "ammoSets\spear3.hpp"
#include "ammoSets\stormshadow.hpp"
#include "ammoSets\sam.hpp"
};
