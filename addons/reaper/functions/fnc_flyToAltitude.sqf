#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Fly drone to new altitude

    Parameter(s):
        0: Drone <OBJECT>
        1: New altitude <SCALAR>

    Return Value:
        Nothing
*/
params ["_drone", "_newAltitude"];

if (GVAR(flyToAltitudeHandlerId) != 1) then {
    [GVAR(flyToAltitudeHandlerId)] call CBA_fnc_removePerFrameHandler;
};

GVAR(flyToAltitudeHandlerId) = [{
    params ["_args", "_idPFH"];
    _args params ["_drone", "_newAltitude"];

    if (!alive _drone) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(flyToAltitudeHandlerId) = -1;
    };

    private _flightMode = _drone getVariable [QGVAR(flightMode), FLIGHT_MODE_CRUISE];
    if (_flightMode == FLIGHT_MODE_STRIKE) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(flyToAltitudeHandlerId) = -1;
        _drone forceSpeed FLIGHT_SPEED_CRUISE;
    };

    private _currentAltitude = (getPosASL _drone)#2;
    private _closeToAltitude = _currentAltitude > _newAltitude - 250 && _currentAltitude < _newAltitude + 250;
    if (_closeToAltitude) exitWith {
        private _speed = [FLIGHT_SPEED_CRUISE, FLIGHT_SPEED_OBSERVE] select (_flightMode == FLIGHT_MODE_OBSERVE);
        systemChat str _speed;
        _drone forceSpeed _speed;
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(flyToAltitudeHandlerId) = -1;
    };

    private _descending = _newAltitude < _currentAltitude;
    if (_descending) then {
        systemChat "descending";
        _drone forceSpeed FLIGHT_SPEED_DESCEND;
    };

    _drone forceSpeed FLIGHT_SPEED_CLIMB;
}, 5, _this] call CBA_fnc_addPerFrameHandler;
