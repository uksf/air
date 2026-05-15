#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Wrapper for AAE camshake function replacement.
        Skips light/small aircraft (drones), scales force by mass and forward speed.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        call uksf_air_common_fnc_aaeCamshake
*/
private _plane = _this;

private _mass = getMass _plane;
if (_mass < 500) exitWith {};

private _distance = player distance _plane;
if (_distance >= camshake_sdr) exitWith {};

private _velocityScale = linearConversion [0, 400, abs (speed _plane), 0, 1, true];
private _massScale = linearConversion [500, 8000, _mass, 0.1, 1, true];
private _force = (linearConversion [5, camshake_sdr, _distance, 1, 0.01, true]) * _massScale * _velocityScale;
private _frequency = linearConversion [50, camshake_sdr, _distance, 20, 8, true];

addCamShake [_force, 0.5, _frequency];
