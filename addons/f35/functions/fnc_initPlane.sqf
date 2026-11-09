#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets the F-35's MFD loadout and real mass, runs the pilot get-in for a player already inside,
        and adds the events that start its loops: Engine, Local and GetIn. Starts the loops that this
        machine needs now. A parked, empty jet with its engine off runs no loop on any machine.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_f35_fnc_initPlane
*/

params ["_plane"];

[_plane] call FUNC(setMfdLoadout);

if (ACE_player in _plane) then {
    [_plane] call FUNC(getIn);
};

[_plane, EMPTY_MASS] call EFUNC(common,initMass);

_plane addEventHandler ["Engine", {
    params ["_plane", "_engineOn"];
    if (_engineOn) then {
        [_plane] call FUNC(startLoops);
    };
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
