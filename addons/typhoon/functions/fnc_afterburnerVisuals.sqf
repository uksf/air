#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens or closes the reheat nozzles and shows or hides the reheat flames, using the EAWS
        model's own animations and flame textures. On light-up the nozzles open first and the
        flame follows once they are open, as on the EJ200. On shutdown the flame goes out at
        once. Called only when reheat changes state, because the animations and textures are
        broadcast.

    Parameter(s):
        0: Plane <OBJECT>
        1: Reheat on <BOOL>

    Return Value:
        Nothing

    Example:
        [_plane, true] call uksf_air_typhoon_fnc_afterburnerVisuals
*/
#define TEXTURE_FLAME "\EAWS_EF2000\data\SU35_engine_fire_high_ca.paa"
#define TEXTURE_EMPTY "\EAWS_EF2000\data\SU35_engine_empty_ca.paa"
#define FLAME_SELECTION_LEFT 6
#define FLAME_SELECTION_RIGHT 7
#define NOZZLE_OPEN_TIME 0.3

params ["_plane", "_on"];

private _phase = [0, 1] select _on;
for "_i" from 1 to 8 do {
    _plane animate [format ["engine_nozzle_l_%1", _i], _phase];
    _plane animate [format ["engine_nozzle_r_%1", _i], _phase];
};

private _setFlame = {
    params ["_plane", "_on"];
    private _phase = [0, 1] select _on;
    _plane setObjectTextureGlobal [FLAME_SELECTION_LEFT, [TEXTURE_EMPTY, TEXTURE_FLAME] select _on];
    _plane setObjectTextureGlobal [FLAME_SELECTION_RIGHT, [TEXTURE_EMPTY, TEXTURE_FLAME] select _on];
    _plane animate ["afterburner_left_userhide", 1 - _phase];
    _plane animate ["afterburner_right_userhide", 1 - _phase];
};

if (!_on) exitWith {
    [_plane, false] call _setFlame;
};

[_plane] call FUNC(nozzles);
[{
    params ["_plane", "_setFlame"];
    if (alive _plane && {_plane getVariable [QGVAR(afterburnerEngaged), false]}) then {
        [_plane, true] call _setFlame;
    };
}, [_plane, _setFlame], NOZZLE_OPEN_TIME] call CBA_fnc_waitAndExecute;
