#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds or removes a radar aircraft from the machine-local IFF poll.
        The shared poll exists only while at least one radar aircraft is local.

    Parameter(s):
        0: Aircraft <OBJECT>
        1: Is local <BOOLEAN>

    Return Value:
        Nothing
*/
params ["_aircraft", "_isLocal"];

if (!_isLocal) exitWith {
    GVAR(localRadarAircraft) = GVAR(localRadarAircraft) - [_aircraft];
    if (GVAR(localRadarAircraft) isEqualTo [] && {GVAR(radarIffPFH) != -1}) then {
        [GVAR(radarIffPFH)] call CBA_fnc_removePerFrameHandler;
        GVAR(radarIffPFH) = -1;
    };
};

private _hasActiveRadar = (listVehicleSensors _aircraft) findIf {
    (_x#0) isEqualTo "ActiveRadarSensorComponent"
} != -1;
if (!_hasActiveRadar) exitWith {};

GVAR(localRadarAircraft) pushBackUnique _aircraft;
if (GVAR(radarIffPFH) == -1) then {
    GVAR(radarIffPFH) = [FUNC(radarIffPFH), 2] call CBA_fnc_addPerFrameHandler;
};
