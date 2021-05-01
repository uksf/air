#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// #include "initSettings.sqf"

["Air", "init", {call FUNC(addAttachTowbarActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;
["Air", "init", {call FUNC(addStaticLineActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
