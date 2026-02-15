#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Paradrops ViV cargo then Ace cargo

    Parameter(s):
        0: Mode (0 = Single, 1 = All) <SCALAR>

    Return Value:
        Nothing
*/
params [["_mode", 0]];

private _vehicle = vehicle ACE_player;
if !(_vehicle isKindOf "Air") exitWith {};

private _loaded = _vehicle getVariable ["ace_cargo_loaded", []];
private _vivLoaded = getVehicleCargo _vehicle;
if (_loaded isEqualTo [] && _vivLoaded isEqualTo []) exitWith {};

if !(ACE_player == driver _vehicle || ACE_player == _vehicle turretUnit [0]) exitWith {};

if (((getPosATLVisual _vehicle)#2) < 30) exitWith {
    [["Too low for paradrop", "Minimum altitude: 100 ft"], 2] call ace_common_fnc_displayTextStructured;
};

if (GVAR(paradropInProgress)) exitWith {
    [["Paradrop in progress..."], 2] call ace_common_fnc_displayTextStructured;
};

GVAR(paradropInProgress) = true;
private _cargo = [+_vivLoaded, +_loaded] select (_vivLoaded isEqualTo []);
reverse _cargo;
private _cargoCount = count _cargo;
private _unloadCount = [0, _cargoCount - 1] select _mode;
for "_i" from 0 to _unloadCount do {
    private _item = _cargo#_i;

    [{
        params ["_vehicle", "_item"];

        objNull setVehicleCargo _item;
        ["ace_cargo_paradropItem", [_item, _vehicle, false]] call CBA_fnc_localEvent;
        [[
            "STR_ace_cargo_UnloadedItem",
            getText (configOf _item >> "displayName"),
            getText (configOf _vehicle >> "displayName")
        ], 3] call ace_common_fnc_displayTextStructured;
    }, [_vehicle, _item], _i + 1] call CBA_fnc_waitAndExecute;
};

[{GVAR(paradropInProgress) = false}, [], _unloadCount + 2] call CBA_fnc_waitAndExecute;
