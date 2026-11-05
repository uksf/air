#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shakes the camera a little for crew inside the Apache while the M230 fires

    Parameters:
        0: Helicopter <OBJECT>
        1: Weapon <STRING>

    Return value:
        Nothing

    Example:
        [_helicopter, "CUP_Vacannon_M230_veh"] call uksf_air_apache_fnc_gunShake
*/
params ["_helicopter", "_weapon"];

if (_weapon isNotEqualTo "CUP_Vacannon_M230_veh") exitWith {};
if (objectParent player isNotEqualTo _helicopter) exitWith {};

addCamShake [0.6, 0.2, 30];
