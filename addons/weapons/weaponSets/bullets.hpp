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
    magazines[] = { QGVAR(gunpod_magazine), QGVAR(gunpod_pylon) };
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
        dispersion = 0.0045;  // 0.00015 (data sheet value 0.003, observed assumed 0.006)
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
