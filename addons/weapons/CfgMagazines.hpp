class CfgMagazines {
    class VehicleMagazine;
    class GVAR(gunpod_magazine) : VehicleMagazine {
        scope = 1;
        displayName = "GAU-22/A";
        displayNameShort = "GAU-22/A";
        descriptionShort = "25mm External Gun Pod\n  Capacity: 220 rounds";
        ammo = QGVAR(gunpod_25mm_apex);
        count = 220;
        initSpeed = 1036;
        tracersEvery = 1;
        mass = 104;
        nameSound = "cannon";
    };
    class GVAR(gunpod_pylon) : GVAR(gunpod_magazine) {
        muzzlePos = "muzzle_start";
        muzzleEnd = "muzzle_end";
        model = QPATHTOF(data\uksf_air_weapons_gunpod.p3d);
        pylonWeapon = QGVAR(gunpod);
        hardpoints[] = { QGVAR(gunpod) };
    };

    class PylonMissile_Bomb_GBU12_x1;
    class PylonRack_Bomb_GBU12_x2;
    class PylonRack_Bomb_SDB_x4;
    class ace_missile_aim9_PylonRack_1Rnd_aim132;
    class PylonRack_Missile_AMRAAM_D_x1;
    class PylonRack_Missile_AMRAAM_D_x2;
    class PylonMissile_Missile_AMRAAM_D_INT_x1;
    class 6Rnd_ACE_Hellfire_AGM114K;
    class CUP_14Rnd_FFAR_M;
    class CUP_19Rnd_CRV7_FAT_M;
    class CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M;
    class PylonRack_3Rnd_ACE_Hellfire_AGM114L;
    class UK3CB_BAF_PylonPod_19Rnd_CRV7_PG_Base;

#include "magazineSets\a2a.hpp"
#include "magazineSets\bombs.hpp"
#include "magazineSets\brimstone.hpp"
#include "magazineSets\bullets.hpp"
#include "magazineSets\hellfire.hpp"
#include "magazineSets\rockets.hpp"
#include "magazineSets\meteor.hpp"
#include "magazineSets\spear3.hpp"
#include "magazineSets\stormshadow.hpp"
};
