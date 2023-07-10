class GVAR(gunpod_25mm_apex) : B_35mm_AA {
    warheadName = "APEX";
    ace_rearm_caliber = 25;
    caliber = 7;
    typicalSpeed = 970;
    hit = 180;
    indirectHit = 50;
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

class CUP_B_30x113mm_M789_HEDP_Red_Tracer : BulletBase {
    SoundSetExplosion[] = { "JPEX_20mm_EXPLOSION_SoundSet", "JPEX_20mm_REFLECTOR_SoundSet" };
    CraterEffects = "ExploAmmoCrater";
    explosionEffects = "ExploAmmoExplosion";
    class HitEffects {
        hitWater = "ImpactEffectsWater";
    };
    hit = 105;
    indirectHit = 15;
    indirectHitRange = 2;
    tracerEndTime = 30;
    timeToLive = 30;
    caliber = 9;
    manualControl = 0;
    explosive = 0.5;
};
