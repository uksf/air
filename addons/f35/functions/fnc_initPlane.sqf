#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises the plane and starts its per-frame handler. Where the plane is local the
        handler drives thrust vectoring, the speedbrake, and reheat. On every client with an
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

params ["_plane"];

[_plane] call FUNC(setMfdLoadout);

if (ACE_player in _plane) then {
    [_plane] call FUNC(getIn);
};

if (hasInterface || isServer) then {
    [{
        params ["_args", "_idPFH"];
        _args params ["_plane", "_previousTime", "_reheatWasOn"];

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
        };

        [_plane] call FUNC(afterburnerLight);

        if (hasInterface) then {
            private _reheatOn = _plane animationSourcePhase REHEAT_SOURCE > REHEAT_SHOWN;
            if (_reheatOn && {!_reheatWasOn}) then {
                [_plane] call FUNC(reheatKick);
            };
            _args set [2, _reheatOn];
        };
    }, 0, [_plane, CBA_missionTime, _plane animationSourcePhase REHEAT_SOURCE > REHEAT_SHOWN]] call CBA_fnc_addPerFrameHandler;
};
