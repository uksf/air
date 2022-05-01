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
    class GVAR(gunpod) : CannonCore {
        holdsterAnimValue = 1;
        scope = 1;
        displayName = "GAU-22/A";
        displayNameMagazine = "GAU-22/A 25mm";
        shortNameMagazine = "GAU-22/A 25mm";
        nameSound = "cannon";
        cursor = "EmptyCursor";
        cursorAim = "mg";
        cursorSize = 1;
        magazines[] = { QGVAR(gunpod_magazine),QGVAR(gunpod_pylon) };
        canLock = 0;
        ballisticsComputer = "4 + 8";
        missileLockCone = 20;
        weaponLockSystem = 3;
        modes[] = { "manual", "close", "near", "medium", "far" };
        class GunParticles {
            class Effect {
                effectName = "MachineGun1";
                positionName = "muzzle_start";
                directionName = "muzzle_dir";
            };
        };
        class manual : CannonCore {
            displayName = "GAU-22/A";
            autoFire = 1;
            sounds[] = { "StandardSound" };
            class StandardSound {
                begin1[] = { "\A3\Sounds_F_Jets\weapons\cannons\Fighter_Gun_30mm_1", 2, 1, 3000 };
                begin2[] = { "\A3\Sounds_F_Jets\weapons\cannons\Fighter_Gun_30mm_2", 2, 1, 3000 };
                begin3[] = { "\A3\Sounds_F_Jets\weapons\cannons\Fighter_Gun_30mm_3", 2, 1, 3000 };
                soundBegin[] = { "begin1", 0.33, "begin2", 0.33, "begin3", 0.34 };
                soundsetshot[] = { "DS_AA_Closure_SoundSet", "DS_AA_Shot_SoundSet", "DS_autocannon_Tail_SoundSet" };
            };
            reloadTime = 0.02;
            dispersion = 0.006;
            soundContinuous = 0;
            soundBurst = 0;
            showToPlayer = 1;
            burst = 1;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 50;
            minRange = 1;
            minRangeProbab = 0.01;
            midRange = 2;
            midRangeProbab = 0.01;
            maxRange = 3;
            maxRangeProbab = 0.01;
            textureType = "fullAuto";
        };
        class close : manual {
            showToPlayer = 0;
            burst = 15;
            aiRateOfFire = 0.25;
            aiRateOfFireDistance = 400;
            minRange = 0;
            minRangeProbab = 0.05;
            midRange = 200;
            midRangeProbab = 0.7;
            maxRange = 400;
            maxRangeProbab = 0.2;
        };
        class near : close {
            burst = 10;
            aiRateOfFire = 0.5;
            aiRateOfFireDistance = 500;
            minRange = 300;
            minRangeProbab = 0.2;
            midRange = 400;
            maxRange = 500;
        };
        class medium : close {
            burst = 7;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 900;
            minRange = 400;
            midRange = 700;
            maxRange = 900;
        };
        class far : close {
            burst = 4;
            aiRateOfFire = 1.5;
            aiRateOfFireDistance = 1500;
            minRange = 800;
            minRangeProbab = 0.2;
            midRange = 1000;
            maxRange = 1500;
        };
    };

    class CMFlareLauncher;
    class GVAR(C130FlareLauncher) : CMFlareLauncher {
        modes[] = { "Single", "Burst1", "Burst2", "Burst3", "Burst4", "Burst5", "Burst6", "AIBurst" };
        class Single : Mode_SemiAuto {
            reloadTime = 0.125;
            autoFire = "false";
            displayName = "4F/-";
            burst = 1;
            multiplier = 4;
            sounds[] = { "StandardSound" };
            class StandardSound {
                begin1[] = { "A3\Sounds_F\weapons\HMG\HMG_grenade", 1, 1, 300 };
                soundBegin[] = { "begin1", 1 };
                weaponSoundEffect = "DefaultRifle";
            };
        };
        class Burst1 : Mode_Burst {
            reloadTime = 0.125;
            autoFire = "true";
            displayName = "40F/1.25S";
            burst = 10;
            sounds[] = { "StandardSound" };
            class StandardSound {
                begin1[] = { "A3\Sounds_F\weapons\HMG\HMG_grenade", 1, 1, 300 };
                soundBegin[] = { "begin1", 1 };
                weaponSoundEffect = "DefaultRifle";
            };
        };
        class Burst2 : Burst1 {
            reloadTime = 0.25;
            displayName = "40F/2.5S";
        };
        class Burst3 : Burst2 {
            reloadTime = 0.5;
            displayName = "40F/5S";
            burst = 10;
        };
        class Burst4 : Burst3 {
            reloadTime = 0.125;
            displayName = "80F/2.5S";
            burst = 20;
        };
        class Burst5 : Burst4 {
            reloadTime = 0.25;
            displayName = "80F/5S";
        };
        class Burst6 : Burst5 {
            reloadTime = 0.5;
            displayName = "80F/10S";
        };
    };
    class UK3CB_BAF_CMFlareLauncher : CMFlareLauncher {
        modes[] = { "Single", "Burst2", "Burst5", "Burst8", "AIBurst" };
        // Burst2 = 8/1s
        // Burst5 = 16/1s
        // Burst8 = 16/8s
    };

    class RocketPods;
    class ace_hellfire_launcher : RocketPods {
        displayName = "AGM-114K";
        magazines[] = { "2Rnd_ACE_Hellfire_AGM114K", "4Rnd_ACE_Hellfire_AGM114K", "PylonMissile_1Rnd_ACE_Hellfire_AGM114K", "PylonRack_1Rnd_ACE_Hellfire_AGM114K", "PylonRack_3Rnd_ACE_Hellfire_AGM114K", "PylonRack_4Rnd_ACE_Hellfire_AGM114K" };
    };
    class ace_hellfire_launcher_N : ace_hellfire_launcher {
        displayName = "AGM-114N";
        magazines[] = { "2Rnd_ACE_Hellfire_AGM114N", "4Rnd_ACE_Hellfire_AGM114N", "6Rnd_ACE_Hellfire_AGM114N", "PylonMissile_1Rnd_ACE_Hellfire_AGM114N", "PylonRack_1Rnd_ACE_Hellfire_AGM114N", "PylonRack_3Rnd_ACE_Hellfire_AGM114N", "PylonRack_4Rnd_ACE_Hellfire_AGM114N" };
    };
    class ace_hellfire_launcher_drone : ace_hellfire_launcher {
        magazines[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone" };
    };
    class ace_hellfire_launcher_drone_N : ace_hellfire_launcher_N {
        magazines[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone" };
    };
    class ace_hellfire_launcher_L : ace_hellfire_launcher {
        displayName = "AGM-114L";
        magazines[] = { "2Rnd_ACE_Hellfire_AGM114L", "4Rnd_ACE_Hellfire_AGM114L", "PylonMissile_1Rnd_ACE_Hellfire_AGM114L", "PylonRack_1Rnd_ACE_Hellfire_AGM114L", "PylonRack_3Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114L" };
    };

    class CUP_Vacannon_M230_veh : CannonCore {
        magazines[] = { "CUP_1200Rnd_TE1_Red_Tracer_30x113mm_M789_HEDP_M", "CUP_1200Rnd_TE1_Green_Tracer_30x113mm_M789_HEDP_M", "CUP_1200Rnd_TE1_Yellow_Tracer_30x113mm_M789_HEDP_M", "CUP_1200Rnd_TE1_White_Tracer_30x113mm_M789_HEDP_M" };
        ballisticsComputer = "1 + 2 + 16";
        canLock = 0;
        reloadTime = 0.096;
        modes[] = { "close", "short", "medium", "far", "manual", "burst_15", "burst_25" };
        cursorAim = "EmptyCursor";
        class GunParticles {
            class EffectSmokeLeft {
                effectName = "MachineGun2";
                positionName = "usti hlavne";
                directionName = "gun_smoke_left";
            };
            class EffectSmokeRight {
                effectName = "MachineGun2";
                positionName = "usti hlavne";
                directionName = "gun_smoke_right";
            };
            class EffectCartridge {
                positionName = "gun_eject";
                directionName = "gun_eject_dir";
                effectName = "MachineGunCartridge1";
            };
        };
        class manual : CannonCore {
            displayName = "Burst 10";
            textureType = "semi";
            burst = 10;
            soundBurst = 0;
            dispersion = 0.00015;
        };
        class burst_15 : manual {
            displayName = "Burst 20";
            textureType = "burst";
            burst = 20;
        };
        class burst_25 : manual {
            displayName = "Full";
            textureType = "fullAuto";
            burst = 1;
        };
    };
    class MGun;
    class CUP_Vacannon_M621_AW159_veh : CannonCore {
        class GunParticles {
            class FirstEffect {
                effectName = "machinegun1";
                positionName = "muzzle_1";
                directionName = "chamber_1";
            };
            class EffectCartridge {
                positionName = "eject_1";
                directionName = "eject_1_dir";
                effectName = "MachineGunCartridge";
            };
        };
        cartridgePos = "eject_1";
        cartridgeVel = "eject_1_dir";
        class manual : MGun {
            class StandardSound {
                begin1[] = { "A3\Sounds_F\arsenal\weapons_vehicles\gatling_20mm\20mm_01_burst", 3.98107, 1, 1300, { 2, 35740 } };
                soundBegin[] = { "begin1", 1 };
                closure1[] = { "A3\Sounds_F\weapons\Closure\sfx10", 0.63095737, 1, 20 };
                closure2[] = { "A3\sounds_f\weapons\closure\sfx11", 0.63095737, 1.2, 20 };
                soundClosure[] = { "closure1", 0.5, "closure2", 0.5 };
            };
        };
    };
    class CUP_Vmlauncher_FFAR_veh;
    class CUP_Vmlauncher_CRV7_veh : CUP_Vmlauncher_FFAR_veh {
        class Single;
        class Double : Single {
            displayName = "Ripple 2";
        };
        class Quadruple : Single {
            displayName = "Ripple 4";
        };
    };
    class missiles_DAR;
    class rksla3_aw159_wpn_crv7_lau5003 : missiles_DAR {
        modes[] = { "Far_AI", "Medium_AI", "Ripple1", "Ripple2", "Ripple4" };
        class Ripple1 : RocketPods {
            displayName = "Ripple 1";
            textureType = "semi";
            burst = 1;
            soundContinuous = 0;
            autoFire = 0;
            reloadTime = 0.08;
            dispersion = 0.015;
            aiRateOfFire = 1;
            aiRateOfFireDistance = 10;
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 1;
            midRangeProbab = 0.01;
            maxRange = 2;
            maxRangeProbab = 0.01;
            sounds[] = { "StandardSound" };
            class StandardSound {
                begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_8", 1.77828, 1.2, 1600 };
                soundBegin[] = { "begin1", 1 };
                soundSetShot[] = { "DS_launcher_Small_Shot_SoundSet", "DS_rifle1_Tail_SoundSet" };
            };
        };
        class Ripple2 : Ripple1 {
            displayName = "Ripple 2";
            textureType = "burst";
            burst = 2;
        };
        class Ripple4 : Ripple1 {
            displayName = "Ripple 4";
            textureType = "fullAuto";
            burst = 4;
        };
    };
    class gatling_30mm_base : CannonCore {
        class LowROF : Mode_FullAuto {
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet", "DS_sniper1_tail_soundset" };
            };
            soundContinuous = 0;
        };
        class close : LowROF {
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet", "DS_sniper1_tail_soundset" };
            };
            soundContinuous = 0;
        };
        class near : close {
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet", "DS_sniper1_tail_soundset" };
            };
            soundContinuous = 0;
        };
        class short : close {
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet", "DS_sniper1_tail_soundset" };
            };
            soundContinuous = 0;
        };
        class medium : close {
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet", "DS_sniper1_tail_soundset" };
            };
            soundContinuous = 0;
        };
        class far : close {
            class StandardSound {
                soundSetShot[] = { "DS_30mmgatling_Shot_SoundSet", "DS_sniper1_tail_soundset" };
            };
            soundContinuous = 0;
        };
    };
};
