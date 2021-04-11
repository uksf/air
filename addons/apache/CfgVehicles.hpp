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
class CfgNonAIVehicles {
    class ProxyWeapon;
    class ProxyPylonRocket_19Rnd_CRV7_HEISAP : ProxyWeapon {
        model = QPATHTOF(PylonRocket_19Rnd_CRV7_HEISAP.p3d);
        simulation = "pylonpod";
    };
    class ProxyPylonPod_4x_Missile_LG_scalpel_F : ProxyWeapon {
        model = "\A3\Weapons_F\DynamicLoadout\PylonPod_4x_Missile_LG_scalpel_F.p3d";
        simulation = "pylonpod";
    };
};
class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F : Helicopter {
        class Turrets;
        class AnimationSources;
        class HitPoints;
    };
    class Heli_Attack_01_base_F : Helicopter_Base_F {
        class Turrets : Turrets {
            class MainTurret;
        };
        class AnimationSources : AnimationSources {
            class Gatling;
            class Muzzle_flash;
        };
        class HitPoints : HitPoints {
            class HitHull;
            class HitAvionics;
            class HitVRotor;
            class HitHRotor;
            class HitEngine;
            class HitEngine1;
            class HitEngine2;
            class HitMissiles;
            class HitGlass1;
            class HitGlass2;
            class HitGlass3;
            class HitGlass4;
            class HitGlass5;
            class HitGlass6;
            class HitGear;
            class HitFuel;
        };
        class CargoTurret;
        class Eventhandlers;
        class ViewOptics;
        class ViewPilot;
        class RotorLibHelicopterProperties;
        class WeaponCloudsMGun;
        class Sounds;
        class Components;
    };
    class GVAR(base) : Heli_Attack_01_base_F {
        scope = 1;
        author = "UKSF";
        displayName = "AH-64D Apache Base";
        model = QPATHTOF(AH_BAF.p3d);
        picture = QPATHTOF(data\ui\Picture_ah64d_CA.paa);
        icon = QPATHTOF(data\ui\Icon_ah64d_CA.paa);
        availableForSupportTypes[] = { "CAS_Heli" };
        armor = 150;
        fuelCapacity = 200;  // 300
        startDuration = 70;
        explosionShielding = 2;
        epeImpulseDamageCoef = 5;
        crewCrashProtection = 0.5;
        enableManualFire = 1;
        copilotHasFlares = 1;
        memoryPointLMissile = "missile_1";
        memoryPointRMissile = "missile_2";
        memoryPointLRocket = "Rocket_1";
        memoryPointRRocket = "Rocket_2";
        memoryPointCM[] = { "flare_launcher1", "flare_launcher2" };
        memoryPointCMDir[] = { "flare_launcher1_dir", "flare_launcher2_dir" };
        radarType = 4;
        lockDetectionSystem = "1 + 2 + 4 + 8";
        showAllTargets = 0;
        destrType = "DestructWreck";
        crew = "UKSF_B_Pilot_656";
        typicalCargo[] = { "UKSF_B_Pilot_656", "UKSF_B_Pilot_656" };
        gunnerCanSee = "1 + 2 + 4 + 8 + 16";
        driverCanSee = "1 + 2 + 4 + 8 + 16";
        driverAction = "AH64_Pilot_EP1";
        driverRightHandAnimName = "stick";
        driverLeftHandAnimName = "lever";
        driverLeftLegAnimName = "pedalL";
        driverRightLegAnimName = "pedalR";
        driverCanEject = 1;
        getInAction = "pilot_Heli_Light_02_Enter";
        getOutAction = "pilot_Heli_Light_02_Exit";
        maximumLoad = 2000;
        cyclicAsideForceCoef = 2; // 1.75 // 1.06
        cyclicForwardForceCoef = 1.6; // 1.5 // 1
        backRotorForceCoef = 1.8;
        backRotorSpeed = 3.0;
        gearRetracting = 0;
        maxSpeed = 293;
        liftForceCoef = 1.8;
        selectionHRotorStill = "velka vrtule staticka";
        selectionHRotorMove = "velka vrtule blur";
        selectionVRotorStill = "mala vrtule staticka";
        selectionVRotorMove = "mala vrtule blur";
        mainBladeCenter = "rotor_center";
        mainBladeRadius = 6.8;
        tailBladeCenter = "rotor_02_center";
        tailBladeRadius = 1.6;
        driveOnComponent[] = { "wheel_1_1", "wheel_2_1", "wheel_12_2" };
        soundgetin[] = { QPATHTOF(data\sounds\close.ogg),1,1 };
        soundgetout[] = { QPATHTOF(data\sounds\open.ogg),1,1,40 };
        weapons[] = { "CUP_weapon_mastersafe", "CMFlareLauncher" };
        magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
        hiddenSelections[] = { "camo1", "id1", "id2", "id3", "decals" };
        dammageHalf[] = { QPATHTOF(data\AH64D_mfd_normal_co.paa),QPATHTOF(data\AH64D_mfd_malfc_co.paa) };
        dammageFull[] = { QPATHTOF(data\AH64D_mfd_normal_co.paa),QPATHTOF(data\AH64D_mfd_malfc_co.paa) };
        unitInfoType = "RscUnitInfoNoSpeed";
        unitInfoTypeLite = "RscUnitInfoNoSpeed";
        class RenderTargets {};
        class RotorLibHelicopterProperties : RotorLibHelicopterProperties {
            rtd_center = "rtd_center";
            RTDconfig = QPATHTOF(RTD_AH_BAF_attack_01.xml);
        };
        class Reflectors {
            class Middle {
                color[] = { 7000, 7500, 10000 };
                ambient[] = { 70, 75, 100 };
                intensity = 200;
                size = 1;
                innerAngle = 20;
                outerAngle = 75;
                coneFadeCoef = 10;
                position = "L svetlo";
                direction = "konec L svetla";
                hitpoint = "L svetlo";
                selection = "L svetlo";
                useFlare = 1;
                dayLight = 1;
                flareSize = 6;
                class Attenuation {
                    start = 1;
                    constant = 0;
                    linear = 0;
                    quadratic = 4;
                };
            };
            class Middle_LensBloom : Middle {
                innerAngle = 170;
                outerAngle = 180;
                flareSize = 0.1;
                class Attenuation : Attenuation {
                    start = 0;
                    hardLimitStart = 0.05;
                    hardLimitEnd = 0.1;
                };
            };
        };
        class HitPoints : HitPoints {
            class HitHull : HitHull {
                name = "NEtrup";
                convexComponent = "NEtrup";
                visual = "trup";
                armor = 4;
                radius = 0.3;
            };
            class HitAvionics : HitAvionics {
                name = "elektronika";
                convexComponent = "elektronika";
                visual = "elektronika";
                armor = 3;
                radius = 0.3;
            };
            class HitMissiles : HitMissiles {
                name = "munice";
                convexComponent = "munice";
                visual = "munice";
                armor = 2;
                radius = 0.3;
            };
            class HitEngine1 : HitEngine1 {
                name = "motor_1";
                convexComponent = "motor_1";
                visual = "motor_1";
                minimalHit = 0.09;
                armor = 2;
                radius = 0.3;
                explosionShielding = 4;
            };
            class HitEngine2 : HitEngine2 {
                name = "motor_2";
                convexComponent = "motor_2";
                visual = "motor_2";
                minimalHit = 0.09;
                armor = 2;
                radius = 0.3;
                explosionShielding = 4;
            };
            class HitEngine : HitEngine {
                name = "";
                convexComponent = "";
                minimalHit = 0.09;
                armor = 2;
                radius = 0.3;
                explosionShielding = 4;
            };
            class HitHRotor : HitHRotor {
                name = "velka vrtule";
                convexComponent = "velka vrtule";
                visual = "velka vrtule staticka";
                armor = 5;
                radius = 0.1;
                minimalHit = 0.09;
                explosionShielding = 2.5;
            };
            class HitVRotor : HitVRotor {
                name = "mala vrtule";
                convexComponent = "mala vrtule";
                visual = "mala vrtule staticka";
                armor = 6;
                radius = 0.06;
                minimalHit = 0.05;
                explosionShielding = 6;
            };
            class HitGear : HitGear {
                name = "gear";
                radius = 0.3;
            };
            class HitFuel : HitFuel {
                name = "fuel";
                armor = 1;
                radius = 0.25;
            };
            class HitGlass1 : HitGlass1 {
                radius = 0.25;
                armor = 0.5;
            };
            class HitGlass2 : HitGlass2 {
                radius = 0.25;
                armor = 0.5;
            };
            class HitGlass3 : HitGlass3 {
                radius = 0.3;
                armor = 0.5;
            };
            class HitGlass4 : HitGlass4 {
                radius = 0.3;
                armor = 0.5;
            };
            class HitGlass5 : HitGlass5 {
                radius = 0.4;
                armor = 3;
            };
            class HitGlass6 : HitGlass6 {
                radius = 0.4;
                armor = 3;
            };
        };
        class AnimationSources : AnimationSources {
            class Muzzle_flash : Muzzle_flash {
                weapon = "CUP_Vacannon_M230_veh";
            };
        };
        class Damage {
            tex[] = {};
            mat[] = {
                QPATHTO_R(data\AH64D_body.rvmat),
                QPATHTO_R(data\AH64D_body_damage.rvmat),
                QPATHTO_R(data\AH64D_body_destruct.rvmat),
                QPATHTO_R(data\AH64D_details.rvmat),
                QPATHTO_R(data\AH64D_details_damage.rvmat),
                QPATHTO_R(data\AH64D_details_destruct.rvmat),
                QPATHTO_R(data\AH64D_inter.rvmat),
                QPATHTO_R(data\AH64D_inter_damage.rvmat),
                QPATHTO_R(data\AH64D_inter_destruct.rvmat),
                QPATHTO_R(data\AH64D_glass.rvmat),
                QPATHTO_R(data\AH64D_glass_damage.rvmat),
                QPATHTO_R(data\AH64D_glass_damage.rvmat),
                QPATHTO_R(data\AH64D_glass_in.rvmat),
                QPATHTO_R(data\AH64D_glass_in_damage.rvmat),
                QPATHTO_R(data\AH64D_glass_in_damage.rvmat),
                QPATHTO_R(data\NumberDecal.rvmat),
                QPATHTO_R(data\NumberDecal.rvmat),
                QPATHTO_R(data\NumberDecal_destruct.rvmat),
                QPATHTO_R(data\default.rvmat),
                QPATHTO_R(data\default.rvmat),
                QPATHTO_R(data\default_destruct.rvmat)
            };
        };
        class ViewPilot : ViewPilot {
            initAngleX = 0;
            minAngleX = -60;
            maxAngleX = +60;
            initAngleY = 0;
            minAngleY = -120;
            maxAngleY = +120;
            initFov = 0.75;
            minFov = 0.25;
            maxFov = 1.25;
            speedZoomMaxSpeed = 0;
            speedZoomMaxFOV = 0.75;
            visionMode[] = { "Normal", "NVG" };
            gunnerOpticsModel = "";
            gunnerOpticsEffect[] = {};
        };
        class ViewOptics : ViewOptics {
            initFov = 0.75;
            minFov = 0.25;
            maxFov = 1.25;
            visionMode[] = { "Normal", "NVG" };
            gunnerOpticsModel = "";
            gunnerOpticsEffect[] = {};
        };
        class Sounds : Sounds {
            class RotorExt {
                sound[] = { QPATHTOF(data\sounds\ah64_rotor_ext),1.4,1,1000 };
                frequency = "(rotorSpeed factor [0.3, 0.7]) * (rotorSpeed factor [0.3, 1]) * (1 - rotorThrust/4)";
                volume = "camPos * (rotorSpeed factor [0.3, 1]) * (1 + rotorThrust)";
            };
            class RotorInt {
                sound[] = { QPATHTOF(data\sounds\ah64_rotor_int),0.7,1 };
                frequency = "(rotorSpeed factor [0.3, 0.7]) * (rotorSpeed factor [0.3, 1]) * (1 - rotorThrust/4)";
                volume = "(1 - camPos) * (rotorSpeed factor [0.3, 0.7]) * (1 + rotorThrust) * 0.7";
            };
            class RotorSwist {
                sound[] = { QPATHTOF(data\sounds\ah64_trotor_ext),1,1,500 };
                frequency = 1;
                volume = 0;
                cone[] = { 0.7, 1.3, 1, 0 };
            };
        };
        class SoundsExt {
            class Sounds {
                class RotorExt {
                    sound[] = { QPATHTOF(data\sounds\ah64_rotor_ext),1.4,1,1000 };
                    frequency = "(rotorSpeed factor [0.3, 0.7]) * (rotorSpeed factor [0.3, 1]) * (1 - rotorThrust/4)";
                    volume = "camPos * (rotorSpeed factor [0.3, 1]) * (1 + rotorThrust)";
                };
                class RotorInt {
                    sound[] = { QPATHTOF(data\sounds\ah64_rotor_int),0.7,1 };
                    frequency = "(rotorSpeed factor [0.3, 0.7]) * (rotorSpeed factor [0.3, 1]) * (1 - rotorThrust/4)";
                    volume = "(1 - camPos) * (rotorSpeed factor [0.3, 0.7]) * (1 + rotorThrust) * 0.7";
                };
                class RotorSwist {
                    sound[] = { QPATHTOF(data\sounds\ah64_trotor_ext),0,1,0 };
                    frequency = 1;
                    volume = 0;
                    cone[] = { 0.7, 1.3, 1, 0 };
                };
            };
        };
        class MarkerLights {
            class PositionRed {
                color[] = { 0.8, 0, 0 };
                ambient[] = { 0.08, 0, 0 };
                intensity = 75;
                name = "cerveny pozicni";
                drawLight = 1;
                drawLightSize = 0.15;
                drawLightCenterSize = 0.04;
                activeLight = 0;
                blinking = 0;
                dayLight = 1;
                useFlare = 0;
                class Attenuation {
                    start = 0;
                    constant = 0;
                    linear = 25;
                    quadratic = 50;
                    hardLimitStart = 0.75;
                    hardLimitEnd = 1;
                };
            };
            class PositionGreen : PositionRed {
                color[] = { 0, 0.8, 0 };
                ambient[] = { 0, 0.08, 0 };
                name = "zeleny pozicni";
            };
            class PositionWhite : PositionRed {
                color[] = { 1, 1, 1 };
                ambient[] = { 0.1, 0.1, 0.1 };
                name = "bily pozicni";
            };
            class CollisionWhite : PositionRed {
                color[] = { 1, 1, 1 };
                ambient[] = { 0.1, 0.1, 0.1 };
                intensity = 10000;
                name = "Strobe_left";
                drawLightSize = 0.2;
                drawLightCenterSize = 0.08;
                blinking = 1;
                blinkingPattern[] = { 0.1, 2.1 };
                blinkingPatternGuarantee = 0;
            };
            class CollisionRed : CollisionWhite {
                name = "Strobe_right";
                blinkingPattern[] = { 0.1, 1.9 };
            };
        };
        class UserActions {
            class jammerSemi {
                displayName = "<t color = '#217cd1'>CM Semi-Auto</t>";
                position = "zamerny";
                radius = 10;
                priority = 4;
                onlyForPlayer = 0;
                hideOnUse = 0;
                condition = QUOTE((player isEqualTo(driver this) || player isEqualTo(gunner this)) && { (this getVariable[ARR_2(QQGVAR(cmMode),0)]) != 1 });
                statement = QUOTE(this setVariable[ARR_3(QQGVAR(cmMode),1,true)]);
            };
            class jammerAuto {
                displayName = "<t color = '#217cd1'>CM Auto</t>";
                position = "zamerny";
                radius = 10;
                priority = 4;
                onlyForPlayer = 0;
                hideOnUse = 0;
                condition = QUOTE((player isEqualTo(driver this) || player isEqualTo(gunner this)) && { (this getVariable[ARR_2(QQGVAR(cmMode),0)]) != 2 });
                statement = QUOTE(this setVariable[ARR_3(QQGVAR(cmMode),2,true)]);
            };
            class jammerOff {
                displayName = "<t color = '#217cd1'>CM Man</t>";
                position = "zamerny";
                radius = 10;
                priority = 4;
                onlyForPlayer = 0;
                hideOnUse = 0;
                condition = QUOTE((player isEqualTo(driver this) || player isEqualTo(gunner this)) && { (this getVariable[ARR_2(QQGVAR(cmMode),0)]) != 0 });
                statement = QUOTE(this setVariable[ARR_3(QQGVAR(cmMode),0,true)]);
            };
        };
        class Turrets : Turrets {
            class MainTurret : MainTurret {
                #include "MFDGunner.hpp"
                turretInfoType = "RscOptics_GENERAL_FLIR";
                discretedistance[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000 };
                discretedistanceinitindex = 4;
                initElev = 0;
                minElev = -60;
                maxElev = 11;
                initTurn = 0;
                minTurn = -110;
                maxTurn = 110;
                weapons[] = { "Laserdesignator_mounted", "CUP_Vacannon_M230_veh" };
                magazines[] = { "Laserbatteries", "CUP_1200Rnd_TE1_Red_Tracer_30x113mm_M789_HEDP_M" };
                gunnerAction = "AH64_gunner_EP1";
                gunnerGetInAction = "pilot_Heli_Light_02_Enter";
                gunnerGetOutAction = "pilot_Heli_Light_02_Exit";
                memoryPointGunnerOptics = "gunnerview";
                class OpticsIn {
                    class WideNGS {
                        opticsDisplayName = "WNGS";
                        initAngleX = 0;
                        minAngleX = -60;
                        maxAngleX = 30;
                        initAngleY = 0;
                        minAngleY = -120;
                        maxAngleY = 120;
                        initFov = 0.466;
                        minFov = 0.466;
                        maxFov = 0.466;
                        visionMode[] = { "Normal", "NVG", "Ti" };
                        thermalMode[] = { 0, 1 };
                        gunnerOpticsColor[] = { 0, 0, 0, 1 };
                        gunnerOpticsEffect[] = { "TankCommanderOptics1" };
                        gunnerOpticsModel = "CUP\AirVehicles\CUP_AirVehicles_AH64\gunnerOptics_ah64.p3d";
                        opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
                        directionStabilized = 0;
                    };
                    class Wide : WideNGS {
                        opticsDisplayName = "W";
                        initFov = 0.466;
                        minFov = 0.466;
                        maxFov = 0.466;
                        gunnerOpticsModel = "CUP\AirVehicles\CUP_AirVehicles_AH64\gunnerOptics_ah64.p3d";
                        directionStabilized = 1;
                        horizontallyStabilized = 1;
                        stabilizedInAxes = 3;
                    };
                    class WideL : Wide {
                        opticsDisplayName = "WL";
                        initFov = 0.094;
                        minFov = 0.094;
                        maxFov = 0.094;
                        gunnerOpticsModel = "CUP\AirVehicles\CUP_AirVehicles_AH64\gunnerOptics_ah64.p3d";
                    };
                    class Medium : Wide {
                        opticsDisplayName = "M";
                        initFov = 0.019;
                        minFov = 0.019;
                        maxFov = 0.019;
                        gunnerOpticsModel = "CUP\AirVehicles\CUP_AirVehicles_AH64\gunnerOptics_ah64.p3d";
                    };
                    class Narrow : Wide {
                        opticsDisplayName = "N";
                        initFov = 0.006;
                        minFov = 0.006;
                        maxFov = 0.006;
                        gunnerOpticsModel = "CUP\AirVehicles\CUP_AirVehicles_AH64\gunnerOptics_ah64.p3d";
                    };
                };
                class OpticsOut {
                    class Monocular {
                        initAngleX = 0;
                        minAngleX = -60;
                        maxAngleX = 60;
                        initAngleY = 0;
                        minAngleY = -120;
                        maxAngleY = 120;
                        initFov = 0.75;
                        minFov = 0.25;
                        maxFov = 1.25;
                        visionMode[] = { "Normal", "NVG" };
                        gunnerOpticsModel = "";
                        gunnerOpticsEffect[] = {};
                        directionStabilized = 0;
                    };
                };
                class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                    defaultDisplay = "EmptyDisplay";
                    class Components {
                        class MissileDisplay {
                            componentType = "TransportFeedDisplayComponent";
                            source = "Missile";
                        };
                        class VehicleDriverDisplay {
                            componentType = "TransportFeedDisplayComponent";
                            source = "Driver";
                        };
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
                        class MissileDisplay {
                            componentType = "TransportFeedDisplayComponent";
                            source = "Missile";
                        };
                        class VehicleDriverDisplay {
                            componentType = "TransportFeedDisplayComponent";
                            source = "Driver";
                        };
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
            };
            class CargoTurret_01 : CargoTurret {
                gunnerAction = "passenger_bench_1";
                gunnerCompartments = "";
                memoryPointsGetInGunner = "pos cargo right";
                memoryPointsGetInGunnerDir = "pos cargo dir right";
                gunnerName = "Passenger (Right Jumpseat)";
                proxyIndex = 1;
                initElev = 0;
                minElev = -50;
                maxElev = +15;
                initTurn = 0;
                minTurn = 30;
                maxTurn = -30;
                isPersonTurret = 0;
                ejectDeadGunner = 0;
                enabledByAnimationSource = "";
                usepip = 0;
                gunnerOutOpticsModel = "";
                gunnerOpticsModel = "";
                memoryPointGunnerOptics = "";
                startEngine = 0;
                outGunnerMayFire = 0;
                inGunnerMayFire = 0;
                commanding = -2;
                selectionFireAnim = "";
            };
            class CargoTurret_02 : CargoTurret_01 {
                memoryPointsGetInGunner = "pos cargo left";
                memoryPointsGetInGunnerDir = "pos cargo dir left";
                gunnerName = "Passenger (Left Jumpseat)";
                proxyIndex = 2;
                initElev = 0;
                minElev = -50;
                maxElev = +15;
                initTurn = 0;
                minTurn = -30;
                maxTurn = 30;
            };
        };
        class Components : Components {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                defaultDisplay = "EmptyDisplay";
                class Components {
                    class MissileDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Missile";
                    };
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
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
                    class MissileDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "Missile";
                    };
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
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
                    class ActiveRadarComponent : SensorTemplateActiveRadar {
                        class AirTarget {
                            maxRange = 8000;
                            minRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        class GroundTarget {
                            maxRange = 8000;
                            minRange = 8000;
                            objectDistanceLimitCoef = -1;
                            viewDistanceLimitCoef = -1;
                        };
                        typeRecognitionDistance = 8000;
                        angleRangeHorizontal = 360;
                        aimDown = 30;
                        maxGroundNoiseDistance = -1;
                        groundNoiseDistanceCoef = -1;
                        minSpeedThreshold = 0;
                        maxSpeedThreshold = 24;
                    };
                    class IRSensorComponent : SensorTemplateIR {
                        class AirTarget {
                            maxRange = 8000;
                            minRange = 50;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 8000;
                            minRange = 50;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        aimDown = 30;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 60;
                        angleRangeVertical = 60;
                        maxTrackableSpeed = 110;
                    };
                    class VisualSensorComponent : SensorTemplateVisual {
                        class AirTarget {
                            maxRange = 8000;
                            minRange = 50;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 8000;
                            minRange = 50;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        aimDown = 30;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 60;
                        angleRangeVertical = 60;
                        maxTrackableSpeed = 110;
                    };
                    class NVSensorComponent : SensorTemplateNV {
                        class AirTarget {
                            maxRange = 2000;
                            minRange = 50;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 2000;
                            minRange = 50;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        aimDown = 30;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 60;
                        angleRangeVertical = 60;
                        maxTrackableSpeed = 110;
                    };
                    class LaserSensorComponent : SensorTemplateLaser {
                        class AirTarget {
                            maxRange = 8000;
                            minRange = 500;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        class GroundTarget {
                            maxRange = 8000;
                            minRange = 500;
                            objectDistanceLimitCoef = 1;
                            viewDistanceLimitCoef = 1;
                        };
                        aimDown = 30;
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 180;
                        angleRangeVertical = 180;
                        maxTrackableSpeed = 110;
                    };
                    class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                    class DataLinkSensorComponent : SensorTemplateDataLink {};
                };
            };
            class TransportPylonsComponent {
                uiPicture = QPATHTOF(data\ui\Apache_EDEN_CA.paa);
                class Pylons {
                    class PylonLeft1 {
                        attachment = "CUP_PylonPod_19Rnd_CRV7_HE_M";
                        priority = 5;
                        bay = -1;
                        hardpoints[] = { "B_CRV7", "B_HELLFIRE", "B_STARSTREAK" };
                        UIposition[] = { 0.13, 0.3 };
                        turret[] = { 0 };
                    };
                    class PylonLeft2 : PylonLeft1 {
                        attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114N";
                        priority = 4;
                        hardpoints[] = { "B_CRV7", "B_HELLFIRE", "B_STARSTREAK" };
                        UIposition[] = { 0.19, 0.35 };
                    };
                    class PylonRight2 : PylonLeft2 {
                        attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114L";
                        mirroredMissilePos = 2;
                        UIposition[] = { 0.43, 0.35 };
                    };
                    class PylonRight1 : PylonLeft1 {
                        mirroredMissilePos = 1;
                        UIposition[] = { 0.50, 0.3 };
                    };
                };
                class Presets {
                    class Empty {
                        displayName = "Empty";
                        attachment[] = {};
                    };
                    class Default {
                        displayName = "CAS";
                        attachment[] = { "CUP_PylonPod_19Rnd_CRV7_FAT_M", "PylonRack_4Rnd_ACE_Hellfire_AGM114N", "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "CUP_PylonPod_19Rnd_CRV7_HE_M" };
                    };
                    class AT {
                        displayName = "AT";
                        attachment[] = { "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114L" };
                    };
                    class Escort {
                        displayName = "Escort";
                        attachment[] = { "CUP_PylonPod_19Rnd_CRV7_FAT_M", "CUP_PylonPod_19Rnd_CRV7_HE_M", "CUP_PylonPod_19Rnd_CRV7_HE_M", "CUP_PylonPod_19Rnd_CRV7_FAT_M" };
                    };
                    class Strike {
                        displayName = "Strike";
                        attachment[] = { "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114N", "PylonRack_4Rnd_ACE_Hellfire_AGM114K", "PylonRack_4Rnd_ACE_Hellfire_AGM114L" };
                    };
                };
            };
        };
        ace_cookoff_cookoffSelections[] = { "zamerny" };
        EGVAR(radios,rackChannels)[] = { 41, 40, 31, 32 };
        // TODO
        // LESH_canBeTowed = 0;
        // LESH_towFromFront = 1;
        // LESH_AxisOffsetTarget[] = { 0, 15.95, 0.4 };
        // LESH_WheelOffset[] = { 0, -1 };
        // EGVAR(common,towbarOffset)[] = { 0, 11.5, 0.37 };
        // EGVAR(common,towbarActionMemoryPoint) = "wheel_1_1";
        INVENTORY_AIRCRAFT;
        #include "MFDPilot.hpp"
    };
    class GVAR(aac) : GVAR(base) {
        scope = 2;
        scopeCurator = 2;
        side = 1;
        faction = "CUP_B_GB";
        displayName = "Apache AH1";
        PREVIEW(GVAR(aac));
        hiddenSelectionsTextures[] = { QPATHTOF(data\ah1_baf_body_co.paa),"","","",QPATHTOF(data\decals_ca.paa) };
        class TransportBackpacks {};
    };
};
