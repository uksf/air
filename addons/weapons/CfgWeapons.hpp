class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons {
    class Default;
    class CUP_weapon_mastersafe : Default {
        displayName = "Safe";
        displayNameMagazine = "Safe";
        shortNameMagazine = "Safe";
        nameSound = "cannon";
        cursor = "EmptyCursor";
        cursorAim = "EmptyCursor";
        magazines[] = { "FakeMagazine" };
        reloadMagazineSound[] = { "", 1, 1 };
        canLock = 0;
        burst = 0;
        reloadTime = 0.01;
        magazineReloadTime = 0.1;
    };

    class CannonCore;
    class CMFlareLauncher;
    class RocketPods;
    class MGun;
    class CUP_Vmlauncher_FFAR_veh;
    class missiles_DAR;
    class weapon_LGBLauncherBase;
    class weapon_SDBLauncher;
    class missiles_ASRAAM;
    class weapon_AMRAAMLauncher;
    class MissileLauncher;
    class Missile_AGM_02_Plane_CAS_01_F;

#include "weaponSets\a2a.hpp"
#include "weaponSets\bombs.hpp"
#include "weaponSets\bullets.hpp"
#include "weaponSets\flares.hpp"
#include "weaponSets\rockets.hpp"

#include "weaponSets\hellfire.hpp"
};
