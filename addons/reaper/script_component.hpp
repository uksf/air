#define COMPONENT reaper
#define COMPONENT_BEAUTIFIED Reaper
#include "\u\uksf_air\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf_air\addons\main\script_macros.hpp"

#define MULTIPLIER_FEET 3.28084
#define FEET_TO_METERS(var) var / MULTIPLIER_FEET
#define METERS_TO_FEET(var) var * MULTIPLIER_FEET

// Gunner display defines
#define TGT_DIST_P 1033
#define TGT_GRID_1 1006
#define TGT_GRID_2 1007
#define TGT_MGRS_1 1021
#define TGT_MGRS_2 1022
#define TGT_ELEV 1039
#define TGT_BEARING 1034
#define TGT_DIST_2D 1035
#define VIEW_L_R 1036
#define VIEW_T_B 1037
#define OWN_ALT 1046
#define OPTIC_FOV 154
#define VISION_MODE 1047
#define LASER_FIRE 158
#define LASER_BOX 1044
#define LASER_TEXT 1045
#define LASER_BOX_CLASSNAME "CA_Laser_Box"
#define LASER_TEXT_CLASSNAME "CA_Laser_Text"
#define OWN_BEARING 1038
#define OWN_MGRS_1 1028
#define OWN_MGRS_2 1029
#define OWN_GRID_1 1031
#define OWN_GRID_2 1032
#define BRIGHT_CONT 1014
#define LASER_CODE 1015
#define TEMP 1016
#define TURRET_EZ_TXT 1041
#define TURRET_EZ_CARET 1040
#define TURRET_AZ_TXT 1043
#define TURRET_AZ_CARET 1042
#define TURRET_AZ_BEG 0.39257 * safeZoneW
#define TURRET_AZ_DIS 0.203156 * safezoneW
#define TURRET_AZ_NUM_OFFSET (-0.009 * safeZoneW)
#define TURRET_EZ_BEG 0.386 * safezoneH
#define TURRET_EZ_DIS 0.3056 * safezoneH
#define VANILLA_VISION_ARR ["DTV","NV","FLIR"]
