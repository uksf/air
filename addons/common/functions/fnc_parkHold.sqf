#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Holds a plane still on the ground when it is meant to be stopped. Arma stops applying wheel brakes at low speed,
        so a plane that is braking or parked keeps rolling. Where the plane is local and on the ground, slower than the
        given speed, its horizontal speed is cut until it stops. A player is held only below 0.02 throttle. An AI told to
        stop, ready, or without waypoints is held, as is an AI that creeps below 2.5 m/s for 2 seconds. An AI accelerating
        toward a destination, or already faster than the given speed, is left alone.

    Parameter(s):
        0: Plane <OBJECT>
        1: Speed below which the hold works, m/s <NUMBER> (default: 6)

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_common_fnc_parkHold
*/
#define PARK_THROTTLE 0.02
#define PARK_AI_THROTTLE 0.35
#define PARK_CREEP 2.5
#define PARK_CREEP_TIME 2
#define PARK_DECELERATION 2
#define PARK_REST 0.01

params ["_plane", ["_maxSpeed", 6]];

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_maxSpeed", "_slowSince"];

    if (!alive _plane) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (!local _plane || {!isTouchingGround _plane}) exitWith {
        _args set [2, -1];
    };

    private _velocity = velocity _plane;
    private _horizontal = vectorMagnitude [_velocity select 0, _velocity select 1, 0];
    private _driver = driver _plane;
    private _throttle = airplaneThrottle _plane;
    private _stopped = false;
    if (!isNull _driver && {!isPlayer _driver}) then {
        private _group = group _driver;
        _stopped = currentCommand _driver == "STOP" || {unitReady _driver} || {isNull _group} || {waypoints _group isEqualTo []};
    };
    private _hold = _throttle < PARK_THROTTLE || {_stopped};
    if (!_hold && {!isNull _driver} && {!isPlayer _driver}) then {
        private _creeping = _horizontal < PARK_CREEP && {_throttle < PARK_AI_THROTTLE};
        if (_creeping) then {
            if (_slowSince < 0) then {
                _slowSince = time;
                _args set [2, _slowSince];
            };
        } else {
            _slowSince = -1;
            _args set [2, -1];
        };
        _hold = _slowSince >= 0 && {time - _slowSince > PARK_CREEP_TIME};
    };

    if (!_hold || {_horizontal < PARK_REST} || {_horizontal > _maxSpeed}) exitWith {};

    _plane setAirplaneThrottle -1;
    if (!isNull _driver) then {
        _driver forceSpeed 0;
    };
    private _scale = 0 max (1 - PARK_DECELERATION * diag_deltaTime / _horizontal);
    _plane setVelocity [(_velocity select 0) * _scale, (_velocity select 1) * _scale, _velocity select 2];
}, 0, [_plane, _maxSpeed, -1]] call CBA_fnc_addPerFrameHandler;
