/*
    Author:
        Tim Beswick

    Description:
        Animates thrustvector components

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane", "_newThrustVector", "_newSpeedBrake"];

// This is better than before, but blocks changing thrust vector with speed brake engaged
// 
// private _speedBrakeOn = _plane getVariable [QGVAR(speedBrakeOn), false];
// if (_newSpeedBrake > 0 && !_speedBrakeOn) exitWith {
//     _plane setVariable [QGVAR(speedBrakeOn), true];
// };

// if (_speedBrakeOn) exitWith {
//     if (_newThrustVector == -1) then {
//         _plane setVariable [QGVAR(speedBrakeOn), false];
//     };
// };

if (_newThrustVector > -1 && {airplaneThrottle _plane > 0.89}) then {
    _plane setAirplaneThrottle 0.89;
};

private _previousThrustVector = _plane getVariable [QGVAR(previousThrustVector), -1];
if (_newThrustVector == _previousThrustVector) exitWith {};

_plane setVariable [QGVAR(previousThrustVector), _newThrustVector];
_plane animateSource ["animationsource_thrustVector", _newThrustVector, true];
