#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(correctPilotPylon), {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;
["ace_rearm_loadoutChanged", {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;

["Air", "init", {(_this#0) call FUNC(reorderWeapons)}, true, nil, true] call CBA_fnc_addClassEventHandler;
["ace_pylons_setPylonLoadOutEvent", {
    params ["_vehicle"];
    [_vehicle] call FUNC(reorderWeapons);
}] call CBA_fnc_addEventHandler;

ADDON = true;
