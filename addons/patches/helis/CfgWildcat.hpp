class Heli_light_03_base_F : Helicopter_Base_F {
    class Components;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class UK3CB_BAF_Wildcat_Base : Heli_light_03_base_F {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    FUEL(836,60);
    weapons[] = { "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
    startDuration = 30;
    mainRotorSpeed = 1;
    bodyFrictionCoef = 0.5;        // 1
    liftForceCoef = 0.95;          // 1
    maxFordingDepth = 1.2;         // 0.7
    cyclicAsideForceCoef = 1.2;    // 1
    cyclicForwardForceCoef = 1.1;  // 1
    unitInfoType = "RscUnitInfoNoSpeed";
    attenuationEffectType = "HeliAttenuation";
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
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class OpticsIn {
                class WideNGS {
                    opticsDisplayName = "WNGS";
                    initAngleX = 0;
                    minAngleX = -35;
                    maxAngleX = 10;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = 0.5;
                    minFov = 0.5;
                    maxFov = 0.5;
                    visionMode[] = { "Normal", "NVG", "Ti" };
                    thermalMode[] = { 0, 1 };
                    gunnerOpticsColor[] = { 0, 0, 0, 1 };
                    gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
                    opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
                    directionStabilized = 0;
                };
                class Wide : WideNGS {
                    opticsDisplayName = "W";
                    initFov = 0.466;
                    minFov = 0.466;
                    maxFov = 0.466;
                    gunnerOpticsEffect[] = { "TankCommanderOptics1" };
                    directionStabilized = 1;
                    horizontallyStabilized = 1;
                    stabilizedInAxes = 3;
                };
                class WideL : Wide {
                    opticsDisplayName = "WL";
                    initFov = 0.094;
                    minFov = 0.094;
                    maxFov = 0.094;
                };
                class Medium : Wide {
                    opticsDisplayName = "M";
                    initFov = 0.019;
                    minFov = 0.019;
                    maxFov = 0.019;
                };
                class Narrow : Wide {
                    opticsDisplayName = "N";
                    initFov = 0.006;
                    minFov = 0.006;
                    maxFov = 0.006;
                };
            };
            class OpticsOut {
                class Monocular {
                    minAngleX = -65;
                    maxAngleX = 85;
                    initAngleX = 0;
                    minAngleY = -150;
                    maxAngleY = 150;
                    initAngleY = 0;
                    minFov = 0.25;
                    maxFov = 1.25;
                    initFov = 0.75;
                    visionMode[] = { "Normal", "NVG" };
                    gunnerOpticsModel = "";
                    gunnerOpticsEffect[] = {};
                    directionStabilized = 0;
                };
            };
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
    ace_cookoff_cookoffSelections[] = { "motor" };
    UGVAR(radios,rackChannels)[] = { 31, 40, 41 };
#include "..\hmds\MFDCAS.hpp"
    LESH_canBeTowed = 0;
    LESH_towFromFront = 1;
    LESH_AxisOffsetTarget[] = { -0.125, 7.915, -1.67 };
    LESH_WheelOffset[] = { -0.125, -1 };
    EGVAR(common,towbarOffset)[] = { 0.31, 0, -0.06 };
    EGVAR(common,towbarRotation)[] = { 0, 1, 0.053 };
    EGVAR(common,towbarActionMemoryPoint) = "wheel_front_axis";
};

class UK3CB_BAF_Wildcat_AH1_6_Base;
class UK3CB_BAF_Wildcat_AH1_6_Armed: UK3CB_BAF_Wildcat_AH1_6_Base {
    crew = "UKSF_B_Pilot_656";
    typicalCargo[] = { "UKSF_B_Pilot_656" };
    weapons[] = { "CUP_weapon_mastersafe", "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
    INVENTORY_AIRCRAFT;
};
class UK3CB_BAF_Wildcat_AH1_8_Base;
class UK3CB_BAF_Wildcat_AH1_8_Armed: UK3CB_BAF_Wildcat_AH1_8_Base {
    crew = "UKSF_B_Pilot_656";
    typicalCargo[] = { "UKSF_B_Pilot_656" };
    weapons[] = { "CUP_weapon_mastersafe", "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
    INVENTORY_AIRCRAFT;
};
class UK3CB_BAF_Wildcat_AH1_TRN_8A : UK3CB_BAF_Wildcat_AH1_8_Base {
    INVENTORY_AIRCRAFT;
};
class UK3CB_BAF_Wildcat_HMA2_Base: UK3CB_BAF_Wildcat_Base {
    class Components : Components {
        class SensorsManagerComponent;
    };
};
class UK3CB_BAF_Wildcat_HMA2_8_Base : UK3CB_BAF_Wildcat_HMA2_Base {
    class Components : Components {
        class SensorsManagerComponent : SensorsManagerComponent {
            class Components;
        };
    };
};
class UK3CB_BAF_Wildcat_HMA2_TRN_8A : UK3CB_BAF_Wildcat_HMA2_8_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    class Components : Components {
        class SensorsManagerComponent : SensorsManagerComponent {
            class Components : Components {
                class ActiveRadarSensorComponent : SensorTemplateActiveRadar {
                    class AirTarget {
                        maxRange = 0;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    maxTrackableSpeed = 40;
                    angleRangeVertical = 90;
                    groundNoiseDistanceCoef = -1;
                    maxGroundNoiseDistance = -1;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 0;
                    aimDown = 30;
                    animDirection = "mainGun";
                };
            };
        };
    };
    INVENTORY_AIRCRAFT;
};

HIDE_CLASS(UK3CB_BAF_Wildcat_AH1_6_Generic,UK3CB_BAF_Wildcat_AH1_6_Armed);
HIDE_CLASS(UK3CB_BAF_Wildcat_AH1_8_Generic,UK3CB_BAF_Wildcat_AH1_8_Armed);
HIDE_CLASS(UK3CB_BAF_Wildcat_AH1_HEL_6A,UK3CB_BAF_Wildcat_AH1_6_Base);
HIDE_CLASS(UK3CB_BAF_Wildcat_AH1_HEL_8A,UK3CB_BAF_Wildcat_AH1_8_Base);

DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_6A,UK3CB_BAF_Wildcat_AH1_6_Armed);
DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_6B,UK3CB_BAF_Wildcat_AH1_6_Armed);
DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_6C,UK3CB_BAF_Wildcat_AH1_6_Armed);
DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_6D,UK3CB_BAF_Wildcat_AH1_6_Armed);
DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_8A,UK3CB_BAF_Wildcat_AH1_8_Armed);
DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_8B,UK3CB_BAF_Wildcat_AH1_8_Armed);
DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_8C,UK3CB_BAF_Wildcat_AH1_8_Armed);
DEPRECATE_CLASS(UK3CB_BAF_Wildcat_AH1_CAS_8D,UK3CB_BAF_Wildcat_AH1_8_Armed);

