#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ace interaction actions to drone for control

    Parameter(s):
        None

    Return Value:
        Nothing
*/

private _action = [QGVAR(droneActionBehaviour), "Behaviour", "", {}, {true}, {
    params ["_target", "_player", "_params"];

    private _actions = [];
    private _action = [QGVAR(droneActionBehaviourStrike), "Strike", "", {
        _target setVariable [QGVAR(diveMode), true, true];
        _target setVariable [QGVAR(observationMode), false, true];
    }, {!(_target getVariable [QGVAR(diveMode), false])}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionBehaviourObserver), "Observer", "", {
        _target setVariable [QGVAR(diveMode), false, true];
        _target setVariable [QGVAR(observationMode), true, true];
    }, {!(_target getVariable [QGVAR(observationMode), false])}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionBehaviourReset), "Reset", "", {
        _target setVariable [QGVAR(diveMode), false, true];
        _target setVariable [QGVAR(observationMode), false, true];
    }, {_target getVariable [QGVAR(diveMode), false] || _target getVariable [QGVAR(observationMode), false]}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _actions
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionAltitude), "Altitude", "", {}, {true}, {
    params ["_target", "_player", "_params"];

    private _actions = [];
    private _action = [QGVAR(droneActionAltitudePlus500), "+500ft", "", {
        private _height = (_target getVariable [QGVAR(targetHeightASL), 5000]) + 500;
        _target setVariable [QGVAR(targetHeightASL), _height, true];
        _target setVariable [QGVAR(customWaypoint), true, true];
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionAltitudeMinus500), "-500ft", "", {
        private _height = (_target getVariable [QGVAR(targetHeightASL), 5000]) - 500;
        _target setVariable [QGVAR(targetHeightASL), _height, true];
        _target setVariable [QGVAR(customWaypoint), true, true];
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionAltitudeReset), "Reset", "", {
        _target setVariable [QGVAR(customWaypoint), false, true];
    }, {_target getVariable [QGVAR(customWaypoint), false]}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    {
        _action = [
            format [QGVAR(droneActionAltitude%1), _x],
            format ["%1ft", _x],
            "",
            {
                _target setVariable [QGVAR(targetHeightASL), (_this#2)#0, true];
                _target setVariable [QGVAR(customWaypoint), true, true];
            },
            {(_target getVariable [QGVAR(targetHeightASL), 5000]) != ((_this#2)#0)},
            {},
            [_x]
        ] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _target];
    } forEach [3500, 5000, 6500];

    _actions
}, nil, nil, nil, [false, false, false, false, false], {
    params ["_target", "_player", "_params", "_actionData"];

    private _group = group _target;
    private _customWaypoint = _target getVariable [QGVAR(customWaypoint), false];
    private _altitude = 5000;
    if (_customWaypoint) then {
        _altitude = _target getVariable [QGVAR(targetHeightASL), 5000];
    } else {
        private _waypointPos = getWPPos [_target, currentWaypoint (group _target)];
        if (_waypointPos#2 == 0) then {
            _altitude = (getPosASL _target)#2;
        } else {
            _altitude = _waypointPos#2;
        };

        _altitude = ROUND_TO_10(METERS_TO_FEET(_altitude));
    };

    _actionData set [1, format ["Altitude (%1ft)", _altitude]];
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionRadius), "Loiter Radius", "", {}, {
    params ["_target", "_player", "_params"];

    (waypointType [group _target, currentWaypoint (group _target)]) isEqualTo 'LOITER'
}, {
    params ["_target", "_player", "_params"];

    private _actions = [];
    private _action = [QGVAR(droneActionRadiusPlus200), "+200m", "", {
        private _radius = (waypointLoiterRadius [group _target, currentWaypoint (group _target)]) + 200;
        [group _target, currentWaypoint (group _target)] setWaypointLoiterRadius _radius;
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionRadiusMinus200), "-200m", "", {
        private _radius = (waypointLoiterRadius [group _target, currentWaypoint (group _target)]) - 200;
        [group _target, currentWaypoint (group _target)] setWaypointLoiterRadius _radius;
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    {
        _action = [
            format [QGVAR(droneActionRadius%1m), _x],
            format ["%1m", _x],
            "",
            {[group _target, currentWaypoint (group _target)] setWaypointLoiterRadius (_this#2)#0;},
            {(waypointLoiterRadius [group _target, currentWaypoint (group _target)]) != (_this#2)#0},
            {},
            [_x]
        ] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _target];
    } forEach [1000, 1500, 2000];

    _actions
}, nil, nil, nil, [false, false, false, false, false], {
    params ["_target", "", "", "_actionData"];

    private _radius = waypointLoiterRadius [group _target, currentWaypoint (group _target)];
    _actionData set [1, format ["Loiter Radius (%1m)", _radius]];
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionDirection), "Toggle Loiter Direction", "", {
    params ["_target", "_player", "_params"];

    private _group = group _target;
    private _currentType = waypointLoiterType [_group, currentWaypoint _group];
    private _newType = ["CIRCLE", "CIRCLE_L"] select (_currentType isEqualTo "CIRCLE");
    [_group, currentWaypoint _group] setWaypointLoiterType _newType;
}, {
    params ["_target", "", ""];

    (waypointType [group _target, currentWaypoint (group _target)]) isEqualTo 'LOITER'
}, {}, nil, nil, nil, [false, false, false, false, false], {
    params ["_target", "", "", "_actionData"];

    private _currentType = waypointLoiterType [group _target, currentWaypoint (group _target)];
    _actionData set [1, format ["Loiter %1", ["Clockwise", "Anti-Clockwise"] select (_currentType isEqualTo "CIRCLE")]];
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionWaypoint), "Waypoints", "", {}, {true}, {
    params ["_target", "_player", "_params"];

    private _actions = [];
    private _action = [QGVAR(droneActionWaypointLoiter), "Loiter", "", {
        [group _target, currentWaypoint (group _target)] setWaypointType 'LOITER';
        [group _target, currentWaypoint (group _target)] setWaypointLoiterRadius 2000;
        _target setVariable [QGVAR(diveMode), false, true];
        _target setVariable [QGVAR(observationMode), true, true];
    }, {(waypointType [group _target, currentWaypoint (group _target)]) != 'LOITER'}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionWaypointMove), "Move", "", {
        [group _target, currentWaypoint (group _target)] setWaypointType 'MOVE';
        _target setVariable [QGVAR(diveMode), false, true];
        _target setVariable [QGVAR(observationMode), false, true];
    }, {(waypointType [group _target, currentWaypoint (group _target)]) != 'MOVE'}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionWaypointDelete), "Delete", "", {
        {deleteWaypoint [group _target, 1]} forEach (waypoints (group _target));
    }, {(count (waypoints group _target)) > 1}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionWaypointMoveToCrosshair), "Move To Crosshair", "", {[_target, 0] call FUNC(moveTo)}, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionWaypointLoiterAtCrosshair), "Loiter At Crosshair", "", {[_target, 1] call FUNC(moveTo)}, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _action = [QGVAR(droneActionWaypointStrikeCrosshair), "Strike Crosshair", "", {[_target, 2] call FUNC(moveTo)}, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _target];

    _actions
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionCompass), "Compass", "", {
    private _state = _target getVariable [QGVAR(compassState), false];
    _target setVariable [QGVAR(compassState), !_state];
}, {true}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionImmobilise), "Immobilise", "", {[_target, true] call FUNC(immobilise)}, {
    speed _target < 10 && {!(_target getVariable [QGVAR(immobilised), false])}
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionMobilise), "Mobilise", "", {[_target, false] call FUNC(immobilise)}, {
    speed _target < 10 && {_target getVariable [QGVAR(immobilised), false]}
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
