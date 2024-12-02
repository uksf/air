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
    };
    class UK3CB_BAF_M_CRV7_Base : MissileBase {
        ace_rearm_dummy = QGVAR(crv7);
        ACE_caliber = 70;
        ACE_hearing_caliber = 15;
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
    class ammo_Missile_BIM9X : ammo_Missile_ShortRangeAABase {
        ace_rearm_dummy = QGVAR(ammo_Missile_BIM9X);
    };
    class M_Air_AA : MissileBase {
        ace_rearm_dummy = QGVAR(ammo_Missile_AIM132);
    };
    class ammo_Missile_MediumRangeAABase : MissileBase {
        hit = 600; // 200
    };
    class ammo_Missile_AMRAAM_D : ammo_Missile_MediumRangeAABase {
        ace_rearm_dummy = QGVAR(ammo_Missile_AMRAAM_D);
    };
    class ace_aim120_d : ammo_Missile_AMRAAM_D {
        flightProfiles[] = { "Direct", "Loft" };
        class Direct {};
        class Loft {};
    };

class BulletBase;
class ammo_Penetrator_Base;
class ammo_Bomb_SmallDiameterBase;
class LaserBombCore;
class M_Scalpel_AT;
class B_35mm_AA;

#include "ammoSets\bombs.hpp"
#include "ammoSets\bullets.hpp"
#include "ammoSets\hellfire.hpp"
// Brimstone uses hellfire classes
#include "ammoSets\brimstone.hpp"
};
