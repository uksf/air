#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Set ramp position

    Parameter(s):
        0: Plane <OBJECT>
        1: New ramp position <SCALAR>

    Return Value:
        Nothing
*/
params ["_plane", ["_newPosition", 0]];

private _bottomValue = _newPosition / 2;
private _topValue = [0, 1] select (_newPosition > 0);

_plane animateSource ["ramp_bottom", _bottomValue, 1];
_plane animateSource ["ramp_top", _topValue, 1];
_plane setVariable [QGVAR(rampPosition), _newPosition, true];
