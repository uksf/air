#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises the pilot-camera white phosphor ppEffect handle for this
        client. Called once per client at postInit. The handle is reused across
        all F-35 sorties; PFEH lifecycle is driven by getIn/getOut.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_air_f35_fnc_initWPCamera
*/

if (!hasInterface) exitWith {};

GVAR(wpCameraCC) = ppEffectCreate ["ColorCorrections", 2010];
GVAR(wpCameraCC) ppEffectAdjust [1, 1, 0.0, [0,0,0,0], [1.1, 0.8, 1.9, 0.9], [1, 1, 6, 0]];
GVAR(wpCameraCC) ppEffectCommit 0;
GVAR(wpCameraCC) ppEffectForceInNVG true;
GVAR(wpCameraCC) ppEffectEnable false;

GVAR(wpCameraPFH) = -1;
