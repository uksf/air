#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(setJumpLightsOff), {
    params ["_plane"];

    private _lightState = _plane getVariable [QGVAR(lightState), false];
    _plane setPilotLight _lightState;
    {_plane setHit [_x, 0]} forEach ["L2 svetlo", "P2 svetlo"];
    if ((_plane animationSourcePhase "gear") < 0.5) then {
        {_plane setHit [_x, 0]} forEach ["L svetlo", "P svetlo"];
    };

    {_plane setHit [_x, 1]} forEach JUMP_LIGHTS_RED;
    {_plane setHit [_x, 1]} forEach JUMP_LIGHTS_GREEN;
    _plane setVariable [QGVAR(jumpLightState), 0, true];
}] call CBA_fnc_addEventHandler;

[QGVAR(setJumpLightsRed), {
    params ["_plane"];

    private _jumpLightState = _plane getVariable [QGVAR(jumpLightState), 0];
    if (_jumpLightState == 0) then {
        private _lightState = isLightOn _plane;
        _plane setVariable [QGVAR(lightState), _lightState, true];
        _plane setPilotLight true;
        {_plane setHit [_x, 1]} forEach ["L svetlo", "P svetlo", "L2 svetlo", "P2 svetlo"];
    };

    {_plane setHit [_x, 0]} forEach JUMP_LIGHTS_RED;
    {_plane setHit [_x, 1]} forEach JUMP_LIGHTS_GREEN;
    _plane setVariable [QGVAR(jumpLightState), 1, true];
}] call CBA_fnc_addEventHandler;

[QGVAR(setJumpLightsGreen), {
    params ["_plane"];

    {_plane setHit [_x, 1]} forEach JUMP_LIGHTS_RED;
    {_plane setHit [_x, 0]} forEach JUMP_LIGHTS_GREEN;
    _plane setVariable [QGVAR(jumpLightState), 2, true];
}] call CBA_fnc_addEventHandler;

ADDON = true;
