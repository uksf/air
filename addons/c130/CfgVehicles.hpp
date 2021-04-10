class DefaultVehicleSystemsDisplayManagerRight;
class DefaultVehicleSystemsDisplayManagerLeft;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class SensorTemplateDataLink;
class CfgVehicles {
    class Plane;
    class Plane_Base_F : Plane {
        class NewTurret;
        class Turrets {
            class CopilotTurret;
        };
        class ViewPilot;
        class ViewGunner;
        class HitPoints {
            class HitHull;
        };
        class Components;
    };
    class GVAR(base) : Plane_Base_F {
        scope = 0;
        scopeCurator = 0;
        side = 1;
        displayname = "C-130J";
        faction = "CUP_B_GB";
        model = QPATHTOF(uksf_c130_base.p3d);
        icon = QPATHTOF(data\ui\icon.paa);
        picture = QPATHTOF(data\ui\picture.paa);
        editorPreview = QPATHTOF(data\ui\uksf_c130_raf.jpg);
        crew = "B_Pilot_F";
        unitInfoType = "RscUnitInfoAirPlaneNoSpeed";
        unitInfoTypeLite = "RscUnitInfoAirPlaneNoSpeed";
        hiddenSelections[] = { "camo1", "camo2", "interior" };
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\tex\c130j_body_raf_co.paa),
            QPATHTOF(data\tex\c130j_wings_raf_co.paa),
            QPATHTOF(data\tex\c130j_interior_raf_co.paa)
        };
        mapSize = 25;
        threat[] = { 0.1, 0.1, 0.1 };
        ejectSpeed[] = { 0, 0, 0 };
        simulation = "airplaneX";
        landingAoa = "rad 7";
        landingSpeed = 220;
        extCameraPosition[] = { 0, 0, -40 };
        envelope[] = { 0, 0.1, 0.9, 2.8, 3.5, 3.7, 3.8, 3.8, 3.6, 3.3, 3 };
        wheelSteeringSensitivity = 5;
        aileronSensitivity = 1.3;
        aileronCoef[] = { 0, 0.5, 0.9, 1, 1.05, 1.1, 1.12 };
        elevatorSensitivity = 0.8;
        elevatorCoef[] = { 0, 0.4, 0.9, 1, 1.05, 1.1, 1.15 };
        rudderInfluence = 0.8;
        rudderCoef[] = { 0, 0.8, 1.5, 1.9, 2.2, 2.4, 2.5, 2.5, 2.6, 2.6, 2.6 };
        aileronControlsSensitivityCoef = 1;
        elevatorControlsSensitivityCoef = 1.5;
        rudderControlsSensitivityCoef = 1.5;
        draconicForceXCoef = 25;
        draconicForceYCoef = 0.2;
        draconicForceZCoef = 1;
        draconicTorqueXCoef[] = { 25, 24.5, 23, 22.5, 22, 22, 22.5, 23, 24, 25, 26 };
        draconicTorqueYCoef[] = { 1, 1.2, 1.4, 2, 4, 7, 6.8, 6.6, 6.4, 6.2, 5.5, 5, 4.5, 3.9, 3, 1 };
        thrustCoef[] = { 0.5, 0.75, 0.9, 1, 1.2, 1, 0.9, 0.7, 0.6, 0.5, 0.3, 0.1, 0 };
        airBrake = 1;
        airBrakeFrictionCoef = 5;
        flapsFrictionCoef = 1;
        noseDownCoef = 1;
        gearUpTime = 4.5;
        gearDownTime = 3;
        destrType = "DestructWreck";
        cabinOpening = 0;
        maxSpeed = 600;
        accuracy = 0.15;
        cost = 20000;
        lockDetectionSystem = "8 + 4";
        incomingMissileDetectionSystem = "8 + 16";
        audible = 6;
        armor = 150;
        armorWheels = 4000;
        fuelCapacity = 2000;
        fuelConsumptionRate = 0.398;
        armorStructured = 1;
        showNVGCargo[] = { 1 };
        brakeDistance = 200;
        gearRetracting = 1;
        lightOnGear = 0;
        getInRadius = 4;
        driverAction = QGVAR(pilot);
        driverLeftHandAnimName = "stick_pilot";
        driverRightHandAnimName = "stick_pilot";
        cargocaneject = 1;
        cargoIsCoDriver[] = { 0, 0 };
        cargoGetInAction[] = { "GetInLow" };
        cargoGetOutAction[] = { "GetOutLow" };
        cargoAction[] = { "Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04","Truck_Cargo02","Truck_Cargo01","Truck_Cargo04" };
        getinaction = "GetInLow";
        getoutaction = "GetInLow";
        gunnerhasflares = 1;
        crewVulnerable = 1;
        transportSoldier = 43;
        maximumLoad = 100000;
        gunnerUsesPilotView = 1;
        driverCompartments = "Compartment1";
        cargoCompartments[] = { "Compartment2" };
        class TransportBackpacks {
            class _xx_B_Parachute {
                backpack = "B_Parachute";
                count = 30;
            };
        };
        weapons[] = { QEGVAR(weapons,C130FlareLauncher) };
        magazines[] = { "300Rnd_CMFlare_Chaff_Magazine" };
        memoryPointCM[] = { "flare_launcher1", "flare_launcher2", "flare_launcher3", "flare_launcher4" };
        memoryPointCMDir[] = { "flare_launcher1_dir", "flare_launcher2_dir", "flare_launcher3_dir", "flare_launcher4_dir" };
        soundGetIn[] = { QPATHTOF(data\sounds\close),0.31622776,1 };
        soundGetOut[] = { QPATHTOF(data\sounds\open),0.31622776,1,40 };
        soundEngineOnInt[] = { QPATHTOF(data\sounds\int_start_1),0.5,1,100 };
        soundEngineOnExt[] = { QPATHTOF(data\sounds\ext_Start_1),2,1,700 };
        soundEngineOffInt[] = { QPATHTOF(data\sounds\int_stop_1),2,1,100 };
        soundEngineOffExt[] = { QPATHTOF(data\sounds\ext_stop_1),2,1,700 };
        soundIncommingMissile[] = { "a3\sounds_f\vehicles\air\noises\alarm_locked_by_missile_2", 0.1, 1.5 };
        soundGearUp[] = { "A3\Sounds_F_EPC\CAS_01\gear_up", 0.794328, 0.4, 150 };
        soundGearDown[] = { "A3\Sounds_F_EPC\CAS_01\gear_down", 0.794328, 0.4, 150 };
        soundFlapsUp[] = { "A3\Sounds_F_EPC\CAS_01\Flaps_Up", 0.630957, 0.4, 100 };
        soundFlapsDown[] = { "A3\Sounds_F_EPC\CAS_01\Flaps_Down", 0.630957, 0.4, 100 };
        class Sounds {
            class EngineLowOut {
                sound[] = { QPATHTOF(data\sounds\c130idle.wss),2,1.0,1000 };
                frequency = "(rpm interpolate [0,1,0.3,1])*(thrust interpolate [0,1,0.8,1.1])";
                volume = "engineOn*camPos*(rpm interpolate [0.5,1,0,1])*(thrust interpolate [0,1,1,1.3])";
            };
            class ForsageOut {
                sound[] = { QPATHTOF(data\sounds\c130forsageV1.wss),2,1,1500 };
                frequency = "(rpm interpolate [0,1,1,1])*(thrust interpolate [0,1,0.8,1.1])";
                volume = "camPos*(rpm interpolate [0,1,0,1])*(thrust interpolate [0,1,0.3,1])";
            };
            class ActuatorForsageOut {
                sound[] = { QPATHTOF(data\sounds\c130ThrottleUpForsage.wss),2,1,800 };
                frequency = "(thrust interpolate [0,1,0.8,1.1])";
                volume = "engineOn*camPos*(thrust factor[0.6, 1.0])";
            };
            class WindNoiseOut {
                sound[] = { QPATHTOF(data\sounds\f_windnoise_ext.wss),1,0.6,150 };
                frequency = "(0.1+(1.2*(speed factor[1, 150])))";
                volume = "camPos*(speed factor[1, 150])";
            };
            class DistantPlaneOut {
                sound[] = { QPATHTOF(data\sounds\c130distant.wss),3,1.0,2000 };
                frequency = "(rpm interpolate [0,1,0.5,1])*(thrust interpolate [0,1,0.8,1])";
                volume = "engineOn*camPos*(rpm interpolate [0,1,0,1])*(thrust interpolate [0,1,0.5,1])";
            };
            class EngineLowIn {
                sound[] = { QPATHTOF(data\sounds\int_engine_low),1,1,100 };
                frequency = "(rpm interpolate [0,1,0.2,1])*(thrust interpolate [0,1,0.8,1.1])";
                volume = "(1-camPos)*engineOn*(rpm interpolate [0,1,0,1])*(thrust interpolate [0.6,1,1,0.5])";
            };
            class EngineHighIn {
                sound[] = { QPATHTOF(data\sounds\int_engine_hi),1,1,100 };
                frequency = "(thrust interpolate [0,1,0.8,1.1])";
                volume = "(1-camPos)*engineOn*(rpm interpolate [0.55,1,0,1])*(thrust interpolate [0.6,1,0.3,1])";
            };
            class ForsageIn {
                sound[] = { QPATHTOF(data\sounds\int_forsage_1.wss),0.5,1,100 };
                frequency = "1";
                volume = "0*(1-camPos)*engineOn*(rpm interpolate [0.4,1,0,1])";
            };
            class WindNoiseIn {
                sound[] = { QPATHTOF(data\sounds\f_windnoise_int.wss),1,100 };
                frequency = "(0.3+(1.005*(speed factor[1, 50])))";
                volume = "(1-camPos)*(speed factor[1, 50])";
            };
        };
        class Attributes {
            class GVAR(rampPosition) {
                control = "Combo";
                defaultValue = 0;
                validate = "number";
                unique = 0;
                condition = "objectVehicle";
                displayName = "Ramp Position";
                expression = QUOTE([ARR_2(_this,_value)] call FUNC(rampControl));
                property = QGVAR(rampPosition);
                toolTip = "Set the ramp position";
                typeName = "Number";
                class values {
                    class closed {
                        name = "Closed";
                        value = 0;
                    };
                    class half {
                        name = "Half Open";
                        value = 1;
                    };
                    class opened {
                        name = "Fully Open";
                        value = 2;
                    };
                };
            };
        };
        class AnimationSources {
            class door_2_2 {
                source = "user";
                animPeriod = 10;
                sound = "ServoRampSound";
            };
            class door_2_1 : door_2_2 {};
            class door_1 : door_2_2 {};
            class ramp_bottom {
                source = "user";
                initPhase = 0;
                animPeriod = 10;
                sound = "ServoRampSound";
            };
            class fuel_probe {
                source = "user";
                initPhase = 0;
                animPeriod = 0.0001;
            };
            class ramp_top {
                source = "user";
                initPhase = 0;
                animPeriod = 10;
                sound = "ServoRampSound";
            };
            class CollisionLightRed_source {
                source = "MarkerLight";
                markerLight = "PositionRed";
            };
            class fuel_tank_hide {
                displayName = "Hide Ext Fuel";
                source = "user";
                initPhase = 1;
                animPeriod = 0.0001;
            };
            class cargo_hide_now {
                source = "user";
                initPhase = 0;
                animPeriod = 0.0001;
            };
            class Formlights {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
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
            class Damper_1_1_source {
                source = "damper";
                wheel = "wheel_1_1";
            };
            class Damper_2_1_source {
                source = "damper";
                wheel = "wheel_2_1";
            };
            class Damper_2_2_source {
                source = "damper";
                wheel = "wheel_2_2";
            };
            class wheel_1_1_source {
                source = "wheel";
                wheel = "wheel_1_1";
            };
            class wheel_2_1_source {
                source = "wheel";
                wheel = "wheel_2_1";
            };
            class wheel_2_2_source {
                source = "wheel";
                wheel = "wheel_2_2";
            };
            class wheel_3_1_source {
                source = "wheel";
                wheel = "wheel_2_1";
            };
            class wheel_3_2_source {
                source = "wheel";
                wheel = "wheel_2_2";
            };
        };
        class UserActions {
            class CloseRamp {
                position = "pilotcontrol";
                onlyforplayer = 1;
                radius = 8;
                showwindow = 0;
                displayName = "Close Ramp";
                condition = QUOTE([ARR_2(this,0)] call FUNC(canControlRamp));
                statement = QUOTE([ARR_2(this,0)] call FUNC(rampControl));
            };
            class HalfRamp : CloseRamp {
                displayname = "Open Ramp Halfway";
                condition = QUOTE([ARR_2(this,1)] call FUNC(canControlRamp));
                statement = QUOTE([ARR_2(this,1)] call FUNC(rampControl));
            };
            class OpenRamp : CloseRamp {
                displayName = "Open Ramp Fully";
                condition = QUOTE([ARR_2(this,2)] call FUNC(canControlRamp));
                statement = QUOTE([ARR_2(this,2)] call FUNC(rampControl));
            };
            class OpenLdoor {
                displayName = "Open Left Jump Door";
                position = "pos doorL";
                onlyforplayer = 1;
                radius = 6;
                showwindow = 0;
                condition = "(this animationPhase 'door_2_1') == 0";
                statement = "this animate ['door_2_1',1]";
            };
            class OpenRdoor : OpenLdoor {
                position = "pos doorR";
                displayName = "Open Right Jump Door";
                condition = "(this animationPhase 'door_2_2') == 0";
                statement = "this animate ['door_2_2',1]";
            };
            class Closeldoor : OpenLdoor {
                displayName = "Close Left Jump Door";
                condition = "(this animationPhase 'door_2_1') == 1";
                statement = "this animate ['door_2_1',0]";
            };
            class Closerdoor : OpenRdoor {
                displayName = "Close Right Jump Door";
                condition = "(this animationPhase 'door_2_2') == 1";
                statement = "this animate ['door_2_2',0]";
            };
            class openfdoor : OpenLdoor {
                position = "pos door crew";
                displayName = "Open Crew Door";
                condition = "(this animationPhase 'door_1') == 0";
                statement = "this animate ['door_1',1]";
            };
            class openfdoorCrew : openfdoor {
                position = "pilotcontrol";
                radius = 50;
                condition = "(this animationPhase 'door_1') == 0 && player in (crew this)";
            };
            class closefdoor : openfdoor {
                displayName = "Close Crew Door";
                condition = "(this animationPhase 'door_1') == 1";
                statement = "this animate ['door_1',0]";
            };
            class closefdoorCrew : closefdoor {
                position = "pilotcontrol";
                radius = 50;
                condition = "(this animationPhase 'door_1') == 1 && player in (crew this)";
            };
            class FormlightsOn {
                displayName = "Formation lights On";
                displayNameDefault = "";
                position = "pilotcontrol";
                textToolTip = "";
                priority = 0.4;
                radius = 5;
                onlyForPlayer = 1;
                condition = "(this animationPhase 'Formlights') == 0 && player == driver this;";
                statement = "this animate ['Formlights',1];";
            };
            class FormlightsOff {
                displayName = "Formation lights Off";
                displayNameDefault = "";
                position = "pilotcontrol";
                textToolTip = "";
                priority = 0.4;
                radius = 5;
                onlyForPlayer = 1;
                condition = "(this animationphase 'Formlights') == 1 && player == driver this;";
                statement = "this animate ['Formlights',0];";
            };
            class JumpLightsOff {
                displayName = "Jump Lights Off";
                position = "pilotcontrol";
                priority = 1.9;
                radius = 5;
                onlyForPlayer = 1;
                condition = QUOTE([ARR_2(this,0)] call FUNC(canControlJumpLights));
                statement = QUOTE([ARR_2(this,0)] call FUNC(jumpLightControl));
            };
            class JumpLightsRed : JumpLightsOff {
                displayName = "Jump Lights Red";
                priority = 2;
                condition = QUOTE([ARR_2(this,1)] call FUNC(canControlJumpLights));
                statement = QUOTE([ARR_2(this,1)] call FUNC(jumpLightControl));
            };
            class JumpLightsGreen : JumpLightsOff {
                displayName = "Jump Lights Green";
                priority = 2;
                condition = QUOTE([ARR_2(this,2)] call FUNC(canControlJumpLights));
                statement = QUOTE([ARR_2(this,2)] call FUNC(jumpLightControl));
            };
        };
        class HitPoints {
            class HitFWheel {
                armor = 1;
                material = -1;
                name = "wheel_1_1";
                visual = "";
                passThrough = 0;
            };
            class HitMLWheel : HitFWheel {
                name = "wheel_2_1";
            };
            class HitMRWheel : HitFWheel {
                name = "wheel_2_2";
            };
            class HitBLWheel : HitFWheel {
                name = "wheel_3_1";
            };
            class HitBRWheel : HitFWheel {
                name = "wheel_3_2";
            };
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
            class HitEngine2 {
                armor = 1.5;
                depends = "0";
                explosionShielding = 2;
                material = -1;
                minimalHit = 0.1;
                name = "HitEngine2";
                passThrough = 0.5;
                radius = 0.15;
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
        };
        class ViewPilot {
            minMoveX = -0.2;
            maxMoveX = 0.2;
            minMoveY = -0.1;
            maxMoveY = 0.1;
            minMoveZ = -0.1;
            maxMoveZ = 0.2;
            minFov = 0.25;
            maxFov = 1.25;
            initFov = 0.75;
            initAngleX = 0;
            minAngleX = -65;
            maxAngleX = 85;
            initAngleY = 0;
            minAngleY = -150;
            maxAngleY = 150;
            speedZoomMaxSpeed = 0;
            speedZoomMaxFOV = 0.75;
        };
        class Turrets : Turrets {
            class CopilotTurret : CopilotTurret {
                memoryPointsGetInGunner = "pos gunner";
                memoryPointsGetInGunnerDir = "pos gunner dir";
                gunnerGetInAction = "GetInLow";
                gunnerGetOutAction = "GetOutLow";
                gunnerAction = QGVAR(pilot);
                gunnerInAction = QGVAR(pilot);
                isCopilot = 1;
                gunnerLeftHandAnimName = "stick_pilot";
                gunnerRightHandAnimName = "stick_pilot";
                class ViewGunner {
                    minMoveX = -0.2;
                    maxMoveX = 0.2;
                    minMoveY = -0.1;
                    maxMoveY = 0.1;
                    minMoveZ = -0.1;
                    maxMoveZ = 0.2;
                    minFov = 0.25;
                    maxFov = 1.25;
                    initFov = 0.75;
                    initAngleX = 0;
                    minAngleX = -65;
                    maxAngleX = 85;
                    initAngleY = 0;
                    minAngleY = -150;
                    maxAngleY = 150;
                    speedZoomMaxSpeed = 0;
                    speedZoomMaxFOV = 0.75;
                };
                speedZoomMaxSpeed = 0;
                speedZoomMaxFOV = 0.75;
#include "MFD.hpp"
            };
            class FlightEngineerTurret : NewTurret {
                commanding = -2;
                gunnerName = "Flight Engineer";
                gunnerCompartments = "Compartment1";
                memoryPointsGetInGunner = "pos gunner";
                memoryPointsGetInGunnerDir = "pos gunner dir";
                gunnerAction = "Truck_Cargo01";
                gunnerInAction = "Truck_Cargo01";
                body = "";
                gun = "";
                animationSourceBody = "";
                animationSourceGun = "";
                gunnerUsesPilotView = 1;
                primaryGunner = 0;
                isCopilot = 0;
                proxyIndex = 2;
                canEject = 1;
                startEngine = 0;
                gunnerForceOptics = 0;
                minElev = -60;
                maxElev = 10;
                initElev = 0;
                minTurn = -70;
                maxTurn = 70;
                initTurn = 0;
                ejectDeadGunner = "true";
                gunnerLeftHandAnimName = "";
                gunnerRightHandAnimName = "";
                gunnerLeftLegAnimName = "";
                gunnerRightLegAnimName = "";
                class ViewPilot : ViewPilot {
                    initFov = 1;
                    minFov = 0.3;
                    maxFov = 1.2;
                    initAngleX = 0;
                    minAngleX = -75;
                    maxAngleX = 85;
                    initAngleY = 0;
                    minAngleY = -170;
                    maxAngleY = 170;
                };
            };
            class LoadMasterLeftDoorTurret : FlightEngineerTurret {
                enabledByAnimationSource = "ramp_bottom";
                commanding = -3;
                gunnerName = "Load Master (Left Jump Door)";
                gunnerCompartments = "Compartment2";
                gunnerUsesPilotView = 0;
                gunnerAction = "Stand";
                proxyIndex = 3;
                memoryPointsGetInGunner = "pos cargo";
                memoryPointsGetInGunnerDir = "pos cargo dir";
                gunnergetinaction = "GetInLow";
                gunnergetoutaction = "GetOutHigh";
                showAsCargo = 1;
                minElev = -40;
                maxElev = 10;
                initElev = 0;
                minTurn = -20;
                maxTurn = 60;
                initTurn = 0;
                class ViewPilot : ViewPilot {
                    initFov = 1;
                    minFov = 0.3;
                    maxFov = 1.2;
                    initAngleX = 0;
                    minAngleX = -75;
                    maxAngleX = 85;
                    initAngleY = 0;
                    minAngleY = -170;
                    maxAngleY = 170;
                };
            };
            class LoadMasterRightDoorTurret : LoadMasterLeftDoorTurret {
                proxyIndex = 4;
                gunnerName = "Load Master (Right Jump Door)";
                dontCreateAI = 1;
            };
            class LoadMasterRampTurret : LoadMasterLeftDoorTurret {
                proxyIndex = 5;
                gunnerName = "Load Master (Ramp)";
                gunnerAction = "CUP_CH47_Gunner01";
                dontCreateAI = 1;
            };
        };
        class Damage {
            tex[] = {};
            mat[] = {
                QPATHTO_R(data\rvmat\c130j_sklo.rvmat),
                QPATHTO_R(data\rvmat\c130j_sklo_damage.rvmat),
                QPATHTO_R(data\rvmat\c130j_sklo_damage.rvmat),
                QPATHTO_R(data\rvmat\c130j_sklo_in.rvmat),
                QPATHTO_R(data\rvmat\c130j_sklo_in_damage.rvmat),
                QPATHTO_R(data\rvmat\c130j_sklo_in_damage.rvmat),
                QPATHTO_R(data\rvmat\c130j_body.rvmat),
                QPATHTO_R(data\rvmat\c130j_body_damage.rvmat),
                QPATHTO_R(data\rvmat\c130j_body_destruct.rvmat),
                QPATHTO_R(data\rvmat\c130j_interior.rvmat),
                QPATHTO_R(data\rvmat\c130j_interior_damage.rvmat),
                QPATHTO_R(data\rvmat\c130j_interior_destruct.rvmat),
                QPATHTO_R(data\rvmat\c130j_wings.rvmat),
                QPATHTO_R(data\rvmat\c130j_wings_damage.rvmat),
                QPATHTO_R(data\rvmat\c130j_wings_destruct.rvmat),
                "a3\data_f\default.rvmat",
                "a3\data_f\default.rvmat",
                "a3\data_f\default_destruct.rvmat"
            };
        };
        class Exhausts {
            class Exhaust_right {
                position = "Exhaust1";
                direction = "Exhaust1_dir";
                effect = "ExhaustsEffectPlaneHP";
                engineIndex = 1;
            };
            class Exhaust_right2 : Exhaust_right {
                position = "Exhaust2";
                direction = "Exhaust2_dir";
            };
            class Exhaust_left : Exhaust_right {
                position = "Exhaust3";
                direction = "Exhaust3_dir";
                engineIndex = 0;
            };
            class Exhaust_left2 : Exhaust_left {
                position = "Exhaust4";
                direction = "Exhaust4_dir";
            };
        };
        class MarkerLights {
            class PositionRed {
                color[] = { 10, 0.0, 0.0 };
                ambient[] = { 0.01, 0.0, 0.0 };
                intensity = 30;
                name = "navigationlight red1";
                drawLight = 1;
                drawLightSize = 0.4;
                drawLightCenterSize = 0.1;
                activeLight = 1;
                blinking = 0;
                dayLight = 1;
                useFlare = 0;
            };
            class PositionRed2 : PositionRed {
                name = "navigationlight red2";
                activeLight = 1;
            };
            class PositionRed3 : PositionRed {
                name = "navigationlight red3";
                activeLight = 1;
            };
            class PositionGreen : PositionRed {
                color[] = { 0.0, 10, 0.0 };
                ambient[] = { 0.0, 0.01, 0.0 };
                name = "navigationlight green1";
                activeLight = 1;
            };
            class PositionWhite : PositionRed {
                color[] = { 10, 10, 10 };
                ambient[] = { 0.01, 0.01, 0.01 };
                name = "navigationlight white1";
                activeLight = 0;
            };
            class PositionWhite2 : PositionWhite {
                name = "navigationlight white2";
                activeLight = 0;
            };
            class CollisionWhite : PositionRed {
                color[] = { 50, 50, 50 };
                ambient[] = { 0.1, 0.1, 0.1 };
                name = "collisionstrobe1";
                activeLight = 1;
                useFlare = 1;
                blinking = 1;
                blinkingPattern[] = { 0.05, 0.95 };
                blinkingPatternGuarantee = 1;
                drawLightSize = 1;
                drawLightCenterSize = 0.1;
            };
            class CollisionWhite2 : CollisionWhite {
                name = "collisionstrobe2";
                activeLight = 2;
            };
        };
        class Reflectors {
            class Left {
                position = "L svetlo";
                direction = "konec L svetla";
                hitpoint = "L svetlo";
                selection = "L svetlo";
                color[] = { 10000, 10500, 14000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 100;
                size = 1;
                innerAngle = 10;
                outerAngle = 45;
                coneFadeCoef = 6;
                brightness = 1;
                useFlare = 1;
                flareSize = 6;
                flareMaxDistance = 600;
                dayLight = 0;
            };
            class Right {
                position = "P svetlo";
                direction = "konec P svetla";
                hitpoint = "P svetlo";
                selection = "P svetlo";
                color[] = { 10000, 10500, 14000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 100;
                size = 1;
                innerAngle = 10;
                outerAngle = 45;
                coneFadeCoef = 6;
                brightness = 1;
                useFlare = 1;
                flareSize = 6;
                flareMaxDistance = 600;
                dayLight = 0;
            };
            class Left2 {
                position = "L2 svetlo";
                direction = "konec L2 svetla";
                hitpoint = "L2 svetlo";
                selection = "L2 svetlo";
                color[] = { 10000, 10500, 14000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 100;
                size = 1;
                innerAngle = 10;
                outerAngle = 50;
                coneFadeCoef = 3;
                brightness = 1;
                useFlare = 1;
                flareSize = 6;
                flareMaxDistance = 600;
                dayLight = 0;
            };
            class Right2 {
                position = "P2 svetlo";
                direction = "konec P2 svetla";
                hitpoint = "P2 svetlo";
                selection = "P2 svetlo";
                color[] = { 10000, 10500, 14000, 1 };
                ambient[] = { 100, 100, 100, 0 };
                intensity = 100;
                size = 1;
                innerAngle = 10;
                outerAngle = 50;
                coneFadeCoef = 3;
                brightness = 1;
                useFlare = 1;
                flareSize = 6;
                flareMaxDistance = 600;
                dayLight = 0;
            };
            class Jump_Light_1_red {
                color[] = { 800, 100, 100 };
                ambient[] = { 8, 1, 1 };
                intensity = 1;
                size = 0.5;
                innerAngle = 60;
                outerAngle = 60;
                coneFadeCoef = 1;
                position = "jump_light_1_pos";
                direction = "jump_light_1_dir";
                hitpoint = "jump_light_1_red_hit";
                selection = "jump_light_1";
                useFlare = 0;
                class Attenuation {
                    start = 0.05;
                    constant = 0;
                    linear = 0;
                    quadratic = 500;
                    hardLimitStart = 0.1;
                    hardLimitEnd = 0.1;
                };
            };
            class Jump_Light_2_red : Jump_Light_1_red {
                position = "jump_light_2_pos";
                direction = "jump_light_2_dir";
                hitpoint = "jump_light_2_red_hit";
                selection = "jump_light_2";
            };
            class Jump_Light_1_green : Jump_Light_1_red {
                color[] = { 100, 800, 100 };
                ambient[] = { 1, 8, 1 };
                hitpoint = "jump_light_1_green_hit";
            };
            class Jump_Light_2_green : Jump_Light_1_green {
                position = "jump_light_2_pos";
                direction = "jump_light_2_dir";
                hitpoint = "jump_light_2_green_hit";
                selection = "jump_light_2";
            };
            class Jump_Light_3_red : Jump_Light_1_red {
                color[] = { 8000, 1000, 1000 };
                ambient[] = { 8, 1, 1 };
                intensity = 50;
                size = 1;
                innerAngle = 90;
                outerAngle = 160;
                coneFadeCoef = 5;
                position = "jump_light_3_pos";
                direction = "jump_light_3_dir";
                hitpoint = "jump_light_3_red_hit";
                selection = "jump_light_3";
                useFlare = 0;
                class Attenuation {
                    start = 0.5;
                    constant = 0;
                    linear = 0;
                    quadratic = 500;
                    hardLimitStart = 1;
                    hardLimitEnd = 3;
                };
            };
            class Jump_Light_3_green : Jump_Light_3_red {
                color[] = { 800, 8000, 800 };
                ambient[] = { 1, 8, 1 };
                hitpoint = "jump_light_3_green_hit";
            };
        };
        class camShakeGForce{
            power = 0.1;
            frequency = 3;
            distance = 0;
            minSpeed = 1;
        };
        class CamShake{
            power = 0.05;
            frequency = 20;
            distance = 3;
            minSpeed = 5;
        };
        class Wheels {
            class wheel_1_1 {
                boneName = "wheel_1_1";
                boundary = "wheel_1_1_rim";
                center = "wheel_1_1_center";
                side = "right";
                steering = 1;
                suspForceAppPointOffset = "wheel_1_1_center";
                tireForceAppPointOffset = "wheel_1_1_center";
                width = 0.5;
                mass = 230;
                MOI = 200;
                dampingRate = 0.1;
                dampingRateDamaged = 1;
                dampingRateDestroyed = 1000;
                maxBrakeTorque = 4000;
                maxHandBrakeTorque = 0;
                maxCompression = 0.2;
                maxDroop = 0;
                sprungMass = 1182;
                springStrength = 400000;
                springDamperRate = 20000;
                longitudinalStiffnessPerUnitGravity = 4000;
                latStiffX = 25;
                latStiffY = 180;
                suspTravelDirection[] = { 0, -1, 0 };
                frictionVsSlipGraph[] = { { 0, 1 }, { 0.5, 1 }, { 1, 1 } };
            };
            class wheel_2_1 : wheel_1_1 {
                boneName = "wheel_2_1";
                boundary = "wheel_2_1_rim";
                center = "wheel_2_1_center";
                suspForceAppPointOffset = "wheel_2_1_center";
                tireForceAppPointOffset = "wheel_2_1_center";
                side = "left";
                steering = 0;
                maxBrakeTorque = 8000;
                sprungMass = 8000;
                springStrength = 50000;
                springDamperRate = 10000;
                maxCompression = 0.1;
                maxDroop = 0;
            };
            class wheel_3_1 : wheel_2_1 {
                boneName = "wheel_3_1";
                boundary = "wheel_3_1_rim";
                center = "wheel_3_1_center";
                suspForceAppPointOffset = "wheel_3_1_center";
                tireForceAppPointOffset = "wheel_3_1_center";
            };
            class wheel_2_2 : wheel_2_1 {
                boneName = "wheel_2_2";
                boundary = "wheel_2_2_rim";
                center = "wheel_2_2_center";
                suspForceAppPointOffset = "wheel_2_2_center";
                tireForceAppPointOffset = "wheel_2_2_center";
                side = "right";
            };
            class wheel_3_2 : wheel_2_2 {
                boneName = "wheel_3_2";
                boundary = "wheel_3_2_rim";
                center = "wheel_3_2_center";
                suspForceAppPointOffset = "wheel_3_2_center";
                tireForceAppPointOffset = "wheel_3_2_center";
            };
        };
        class Components : Components {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                defaultDisplay = "EmptyDisplay";
                class Components {
                    class SensorsDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        resource = "RscCustomInfoSensors";
                    };
                    class CrewDisplay {
                        componentType = "CrewDisplayComponent";
                        resource = "RscCustomInfoCrew";
                    };
                    class MinimapDisplay {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
                    class EmptyDisplay {
                        componentType = "EmptyDisplayComponent";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
                defaultDisplay = "SensorsDisplay";
                class Components {
                    class SensorsDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        resource = "RscCustomInfoSensors";
                    };
                    class CrewDisplay {
                        componentType = "CrewDisplayComponent";
                        resource = "RscCustomInfoCrew";
                    };
                    class MinimapDisplay {
                        componentType = "MinimapDisplayComponent";
                        resource = "RscCustomInfoMiniMap";
                    };
                    class EmptyDisplay {
                        componentType = "EmptyDisplayComponent";
                    };
                };
            };
            class SensorsManagerComponent {
                class Components {
                    class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                    class DataLinkSensorComponent : SensorTemplateDataLink {};
                };
            };
        };
        driveOnComponent[] = {};
        numberPhysicalWheels = 5;
        maxOmega = 2000;
        delete CarrierOpsCompatability;
        CatapultExclude = 1;
        LESH_canBeTowed = 0;
        LESH_towFromFront = 1;
        LESH_AxisOffsetTarget[] = { 0, 15.95, 0.4 };
        LESH_WheelOffset[] = { 0, -1 };
        EGVAR(common,towbarOffset)[] = { 0, 11.5, 0.37 };
        EGVAR(common,towbarActionMemoryPoint) = "wheel_1_1";
        uksf_radios_rackChannels[] = { 31, 40, 41 };
#include "MFD.hpp"
    };
    class GVAR(raf) : GVAR(base) {
        scope = 2;
        scopeCurator = 2;
        crew = "UKSF_B_Pilot_617";
        typicalCargo[] = { "UKSF_B_Pilot_617" };
    };
    class GVAR(raf_cargo) : GVAR(raf) {
        displayname = "C-130J (Cargo)";
        transportSoldier = 0;
        class AnimationSources : AnimationSources {
            class cargo_hide_now : cargo_hide_now {
                initPhase = 1;
            };
        };
        class VehicleTransport {
            class Carrier {
                cargoBayDimensions[] = { "VIV_point_1", "VIV_point_2" };
                disableHeightLimit = 0;
                maxLoadMass = 35900;
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
    };
};
