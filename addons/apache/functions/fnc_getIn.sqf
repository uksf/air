#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles crew getting in — starts damage warning PFH for pilot

    Parameters:
        0: Helicopter <OBJECT>
        1: Role <STRING>
        2: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_helicopter", "_role", "_unit"];

if (_unit isNotEqualTo player) exitWith {};
if (_role isNotEqualTo "driver" && {_role isNotEqualTo "gunner"}) exitWith {};

if (_role isEqualTo "driver" && {GVAR(damageHandlerPFHID) isEqualTo -1}) then {
    [_helicopter] call FUNC(warning);
};
