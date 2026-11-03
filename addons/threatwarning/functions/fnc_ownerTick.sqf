#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Owner loop.
        Broadcasts target changes of missiles fired on this machine when the old or new target is a covered aircraft, because missileTarget only reads correctly where the missile is local.
        Each broadcast is a JIP event keyed to the missile, so a machine that joins later, and then takes ownership of the aircraft, still knows the target. The JIP event is removed when the missile dies.
        Drops dead missiles, then updates the published threat state of every covered aircraft local to this machine.

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_air_threatwarning_fnc_ownerTick
*/
GVAR(aircraft) = GVAR(aircraft) select {!isNull _x};
GVAR(localMissiles) = GVAR(localMissiles) select {
    _x params ["_missile", "", ["_jipId", ""]];
    if (alive _missile) then {true} else {
        if (_jipId isNotEqualTo "") then {[_jipId] call CBA_fnc_removeGlobalEventJIP};
        false
    };
};
{
    _x params ["_missile", "_last"];
    private _target = missileTarget _missile;
    if (_target isEqualTo _last) then {continue};
    _x set [1, _target];
    if (_target in GVAR(aircraft) || {_last in GVAR(aircraft)}) then {
        private _jipId = format ["%1_%2", QGVAR(missile), netId _missile];
        if (netId _missile isEqualTo "0:0") then {
            [QGVAR(missileTarget), [_missile, _target]] call CBA_fnc_globalEvent;
        } else {
            [QGVAR(missileTarget), [_missile, _target], _jipId] call CBA_fnc_globalEventJIP;
            _x set [2, _jipId];
        };
    };
} forEach GVAR(localMissiles);
GVAR(missileTargets) = GVAR(missileTargets) select {alive (_x#0)};
{
    if (local _x) then {
        [_x] call FUNC(ownerUpdate);
    };
} forEach GVAR(aircraft);
