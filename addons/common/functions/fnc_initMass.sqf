#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts real mass for a jet: sets it now where the plane is local, and again on the frame after each
        weapon release or pylon change on whichever machine then owns the plane. Fuel burn, refuel and crew changes
        also reach the mass through the caller's once-a-second updateMass call. Resets the fuel-burn baseline
        when locality changes. Call once on every machine that runs the plane's init.

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

_plane addEventHandler ["Local", {
    params ["_plane"];
    _plane setVariable [QGVAR(fuelBurnTime), nil];
}];

if (local _plane) then {
    [_plane, _emptyMass, true] call FUNC(updateMass);
};

private _queueMassUpdate = {
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
};

_plane addEventHandler ["Fired", _queueMassUpdate];
_plane addEventHandler ["PylonChanged", _queueMassUpdate];
