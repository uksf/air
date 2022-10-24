#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Add actions for loiter

    Parameter(s):
        None

    Return Value:
        Nothing
*/
params ["_drone"];

private _actions = [];
private _action = [QGVAR(droneActionRadius), "Loiter Radius", "", {}, {
    params ["_drone"];

    (waypointType [group _drone, currentWaypoint (group _drone)]) isEqualTo "LOITER"
}, {
    params ["_drone"];

    private _actions = [];
    private _action = [QGVAR(droneActionRadiusPlus200), "+200m", "", {
        params ["_drone"];

        private _radius = (_drone getVariable [QGVAR(loiterRadius), 2000]) + 200;
        [_drone, _radius] call FUNC(setLoiterRadius);
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionRadiusMinus200), "-200m", "", {
        params ["_drone"];

        private _radius = (_drone getVariable [QGVAR(loiterRadius), 2000]) - 200;
        [_drone, _radius] call FUNC(setLoiterRadius);
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionRadiusSet), "Set", "", {
        params ["_drone"];

        private _currentRadius = _drone getVariable [QGVAR(loiterRadius), 2000];
        ["Set Loiter Radius", [
            ["SLIDER", ["Radius (m)", "Sets the drone loiter radius in meters"], [500, 5000, _currentRadius, 0, nil, nil, 100]]
        ], {
            params ["_dialogValues", "_drone"];
            _dialogValues params ["_radius"];
            systemChat str _radius;
            
            [_drone, _radius] call FUNC(setLoiterRadius);
        }, {}, _drone] call zen_dialog_fnc_create;
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _actions
}, nil, nil, nil, [false, false, false, false, false], {
    params ["_drone", "", "", "_actionData"];

    private _group = group _drone;
    private _currentWaypoint = currentWaypoint _group;
    private _waypointPosition = getWPPos [_group, _currentWaypoint];
    private _currentRadius = _drone distance2D _waypointPosition;
    private _radius = _drone getVariable [QGVAR(loiterRadius), 2000];
    private _closeToRadius = _currentRadius > _radius - 100 && _currentRadius < _radius + 100;
    private _text = if (_closeToRadius) then {
        format ["Loiter Radius<br/>%1m", ROUND_TO_NEAREST(_radius,100)]
    } else {
        format ["Loiter Radius<br/>%1/%2m", ROUND_TO_NEAREST(_currentRadius,100), ROUND_TO_NEAREST(_radius,100)]
    };

    _actionData set [1, _text];
}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _drone];

_action = [QGVAR(droneActionDirection), "Toggle Loiter Direction", "", {
    params ["_drone"];

    private _group = group _drone;
    private _currentWaypoint = currentWaypoint _group;
    private _currentType = waypointLoiterType [_group, _currentWaypoint];
    private _newType = ["CIRCLE", "CIRCLE_L"] select (_currentType isEqualTo "CIRCLE");
    [_group, _currentWaypoint] setWaypointLoiterType _newType;
}, {
    params ["_drone"];

    (waypointType [group _drone, currentWaypoint (group _drone)]) isEqualTo "LOITER"
}, {}, nil, nil, nil, [false, false, false, false, false], {
    params ["_drone", "", "", "_actionData"];

    private _currentType = waypointLoiterType [group _drone, currentWaypoint (group _drone)];
    _actionData set [1, format ["Loiter %1", ["Clockwise", "Anti-Clockwise"] select (_currentType isEqualTo "CIRCLE")]];
}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _drone];

_actions
