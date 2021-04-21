class RscControlsGroup;
class RscText;
class RscPicture;
class RscInGameUI {
    class RscUnitInfo;
    class RscOptics_UAV_reaper_gunner : RscUnitInfo {
        onLoad = "[""onLoad"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay');";
        onUnload = "[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay')";
        idd = 300;
        controls[] = { "CA_IGUI_elements_group" };
        class VScrollbar;
        class HScrollbar;
        class CA_IGUI_elements_group : RscControlsGroup {
            idc = 170;
            class VScrollbar : VScrollbar {
                width = 0;
            };
            class HScrollbar : HScrollbar {
                height = 0;
            };
            x = "safezoneX";
            y = "safezoneY";
            h = "safeZoneH";
            w = "safeZoneW";
            class controls {
                class slant_tgt_e : RscText {
                    idc = 1033;
                    style = 1;
                    shadow = 2;
                    font = "RobotoCondensed";
                    text = "12345M+";
                    x = "0.9075 * safezoneW";
                    y = "0.803 * safezoneH";
                    w = "0.0773437 * safezoneW";
                    h = "0.033 * safezoneH";
                    sizeEx = "0.04*SafezoneH";
                };
                class TgT_Grid_text : slant_tgt_e {
                    idc = 1005;
                    style = 2;
                    text = "TGT  A";
                    x = "0.889144 * safeZoneW";
                    y = "0.6424 * safeZoneH";
                    w = "0.0515625 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class TGT_MGRS : slant_tgt_e {
                    idc = 1021;
                    text = "30U";
                    x = "0.847894 * safeZoneW";
                    y = "0.6666 * safeZoneH";
                    w = "0.0360937 * safezoneW";
                    h = "0.0418 * safezoneH";
                };
                class TGT_MGRS2 : slant_tgt_e {
                    idc = 1022;
                    style = 2;
                    text = "WB";
                    x = "0.888731 * safeZoneW";
                    y = "0.66506 * safeZoneH";
                    w = "0.0360937 * safezoneW";
                    h = "0.044 * safezoneH";
                };
                class TGT_ValueGrid : slant_tgt_e {
                    idc = 1006;
                    style = 1;
                    text = "12345+";
                    x = "0.917813 * safeZoneW";
                    y = "0.671 * safeZoneH";
                    w = "0.0670311 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class TGT_ValueGrid2 : slant_tgt_e {
                    idc = 1007;
                    style = 1;
                    text = "12345+";
                    x = "0.917813 * safeZoneW";
                    y = "0.704 * safeZoneH";
                    w = "0.0670311 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class ELV_TGT : slant_tgt_e {
                    idc = 1024;
                    style = 0;
                    text = "ELV";
                    x = "0.840469 * safezoneW";
                    y = "0.737 * safezoneH";
                    w = "0.04125 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class TGT_BEARING : slant_tgt_e {
                    idc = 1025;
                    style = 0;
                    text = "BRG";
                    x = "0.840469 * safezoneW";
                    y = "0.77 * safezoneH";
                    w = "0.04125 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class slant_range : slant_tgt_e {
                    idc = 1026;
                    style = 0;
                    text = "SLR";
                    x = "0.840469 * safezoneW";
                    y = "0.803 * safezoneH";
                    w = "0.04125 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class ground_range : slant_tgt_e {
                    idc = 1027;
                    style = 0;
                    text = "GDR";
                    x = "0.840469 * safezoneW";
                    y = "0.836 * safezoneH";
                    w = "0.04125 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class d_l_r : slant_tgt_e {
                    idc = 1027;
                    style = 0;
                    text = "FVW";
                    x = "0.840469 * safezoneW";
                    y = "0.869 * safezoneH";
                    w = "0.04125 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class d_t_b : slant_tgt_e {
                    idc = 1027;
                    style = 0;
                    text = "FVH";
                    x = "0.840469 * safezoneW";
                    y = "0.902 * safezoneH";
                    w = "0.04125 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class ELV_TGT_E : slant_tgt_e {
                    idc = 1039;
                    style = 1;
                    text = "223+";
                    x = "0.9075 * safezoneW";
                    y = "0.737 * safezoneH";
                    w = "0.0773437 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class BRG_TGT_E : slant_tgt_e {
                    idc = 1034;
                    style = 1;
                    text = "12345M";
                    x = "0.915144 * safeZoneW";
                    y = "0.77 * safezoneH";
                    w = "0.061875 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class ground_range_e : slant_tgt_e {
                    idc = 1035;
                    style = 1;
                    text = "12345M+";
                    x = "0.9075 * safezoneW";
                    y = "0.836 * safezoneH";
                    w = "0.0773437 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class d_l_r_e : slant_tgt_e {
                    idc = 1036;
                    style = 1;
                    text = "12345M+";
                    x = "0.9075 * safezoneW";
                    y = "0.869 * safezoneH";
                    w = "0.0773437 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class d_t_b_e : slant_tgt_e {
                    idc = 1037;
                    style = 1;
                    text = "12345M+";
                    x = "0.9075 * safezoneW";
                    y = "0.902 * safezoneH";
                    w = "0.0773437 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class CA_Alt : slant_tgt_e {
                    idc = 1046;
                    style = 1;
                    text = "23825";
                    x = "0.881562 * safezoneW";
                    y = "0.236 * safezoneH";
                    w = "0.061875 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class CA_VisionMode : slant_tgt_e {
                    idc = 154;
                    style = 0;
                    text = "WIDE";
                    x = "0.0165 * safezoneW";
                    y = "0.1716 * safezoneH";
                    w = "0.0464063 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class FlirMode : slant_tgt_e {
                    idc = 1047;
                    style = 0;
                    x = "0.0165 * safezoneW";
                    y = "0.2046 * safezoneH";
                    w = "0.078375 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class CA_Laser : slant_tgt_e {
                    idc = 158;
                    style = 2;
                    text = "";
                    x = 0;
                    y = 0;
                    w = 0;
                    h = 0;
                    colorText[] = { 0, 0, 0, 0 };
                };
                class CA_FlirMode : slant_tgt_e {
                    idc = 153;
                    text = "";
                    x = 0;
                    y = 0;
                    w = 0;
                    h = 0;
                    colorText[] = { 0, 0, 0, 0 };
                };
                class CA_Laser_Text : slant_tgt_e {
                    idc = 1045;
                    style = 2;
                    text = "LRD LASE DES";
                    x = "0.452513 * safezoneW";
                    y = "0.22726 * safezoneH";
                    w = "0.0928143 * safezoneW";
                    h = "0.0308 * safezoneH";
                };
                class CA_Laser_Box : RscPicture {
                    idc = 1044;
                    text = QPATHTOF(data\square_CA.paa);
                    x = "0.452512 * safezoneW";
                    y = "0.22726 * safezoneH";
                    w = "0.0938454 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class CA_Heading : slant_tgt_e {
                    idc = 1038;
                    style = 2;
                    text = "555";
                    x = "0.483863 * safeZoneW";
                    y = "0.0968 * safeZoneH";
                    w = "0.0315 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class CA_Heading_Box : RscPicture {
                    idc = 1030;
                    text = QPATHTOF(data\heading_box_CA.paa);
                    x = "0.485925 * safezoneW";
                    y = "0.1001 * safezoneH";
                    w = "0.0278437 * safezoneW";
                    h = "0.03905 * safezoneH";
                };
                class MagneticHeadingTxt : slant_tgt_e {
                    idc = 1012;
                    style = 2;
                    text = "M";
                    x = "0.510675 * safeZoneW";
                    y = "0.0968 * safeZoneH";
                    w = "0.0185627 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class turretBearingTape : RscPicture {
                    idc = 1013;
                    text = QPATHTOF(data\sensoraz.paa);
                    x = "0.3993 * safeZoneW";
                    y = "0.1408 * safeZoneH";
                    w = "0.203156 * safezoneW";
                    h = "0.0352 * safezoneH";
                };
                class turretState : slant_tgt_e {
                    idc = 1003;
                    style = 0;
                    text = "RATE";
                    x = "0.0165 * safezoneW";
                    y = "0.2376 * safezoneH";
                    w = "0.0464063 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class birghtnesscontrast : slant_tgt_e {
                    idc = 1014;
                    style = 0;
                    text = "";
                    x = "0.0165 * safezoneW";
                    y = "0.2706 * safezoneH";
                    w = "0.0825 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class temperature : slant_tgt_e {
                    idc = 1016;
                    style = 1;
                    text = "15C";
                    x = "0.032225 * safezoneW";
                    y = "0.33654 * safezoneH";
                    w = "0.0464063 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class turretElevationTape : RscPicture {
                    idc = 1017;
                    text = QPATHTOF(data\sensorelev.paa);
                    x = "0.0641437 * safezoneW";
                    y = "0.40436 * safezoneH";
                    w = "0.0154686 * safezoneW";
                    h = "0.3056 * safezoneH";
                };
                class lasercode : slant_tgt_e {
                    idc = 1015;
                    style = 0;
                    text = "1111";
                    x = "0.020625 * safezoneW";
                    y = "0.902 * safezoneH";
                    w = "0.0443438 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class armlaser : slant_tgt_e {
                    idc = 1001;
                    style = 0;
                    text = "ARM LRD";
                    x = "0.020625 * safezoneW";
                    y = "0.869 * safezoneH";
                    w = "0.0825 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class 60h : slant_tgt_e {
                    idc = 1018;
                    style = 1;
                    text = "60";
                    x = "0.0342375 * safezoneW";
                    y = "0.3894 * safezoneH";
                    w = "0.0257812 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class 0h : slant_tgt_e {
                    idc = 1019;
                    style = 1;
                    text = "0";
                    x = "0.0435187 * safezoneW";
                    y = "0.4928 * safezoneH";
                    w = "0.0154689 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class 120nh : slant_tgt_e {
                    idc = 1020;
                    style = 1;
                    text = "-120";
                    x = "0.0159842 * safezoneW";
                    y = "0.6886 * safezoneH";
                    w = "0.044125 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class HAT : slant_tgt_e {
                    idc = 1030;
                    text = "HAT";
                    x = "0.943438 * safezoneW";
                    y = "0.236 * safezoneH";
                    w = "0.0360937 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class OWN_Grid_text : slant_tgt_e {
                    idc = 1005;
                    style = 2;
                    text = "ACFT";
                    x = "0.894914 * safezoneW";
                    y = "0.13926 * safezoneH";
                    w = "0.0464063 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class OWN_MGRS : slant_tgt_e {
                    idc = 1028;
                    text = "30U";
                    x = "0.869235 * safezoneW";
                    y = "0.17226 * safezoneH";
                    w = "0.0309375 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class OWN_MGRS2 : slant_tgt_e {
                    idc = 1029;
                    style = 2;
                    text = "WB";
                    x = "0.903164 * safezoneW";
                    y = "0.17226 * safezoneH";
                    w = "0.0319688 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class OWN_ValueGrid : slant_tgt_e {
                    idc = 1031;
                    style = 1;
                    text = "12345";
                    x = "0.927968 * safezoneW";
                    y = "0.17226 * safezoneH";
                    w = "0.0515625 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class OWN_ValueGrid2 : slant_tgt_e {
                    idc = 1032;
                    style = 1;
                    text = "12345";
                    x = "0.929 * safezoneW";
                    y = "0.2074 * safezoneH";
                    w = "0.0515625 * safezoneW";
                    h = "0.033 * safezoneH";
                };
                class turretElevCarrot : RscPicture {
                    idc = 1040;
                    text = QPATHTOF(data\carrotL.paa);
                    x = "0.0876563 * safezoneW";
                    y = "0.4884 * safezoneH";
                    w = "0.0185625 * safezoneW";
                    h = "0.0352 * safezoneH";
                };
                class turretElevNum : slant_tgt_e {
                    idc = 1041;
                    style = 0;
                    text = "-120";
                    x = "0.0959063 * safezoneW";
                    y = "0.4884 * safezoneH";
                    w = "0.0309379 * safezoneW";
                    h = "0.0352 * safezoneH";
                };
                class turretHeadingCarrot : RscPicture {
                    idc = 1042;
                    text = QPATHTOF(data\carrotU.paa);
                    x = "0.493969 * safezoneW";
                    y = "0.176 * safezoneH";
                    w = "0.0134065 * safezoneW";
                    h = "0.0264 * safezoneH";
                };
                class turretHeadingNum : slant_tgt_e {
                    idc = 1043;
                    style = 2;
                    text = "-180";
                    x = "0.484687 * safezoneW";
                    y = "0.1936 * safezoneH";
                    w = "0.0309379 * safezoneW";
                    h = "0.0352 * safezoneH";
                };
                class compassNPicture : slant_tgt_e {
                    idc = 1300;
                    text = "N";
                    x = "0.491234 * safezoneW";
                    y = "0.148 * safezoneH";
                    w = "0.0154688 * safezoneW";
                    h = "0.022 * safezoneH";
                };
            };
        };
    };
};
