class GVAR(penetrator_brimstone) : ammo_Penetrator_Base {
    caliber = 80;
    warheadName = "TandemHEAT";
    hit = 5000;
};
class rksla3_ammo_brimstone_2;
class rksla3_ammo_brimstone_3 : rksla3_ammo_brimstone_2 {
    hit = 300; // 210
    indirectHit = 50; // 70
    indirectHitRange = 5; // 11
    submunitionAmmo = QGVAR(penetrator_brimstone);
    timeToLive = 40;
    maneuvrability = 0;
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet", "JPEX_Big_Debris_SoundSet" };
    ace_rearm_dummy = QGVAR(ammo_missile_brimstone3);
    effectsMissileInit = "PylonBackEffects";

    weaponLockSystem = "8";
    airLock = 1;
    lockType = 0;
    laserLock = 0;
    irLock = 0;

    missileLockMaxDistance = 12000;
    missileLockMinDistance = 250;
    missileLockMaxSpeed = 600;
    missileKeepLockedCone = 70;

    class ace_missileguidance {
        enabled = 1;
        canVanillaLock = 1;
        pitchRate = 40;
        yawRate = 40;
        defaultSeekerType = "MillimeterWaveRadar";
        seekerTypes[] = { "MillimeterWaveRadar" };
        defaultSeekerLockMode = "LOBL";
        seekerLockModes[] = { "LOBL" };
        defaultNavigationType = "Direct";
        navigationTypes[] = { "Direct", "ZeroEffortMiss" };

        seekLastTargetPos = 1;
        seekerAngle = 70;
        seekerAccuracy = 1;
        seekerMinRange = 1;
        seekerMaxRange = 12000;
        activeRadarEngageDistance = 2000;

        defaultAttackProfile = "hellfire";
        attackProfiles[] = { "hellfire" };

        class navigationStates {
            class initial {
                transitionCondition = "ace_hellfire_fnc_midCourseTransition";
                navigationType = "Direct";
            };
            class terminal {
                transitionCondition = "";
                navigationType = "ZeroEffortMiss";
            };
            states[] = { "initial", "terminal" };
        };
    };

    class Components {
        class SensorsManagerComponent {
            class Components {
                class MillimeterWaveRadar {
                    componentType = "ActiveRadarSensorComponent";
                    class AirTarget {
                        minRange = 0;
                        maxRange = 12000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 0;
                        maxRange = 12000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    typeRecognitionDistance = 3000;
                    angleRangeHorizontal = 70;
                    angleRangeVertical = 70;
                    groundNoiseDistanceCoef = 0;
                    maxGroundNoiseDistance = 250;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 600;
                    nightRangeCoef = 1;
                    maxFogSeeThrough = 0.8;
                };
            };
        };
    };
};
