// Litening pod camera: EAWS limits, F-35 zoom levels.
#include "PilotCamera.hpp"

// F-35 helmet display, hidden while the pilot looks through the Typhoon's own HUD.
class MFD : MFD {
    // The EAWS glass HUD and cockpit displays, declared ahead of the HMD.
    class HUD : HUD {};
    class MFD_LH : MFD_LH {};
    class MFD_RH : MFD_RH {};
// user40 is HMD_USER_VALUE, set by fnc_hmdVisibility.
#define HMD_DRAW_CONDITION "on*(user40>0.5)"
#include "\u\uksf_air\addons\f35\hmd\hmd.hpp"
};

icon = "\EAWS_EF2000\data\ico\ico.paa";
picture = "\EAWS_EF2000\data\ico\pic.paa";

tailHook = 0;
CatapultExclude = 1;
LESH_canBeTowed = 0;
LESH_towFromFront = 1;
LESH_AxisOffsetTarget[] = { 0, 8, -0.7 }; // ahead of the nose, at the land-contact height
LESH_WheelOffset[] = { 0, -1 };
EGVAR(common,towbarOffset)[] = { 0, 0, -0.05 };
EGVAR(common,towbarRotation)[] = { 0, 1, 0 };
EGVAR(common,towbarActionMemoryPoint) = "wheel_1_axis";

UGVAR(radios,rackChannels)[] = { 31, 40, 41 };
#include "\u\uksf_air\addons\radios\racks.hpp"
RACKS_AIR;

AAE_Have_AB = 0;
AAE_Alarm_Int = "AAE_Alarm";
AAE_Rumble_Int = "AAE_Rumble";
AAE_GBreathe = "AAE_GBreathe";
AAE_GBreathe_Hold = "AAE_GBreathe_Hold";
AAE_AB_Sound = "AAE_AB_Active";
Taxiing = "AAE_RumbleG";
AAE_Touchdown_Int = "TouchDown_Int";
AAE_Touchdown_Ext[] = { "MG8\AVDAVFX\snd\touchdown.ogg", 1, 1, 1500 };
AAE_WheelsContact[] = { "wheel_1_contact", "wheel_2_contact", "wheel_3_contact" };
#include "AAE.hpp"
