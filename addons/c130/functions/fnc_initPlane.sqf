#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises plane

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
params ["_plane"];

if (local _plane) then {
    {_plane setHit [_x, 1]} forEach JUMP_LIGHTS_RED;
    {_plane setHit [_x, 1]} forEach JUMP_LIGHTS_GREEN;
    _plane setVariable [QGVAR(jumpLightState), 0, true];
};
