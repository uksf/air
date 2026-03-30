#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets NATO marker type for a group based on its leader's vehicle

    Parameter(s):
        0: Group <GROUP>

    Return Value:
        Marker type <STRING>

    Example:
        [_group] call uksf_air_tracking_fnc_getVehicleMarker
*/
params ["_group"];

private _leader = leader _group;
private _vehicle = vehicle _leader;

if (isNull objectParent _leader) exitWith {
    "b_inf"
};

if (getNumber (configOf _vehicle >> "attendant") isEqualTo 1) exitWith {
    "b_med"
};

if (
    getNumber (configOf _vehicle >> "transportRepair") > 0
    || {getNumber (configOf _vehicle >> "transportFuel") > 0}
    || {getNumber (configOf _vehicle >> "transportAmmo") > 0}
) exitWith {
    "b_support"
};

if (_vehicle isKindOf "UAV") exitWith {
    "b_uav"
};

if (_vehicle isKindOf "Plane") exitWith {
    "b_plane"
};

if (_vehicle isKindOf "Air") exitWith {
    "b_air"
};

if (_vehicle isKindOf "StaticMortar") exitWith {
    "b_mortar"
};

if (getNumber (configOf _vehicle >> "artilleryScanner") isEqualTo 1) exitWith {
    "b_art"
};

if (_vehicle isKindOf "Car") exitWith {
    "b_motor_inf"
};

if (_vehicle isKindOf "Tank") exitWith {
    if (getNumber (configOf _vehicle >> "transportSoldier") > 0) then {
        "b_mech_inf"
    } else {
        "b_armor"
    };
};

if (_vehicle isKindOf "Ship") exitWith {
    "b_naval"
};

"b_unknown"
