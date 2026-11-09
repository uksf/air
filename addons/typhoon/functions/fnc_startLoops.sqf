#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the Typhoon loops that this machine needs now. The local loop runs where the plane is
        local while its engine runs or reheat is still engaged. The client loop runs only on machines
        with an interface, while the engine runs or the player flies the plane. Each loop stops itself
        when its condition ends, and the Engine, Local and GetIn events start it again.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_startLoops
*/

params ["_plane"];

[_plane, QGVAR(localLoop), {
    params ["_plane"];
    local _plane && {_plane getVariable [QGVAR(afterburnerEngaged), false] || {alive _plane && {isEngineOn _plane}}}
}, FUNC(localTick), [0, 0]] call EFUNC(common,startLoop);

if (hasInterface) then {
    [_plane, QGVAR(clientLoop), {
        params ["_plane"];
        alive _plane && {isEngineOn _plane || {ACE_player == driver _plane}}
    }, FUNC(clientTick), [_plane animationPhase REHEAT_FLAME_HIDE < REHEAT_FLAME_SHOWN]] call EFUNC(common,startLoop);
};
