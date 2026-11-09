#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        One frame of the Typhoon client loop: plays the reheat kick when the reheat flame lights,
        and sets HMD visibility when the player flies the plane.

    Parameter(s):
        0: Plane <OBJECT>
        1: State, [reheat flame shown on the last frame] <ARRAY>

    Return Value:
        Nothing

    Example:
        [_plane, [false]] call uksf_air_typhoon_fnc_clientTick
*/

params ["_plane", "_state"];
_state params ["_reheatWasOn"];

private _reheatOn = _plane animationPhase REHEAT_FLAME_HIDE < REHEAT_FLAME_SHOWN;
if (_reheatOn && {!_reheatWasOn}) then {
    [_plane] call FUNC(reheatKick);
};
_state set [0, _reheatOn];

if (ACE_player == driver _plane) then {
    [_plane] call FUNC(hmdVisibility);
};
