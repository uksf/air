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

#define UGVAR(var1,var2) TRIPLES(uksf,var1,var2)
#define QUGVAR(var1,var2) QUOTE(UGVAR(var1,var2))
#define QQUGVAR(var1,var2) QUOTE(QUGVAR(var1,var2))

#define UFUNC(var1,var2) TRIPLES(DOUBLES(uksf,var1),fnc,var2)
#define QUFUNC(var1,var2) QUOTE(UFUNC(var1,var2))
#define QQUFUNC(var1,var2) QUOTE(QUFUNC(var1,var2))

#define ARR_12(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12
#define ARR_14(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14
#define ARR_16(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14,ARG15,ARG16) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16
#define ARR_17(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14,ARG15,ARG16,ARG17) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16, ARG17

#ifdef DEBUG_MODE_FULL
    #define DEBUG(MESSAGE) LOG_SYS_FILELINENUMBERS('DEBUG',MESSAGE)
    #define DEBUG_1(MESSAGE,ARG1) DEBUG(FORMAT_1(MESSAGE,ARG1))
    #define DEBUG_2(MESSAGE,ARG1,ARG2) DEBUG(FORMAT_2(MESSAGE,ARG1,ARG2))
    #define DEBUG_3(MESSAGE,ARG1,ARG2,ARG3) DEBUG(FORMAT_3(MESSAGE,ARG1,ARG2,ARG3))
    #define DEBUG_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) DEBUG(FORMAT_4(MESSAGE,ARG1,ARG2,ARG3,ARG4))
    #define DEBUG_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) DEBUG(FORMAT_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5))
    #define DEBUG_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) DEBUG(FORMAT_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6))
    #define DEBUG_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) DEBUG(FORMAT_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7))
    #define DEBUG_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) DEBUG(FORMAT_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8))
#else
    #define DEBUG(MESSAGE) /* disabled */
    #define DEBUG_1(MESSAGE,ARG1) /* disabled */
    #define DEBUG_2(MESSAGE,ARG1,ARG2) /* disabled */
    #define DEBUG_3(MESSAGE,ARG1,ARG2,ARG3) /* disabled */
    #define DEBUG_4(MESSAGE,ARG1,ARG2,ARG3,ARG4) /* disabled */
    #define DEBUG_5(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5) /* disabled */
    #define DEBUG_6(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6) /* disabled */
    #define DEBUG_7(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7) /* disabled */
    #define DEBUG_8(MESSAGE,ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8) /* disabled */
#endif

#define ALL_PLAYERS (allPlayers - entities "HeadlessClient_F")

#define MACRO_ADDWEAPON(WEAPON,COUNT) class _xx_##WEAPON { \
    weapon = #WEAPON; \
    count = COUNT; \
}
#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
}
#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
    magazine = #MAGAZINE; \
    count = COUNT; \
}
#define MACRO_ADDBACKPACK(BACKPACK,COUNT) class _xx_##BACKPACK { \
    backpack = #BACKPACK; \
    count = COUNT; \
}
#define MACRO_ADDACECARGO(CARGO,COUNT) class CARGO { \
    type = #CARGO; \
    amount = COUNT; \
}

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
class TransportBackpacks {}; \
class TransportWeapons {}

#define DEPRECATE_CLASS(CLASS,BASE) class CLASS : BASE { \
    scope = 1; \
    scopeCurator = 0; \
    class Attributes { \
        class GVAR(deprecated) { \
            property = QGVAR(deprecated); \
            control = "Checkbox"; \
            displayName = QUOTE(Deprecated by 'BASE'); \
            tooltip = QUOTE(This object has been deprecated. Use 'BASE' instead.); \
            expression = "'BASE'"; \
            typeName = "BOOL"; \
            condition = "objectVehicle"; \
            defaultValue = 1; \
        }; \
    }; \
}

#define DEPRECATE_CLASS_WITH_BASE(CLASS,BASE) class BASE; \
DEPRECATE_CLASS(CLASS,BASE)

#define HIDE \
    scope = 0; \
    scopeCurator = 0

#define HIDE_CLASS(CLASS,BASE) class CLASS : BASE { \
    HIDE; \
}

#define HIDE_CLASS_WITH_BASE(CLASS,BASE) class BASE; \
HIDE_CLASS(CLASS,BASE)

#define PREVIEW(NAME) editorPreview = QPATHTOF(data\previews\GVAR(NAME).jpg)

#define FUEL(capacity,flightTime) fuelCapacity = capacity; \
ace_refuel_fuelCapacity = capacity; \
fuelConsumptionRate = capacity / (flightTime * 60)
