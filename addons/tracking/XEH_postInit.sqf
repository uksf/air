#include "script_component.hpp"

["uksf_air_atc_terminal", QGVAR(terminal)] call ace_common_fnc_registerItemReplacement;

if (!hasInterface) exitWith {};

["visibleMap", {
    params ["_player", "_mapOn"];

    private _hasTerminal = QGVAR(terminal) in assignedItems _player;
    private _inAirCrewSeat = false;

    if (!isNull objectParent _player) then {
        private _vehicle = objectParent _player;
        if (_vehicle isKindOf "Air") then {
            private _role = assignedVehicleRole _player;
            if (_role isNotEqualTo [] && {_role select 0 isNotEqualTo "cargo"}) then {
                _inAirCrewSeat = true;
            };
        };
    };

    if (!_mapOn || {!_hasTerminal && !_inAirCrewSeat}) exitWith {
        if (GVAR(loopPFHID) != -1) then {
            [_player, false, 0] call FUNC(loop);
        };
    };

    private _tier = if (_hasTerminal) then {2} else {1};
    [_player, true, _tier] call FUNC(loop);
}] call CBA_fnc_addPlayerEventHandler;
