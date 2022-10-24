#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Open dialog to select reaper drone to connect to

    Parameter(s):
        None

    Return Value:
        Nothing
*/
private _drones = (allUnitsUAV select {_x isKindOf QGVAR(raf) && (getConnectedUAV ACE_player) != _x});
["Connect to Reaper Drone", [
    ["COMBO", "Select Reaper Drone", [_drones, _drones apply {groupId group _x}, 0]]
], {
    params ["_values", "_args"];
    _values params ["_drone"];
    
    ACE_player connectTerminalToUAV _drone;
}, {}, []] call zen_dialog_fnc_create;
