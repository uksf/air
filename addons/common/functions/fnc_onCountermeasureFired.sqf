#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Vehicle "Fired" EH callback. If the fired weapon is a CMFlareLauncher
        descendant, reads the firer's post-fire ammo and propagates to all
        other cached CM turrets on this vehicle.

    Parameter(s):
        Standard "Fired" EH args:
            [_vehicle, _weapon, _muzzle, _mode, _ammo, _magazine, _projectile, _gunner]

    Return Value:
        Nothing
*/
params ["_vehicle", "_weapon", "", "", "", "_magazine", "", "_gunner"];

if (!local _vehicle) exitWith {};
if (!(_weapon isKindOf ["CMFlareLauncher", configFile >> "CfgWeapons"])) exitWith {};

private _firerPath = if (_gunner isEqualTo driver _vehicle) then {
    [-1]
} else {
    [_gunner] call CBA_fnc_turretPath
};

private _firerAmmo = _vehicle magazineTurretAmmo [_magazine, _firerPath];

[_vehicle, _magazine, _firerAmmo] call FUNC(syncCountermeasures);
