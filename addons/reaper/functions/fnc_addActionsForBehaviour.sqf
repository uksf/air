#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Add actions for behaviour

    Parameter(s):
        None

    Return Value:
        Nothing
*/
params ["_drone"];

private _actions = [];
private _action = [QGVAR(droneActionBehaviour), "Behaviour", "", {}, {true}, {
    params ["_drone"];

    private _actions = [];

    {
        _x params ["_mode", "_text"];

        private _action = [
            format [QGVAR(droneActionBehaviour%1), _text],
            _text,
            "",
            {
                params ["_drone", "", "_params"];
                _params params ["_mode"];

                [_drone, _mode] call FUNC(setFlightMode);
            },
            {
                params ["_drone", "", "_params"];
                _params params ["_mode"];

                (_drone getVariable [QGVAR(flightMode), FLIGHT_MODE_CRUISE]) != _mode
            },
            {},
            _x
        ] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _drone];
    } forEach [[FLIGHT_MODE_CRUISE, "Cruise"], [FLIGHT_MODE_OBSERVE, "Observe"], [FLIGHT_MODE_STRIKE, "Strike"]];

    _actions
}] call ace_interact_menu_fnc_createAction;
_actions pushBack [_action, [], _drone];

_actions
