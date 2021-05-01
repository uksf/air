#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Keybind command for marshall action command

    Parameter(s):
        0: Animation name <STRING>
        1: Action name <STRING>

    Return Value:
        Block keypress <BOOLEAN>
*/
params ["_animation", "_action"];

if !([ACE_player, objNull, []] call ace_common_fnc_canInteractWith) exitWith {false};

if (hmd ACE_player != QGVAR(marshallSticks)) exitWith {false};

[ACE_player, [_animation, _action]] call FUNC(marshallCommand);
true
