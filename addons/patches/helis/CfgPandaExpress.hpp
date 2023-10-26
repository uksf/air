class Heli_Light_01_unarmed_base_F;
class B_Heli_Light_01_F : Heli_Light_01_unarmed_base_F {
    class Components;
};
class GVAR(pe_mh6) : B_Heli_Light_01_F {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    editorSubcategory = QGVAR(pe);
    weapons[] = { "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    startDuration = 30;
    lockDetectionSystem = "8 + 4";
    incomingMissileDetectionSystem = "8 + 16";
    UGVAR(radios,rackChannels)[] = { 30,40,41 };
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
                class IRSensorComponent : SensorTemplateIR {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class VisualSensorComponent : SensorTemplateVisual {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class NVSensorComponent : SensorTemplateNV {
                    animDirection = "flir_gun";
                };
                class LaserSensorComponent : SensorTemplateLaser {
                    animDirection = "flir_gun";
                };
                class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                class DataLinkSensorComponent : SensorTemplateDataLink {};
            };
        };
    };
    INVENTORY_AIRCRAFT;
#include "..\hmds\MFDGeneral.hpp"
};

class Heli_Light_01_dynamicLoadout_base_F;
class B_Heli_Light_01_dynamicLoadout_F : Heli_Light_01_dynamicLoadout_base_F {
    class Components;
};
class GVAR(pe_ah6) : B_Heli_Light_01_dynamicLoadout_F {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    editorSubcategory = QGVAR(pe);
    weapons[] = { "CUP_weapon_mastersafe", "UK3CB_BAF_CMFlareLauncher", "M134_minigun" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine", "5000Rnd_762x51_Belt" };
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    startDuration = 30;
    lockDetectionSystem = "8 + 4";
    incomingMissileDetectionSystem = "8 + 16";
    UGVAR(radios,rackChannels)[] = { 30,40,41 };
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
                class IRSensorComponent : SensorTemplateIR {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class VisualSensorComponent : SensorTemplateVisual {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class NVSensorComponent : SensorTemplateNV {
                    animDirection = "flir_gun";
                };
                class LaserSensorComponent : SensorTemplateLaser {
                    animDirection = "flir_gun";
                };
                class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                class DataLinkSensorComponent : SensorTemplateDataLink {};
            };
        };
    };
    INVENTORY_AIRCRAFT;
#include "..\hmds\MFDCAS.hpp"
};

