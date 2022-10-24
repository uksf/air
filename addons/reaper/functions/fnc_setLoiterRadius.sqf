#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets drone loiter radius

    Parameter(s):
        0: Drone <OBJECT>
        1: Radius <SCALAR>

    Return Value:
        Nothing
*/
params ["_drone", "_radius"];

_drone setVariable [QGVAR(loiterRadius), _radius, true];

private _group = group _drone;
private _currentWaypoint = currentWaypoint _group;
[_group, _currentWaypoint] setWaypointLoiterRadius _radius;
[_drone, _drone getVariable [QGVAR(altitude), 5000]] call FUNC(adjustAltitude);
