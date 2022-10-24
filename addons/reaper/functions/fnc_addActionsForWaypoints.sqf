#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Add actions for waypoints

    Parameter(s):
        None

    Return Value:
        Nothing
*/
params ["_drone"];

private _actions = [];
private _action = [QGVAR(droneActionWaypoint), "Waypoints", "", {}, {true}, {
    params ["_drone"];

    private _actions = [];
    private _action = [QGVAR(droneActionWaypointLoiter), "Loiter", "", {
        params ["_drone"];

        [_drone, FLIGHT_MODE_OBSERVE] call FUNC(setWaypoint);
    }, {
        params ["_drone"];

        private _group = group _drone;
        private _currentWaypoint = currentWaypoint _group;
        (getWPPos [_group, _currentWaypoint]) isNotEqualTo [0,0,0]
        && (waypointType [_group, _currentWaypoint]) != "LOITER"
    }] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionWaypointMove), "Move", "", {
        params ["_drone"];

        [_drone, FLIGHT_MODE_CRUISE] call FUNC(setWaypoint);
    }, {
        params ["_drone"];

        private _group = group _drone;
        private _currentWaypoint = currentWaypoint _group;
        (getWPPos [_group, _currentWaypoint]) isNotEqualTo [0,0,0]
        && (waypointType [_group, currentWaypoint _group]) != "MOVE"
    }] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionWaypointDelete), "Delete", "", {
        params ["_drone"];

        private _group = group _drone;
        {deleteWaypoint [_group, 1]} forEach (waypoints _group);
        [_drone, FLIGHT_MODE_CRUISE] call FUNC(setFlightMode);
        [_drone, _drone getVariable [QGVAR(altitude), 5000]] call FUNC(adjustAltitude);
    }, {
        params ["_drone"];

        (count (waypoints group _drone)) > 1
    }] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionWaypointsCrosshair), "Crosshair", "", {}, {true}, {
        params ["_drone"];

        private _actions = [];
        private _action = [QGVAR(droneActionWaypointCrosshairMoveTo), "Move To", "", {
            params ["_drone"];

            private _screenPosition = screenToWorld [0.5, 0.5];
            private _altitude = _drone getVariable [QGVAR(altitude), 5000];
            [_drone, FLIGHT_MODE_CRUISE, [_screenPosition#0, _screenPosition#1, FEET_TO_METERS(_altitude)]] call FUNC(setWaypoint);
        }, {true}] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _drone];

        _action = [QGVAR(droneActionWaypointCrosshairLoiterAt), "Loiter At", "", {
            params ["_drone"];

            private _screenPosition = screenToWorld [0.5, 0.5];
            private _altitude = _drone getVariable [QGVAR(altitude), 5000];
            [_drone, FLIGHT_MODE_OBSERVE, [_screenPosition#0, _screenPosition#1, FEET_TO_METERS(_altitude)]] call FUNC(setWaypoint);
        }, {true}] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _drone];

        _action = [QGVAR(droneActionWaypointCrosshairStrike), "Strike", "", {
            params ["_drone"];

            private _screenPosition = screenToWorld [0.5, 0.5];
            private _altitude = _drone getVariable [QGVAR(altitude), 5000];
            [_drone, FLIGHT_MODE_STRIKE, [_screenPosition#0, _screenPosition#1, FEET_TO_METERS(_altitude)]] call FUNC(setWaypoint);
        }, {true}] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _drone];

        _actions
    }] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionWaypointsMap), "Map", "", {}, {true}, {
        params ["_drone"];

        private _actions = [];
        private _action = [QGVAR(droneActionWaypointMapMoveTo), "Move To", "", {
            params ["_drone"];
            
            [_drone, FLIGHT_MODE_CRUISE, {
                params ["_drone", "_position"];

                [_drone, FLIGHT_MODE_CRUISE, _position] call FUNC(setWaypoint);
            }] call FUNC(selectMapPosition);
        }, {true}] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _drone];

        _action = [QGVAR(droneActionWaypointMapLoiterAt), "Loiter At", "", {
            params ["_drone"];
            
            [_drone, FLIGHT_MODE_OBSERVE, {
                params ["_drone", "_position"];

                [_drone, FLIGHT_MODE_OBSERVE, _position] call FUNC(setWaypoint);
            }] call FUNC(selectMapPosition);
        }, {true}] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _drone];

        _action = [QGVAR(droneActionWaypointMapStrike), "Strike", "", {
            params ["_drone"];
            
            [_drone, FLIGHT_MODE_STRIKE, {
                params ["_drone", "_position"];

                [_drone, FLIGHT_MODE_STRIKE, _position] call FUNC(setWaypoint);
            }] call FUNC(selectMapPosition);
        }, {true}] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _drone];

        _actions
    }] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _actions
}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _drone];

_actions
