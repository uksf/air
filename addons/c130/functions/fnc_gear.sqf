#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Switches gear lights on or off based on gear state

    Parameter(s):
        0: Plane <OBJECT>
        1: Gear State <BOLEAN>

    Return Value:
        Nothing
*/
params ["_plane", "_gearState"];

if !(local _plane) exitWith {};

private _jumpLightState = _plane getVariable [QGVAR(jumpLightState), 0];
if (_jumpLightState != 0) exitWith {};

private _state = [1, 0] select _gearState;
{_plane setHit [_x, _state]} forEach ["L svetlo", "P svetlo"];
