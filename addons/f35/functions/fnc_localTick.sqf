#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        One frame of the F-35 local loop. On a destroyed plane it only puts out the reheat.
        Otherwise it drives thrust vectoring and the speedbrake every frame, reheat once each
        mission-time step, and the fuel burn and mass every FUEL_INTERVAL. The F135 makes
        28,000 lbf dry and 43,000 lbf in reheat (Pratt & Whitney); at the published estimate of
        0.7 and 2.0 lb/lbf/h that burns about 8,900 kg/h dry and 39,000 kg/h in reheat, jet fuel
        at 0.8 kg/L. Mass is the F-35B's 14,651 kg empty mass (Lockheed Martin) plus fuel, stores
        and crew.

    Parameter(s):
        0: Plane <OBJECT>
        1: State, [last reheat mission time, next fuel burn time] <ARRAY>

    Return Value:
        Nothing

    Example:
        [_plane, [CBA_missionTime, 0]] call uksf_air_f35_fnc_localTick
*/
#define FUEL_INTERVAL 1
#define IDLE_LITRES_PER_HOUR 600
#define MAX_DRY_LITRES_PER_HOUR 11100
#define MAX_REHEAT_LITRES_PER_HOUR 48800

params ["_plane", "_state"];
_state params ["_previousTime", "_nextFuelBurn"];

if (!alive _plane) exitWith {
    _plane setVariable [QGVAR(afterburnerEngaged), false];
    _plane animateSource [REHEAT_SOURCE, 0, true];
};

private _newThrustVector = _plane animationPhase "source_thrustVector";
private _newSpeedBrake = _plane animationPhase "source_speedBrake";
[_plane, _newThrustVector, _newSpeedBrake] call FUNC(animateThrustVector);
[_plane, _newSpeedBrake] call FUNC(animateSpeedBreak);

if (CBA_missionTime > _previousTime) then {
    [_plane] call FUNC(afterburner);
    _state set [0, CBA_missionTime];
};

if (CBA_missionTime > _nextFuelBurn) then {
    [_plane, IDLE_LITRES_PER_HOUR, MAX_DRY_LITRES_PER_HOUR, MAX_REHEAT_LITRES_PER_HOUR] call EFUNC(common,fuelBurn);
    [_plane, EMPTY_MASS] call EFUNC(common,updateMass);
    _state set [1, CBA_missionTime + FUEL_INTERVAL];
};
