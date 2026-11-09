#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        One frame of the F-35 client loop: moves the afterburner light, and plays the reheat kick
        when reheat lights.

    Parameter(s):
        0: Plane <OBJECT>
        1: State, [reheat shown on the last frame] <ARRAY>

    Return Value:
        Nothing

    Example:
        [_plane, [false]] call uksf_air_f35_fnc_clientTick
*/

params ["_plane", "_state"];
_state params ["_reheatWasOn"];

[_plane] call FUNC(afterburnerLight);

private _reheatOn = _plane animationSourcePhase REHEAT_SOURCE > REHEAT_SHOWN;
if (_reheatOn && {!_reheatWasOn}) then {
    [_plane] call FUNC(reheatKick);
};
_state set [0, _reheatOn];
