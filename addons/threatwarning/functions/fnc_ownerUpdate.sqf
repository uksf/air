#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Computes the threat state of a local aircraft from engine sensor data and publishes it when it changes.
        Radar threats only resolve on the aircraft owner, so listeners read the published state.
        Radars: hostile radar emitters that have the aircraft marked or locked.
        Missiles: missiles guided at the aircraft, flagged for the launch warble while radar guided and closing since the last update.

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
        _x params ["_entity", "_state", "_sensors"];
        if (_state isEqualTo "missile") then {
            if !(_entity in _known) then {
                _candidates pushBack [_entity, CBA_missionTime, _entity distance _aircraft];
                _known pushBack _entity;
            };
            continue;
        };
        if (!("radar" in _sensors) || {(_side getFriend side _entity) >= 0.6}) then {continue};
        private _locked = parseNumber (_state isEqualTo "locked");
        private _index = _radars findIf {_x#0 isEqualTo _entity};
        if (_index isEqualTo -1) then {
            _radars pushBack [_entity, _locked];
        } else {
            (_radars select _index) set [1, _locked max (_radars#_index#1)];
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
        private _ammo = typeOf _missile;
        private _radarGuided = GVAR(guidance) getOrDefaultCall [_ammo, {[_ammo] call EFUNC(common,classifyMissileGuidance) isEqualTo "RDR"}, true];
        _missiles pushBack [_missile, _radarGuided && _closing];
    } forEach _candidates;

    _aircraft setVariable [QGVAR(candidates), _candidates];
};

if (_radars isNotEqualTo (_aircraft getVariable [QGVAR(radars), []])) then {
    _aircraft setVariable [QGVAR(radars), _radars, true];
};
if (_missiles isNotEqualTo (_aircraft getVariable [QGVAR(missiles), []])) then {
    _aircraft setVariable [QGVAR(missiles), _missiles, true];
};
