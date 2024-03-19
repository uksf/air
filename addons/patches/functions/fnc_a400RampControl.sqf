#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Set ramp position for A400M

    Parameter(s):
        0: Plane <OBJECT>
        1: New ramp position <SCALAR>

    Return Value:
        Nothing
*/
#define RAMP_HALF 0.6

params ["_plane", ["_newPosition", 0]];

private _bottomValue = (_newPosition * RAMP_HALF) min 1;
private _topValue = [0, 1] select (_newPosition > 0);

_plane animate ["ramp_bottom", _bottomValue, 1];
_plane animate ["ramp_bottom2", _topValue, 1];
_plane animate ["ramp_top", _topValue, 1];
_plane setVariable [QEGVAR(common,rampPosition), _newPosition, true];
