#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Piggyback on ace_rearm_rearmSuccessLocalEH. Fires alongside ACE's
        own handler (CBA dispatches all registered handlers).

        Defers one frame so ACE's addMagazineTurret/setTurretMagazineAmmo
        has committed, then reads the rearmed mag's new ammo and propagates
        to every cached CM turret on this vehicle. Whatever amount ACE
        actually loaded (full mag, partial mag, second load on top of
        existing — all covered) is what every other turret syncs to.

        Pylon rearms are ignored (handled separately by ACE pylons).

    Parameter(s):
        Standard ace_rearm_rearmSuccessLocalEH args:
            [_vehicle, _unit, _turretPath, _numMagazines, _magazineClass, _numRounds, _pylon]

    Return Value:
        Nothing
*/
params ["_vehicle", "", "_turretPath", "", "_magazineClass", "", "_pylon"];

if (_pylon > 0) exitWith {};
if (!alive _vehicle) exitWith {};

private _cmTurrets = _vehicle getVariable [QGVAR(cmTurrets), []];
if (_cmTurrets isEqualTo []) exitWith {};

private _isTracked = _cmTurrets findIf {(_x select 0) isEqualTo _magazineClass} != -1;
if (!_isTracked) exitWith {};

[{
    params ["_vehicle", "_magazineClass", "_turretPath"];
    if (!alive _vehicle) exitWith {};
    private _newAmmo = _vehicle magazineTurretAmmo [_magazineClass, _turretPath];
    [_vehicle, _magazineClass, _newAmmo] call FUNC(syncCountermeasures);
}, [_vehicle, _magazineClass, _turretPath]] call CBA_fnc_execNextFrame;
