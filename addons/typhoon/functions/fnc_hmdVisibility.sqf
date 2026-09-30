#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Hides the helmet display while the pilot looks through the HUD, so the two do not overlap.
        The HMD's draw condition reads this MFD user value.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_hmdVisibility
*/
// Half-angle of the HUD's field of view from the pilot's eye, in degrees.
#define HUD_HALF_ANGLE 15

params ["_plane"];

private _visible = 1;
if (cameraView == "INTERNAL") then {
    private _angle = acos (((getCameraViewDirection ACE_player) vectorDotProduct (vectorDir _plane)) max -1 min 1);
    if (_angle < HUD_HALF_ANGLE) then {
        _visible = 0;
    };
};

if (_visible != (_plane getVariable [QGVAR(hmdVisible), -1])) then {
    _plane setVariable [QGVAR(hmdVisible), _visible];
    _plane setUserMFDValue [HMD_USER_VALUE, _visible];
};
