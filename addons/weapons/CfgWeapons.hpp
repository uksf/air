class CfgWeapons {
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
};
