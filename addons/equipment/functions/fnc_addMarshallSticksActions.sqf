#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ace interaction actions for marshall sticks

    Parameter(s):
        None

    Return Value:
        None
*/

private _fnc_getChildren = {
    params ["_target"];

    private _actions = [];
    
    {
        _x params ["_actionName", "_displayName", "_icon", "_animation", "_action"];

        private _action = [format [QGVAR(marshallActions_%1), _actionName], _displayName, format [QPATHTOF(data\marshall_sticks\%1.paa), _icon], {
            params ["", "_player", "_params"];
            [_player, _params] call FUNC(marshallCommand);
        }, {true}, {}, [_animation, _action]] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _target];
    } forEach [
        ["enginesOff", "Engines Off", "a_idle", "Acts_JetsMarshallingEnginesOff_in", QGVAR(takeMarshallSticks)],
        ["enginesOn", "Engines On", "a_idle", "Acts_JetsMarshallingEnginesOn_in", QGVAR(takeMarshallSticks)],
        ["straight", "Straight", "a_straight", "Acts_JetsMarshallingStraight_in", QGVAR(takeMarshallSticks)],
        ["slow", "Slow", "a_idle", "Acts_JetsMarshallingSlow_in", QGVAR(takeMarshallSticks)],
        ["right", "Right", "a_right", "Acts_JetsMarshallingRight_in", QGVAR(takeMarshallSticks)],
        ["left", "Left", "a_left", "Acts_JetsMarshallingLeft_in", QGVAR(takeMarshallSticks)],
        ["stop", "Stop", "a_normalstop", "Acts_JetsMarshallingStop_in", QGVAR(takeMarshallSticks)],
        ["emergencyStop", "Emergency Stop", "a_normalstop", "Acts_JetsMarshallingEmergencyStop_in", QGVAR(takeMarshallSticks)],
        ["cancel", "Cancel", "a_idle", "", "default"]
    ];

    _actions
};

private _action = [QGVAR(marshallActions), "Marshall Signals", QPATHTOF(data\marshall_sticks\lightsticks_ui.paa), {}, {hmd _player == QGVAR(marshallSticks)}, _fnc_getChildren] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
