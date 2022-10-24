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
private _action = [QGVAR(droneActionPositioning), "Positioning", "", {}, {true}, {
    private _actions = [];

    _actions append (call FUNC(addActionsForAltitude));
    _actions append (call FUNC(addActionsForBehaviour));
    _actions append (call FUNC(addActionsForLoiter));
    _actions append (call FUNC(addActionsForWaypoints));

    _actions
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionCompass), "Compass", "", {
    params ["_drone"];

    private _state = _drone getVariable [QGVAR(compassState), false];
    _drone setVariable [QGVAR(compassState), !_state];
}, {true}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionImmobilise), "Immobilise", "", {
    params ["_drone"];

    [_drone, true] call FUNC(immobilise)
}, {
    params ["_drone"];

    speed _drone < 10 && {!(_drone getVariable [QGVAR(immobilised), false])}
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(droneActionMobilise), "Mobilise", "", {
    params ["_drone"];

    [_drone, false] call FUNC(immobilise)
}, {
    params ["_drone"];

    speed _drone < 10 && {_drone getVariable [QGVAR(immobilised), false]}
}] call ace_interact_menu_fnc_createAction;
[QGVAR(raf), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
