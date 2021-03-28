/*
    Author:
        Tim Beswick

    Description:
        Handle afterburner animations, effects, and speed

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

#define ANIMATION_HIDE "afterburner_hide"
#define ANIMATION_STRETCH "afterburner_stretch"
#define ANIMATION_THRUSTVECTOR "source_thrustVector"
#define HIT_ENGINE "HitEngine"
#define THROTTLE_ENGAGE 0.9
#define THROTTLE_MULTIPLIER 10
#define SPEED_UPPER_MIN 1500
#define SPEED_UPPER_OFFSET 800
#define SPEED_LOWER_OFFSET 150
#define FORCE 600
#define FUEL_USAGE 0.0002

params ["_plane"];

private _throttle = airplaneThrottle _plane;
if (!isEngineOn _plane || {_throttle < THROTTLE_ENGAGE} || {_plane getHitPointDamage HIT_ENGINE > 0.8} || {_plane animationPhase ANIMATION_THRUSTVECTOR > -1}) exitWith {
    if (_plane getVariable [QGVAR(afterburnerEngaged), false]) then {
        _plane animateSource [ANIMATION_HIDE, 0, true];
        _plane setVariable [QGVAR(afterburnerEngaged), false, true];
    };
};
if (!(_plane getVariable [QGVAR(afterburnerEngaged), false])) then {
    _plane setVariable [QGVAR(afterburnerEngaged), true, true];
    GVAR(afterburnerTick) = time + 1;
};

private _throttleMultiplier = (_throttle - THROTTLE_ENGAGE) * THROTTLE_MULTIPLIER;
private _speed = (speed _plane) max 1;
private _speedMultiplier = 1;
if (_speed < SPEED_LOWER_OFFSET) then {
    _speedMultiplier = (_speed / SPEED_LOWER_OFFSET) min 1;
};    
if (_speed > SPEED_UPPER_MIN) then {
    _speedMultiplier = 1 - ((_speed - SPEED_UPPER_MIN) / SPEED_UPPER_OFFSET);
};    

private _forceFinal = FORCE * _throttleMultiplier * _speedMultiplier;
_plane addForce [_plane vectorModelToWorld [0, abs _forceFinal, 0], getCenterOfMass _plane];

if (time > GVAR(afterburnerTick)) then {
    GVAR(afterburnerTick) = time + 1;
    private _fuelUsage = linearConversion [THROTTLE_ENGAGE, 1, _throttle, 0.00005, FUEL_USAGE];
    _plane setFuel (fuel _plane - _fuelUsage);
};

_plane animateSource [ANIMATION_HIDE, 1, true];
_plane animateSource [ANIMATION_STRETCH, _throttleMultiplier];
