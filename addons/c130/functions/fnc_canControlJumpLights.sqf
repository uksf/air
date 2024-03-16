#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if jump lights can be controlled from the current position

    Parameter(s):
        0: Plane <OBJECT>
        1: New jump light state <SCALAR>
            0 = Off
            1 = Red
            2 = Green
            Can only transition to green from red, and to off from red

    Return Value:
        True if jump light control possible <BOOLEAN>
*/
params ["_plane", ["_newState", 0]];

private _currentState = _plane getVariable [QGVAR(jumpLightState), 0];

if (_newState == 0 && _currentState != 1) exitWith {
    false
};

if (_newState == 2 && _currentState != 1) exitWith {
    false
};

_currentState != _newState
&& {[_plane] call EFUNC(common,canControl)}
