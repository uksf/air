#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// #include "initSettings.sqf"

GVAR(paradropInProgress) = false;
GVAR(localRadarAircraft) = [];
GVAR(radarIffPFH) = -1;

["Plane", "init", {_this#0 setVariable ["itc_air_systems", ["AUTOPILOT"], true]}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "init", {call FUNC(addAttachTowbarActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "init", {call FUNC(addStaticLineActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "init", {call FUNC(initCountermeasures)}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "init", {[_this#0, local (_this#0)] call FUNC(setRadarAircraftLocal)}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "local", {call FUNC(setRadarAircraftLocal)}] call CBA_fnc_addClassEventHandler;
["Air", "incomingMissile", {call FUNC(onIncomingMissile)}] call CBA_fnc_addClassEventHandler;

ADDON = true;
