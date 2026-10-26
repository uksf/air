#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets a jet's mass to its empty mass plus fuel, stores and crew. Arma keeps a plane at its config mass
        whatever it carries, so a loaded jet accelerated like an empty one.
        Fuel is jet fuel at 0.8 kg/L of fuelCapacity litres. Each round of every magazine, pylons included, weighs
        the CfgStoreMass entry of its ammo class or of the nearest parent that has one. Each crew member is 100 kg.
        Sets the mass only when it moves more than MASS_STEP kg from the current mass, or when forced, so the
        once-a-second fuel tick does not broadcast every small change.
        Call where the plane is local.

    Parameter(s):
        0: Plane <OBJECT>
        1: Empty mass in kg <NUMBER>
        2: Force the update <BOOL> (Optional, default false)

    Return Value:
        Nothing

    Example:
        [_plane, 11000] call uksf_air_common_fnc_updateMass
*/
#define FUEL_KG_PER_LITRE 0.8
#define CREW_KG 100
#define MASS_STEP 50

params ["_plane", "_emptyMass", ["_force", false]];

if (isNil QGVAR(storeMassCache)) then {
    GVAR(storeMassCache) = createHashMap;
};

private _storesMass = 0;
{
    _x params ["_magazine", "", "_rounds"];
    private _ammo = getText (configFile >> "CfgMagazines" >> _magazine >> "ammo");
    private _roundMass = GVAR(storeMassCache) getOrDefaultCall [_ammo, {
        private _table = configFile >> QGVAR(storeMass);
        private _class = configFile >> "CfgAmmo" >> _ammo;
        while { isClass _class && {!isNumber (_table >> configName _class)} } do {
            _class = inheritsFrom _class;
        };
        getNumber (_table >> configName _class)
    }, true];
    _storesMass = _storesMass + _rounds * _roundMass;
} forEach magazinesAllTurrets _plane;

private _fuelMass = fuel _plane * getNumber (configOf _plane >> "fuelCapacity") * FUEL_KG_PER_LITRE;
private _mass = _emptyMass + _fuelMass + _storesMass + CREW_KG * count crew _plane;

if (_force || {abs (_mass - getMass _plane) > MASS_STEP}) then {
    _plane setMass _mass;
};
