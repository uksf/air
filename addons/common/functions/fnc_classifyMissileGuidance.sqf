#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Classifies a missile ammo type as a radar (RDR) or infrared (IR)
        guidance source for the RWR source-classifier panel.

        Tier A: ACE missileguidance defaultSeekerType (preferred — overrides
        any vanilla guidance). Tier B: missile's own SensorsManagerComponent.

        Returns "" for guidance types we deliberately don't display (laser,
        SACLOS, optical, GPS, SALH) since they don't produce a vanilla
        lock tone.

    Parameter(s):
        0: Ammo type classname <STRING>

    Return Value:
        "RDR" or "IR" or "" <STRING>

    Example:
        ["ace_missile_AIM120D_C"] call uksf_air_common_fnc_classifyMissileGuidance
*/
params [["_ammoType", "", [""]]];

if (_ammoType isEqualTo "") exitWith {""};

private _ammoConfig = configFile >> "CfgAmmo" >> _ammoType;
if (!isClass _ammoConfig) exitWith {""};

// Tier A: ACE missileguidance overhaul
private _aceConfig = _ammoConfig >> "ace_missileguidance";
if (isClass _aceConfig && {getNumber (_aceConfig >> "enabled") > 0}) exitWith {
    private _seekerType = getText (_aceConfig >> "defaultSeekerType");
    if (_seekerType in ["DopplerRadar", "ARH", "SARH", "ActiveRadar", "AntiRadiation"]) exitWith {"RDR"};
    if (_seekerType isEqualTo "IR") exitWith {"IR"};
    ""
};

// Tier B: walk the missile's own SensorsManagerComponent
private _components = _ammoConfig >> "Components" >> "SensorsManagerComponent" >> "Components";
if (!isClass _components) exitWith {""};

private _result = "";
{
    if (_result isNotEqualTo "") exitWith {};
    private _typeName = configName _x;
    if (_typeName isEqualTo "IRSensorComponent") then { _result = "IR"; };
    if (_typeName in ["ActiveRadarSensorComponent", "PassiveRadarSensorComponent", "AntiRadiationSensorComponent", "RadarSensorComponent"]) then { _result = "RDR"; };
} forEach configProperties [_components, "isClass _x", false];

_result
