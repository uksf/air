#include "script_component.hpp"
/*
    Author:
        Karel Kroonen & Tim Beswick

    Description:
        Controls drone behaviour to be changed and the altitude to be changed.

    Parameter(s):
        0: Drone <OBJECT>

    Return Value:
        Nothing
*/
params ["_drone"];

if (local _drone) then {
    _drone setVariable ["acex_headless_blacklist", true, true];
    _drone setVariable ["NOAI", 1, true];
    _drone setVariable [QGVAR(flightMode), FLIGHT_MODE_CRUISE, true];
    _drone setVariable [QGVAR(altitude), 5000, true];
    _drone setVariable [QGVAR(loiterRadius), 2000, true];
    [_drone, 5000] call FUNC(adjustAltitude);
};
