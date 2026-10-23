#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Manages the F-35 afterburner light and light-up particles. Replaces AAE's burner pipeline,
        which AAE_Have_AB=0 disables. The light follows the plane's visual transform every frame
        instead of attachTo, so it does not lag a simulation tick. The cockpit light-up sound is
        the reheat kick in fnc_reheatKick.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_f35_fnc_afterburnerLight
*/
#define OFFSET [0, -5.83, 0.09]

params ["_plane"];

if (!hasInterface) exitWith {};

private _light = _plane getVariable [QGVAR(afterburnerLight), objNull];
private _wasEngaged = _plane getVariable [QGVAR(afterburnerLightWas), false];
private _engaged = alive _plane && {_plane animationPhase "afterburner_hide" > 0.5};

if (!_engaged) exitWith {
    if (!_wasEngaged) exitWith {};
    if (!isNull _light) then {
        deleteVehicle _light;
    };
    _plane setVariable [QGVAR(afterburnerLight), nil];
    _plane setVariable [QGVAR(afterburnerLightWas), false];
};

if (!_wasEngaged) then {
    _light = "AAE_AfterBurner_Reflector" createVehicleLocal [0, 0, 0];
    _plane setVariable [QGVAR(afterburnerLight), _light];
    _plane setVariable [QGVAR(afterburnerLightWas), true];

    private _velocity = velocity _plane;
    private _particle = "#particlesource" createVehicleLocal [0, 0, 0];
    _particle attachTo [_plane, OFFSET];
    _particle setParticleParams [
        ["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 0, 40, 1], "", "Billboard",
        1, 3, [0, 0, 0], [(_velocity # 0) * 0.01, (_velocity # 1) * 0.01, (_velocity # 2) * 0.05],
        1, 1.4, 1, 0.1, [1, 2, 4, 6, 8],
        [[0.06, 0.06, 0.06, 0.05], [0.06, 0.06, 0.06, 0.1], [0.1, 0.1, 0.1, 0.04], [0.2, 0.2, 0.2, 0.01], [0.3, 0.3, 0.3, 0.001]],
        [2, 1], 0.1, 0.25, "", "", _particle
    ];
    _particle setDropInterval 0.005;
    _particle setParticleRandom [1, [0.4, 0.4, 0.4], [1, 1, 1], 20, 0.3, [0, 0, 0, 0.04], 0.1, 0.05, 0];
    [_particle] spawn {
        params ["_p"];
        uiSleep 0.3;
        deleteVehicle _p;
    };
};

if (isNull _light) exitWith {};

_light setPosASL (_plane modelToWorldVisualWorld OFFSET);
_light setVectorDirAndUp [
    _plane vectorModelToWorldVisual [0, -1, 0],
    _plane vectorModelToWorldVisual [0, 0, 1]
];
