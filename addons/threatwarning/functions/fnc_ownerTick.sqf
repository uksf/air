#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Owner loop. Updates the published threat state of every covered aircraft local to this machine

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_air_threatwarning_fnc_ownerTick
*/
GVAR(aircraft) = GVAR(aircraft) select {!isNull _x};
{
    if (local _x) then {
        [_x] call FUNC(ownerUpdate);
    };
} forEach GVAR(aircraft);
