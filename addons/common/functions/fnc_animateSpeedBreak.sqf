/*
    Author:
        Tim Beswick

    Description:
        Animates speedbrake components

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane", "_newSpeedBrake"];

private _previousSpeedBrake = _plane getVariable [QGVAR(previousSpeedBrake), 0];

if (_newSpeedBrake == _previousSpeedBrake) exitWith {};

_plane setVariable [QGVAR(previousSpeedBrake), _newSpeedBrake];
_plane animateSource ["animationsource_speedBrake", _newSpeedBrake, true];
