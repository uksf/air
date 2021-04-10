#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Set jump light state.
        Handles vehicle lights needing to be on for jump lights to show

    Parameter(s):
        0: Plane <OBJECT>
        1: New jump light state <SCALAR>
            0 = Off
            1 = Red
            2 = Green

    Return Value:
        Nothing
*/
params ["_plane", ["_newState", 0]];

private _currentState = _plane getVariable [QGVAR(jumpLightState), 0];
if (_currentState == 1 && _newState == 0) exitWith {
    [QGVAR(setJumpLightsOff), [_plane], _plane] call CBA_fnc_targetEvent;
};

if (_newState == 1) exitWith {
    [QGVAR(setJumpLightsRed), [_plane], _plane] call CBA_fnc_targetEvent;
};

if (_currentState == 1 && _newState == 2) exitWith {
    [QGVAR(setJumpLightsGreen), [_plane], _plane] call CBA_fnc_targetEvent;
};
