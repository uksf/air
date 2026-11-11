#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(correctPilotPylon), {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;
["ace_rearm_loadoutChanged", {call FUNC(correctPilotPylon)}] call CBA_fnc_addEventHandler;
["Air", "InitPost", {
    params ["_vehicle"];
    if (_vehicle getVariable [QGVAR(pylonHandler), false]) exitWith {};
    _vehicle setVariable [QGVAR(pylonHandler), true];
    _vehicle addEventHandler ["PylonChanged", {
        params ["_vehicle"];
        if (_vehicle getVariable [QGVAR(correctingPylons), false] || {_vehicle getVariable [QGVAR(pylonPending), false]}) exitWith {};
        _vehicle setVariable [QGVAR(pylonPending), true];
        [{
            params ["_vehicle"];
            _vehicle setVariable [QGVAR(pylonPending), false];
            if (local _vehicle) then {
                [_vehicle] call FUNC(correctPilotPylon);
            };
        }, [_vehicle]] call CBA_fnc_execNextFrame;
    }];
}, true, nil, true] call CBA_fnc_addClassEventHandler;


ADDON = true;
