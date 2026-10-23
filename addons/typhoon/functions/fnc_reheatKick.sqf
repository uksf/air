#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Plays the reheat light-up thump on this client. From the plane's own cockpit it plays the
        cockpit version straight to the listener, without distance fade or interior muffling.
        Otherwise it plays the external version from the plane.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_reheatKick
*/
#define EXTERNAL_RANGE 2000
#define UNMUFFLED 2

params ["_plane"];

if (cameraOn == _plane && {cameraView == "INTERNAL"}) exitWith {
    playSound [QGVAR(reheatKickInt), UNMUFFLED];
};

_plane say3D [QGVAR(reheatKickExt), EXTERNAL_RANGE, 1, 0, 0, true];
