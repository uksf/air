#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Computes the threat state of a local aircraft from engine sensor data and publishes it when it changes.
        Radar threats only resolve on the aircraft owner, so listeners read the published state.
        Radars: [emitter vehicle, state] for every non-friendly active radar on the RWR. State 0 on the RWR only, 1 marked by it, 2 locked by it.
        Missiles: [missile, closing] for every live missile whose shooter reported the aircraft as its target. Closing compares with the last update.

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

    {
        _x params ["_target", "", "", "_sensors"];
        private _emitter = vehicle _target;
        if ("passiveradar" in _sensors && {(_side getFriend side _emitter) < 0.6} && {_radars findIf {_x#0 isEqualTo _emitter} isEqualTo -1}) then {
            _radars pushBack [_emitter, 0];
        };
    } forEach getSensorTargets _aircraft;

    {
        _x params ["_entity", "_state", "_sensors"];
        private _emitter = vehicle _entity;
        if (_state isEqualTo "missile" || {!("radar" in _sensors)} || {(_side getFriend side _emitter) >= 0.6}) then {continue};
        private _level = [1, 2] select (_state isEqualTo "locked");
        private _index = _radars findIf {_x#0 isEqualTo _emitter};
        if (_index isEqualTo -1) then {
            _radars pushBack [_emitter, _level];
        } else {
            (_radars select _index) set [1, _level max (_radars#_index#1)];
        };
    } forEach getSensorThreats _aircraft;

    private _lastDistances = _aircraft getVariable [QGVAR(distances), []];
    private _distances = [];
    {
        _x params ["_missile", "_target"];
        if (_target isEqualTo _aircraft) then {
            private _distance = _missile distance _aircraft;
            private _last = _lastDistances findIf {_x#0 isEqualTo _missile};
            _missiles pushBack [_missile, _last isEqualTo -1 || {_distance <= _lastDistances#_last#1}];
            _distances pushBack [_missile, _distance];
        };
    } forEach GVAR(missileTargets);
    _aircraft setVariable [QGVAR(distances), _distances];
};

if (_radars isNotEqualTo (_aircraft getVariable [QGVAR(radars), []])) then {
    _aircraft setVariable [QGVAR(radars), _radars, true];
};
if (_missiles isNotEqualTo (_aircraft getVariable [QGVAR(missiles), []])) then {
    _aircraft setVariable [QGVAR(missiles), _missiles, true];
};
