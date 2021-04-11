#define DEBUG_SYNCHRONOUS

#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\cba\addons\xeh\script_xeh.hpp"

#ifdef DISABLE_COMPILE_CACHE
    #undef PREP
    #define PREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
    #undef PREP
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif

#define ARR_12(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12
#define ARR_14(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14
#define ARR_16(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14,ARG15,ARG16) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16
#define ARR_17(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14,ARG15,ARG16,ARG17) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16, ARG17

#define INVENTORY_EMPTY delete TransportMagazines; \
    delete TransportItems; \
    delete TransportWeapons; \
    delete TransportBackpacks

#define RESET_INVENTORY(CLASS,BASE) class CLASS : BASE { \
    INVENTORY_EMPTY; \
}

#define INVENTORY_AIRCRAFT class TransportMagazines { \
    MACRO_ADDMAGAZINE(ACE_M14,2); \
    MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2); \
    MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2); \
    MACRO_ADDMAGAZINE(B_IR_Grenade,2); \
}; \
class TransportItems { \
    MACRO_ADDITEM(Toolkit,1); \
    MACRO_ADDITEM(ACE_elasticBandage,4); \
    MACRO_ADDITEM(ACE_packingBandage,4); \
    MACRO_ADDITEM(ACE_morphine,4); \
    MACRO_ADDITEM(ACE_painkillers,4); \
}; \
class TransportBackpacks { \
    MACRO_ADDBACKPACK(B_Parachute,6); \
}; \
class TransportWeapons {}
