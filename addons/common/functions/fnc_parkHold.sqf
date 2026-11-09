#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Holds a plane still on the ground at zero throttle. Arma stops applying wheel brakes at low speed,
        so a plane that is braking or parked keeps rolling. Where the plane is local, on the ground,
        below 0.02 throttle and slower than the given speed, its horizontal speed is cut at a steady rate until it stops.

    Parameter(s):
        0: Plane <OBJECT>
        1: Speed below which the hold works, m/s <NUMBER> (default: 6)

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_common_fnc_parkHold
*/
#define PARK_THROTTLE 0.02
#define PARK_DECELERATION 2
#define PARK_REST 0.01

params ["_plane", ["_maxSpeed", 6]];

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_maxSpeed"];

    if (!alive _plane) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (!local _plane || {!isTouchingGround _plane} || {airplaneThrottle _plane >= PARK_THROTTLE}) exitWith {};

    private _velocity = velocity _plane;
    private _horizontal = vectorMagnitude [_velocity select 0, _velocity select 1, 0];
    if (_horizontal < PARK_REST || {_horizontal > _maxSpeed}) exitWith {};

    private _scale = 0 max (1 - PARK_DECELERATION * diag_deltaTime / _horizontal);
    _plane setVelocity [(_velocity select 0) * _scale, (_velocity select 1) * _scale, _velocity select 2];
}, 0, [_plane, _maxSpeed]] call CBA_fnc_addPerFrameHandler;
