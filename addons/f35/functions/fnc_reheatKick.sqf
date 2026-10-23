#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Plays the reheat light-up thump on this client: the low-passed cockpit version, without the
        engine's interior muffling, when this client views the plane from its own cockpit, otherwise
        the external version.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_f35_fnc_reheatKick
*/
#define EXTERNAL_RANGE 2000
#define INTERNAL_RANGE 20
#define UNMUFFLED 2

params ["_plane"];

if (cameraOn == _plane && {cameraView == "INTERNAL"}) exitWith {
    _plane say3D [QGVAR(reheatKickInt), INTERNAL_RANGE, 1, UNMUFFLED, 0, false];
};

_plane say3D [QGVAR(reheatKickExt), EXTERNAL_RANGE, 1, 0, 0, true];
