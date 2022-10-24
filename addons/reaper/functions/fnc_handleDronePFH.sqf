#include "script_component.hpp"
/*
    Author:
        Karel Kroonen & Tim Beswick

    Description:
        Controls drone behaviour to be changed and the altitude to be changed.

    Parameter(s):
        0: Args <ARRAY>
            0: UAV <OBJECT>
            1: Current seat <STRING>
            2: Height changed
            3: Last waypoint
        1: PFH ID <SCALAR>

    Return Value:
        Nothing
*/
params ["_args", "_idPFH"];
_args params ["_uav", "_seat", "_heightChanged", "_lastWaypoint"];

private _currentUav = ACE_controlledUAV#0;
if (isNull _currentUav || {_currentUav != _uav}) exitWith {
    WARNING_2("Current uav (%1) is not the same as the context uav (%2)",_currentUav,_uav);
    [_idPFH] call CBA_fnc_removePerFrameHandler;
    GVAR(displayHandlerId) = -1;
};

if (_seat isEqualTo "GUNNER" && {cameraView isEqualTo "GUNNER"}) then {
    [_uav] call FUNC(updateDisplay);
};

if (true) exitWith {};

private _waypointHeight = (getWPPos [_uav, 1])#2;
private _diveMode = _uav getVariable [QGVAR(diveMode), false];
private _observationMode = _uav getVariable [QGVAR(observationMode), true];
private _targetHeightASL = _uav getVariable [QGVAR(targetHeightASL), 5000];
private _targetHeightASLMeters = FEET_TO_METERS(_targetHeightASL);
private _customWaypoint = _uav getVariable [QGVAR(customWaypoint), false];
private _currentWaypoint = currentWaypoint (group _uav);
private _specificDistance = (getPosATL _uav)#2;
if (((getWPPos [_uav, _currentWaypoint])#2) != 0) then {
    _specificDistance = (getWPPos [_uav, _currentWaypoint])#2;
};

// Sets the height of all current waypoints to _targetHeightASL if set.
if (_customWaypoint && !_heightChanged) then {
    if (!(((getWPPos [_uav, _currentWaypoint])#2) == _targetHeightASLMeters)) then {
        {
            private _pos = getWPPos _x;
            _pos set [2, _targetHeightASLMeters];
            _x setWPpos _pos;
        } forEach waypoints (group _uav);
        _waypointHeight = _targetHeightASLMeters;
    };
};

private _newSpeed = -1;

// Slows down the drone if it is in observation mode and close to its waypoint, unlimits speed when it's far from its waypoint.
if (_observationMode && ((getPosATL _uav) distance2D (getWPPos [_uav, _currentWaypoint])) < (waypointLoiterRadius [_uav, _currentWaypoint] + 500)) then {
    _newSpeed = 35;
} else {
    if (!_diveMode) then {
        _newSpeed = -1;
    };
};

// Limits speed of the drone when it is getting close to its waypoint (so target can be acquired).
// Then nosedives the drone in order for the hellfire to get a lock on the laser.
// Once waypoint is completed drone speed is unlimited and drone climbs back to its original altitude.
if (_diveMode && ((getPosATL _uav) distance2D (getWPPos [_uav, _currentWaypoint]) < (4000 min (_specificDistance * 3))) && !_heightChanged) then {
    _newSpeed = 35;
    if (((getPosATL _uav) distance2D (getWPPos [_uav, _currentWaypoint])) < (_specificDistance * 1.5)) then {
        _targetHeightASLMeters = 200 max (_specificDistance - 200);
        _heightChanged = true;
        _newSpeed = -1;
    };
} else {
    if (_lastWaypoint < _currentWaypoint) then {
        _heightChanged = false;
        _uav setVariable [QGVAR(diveMode), false, true];
        _newSpeed = -1;
        _targetHeightASLMeters = 200 max _waypointHeight;
    };
};

if (!local _uav) then {
    [QGVAR(forceSpeed), [_uav, _newSpeed], _uav] call CBA_fnc_targetEvent;
    [QGVAR(flyInHeightASL), [_uav, [_targetHeightASLMeters, _targetHeightASLMeters, _targetHeightASLMeters]], _uav] call CBA_fnc_targetEvent;
} else {
    _uav forceSpeed _newSpeed;
    _uav flyInHeightASL [_targetHeightASLMeters, _targetHeightASLMeters, _targetHeightASLMeters];
    _uav flyinHeight ((_targetHeightASLMeters - 500) max 300);
};

// Update vars
_args set [2, _heightChanged];
_args set [3, _currentWaypoint];
