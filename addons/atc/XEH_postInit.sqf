#include "script_component.hpp"

[QUGVAR(atc,terminal), QGVAR(terminal)] call ace_common_fnc_registerItemReplacement;

if (!hasInterface) exitWith {};

["visibleMap", {
    params ["_player", "_mapOn"];

    private _hasTerminal = QGVAR(terminal) in (assignedItems _player);
    if (!_hasTerminal && GVAR(loopPFHID) != -1) exitWith {
        [_player, false] call FUNC(loop);
    };

    [_player, _mapOn] call FUNC(loop);
}] call CBA_fnc_addPlayerEventHandler;
