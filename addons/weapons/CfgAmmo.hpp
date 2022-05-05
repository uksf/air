class CfgAmmo {
    class B_35mm_AA;
    class GVAR(gunpod_25mm_apex) : B_35mm_AA {
        warheadName = "APEX";
        ace_rearm_caliber = 25;
        caliber = 7;
        typicalSpeed = 970;
        hit = 90;
        indirectHit = 15;
        indirectHitRange = 2;
        explosive = 0.5;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
        tracerEndTime = 30;
        soundHit1[] = { "A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_01", 3.16228, 1, 1300 };
        soundHit2[] = { "A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_02", 3.16228, 1, 1300 };
        soundHit3[] = { "A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_03", 3.16228, 1, 1300 };
        soundHit4[] = { "A3\Sounds_F\arsenal\explosives\Grenades\Explosion_gng_grenades_04", 3.16228, 1, 1300 };
        multiSoundHit[] = { "soundHit1", 0.25, "soundHit2", 0.25, "soundHit3", 0.25, "soundHit4", 0.25 };
        SoundSetExplosion[] = { "DS_Ex_Gau8_SoundSet" };
        class CamShakeExplode {
            power = 6;
            duration = 1;
            frequency = 20;
            distance = 67.8178;
        };
        class CamShakeHit {
            power = 30;
            duration = 0.4;
            frequency = 20;
            distance = 1;
        };
        class CamShakeFire {
            power = 2.34035;
            duration = 1;
            frequency = 20;
            distance = 43.8178;
        };
        class CamShakePlayerFire {
            power = 0.01;
            duration = 0.1;
            frequency = 20;
            distance = 1;
        };
    };

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
    class ammo_Missile_ShortRangeAABase;
    class ammo_Missile_BIM9X : ammo_Missile_ShortRangeAABase {
        ace_rearm_dummy = QGVAR(ammo_Missile_BIM9X);
    };
    class ammo_Missile_MediumRangeAABase;
    class ammo_Missile_AMRAAM_D : ammo_Missile_MediumRangeAABase {
        ace_rearm_dummy = QGVAR(ammo_Missile_AMRAAM_D);
    };
    class ace_aim120_d: ammo_Missile_AMRAAM_D {
        flightProfiles[] = {"Direct", "Loft"};
        class Direct {};
        class Loft {};
    };
    class ammo_Bomb_SmallDiameterBase;
    class ammo_Bomb_SDB : ammo_Bomb_SmallDiameterBase {
        ace_rearm_dummy = QGVAR(ammo_Bomb_SDB);
    };

    class ammo_Penetrator_Scalpel;
    class ammo_Penetrator_Hellfire : ammo_Penetrator_Scalpel {
        caliber = 70;
        hit = 1550;
    };
    class M_Scalpel_AT;
    class ACE_Hellfire_AGM114K : M_Scalpel_AT {
        hit = 400;  // 150 (javelin 350)
        submunitionAmmo = "ammo_Penetrator_Hellfire";
        SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet", "JPEX_Big_Debris_SoundSet" };
        model = QPATHTOF(data\AGM114\AGM114Hellfire.p3d);
        proxyShape = QPATHTOF(data\AGM114\AGM114Hellfire_proxy.p3d);
        ace_rearm_dummy = QGVAR(ACE_Hellfire_AGM114);
        effectsMissileInit = "PylonBackEffects";
        class ace_missileguidance;
    };

    class ACE_Hellfire_AGM114K_drone : ACE_Hellfire_AGM114K {
        class ace_missileguidance : ace_missileguidance {
            enabled = 1;
            seekerAngle = 360;
            pitchRate = 45; // degrees per second
            yawRate = 45;
        };
    };
    class ACE_Hellfire_AGM114N : ACE_Hellfire_AGM114K {
        class ace_missileguidance;
    };
    class ACE_Hellfire_AGM114N_drone : ACE_Hellfire_AGM114N {
        class ace_missileguidance : ace_missileguidance {
            enabled = 1;
            seekerAngle = 360;
            pitchRate = 45; // degrees per second
            yawRate = 45;
        };
    };

    class LaserBombCore;
    class ammo_Bomb_LaserGuidedBase : LaserBombCore {
        indirectHitRange = 20;  // 12
    };
    class Bo_GBU12_LGB : ammo_Bomb_LaserGuidedBase {
        model = "\A3\Weapons_F_EPC\Ammo\Bomb_04_fly_F";
        proxyShape = "\A3\Weapons_F_EPC\Ammo\Bomb_04_F";
    };
    class CUP_Bo_GBU12_LGB : Bo_GBU12_LGB {
        model = "\A3\Weapons_F_EPC\Ammo\Bomb_04_fly_F";
        proxyShape = "\A3\Weapons_F_EPC\Ammo\Bomb_04_F";
    };

    class BulletBase;
    class CUP_B_30x113mm_M789_HEDP_Red_Tracer : BulletBase {
        SoundSetExplosion[] = { "JPEX_20mm_EXPLOSION_SoundSet", "JPEX_20mm_REFLECTOR_SoundSet" };
        CraterEffects = "ExploAmmoCrater";
        explosionEffects = "ExploAmmoExplosion";
        class HitEffects {
            hitWater = "ImpactEffectsWater";
        };
        hit = 105;
        indirectHit = 10;
        indirectHitRange = 2;
        tracerEndTime = 30;
        timeToLive = 30;
        caliber = 9;
        manualControl = 0;
        explosive = 0.5;
    };
};
