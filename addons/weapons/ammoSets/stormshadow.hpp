// BROACH-style dual stage: outer shell -> AP precursor penetrator -> HE follow-through.
// Vanilla tandem pattern (Titan/Scalpel): submunitionInitSpeed + ParentSpeedCoef=0 so the
// child keeps forward velocity when the parent dies on impact. ParentSpeedCoef=1 was the
// dud — child inherited the dying missile's near-zero speed and never punched through.
class GVAR(payload_stormshadow) : ammo_Penetrator_Base {
    caliber = 40;
    warheadName = "HE";
    hit = 12000;
    indirectHit = 1500;
    indirectHitRange = 18;
    explosive = 1;
    typicalSpeed = 800;
    timeToLive = 0.2;
    explosionEffects = "BombExplosion";
    CraterEffects = "BombCrater";
};
class GVAR(penetrator_stormshadow) : ammo_Penetrator_Base {
    caliber = 80;
    warheadName = "AP";
    hit = 500;
    indirectHit = 0;
    indirectHitRange = 0;
    explosive = 0;
    typicalSpeed = 1000;
    timeToLive = 0.25;
    submunitionAmmo = QGVAR(payload_stormshadow);
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionInitSpeed = 800;
    submunitionParentSpeedCoef = 0;
    submunitionInitialOffset[] = { 0, 0, -0.3 };
    triggerOnImpact = 1;
    deleteParentWhenTriggered = 0;
    explosionEffects = "";
    CraterEffects = "";
};
class rksla3_ammo_kepd350;
class rksla3_ammo_stormshadow : rksla3_ammo_kepd350 {
    hit = 100;
    indirectHit = 50;
    indirectHitRange = 4;
    explosive = 0.5;
    submunitionAmmo = QGVAR(penetrator_stormshadow);
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionInitSpeed = 1000;
    submunitionParentSpeedCoef = 0;
    submunitionInitialOffset[] = { 0, 0, -0.2 };
    deleteParentWhenTriggered = 0;
    triggerOnImpact = 1;
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