class CUP_Uh60_Unarmed_FFV_Base;
class CUP_Uh60L_Unarmed_FFV_Base : CUP_Uh60_Unarmed_FFV_Base {
    // class Turrets;
};
class CUP_B_UH60L_Unarmed_FFV_MEV_US : CUP_Uh60L_Unarmed_FFV_Base {
    // class Turrets : Turrets {
    //     class CopilotTurret;
    // };
    class Components;
};
class GVAR(pe_uh60) : CUP_B_UH60L_Unarmed_FFV_MEV_US {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "UH-60L";
    crew = "UKSF_B_Pilot_7";
    editorSubcategory = QGVAR(pe);
    weapons[] = { "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    startDuration = 45;
    lockDetectionSystem = "8 + 4";
    incomingMissileDetectionSystem = "8 + 16";
    UGVAR(radios,rackChannels)[] = { 30,40,41 };
    // class Turrets : Turrets {
    //     class CopilotTurret : CopilotTurret {
    //         // body = "flirgun";
    //         // gun = "flirgun";
    //         // animationSourceBody = "flirgun";
    //         // animationSourceGun = "flirgun";
    //         memoryPointGunnerOptics = "flirgun_axis";
    //         // gunBeg = "flirgun_axis";
    //         // gunEnd = "flirgun";
    //         // memoryPointGun = "flirgun_axis";
    //         gunAxis = "flirgun_axis";
    //         turretAxis = "flirturret_axis";
    //         stabilizedInAxes = 3;
    //         isCopilot = 1;
    //         primaryObserver = 1;
    //         proxyIndex = 3;
    //         minElev = -40;
    //         maxElev = 20;
    //         initElev = 0;
    //         minTurn = -360;
    //         maxTurn = 360;
    //         initTurn = 0;
    //         turretInfoType = "RscOptics_UAV_gunner";
    //         weapons[] = {};
    //         magazines[] = {};
    //         proxyType = "CPGunner";
    //         inGunnerMayFire = 0;
    //         gunnerOpticsEffect[] = {};
    //         gunnerOpticsModel = "";
    //         class Components {
    //             class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft{
    //                 defaultDisplay = "EmptyDisplay";
    //                 class Components{
    //                     class CrewDisplay{
    //                         componentType = "CrewDisplayComponent";
    //                         resource = "RscCustomInfoCrew";
    //                     };
    //                     class MinimapDisplay{
    //                         componentType = "MinimapDisplayComponent";
    //                         resource = "RscCustomInfoMiniMap";
    //                     };
    //                     class SlingLoadDisplay{
    //                         componentType = "SlingLoadDisplayComponent";
    //                         resource = "RscCustomInfoSlingLoad";
    //                     };
    //                     class EmptyDisplay{
    //                         componentType = "EmptyDisplayComponent";
    //                     };
    //                 };
    //             };
    //             class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight{
    //                 defaultDisplay = "SensorsDisplay";
    //                 class Components{
    //                     class SensorsDisplay{
    //                         componentType = "SensorsDisplayComponent";
    //                         range[] = {16000, 8000, 4000, 2000};
    //                         resource = "RscCustomInfoSensors";
    //                     };
    //                     class CrewDisplay{
    //                         componentType = "CrewDisplayComponent";
    //                         resource = "RscCustomInfoCrew";
    //                     };
    //                     class MinimapDisplay{
    //                         componentType = "MinimapDisplayComponent";
    //                         resource = "RscCustomInfoMiniMap";
    //                     };
    //                     class SlingLoadDisplay{
    //                         componentType = "SlingLoadDisplayComponent";
    //                         resource = "RscCustomInfoSlingLoad";
    //                     };
    //                     class EmptyDisplay{
    //                         componentType = "EmptyDisplayComponent";
    //                     };
    //                 };
    //             };
    //         };
    //         class OpticsIn{
    //             class WideNGS{
    //                 opticsDisplayName = "W";
    //                 initAngleX = 0;
    //                 minAngleX = -35;
    //                 maxAngleX = 10;
    //                 initAngleY = 0;
    //                 minAngleY = -100;
    //                 maxAngleY = 100;
    //                 initFov = 0.466;
    //                 minFov = 0.466;
    //                 maxFov = 0.466;
    //                 visionMode[] = {"Normal", "NVG", "Ti"};
    //                 thermalMode[] = {0, 1};
    //                 gunnerOpticsColor[] = {0.15, 1, 0.15, 1};
    //                 gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
    //                 directionStabilized = 0;
    //                 opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
    //             };
    //             class Wide{
    //                 opticsDisplayName = "W";
    //                 initAngleX = 0;
    //                 minAngleX = -35;
    //                 maxAngleX = 10;
    //                 initAngleY = 0;
    //                 minAngleY = -100;
    //                 maxAngleY = 100;
    //                 initFov = 0.466;
    //                 minFov = 0.466;
    //                 maxFov = 0.466;
    //                 visionMode[] = {"Normal", "NVG", "Ti"};
    //                 thermalMode[] = {0, 1};
    //                 gunnerOpticsColor[] = {0.15, 1, 0.15, 1};
    //                 gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
    //                 directionStabilized = 1;
    //                 opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
    //                 gunnerOpticsEffect[] = {"TankCommanderOptics1"};
    //             };
    //             class WideL: Wide{
    //                 opticsDisplayName = "WL";
    //                 initFov = 0.2;
    //                 minFov = 0.2;
    //                 maxFov = 0.2;
    //                 gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
    //                 gunnerOpticsColor[] = {0, 0, 0, 1};
    //                 directionStabilized = 1;
    //                 opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
    //             };
    //             class Medium: Wide{
    //                 opticsDisplayName = "M";
    //                 initFov = 0.1;
    //                 minFov = 0.1;
    //                 maxFov = 0.1;
    //                 directionStabilized = 1;
    //                 gunnerOpticsColor[] = {0, 0, 0, 1};
    //                 gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
    //             };
    //             class Narrow: Wide{
    //                 opticsDisplayName = "N";
    //                 gunnerOpticsColor[] = {0, 0, 0, 1};
    //                 gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
    //                 directionStabilized = 1;
    //                 initFov = 0.02;
    //                 minFov = 0.02;
    //                 maxFov = 0.02;
    //             };
    //             class Narrower: Wide{
    //                 opticsDisplayName = "N";
    //                 gunnerOpticsColor[] = {0, 0, 0, 1};
    //                 gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
    //                 directionStabilized = 1;
    //                 initFov = 0.01;
    //                 minFov = 0.01;
    //                 maxFov = 0.01;
    //             };
    //         };
    //         class OpticsOut{
    //             class Monocular{
    //                 initAngleX = 0;
    //                 minAngleX = -30;
    //                 maxAngleX = 30;
    //                 initAngleY = 0;
    //                 minAngleY = -100;
    //                 maxAngleY = 100;
    //                 initFov = 1.1;
    //                 minFov = 0.133;
    //                 maxFov = 1.1;
    //                 visionMode[] = {"Normal", "NVG"};
    //                 gunnerOpticsModel = "";
    //                 gunnerOpticsEffect[] = {};
    //             };
    //         };
    //         startEngine = 0;
    //         gunnerHasFlares = 0;
    //     };
    // };
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
                class IRSensorComponent : SensorTemplateIR {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class VisualSensorComponent : SensorTemplateVisual {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class NVSensorComponent : SensorTemplateNV {
                    animDirection = "flir_gun";
                };
                class LaserSensorComponent : SensorTemplateLaser {
                    animDirection = "flir_gun";
                };
                class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                class DataLinkSensorComponent : SensorTemplateDataLink {};
            };
        };
    };
    INVENTORY_AIRCRAFT;
#include "..\hmds\MFDGeneral.hpp"
};

class CUP_Merlin_Rescue_Base;
class CUP_C_Merlin_HC3_IDAP_Rescue : CUP_Merlin_Rescue_Base {
    class Components;
};
class GVAR(eh101_idap) : CUP_C_Merlin_HC3_IDAP_Rescue {
    scope = 2;
    scopeCurator = 2;
    side = 1;
    faction = "CUP_B_GB";
    displayName = "EH101 (IDAP)";
    crew = "UKSF_B_Pilot_7";
    editorSubcategory = QGVAR(pe);
    weapons[] = { "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    startDuration = 60;
    lockDetectionSystem = "8 + 4";
    incomingMissileDetectionSystem = "8 + 16";
    attendant = 1;
    UGVAR(radios,rackChannels)[] = { 30,40,41 };
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
                class IRSensorComponent : SensorTemplateIR {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class VisualSensorComponent : SensorTemplateVisual {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "flir_turret";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class NVSensorComponent : SensorTemplateNV {
                    animDirection = "flir_gun";
                };
                class LaserSensorComponent : SensorTemplateLaser {
                    animDirection = "flir_gun";
                };
                class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                class DataLinkSensorComponent : SensorTemplateDataLink {};
            };
        };
    };
    INVENTORY_AIRCRAFT;
#include "..\hmds\MFDGeneral.hpp"
};
