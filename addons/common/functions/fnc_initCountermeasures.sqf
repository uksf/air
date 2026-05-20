#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Class init EH for "Air". Scans the vehicle for CM-flare magazines
        across all turrets (incl. driver [-1]). If 2+ CM mags exist, caches
        the [magClass, turretPath] list on the vehicle as QGVAR(cmTurrets)
        (server-only setVariable with broadcast to avoid N redundant
        broadcasts) and attaches the Fired EH on every machine — gating
        the actual sync work inside the callback on `local _vehicle`.

    Parameter(s):
        0: Aircraft <OBJECT>

    Return Value:
        Nothing

    Example:
        [_aircraft] call uksf_air_common_fnc_initCountermeasures
*/
params ["_vehicle"];

private _cmMagClasses = [
    "60Rnd_CMFlareMagazine",
    "120Rnd_CMFlareMagazine",
    "240Rnd_CMFlareMagazine",
    "60Rnd_CMFlare_Chaff_Magazine",
    "120Rnd_CMFlare_Chaff_Magazine",
    "168Rnd_CMFlare_Chaff_Magazine",
    "192Rnd_CMFlare_Chaff_Magazine",
    "240Rnd_CMFlare_Chaff_Magazine",
    "300Rnd_CMFlare_Chaff_Magazine",
    QEGVAR(weapons,CMFlare_Chaff_1200Rnd_Magazine)
];

private _cmTurrets = [];
{
    _cmTurrets pushBackUnique [_x select 0, _x select 1];
} forEach ((magazinesAllTurrets _vehicle) select {
    (_x select 0) in _cmMagClasses
});

if (count _cmTurrets < 2) exitWith {};

_vehicle setVariable [QGVAR(cmTurrets), _cmTurrets, isServer];

_vehicle addEventHandler ["Fired", {call FUNC(onCountermeasureFired)}];
