class CfgPatches {
    class USAF_C17_C {
        author = "USAF Mod Team";
        url = "https://gitlab.com/usaf-a3/usaf-mod";
        units[] = { "USAF_C17" };
        weapons[] = {};
        requiredVersion = 2.00;
        requiredAddons[] = { "usaf_utility_core", "USAF_C17" };
    };
};
class cfgFunctions {
    class USAF_C17 {
        class init {
            file = "\USAF_C17_C\functions\init";
            class rampCtrl {};
        };
    };
};
class CfgMovesBasic {
    class DefaultDie;
    class ManActions {
        C17_Pilot = "C17_Pilot";
    };
};
class CfgMovesMaleSdr : CfgMovesBasic {
    class States {
        class Crew;
        class C17_Pilot : Crew {
            file = "\USAF_C17\data\Anim\C17_Pilot.rtm";
            interpolateTo[] = { "KIA_C17_Pilot", 1 };
        };
        class KIA_C17_Pilot : DefaultDie {
            actions = "DeadActions";
            speed = 0.5;
            looped = 0;
            terminal = 1;
            file = "\USAF_C17\data\Anim\KIA_C17_Pilot.rtm";
            connectTo[] = { "DeadState", 0.1 };
        };
    };
};
class CfgSounds {
    class usaf_c17_ramp {
        sound[] = { "\USAF_C17\sound\ramp.wss", 1.5, 1 };
        name = "USAF_C17_doors";
        titles[] = {};
    };
};
class DefaultEventhandlers;
class CfgVehicles {
    class Air;
    class Plane : Air {
        class NewTurret;
        class ViewPilot;
        class AnimationSources;
        class ViewGunner;
        class EventHandlers;
    };
    class Plane_Base_F : Plane {};
    class USAF_C17 : Plane_Base_F {
        // editorSubcategory = "EdSubCat_USAF_Transport";
        model = "\USAF_C17\USAF_C17.p3d";
        picture = "\USAF_C17\data\icons\picture.paa";
        icon = "\USAF_C17\data\icons\icon.paa";
        editorPreview = "USAF_C17\data\UI\preview.jpg";
        destrType = "DestructWreck";
        displayName = "C-17 Globemaster III";
        crew = "B_Pilot_F";
        author = "USAF Mod Team";
        simulation = "airplaneX";
        USAF_RefuelType = "probe";
        USAF_RefuelPoint = "refuel_probe";
        USAF_RefuelAnimation = "fuel_probe";
        crewVulnerable = 0;
        driverAction = "C17_Pilot";
        cargoAction[] = { "passenger_low01" };
        weapons[] = { "CMFlareLauncher" };
        magazines[] = { "240Rnd_CMFlare_Chaff_Magazine" };
        attendant = 1;
        vehicleClass = "Air";
        faction = "USAF";
        mapSize = 52;
        damageEffect = "AirDestructionEffects";
        LockDetectionSystem = 8;
        incomingMissileDetectionSystem = "8+16";
        radarType = 4;
        radarTargetSize = 2;
        side = 1;
        scope = 2;
        scopeCurator = 2;
        animated = 1;
        cabinOpening = 0;
        camouflage = 2;
        audible = 25;
        accuracy = 1;
        landingSpeed = 275;
        limitedspeedcoef = 0.5;
        brakeDistance = 200;
        acceleration = 2500;
        maxSpeed = 950;
        altFullForce = 12000;
        altNoForce = 14000;
        wheelSteeringSensitivity = 5;
        rudderSensitivity = 2;
        landingAoa = "rad 7";
        airBrake = 1;
        armor = 90;
        armorWheels = 4000;
        armorStructured = 1;
        gearRetracting = 1;
        gearUpTime = 4.5;
        gearDownTime = 3;
        hasGunner = 1;
        supplyRadius = 20;
        getInRadius = 6;
        formationX = 190;
        formationZ = 190;
        formationTime = 15;
        irScanRangeMin = 205;
        irScanRangeMax = 20500;
        irScanToEyeFactor = 3;
        transportFuel = 10000;
        transportVehiclesCount = 4;
        transportVehiclesMass = 170000;
        transportSoldier = 56;
        transportMaxWeapons = 400;
        transportMaxMagazines = 800;
        transportMaxBackpacks = 100;
        fuelCapacity = 2600;
        precision = 200;
        maneuvrability = 20;
        dustEffect = "HeliDust";
        gunnerUsesPilotView = 1;
        driverRightHandAnimName = "stick_pilot";
        memoryPointCM[] = { "launcher1", "launcher2", "levy prach", "pravy prach" };
        memoryPointCMDir[] = { "launcher1_dir", "launcher2_dir", "cerveny pozicni", "zeleny pozicni" };
        memoryPointSupply = "pos supply";
        memoryPointsGetInCargo[] = { "pos cargo", "pos cargo front", "pos cargo jumpL", "pos cargo jumpR" };
        memoryPointsGetInCargoDir[] = { "pos cargo dir", "pos cargo front dir", "pos cargo jumpL dir", "pos cargo jumpR dir" };
        aileronSensitivity = 1.1;
        elevatorSensitivity = 1.2;
        flapsFrictionCoef = 2;
        lightongear = 0;
        envelope[] = { 0, 0.5, 1, 2, 4, 4.5, 5, 5.3, 5.6, 6, 6.2, 6.5, 6.7, 0 };
        gunAimDown = 0.045;
        insideSoundCoef = 0.45;
        hascommander = 0;
        nosedowncoef = 1;
        gunAimUp = 0.2;
        minFireTime = 5;
        extCameraPosition[] = { 0, 1, -43 };
        type = "VAir";
        fov = 0.7;
        spotabledarknightlightsoff = 0.003;
        spotablenightlightsoff = 0.035;
        spotablenightlightson = 4;
        aggregatereflectors[] = {};
        visiblenightlightsoff = 0.1;
        visiblenightlightson = 0.2;
        driverCanEject = 1;
        GunnerCanEject = 1;
        cargoCanEject = 1;
        ejectSpeed[] = { 0, 0, 0 };
        cost = 218000000;
        threat[] = { 0.5, 0.5, 0.5 };
        class USAF_ServiceMenu {
            enabled = 1;
            loadOutCustomization = 0;
            openBays = 0;
            addBaysToggle = 0;
            cameraPos[] = { { -0.24, -0.602, 1.916 }, 28.502, 9.699, 86.252, 0 };
            animationToggles[] = {};
        };
        hiddenSelections[] = { "c17-1", "c17-2", "c17-3", "c17-5", "c17-6", "c17-7_t", "c17-8", "eng_t", "lwng", "rwng", "tail", "hourformat1", "hourformat2", "minformat1", "minformat2", "secformat1", "secformat2", "n_gear", "l_gear_1", "l_gear_2", "r_gear_1", "r_gear_2" };
        hiddenSelectionsTextures[] = { "\USAF_C17\data\texture\C17-1_co.paa", "\USAF_C17\data\texture\C17-2_co.paa", "\USAF_C17\data\texture\C17-3_co.paa", "\USAF_C17\data\texture\C17-5_co.paa", "\USAF_C17\data\texture\C17-6_co.paa", "\USAF_C17\data\texture\C17-7_t_co.paa", "\USAF_C17\data\texture\C17-8_co.paa", "\USAF_C17\data\texture\C17-eng_co.paa", "\USAF_C17\data\texture\Lwng_co.paa", "\USAF_C17\data\texture\Rwng_co.paa", "\USAF_C17\data\texture\Tail_co.paa" };
        soundServo[] = { "\USAF_C17\sound\trains.wss", 0.2, 1.4, 50 };
        soundDammage[] = { "\USAF_C17\sound\alert.wss", 0.2, 1 };
        soundGetIn[] = { "\USAF_C17\sound\ext-jetair-cabine-close1.wss", 2, 0.6, 800 };
        soundGetOut[] = { "\USAF_C17\sound\ext-jetair-cabine-open1.wss", 2, 0.6, 800 };
        soundEngineOnInt[] = { "\USAF_C17\sound\c17_start_in.wss", 0, 0.6, 800 };
        soundEngineOnExt[] = { "\USAF_C17\sound\c17_start.wss", 2, 0.6, 800 };
        soundEngineOffInt[] = { "\USAF_C17\sound\c17_stop_in.wss", 2, 0.6, 800 };
        soundEngineOffExt[] = { "\USAF_C17\sound\c17_stop.wss", 2, 0.6, 800 };
        soundIncommingMissile[] = { "\A3\Sounds_F\weapons\Rockets\locked_3", 0.1, 1.5 };
        soundEngine[] = { "\USAF_C17\sound\c17_idle", 0, 0.6, 800 };
        soundGearUp[] = { "\USAF_C17\sound\gearup", 3, 1, 100 };
        soundGearDown[] = { "\USAF_C17\sound\geardn", 3, 1, 100 };
        soundFlapsUp[] = { "\USAF_C17\sound\flaps", 3, 1, 100 };
        soundFlapsDown[] = { "\USAF_C17\sound\flaps", 3, 1, 100 };
        driverCompartments = "Compartment1";
        cargoCompartments[] = { "Compartment1" };
        attenuationEffectType = "PlaneAttenuation";
        class Turrets {
            class MainTurret : NewTurret {
                isCopilot = 1;
                proxyIndex = 1;
                gunnerName = "Copilot";
                primaryGunner = 1;
                canEject = 0;
                body = "";
                gun = "";
                animationSourceBody = "";
                animationSourceGun = "";
                weapons[] = {};
                magazines[] = {};
                gunnerAction = "C17_Pilot";
                gunnerInAction = "C17_Pilot";
                gunnerGetInAction = "GetInLow";
                gunnerGetOutAction = "GetOutLow";
                memoryPointsGetInGunner = "pos copilot";
                memoryPointsGetInGunnerDir = "pos copilot dir";
                memoryPointsGetInGunnerPrecise = "pos copilot";
                preciseGetInOut = 1;
                startEngine = 1;
                gunnerForceOptics = "false";
                soundServo[] = { "", 0.01, 1 };
                outGunnerMayFire = "false";
                inGunnerMayFire = "false";
                minElev = 0;
                maxElev = 0;
                initElev = 0;
                minTurn = 0;
                maxTurn = 0;
                initTurn = 0;
                maxHorizontalRotSpeed = 3;
                maxVerticalRotSpeed = 3;
                class ViewGunner {
                    initFov = 1;
                    minFov = 0.6;
                    maxFov = 1;
                    initAngleX = 0;
                    minAngleX = -40;
                    maxAngleX = 85;
                    initAngleY = 0;
                    minAngleY = -130;
                    maxAngleY = 130;
                    minMoveX = -0.2;
                    maxMoveX = 0.2;
                    minMoveY = -0.025;
                    maxMoveY = 0.1;
                    minMoveZ = -0.2;
                    maxMoveZ = 0.2;
                };
                commanding = -1;
                gunnerLeftHandAnimName = "stick_copilot";
                gunnerRightHandAnimName = "stick_copilot";
            };
        };
        class ViewPilot {
            initFov = 1;
            minFov = 0.3;
            maxFov = 1.2;
            initAngleX = 0;
            minAngleX = -40;
            maxAngleX = 85;
            initAngleY = 0;
            minAngleY = -150;
            maxAngleY = 150;
        };
        class WingVortices {
            class BodyLeft_inner {
                effectName = "BodyVortices";
                position = "body_vapour_wingL";
            };
            class BodyRight_inner {
                effectName = "BodyVortices";
                position = "body_vapour_wingR";
            };
            class BodyLeft_outer {
                effectName = "WingVortices";
                position = "body_vapour_tipL";
            };
            class BodyRight_outer {
                effectName = "WingVortices";
                position = "body_vapour_tipR";
            };
        };
        class Exhausts {
            class Exhaust_left {
                position = "Exhausts_start_left1";
                direction = "Exhausts_end_left1";
                effect = "ExhaustsEffectPlaneHP";
                engineIndex = 0;
            };
            class Exhaust_left2 : Exhaust_left {
                position = "Exhausts_start_left2";
                direction = "Exhausts_end_left2";
            };
            class Exhaust_right : Exhaust_left {
                position = "Exhausts_start_right1";
                direction = "Exhausts_end_right1";
                engineIndex = 1;
            };
            class Exhaust_right2 : Exhaust_right {
                position = "Exhausts_start_right2";
                direction = "Exhausts_end_right2";
            };
        };
        class Sounds {
            class EngineLowOut {
                sound[] = { "\USAF_C17\sound\c17_engine2.wss", 3.5, 1, 600 };
                frequency = "(rpm interpolate [0, 1, 0.7, 1])";
                volume = "camPos*rpm*(thrust interpolate [0,1, 1, 1])";
            };
            class EngineHighOut {
                sound[] = { "\USAF_C17\sound\C_17_idle.wss", 3, 1, 600 };
                frequency = "(rpm interpolate [0, 1, 0.1, 0.6]) + (thrust interpolate [0, 1, 0, 0.7])";
                volume = "camPos*rpm*(thrust interpolate [0,1,0.7,0.85])";
            };
            class ForsageOut {
                sound[] = { "\USAF_C17\sound\ext-jetair-forsage1", 3, 0.6, 400 };
                frequency = "(rpm interpolate [0, 1, 0.5, 1])";
                volume = "camPos*rpm*(thrust interpolate [0.5,1,0.1,1])";
            };
            class ActuatorForsageOut {
                sound[] = { "\USAF_C17\sound\C17_throttleup.wss", 3, 1, 600 };
                frequency = "1";
                volume = "camPos*(rpm interpolate [0.4,1,0,1])";
            };
            class DistantPlaneOut {
                sound[] = { "\USAF_C17\sound\distantplane", 1, 0.75, 800 };
                frequency = "1";
                volume = "camPos*rpm";
            };
            class DistantPlaneOutLong {
                sound[] = { "\USAF_C17\sound\distantplane", 4, 0.3, 3000 };
                frequency = "1";
                volume = "camPos*rpm*(thrust interpolate [0.4,1,0,1])";
            };
            class WindNoiseOut {
                sound[] = { "\USAF_C17\sound\ext-jetair-wind", 3, 0.8, 200 };
                frequency = "(0.1+(1.2*(speed factor[1, 150])))";
                volume = "camPos*(speed factor[1, 150])";
            };
            class EngineLowIn {
                sound[] = { "\USAF_C17\sound\C17_high_in", 1, 0.6, 800 };
                frequency = "(rpm interpolate [0, 1, 0 ,1]) + (thrust interpolate [0,1,0,0.1])";
                volume = "(1-camPos)*rpm*(thrust interpolate [0,1,0.8,1])";
            };
            class EngineHighIn {
                sound[] = { "\USAF_C17\sound\engine_in", 1, 0.6, 800 };
                frequency = "(rpm interpolate [0,1,0,1]) + (thrust interpolate [0,1,0,0.1])";
                volume = "(1-camPos)*rpm*(thrust interpolate [0.4,1,0.8,1])";
            };
            class WindNoiseIn {
                sound[] = { "\USAF_C17\sound\int-jetair-wind1", 1.5, 0.6, 800 };
                frequency = "(0.1+(1.2*(speed factor[1, 150])))";
                volume = "(1-camPos)*(speed factor[1, 150])";
            };
            class RainExt {
                sound[] = { "A3\Sounds_F\vehicles\noises\rain1_ext", 1.7782794, 1, 100 };
                frequency = 1;
                volume = "camPos * rain * (speed factor[50, 0])";
            };
            class RainInt {
                sound[] = { "A3\Sounds_F\vehicles\noises\rain1_int", 1, 1, 100 };
                frequency = 1;
                volume = "(1-camPos) * rain * (speed factor[50, 0])";
            };
        };
        class AnimationSources : AnimationSources {
            class doors {
                source = "user";
                initPhase = 0;
                animPeriod = 7;
            };
            class back_ramp {
                source = "user";
                initPhase = 0;
                animPeriod = 20;
            };
            class back_ramp_half {
                source = "user";
                initPhase = 0;
                animPeriod = 10;
            };
            class fuel_probe {
                source = "user";
                initPhase = 0;
                animPeriod = 0.0001;
            };
            class back_ramp_switch {
                source = "user";
                initPhase = 0;
                animPeriod = 0.0001;
            };
            class back_ramp_half_switch {
                source = "user";
                initPhase = 0;
                animPeriod = 0.0001;
            };
            class jumpdoor_1 {
                source = "user";
                initPhase = 0;
                animPeriod = 2;
            };
            class jumpdoor_2 {
                source = "user";
                initPhase = 0;
                animPeriod = 2;
            };
            class Formlights {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class refuel_lights {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class refuel_hatch {
                source = "user";
                initphase = 0;
                animPeriod = 1.5;
            };
            class HitAvionics {
                hitpoint = "HitAvionics";
                raw = 1;
                source = "Hit";
            };
            class HitEngine : HitAvionics {
                hitpoint = "HitEngine";
            };
            class HitEngine2 : HitAvionics {
                hitpoint = "HitEngine2";
            };
            class HitFuel : HitAvionics {
                hitpoint = "HitFuel";
            };
            class HitFuel2 : HitAvionics {
                hitpoint = "HitFuel2";
            };
            class HitGear : HitAvionics {
                hitpoint = "HitGear";
            };
            class HitHull : HitAvionics {
                hitpoint = "HitHull";
            };
            class HitLAileron : HitAvionics {
                hitpoint = "HitLAileron";
            };
            class HitRAileron : HitAvionics {
                hitpoint = "HitRAileron";
            };
            class HitLCElevator : HitAvionics {
                hitpoint = "HitLCElevator";
            };
            class HitRElevator : HitAvionics {
                hitpoint = "HitRElevator";
            };
            class HitLCRudder : HitAvionics {
                hitpoint = "HitLCRudder";
            };
            class HitRRudder : HitAvionics {
                hitpoint = "HitRRudder";
            };
        };
        class UserActions {
            class extendrefueling {
                displayName = "<t color='#55bbff'>Open Refueling Hatch</t";
                onlyforplayer = 0;
                position = "pos nose open";
                radius = 100;
                showWindow = 0;
                condition = "(this animationPhase 'fuel_probe' == 0) && (player == driver this) and (this animationPhase 'refuel_hatch' == 0)";
                statement = "this animate ['fuel_probe',1] and this animate ['refuel_hatch',1] and this animate ['refuel_lights',1]";
            };
            class retractrefueling {
                onlyforplayer = 0;
                displayName = "<t color='#55bbff'>Close Refueling Hatch</t";
                position = "pos nose open";
                radius = 100;
                showWindow = 0;
                condition = "(this animationPhase 'fuel_probe' == 1) and (player == driver this)";
                statement = "this animate ['fuel_probe',0] and this animate ['refuel_hatch',0] and this animate ['refuel_lights',0]";
            };
            class OpenRear {
                displayName = "<t color='#55bbff'>Open Rear Cargo</t";
                onlyforplayer = 1;
                position = "pos cargo dir";
                radius = 10;
                showWindow = 0;
                condition = "(this animationPhase 'back_ramp_switch' == 0) && (this animationPhase 'back_ramp_half_switch' == 0)";
                statement = "this animate ['back_ramp_switch',1]; [this] execVM '\USAF_C17_C\scripts\back_rampdown.sqf'";
            };
            class CloseRear {
                onlyforplayer = 0;
                displayName = "<t color='#55bbff'>Close Rear Cargo</t";
                position = "pos cargo dir";
                radius = 10;
                showWindow = 0;
                condition = "(this animationPhase 'back_ramp_switch' == 1) and (this animationPhase 'back_ramp_half_switch' == 0)";
                statement = "this animate ['back_ramp_switch',0]; [this] execVM '\USAF_C17_C\scripts\back_rampclose.sqf'";
            };
            class OpenRearHalf {
                displayName = "<t color='#55bbff'>Open Rear Cargo Half</t";
                onlyforplayer = 0;
                position = "pos cargo dir";
                radius = 10;
                showWindow = 0;
                condition = "(this animationPhase 'back_ramp_half_switch' == 0) and (this animationPhase 'back_ramp_switch' == 0)";
                statement = "this animate ['back_ramp_half_switch',1]; [this] execVM '\USAF_C17_C\scripts\back_rampdown_half.sqf'";
            };
            class CloseRearHalf {
                onlyforplayer = 0;
                displayName = "<t color='#55bbff'>Close Rear Cargo</t";
                position = "pos cargo dir";
                radius = 10;
                showWindow = 0;
                condition = "(this animationPhase 'back_ramp_half_switch' == 1) and (this animationPhase 'back_ramp_switch' == 0)";
                statement = "this animate ['back_ramp_half_switch',0];[this] execVM '\USAF_C17_C\scripts\back_rampclose_half.sqf'";
            };
            class FormlightsOn {
                displayName = "<t color='#1F42F0'>Formation lights On</t>";
                position = "";
                priority = 0.4;
                radius = 10;
                onlyForPlayer = 1;
                showWindow = 0;
                condition = "(this animationphase 'Formlights' < 0.1) && (alive this) && (player == driver this)";
                statement = "this animate ['Formlights',1,true];";
            };
            class FormlightsOff {
                displayName = "<t color='#FF9D00'>Formation lights Off</t>";
                position = "";
                priority = 0.4;
                radius = 10;
                onlyForPlayer = 1;
                showWindow = 0;
                condition = "(this animationphase 'Formlights' > 0.9) && (alive this) && (player == driver this)";
                statement = "this animate ['Formlights',0,true];";
            };
            class open_jumpdoor_1 {
                displayName = "<t color='#55bbff'>Open Jump Door 1</t";
                onlyforplayer = 0;
                radius = 4;
                showWindow = 0;
                condition = "(this animationPhase 'jumpdoor_1' < 0.2)";
                statement = "this animate ['jumpdoor_1', 1];";
                position = "jumpdoor_1_pos";
            };
            class close_jumpdoor_1 {
                displayName = "<t color='#55bbff'>Close Jump Door 1</t";
                onlyforplayer = 0;
                radius = 4;
                showWindow = 0;
                position = "jumpdoor_1_pos";
                condition = "(this animationPhase 'jumpdoor_1' > 0.8)";
                statement = "this animate ['jumpdoor_1', 0];";
            };
            class open_jumpdoor_2 {
                displayName = "<t color='#55bbff'>Open Jump Door 2</t";
                onlyforplayer = 0;
                radius = 4;
                showWindow = 0;
                position = "jumpdoor_2_pos";
                condition = "(this animationPhase 'jumpdoor_2' < 0.2)";
                statement = "this animate ['jumpdoor_2', 1];";
            };
            class close_jumpdoor_2 {
                displayName = "<t color='#55bbff'>Close Jump Door 2</t";
                onlyforplayer = 0;
                radius = 4;
                showWindow = 0;
                position = "jumpdoor_2_pos";
                condition = "(this animationPhase 'jumpdoor_2' > 0.8)";
                statement = "this animate ['jumpdoor_2', 0];";
            };
            class open_jumpdoor_1_pilot {
                displayName = "<t color='#55bbff'>Open Jump Door 1</t";
                onlyforplayer = 0;
                radius = 100;
                showWindow = 0;
                position = "pilotcontrol";
                condition = "(this animationPhase 'jumpdoor_1' < 0.2) && player in crew this";
                statement = "this animate ['jumpdoor_1', 1];";
            };
            class close_jumpdoor_1_pilot {
                displayName = "<t color='#55bbff'>Close Jump Door 1</t";
                onlyforplayer = 0;
                radius = 100;
                showWindow = 0;
                position = "pilotcontrol";
                condition = "(this animationPhase 'jumpdoor_1' > 0.8) && player in crew this";
                statement = "this animate ['jumpdoor_1', 0];";
            };
            class open_jumpdoor_2_pilot {
                displayName = "<t color='#55bbff'>Open Jump Door 2</t";
                onlyforplayer = 0;
                radius = 100;
                showWindow = 0;
                position = "pilotcontrol";
                condition = "(this animationPhase 'jumpdoor_2' < 0.2) && player in crew this";
                statement = "this animate ['jumpdoor_2', 1];";
            };
            class close_jumpdoor_2_pilot {
                displayName = "<t color='#55bbff'>Close Jump Door 2</t";
                onlyforplayer = 0;
                radius = 100;
                showWindow = 0;
                position = "pilotcontrol";
                condition = "(this animationPhase 'jumpdoor_2' > 0.8) && player in crew this";
                statement = "this animate ['jumpdoor_2', 0];";
            };
            class open_door {
                displayName = "<t color='#55bbff'>Open Boarding Door</t";
                onlyforplayer = 0;
                radius = 4;
                showWindow = 0;
                position = "pos door front";
                condition = "(this animationPhase 'door' < 0.2)";
                statement = "this animate ['door', 1]; this animate ['ladder', 1]; this animate ['stup', 1];";
            };
            class close_door {
                displayName = "<t color='#55bbff'>Close Boarding Door</t";
                onlyforplayer = 0;
                radius = 4;
                showWindow = 0;
                position = "pos door front";
                condition = "(this animationPhase 'door' > 0.8)";
                statement = "this animate ['door', 0]; this animate ['ladder', 0]; this animate ['stup', 0];";
            };
            class LAIRCM {
                displayName = "LAIRCM";
                onlyforplayer = 0;
                position = "pilotcontrol";
                radius = 25;
                showWindow = 0;
                condition = "isEngineOn this && player in crew this";
                statement = "[this] spawn USAF_ECM_fnc_ECM_INIT;";
            };
        };
        class Damage {
            tex[] = {};
            mat[] = { "USAF_C17\data\mat\c17_lwing.rvmat", "USAF_C17\data\mat\dmg\c17_lwing.rvmat", "USAF_C17\data\mat\dmg\c17_lwing.rvmat", "USAF_C17\data\mat\c17_rwing.rvmat", "USAF_C17\data\mat\dmg\c17_rwing.rvmat", "USAF_C17\data\mat\dmg\c17_rwing.rvmat", "USAF_C17\data\mat\c17_1.rvmat", "USAF_C17\data\mat\dmg\c17_1.rvmat", "USAF_C17\data\mat\dmg\c17_1.rvmat", "USAF_C17\data\mat\c17_2.rvmat", "USAF_C17\data\mat\dmg\c17_2.rvmat", "USAF_C17\data\mat\dmg\c17_2.rvmat", "USAF_C17\data\mat\c17_3.rvmat", "USAF_C17\data\mat\dmg\c17_3.rvmat", "USAF_C17\data\mat\dmg\c17_3.rvmat", "USAF_C17\data\mat\c17_5.rvmat", "USAF_C17\data\mat\dmg\c17_5.rvmat", "USAF_C17\data\mat\dmg\c17_5.rvmat", "USAF_C17\data\mat\c17_6.rvmat", "USAF_C17\data\mat\dmg\c17_6.rvmat", "USAF_C17\data\mat\dmg\c17_6.rvmat", "USAF_C17\data\mat\c17_tail.rvmat", "USAF_C17\data\mat\dmg\c17_tail.rvmat", "USAF_C17\data\mat\dmg\c17_tail.rvmat" };
        };
        class Attributes {
            class usaf_rearRampPos {
                control = "Combo";
                defaultValue = 0;
                validate = "number";
                unique = 0;
                condition = "1";
                displayName = "Ramp Position";
                expression = "_this setVariable['%s', _value]; [_this, _value] call USAF_C17_fnc_rampCtrl;";
                property = "usaf_rearRampPos";
                toolTip = "Set the ramp position";
                typeName = "Number";
                class values {
                    class closed {
                        name = "Closed";
                        value = 0;
                    };
                    class half {
                        name = "Half";
                        value = 1;
                    };
                    class opened {
                        name = "Opened";
                        value = 2;
                    };
                };
            };
        };
        class EventHandlers : EventHandlers {
            init =
                "_this execvm "
                "\USAF_C17_C\scripts\init.sqf"
                "; [(_this select 0)] spawn USAF_Cargo_fnc_addActions;";
        };
        class Library {
            libTextDesc = "The Boeing C-17 Globemaster III is a large military transport aircraft. It was developed for the United States Air Force from the 1980s to the early 1990s by McDonnell Douglas. The C-17 is used for rapid strategic airlift of troops and cargo to main operating bases or forward operating bases throughout the world. The C-17 carries the name of two previous";
        };
        class TransportBackpacks {
            class _xx_B_Parachute {
                backpack = "B_Parachute";
                count = 60;
            };
        };
        class MarkerLights {
            class Nav_Red {
                name = "cerveny pozicni";
                color[] = { 10, 0, 0 };
                ambient[] = { 0.01, 0, 0 };
                intensity = 70;
                drawLight = 1;
                drawLightSize = 0.6;
                drawLightCenterSize = 0.2;
                activeLight = 0;
                blinking = 0;
                dayLight = 1;
                useFlare = 0;
            };
            class Nav_Green : Nav_Red {
                name = "zeleny pozicni";
                color[] = { 0, 10, 0, 1 };
                ambient[] = { 0, 0.01, 0, 0 };
            };
            class Nav_white : Nav_Red {
                name = "navigationlight white1";
                color[] = { 10, 10, 10, 1 };
                ambient[] = { 0.01, 0.01, 0.01, 0 };
            };
            class Strobe_L : Nav_Red {
                color[] = { 50, 50, 50 };
                ambient[] = { 0.1, 0.1, 0.1 };
                name = "_leftwingemitter";
                intensity = 70;
                activeLight = 1;
                useFlare = 1;
                blinking = 1;
                blinkingPattern[] = { 0.05, 0.95 };
                blinkingPatternGuarantee = 1;
                drawLightSize = 1;
                drawLightCenterSize = 0.4;
            };
            class Strobe_R : Strobe_L {
                name = "_rightwingemitter";
            };
            class Red_Strobe_T : Strobe_L {
                name = "Tail_Light";
                color[] = { 50, 0, 0, 1 };
                ambient[] = { 0.1, 0, 0, 0 };
                blinkingPattern[] = { 0.2, 1.1 };
            };
            class Red_Strobe_B : Red_Strobe_T {
                name = "Light_bottom";
            };
        };
        class Reflectors {
            class Left {
                position = "L svetlo";
                direction = "konec L svetla";
                hitpoint = "L svetlo";
                selection = "L svetlo";
                color[] = { 6000, 6500, 9000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 80;
                size = 1;
                innerAngle = 20;
                outerAngle = 60;
                coneFadeCoef = 10;
                brightness = 1;
                useFlare = 1;
                flareSize = 2;
                flareMaxDistance = 300;
                dayLight = 0;
            };
            class Right {
                position = "P svetlo";
                direction = "konec P svetla";
                hitpoint = "P svetlo";
                selection = "P svetlo";
                color[] = { 6000, 6500, 9000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 80;
                size = 1;
                innerAngle = 20;
                outerAngle = 60;
                coneFadeCoef = 10;
                brightness = 1;
                useFlare = 1;
                flareSize = 2;
                flareMaxDistance = 300;
                dayLight = 0;
            };
            class Left2 {
                position = "L_wing_light";
                direction = "L_wing_light_dir";
                hitpoint = "L_wing_light";
                selection = "L_wing_light";
                color[] = { 10000, 10500, 14000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 80;
                size = 1;
                innerAngle = 20;
                outerAngle = 60;
                coneFadeCoef = 10;
                brightness = 1;
                useFlare = 1;
                flareSize = 2;
                flareMaxDistance = 300;
                dayLight = 0;
            };
            class Right2 {
                position = "R_wing_light";
                direction = "R_wing_light_dir";
                hitpoint = "R_wing_light";
                selection = "R_wing_light";
                color[] = { 10000, 10500, 14000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 80;
                size = 1;
                innerAngle = 20;
                outerAngle = 60;
                coneFadeCoef = 10;
                brightness = 1;
                useFlare = 1;
                flareSize = 2;
                flareMaxDistance = 300;
                dayLight = 0;
            };
            class Left3 {
                position = "M svetlo";
                direction = "konec M svetla";
                hitpoint = "M svetlo";
                selection = "M svetlo";
                color[] = { 20000, 21000, 28000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 300;
                size = 1;
                innerAngle = 10;
                outerAngle = 30;
                coneFadeCoef = 10;
                brightness = 1;
                useFlare = 1;
                flareSize = 6;
                flareMaxDistance = 600;
                dayLight = 0;
            };
            class Right3 {
                position = "N svetlo";
                direction = "konec N svetla";
                hitpoint = "N svetlo";
                selection = "N svetlo";
                color[] = { 20000, 21000, 28000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 300;
                size = 1;
                innerAngle = 10;
                outerAngle = 30;
                coneFadeCoef = 10;
                brightness = 1;
                useFlare = 1;
                flareSize = 6;
                flareMaxDistance = 600;
                dayLight = 0;
            };
        };
        class MFD {
            class HUD {
                class Pos10Vector {
                    type = "vector";
                    pos0[] = { 0.5, 0.5 };
                    pos10[] = { 1.225, 1.1 };
                };
                enableParallax = 1;
                topLeft = "HUD LH";
                topRight = "HUD PH";
                bottomLeft = "HUD LD";
                borderLeft = 0;
                borderRight = 0;
                borderTop = 0;
                borderBottom = 0;
                color[] = { 0, 1, 0, 0.1 };
                class Bones {
                    class PlaneW {
                        type = "fixed";
                        pos[] = { 0.5, 0.5 };
                    };
                    class WeaponAim : Pos10Vector {
                        source = "weapon";
                    };
                    class Target : Pos10Vector {
                        source = "target";
                    };
                    class Velocity : Pos10Vector {
                        type = "vector";
                        source = "velocity";
                        pos0[] = { 0.5, 0.4 };
                        pos10[] = { 1.24, 1.1 };
                    };
                    class ILS_H {
                        type = "ils";
                        pos0[] = { 0.5, 0.4 };
                        pos3[] = { 0.722, 0.4 };
                    };
                    class ILS_W : ILS_H {
                        pos3[] = { 0.5, 0.61 };
                    };
                    class Level0 : Pos10Vector {
                        pos0[] = { 0.5, 0.4 };
                        pos10[] = { 1.24, 1.1 };
                        type = "horizon";
                        angle = 0;
                    };
                    class LevelP5 : Level0 {
                        angle = 5;
                    };
                    class LevelM5 : Level0 {
                        angle = -5;
                    };
                    class LevelP10 : Level0 {
                        angle = 10;
                    };
                    class LevelM10 : Level0 {
                        angle = -10;
                    };
                    class LevelP15 : Level0 {
                        angle = 15;
                    };
                    class LevelM15 : Level0 {
                        angle = -15;
                    };
                    class LevelP20 : Level0 {
                        angle = 20;
                    };
                    class LevelM20 : Level0 {
                        angle = -20;
                    };
                    class LevelP25 : Level0 {
                        angle = 25;
                    };
                    class LevelM25 : Level0 {
                        angle = -25;
                    };
                    class LevelP30 : Level0 {
                        angle = 30;
                    };
                    class LevelM30 : Level0 {
                        angle = -30;
                    };
                    class LevelP35 : Level0 {
                        angle = 35;
                    };
                    class LevelM35 : Level0 {
                        angle = -35;
                    };
                    class LevelP40 : Level0 {
                        angle = 40;
                    };
                    class LevelM40 : Level0 {
                        angle = -40;
                    };
                    class LevelP45 : Level0 {
                        angle = 45;
                    };
                    class LevelM45 : Level0 {
                        angle = -45;
                    };
                    class LevelP50 : Level0 {
                        angle = 50;
                    };
                    class LevelM50 : Level0 {
                        angle = -50;
                    };
                };
                class Draw {
                    alpha = 1;
                    color[] = { 0, 0.3, 0.05 };
                    condition = "on";
                    class PlaneW {
                        clipTL[] = { 0, 1 };
                        clipBR[] = { 1, 0 };
                        type = "line";
                        points[] = { { "PlaneW", { -0.08, 0 }, 1 }, { "PlaneW", { -0.03, 0 }, 1 }, { "PlaneW", { -0.015, 0.0283784 }, 1 }, { "PlaneW", { 0, 0 }, 1 }, { "PlaneW", { 0.015, 0.0283784 }, 1 }, { "PlaneW", { 0.03, 0 }, 1 }, { "PlaneW", { 0.08, 0 }, 1 } };
                    };
                    class PlaneHeading {
                        clipTL[] = { 0, 1 };
                        clipBR[] = { 1, 0 };
                        type = "line";
                        points[] = { { "Velocity", { 0, -0.0189189 }, 1 }, { "Velocity", { 0.014, -0.0132432 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, { "Velocity", { 0.014, 0.0132432 }, 1 }, { "Velocity", { 0, 0.0189189 }, 1 }, { "Velocity", { -0.014, 0.0132432 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, { "Velocity", { -0.014, -0.0132432 }, 1 }, { "Velocity", { 0, -0.0189189 }, 1 }, {}, { "Velocity", { 0.04, 0 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, {}, { "Velocity", { -0.04, 0 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, {}, { "Velocity", { 0, -0.0378378 }, 1 }, { "Velocity", { 0, -0.0189189 }, 1 }, {} };
                    };
                    class Static {
                        clipTL[] = { 0, 0.1 };
                        clipBR[] = { 1, 0 };
                        type = "line";
                        points[] = { { { 0.21, 0.52 }, 1 }, { { 0.19, 0.5 }, 1 }, { { 0.21, 0.48 }, 1 }, {}, { { 0.18, 0.2 }, 1 }, { { 0.18, 0.85 }, 1 }, {}, { { 0.79, 0.52 }, 1 }, { { 0.81, 0.5 }, 1 }, { { 0.79, 0.48 }, 1 }, {}, { { 0.82, 0.2 }, 1 }, { { 0.82, 0.85 }, 1 }, {}, { { 0.52, "0.08+0.01" }, 1 }, { { 0.5, "0.06+0.01" }, 1 }, { { 0.48, "0.08+0.01" }, 1 }, {}, { { 0.2, "0.055+0.01" }, 1 }, { { 0.8, "0.055+0.01" }, 1 }, {} };
                    };
                    class Horizont {
                        clipTL[] = { 0, 0 };
                        clipBR[] = { 1, 1 };
                        class Dimmed {
                            class Level0 {
                                type = "line";
                                points[] = { { "Level0", { -0.2, 0 }, 1 }, { "Level0", { -0.05, 0 }, 1 }, {}, { "Level0", { 0.05, 0 }, 1 }, { "Level0", { 0.2, 0 }, 1 } };
                            };
                            class VALM_1_0 {
                                type = "text";
                                source = "static";
                                text = 0;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "Level0", { -0.23, -0.025 }, 1 };
                                right[] = { "Level0", { -0.13, -0.025 }, 1 };
                                down[] = { "Level0", { -0.23, 0.025 }, 1 };
                            };
                            class VALM_2_0 : VALM_1_0 {
                                align = "right";
                                pos[] = { "Level0", { 0.22, -0.025 }, 1 };
                                right[] = { "Level0", { 0.32, -0.025 }, 1 };
                                down[] = { "Level0", { 0.22, 0.025 }, 1 };
                            };
                            class LevelM5 : Level0 {
                                type = "line";
                                points[] = { { "LevelM5", { -0.2, -0.03 }, 1 }, { "LevelM5", { -0.2, 0 }, 1 }, { "LevelM5", { -0.15, 0 }, 1 }, {}, { "LevelM5", { -0.1, 0 }, 1 }, { "LevelM5", { -0.05, 0 }, 1 }, {}, { "LevelM5", { 0.05, 0 }, 1 }, { "LevelM5", { 0.1, 0 }, 1 }, {}, { "LevelM5", { 0.15, 0 }, 1 }, { "LevelM5", { 0.2, 0 }, 1 }, { "LevelM5", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_5 {
                                type = "text";
                                source = "static";
                                text = -5;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM5", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM5", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM5", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_5 : VALM_1_5 {
                                align = "right";
                                pos[] = { "LevelM5", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM5", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM5", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP5 : Level0 {
                                type = "line";
                                points[] = { { "LevelP5", { -0.2, 0.03 }, 1 }, { "LevelP5", { -0.2, 0 }, 1 }, { "LevelP5", { -0.05, 0 }, 1 }, {}, { "LevelP5", { 0.05, 0 }, 1 }, { "LevelP5", { 0.2, 0 }, 1 }, { "LevelP5", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_5 {
                                type = "text";
                                source = "static";
                                text = "5";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP5", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP5", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP5", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_5 : VALP_1_5 {
                                align = "right";
                                pos[] = { "LevelP5", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP5", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP5", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM10 : Level0 {
                                type = "line";
                                points[] = { { "LevelM10", { -0.2, -0.03 }, 1 }, { "LevelM10", { -0.2, 0 }, 1 }, { "LevelM10", { -0.15, 0 }, 1 }, {}, { "LevelM10", { -0.1, 0 }, 1 }, { "LevelM10", { -0.05, 0 }, 1 }, {}, { "LevelM10", { 0.05, 0 }, 1 }, { "LevelM10", { 0.1, 0 }, 1 }, {}, { "LevelM10", { 0.15, 0 }, 1 }, { "LevelM10", { 0.2, 0 }, 1 }, { "LevelM10", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_10 {
                                type = "text";
                                source = "static";
                                text = -10;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM10", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM10", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM10", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_10 : VALM_1_10 {
                                align = "right";
                                pos[] = { "LevelM10", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM10", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM10", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP10 : Level0 {
                                type = "line";
                                points[] = { { "LevelP10", { -0.2, 0.03 }, 1 }, { "LevelP10", { -0.2, 0 }, 1 }, { "LevelP10", { -0.05, 0 }, 1 }, {}, { "LevelP10", { 0.05, 0 }, 1 }, { "LevelP10", { 0.2, 0 }, 1 }, { "LevelP10", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_10 {
                                type = "text";
                                source = "static";
                                text = "10";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP10", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP10", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP10", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_10 : VALP_1_10 {
                                align = "right";
                                pos[] = { "LevelP10", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP10", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP10", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM15 : Level0 {
                                type = "line";
                                points[] = { { "LevelM15", { -0.2, -0.03 }, 1 }, { "LevelM15", { -0.2, 0 }, 1 }, { "LevelM15", { -0.15, 0 }, 1 }, {}, { "LevelM15", { -0.1, 0 }, 1 }, { "LevelM15", { -0.05, 0 }, 1 }, {}, { "LevelM15", { 0.05, 0 }, 1 }, { "LevelM15", { 0.1, 0 }, 1 }, {}, { "LevelM15", { 0.15, 0 }, 1 }, { "LevelM15", { 0.2, 0 }, 1 }, { "LevelM15", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_15 {
                                type = "text";
                                source = "static";
                                text = -15;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM15", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM15", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM15", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_15 : VALM_1_15 {
                                align = "right";
                                pos[] = { "LevelM15", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM15", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM15", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP15 : Level0 {
                                type = "line";
                                points[] = { { "LevelP15", { -0.2, 0.03 }, 1 }, { "LevelP15", { -0.2, 0 }, 1 }, { "LevelP15", { -0.05, 0 }, 1 }, {}, { "LevelP15", { 0.05, 0 }, 1 }, { "LevelP15", { 0.2, 0 }, 1 }, { "LevelP15", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_15 {
                                type = "text";
                                source = "static";
                                text = "15";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP15", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP15", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP15", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_15 : VALP_1_15 {
                                align = "right";
                                pos[] = { "LevelP15", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP15", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP15", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM20 : Level0 {
                                type = "line";
                                points[] = { { "LevelM20", { -0.2, -0.03 }, 1 }, { "LevelM20", { -0.2, 0 }, 1 }, { "LevelM20", { -0.15, 0 }, 1 }, {}, { "LevelM20", { -0.1, 0 }, 1 }, { "LevelM20", { -0.05, 0 }, 1 }, {}, { "LevelM20", { 0.05, 0 }, 1 }, { "LevelM20", { 0.1, 0 }, 1 }, {}, { "LevelM20", { 0.15, 0 }, 1 }, { "LevelM20", { 0.2, 0 }, 1 }, { "LevelM20", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_20 {
                                type = "text";
                                source = "static";
                                text = -20;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM20", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM20", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM20", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_20 : VALM_1_20 {
                                align = "right";
                                pos[] = { "LevelM20", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM20", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM20", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP20 : Level0 {
                                type = "line";
                                points[] = { { "LevelP20", { -0.2, 0.03 }, 1 }, { "LevelP20", { -0.2, 0 }, 1 }, { "LevelP20", { -0.05, 0 }, 1 }, {}, { "LevelP20", { 0.05, 0 }, 1 }, { "LevelP20", { 0.2, 0 }, 1 }, { "LevelP20", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_20 {
                                type = "text";
                                source = "static";
                                text = "20";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP20", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP20", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP20", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_20 : VALP_1_20 {
                                align = "right";
                                pos[] = { "LevelP20", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP20", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP20", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM25 : Level0 {
                                type = "line";
                                points[] = { { "LevelM25", { -0.2, -0.03 }, 1 }, { "LevelM25", { -0.2, 0 }, 1 }, { "LevelM25", { -0.15, 0 }, 1 }, {}, { "LevelM25", { -0.1, 0 }, 1 }, { "LevelM25", { -0.05, 0 }, 1 }, {}, { "LevelM25", { 0.05, 0 }, 1 }, { "LevelM25", { 0.1, 0 }, 1 }, {}, { "LevelM25", { 0.15, 0 }, 1 }, { "LevelM25", { 0.2, 0 }, 1 }, { "LevelM25", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_25 {
                                type = "text";
                                source = "static";
                                text = -25;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM25", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM25", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM25", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_25 : VALM_1_25 {
                                align = "right";
                                pos[] = { "LevelM25", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM25", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM25", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP25 : Level0 {
                                type = "line";
                                points[] = { { "LevelP25", { -0.2, 0.03 }, 1 }, { "LevelP25", { -0.2, 0 }, 1 }, { "LevelP25", { -0.05, 0 }, 1 }, {}, { "LevelP25", { 0.05, 0 }, 1 }, { "LevelP25", { 0.2, 0 }, 1 }, { "LevelP25", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_25 {
                                type = "text";
                                source = "static";
                                text = "25";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP25", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP25", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP25", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_25 : VALP_1_25 {
                                align = "right";
                                pos[] = { "LevelP25", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP25", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP25", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM30 : Level0 {
                                type = "line";
                                points[] = { { "LevelM30", { -0.2, -0.03 }, 1 }, { "LevelM30", { -0.2, 0 }, 1 }, { "LevelM30", { -0.15, 0 }, 1 }, {}, { "LevelM30", { -0.1, 0 }, 1 }, { "LevelM30", { -0.05, 0 }, 1 }, {}, { "LevelM30", { 0.05, 0 }, 1 }, { "LevelM30", { 0.1, 0 }, 1 }, {}, { "LevelM30", { 0.15, 0 }, 1 }, { "LevelM30", { 0.2, 0 }, 1 }, { "LevelM30", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_30 {
                                type = "text";
                                source = "static";
                                text = -30;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM30", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM30", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM30", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_30 : VALM_1_30 {
                                align = "right";
                                pos[] = { "LevelM30", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM30", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM30", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP30 : Level0 {
                                type = "line";
                                points[] = { { "LevelP30", { -0.2, 0.03 }, 1 }, { "LevelP30", { -0.2, 0 }, 1 }, { "LevelP30", { -0.05, 0 }, 1 }, {}, { "LevelP30", { 0.05, 0 }, 1 }, { "LevelP30", { 0.2, 0 }, 1 }, { "LevelP30", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_30 {
                                type = "text";
                                source = "static";
                                text = "30";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP30", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP30", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP30", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_30 : VALP_1_30 {
                                align = "right";
                                pos[] = { "LevelP30", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP30", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP30", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM35 : Level0 {
                                type = "line";
                                points[] = { { "LevelM35", { -0.2, -0.03 }, 1 }, { "LevelM35", { -0.2, 0 }, 1 }, { "LevelM35", { -0.15, 0 }, 1 }, {}, { "LevelM35", { -0.1, 0 }, 1 }, { "LevelM35", { -0.05, 0 }, 1 }, {}, { "LevelM35", { 0.05, 0 }, 1 }, { "LevelM35", { 0.1, 0 }, 1 }, {}, { "LevelM35", { 0.15, 0 }, 1 }, { "LevelM35", { 0.2, 0 }, 1 }, { "LevelM35", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_35 {
                                type = "text";
                                source = "static";
                                text = -35;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM35", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM35", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM35", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_35 : VALM_1_35 {
                                align = "right";
                                pos[] = { "LevelM35", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM35", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM35", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP35 : Level0 {
                                type = "line";
                                points[] = { { "LevelP35", { -0.2, 0.03 }, 1 }, { "LevelP35", { -0.2, 0 }, 1 }, { "LevelP35", { -0.05, 0 }, 1 }, {}, { "LevelP35", { 0.05, 0 }, 1 }, { "LevelP35", { 0.2, 0 }, 1 }, { "LevelP35", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_35 {
                                type = "text";
                                source = "static";
                                text = "35";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP35", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP35", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP35", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_35 : VALP_1_35 {
                                align = "right";
                                pos[] = { "LevelP35", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP35", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP35", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM40 : Level0 {
                                type = "line";
                                points[] = { { "LevelM40", { -0.2, -0.03 }, 1 }, { "LevelM40", { -0.2, 0 }, 1 }, { "LevelM40", { -0.15, 0 }, 1 }, {}, { "LevelM40", { -0.1, 0 }, 1 }, { "LevelM40", { -0.05, 0 }, 1 }, {}, { "LevelM40", { 0.05, 0 }, 1 }, { "LevelM40", { 0.1, 0 }, 1 }, {}, { "LevelM40", { 0.15, 0 }, 1 }, { "LevelM40", { 0.2, 0 }, 1 }, { "LevelM40", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_40 {
                                type = "text";
                                source = "static";
                                text = -40;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM40", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM40", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM40", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_40 : VALM_1_40 {
                                align = "right";
                                pos[] = { "LevelM40", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM40", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM40", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP40 : Level0 {
                                type = "line";
                                points[] = { { "LevelP40", { -0.2, 0.03 }, 1 }, { "LevelP40", { -0.2, 0 }, 1 }, { "LevelP40", { -0.05, 0 }, 1 }, {}, { "LevelP40", { 0.05, 0 }, 1 }, { "LevelP40", { 0.2, 0 }, 1 }, { "LevelP40", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_40 {
                                type = "text";
                                source = "static";
                                text = "40";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP40", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP40", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP40", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_40 : VALP_1_40 {
                                align = "right";
                                pos[] = { "LevelP40", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP40", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP40", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM45 : Level0 {
                                type = "line";
                                points[] = { { "LevelM45", { -0.2, -0.03 }, 1 }, { "LevelM45", { -0.2, 0 }, 1 }, { "LevelM45", { -0.15, 0 }, 1 }, {}, { "LevelM45", { -0.1, 0 }, 1 }, { "LevelM45", { -0.05, 0 }, 1 }, {}, { "LevelM45", { 0.05, 0 }, 1 }, { "LevelM45", { 0.1, 0 }, 1 }, {}, { "LevelM45", { 0.15, 0 }, 1 }, { "LevelM45", { 0.2, 0 }, 1 }, { "LevelM45", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_45 {
                                type = "text";
                                source = "static";
                                text = -45;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM45", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM45", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM45", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_45 : VALM_1_45 {
                                align = "right";
                                pos[] = { "LevelM45", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM45", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM45", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP45 : Level0 {
                                type = "line";
                                points[] = { { "LevelP45", { -0.2, 0.03 }, 1 }, { "LevelP45", { -0.2, 0 }, 1 }, { "LevelP45", { -0.05, 0 }, 1 }, {}, { "LevelP45", { 0.05, 0 }, 1 }, { "LevelP45", { 0.2, 0 }, 1 }, { "LevelP45", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_45 {
                                type = "text";
                                source = "static";
                                text = "45";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP45", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP45", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP45", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_45 : VALP_1_45 {
                                align = "right";
                                pos[] = { "LevelP45", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP45", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP45", { 0.22, 0.085 }, 1 };
                            };
                            class LevelM50 : Level0 {
                                type = "line";
                                points[] = { { "LevelM50", { -0.2, -0.03 }, 1 }, { "LevelM50", { -0.2, 0 }, 1 }, { "LevelM50", { -0.15, 0 }, 1 }, {}, { "LevelM50", { -0.1, 0 }, 1 }, { "LevelM50", { -0.05, 0 }, 1 }, {}, { "LevelM50", { 0.05, 0 }, 1 }, { "LevelM50", { 0.1, 0 }, 1 }, {}, { "LevelM50", { 0.15, 0 }, 1 }, { "LevelM50", { 0.2, 0 }, 1 }, { "LevelM50", { 0.2, -0.03 }, 1 } };
                            };
                            class VALM_1_50 {
                                type = "text";
                                source = "static";
                                text = -50;
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelM50", { -0.23, -0.085 }, 1 };
                                right[] = { "LevelM50", { -0.13, -0.085 }, 1 };
                                down[] = { "LevelM50", { -0.23, -0.035 }, 1 };
                            };
                            class VALM_2_50 : VALM_1_50 {
                                align = "right";
                                pos[] = { "LevelM50", { 0.22, -0.085 }, 1 };
                                right[] = { "LevelM50", { 0.32, -0.085 }, 1 };
                                down[] = { "LevelM50", { 0.22, -0.035 }, 1 };
                            };
                            class LevelP50 : Level0 {
                                type = "line";
                                points[] = { { "LevelP50", { -0.2, 0.03 }, 1 }, { "LevelP50", { -0.2, 0 }, 1 }, { "LevelP50", { -0.05, 0 }, 1 }, {}, { "LevelP50", { 0.05, 0 }, 1 }, { "LevelP50", { 0.2, 0 }, 1 }, { "LevelP50", { 0.2, 0.03 }, 1 } };
                            };
                            class VALP_1_50 {
                                type = "text";
                                source = "static";
                                text = "50";
                                align = "left";
                                scale = 1;
                                sourceScale = 1;
                                pos[] = { "LevelP50", { -0.23, 0.035 }, 1 };
                                right[] = { "LevelP50", { -0.13, 0.035 }, 1 };
                                down[] = { "LevelP50", { -0.23, 0.085 }, 1 };
                            };
                            class VALP_2_50 : VALP_1_50 {
                                align = "right";
                                pos[] = { "LevelP50", { 0.22, 0.035 }, 1 };
                                right[] = { "LevelP50", { 0.32, 0.035 }, 1 };
                                down[] = { "LevelP50", { 0.22, 0.085 }, 1 };
                            };
                        };
                    };
                    class AltScale {
                        type = "scale";
                        scale = 1;
                        source = "altitudeASL";
                        sourceScale = 1;
                        align = "right";
                        pos[] = { 0.86, 0.82 };
                        right[] = { 0.94, 0.82 };
                        down[] = { 0.86, 0.87 };
                        lineXleft = 0.825;
                        lineYright = 0.835;
                        lineXleftMajor = 0.825;
                        lineYrightMajor = 0.845;
                        bottom = 0.2;
                        top = 0.85;
                        center = 0.5;
                        step = 20;
                        StepSize = "(0.85- 0.2)/20";
                        horizontal = 0;
                        min = "none";
                        max = "none";
                        numberEach = 5;
                        majorLineEach = 5;
                    };
                    class SpeedScale {
                        type = "scale";
                        scale = 1;
                        source = "speed";
                        sourceScale = 3.6;
                        align = "right";
                        pos[] = { 0.06, "0.82-0.85+0.2" };
                        right[] = { 0.14, "0.82-0.85+0.2" };
                        down[] = { 0.06, "0.87-0.85+0.2" };
                        lineXleft = "0.18 + 0.82 - 0.825";
                        lineYright = "0.18 + 0.82 - 0.835";
                        lineXleftMajor = "0.18 + 0.82 - 0.825";
                        lineYrightMajor = "0.18 + 0.82 - 0.845";
                        bottom = 0.85;
                        center = 0.5;
                        top = 0.2;
                        step = 20;
                        StepSize = "(0.85- 0.2)/20";
                        horizontal = 0;
                        min = "none";
                        max = "none";
                        numberEach = 5;
                        majorLineEach = 5;
                    };
                    class Gear {
                        condition = "ils";
                        class text {
                            type = "text";
                            source = "static";
                            text = "GEAR";
                            align = "right";
                            scale = 0.5;
                            sourceScale = 1;
                            pos[] = { { 0.84, 0.88 }, 1 };
                            right[] = { { 0.9, 0.88 }, 1 };
                            down[] = { { 0.84, 0.92 }, 1 };
                        };
                    };
                    class Flaps {
                        condition = "flaps";
                        class text {
                            type = "text";
                            source = "static";
                            text = "FLAPS";
                            align = "right";
                            scale = 0.5;
                            sourceScale = 1;
                            pos[] = { { 0.84, 0.93 }, 1 };
                            right[] = { { 0.9, 0.93 }, 1 };
                            down[] = { { 0.84, 0.97 }, 1 };
                        };
                    };
                    class weapons {
                        type = "text";
                        source = "weapon";
                        align = "right";
                        scale = 0.5;
                        sourceScale = 1;
                        pos[] = { { 0.1, 0.88 }, 1 };
                        right[] = { { 0.16, 0.88 }, 1 };
                        down[] = { { 0.1, 0.92 }, 1 };
                    };
                    class ammo {
                        type = "text";
                        source = "ammo";
                        align = "right";
                        scale = 0.5;
                        sourceScale = 1;
                        pos[] = { { 0.1, 0.93 }, 1 };
                        right[] = { { 0.16, 0.93 }, 1 };
                        down[] = { { 0.1, 0.97 }, 1 };
                    };
                    class VspeedNumber {
                        type = "text";
                        align = "right";
                        scale = 1;
                        source = "vspeed";
                        sourceScale = 1;
                        pos[] = { { 0.86, "0.52-0.4" }, 1 };
                        right[] = { { 0.94, "0.52-0.4" }, 1 };
                        down[] = { { 0.86, "0.57-0.4" }, 1 };
                    };
                    class HeadingScale {
                        type = "scale";
                        scale = 1;
                        source = "Heading";
                        sourceScale = 1;
                        align = "center";
                        pos[] = { "0.21-0.01", 0 };
                        right[] = { "0.29-0.01", 0 };
                        down[] = { "0.21-0.01", 0.05 };
                        lineXleft = 0.06;
                        lineYright = 0.05;
                        lineXleftMajor = 0.06;
                        lineYrightMajor = 0.04;
                        bottom = 0.8;
                        center = 0.5;
                        top = 0.2;
                        step = "18/9";
                        StepSize = "(0.80- 0.2)/20";
                        horizontal = 1;
                        min = "none";
                        max = "none";
                        numberEach = 5;
                        majorLineEach = 5;
                    };
                    class ILS {
                        condition = "ils";
                        class Glideslope {
                            clipTL[] = { 0, 0 };
                            clipBR[] = { 1, 1 };
                            class ILS {
                                type = "line";
                                points[] = { { "ILS_W", { -0.24, 0 }, 1 }, { "ILS_W", { 0.24, 0 }, 1 }, {}, { "ILS_W", { 0, 0.0227027 }, 1 }, { "ILS_W", { 0, -0.0227027 }, 1 }, {}, { "ILS_W", { 0.12, 0.0227027 }, 1 }, { "ILS_W", { 0.12, -0.0227027 }, 1 }, {}, { "ILS_W", { 0.24, 0.0227027 }, 1 }, { "ILS_W", { 0.24, -0.0227027 }, 1 }, {}, { "ILS_W", { -0.12, 0.0227027 }, 1 }, { "ILS_W", { -0.12, -0.0227027 }, 1 }, {}, { "ILS_W", { -0.24, 0.0227027 }, 1 }, { "ILS_W", { -0.24, -0.0227027 }, 1 }, {}, { "ILS_H", { 0, -0.227027 }, 1 }, { "ILS_H", { 0, 0.227027 }, 1 }, {}, { "ILS_H", { 0.024, 0 }, 1 }, { "ILS_H", { -0.024, 0 }, 1 }, {}, { "ILS_H", { 0.024, 0.113514 }, 1 }, { "ILS_H", { -0.024, 0.113514 }, 1 }, {}, { "ILS_H", { 0.024, 0.227027 }, 1 }, { "ILS_H", { -0.024, 0.227027 }, 1 }, {}, { "ILS_H", { 0.024, -0.113514 }, 1 }, { "ILS_H", { -0.024, -0.113514 }, 1 }, {}, { "ILS_H", { 0.024, -0.227027 }, 1 }, { "ILS_H", { -0.024, -0.227027 }, 1 } };
                            };
                        };
                    };
                };
            };
            class HUD2 : HUD {
                topLeft = "HUD2 LH";
                topRight = "HUD2 PH";
                bottomLeft = "HUD2 LD";
            };
        };
        USAF_Cargo_MaxWidth = 10;
        USAF_Cargo_MaxLength = 22;
        USAF_Cargo_MaxHeight = 6;
        USAF_Cargo_MaxWeight = 137250;
        USAF_Cargo_initOffset[] = { 0, -21, -3.38 };
        USAF_Cargo_midOffset[] = { 0, -3, -1.27 };
        USAF_Cargo_endOffset[] = { 0, 15, -1.26 };
        USAF_Cargo_InitPos[] = { 0, -20, -3.45 };
        USAF_Cargo_LAPESPos[] = { 0, -30, -5 };
        USAF_Cargo_DropPos[] = { 0, -30, -5 };
        USAF_Cargo_Doors[] = { "back_ramp", "back_ramp_st", "back_ramp_p", "back_ramp_p_2", "back_ramp_door_main" };
        driveOnComponent[] = { "wheel_1", "wheel_2_1", "wheel_3_1", "wheel_4_1", "wheel_5_1" };
        maxOmega = 2000;
        class Wheels {
            class wheel_1 {
                boneName = "wheel_1";
                boundary = "wheel_1_rim";
                center = "wheel_1_center";
                dampingRate = 0.25;
                dampingRateDamaged = 1;
                dampingRateDestroyed = 1000;
                frictionVsSlipGraph[] = { "[0", "1]", "[0.5", "1]", "[1", "1]" };
                latStiffX = 25;
                latStiffY = 180;
                longitudinalStiffnessPerUnitGravity = 5000;
                mass = 150;
                maxBrakeTorque = 1500;
                maxCompression = 0.15;
                maxDroop = 0.15;
                maxHandBrakeTorque = 0;
                MOI = 2;
                side = "left";
                springDamperRate = 37000;
                springStrength = 149000;
                sprungMass = 21000;
                steering = 1;
                suspForceAppPointOffset = "wheel_1_center";
                suspTravelDirection[] = { 0, -1, 0 };
                tireForceAppPointOffset = "wheel_1_center";
                width = 0.3;
            };
            class wheel_2 : wheel_1 {
                boneName = "wheel_2_1";
                boundary = "wheel_2_1_rim";
                center = "wheel_2_1_center";
                springDamperRate = 23883;
                springStrength = 95531;
                sprungMass = 27000;
                steering = 0;
                suspForceAppPointOffset = "wheel_2_1_center";
                tireForceAppPointOffset = "wheel_2_1_center";
            };
            class wheel_3 : wheel_2 {
                boneName = "wheel_3_1";
                boundary = "wheel_3_1_rim";
                center = "wheel_3_1_center";
                side = "right";
                suspForceAppPointOffset = "wheel_3_1_center";
                tireForceAppPointOffset = "wheel_3_1_center";
            };
            class wheel_4 : wheel_2 {
                boneName = "wheel_4_1";
                boundary = "wheel_4_1_rim";
                center = "wheel_4_1_center";
                side = "right";
                suspForceAppPointOffset = "wheel_4_1_center";
                tireForceAppPointOffset = "wheel_4_1_center";
            };
            class wheel_5 : wheel_2 {
                boneName = "wheel_5_1";
                boundary = "wheel_5_1_rim";
                center = "wheel_5_1_center";
                side = "right";
                suspForceAppPointOffset = "wheel_5_1_center";
                tireForceAppPointOffset = "wheel_5_1_center";
            };
        };
        thrustCoef[] = { 0.15, 0.8, 1.2, 1.3, 1.5, 1.2, 1, 0.9, 0.6, 0.5, 0.3, 0.1, 0 };
        class HitPoints {
            class HitAvionics {
                armor = 3;
                depends = "0";
                explosionShielding = 1;
                material = -1;
                minimalHit = 0.02;
                name = "HitAvionics";
                passThrough = 0.2;
                radius = 0.2;
                visual = "HitAvionics";
            };
            class HitEngine {
                armor = 1.5;
                depends = "0";
                explosionShielding = 2;
                material = -1;
                minimalHit = 0.1;
                name = "HitEngine";
                passThrough = 0.5;
                radius = 0.15;
                visual = "HitEngine";
            };
            class HitEngine2 : HitEngine {
                name = "HitEngine2";
                visual = "HitEngine2";
            };
            class HitFuel {
                armor = 30;
                depends = "0";
                explosionShielding = 4;
                material = -1;
                minimalHit = 0.1;
                name = "HitFuel";
                passThrough = 0.5;
                radius = 0.25;
                visual = "HitFuel";
            };
            class HitFuel2 : HitFuel {
                name = "HitFuel2";
                visual = "HitFuel2";
            };
            class HitHull {
                armor = 30;
                depends = "0";
                explosionShielding = 5;
                material = -1;
                minimalHit = 0.02;
                name = "HitHull";
                passThrough = 0.5;
                radius = 0.5;
                visual = "HitHull";
            };
            class HitLAileron {
                armor = 1.5;
                depends = "0";
                explosionShielding = 3;
                material = -1;
                minimalHit = 0.1;
                name = "HitLAileron";
                passThrough = 0.1;
                radius = 0.18;
                visual = "HitLAileron";
            };
            class HitRAileron : HitLAileron {
                name = "HitRAileron";
                visual = "HitRAileron";
            };
            class HitLCElevator {
                armor = 1.5;
                depends = "0";
                explosionShielding = 3;
                material = -1;
                minimalHit = 0.1;
                name = "HitLCElevator";
                passThrough = 0.1;
                radius = 0.2;
                visual = "HitLCElevator";
            };
            class HitRElevator : HitLCElevator {
                name = "HitRElevator";
                visual = "HitRElevator";
            };
            class HitLCRudder {
                armor = 1.5;
                depends = "0";
                explosionShielding = 3;
                material = -1;
                minimalHit = 0.1;
                name = "HitLCRudder";
                passThrough = 0.1;
                radius = 0.25;
                visual = "HitLCRudder";
            };
            class HitGlass1 {
                armor = 2;
                material = -1;
                name = "glass1";
                visual = "glass1";
                passThrough = 0;
            };
            class HitGlass2 : HitGlass1 {
                armor = 0.5;
            };
        };
        class VehicleTransport {
            class Carrier {
                cargoBayDimensions[] = { "VIV_point_1", "VIV_point_2" };
                disableHeightLimit = 0;
                maxLoadMass = 137250;
                cargoAlignment[] = { "front", "center" };
                cargoSpacing[] = { 0, 0, 0 };
                exits[] = { "VIV_exit" };
                unloadingInterval = 2;
                loadingDistance = 15;
                loadingAngle = 60;
                parachuteClassDefault = "B_Parachute_02_F";
                parachuteHeightLimitDefault = 5;
            };
            class Cargo {
                canBeTransported = 0;
            };
        };
        class TextureSources {
            class Standard {
                author = "USAF Mod Team";
                displayName = "Standard";
                textures[] = { "\USAF_C17\data\texture\C17-1_co.paa", "\USAF_C17\data\texture\C17-2_co.paa", "\USAF_C17\data\texture\C17-3_co.paa", "\USAF_C17\data\texture\C17-5_co.paa", "\USAF_C17\data\texture\C17-6_co.paa", "\USAF_C17\data\texture\C17-7_t_co.paa", "\USAF_C17\data\texture\C17-8_co.paa", "\USAF_C17\data\texture\C17-eng_co.paa", "\USAF_C17\data\texture\Lwng_co.paa", "\USAF_C17\data\texture\Rwng_co.paa", "\USAF_C17\data\texture\Tail_co.paa" };
                factions[] = { "USAF", "BLU_F" };
            };
        };
    };
    class PlaneWreck;
    class USAF_c17_Wreck : PlaneWreck {
        scope = 1;
        class Armory {
            disabled = 1;
        };
        model = "\USAF_C17\USAF_C17_Wreck.p3d";
        typicalCargo[] = {};
        irTarget = 0;
        transportAmmo = 0;
        transportRepair = 0;
        transportFuel = 0;
        transportSoldier = 0;
        class Eventhandlers : DefaultEventhandlers {};
    };
};
