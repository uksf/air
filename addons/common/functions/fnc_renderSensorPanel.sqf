#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame (0.1s tick) render of the SENS panel extension. Reads the
        player vehicle's activeThreats hashmap, prunes entries whose missile
        is dead/null or whose TTL has expired, and sets each label's alpha to
        either 0 (no threat of that type) or a blink pattern (300ms on/off)
        with full alpha on the colour set in initSensorPanelExtension.

    Parameter(s):
        0: RDR control <CONTROL>
        1: IR control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_rdrCtrl, _irCtrl] call uksf_air_common_fnc_renderSensorPanel
*/
#define BLINK_PERIOD 0.6

params ["_rdrCtrl", "_irCtrl"];

private _vehicle = vehicle player;
if (_vehicle isEqualTo player) exitWith {
    _rdrCtrl ctrlSetTextColor [1, 0.2, 0.2, 0];
    _irCtrl ctrlSetTextColor [1, 1, 0.2, 0];
};

private _threats = _vehicle getVariable [QGVAR(activeThreats), createHashMap];

// Prune
private _toRemove = [];
{
    _y params ["_source", "_expiry", "_missile"];
    if (CBA_missionTime > _expiry) then { _toRemove pushBack _x; };
    if (!isNull _missile && {!alive _missile}) then { _toRemove pushBack _x; };
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

private _blinkOn = ((CBA_missionTime / (BLINK_PERIOD / 2)) mod 2) < 1;
private _alpha = [0.3, 1.0] select _blinkOn;

private _rdrAlpha = if (_hasRDR) then { _alpha } else { 0 };
private _irAlpha = if (_hasIR) then { _alpha } else { 0 };

_rdrCtrl ctrlSetTextColor [1, 0.2, 0.2, _rdrAlpha];
_irCtrl ctrlSetTextColor [1, 1, 0.2, _irAlpha];
