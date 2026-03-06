#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises Apache

    Parameters:
        0: Helicopter <OBJECT>

    Return value:
        Nothing
*/
params ["_helicopter"];

if (local _helicopter) then {
    _helicopter setVariable [QGVAR(previousTailDamage), 0, true];
    _helicopter setVariable [QGVAR(previousMainDamage), 0, true];
    _helicopter setVariable [QGVAR(previousE1Damage), 0, true];
    _helicopter setVariable [QGVAR(previousE2Damage), 0, true];
    _helicopter setVariable [QGVAR(previousGunDamage), 0, true];
    _helicopter setVariable [QGVAR(previousInsDamage), 0, true];
    _helicopter setVariable [QGVAR(cmMode), 0, true];
};

if (player isEqualTo driver _helicopter) then {
    [_helicopter, "driver", player] call FUNC(getIn);
};
