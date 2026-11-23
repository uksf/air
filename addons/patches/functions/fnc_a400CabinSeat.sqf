#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Seat a player who is standing inside the A400M cabin, without the engine walking them to an outside get-in point.
        With check set, only reports whether the seat can be taken.

    Parameter(s):
        0: Plane <OBJECT>
        1: Seat, "driver", "copilot" or "cargo" <STRING>
        2: Check only <BOOL> (Optional, default false)

    Return Value:
        Seat can be taken <BOOL>

    Example:
        [_plane, "cargo", true] call uksf_air_patches_fnc_a400CabinSeat
*/

params ["_plane", "_seat", ["_check", false]];

private _rel = _plane worldToModel (ASLToAGL getPosASL player);
_rel params ["_x", "_y", "_z"];
private _inCabin = isNull objectParent player && {alive player} && {abs _x < 2.4} && {_y > -13.5} && {_y < 10} && {_z > 1.3} && {_z < 4.6};
if (!_inCabin) exitWith { false };

private _free = switch (_seat) do {
    case "driver": { isNull driver _plane };
    case "copilot": { isNull (_plane turretUnit [0]) };
    default { (_plane emptyPositions "Cargo") > 0 };
};
if (_check || {!_free}) exitWith { _free };

switch (_seat) do {
    case "driver": { player moveInDriver _plane };
    case "copilot": { player moveInTurret [_plane, [0]] };
    default { player moveInCargo _plane };
};
true
