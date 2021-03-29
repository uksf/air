#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises plane

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
params ["_plane"];

[_plane] call FUNC(setMfdLoadout);

if (ACE_player in _plane) then {
    [_plane] call FUNC(getIn);
};

if (hasInterface || isServer) then {
    [{
        params ["_args", "_idPFH"];
        _args params ["_plane", "_previousTime"];
        
        if (!alive _plane) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        if (local _plane) then {
            private _newThrustVector = _plane animationPhase "source_thrustVector";
            private _newSpeedBrake = _plane animationPhase "source_speedBrake";

            // Thrustvector animations
            [_plane, _newThrustVector, _newSpeedBrake] call FUNC(animateThrustVector);

            // Speedbrake animations
            [_plane, _newSpeedBrake] call FUNC(animateSpeedBreak);

            // Afterburner effects
            if (CBA_missionTime > _previousTime) then {
                [_plane] call FUNC(afterburner);
                _args set [1, CBA_missionTime];
            };
        };
    }, 0, [_plane, CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
};
