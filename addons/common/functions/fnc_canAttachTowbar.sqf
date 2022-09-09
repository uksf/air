#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if player can attach/detach towbar

    Parameter(s):
        0: Aircraft <OBJECT>
        1: New attach state <BOOLEAN>
            true = attached
            false = detached

    Return Value:
        True if can attach/detach <BOOLEAN>
*/
params ["_aircraft", "_attach"];

private _towbarConfig = configOf _aircraft >> QGVAR(towbarOffset);
if !(isArray _towbarConfig) exitWith {
    false
};

private _baseCondition = vehicle ACE_player == ACE_player
&& isNull (ACE_controlledUAV#0)
&& speed _aircraft < 1;

private _towbar = _aircraft getVariable [QGVAR(attachedTowbar), objNull];
if (_attach) exitWith {
    _baseCondition && isNull _towbar
};

_baseCondition && !(isNull _towbar)
