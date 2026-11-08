#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sequence the A400M ramp and toe through closed, airdrop and loading positions.
        Opening or closing the airdrop position moves the ramp and toe together.
        Opening fully lowers the ramp first, then extends the toe.
        Leaving the loading position retracts the toe first, then moves the ramp.

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
private _from = round ((_plane getVariable [QEGVAR(common,rampPosition), 0]) max 0 min 2);
private _serial = (_plane getVariable [QGVAR(a400RampSerial), 0]) + 1;
private _ramp = [0, RAMP_LEVEL, 1] select _position;
private _toe = [TOE_UPRIGHT, 0, 1] select _position;
private _together = _from == _position || {(_from min _position) == 0 && {(_from max _position) == 1}};

_plane setVariable [QGVAR(a400RampSerial), _serial];
_plane setVariable [QEGVAR(common,rampPosition), _position, true];
_plane animateSource ["ramp_top", parseNumber (_position > 0)];

if (_together) exitWith {
    _plane animateSource ["ramp_bottom", _ramp];
    _plane animateSource ["ramp_bottom2", _toe];
};

if (_from == 2) then {
    _plane animateSource ["ramp_bottom", _plane animationSourcePhase "ramp_bottom"];
    _plane animateSource ["ramp_bottom2", _toe];
    [{
        params ["_plane", "_serial", "_toe"];
        (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) || {abs ((_plane animationSourcePhase "ramp_bottom2") - _toe) < PHASE_DONE}
    }, {
        params ["_plane", "_serial", "_toe", "_ramp"];
        if (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) exitWith {};
        _plane animateSource ["ramp_bottom", _ramp];
    }, [_plane, _serial, _toe, _ramp]] call CBA_fnc_waitUntilAndExecute;
} else {
    _plane animateSource ["ramp_bottom2", _plane animationSourcePhase "ramp_bottom2"];
    _plane animateSource ["ramp_bottom", _ramp];
    [{
        params ["_plane", "_serial", "_ramp"];
        (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) || {abs ((_plane animationSourcePhase "ramp_bottom") - _ramp) < PHASE_DONE}
    }, {
        params ["_plane", "_serial", "_ramp", "_toe"];
        if (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) exitWith {};
        _plane animateSource ["ramp_bottom2", _toe];
    }, [_plane, _serial, _ramp, _toe]] call CBA_fnc_waitUntilAndExecute;
};
