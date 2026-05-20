#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Fans out the given ammo value to every cached CM turret on this
        vehicle whose magazine class matches. Uses CBA_fnc_turretEvent
        so each turret's owner machine applies the update locally.

        No-op if the vehicle has no cached CM turret list.

    Parameter(s):
        0: Aircraft <OBJECT>
        1: Magazine class <STRING>
        2: Ammo count to set <NUMBER>

    Return Value:
        Nothing

    Example:
        [_aircraft, "168Rnd_CMFlare_Chaff_Magazine", 120] call uksf_air_common_fnc_syncCountermeasures
*/
params ["_vehicle", "_magClass", "_ammoCount"];

private _cmTurrets = _vehicle getVariable [QGVAR(cmTurrets), []];
if (_cmTurrets isEqualTo []) exitWith {};

{
    _x params ["_otherMagClass", "_turretPath"];
    if (_otherMagClass isEqualTo _magClass) then {
        [QGVAR(applyMagazineAmmo), [_vehicle, _magClass, _ammoCount, _turretPath], _vehicle, _turretPath] call CBA_fnc_turretEvent;
    };
} forEach _cmTurrets;
