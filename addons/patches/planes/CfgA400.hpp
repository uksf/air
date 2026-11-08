class A400M_base_F : Plane_Base_F {
    class Turrets {
        class MainTurret;
        class MainTurret2;
    };
    memoryPointsGetInDriver = "pos driver";
    memoryPointsGetInDriverDir = "pos driver dir";
    memoryPointsGetInCargo = "pos cargo";
    memoryPointsGetInCargoDir = "pos cargo dir";
    cargoGetInAction[] = {"GetInLow"};
    cargoGetOutAction[] = {"GetOutLow"};
    preciseGetInOut = 1;
    getInRadius = 8;
    ejectSpeed[] = {0, 0, 0};
    unitInfoType = "RscUnitInfoAirPlaneNoSpeed";
    unitInfoTypeLite = "RscUnitInfoAirPlaneNoSpeed";
    FUEL(63750,120);
    altFullForce = 10000;
    thrustCoef[] = { 1.42, 1.38, 1.34, 1.3, 1.25, 1.2, 1.19, 1.18, 1.17, 1.17, 1.16, 1.16, 1.1, 1, 0.7, 0.2, 0 };
    armor = 150;
    weapons[] = { QEGVAR(weapons,C130FlareLauncher) };
    magazines[] = { QEGVAR(weapons,CMFlare_Chaff_1200Rnd_Magazine) };
    gunnerhasflares = 1;
    lockDetectionSystem = "8 + 4";
    #include "CfgA400Components.hpp"
    #include "CfgA400Wheels.hpp"
    LESH_canBeTowed = 0;
    LESH_towFromFront = 1;
    LESH_AxisOffsetTarget[] = { 0, 13.2, 0.45 };
    LESH_WheelOffset[] = { 0, -1 };
    EGVAR(common,towbarOffset)[] = { 0, 0, 0 };
    EGVAR(common,towbarRotation)[] = { 0, 1, -0.005 };
    EGVAR(common,towbarActionMemoryPoint) = "wheel_1_1_center";
    UGVAR(radios,rackChannels)[] = { 31, 40, 41 };
    maximumLoad = 20000;
    epeImpulseDamageCoef = 10;
    class TransportMagazines {
        MACRO_ADDMAGAZINE(ACE_M14,2);
        MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2);
        MACRO_ADDMAGAZINE(B_IR_Grenade,2);
        MACRO_ADDMAGAZINE(ACE_painkillers,4);
    };
    class TransportItems {
        MACRO_ADDITEM(Toolkit,1);
        MACRO_ADDITEM(ACE_elasticBandage,4);
        MACRO_ADDITEM(ACE_packingBandage,4);
        MACRO_ADDITEM(ACE_morphine,4);
        MACRO_ADDITEM(uksf_halohaho_airSupply,6);
    };
    class TransportBackpacks {
        MACRO_ADDBACKPACK(B_Parachute,30);
    };
    class TransportWeapons {};
    class VehicleTransport {
        class Carrier {
            cargoBayDimensions[] = { { 1.5, -11.4, 1.85 }, { -1.5, 7, 5.7 } };
            disableHeightLimit = 1;
            maxLoadMass = 50000;
            cargoAlignment[] = { "front", "center" };
            cargoSpacing[] = { 0.2, 0.2, 0 };
            exits[] = { "VTV_exit_1" };
            unloadingInterval = 2;
            loadingDistance = 3;
            loadingAngle = 60;
            parachuteClassDefault = "B_Parachute_02_F";
            parachuteHeightLimitDefault = 50;
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
            expression = QUOTE([ARR_2(_this,_value)] call FUNC(a400RampControl));
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
    class AnimationSources : AnimationSources {
        class DOOR_PARA_LEFT {
            source = "user";
            initPhase = 1;
            animPeriod = 2;
        };
        class DOOR_PARA_RIGHT {
            source = "user";
            initPhase = 1;
            animPeriod = 2;
        };
        class DOOR_PARA_LEFT_ROT {
            source = "user";
            initPhase = 0;
            animPeriod = 2;
        };
        class DOOR_PARA_RIGHT_ROT {
            source = "user";
            initPhase = 0;
            animPeriod = 2;
        };
        class DOOR_PARA_LEFT_HIDE {
            source = "user";
            initPhase = 1;
            animPeriod = 0.1;
        };
        class DOOR_PARA_RIGHT_HIDE {
            source = "user";
            initPhase = 1;
            animPeriod = 0.1;
        };
        class damper_wheel_1_1_source {
            source = "damper";
            wheel = "Wheel_1";
        };
        class damper_wheel_3_1_source {
            source = "damper";
            wheel = "Wheel_3_1";
        };
        class damper_wheel_3_2_source {
            source = "damper";
            wheel = "Wheel_3_2";
        };
        class ramp_bottom {
            source = "user";
            animPeriod = 4;
            initPhase = 0;
        };
        class ramp_bottom2 {
            source = "user";
            animPeriod = 4;
            initPhase = 0;
        };
        class ramp_top {
            source = "user";
            animPeriod = 4;
            initPhase = 0;
        };
    };
    class HitPoints : HitPoints {
        class HitHull : HitHull {
            armor = 3.5;
            explosionShielding = 3;
            name = "HitHull";
            passThrough = 1;
            radius = 3;
            minimalHit = 0.05;
            depends = "0";
            material = -1;
        };
        class HitEngine : HitHull {
            armor = 3;
            explosionShielding = 4.5;
            name = "HitEngine";
            visual = "";
            passThrough = 0.8;
            radius = 0.6;
        };
        class HitEngine2 : HitEngine {
            name = "HitEngine2";
        };
        class HitEngine3 : HitEngine {
            name = "HitEngine3";
        };
        class HitEngine4 : HitEngine {
            name = "HitEngine4";
        };
        class HitAvionics : HitHull {
            armor = 1.5;
            explosionShielding = 4;
            name = "HitAvionics";
            visual = "";
            passThrough = 0.4;
            radius = 0.3;
        };
        class HitFuel : HitHull {
            armor = 4;
            explosionShielding = 5;
            name = "HitFuel";
            visual = "";
            passThrough = 0.6;
            radius = 0.3;
        };
        class HitFuel2 : HitFuel {
            name = "HitFuel2";
        };
        class HitGlass1 : HitHull {
            armor = 1.5;
            explosionShielding = 3;
            name = "HitGlass1";
            visual = "";
            passThrough = 0;
            radius = 0.2;
            minimalHit = 0.1;
        };
        class HitLAileron : HitHull {
            armor = 1.8;
            explosionShielding = 3.5;
            name = "HitLAileron";
            visual = "";
            passThrough = 0.3;
            radius = 0.35;
        };
        class HitRAileron : HitLAileron {
            name = "HitRAileron";
        };
        class HitLCElevator : HitLAileron {
            name = "HitLCElevator";
        };
        class HitRElevator : HitLAileron {
            name = "HitRElevator";
        };
        class HitLCRudder : HitLAileron {
            name = "HitRudder";
        };
        class HitRRudder : HitLAileron {
            name = "HitRudder";
        };
    };
    class RenderTargets {
        delete ecran_FE;
    };
    class UserActions : UserActions {
        delete openrampbottom;
        delete closerampbottom;
        class CloseRamp {
            position = "pilotcontrol";
            onlyforplayer = 1;
            radius = 8;
            showwindow = 0;
            displayName = "Close Ramp";
            condition = QUOTE([ARR_2(this,0)] call EFUNC(common,canControlRamp));
            statement = QUOTE([ARR_2(this,0)] call FUNC(a400RampControl));
        };
        class HalfRamp : CloseRamp {
            displayname = "Open Ramp Halfway";
            condition = QUOTE([ARR_2(this,1)] call EFUNC(common,canControlRamp));
            statement = QUOTE([ARR_2(this,1)] call FUNC(a400RampControl));
        };
        class OpenRamp : CloseRamp {
            displayName = "Open Ramp Fully";
            condition = QUOTE([ARR_2(this,2)] call EFUNC(common,canControlRamp));
            statement = QUOTE([ARR_2(this,2)] call FUNC(a400RampControl));
        };
        class open_door_crew {
            displayName = "Open Crew Door";
            position = "pos driver";
            radius = 5;
            showWindow = 0;
            onlyforplayer = 1;
            hideOnUse = 1;
            condition = "(this animationPhase ""door_crew"") < 0.5";
            statement = "this animate [""door_crew"", 1]";
        };
        class open_door_crew_pilot : open_door_crew {
            position = "pilotcontrol";
            condition = "(this animationPhase ""door_crew"") < 0.5";
        };
        class close_door_crew {
            displayName = "Close Crew Door";
            position = "pos driver";
            radius = 5;
            showWindow = 0;
            onlyforplayer = 1;
            hideOnUse = 1;
            condition = "(this animationPhase ""door_crew"") >= 0.5";
            statement = "this animate [""door_crew"", 0]";
        };
        class close_door_crew_pilot : close_door_crew {
            position = "pilotcontrol";
            condition = "(this animationPhase ""door_crew"") >= 0.5";
        };
        class DOOR_PARA_LEFT_OPEN {
            displayName = "Open Para Left Door";
            position = "pilotcontrol";
            onlyforplayer = 1;
            showWindow = 0;
            hideOnUse = 1;
            radius = 5;
            condition = "(player in this) && (this animationSourcePhase ""DOOR_PARA_LEFT"") >= 0.95";
            statement = QUOTE([ARR_3(this,'LEFT',1)] call FUNC(a400ParaDoorControl));
        };
        class DOOR_PARA_LEFT_CLOSE {
            displayName = "Close Para Left Door";
            position = "pilotcontrol";
            onlyforplayer = 1;
            showWindow = 0;
            hideOnUse = 1;
            radius = 5;
            condition = "(player in this) && (this animationSourcePhase ""DOOR_PARA_LEFT"") < 0.05";
            statement = QUOTE([ARR_3(this,'LEFT',0)] call FUNC(a400ParaDoorControl));
        };
        class DOOR_PARA_RIGHT_OPEN {
            displayName = "Open Para Right Door";
            position = "pilotcontrol";
            onlyforplayer = 1;
            showWindow = 0;
            hideOnUse = 1;
            radius = 5;
            condition = "(player in this) && (this animationSourcePhase ""DOOR_PARA_RIGHT"") >= 0.95";
            statement = QUOTE([ARR_3(this,'RIGHT',1)] call FUNC(a400ParaDoorControl));
        };
        class DOOR_PARA_RIGHT_CLOSE {
            displayName = "Close Para Right Door";
            position = "pilotcontrol";
            onlyforplayer = 1;
            showWindow = 0;
            hideOnUse = 1;
            radius = 5;
            condition = "(player in this) && (this animationSourcePhase ""DOOR_PARA_RIGHT"") < 0.05";
            statement = QUOTE([ARR_3(this,'RIGHT',0)] call FUNC(a400ParaDoorControl));
        };
    };
    #include "..\hmds\MFDA400M.hpp"
};
class B_A400M_UK_CAMO_F : A400M_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            weapons[] += { QEGVAR(weapons,C130FlareLauncher) };
            magazines[] += { QEGVAR(weapons,CMFlare_Chaff_1200Rnd_Magazine) };
            gunnerGetOutAction = "GetOutLow";
        };
        class MainTurret2 : MainTurret2 {
            gunnerGetOutAction = "GetOutLow";
        };
    };
};
class GVAR(a400m_raf) : B_A400M_UK_CAMO_F {
    faction = "CUP_B_GB";
    displayName = "A400M";
    crew = "UKSF_B_Pilot_617";
    typicalCargo[] = { "UKSF_B_Pilot_617" };
    hiddenSelectionsTextures[] = {
        "\A400M\Data\Textures\TX_ATTER.paa",
        "\A400M\Data\Textures\_TX_BOTTOM_PLAN.paa",
        QPATHTOF(data\textures\a400m\_tx_fuse_d.paa),
        QPATHTOF(data\textures\a400m\_tx_fuse_g.paa),
        "\A400M\Data\Textures\_TX_PROPULS.paa",
        "\A400M\Data\Textures\_TX_PROPULS_EXT.paa",
        "\A400M\Data\Textures\_TX_TOP_FUSE.paa",
        QPATHTOF(data\textures\a400m\_tx_wing_l.paa),
        QPATHTOF(data\textures\a400m\_tx_wing_l_b.paa),
        QPATHTOF(data\textures\a400m\_tx_wing_r.paa),
        QPATHTOF(data\textures\a400m\_tx_wing_r_b.paa)
    };
};
class PlaneWreck;
class A400M_wreck_F : PlaneWreck {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
