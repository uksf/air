#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// #include "initSettings.sqf"

GVAR(paradropInProgress) = false;

["Plane", "init", {_this#0 setVariable ["itc_air_systems", ["AUTOPILOT"], true]}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "init", {call FUNC(addAttachTowbarActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "init", {call FUNC(addStaticLineActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
