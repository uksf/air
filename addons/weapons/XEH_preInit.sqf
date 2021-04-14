#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(correctPilotPylon), {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;
["ace_rearm_loadoutChanged", {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;

ADDON = true;
