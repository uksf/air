#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts real mass for a jet: sets it now where the plane is local, and again on the frame after each
        weapon release on whichever machine then owns the plane. Fuel burn, refuel, rearm and crew changes
        reach the mass through the caller's once-a-second updateMass call.
        Call once on every machine that runs the plane's init.

    Parameter(s):
        0: Plane <OBJECT>
        1: Empty mass in kg <NUMBER>

    Return Value:
        Nothing

    Example:
        [_plane, 11000] call uksf_air_common_fnc_initMass
*/
params ["_plane", "_emptyMass"];

_plane setVariable [QGVAR(emptyMass), _emptyMass];

if (local _plane) then {
    [_plane, _emptyMass, true] call FUNC(updateMass);
};

_plane addEventHandler ["Fired", {
    params ["_plane"];

    if (!local _plane || {_plane getVariable [QGVAR(massPending), false]}) exitWith {};

    _plane setVariable [QGVAR(massPending), true];
    [{
        params ["_plane"];

        _plane setVariable [QGVAR(massPending), false];
        if (local _plane) then {
            [_plane, _plane getVariable QGVAR(emptyMass)] call FUNC(updateMass);
        };
    }, [_plane]] call CBA_fnc_execNextFrame;
}];
