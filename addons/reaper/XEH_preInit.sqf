#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(handlerUav) = -1;

[QGVAR(raf), "init", {call FUNC(init)}, true] call CBA_fnc_addClassEventHandler;

[QGVAR(flyInHeightASL), {_this#0 flyInHeightASL _this#1}] call CBA_fnc_addEventHandler;
[QGVAR(forceSpeed), {_this#0 forceSpeed _this#1}] call CBA_fnc_addEventHandler;

ADDON = true;
