class rksla3_ammo_spear3 : M_Scalpel_AT {
    hit = 200;
    indirectHit = 60;
    indirectHitRange = 5;
    maneuvrability = 0;
    ace_rearm_dummy = QGVAR(ammo_missile_spear3);
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet" };

    weaponLockSystem = "8";
    airLock = 1;
    lockType = 0;
    laserLock = 0;
    irLock = 0;

    missileLockMaxDistance = 20000;
    missileLockMinDistance = 250;
    missileLockMaxSpeed = 600;
    missileKeepLockedCone = 70;

    class ace_missileguidance {
        enabled = 1;
        canVanillaLock = 1;
        pitchRate = 35;
        yawRate = 35;
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
        seekerMaxRange = 20000;
        activeRadarEngageDistance = 3000;

        defaultAttackProfile = "hellfire";
        attackProfiles[] = { "hellfire", "hellfire_hi", "hellfire_lo" };

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
                        maxRange = 20000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 0;
                        maxRange = 20000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    typeRecognitionDistance = 5000;
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
