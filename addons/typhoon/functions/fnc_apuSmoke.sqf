#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Local smoke puff from the APU exhaust on engine start: a dense dark burst that thins out.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_apuSmoke
*/
// APU exhaust on top of the port wing root, in model coordinates.
#define APU_EXHAUST [-1.15, -1.5, 0.05]

params ["_plane"];

private _source = "#particlesource" createVehicleLocal (getPosATL _plane);
_source setParticleParams [
    ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48, 1], "", "Billboard",
    1, 3.5, APU_EXHAUST, [0, 0, 1.2], 0, 1.3, 1, 0.08,
    [0.5, 2, 4], [[0.08, 0.08, 0.08, 0.85], [0.2, 0.2, 0.2, 0.5], [0.4, 0.4, 0.4, 0]],
    [0.8], 0.2, 0.2, "", "", _plane
];
_source setParticleRandom [0.8, [0.1, 0.1, 0.05], [0.4, 0.4, 0.3], 0, 0.3, [0.03, 0.03, 0.03, 0], 0, 0];
_source setDropInterval 0.015;

[{
    params ["_source"];
    _source setDropInterval 0.06;
    [{deleteVehicle _this}, _source, 1.5] call CBA_fnc_waitAndExecute;
}, [_source], 0.8] call CBA_fnc_waitAndExecute;
