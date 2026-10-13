class Heli_Light_01_unarmed_base_F : Heli_Light_01_base_F {
    class Turrets;
};
class B_Heli_Light_01_F : Heli_Light_01_unarmed_base_F {
    class Components;
    class Turrets : Turrets {
        class CopilotTurret;
    };
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
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
            weapons[] += { "UK3CB_BAF_CMFlareLauncher" };
            magazines[] += { "168Rnd_CMFlare_Chaff_Magazine" };
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

class Heli_Light_01_armed_base_F;
class Heli_Light_01_dynamicLoadout_base_F : Heli_Light_01_armed_base_F {
    class Turrets;
};
class B_Heli_Light_01_dynamicLoadout_F : Heli_Light_01_dynamicLoadout_base_F {
    class Components;
    class Turrets : Turrets {
        class CopilotTurret;
    };
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
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
            weapons[] += { "UK3CB_BAF_CMFlareLauncher" };
            magazines[] += { "168Rnd_CMFlare_Chaff_Magazine" };
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

class CUP_Uh60L_Unarmed_FFV_Base : CUP_Uh60_Unarmed_FFV_Base {
    class Turrets;
};
class CUP_B_UH60L_Unarmed_FFV_MEV_US : CUP_Uh60L_Unarmed_FFV_Base {
    class Turrets : Turrets {
        class CopilotTurret;
    };
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
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
            weapons[] += { "UK3CB_BAF_CMFlareLauncher" };
            magazines[] += { "168Rnd_CMFlare_Chaff_Magazine" };
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

class CUP_B_UH60M_FFV_US : CUP_Uh60_FFV_Base {
    class Components;
    class Turrets : Turrets {
        class CopilotTurret;
    };
};
class GVAR(pe_uh60m) : CUP_B_UH60M_FFV_US {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "UH-60M";
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
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
            weapons[] += { "UK3CB_BAF_CMFlareLauncher" };
            magazines[] += { "168Rnd_CMFlare_Chaff_Magazine" };
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

class CUP_MH60L_Dap_4x_Dynamic_Base : CUP_Uh60_Base {
    class Turrets;
};
class CUP_B_MH60L_DAP_4x_US : CUP_MH60L_Dap_4x_Dynamic_Base {
    class Components;
    class Turrets : Turrets {
        class CopilotTurret;
    };
};
class GVAR(pe_mh60l) : CUP_B_MH60L_DAP_4x_US {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "MH-60L";
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
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
            weapons[] += { "UK3CB_BAF_CMFlareLauncher" };
            magazines[] += { "168Rnd_CMFlare_Chaff_Magazine" };
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
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
            weapons[] += { "UK3CB_BAF_CMFlareLauncher" };
            magazines[] += { "168Rnd_CMFlare_Chaff_Magazine" };
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
