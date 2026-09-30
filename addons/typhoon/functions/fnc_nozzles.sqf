#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Closes the dry-thrust nozzle petals at cruise and opens them at low speed or in reheat,
        as the EAWS nozzle script did. Animates only when the target changes.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_nozzles
*/
#define CRUISE_SPEED 135
#define OUTER_PETALS 12
#define INNER_PETALS 14

params ["_plane"];

private _closed = speed _plane > CRUISE_SPEED && {!(_plane getVariable [QGVAR(afterburnerEngaged), false])};
if (_closed isEqualTo (_plane getVariable [QGVAR(nozzlesClosed), false])) exitWith {};
_plane setVariable [QGVAR(nozzlesClosed), _closed];

private _phase = [0, 1] select _closed;
for "_i" from 1 to OUTER_PETALS do {
    _plane animate [format ["nozzle_2_%1", _i], _phase];
};
for "_i" from 1 to INNER_PETALS do {
    _plane animate [format ["nozzle_1_%1", _i], _phase];
};
