#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Inits map display for drone control

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        Nothing
*/
params ["_display"];

systemChat str _display;

// [_display] call FUNC(map);
// systemChat str _display;

// private _control = _display displayCtrl 51;
// systemChat str _control;

// private _drone = getConnectedUAV ACE_player;
// if (isNull _drone) exitWith {systemChat "no drone";};

// if (!isNil QGVAR(mapDrawEH)) then {_control ctrlRemoveEventHandler ["Draw", GVAR(mapDrawEH)]};
// GVAR(mapDrawEH) = [_control, "Draw", {
//     params ["_control"];
//     _thisArgs params ["_drone"];

//     private _group = group _drone;
//     private _currentWaypoint = currentWaypoint _group;
//     private _mousePosition = _control ctrlMapScreenToWorld getMousePosition;
//     private _dronePosition = getPosASL _drone;
//     private _waypointPosition = getWPPos [_group, _currentWaypoint];

//     _control drawEllipse [_dronePosition, 5, 5, 0, [0,0,1,1], ""];
//     // _control drawIcon ["\a3\ui_f\data\IGUI\Cfg\Cursors\select_target_ca.paa", [0,0,1,1], _dronePosition, 24, 24, 0, "", 1, 0.03, "TahomaB", "right"];
//     _control drawIcon ["\a3\ui_f\data\map\mapcontrol\waypoint_ca.paa", [0,0,1,1], _waypointPosition, 24, 24, 0, "", 1, 0.03, "TahomaB", "right"];

//     _control drawLine [_dronePosition, _waypointPosition, [0,0,1,1]];
    
//     if (waypointType [_group, _currentWaypoint] == "LOITER") then {
//         private _radius = _drone getVariable [QGVAR(loiterRadius), 2000];
//         _control drawEllipse [_waypointPosition, _radius, _radius, 0, [0,0,1,1], ""];
//     };    
// }, [_drone]] call CBA_fnc_addBISEventHandler;
