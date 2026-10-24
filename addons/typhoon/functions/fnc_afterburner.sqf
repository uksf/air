#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Reheat as the top of the throttle range, not a toggle. Above THROTTLE_ENGAGE it adds thrust
        scaled by throttle and airspeed, and shows the reheat flames. fuelBurn charges the reheat fuel.
        Reheat adds about 30 kN per EJ200 (60 kN dry, 90 kN wet), so FORCE is 60 kN for the pair,
        applied as an impulse scaled by frame time. Thrust fades out between SPEED_UPPER_MIN and
        SPEED_UPPER_MIN + SPEED_UPPER_OFFSET km/h. The flames stretch with throttle in tenths, so the
        animation broadcasts only when the step changes.
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
#define SPEED_UPPER_MIN 1700
#define SPEED_UPPER_OFFSET 700
#define SPEED_LOWER_OFFSET 150
#define FORCE 60000
#define STRETCH_STEPS 10

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
    [_plane, true] call FUNC(afterburnerVisuals);
};

private _throttleMultiplier = (_throttle - THROTTLE_ENGAGE) * THROTTLE_MULTIPLIER;
private _stretch = (round (_throttleMultiplier * STRETCH_STEPS) / STRETCH_STEPS) min 1;
if (_stretch != (_plane getVariable [QGVAR(afterburnerStretch), -1])) then {
    _plane setVariable [QGVAR(afterburnerStretch), _stretch];
    _plane animateSource ["afterburner_stretch", _stretch, true];
};
private _speed = (speed _plane) max 1;
private _speedMultiplier = 1;
if (_speed < SPEED_LOWER_OFFSET) then {
    _speedMultiplier = _speed / SPEED_LOWER_OFFSET;
};
if (_speed > SPEED_UPPER_MIN) then {
    _speedMultiplier = (1 - ((_speed - SPEED_UPPER_MIN) / SPEED_UPPER_OFFSET)) max 0;
};

private _impulse = FORCE * _throttleMultiplier * _speedMultiplier * diag_deltaTime;
_plane addForce [_plane vectorModelToWorld [0, _impulse, 0], getCenterOfMass _plane];
