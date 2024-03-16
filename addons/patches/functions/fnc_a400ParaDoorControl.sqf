#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Control para doors

    Parameter(s):
        0: Plane <OBJECT>
        1: Door side <STRING>
        2: State <SCALAR>
            0 = Closed
            1 = Open

    Return Value:
        Nothing
*/
params ["_plane", "_side", "_state"];

_plane animateSource [format ["DOOR_PARA_%1", _side], [1, 0] select _state];
_plane animateSource [format ["DOOR_PARA_%1_ROT", _side], _state];

[{
    params ["_plane", "_side", "_state"];

    private _animationPhase = _plane animationSourcePhase (format ["DOOR_PARA_%1", _side]);
    private _condition = [{_this > 0}, {_this < 0.05}] select _state;
    _animationPhase call _condition
}, {
    params ["_plane", "_side", "_state"];

    _plane animateSource [format ["DOOR_PARA_%1_HIDE", _side], [1, 0] select _state];
}, _this] call CBA_fnc_waitUntilAndExecute;

