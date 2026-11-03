#define COMPONENT threatwarning
#define COMPONENT_BEAUTIFIED Threat Warning
#include "\u\uksf_air\addons\main\script_mod.hpp"

#include "\u\uksf_air\addons\main\script_macros.hpp"

#define TICK_OWNER 0.25
#define TICK_LISTENER 0.1
#define SCAN_RADIUS 9000
#define LAUNCH_GRACE 2
#define RADAR_LOST_AFTER 10
#define SEARCH_PING_INTERVAL 4
#define CALL_REPEAT_INTERVAL 3
#define VOICE_LENGTH 2.15
#define DUCKED_LEVEL 0.35
#define SOUND(NAME) QPATHTOF(data\NAME.ogg)
