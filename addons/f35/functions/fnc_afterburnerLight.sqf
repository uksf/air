#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates or destroys the afterburner light pair on an F-35.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_f35_fnc_afterburnerLight
*/
#define EXHAUST_MEM_POINT "exhaust_pos"

params ["_plane"];

if (!hasInterface) exitWith {};

private _engaged = _plane getVariable [QGVAR(afterburnerEngaged), false];
private _lights = _plane getVariable [QGVAR(afterburnerLights), []];

if (!_engaged) exitWith {
    if (count _lights == 0) exitWith {};
    { deleteVehicle _x } forEach _lights;
    _plane setVariable [QGVAR(afterburnerLights), nil];
};

if (count _lights > 0) exitWith {};

private _outer = "#lightreflector" createVehicleLocal [0, 0, 0];
_outer setLightColor [0.8, 0.2, 0];
_outer setLightAmbient [0.8, 0.2, 0];
_outer setLightIntensity 5000;
_outer setLightConePars [0, 120, 3];
_outer setLightAttenuation [0, 0, 5, 1, 0.1, 100];
_outer setLightDayLight false;
_outer attachTo [_plane, [0, 0, 0], EXHAUST_MEM_POINT];

private _inner = "#lightreflector" createVehicleLocal [0, 0, 0];
_inner setLightColor [1, 0.9, 0.6];
_inner setLightAmbient [1, 0.9, 0.6];
_inner setLightIntensity 60000;
_inner setLightConePars [5, 60, 8];
_inner setLightAttenuation [0.2, 0, 5, 1, 0.1, 30];
_inner setLightDayLight false;
_inner attachTo [_plane, [0, 0, 0], EXHAUST_MEM_POINT];

private _vectors = _plane selectionVectorDirAndUp [EXHAUST_MEM_POINT, "Memory"];
_vectors params ["_forward", "_up"];
private _back = [_forward vectorMultiply -1, _up vectorMultiply -1];
_outer setVectorDirAndUp _back;
_inner setVectorDirAndUp _back;

_plane setVariable [QGVAR(afterburnerLights), [_outer, _inner]];
