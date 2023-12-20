#include "script_component.hpp"
/*
    Author:
        Karel Kroonen & Tim Beswick

    Description:
        Controls drone behaviour to be changed and the altitude to be changed.

    Parameter(s):
        0: UAV <OBJECT>

    Return Value:
        Nothing
*/
params ["_uav"];

if (!local _uav) exitWith {};

_uav setVariable ["acex_headless_blacklist", true, true];
_uav setVariable ["NOAI", 1, true];
_uav setVariable [QGVAR(diveMode), false, true];
_uav setVariable [QGVAR(observationMode), true, true];
_uav setVariable [QGVAR(targetHeightASL), 5000, true];
_uav setVariable [QGVAR(customWaypoint), false, true];

[{
    params ["_uav"];

    _uav setCombatMode "BLUE";
    _uav flyInHeightASL [FEET_TO_METERS(5000), FEET_TO_METERS(5000), FEET_TO_METERS(5000)];
}, [_uav]] call CBA_fnc_execNextFrame;

