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
    class UK3CB_BAF_Apache_base;
    class UK3CB_BAF_Apache_AH1 : UK3CB_BAF_Apache_base {
        class Turrets;
    };
    class UK3CB_BAF_Apache_AH1_Generic : UK3CB_BAF_Apache_AH1 {
        class Sounds;
        class Turrets : Turrets {
            class MainTurret;
        };
        class Components;
    };
    class GVAR(base) : UK3CB_BAF_Apache_AH1_Generic {
        scope = 1;
        author = "UKSF";
        displayName = "AH-64D Apache Base";
        picture = QPATHTOF(data\ui\Picture_ah64d_CA.paa);
        icon = QPATHTOF(data\ui\Icon_ah64d_CA.paa);
        crew = "UKSF_B_Pilot_656";
        typicalCargo[] = { "UKSF_B_Pilot_656", "UKSF_B_Pilot_656" };
        armor = 150;
        FUEL(870,75);
        startDuration = 70;
        explosionShielding = 2;
        epeImpulseDamageCoef = 5;
        crewCrashProtection = 0.5;
        lockDetectionSystem = "1 + 2 + 4 + 8";
        cyclicAsideForceCoef = 2; // 1.75 // 1.06
        cyclicForwardForceCoef = 1.6; // 1.5 // 1
        backRotorForceCoef = 1.8;
        backRotorSpeed = 3.0;
        liftForceCoef = 1.8;
        maxSpeed = 293;
        weapons[] = { "CUP_weapon_mastersafe", "UK3CB_BAF_CMFlareLauncher" };
        magazines[] = { "168Rnd_CMFlare_Chaff_Magazine" };
        unitInfoType = "RscUnitInfoNoSpeed";
        unitInfoTypeLite = "RscUnitInfoNoSpeed";
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
            class EngineExt {
                sound[] = { "LAxemann\DynaSound\addons\DS_a_Kajman\sounds\Engine_Ext", 1.301, 1, 800 };
                frequency = "rotorSpeed";
                volume = "2.2 * camPos * (0 max (rotorSpeed - 0.4))";
            };
            class EngineInt {
                sound[] = { "LAxemann\DynaSound\addons\DS_a_Kajman\sounds\Engine_Int", 0.801, 1 };
                frequency = "rotorSpeed";
                volume = "(1 - camPos) * 1.5 * (0 max (rotorSpeed - 0.4))";
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
                class EngineExt {
                    sound[] = { "LAxemann\DynaSound\addons\DS_a_Kajman\sounds\Engine_Ext", 1.301, 1, 800 };
                    frequency = "rotorSpeed";
                    volume = "2.2 * camPos * (0 max (rotorSpeed - 0.4))";
                };
                class EngineInt {
                    sound[] = { "LAxemann\DynaSound\addons\DS_a_Kajman\sounds\Engine_Int", 0.801, 1 };
                    frequency = "rotorSpeed";
                    volume = "(1 - camPos) * 1.5 * (0 max (rotorSpeed - 0.4))";
                };
            };
        };
        class Turrets : Turrets {
            class MainTurret : MainTurret {
                #include "MFDGunner.hpp"
                turretInfoType = "RscOptics_GENERAL_FLIR";
                weapons[] = { "CUP_weapon_mastersafe", "UK3CB_BAF_Laserdesignator_mounted", "CUP_Vacannon_M230_veh" };
                magazines[] = { "Laserbatteries", "CUP_1200Rnd_TE1_Red_Tracer_30x113mm_M789_HEDP_M" };
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
                        class VehicleDriverDisplay {
                            componentType = "TransportFeedDisplayComponent";
                            source = "Driver";
                        };
                        class SensorsDisplay {
                            componentType = "SensorsDisplayComponent";
                            range[] = { 16000, 8000, 4000, 2000 };
                            showTargetTypes = "1+2+4+8+16+32+64+128+256+512+1024";
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
                        class VehicleDriverDisplay {
                            componentType = "TransportFeedDisplayComponent";
                            source = "Driver";
                        };
                        class SensorsDisplay {
                            componentType = "SensorsDisplayComponent";
                            range[] = { 16000, 8000, 4000, 2000 };
                            showTargetTypes = "1+2+4+8+16+32+64+128+256+512+1024";
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
        class Components : Components {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
                defaultDisplay = "EmptyDisplay";
                class Components {
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
                    class SensorsDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        showTargetTypes = "1+2+4+8+16+32+64+128+256+512+1024";
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
                    class VehicleGunnerDisplay {
                        componentType = "TransportFeedDisplayComponent";
                        source = "PrimaryGunner";
                    };
                    class SensorsDisplay {
                        componentType = "SensorsDisplayComponent";
                        range[] = { 16000, 8000, 4000, 2000 };
                        showTargetTypes = "1+2+4+8+16+32+64+128+256+512+1024";
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
            class TransportPylonsComponent {
                uiPicture = QPATHTOF(data\ui\Apache_EDEN_CA.paa);
                class Pylons {
                    class PylonLeft1 {
                        attachment = "CUP_PylonPod_19Rnd_CRV7_HE_M";
                        priority = 5;
                        bay = -1;
                        hardpoints[] = { "B_CRV7", "B_HELLFIRE" };
                        UIposition[] = { 0.13, 0.3 };
                        turret[] = { 0 };
                    };
                    class PylonLeft2 : PylonLeft1 {
                        attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114N";
                        priority = 4;
                        hardpoints[] = { "B_CRV7", "B_HELLFIRE" };
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
        UGVAR(radios,rackChannels)[] = { 41, 31, 40, 42, 31, 30 };
        LESH_canBeTowed = 0;
        LESH_towFromFront = 0;
        LESH_AxisOffsetTarget[] = { 0.02, -12.33, -1.95 };
        LESH_WheelOffset[] = { 0.02, -1 };
        EGVAR(common,towbarOffset)[] = { 0.16, -0.05, 0.07 };
        EGVAR(common,towbarRotation)[] = { 0, -1, 0.035 };
        EGVAR(common,towbarActionMemoryPoint) = "wheel_12_2_axis";
        INVENTORY_AIRCRAFT;
        #include "MFDPilot.hpp"
    };
    class GVAR(aac) : GVAR(base) {
        scope = 2;
        scopeCurator = 2;
        side = 1;
        faction = "CUP_B_GB";
        displayName = "Apache AH1";
        PREVIEW(aac);
        class TransportBackpacks {};
    };
};
