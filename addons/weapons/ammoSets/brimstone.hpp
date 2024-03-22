class ACE_Hellfire_AGM114L;
class GVAR(brimstone3) : ACE_Hellfire_AGM114L {
    author = "UKSF";
    displayName = "Brimstone III";
    displayNameShort = "Brimstone III";
    description = "Brimstone III";
    descriptionShort = "Brimstone III";
    model = QPATHTOF(data\brimstone\brimstone.p3d);
    proxyShape = QPATHTOF(data\brimstone\brimstone_proxy.p3d);
    ace_rearm_dummy = QGVAR(ammo_missile_brimstone3);

    thrustTime = 3;
    thrust = 250;
    timeToLive = 120;

    class ace_missileguidance {
        enabled = 1;
        canVanillaLock = 1;
        pitchRate = 40;  // degrees per second
        yawRate = 40;
        defaultSeekerType = "MillimeterWaveRadar";
        seekerTypes[] = { "MillimeterWaveRadar" };
        defaultSeekerLockMode = "LOBL";
        seekerLockModes[] = { "LOBL" };
        defaultNavigationType = "Direct";
        navigationTypes[] = { "Direct", "ZeroEffortMiss" };

        seekLastTargetPos = 1;  // seek last target position [if seeker loses LOS of target, continue to last known pos]
        seekerAngle = 70;       // Angle in front of the missile which can be searched
        seekerAccuracy = 1;     // seeker accuracy multiplier
        seekerMinRange = 1;
        seekerMaxRange = 12000;  // Range from the missile which the seeker can visually search
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
            // transitions from initial -> termimal
            states[] = {"initial", "terminal"};
        };
    };

    // Vanilla lock system vars
    weaponLockSystem = "8";
    airLock = 1;
    lockType = 0;
    maneuvrability = 0;  // no maneuvrability so that default guidance doesnt work

    missileLockMaxDistance = 12000;
    missileLockMinDistance = 250;
    missileLockMaxSpeed = 600;
    missileKeepLockedCone = 70;

    flightProfiles[] = {};
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
                    groundNoiseDistanceCoef = 0;  // relevant to AA missiles - not really for this
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
