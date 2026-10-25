#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises the plane and starts its per-frame handler. Where the plane is local the
        handler drives thrust vectoring, the speedbrake, reheat, and the fuel burn. The F135 makes
        28,000 lbf dry and 43,000 lbf in reheat (Pratt & Whitney); at the published estimate of
        0.7 and 2.0 lb/lbf/h that burns about 8,900 kg/h dry and 39,000 kg/h in reheat, jet fuel
        at 0.8 kg/L. On every client with an
        interface it drives the afterburner light and plays the reheat kick on light-up.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_f35_fnc_initPlane
*/
#define REHEAT_SOURCE "afterburner_hide"
#define REHEAT_SHOWN 0.5
#define FUEL_INTERVAL 1
#define IDLE_LITRES_PER_HOUR 600
#define MAX_DRY_LITRES_PER_HOUR 11100
#define MAX_REHEAT_LITRES_PER_HOUR 48800

params ["_plane"];

[_plane] call FUNC(setMfdLoadout);

if (ACE_player in _plane) then {
    [_plane] call FUNC(getIn);
};

if (hasInterface || isServer) then {
    [{
        params ["_args", "_idPFH"];
        _args params ["_plane", "_previousTime", "_reheatWasOn", "_nextFuelBurn"];

        if (!alive _plane) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            [_plane] call FUNC(afterburnerLight);
        };

        if (local _plane) then {
            private _newThrustVector = _plane animationPhase "source_thrustVector";
            private _newSpeedBrake = _plane animationPhase "source_speedBrake";

            [_plane, _newThrustVector, _newSpeedBrake] call FUNC(animateThrustVector);

            [_plane, _newSpeedBrake] call FUNC(animateSpeedBreak);

            if (CBA_missionTime > _previousTime) then {
                [_plane] call FUNC(afterburner);
                _args set [1, CBA_missionTime];
            };

            if (CBA_missionTime > _nextFuelBurn) then {
                [_plane, IDLE_LITRES_PER_HOUR, MAX_DRY_LITRES_PER_HOUR, MAX_REHEAT_LITRES_PER_HOUR] call EFUNC(common,fuelBurn);
                _args set [3, CBA_missionTime + FUEL_INTERVAL];
            };
        };

        [_plane] call FUNC(afterburnerLight);

        if (hasInterface) then {
            private _reheatOn = _plane animationSourcePhase REHEAT_SOURCE > REHEAT_SHOWN;
            if (_reheatOn && {!_reheatWasOn}) then {
                [_plane] call FUNC(reheatKick);
            };
            _args set [2, _reheatOn];
        };
    }, 0, [_plane, CBA_missionTime, _plane animationSourcePhase REHEAT_SOURCE > REHEAT_SHOWN, 0]] call CBA_fnc_addPerFrameHandler;
};
