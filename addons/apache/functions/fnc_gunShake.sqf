#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shakes the camera for crew inside the Apache while the M230 fires, at a tenth of the strength in the gunner optics where zoom magnifies it

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

addCamShake [[1.5, 0.15] select (cameraView == "GUNNER"), 0.3, 25];
