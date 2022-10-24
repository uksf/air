#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adjust drone altitude

    Parameter(s):
        0: Drone <OBJECT>
        1: New altitude in feet <SCALAR>

    Return Value:
        Nothing
*/
params ["_drone", "_newAltitudeinFeet"];

systemChat str _newAltitudeinFeet;
_drone setVariable [QGVAR(altitude), _newAltitudeinFeet, true];

private _group = group _drone;
private _currentWaypoint = currentWaypoint _group;
private _waypointPosition = getWPPos [_drone, _currentWaypoint];
private _newAltitude = FEET_TO_METERS(_newAltitudeinFeet);

if (_waypointPosition isNotEqualTo [0,0,0]) then {
    {
        private _position = getWPPos _x;
        _position set [2, _newAltitude];
        _x setWPpos _position;

        if (waypointType _x == "LOITER") then {
            _x setWaypointLoiterAltitude _newAltitude;
        };
    } forEach (waypoints _group);
};

_drone flyInHeight 100;
_drone flyInHeightASL [_newAltitude, _newAltitude, _newAltitude];

[_drone, _newAltitude] call FUNC(flyToAltitude);
