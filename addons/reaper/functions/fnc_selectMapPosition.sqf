#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opens map to prompt position selection for waypoint

    Parameter(s):
        0: Drone <OBJECT>
        1: Mode <STRING>
        2: OnSelect Callback <CODE>

    Return Value:
        Nothing
*/
params ["_drone", ["_mode", FLIGHT_MODE_CRUISE], "_onSelect"];
systemChat _mode;

openMap true;
// openMap [true, true];
private _mapDisplay = findDisplay 12;
private _mapControl = _mapDisplay displayCtrl 51;


