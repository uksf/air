#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sequence the A400M ramp and ground-only toe through closed, airdrop and loading positions.
        Fold and hide the toe before raising the ramp, and show it flat after lowering the ramp.

    Parameter(s):
        0: Plane <OBJECT>
        1: New ramp position <SCALAR>

    Return Value:
        Nothing

    Example:
        [_plane, _newPosition] call uksf_air_patches_fnc_a400RampControl
*/
#define RAMP_LEVEL 0.54
#define TOE_UPRIGHT 0.427917
#define PHASE_DONE 0.01

params ["_plane", ["_newPosition", 0]];

private _position = round ((_newPosition max 0) min 2);
private _serial = (_plane getVariable [QGVAR(a400RampSerial), 0]) + 1;
private _ramp = [0, RAMP_LEVEL, 1] select _position;
private _toe = [TOE_UPRIGHT, 0, 1] select _position;

_plane setVariable [QGVAR(a400RampSerial), _serial];
_plane setVariable [QEGVAR(common,rampPosition), _position, true];
_plane animateSource ["ramp_top", parseNumber (_position > 0)];

[_plane, _serial, _position, _ramp, _toe] spawn {
    params ["_plane", "_serial", "_position", "_ramp", "_toe"];
    private _current = {alive _plane && {_plane getVariable [QGVAR(a400RampSerial), 0] == _serial}};
    _plane animateSource ["ramp_bottom", _plane animationSourcePhase "ramp_bottom"];
    _plane animateSource ["ramp_bottom2", 0];
    if (_plane animationSourcePhase "uksf_air_a400_toe_hide" < 0.5) then {
        waitUntil {uiSleep 0.05; !call _current || {abs (_plane animationSourcePhase "ramp_bottom2") < PHASE_DONE}};
        if (call _current) then {
            _plane animateSource ["uksf_air_a400_toe_hide", 1, true];
        };
    };
    if (!call _current) exitWith {};
    _plane animateSource ["ramp_bottom", _ramp];
    if (_position != 2) exitWith {
        _plane animateSource ["ramp_bottom2", _toe];
    };
    waitUntil {uiSleep 0.05; !call _current || {abs ((_plane animationSourcePhase "ramp_bottom") - _ramp) < PHASE_DONE && {abs (_plane animationSourcePhase "ramp_bottom2") < PHASE_DONE}}};
    if (!call _current) exitWith {};
    _plane animateSource ["uksf_air_a400_toe_hide", 0, true];
    _plane animateSource ["ramp_bottom2", _toe];
};
