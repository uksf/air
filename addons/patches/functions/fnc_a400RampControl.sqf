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

    Example:
        [_plane, _newPosition] call uksf_air_patches_fnc_a400RampControl
*/
#define RAMP_LEVEL 0.54

params ["_plane", ["_newPosition", 0]];

private _bottomValue = [0, RAMP_LEVEL, 1] select (_newPosition min 2);
private _toeValue = parseNumber (_newPosition >= 2);
private _topValue = parseNumber (_newPosition > 0);
private _values = [_bottomValue, _toeValue, _topValue];

{
    _plane animate [_x, _values select _forEachIndex, 1];
    _plane animateSource [_x, _values select _forEachIndex, 1];
} forEach ["ramp_bottom", "ramp_bottom2", "ramp_top"];
_plane setVariable [QEGVAR(common,rampPosition), _newPosition, true];
