#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether a unit sits in a flight seat of the aircraft: the pilot, a co-pilot turret, or a turret listed in the aircraft's flightTurrets config.
        The result is cached for the local player's current seat.

    Parameters:
        0: Aircraft <OBJECT>
        1: Unit <OBJECT>

    Return value:
        Unit is in a flight seat <BOOL>

    Example:
        [_aircraft, player] call uksf_air_threatwarning_fnc_isFlightSeat
*/
params ["_aircraft", "_unit"];

if (driver _aircraft isEqualTo _unit) exitWith {true};

private _path = _aircraft unitTurret _unit;
if (_path isEqualTo []) exitWith {false};

GVAR(seat) params ["_seatAircraft", "_seatPath", "_seatResult"];
if (_unit isEqualTo player && {_seatAircraft isEqualTo _aircraft} && {_seatPath isEqualTo _path}) exitWith {_seatResult};

private _result = _path isEqualTo [-1]
    || {getNumber ([_aircraft, _path] call BIS_fnc_turretConfig >> "isCopilot") isEqualTo 1}
    || {_path in getArray (configOf _aircraft >> QGVAR(flightTurrets))};

if (_unit isEqualTo player) then {
    GVAR(seat) = [_aircraft, _path, _result];
};
_result
