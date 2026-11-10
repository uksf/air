#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Holds a plane still on the ground when it is meant to be stopped. Arma stops applying wheel brakes at low speed,
        so a plane that is braking or parked keeps rolling. Where the plane is local and on the ground, slower than the
        configured speed, its horizontal speed is cut until it stops. The hold is skipped while the aircraft is attached
        to another object, loaded as vehicle cargo, roped to another vehicle, engine-towed, or marked towed by LESH.
        When AI stop handling is enabled, an AI told to stop, ready, or without waypoints is put back at the position
        where that stop began, so engine thrust between frames cannot roll it. A current move waypoint releases that
        hold. An AI that creeps below 2.5 m/s for 2 seconds is also held. An AI already faster than the configured
        speed is left alone. A player or a taxiing AI is only slowed by the configured deceleration.

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
        if (count _args > 6) then { _args deleteAt 6 };
    };
    if (!isNull attachedTo _plane || {!isNull isVehicleCargo _plane} || {!isNull ropeAttachedTo _plane} || {!isNull getTowParent _plane} || {!isNull (_plane getVariable ["LESH_towedBy", objNull])}) exitWith {
        _args set [2, -1];
        if (count _args > 6) then { _args deleteAt 6 };
    };

    private _velocity = velocity _plane;
    private _horizontal = vectorMagnitude [_velocity select 0, _velocity select 1, 0];
    private _driver = driver _plane;
    private _throttle = airplaneThrottle _plane;
    private _stopped = false;
    if (_holdAI > 0 && {!isNull _driver} && {!isPlayer _driver}) then {
        private _group = group _driver;
        private _driving = false;
        if (!isNull _group && {waypoints _group isNotEqualTo []}) then {
            private _index = currentWaypoint _group;
            if (_index >= 0 && {_index < count waypoints _group}) then {
                _driving = (waypointType [_group, _index]) in ["MOVE", "SAD", "SCRIPTED", "GETIN", "GETOUT", "UNLOAD", "LOAD", "TR UNLOAD", "HOOK", "UNHOOK", "SUPPORT", "DESTROY"];
            };
        };
        _stopped = !_driving && {
            currentCommand _driver == "STOP" || {unitReady _driver} || {isNull _group} || {waypoints _group isEqualTo []}
        };
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

    if (_stopped && {_horizontal <= _maxSpeed}) then {
        if (count _args < 7) then {
            _args pushBack (getPosATL _plane);
        };
        _plane setAirplaneThrottle -1;
        _plane setVelocity [0, 0, 0];
        _plane setPosATL (_args select 6);
    } else {
        if (count _args > 6) then {
            _args deleteAt 6;
        };
        if (!_hold || {_horizontal < PARK_REST} || {_horizontal > _maxSpeed}) exitWith {};
        if (_holdAI > 0) then {
            _plane setAirplaneThrottle -1;
        };
        private _scale = if (_deceleration <= 0) then {
            0
        } else {
            0 max (1 - _deceleration * diag_deltaTime / _horizontal)
        };
        _plane setVelocity [(_velocity select 0) * _scale, (_velocity select 1) * _scale, _velocity select 2];
    };
}, 0, [_plane, _maxSpeed, -1, _maxThrottle, _deceleration, _holdAI]] call CBA_fnc_addPerFrameHandler;
