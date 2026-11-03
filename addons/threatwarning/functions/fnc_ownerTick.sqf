#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Owner loop.
        Broadcasts target changes of missiles fired on this machine when the old or new target is a covered aircraft, because missileTarget only reads correctly where the missile is local.
        Drops dead missiles, then updates the published threat state of every covered aircraft local to this machine.

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_air_threatwarning_fnc_ownerTick
*/
GVAR(aircraft) = GVAR(aircraft) select {!isNull _x};
GVAR(localMissiles) = GVAR(localMissiles) select {alive (_x#0)};
{
    _x params ["_missile", "_last"];
    private _target = missileTarget _missile;
    if (_target isEqualTo _last) then {continue};
    _x set [1, _target];
    if (_target in GVAR(aircraft) || {_last in GVAR(aircraft)}) then {
        [QGVAR(missileTarget), [_missile, _target]] call CBA_fnc_globalEvent;
    };
} forEach GVAR(localMissiles);
GVAR(missileTargets) = GVAR(missileTargets) select {alive (_x#0)};
{
    if (local _x) then {
        [_x] call FUNC(ownerUpdate);
    };
} forEach GVAR(aircraft);
