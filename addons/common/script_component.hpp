#define COMPONENT common
#define COMPONENT_BEAUTIFIED Common
#include "\u\uksf_air\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf_air\addons\main\script_macros.hpp"

#define VERSION_CONFIG_COMMON VERSION_CONFIG; \
    versionDesc = "UKSF Air"; \
    versionAct = QUOTE(call COMPILE_FILE(init_versionTooltip))

#define STATIC_LINE_MINIMUM_ALTITUDE 80
