#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Reheat as the top of the throttle range, not a toggle. Above THROTTLE_ENGAGE it adds thrust
        scaled by throttle and airspeed, burns extra fuel, and shows the reheat flames.
        Runs every frame where the plane is local.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_afterburner
*/
#define HIT_ENGINE "HitEngine"
#define THROTTLE_ENGAGE 0.9
#define THROTTLE_MULTIPLIER 10
// Reheat fades out between these speeds (km/h); the Typhoon is still accelerating well past Mach 1.
#define SPEED_UPPER_MIN 1700
#define SPEED_UPPER_OFFSET 700
#define SPEED_LOWER_OFFSET 150
// Two EJ200s gain roughly half again their dry thrust in reheat, more than the F-35's single engine.
#define FORCE 800
#define FUEL_USAGE 0.0005

params ["_plane"];

private _throttle = airplaneThrottle _plane;
private _engaged = _plane getVariable [QGVAR(afterburnerEngaged), false];
if (!isEngineOn _plane || {_throttle < THROTTLE_ENGAGE} || {_plane getHitPointDamage HIT_ENGINE > 0.8} || {fuel _plane <= 0}) exitWith {
    if (_engaged) then {
        _plane setVariable [QGVAR(afterburnerEngaged), false];
        [_plane, false] call FUNC(afterburnerVisuals);
    };
};

if (!_engaged) then {
    _plane setVariable [QGVAR(afterburnerEngaged), true];
    _plane setVariable [QGVAR(afterburnerFuelTick), time + 1];
    [_plane, true] call FUNC(afterburnerVisuals);
};

private _throttleMultiplier = (_throttle - THROTTLE_ENGAGE) * THROTTLE_MULTIPLIER;
private _speed = (speed _plane) max 1;
private _speedMultiplier = 1;
if (_speed < SPEED_LOWER_OFFSET) then {
    _speedMultiplier = _speed / SPEED_LOWER_OFFSET;
};
if (_speed > SPEED_UPPER_MIN) then {
    _speedMultiplier = (1 - ((_speed - SPEED_UPPER_MIN) / SPEED_UPPER_OFFSET)) max 0;
};

private _force = FORCE * _throttleMultiplier * _speedMultiplier;
_plane addForce [_plane vectorModelToWorld [0, _force, 0], getCenterOfMass _plane];

if (time > (_plane getVariable [QGVAR(afterburnerFuelTick), 0])) then {
    _plane setVariable [QGVAR(afterburnerFuelTick), time + 1];
    private _fuelUsage = linearConversion [THROTTLE_ENGAGE, 1, _throttle, 0.0001, FUEL_USAGE, true];
    _plane setFuel ((fuel _plane - _fuelUsage) max 0);
};
