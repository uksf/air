#include "PilotCamera.hpp"

class Reflectors : Reflectors {
    class Left : Left {
        innerAngle = 20;
        outerAngle = 60;
    };
    class Right : Right {
        innerAngle = 20;
        outerAngle = 60;
    };
};

class MFD : MFD {
    class HUD : HUD {};
    class MFD_LH : MFD_LH {};
    class MFD_RH : MFD_RH {};
#define HMD_DRAW_CONDITION "on*(user40>0.5)"
#define HMD_NO_F35_SYMBOLS
#include "\u\uksf_air\addons\f35\hmd\hmd.hpp"
    class HmdCentreDot {
        enableParallax = 1;
        helmetMountedDisplay = 1;
        helmetPosition[] = { -0.04, 0.03, 0.1 };
        helmetRight[] = { 0.08, 0, 0 };
        helmetDown[] = { 0, -0.06, 0 };
        topLeft = "HUD LH";
        topRight = "HUD PH";
        bottomLeft = "HUD LD";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.15, 1, 0.15, 0.1 };
        class Bones {
            class PlaneW {
                type = "fixed";
                pos[] = { 0.5, 0.5 };
            };
        };
        class Draw {
            alpha = 0.4;
            color[] = { 0.15, 1, 0.15 };
            condition = "on*(user40<0.5)";
            class centerPoint {
                type = "line";
                width = 4;
                points[] = {
                    { "PlaneW", { 0, -0.0025 }, 1 },
                    { "PlaneW", { 0, 0.0025 }, 1 },
                    {},
                    { "PlaneW", { 0.002, 0 }, 1 },
                    { "PlaneW", { -0.002, 0 }, 1 },
                    {}
                };
            };
        };
    };
};

icon = "\EAWS_EF2000\data\ico\ico.paa";
picture = "\EAWS_EF2000\data\ico\pic.paa";

tailHook = 0;
CatapultExclude = 1;
LESH_canBeTowed = 0;
LESH_towFromFront = 1;
LESH_AxisOffsetTarget[] = { 0, 8, -0.7 };
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
