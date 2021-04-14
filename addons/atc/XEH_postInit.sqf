#include "script_component.hpp"

[QUGVAR(atc,terminal), QGVAR(terminal)] call ace_common_fnc_registerItemReplacement;

if (!hasInterface) exitWith {};

["visibleMap", {
    params ["_player", "_mapOn"];

    if (!(QGVAR(terminal) in (assignedItems _player))) exitWith {};

    if (_mapOn) then {
        [_player, true] call FUNC(loop);
    } else {
        [_player, false] call FUNC(loop);
    };
}] call CBA_fnc_addPlayerEventHandler;
