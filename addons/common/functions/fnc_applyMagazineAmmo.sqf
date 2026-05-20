#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Receiver for the QGVAR(applyMagazineAmmo) CBA event, dispatched
        via CBA_fnc_turretEvent. Runs on the machine where the target
        turret is local. setMagazineTurretAmmo is local-effect, so each
        turret owner must apply its own update.

    Parameter(s):
        0: Aircraft <OBJECT>
        1: Magazine class <STRING>
        2: Ammo count <NUMBER>
        3: Turret path <ARRAY>

    Return Value:
        Nothing

    Example:
        Wired via CBA_fnc_addEventHandler in XEH_postInit.sqf.
*/
params ["_vehicle", "_magClass", "_ammoCount", "_turretPath"];

if (!alive _vehicle) exitWith {};

_vehicle setMagazineTurretAmmo [_magClass, _ammoCount, _turretPath];
