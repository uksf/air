#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Holds a plane still on the ground when it is meant to be stopped. Arma stops applying wheel brakes at low speed,
        so a plane that is braking or parked keeps rolling. Where the plane is local and on the ground, slower than the
        configured speed, its horizontal speed is cut until it stops. When AI stop handling is enabled, an AI told to
        stop, ready, or without waypoints is held, as is an AI that creeps below 2.5 m/s for 2 seconds. An AI accelerating
        toward a destination, or already faster than the configured speed, is left alone.

    Parameter(s):
        0: Plane <OBJECT>
        Hold parameters are read from the aircraft config: maximum speed, throttle threshold,
        deceleration (zero for immediate hold), and whether AI stop handling is enabled.

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_common_fnc_parkHold
*/
#define PARK_AI_THROTTLE 0.35
#define PARK_CREEP 2.5
#define PARK_CREEP_TIME 2
#define PARK_REST 0.01

params ["_plane"];
private _settings = getArray (configOf _plane >> QGVAR(parkHold));
_settings params ["_maxSpeed", "_maxThrottle", "_deceleration", "_holdAI"];

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_maxSpeed", "_slowSince", "_maxThrottle", "_deceleration", "_holdAI"];

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
    if (_holdAI > 0 && {!isNull _driver} && {!isPlayer _driver}) then {
        private _group = group _driver;
        _stopped = currentCommand _driver == "STOP" || {unitReady _driver} || {isNull _group} || {waypoints _group isEqualTo []};
    };
    private _hold = _throttle < _maxThrottle || {_stopped};
    if (_holdAI > 0 && {!_hold} && {!isNull _driver} && {!isPlayer _driver}) then {
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

    if (_holdAI > 0) then {
        _plane setAirplaneThrottle -1;
        if (!isNull _driver) then {
            _driver forceSpeed 0;
        };
    };
    private _scale = if (_deceleration > 0) then {0 max (1 - _deceleration * diag_deltaTime / _horizontal)} else {0};
    _plane setVelocity [(_velocity select 0) * _scale, (_velocity select 1) * _scale, _velocity select 2];
}, 0, [_plane, _maxSpeed, -1, _maxThrottle, _deceleration, _holdAI]] call CBA_fnc_addPerFrameHandler;
