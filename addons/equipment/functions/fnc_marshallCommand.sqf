#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Animates marshall sticks command

    Parameter(s):
        0: Unit <OBJECT>
        1: Animation names <ARRAY>
            0: Animation name <STRING>
            1: Action name <STRING>

    Return Value:
        None
*/
params ["_unit", "_animations"];
_animations params ["_animation", "_action"];

["ace_common_switchMove", [_unit, _animation]] call CBA_fnc_globalEvent;
["ace_common_playAction", [_unit, _action]] call CBA_fnc_globalEvent;
