#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame (0.1s tick) render of the SENS panel extension. Reads the
        player vehicle's activeThreats hashmap, prunes entries whose missile
        is dead, retargeted off this aircraft (ACE guidance variable or
        velocity vector pointing away), or whose TTL has expired.

        The background colour is the primary threat signal — colour-coded per
        active source mix (RDR=red, IR=amber, both=orange). The text label
        is plain white for contrast against any of those colours. Background
        alpha pulses 0.7 / 0.15 on a 300ms on/off blink to draw the eye
        without fully occluding the SENS panel underneath.

    Parameter(s):
        0: Structured-text control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_sourcesCtrl] call uksf_air_common_fnc_renderSensorPanel
*/
#define BLINK_PERIOD 0.6

params ["_sourcesCtrl"];

private _vehicle = vehicle player;
if (_vehicle isEqualTo player) exitWith {
    _sourcesCtrl ctrlSetStructuredText parseText "";
    _sourcesCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
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
    _sourcesCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
};

private _blinkOn = ((CBA_missionTime / (BLINK_PERIOD / 2)) mod 2) < 1;

private _bgColour = switch (true) do {
    case (_hasRDR && _hasIR): { [0.85, 0.35, 0, 0] };  // orange
    case (_hasRDR):           { [0.7,  0.05, 0.05, 0] };  // red
    case (_hasIR):            { [0.9,  0.6,  0, 0] };  // amber
    default { [0, 0, 0, 0] };
};
_bgColour set [3, [0.15, 0.7] select _blinkOn];

private _parts = [];
if (_hasRDR) then { _parts pushBack "RDR" };
if (_hasIR) then { _parts pushBack "IR" };

_sourcesCtrl ctrlSetStructuredText parseText format ["<t align='center' color='#FFFFFFFF'>%1</t>", _parts joinString " "];
_sourcesCtrl ctrlSetBackgroundColor _bgColour;
