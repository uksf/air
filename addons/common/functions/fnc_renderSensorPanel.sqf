#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame (0.1s tick) render of the SENS panel extension. Reads the
        player vehicle's activeThreats hashmap, prunes entries whose missile
        is dead, retargeted off this aircraft (ACE guidance variable or
        velocity vector pointing away), or whose TTL has expired. Builds a
        single structured-text label containing "RDR" (red) and/or "IR"
        (yellow) for the active source types, with alpha driven by a 300ms
        on/off blink pattern.

    Parameter(s):
        0: Structured-text control <CONTROL>
        1: SENS background control (IDC 15110) <CONTROL>

    Return Value:
        Nothing

    Example:
        [_sourcesCtrl, _background] call uksf_air_common_fnc_renderSensorPanel
*/
#define BLINK_PERIOD 0.6

params ["_sourcesCtrl", "_background"];

private _vehicle = vehicle player;
if (_vehicle isEqualTo player) exitWith {
    _sourcesCtrl ctrlSetStructuredText parseText "";
};

// Hide if the SENS panel itself is not currently shown (player cycled to a
// different custom-info panel, or toggled the column off)
if (isNull _background || {!ctrlShown _background}) exitWith {
    _sourcesCtrl ctrlSetStructuredText parseText "";
};

private _threats = _vehicle getVariable [QGVAR(activeThreats), createHashMap];

// Prune
private _toRemove = [];
private _vehiclePosition = getPosASL _vehicle;
{
    _y params ["_source", "_expiry", "_missile"];
    if (CBA_missionTime > _expiry) then { _toRemove pushBack _x; };
    if (isNull _missile || {!alive _missile}) then { _toRemove pushBack _x; };
    if (!isNull _missile && {alive _missile}) then {
        // ACE-guided missile retargeted to something other than us
        private _aceTarget = _missile getVariable ["ace_missileguidance_target", objNull];
        if (!isNull _aceTarget && {_aceTarget isNotEqualTo _vehicle}) then {
            _toRemove pushBack _x;
        };
        // Missile velocity no longer heading toward us (covers vanilla retargets and decoy capture)
        private _toVehicle = _vehiclePosition vectorDiff (getPosASL _missile);
        if ((velocity _missile) vectorDotProduct _toVehicle <= 0) then {
            _toRemove pushBack _x;
        };
    };
} forEach _threats;

{
    _threats deleteAt _x;
} forEach _toRemove;

if (count _threats > 0) then {
    _vehicle setVariable [QGVAR(activeThreats), _threats];
};

// Aggregate
private _hasRDR = false;
private _hasIR = false;
{
    switch (_y#0) do {
        case "RDR": { _hasRDR = true; };
        case "IR": { _hasIR = true; };
    };
} forEach _threats;

if (!_hasRDR && !_hasIR) exitWith {
    _sourcesCtrl ctrlSetStructuredText parseText "";
};

private _blinkOn = ((CBA_missionTime / (BLINK_PERIOD / 2)) mod 2) < 1;
// Hex alpha for the structured-text colour tags (#AARRGGBB)
private _alphaHex = if (_blinkOn) then { "FF" } else { "4D" };

private _parts = [];
if (_hasRDR) then {
    _parts pushBack format ["<t color='#%1FF3333'>RDR</t>", _alphaHex];
};
if (_hasIR) then {
    _parts pushBack format ["<t color='#%1FFFF33'>IR</t>", _alphaHex];
};

_sourcesCtrl ctrlSetStructuredText parseText format ["<t align='center'>%1</t>", _parts joinString " "];
