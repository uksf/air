#include "script_component.hpp"
#include "initKeybinds.inc.sqf"

[QGVAR(applyMagazineAmmo), {call FUNC(applyMagazineAmmo)}] call CBA_fnc_addEventHandler;
["ace_rearm_rearmSuccessLocalEH", {call FUNC(onCountermeasureRearmed)}] call CBA_fnc_addEventHandler;

if (!hasInterface) exitWith {};

["vehicle", {
    params ["_player", "_vehicle"];
    if (_vehicle isEqualTo _player) exitWith {};
    if (!(_vehicle isKindOf "Air")) exitWith {};
    private _hasRWR = isClass (configOf _vehicle >> "Components" >> "SensorsManagerComponent" >> "Components" >> "PassiveRadarSensorComponent");
    if (!_hasRWR) exitWith {};

    private _deadline = CBA_missionTime + 15;
    [{
        params ["_args", "_idPFH"];
        _args params ["_deadline"];
        if (CBA_missionTime > _deadline) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
        private _display = uiNamespace getVariable ["RscCustomInfoSensors", displayNull];
        if (isNull _display) exitWith {};
        [_display] call FUNC(initSensorPanelExtension);
        if (_display getVariable [QGVAR(panelExtAttached), false]) then {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };
    }, 0.25, [_deadline]] call CBA_fnc_addPerFrameHandler;
}, true] call CBA_fnc_addPlayerEventHandler;
