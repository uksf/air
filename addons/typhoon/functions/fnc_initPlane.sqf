#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the per-frame handler for a Typhoon: afterburner and nozzles where the plane is local,
        and HMD visibility for the local pilot.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_initPlane
*/
#define NOZZLE_INTERVAL 0.5

params ["_plane"];

if !(hasInterface || isServer) exitWith {};

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_nextNozzleCheck"];

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
    };

    if (hasInterface && {ACE_player == driver _plane}) then {
        [_plane] call FUNC(hmdVisibility);
    };
}, 0, [_plane, 0]] call CBA_fnc_addPerFrameHandler;
