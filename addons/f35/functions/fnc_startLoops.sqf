#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the F-35 loops that this machine needs now. The local loop runs where the plane is
        local while it is crewed, its engine runs, or reheat is still engaged. The client loop runs
        only on machines with an interface, while the engine runs or the afterburner light is still
        out. Each loop stops itself when its condition ends, and the Engine, Local and GetIn events
        start it again.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_f35_fnc_startLoops
*/

params ["_plane"];

[_plane, QGVAR(localLoop), {
    params ["_plane"];
    local _plane && {
        _plane getVariable [QGVAR(afterburnerEngaged), false]
        || {alive _plane && {isEngineOn _plane || {crew _plane isNotEqualTo []}}}
    }
}, FUNC(localTick), [CBA_missionTime, 0]] call EFUNC(common,startLoop);

if (hasInterface) then {
    [_plane, QGVAR(clientLoop), {
        params ["_plane"];
        (alive _plane && {isEngineOn _plane}) || {_plane getVariable [QGVAR(afterburnerLightWas), false]}
    }, FUNC(clientTick), [_plane animationSourcePhase REHEAT_SOURCE > REHEAT_SHOWN]] call EFUNC(common,startLoop);
};
