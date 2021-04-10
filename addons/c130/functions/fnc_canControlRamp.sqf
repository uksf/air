#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if ramp can be controlled from the current position

    Parameter(s):
        0: Plane <OBJECT>
        1: New ramp position <SCALAR>

    Return Value:
        True if ramp control possible <BOOLEAN>
*/
params ["_plane", ["_newPosition", 0]];

(_plane getVariable [QGVAR(rampPosition), 0]) != _newPosition
&& {[_plane, true] call FUNC(canControl)}
