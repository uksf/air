#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sequence the A400M ramp and toe through closed, airdrop and loading positions.

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

params ["_plane", ["_newPosition", 0]];

private _position = (_newPosition max 0) min 2;
private _serial = (_plane getVariable [QGVAR(a400RampSerial), 0]) + 1;
_plane setVariable [QGVAR(a400RampSerial), _serial];
_plane setVariable [QEGVAR(common,rampPosition), _position, true];
_plane animateSource ["ramp_bottom2", TOE_UPRIGHT];
_plane animateSource ["ramp_top", parseNumber (_position > 0)];

[{
    params ["_plane", "_position", "_serial"];
    (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) || {abs ((_plane animationSourcePhase "ramp_bottom2") - TOE_UPRIGHT) < 0.01}
}, {
    params ["_plane", "_position", "_serial"];
    if (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) exitWith {};
    private _bottom = [0, RAMP_LEVEL, 1] select _position;
    _plane animateSource ["ramp_bottom", _bottom];
    [{
        params ["_plane", "_position", "_serial", "_bottom"];
        (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) || {abs ((_plane animationSourcePhase "ramp_bottom") - _bottom) < 0.01}
    }, {
        params ["_plane", "_position", "_serial"];
        if (_plane getVariable [QGVAR(a400RampSerial), 0] != _serial) exitWith {};
        _plane animateSource ["ramp_bottom2", [TOE_UPRIGHT, 0, 1] select _position];
    }, [_plane, _position, _serial, _bottom]] call CBA_fnc_waitUntilAndExecute;
}, [_plane, _position, _serial]] call CBA_fnc_waitUntilAndExecute;
