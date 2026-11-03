#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Computes the threat state of a local aircraft from engine sensor data and publishes it when it changes.
        Radar threats only resolve on the aircraft owner, so listeners read the published state.
        Radars: [emitter vehicle, state] for every non-friendly active radar on the RWR. State 0 on the RWR only, 1 marked by it, 2 locked by it.
        Missiles: [missile, closing] for every missile guided at the aircraft. Closing compares with the last update.

    Parameters:
        0: Aircraft <OBJECT>

    Return value:
        Nothing

    Example:
        [_aircraft] call uksf_air_threatwarning_fnc_ownerUpdate
*/
params ["_aircraft"];

private _radars = [];
private _missiles = [];

if (alive _aircraft && {isEngineOn _aircraft}) then {
    private _side = side _aircraft;
    private _candidates = _aircraft getVariable [QGVAR(candidates), []];
    private _known = _candidates apply {_x#0};

    {
        _x params ["_target", "", "", "_sensors"];
        private _emitter = vehicle _target;
        if ("passiveradar" in _sensors && {(_side getFriend side _emitter) < 0.6} && {_radars findIf {_x#0 isEqualTo _emitter} isEqualTo -1}) then {
            _radars pushBack [_emitter, 0];
        };
    } forEach getSensorTargets _aircraft;

    {
        _x params ["_entity", "_state", "_sensors"];
        if (_state isEqualTo "missile") then {
            if !(_entity in _known) then {
                _candidates pushBack [_entity, CBA_missionTime, _entity distance _aircraft];
                _known pushBack _entity;
            };
            continue;
        };
        private _emitter = vehicle _entity;
        if (!("radar" in _sensors) || {(_side getFriend side _emitter) >= 0.6}) then {continue};
        private _level = [1, 2] select (_state isEqualTo "locked");
        private _index = _radars findIf {_x#0 isEqualTo _emitter};
        if (_index isEqualTo -1) then {
            _radars pushBack [_emitter, _level];
        } else {
            (_radars select _index) set [1, _level max (_radars#_index#1)];
        };
    } forEach getSensorThreats _aircraft;

    private _scan = (_aircraft getVariable [QGVAR(scan), 0]) + 1;
    _aircraft setVariable [QGVAR(scan), _scan];
    if (_scan mod 4 isEqualTo 0) then {
        {
            if (missileTarget _x isEqualTo _aircraft && {!(_x in _known)}) then {
                _candidates pushBack [_x, CBA_missionTime, _x distance _aircraft];
            };
        } forEach (_aircraft nearObjects ["MissileBase", SCAN_RADIUS]);
    };

    _candidates = _candidates select {
        _x params ["_missile", "_added"];
        private _target = missileTarget _missile;
        alive _missile && {_target isEqualTo _aircraft || {isNull _target && {CBA_missionTime - _added < LAUNCH_GRACE}}}
    };

    {
        _x params ["_missile", "", "_lastDistance"];
        private _distance = _missile distance _aircraft;
        private _closing = _distance <= _lastDistance;
        _x set [2, _distance];
        _missiles pushBack [_missile, _closing];
    } forEach _candidates;

    _aircraft setVariable [QGVAR(candidates), _candidates];
};

if (_radars isNotEqualTo (_aircraft getVariable [QGVAR(radars), []])) then {
    _aircraft setVariable [QGVAR(radars), _radars, true];
};
if (_missiles isNotEqualTo (_aircraft getVariable [QGVAR(missiles), []])) then {
    _aircraft setVariable [QGVAR(missiles), _missiles, true];
};
