#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds the ACE self-interaction that switches an aircraft's threat warning system off and on.
        Only flight-seat occupants of a covered aircraft see it. The state is shared with the whole crew.

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_air_threatwarning_fnc_addActions
*/
private _action = [
    QGVAR(toggle),
    "Threat warning",
    "",
    {
        private _aircraft = vehicle _player;
        _aircraft setVariable [QGVAR(off), !(_aircraft getVariable [QGVAR(off), false]), true];
    },
    {
        private _aircraft = vehicle _player;
        getNumber (configOf _aircraft >> QGVAR(enabled)) isEqualTo 1 && {[_aircraft, _player] call FUNC(isFlightSeat)}
    },
    {},
    [],
    "",
    2,
    [false, false, false, false, false],
    {
        params ["_target", "_player", "", "_actionData"];
        _actionData set [1, ["Threat warning: switch off", "Threat warning: switch on"] select ((vehicle _player) getVariable [QGVAR(off), false])];
    }
] call ace_interact_menu_fnc_createAction;

["Air", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
