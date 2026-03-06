#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Reorders vehicle weapons to match the weaponOrder config array.
        Weapons listed in weaponOrder appear first in that order,
        any remaining weapons are appended after.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None
*/
params ["_vehicle"];

if !(local _vehicle) exitWith {};

private _config = configOf _vehicle;
private _weaponOrder = getArray (_config >> QGVAR(weaponOrder));
if (_weaponOrder isEqualTo []) exitWith {};

private _currentWeapons = weapons _vehicle;
if (_currentWeapons isEqualTo []) exitWith {};

// Build ordered list: weapons from weaponOrder that exist on the vehicle, then the rest
private _orderedWeapons = [];
private _remaining = +_currentWeapons;

{
    private _orderEntry = toLowerANSI _x;
    private _foundIndex = _remaining findIf {toLowerANSI _x == _orderEntry};
    if (_foundIndex != -1) then {
        _orderedWeapons pushBack (_remaining#_foundIndex);
        _remaining deleteAt _foundIndex;
    };
} forEach _weaponOrder;

_orderedWeapons append _remaining;

// Check if already in correct order
if (_orderedWeapons isEqualTo _currentWeapons) exitWith {};

// Save all magazine state before removing weapons
// magazinesAllTurrets returns [magazine, turretPath, ammoCount]
private _savedMagazines = magazinesAllTurrets _vehicle;

// Remove all weapons then re-add in desired order
{
    _vehicle removeWeapon _x;
} forEach _currentWeapons;

{
    _vehicle addWeapon _x;
} forEach _orderedWeapons;

// Remove default magazines added by addWeapon, then restore the saved state
{
    _x params ["_mag", "_turretPath"];
    _vehicle removeMagazineTurret [_mag, _turretPath];
} forEach magazinesAllTurrets _vehicle;

{
    _x params ["_mag", "_turretPath", "_ammoCount"];
    _vehicle addMagazineTurret [_mag, _turretPath];
    _vehicle setMagazineTurretAmmo [_mag, _ammoCount, _turretPath];
} forEach _savedMagazines;
