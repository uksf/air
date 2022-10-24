#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets drone waypoint to given position for given mode

    Parameter(s):
        0: Drone <OBJECT>
        1: Mode <STRING>
        2: Position <ARRAY>

    Return Value:
        Nothing
*/
params ["_drone", ["_mode", FLIGHT_MODE_CRUISE], ["_position", []]];
systemChat _mode;

private _group = group _drone;
private _currentWaypoint = currentWaypoint _group;
private _waypointPosition = getWPPos [_group, _currentWaypoint];
if (_waypointPosition isEqualTo [0,0,0] && _position isEqualTo []) exitWith {
    [QUGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FFFF00'>DRONE HAS NO WAYPOINT</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _units] call CBA_fnc_targetEvent;
};

if (_waypointPosition isEqualTo [0,0,0]) then {
    // Default waypoint
    private _waypoint = _group addWaypoint [_position, 0];
    _group setCurrentWaypoint _waypoint;
    _currentWaypoint = currentWaypoint _group;
};

if (_position isEqualTo []) then {
    _position = getWPPos [_group, _currentWaypoint];
};



[_group, _currentWaypoint] setWPpos _position;

switch (_mode) do {
    case FLIGHT_MODE_CRUISE: {
        [_group, _currentWaypoint] setWaypointType 'MOVE';
        [_drone, FLIGHT_MODE_CRUISE] call FUNC(setFlightMode);
    };
    case FLIGHT_MODE_OBSERVE: {
        [_group, _currentWaypoint] setWaypointType 'LOITER';
        [_drone, _drone getVariable [QGVAR(loiterRadius), 2000]] call FUNC(setLoiterRadius);
        [_drone, FLIGHT_MODE_OBSERVE] call FUNC(setFlightMode);
    };
    case FLIGHT_MODE_STRIKE: {
        [_drone, FLIGHT_MODE_STRIKE] call FUNC(setFlightMode);
        [_drone] call FUNC(strike);
    };
};

[_drone, _drone getVariable [QGVAR(altitude), 5000]] call FUNC(adjustAltitude);
