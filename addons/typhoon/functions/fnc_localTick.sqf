#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        One frame of the Typhoon local loop. On a destroyed plane it only puts out the reheat.
        Otherwise: afterburner every frame, nozzles and the landing light
        (off while the gear is up, because the lights sit in the main gear doors) every NOZZLE_INTERVAL,
        and the fuel burn and mass every FUEL_INTERVAL. Two EJ200s burn about 9,500 kg/h at full dry
        power and 31,000 kg/h at full reheat (Rolls-Royce and EuroJet figures, jet fuel at 0.8 kg/L).
        Mass is the 11,000 kg basic empty mass (EuroJet) plus fuel, stores and crew.

    Parameter(s):
        0: Plane <OBJECT>
        1: State, [next nozzle check time, next fuel burn time] <ARRAY>

    Return Value:
        Nothing

    Example:
        [_plane, [0, 0]] call uksf_air_typhoon_fnc_localTick
*/
#define NOZZLE_INTERVAL 0.5
#define FUEL_INTERVAL 1
#define IDLE_LITRES_PER_HOUR 600
#define MAX_DRY_LITRES_PER_HOUR 11900
#define MAX_REHEAT_LITRES_PER_HOUR 38800
#define GEAR_SOURCE "gear"
#define GEAR_RETRACTED 0.5

params ["_plane", "_state"];
_state params ["_nextNozzleCheck", "_nextFuelBurn"];

if (!alive _plane) exitWith {
    _plane setVariable [QGVAR(afterburnerEngaged), false, true];
    [_plane, false] call FUNC(afterburnerVisuals);
};

[_plane] call FUNC(afterburner);

if (CBA_missionTime > _nextNozzleCheck) then {
    [_plane] call FUNC(nozzles);
    if (isLightOn _plane && {_plane animationSourcePhase GEAR_SOURCE > GEAR_RETRACTED}) then {
        _plane setPilotLight false;
    };
    _state set [0, CBA_missionTime + NOZZLE_INTERVAL];
};

if (CBA_missionTime > _nextFuelBurn) then {
    [_plane, IDLE_LITRES_PER_HOUR, MAX_DRY_LITRES_PER_HOUR, MAX_REHEAT_LITRES_PER_HOUR] call EFUNC(common,fuelBurn);
    [_plane, EMPTY_MASS] call EFUNC(common,updateMass);
    _state set [1, CBA_missionTime + FUEL_INTERVAL];
};
