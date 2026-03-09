class GVAR(payload_stormshadow) : ammo_Penetrator_Base {
    caliber = 80;
    warheadName = "HE";
    hit = 12000;            // 5800
    indirectHit = 1500;     // 1200
    indirectHitRange = 18;  // 20
    explosive = 1;
    explosionEffects = "BombExplosion";
    CraterEffects = "BombCrater";
    triggerOnImpact = 1;
    deleteParentWhenTriggered = 0;
};
class GVAR(penetrator_stormshadow) : ammo_Penetrator_Base {
    caliber = 80;
    warheadName = "AP";
    hit = 500;
    indirectHit = 0;
    indirectHitRange = 0;
    explosive = 0;
    submunitionAmmo = QGVAR(payload_stormshadow);
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionParentSpeedCoef = 1;
    submunitionInitialOffset[] = { 0, 0, -0.5 };
    triggerDistance = 1;
    triggerOnImpact = 0;
    deleteParentWhenTriggered = 0;
};
class rksla3_ammo_kepd350;
class rksla3_ammo_stormshadow : rksla3_ammo_kepd350 {
    hit = 100;
    indirectHit = 10;
    indirectHitRange = 1;
    submunitionAmmo = QGVAR(penetrator_stormshadow);
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionParentSpeedCoef = 1;
    submunitionInitialOffset[] = { 0, 0, 0 };
    triggerDistance = 1;
    triggerOnImpact = 0;
    maneuvrability = 0;
    explosionEffects = "";
    CraterEffects = "";
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet", "JPEX_Big_Debris_SoundSet" };
    ace_rearm_dummy = QGVAR(ammo_missile_stormshadow);
    effectsMissileInit = "PylonBackEffects_InitDelay";

    weaponLockSystem = 0;
    laserLock = 0;
    irLock = 0;
    airLock = 0;

    maxSpeed = 220;
    thrust = 45;
    thrustTime = 200;
    airFriction = 0.35;
    sideAirFriction = 0.4;
    initTime = 1;

    class ace_missileguidance : ace_missileguidance_type_CruiseMissile {
        enabled = 1;
        seekerTypes[] = { "GPS", "SALH" };
        seekLastTargetPos = 1;

        seekerAngle = 90;
        seekerAccuracy = 1;
        seekerMinRange = 5;
        seekerMaxRange = 25000;

        class seekerStates {
            class cruise {
                transitionCondition = QFUNC(stormshadowSeekerTransition);
                seekerType = "GPS";
            };
            class terminal {
                transitionCondition = "";
                seekerType = "SALH";
            };
            states[] = { "cruise", "terminal" };
        };
    };
};
