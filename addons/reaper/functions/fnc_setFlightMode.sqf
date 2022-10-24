#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets drone flight mode

    Parameter(s):
        0: Drone <OBJECT>
        1: Mode <STRING>

    Return Value:
        Nothing
*/
params ["_drone", ["_mode", FLIGHT_MODE_CRUISE]];
systemChat _mode;

switch (_mode) do {
    case FLIGHT_MODE_CRUISE: {
        _drone setVariable [QGVAR(flightMode), FLIGHT_MODE_CRUISE, true];
        _drone forceSpeed FLIGHT_SPEED_CRUISE;
    };
    case FLIGHT_MODE_OBSERVE: {
        _drone setVariable [QGVAR(flightMode), FLIGHT_MODE_OBSERVE, true];
        _drone forceSpeed FLIGHT_SPEED_OBSERVE;
    };
    case FLIGHT_MODE_STRIKE: {
        _drone setVariable [QGVAR(flightMode), FLIGHT_MODE_STRIKE, true];
    };
};
