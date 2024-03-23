class Heli_Transport_02_base_F : Helicopter_Base_H {};
class UK3CB_BAF_Merlin_Base : Heli_Transport_02_base_F {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    FUEL(3222,100);
    weapons[] = { "UK3CB_BAF_CMFlareLauncher" };
    magazines[] = { "120Rnd_CMFlare_Chaff_Magazine" };
    startDuration = 60;
    cyclicAsideForceCoef = 1.1; // 1
    cyclicForwardForceCoef = 1;
    unitInfoType = "RscUnitInfoNoSpeed";
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
    /*landingSoundInt0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int1", 0.25, 1, 50 };
    landingSoundInt1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int2", 0.25, 1, 50 };
    landingSoundInt[] = { "landingSoundInt0", 0.5, "landingSoundInt1", 0.5 };
    landingSoundOut0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1", 0.4, 1, 50 };
    landingSoundOut1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2", 0.4, 1, 50 };
    landingSoundOut[] = { "landingSoundOut0", 0.5, "landingSoundOut1", 0.5 };*/
    class Components : Components {
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
                    animDirection = "mainGun";
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
                    animDirection = "mainGun";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class PassiveSensorComponent : SensorTemplatePassiveRadar {};
                class LaserSensorComponent : SensorTemplateLaser {};
                class NVSensorComponent : SensorTemplateNV {};
                class DataLinkSensorComponent : SensorTemplateDataLink {};
            };
        };
    };
    ace_cookoff_cookoffSelections[] = { "motor" };
    UGVAR(radios,rackChannels)[] = { 31, 40, 41 };
    LESH_canBeTowed = 0;
    LESH_towFromFront = 1;
    LESH_AxisOffsetTarget[] = { 0.22, 11.905, -3.295 };
    LESH_WheelOffset[] = { 0.22, -1 };
    EGVAR(common,towbarOffset)[] = { 0.255, 0, -0.115 };
    EGVAR(common,towbarRotation)[] = { 0, 1, 0.04 };
    EGVAR(common,towbarActionMemoryPoint) = "wheel_front_axis";
#include "..\hmds\MFDMerlin.hpp"
};

HIDE_CLASS_WITH_BASE(UK3CB_BAF_Merlin_HC3_18,UK3CB_BAF_Merlin_HC3_Unarmed_Base);
HIDE_CLASS(UK3CB_BAF_Merlin_HC3_24,UK3CB_BAF_Merlin_HC3_Unarmed_Base);
HIDE_CLASS(UK3CB_BAF_Merlin_HC3_32,UK3CB_BAF_Merlin_HC3_Unarmed_Base);
HIDE_CLASS(UK3CB_BAF_Merlin_HC3_Cargo,UK3CB_BAF_Merlin_HC3_Unarmed_Base);
HIDE_CLASS_WITH_BASE(UK3CB_BAF_Merlin_HC3_18_GPMG,UK3CB_BAF_Merlin_HC3_Armed_Base);
HIDE_CLASS(UK3CB_BAF_Merlin_HC3_CSAR,UK3CB_BAF_Merlin_HC3_Armed_Base);

HIDE_CLASS(UK3CB_BAF_Merlin_HC4_18,UK3CB_BAF_Merlin_HC3_18);
HIDE_CLASS(UK3CB_BAF_Merlin_HC4_24,UK3CB_BAF_Merlin_HC3_24);
class UK3CB_BAF_Merlin_HC4_32 : UK3CB_BAF_Merlin_HC3_32 {
    faction = "CUP_B_GB";
    displayname = "Merlin HC4 (32)";
    INVENTORY_AIRCRAFT;
};
class UK3CB_BAF_Merlin_HC4_Cargo : UK3CB_BAF_Merlin_HC3_Cargo {
    faction = "CUP_B_GB";
    displayname = "Merlin HC4 (Cargo)";
    INVENTORY_AIRCRAFT;
};
class UK3CB_BAF_Merlin_HC4_18_GPMG : UK3CB_BAF_Merlin_HC3_18_GPMG {
    faction = "CUP_B_GB";
    displayname = "Merlin HC4 (Armed)";
    class TransportMagazines {
        MACRO_ADDMAGAZINE(ACE_M14,2);
        MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2);
        MACRO_ADDMAGAZINE(B_IR_Grenade,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd_T,15);
    };
    class TransportItems {
        MACRO_ADDITEM(Toolkit,1);
        MACRO_ADDITEM(ACE_elasticBandage,4);
        MACRO_ADDITEM(ACE_packingBandage,4);
        MACRO_ADDITEM(ACE_morphine,4);
    };
    class TransportWeapons {};
    class TransportBackpacks {};
};
class UK3CB_BAF_Merlin_HC4_CSAR : UK3CB_BAF_Merlin_HC3_CSAR {
    faction = "CUP_B_GB";
    displayname = "Merlin HC4 (CSAR)";
    class TransportMagazines {
        MACRO_ADDMAGAZINE(ACE_M14,2);
        MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2);
        MACRO_ADDMAGAZINE(B_IR_Grenade,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd_T,15);
        MACRO_ADDMAGAZINE(ACE_painkillers,15);
    };
    class TransportItems {
        MACRO_ADDITEM(Toolkit,1);
        MACRO_ADDITEM(ACE_elasticBandage,40);
        MACRO_ADDITEM(ACE_morphine,30);
        MACRO_ADDITEM(ACE_bloodIV,20);
        MACRO_ADDITEM(ACE_bloodIV_500,20);
        MACRO_ADDITEM(ACE_bloodIV_250,20);
        MACRO_ADDITEM(ACE_splint,10);
    };
    class TransportWeapons {};
    class TransportBackpacks {};
};

HIDE_CLASS(UK3CB_BAF_Merlin_HM2_Base,UK3CB_BAF_Merlin_Base);
HIDE_CLASS(UK3CB_BAF_Merlin_HM2_Unarmed_Base,UK3CB_BAF_Merlin_HM2_Base);
class UK3CB_BAF_Merlin_HM2_18 : UK3CB_BAF_Merlin_HM2_Unarmed_Base {
    faction = "CUP_B_GB";
    displayname = "Merlin HM2 (18)";
    INVENTORY_AIRCRAFT;
};
