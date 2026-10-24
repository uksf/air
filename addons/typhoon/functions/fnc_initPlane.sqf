#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the per-frame handler for a Typhoon: afterburner, fuel burn and nozzles where the plane is local,
        the reheat light-up kick and APU smoke on every client, and HMD visibility for the local pilot.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_initPlane
*/
#define NOZZLE_INTERVAL 0.5
#define FUEL_INTERVAL 1
#define REHEAT_FLAME_HIDE "afterburner_left_userhide"
#define REHEAT_FLAME_SHOWN 0.5

params ["_plane"];

if !(hasInterface || isServer) exitWith {};

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_nextNozzleCheck", "_engineWasOn", "_reheatWasOn", "_nextFuelBurn"];

    if (!alive _plane) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        if (local _plane) then {
            [_plane, false] call FUNC(afterburnerVisuals);
        };
    };

    if (local _plane) then {
        [_plane] call FUNC(afterburner);

        if (CBA_missionTime > _nextNozzleCheck) then {
            [_plane] call FUNC(nozzles);
            _args set [1, CBA_missionTime + NOZZLE_INTERVAL];
        };

        if (CBA_missionTime > _nextFuelBurn) then {
            [_plane] call FUNC(fuelBurn);
            _args set [4, CBA_missionTime + FUEL_INTERVAL];
        };
    };

    if (hasInterface) then {
        private _engineOn = isEngineOn _plane;
        if (_engineOn && {!_engineWasOn} && {speed _plane < 10}) then {
            [_plane] call FUNC(apuSmoke);
        };
        _args set [2, _engineOn];

        private _reheatOn = _plane animationPhase REHEAT_FLAME_HIDE < REHEAT_FLAME_SHOWN;
        if (_reheatOn && {!_reheatWasOn}) then {
            [_plane] call FUNC(reheatKick);
        };
        _args set [3, _reheatOn];
    };

    if (hasInterface && {ACE_player == driver _plane}) then {
        [_plane] call FUNC(hmdVisibility);
    };
}, 0, [_plane, 0, isEngineOn _plane, _plane animationPhase REHEAT_FLAME_HIDE < REHEAT_FLAME_SHOWN, 0]] call CBA_fnc_addPerFrameHandler;
