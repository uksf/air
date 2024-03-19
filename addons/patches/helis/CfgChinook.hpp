class CUP_CH47F_base : Helicopter_Base_H {
    cyclicAsideForceCoef = 2; // 1.7
    cyclicForwardForceCoef = 1.8; // 1.7
    FUEL(3914,100);
    armor = 60;
    startDuration = 90;
    maximumLoad = 2500;
    memoryPointsGetInDriver = "pos cargo";
    memoryPointsGetInDriverDir = "pos cargo dir";
    driverCanEject = 1;
    weapons[] = { "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
    attenuationEffectType = "SemiOpenHeliAttenuation";
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    class ViewPilot : ViewPilot {
        minFov = 0.25;
        maxFov = 1.25;
        initFov = 0.95;
        initAngleX = 0;
        minAngleX = -65;
        maxAngleX = 85;
        initAngleY = 0;
        minAngleY = -150;
        maxAngleY = 150;
        minMoveX = -0.3;
        maxMoveX = 0.3;
        minMoveY = -0.025;
        maxMoveY = 0.05;
        minMoveZ = -0.2;
        maxMoveZ = 0.2;
        speedZoomMaxSpeed = 0;
        speedZoomMaxFOV = 0.95;
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            gunnerName = "Crew Chief";
            primaryGunner = 0;
            soundAttenuationTurret = "HeliAttenuationGunner";
        };
        class RightDoorGun : MainTurret {
            soundAttenuationTurret = "HeliAttenuationGunner";
        };
        class BackDoorGun : MainTurret {
            soundAttenuationTurret = "HeliAttenuationGunner";
        };
        class CopilotTurret : CopilotTurret {
            primaryGunner = 1;
            memoryPointsGetInGunner = "pos cargo";
            memoryPointsGetInGunnerDir = "pos cargo dir";
            CanEject = 1;
            showHMD = 1;
            class Components {
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
            };
        };
    };
    class Sounds {
        class Engine {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_engine_high_ext", 1, 1.0, 1000 };
            frequency = "rotorSpeed";
            volume = "camPos*((rotorSpeed-0.15)*2)";
        };
        class RotorLowOut {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_ext", 2, 1.0, 2000 };
            frequency = "rotorSpeed";
            volume = "camPos*2*(0 max (rotorSpeed-0.5))";
            cone[] = { 1.8, 3.14, 2.0, 0.9 };
        };
        class RotorHighOut {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_forsage_ext", 2, 1.0, 2500 };
            frequency = "rotorSpeed";
            volume = "camPos*15*(0 max (rotorThrust-0.95))";
            cone[] = { 1.8, 3.14, 2.0, 0.9 };
        };
        class EngineIn {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_engine_high_int", 1, 1.0 };
            frequency = "rotorSpeed";
            volume = "(1-camPos)*((rotorSpeed-0.2)*2)";
        };
        class RotorLowIn {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_int", 1, 1.0 };
            frequency = "rotorSpeed";
            volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))";
        };
        class RotorHighIn {
            sound[] = { "CUP\AirVehicles\CUP_AirVehicles_CH47\sounds\CH47_rotor_forsage_int", 1, 1.0 };
            frequency = "rotorSpeed";
            volume = "(1-camPos)*3*(rotorThrust-0.9)";
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
    class MarkerLights {
        class WhiteStill {
            name = "pos_light_still_white";
            color[] = {1, 1, 1};
            ambient[] = {0.1, 0.1, 0.1};
            intensity = 75;
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
        class RedStill {
            name = "pos_light_still_red";
            color[] = {0.8, 0, 0};
            ambient[] = {0.08, 0, 0};
            intensity = 75;
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
        class GreenStill {
            name = "pos_light_still_green";
            color[] = {0, 0.8, 0};
            ambient[] = {0, 0.08, 0};
            intensity = 75;
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
        class RedBlinking {
            name = "pos_light_blink_red";
            color[] = {0.9, 0.15, 0.1};
            ambient[] = {0.09, 0.015, 0.01};
            intensity = 10000;
            drawLightSize = 0.2;
            drawLightCenterSize = 0.04;
            activeLight = 0;
            blinking = 1;
            blinkingStartsOn = 0;
            blinkingPattern[] = {0.9, 0.1};
            blinkingPatternGuarantee = 0;
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
        class WhiteBlinking {
            name = "pos_light_blink_white";
            color[] = {1, 1, 1};
            ambient[] = {0.1, 0.1, 0.1};
            intensity = 10000;
            drawLightSize = 0.25;
            drawLightCenterSize = 0.08;
            activeLight = 0;
            blinking = 1;
            blinkingPattern[] = {0.1, 0.9};
            blinkingPatternGuarantee = 0;
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
    };
    class AnimationSources;
    ace_cookoff_cookoffSelections[] = { "exhaust_1" };
    UGVAR(radios,rackChannels)[] = { 31, 40, 41 };
    LESH_canBeTowed = 0;
    LESH_towFromFront = 0;
    LESH_AxisOffsetTarget[] = { 1.6, -9.14, -3.14 };
    LESH_WheelOffset[] = { 1.6, -1 };
    EGVAR(common,towbarOffset)[] = { 1.6, -0.6, -0.19 };
    EGVAR(common,towbarRotation)[] = { 0, -1, 0.036 };
    EGVAR(common,towbarActionMemoryPoint) = "doplnovani";
    #include "..\hmds\MFDGeneral.hpp"
};
class CUP_B_CH47F_GB : CUP_CH47F_base {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction = "CUP_B_GB";
    displayName = "Chinook HC-4";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7", "UKSF_B_Pilot_7", "UKSF_B_Pilot_7" };
    hiddenSelectionsTextures[] = { "cup\airvehicles\cup_airvehicles_ch47\data\ch47_ext_1_baf_co.paa", "cup\airvehicles\cup_airvehicles_ch47\data\ch47_ext_2_baf_co.paa", "", "cup\airvehicles\cup_airvehicles_ch47\data\ch47_ext_mlod_co.paa" };
    class TextureSources {};
    editorPreview = "CUP\AirVehicles\CUP_AirVehicles_CH47\Data\preview\CUP_B_CH47F_GB.jpg";
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            gunnerName = "Crew Chief";
            body = "mainTurret";
            gun = "mainGun";
            minElev = -50;
            maxElev = 30;
            initElev = -30;
            minTurn = -3;
            maxTurn = 173;
            initTurn = 0;
            soundServo[] = { "db-40", 1.0 };
            animationSourceHatch = "";
            stabilizedInAxes = 0;
            gunBeg = "muzzle_1";
            gunEnd = "chamber_1";
            weapons[] = { "CUP_M134" };
            magazines[] = { "CUP_2000Rnd_TE1_Red_Tracer_762x51_M134_M" };
            gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
            gunnerOutOpticsShowCursor = 1;
            gunnerOpticsShowCursor = 1;
            gunnerAction = "CUP_CH47_Gunner";
            gunnerInAction = "CUP_CH47_Gunner";
            commanding = -2;
            primaryGunner = 0;
            class ViewOptics {
                initAngleX = 0;
                minAngleX = -30;
                maxAngleX = 30;
                initAngleY = 0;
                minAngleY = -100;
                maxAngleY = 100;
                initFov = 0.7;
                minFov = 0.25;
                maxFov = 1.1;
            };
            gunnerCompartments = "Compartment2";
            memoryPointsGetInGunner = "pos gunner";
            memoryPointsGetInGunnerDir = "pos gunner dir";
            isCopilot = 0;
            selectionFireAnim = "zasleh";
            slingLoadOperator = 0;
        };
        class RightDoorGun : MainTurret {
            body = "Turret2";
            gun = "Gun_2";
            minElev = -60;
            maxElev = 30;
            initElev = -30;
            minTurn = -173;
            maxTurn = 3;
            initTurn = 0;
            animationSourceBody = "Turret_2";
            animationSourceGun = "Gun_2";
            stabilizedInAxes = 0;
            selectionFireAnim = "zasleh_1";
            proxyIndex = 2;
            weapons[] = { "CUP_M134_2" };
            magazines[] = { "CUP_2000Rnd_TE1_Red_Tracer_762x51_M134_M" };
            gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
            gunnerOutOpticsShowCursor = 1;
            gunnerOpticsShowCursor = 1;
            gunnerName = "$STR_A3_RIGHT_GUNNER";
            commanding = -2;
            gunBeg = "muzzle_2";
            gunEnd = "chamber_2";
            primaryGunner = 0;
            preciseGetInOut = 1;
            memoryPointGun = "machinegun_2";
            memoryPointGunnerOptics = "gunnerview_2";
            gunnerCompartments = "Compartment2";
            memoryPointsGetInGunner = "pos gunner";
            memoryPointsGetInGunnerDir = "pos gunner dir";
            isCopilot = 0;
            turretFollowFreeLook = 0;
            slingLoadOperator = 0;
        };
        class BackDoorGun : MainTurret {
            body = "Turret3";
            gun = "Gun_3";
            minTurn = 130;
            maxTurn = 230;
            initTurn = 180;
            minElev = -50;
            maxElev = 50;
            initElev = 0;
            animationSourceBody = "Turret_3";
            animationSourceGun = "Gun_3";
            stabilizedInAxes = 0;
            selectionFireAnim = "zasleh_3";
            proxyIndex = 3;
            gunnerName = "$STR_A3_REAR_GUNNER";
            gunnerOpticsShowCursor = 0;
            commanding = -1;
            gunnerAction = "CUP_CH47_Gunner01";
            gunnerInAction = "CUP_CH47_Gunner01";
            weapons[] = { "CUP_Vlmg_L7A2_veh" };
            magazines[] = { "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M" };
            gunBeg = "muzzle_3";
            gunEnd = "chamber_3";
            primaryGunner = 0;
            memoryPointGun = "machinegun_3";
            memoryPointGunnerOptics = "gunnerview_3";
            memoryPointsGetInGunner = "pos gunner";
            memoryPointsGetInGunnerDir = "pos gunner dir";
            gunnerCompartments = "Compartment2";
            isCopilot = 0;
            slingLoadOperator = 0;
        };
        class CopilotTurret : CopilotTurret {
            CanEject = 0;
            gunnerAction = "CUP_CH47_Pilot";
            gunnerInAction = "CUP_CH47_Pilot";
            memoryPointsGetInGunner = "pos cargo";
            memoryPointsGetInGunnerDir = "pos cargo dir";
            gunnerGetInAction = "GetInHeli_Transport_01Cargo";
            gunnerGetOutAction = "GetOutLow";
            preciseGetInOut = 0;
            GunnerDoor = "";
            gunnerLeftHandAnimName = "lever_copilot";
            gunnerRightHandAnimName = "stick_copilot";
            gunnerLeftLegAnimName = "";
            gunnerRightLegAnimName = "";
            proxyIndex = 4;
            LODTurnedIn = 1100;
            LODTurnedOut = 1100;
            gunnerCompartments = "Compartment3";
            commanding = -3;
            isCopilot = 1;
            primaryGunner = 1;
            slingLoadOperator = 0;
            class Components {
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
            };
        };
    };
    class AnimationSources : AnimationSources {
        class machinegun_muzzle_rot {
            source = "ammorandom";
            weapon = "CUP_Vlmg_L7A2_veh";
        };
        class ReloadAnim {
            source = "reload";
            weapon = "CUP_Vlmg_L7A2_veh";
        };
        class ReloadMagazine {
            source = "reloadmagazine";
            weapon = "CUP_Vlmg_L7A2_veh";
        };
        class Revolving {
            source = "revolving";
            weapon = "CUP_Vlmg_L7A2_veh";
        };
    };
    INVENTORY_AIRCRAFT;
};
class CUP_CH47F_VIV_base;
class CUP_B_CH47F_VIV_GB : CUP_CH47F_VIV_base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7", "UKSF_B_Pilot_7", "UKSF_B_Pilot_7" };
    hiddenSelectionsTextures[] = { "cup\airvehicles\cup_airvehicles_ch47\data\ch47_ext_1_baf_co.paa", "cup\airvehicles\cup_airvehicles_ch47\data\ch47_ext_2_baf_co.paa", "", "cup\airvehicles\cup_airvehicles_ch47\data\ch47_ext_mlod_co.paa" };
    class TextureSources {};
    INVENTORY_AIRCRAFT;
};

HIDE_CLASS_WITH_BASE(CUP_B_MH47E_GB,CUP_B_MH47E_USA);
