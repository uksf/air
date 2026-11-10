#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets the Typhoon's real mass and adds the events that start its loops: Engine (with APU smoke
        on clients when the engine starts on the ground), Local and GetIn. Starts the loops that this
        machine needs now. Hides reheat flames until light-up. A parked jet with its engine off runs no loop on any machine.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_initPlane
*/
#define APU_SMOKE_MAX_SPEED 10

params ["_plane"];

[_plane, EMPTY_MASS] call EFUNC(common,initMass);
if (local _plane) then {
    [_plane, false] call FUNC(afterburnerVisuals);
};

_plane addEventHandler ["Engine", {
    params ["_plane", "_engineOn"];
    if (!_engineOn) exitWith {};
    if (hasInterface && {speed _plane < APU_SMOKE_MAX_SPEED}) then {
        [_plane] call FUNC(apuSmoke);
    };
    [_plane] call FUNC(startLoops);
}];

_plane addEventHandler ["Local", {
    params ["_plane", "_isLocal"];
    if (_isLocal) then {
        [_plane] call FUNC(startLoops);
    };
}];

_plane addEventHandler ["GetIn", {
    params ["_plane"];
    [_plane] call FUNC(startLoops);
}];

[_plane] call FUNC(startLoops);
