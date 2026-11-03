#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a covered aircraft for threat warning on this machine

    Parameters:
        0: Aircraft <OBJECT>

    Return value:
        Nothing

    Example:
        [_aircraft] call uksf_air_threatwarning_fnc_onInit
*/
params ["_aircraft"];

if (getNumber (configOf _aircraft >> QGVAR(enabled)) isNotEqualTo 1) exitWith {};

GVAR(aircraft) pushBackUnique _aircraft;
