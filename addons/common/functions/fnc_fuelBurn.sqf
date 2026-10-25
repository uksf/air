#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Burns jet fuel at real engine rates. The airplaneX engine ignores fuelConsumptionRate and burns at most
        about 1,200 L/h at full throttle for every jet, so each jet passes its real rates here.
        Dry burn scales with throttle up to THROTTLE_REHEAT, with an idle floor; reheat scales from full dry
        to full reheat over the top of the throttle range.
        FUEL_TIME_SCALE multiplies every rate for every jet, to shorten flight time and force refuels.
        Call about once a second where the plane is local; the burn uses the real time since the last call.

    Parameter(s):
        0: Plane <OBJECT>
        1: Idle burn in litres per hour <NUMBER>
        2: Full dry burn in litres per hour <NUMBER>
        3: Full reheat burn in litres per hour <NUMBER>

    Return Value:
        Nothing

    Example:
        [_plane, 600, 11900, 38800] call uksf_air_common_fnc_fuelBurn
*/
#define THROTTLE_REHEAT 0.9
#define FUEL_TIME_SCALE 1

params ["_plane", "_idleLitresPerHour", "_maxDryLitresPerHour", "_maxReheatLitresPerHour"];

private _now = CBA_missionTime;
private _elapsed = _now - (_plane getVariable [QGVAR(fuelBurnTime), _now]);
_plane setVariable [QGVAR(fuelBurnTime), _now];

private _fuel = fuel _plane;
if (!isEngineOn _plane || {_fuel <= 0} || {_elapsed <= 0}) exitWith {};

private _throttle = airplaneThrottle _plane;
private _litresPerHour = if (_throttle < THROTTLE_REHEAT) then {
    (_maxDryLitresPerHour * _throttle / THROTTLE_REHEAT) max _idleLitresPerHour
} else {
    linearConversion [THROTTLE_REHEAT, 1, _throttle, _maxDryLitresPerHour, _maxReheatLitresPerHour, true]
};

private _capacity = getNumber (configOf _plane >> "fuelCapacity");
private _burned = _litresPerHour * FUEL_TIME_SCALE * _elapsed / 3600 / _capacity;
_plane setFuel ((_fuel - _burned) max 0);
