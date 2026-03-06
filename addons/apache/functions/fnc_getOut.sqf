#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles crew getting out — stops damage PFH, clears cooldowns

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

if (_role isEqualTo "driver" && {GVAR(damageHandlerPFHID) isNotEqualTo -1}) then {
    [GVAR(damageHandlerPFHID)] call CBA_fnc_removePerFrameHandler;
    GVAR(damageHandlerPFHID) = -1;
};

GVAR(cooldowns) = createHashMap;
