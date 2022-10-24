#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Add actions for altitude

    Parameter(s):
        None

    Return Value:
        Nothing
*/
params ["_drone"];

private _actions = [];
private _action = [QGVAR(droneActionAltitude), "Altitude", "", {}, {true}, {
    params ["_drone"];

    private _actions = [];
    private _action = [QGVAR(droneActionAltitudePlus500), "+500ft", "", {
        params ["_drone"];

        private _altitude = (_drone getVariable [QGVAR(altitude), 5000]) + 500;
        [_drone, _altitude] call FUNC(adjustAltitude);
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionAltitudeMinus500), "-500ft", "", {
        params ["_drone"];

        private _altitude = (_drone getVariable [QGVAR(altitude), 5000]) - 500;
        [_drone, _altitude] call FUNC(adjustAltitude);
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _action = [QGVAR(droneActionAltitudeSet), "Set", "", {
        params ["_drone"];

        private _currentAltitude = _drone getVariable [QGVAR(altitude), 5000];
        ["Set Altitude", [
            ["SLIDER", ["Altitude (ft)", "Sets the drone altitude ASL in feet"], [500, 20000, _currentAltitude, 0, nil, nil, 500]]
        ], {
            params ["_dialogValues", "_drone"];
            _dialogValues params ["_altitude"];
            systemChat str _altitude;
            
            [_drone, _altitude] call FUNC(adjustAltitude);
        }, {}, _drone] call zen_dialog_fnc_create;
    }, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _drone];

    _actions
}, nil, nil, nil, [false, false, false, false, false], {
    params ["_drone", "", "", "_actionData"];

    private _altitude = _drone getVariable [QGVAR(altitude), 5000];
    private _currentAltitude = METERS_TO_FEET((getPosASL _drone)#2);
    private _closeToAltitude = _currentAltitude > _altitude - 150 && _currentAltitude < _altitude + 150;
    private _text = if (_closeToAltitude) then {
        format ["Altitude<br/>%1ft", ROUND_TO_NEAREST(_altitude,100)]
    } else {
        format ["Altitude<br/>%1/%2ft", ROUND_TO_NEAREST(_currentAltitude,100), ROUND_TO_NEAREST(_altitude,100)]
    };

    _actionData set [1, _text];
}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _drone];

_actions
