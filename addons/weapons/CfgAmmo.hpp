class CfgAmmo {
    class MissileCore;
    class MissileBase : MissileCore {
        timeToLive = 60;
    };
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
        ace_frag_skip = 0;
        ace_frag_force = 1;
        ace_frag_charge = 1700;
        ace_frag_metal = 3600;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_randomFraction = 0.05;
        ace_frag_classes[] = { QGVAR(frag_a2a_sr) };
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
        ace_frag_skip = 0;
        ace_frag_force = 1;
        ace_frag_charge = 3800;
        ace_frag_metal = 8000;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = 0.5;
        ace_frag_randomFraction = 0.05;
        ace_frag_classes[] = { QGVAR(frag_a2a_mr) };
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
};
