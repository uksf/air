#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Confirms a target as hostile when its side is hostile to the radar
        aircraft's side. Existing classifications are otherwise unchanged.

    Parameter(s):
        0: Radar aircraft <OBJECT>
        1: Target <OBJECT>

    Return Value:
        Nothing
*/
params ["_aircraft", "_target"];

if (isNull _target) exitWith {};

private _observerSide = side _aircraft;
if (_target isSensorTargetConfirmed _observerSide) exitWith {};
if ((_observerSide getFriend side _target) >= 0.6) exitWith {};

_target confirmSensorTarget [_observerSide, true];