class rksla3_aw159_base : Helicopter_Base_F {
    class ViewPilot;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class rksla3_aw159_hma2 : rksla3_aw159_base {
    faction = "CUP_B_GB";
    vehicleClass = "Air";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    FUEL(836,60);
    startDuration = 30;
    unitInfoType = "RscUnitInfoNoSpeed";
    attenuationEffectType = "HeliAttenuation";
    weapons[] = { "CUP_weapon_mastersafe", "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
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
            weapons[] = { "UK3CB_BAF_Laserdesignator_mounted" };
            magazines[] = { "Laserbatteries" };
            primaryGunner = 1;
            canEject = 1;
            showHMD = 1;
            lockDetectionSystem = "4 + 8";
            incomingMissileDetectionSystem = "16";
            canLock = 2;
            turretInfoType = "RscOptics_Wildcat_gunner_zeroing";
            stabilizedInAxes = 3;
            ace_laser_canLockLaser = 1;
            ace_laser_selfDesignate_enabled = 1;
            showCrewAim = "1 + 2";
            class OpticsIn {
                class WideNGS {
                    visionMode[] = { "Normal", "NVG", "Ti" };
                    thermalMode[] = { 0, 1 };
                    gunnerOpticsColor[] = { 0, 0, 0, 1 };
                    opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
                    opticsDisplayName = "WNGS";
                    initAngleX = 0;
                    minAngleX = -35;
                    maxAngleX = 10;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    initFov = 0.5;
                    minFov = 0.5;
                    maxFov = 0.5;
                    gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
                    directionStabilized = 0;
                };
                class Wide : WideNGS {
                    gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
                    gunnerOpticsEffect[] = { "TankCommanderOptics1" };
                    opticsDisplayName = "W";
                    initFov = 0.466;
                    minFov = 0.466;
                    maxFov = 0.466;
                    directionStabilized = 1;
                    horizontallyStabilized = 1;
                    stabilizedInAxes = 3;
                };
                class WideL : Wide {
                    opticsDisplayName = "WL";
                    initFov = 0.094;
                    minFov = 0.094;
                    maxFov = 0.094;
                };
                class Medium : Wide {
                    opticsDisplayName = "M";
                    initFov = 0.019;
                    minFov = 0.019;
                    maxFov = 0.019;
                };
                class Narrow : Wide {
                    opticsDisplayName = "N";
                    initFov = 0.006;
                    minFov = 0.006;
                    maxFov = 0.006;
                };
            };
            class OpticsOut {
                class Monocular {
                    visionMode[] = { "Normal", "NVG" };
                    gunnerOpticsEffect[] = {};
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
                    gunnerOpticsModel = "";
                    directionStabilized = 0;
                };
            };
        };
    };
    UGVAR(radios,rackChannels)[] = { 31, 40, 41 };
    INVENTORY_AIRCRAFT;
#include "..\hmds\MFDRKSLWildcat.hpp"
};
