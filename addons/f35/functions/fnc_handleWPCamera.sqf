#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        PFEH body. Enables the WP camera ppEffect iff:
          - Player toggle var is true
          - Player still inside the F-35
          - Pilot camera is the active view (cameraView == "GUNNER")
          - Driver-seat optic is in NVG vision mode (currentVisionMode == 1)
        Otherwise disables it. Stops itself if the player leaves the plane.

    Parameter(s):
        0: PFEH args <ARRAY> - [_plane]
        1: PFEH id <NUMBER>

    Return Value:
        Nothing
*/

params ["_args", "_idPFH"];
_args params ["_plane"];

if (!alive _plane || {vehicle ACE_player != _plane}) exitWith {
    GVAR(wpCameraCC) ppEffectEnable false;
    [_idPFH] call CBA_fnc_removePerFrameHandler;
    GVAR(wpCameraPFH) = -1;
};

private _enabled = ACE_player getVariable [QGVAR(wpCamera), EGVAR(nightvision,alwaysUseWP)];
private _inCamera = cameraView == "GUNNER";
private _nvg = currentVisionMode _plane == 1;

GVAR(wpCameraCC) ppEffectEnable (_enabled && _inCamera && _nvg);
