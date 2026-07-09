#include "script_component.hpp"
#include "initKeybinds.inc.sqf"

[QGVAR(applyMagazineAmmo), {call FUNC(applyMagazineAmmo)}] call CBA_fnc_addEventHandler;
["ace_rearm_rearmSuccessLocalEH", {call FUNC(onCountermeasureRearmed)}] call CBA_fnc_addEventHandler;

if (!hasInterface) exitWith {};

// Strip A3TI's LTM keybinds (Toggle LTM / Toggle LTM Mode). The LTM functions are
// already neutered via CfgFunctions, but A3TI still registers the keybinds (Toggle
// LTM defaults to L); remove just those two entries so they don't clutter or bind.
// Reaches into CBA keybinding internals - if they ever return, CBA changed them.
{
    private _action = toLower format ["A3TI$%1", _x];
    private _entry = cba_keybinding_actions getVariable _action;
    if (!isNil "_entry") then {
        {
            [format ["%1_down_%2", _action, _forEachIndex], "keydown"] call CBA_fnc_removeKeyHandler;
            [format ["%1_up_%2", _action, _forEachIndex], "keyup"] call CBA_fnc_removeKeyHandler;
        } forEach (_entry param [2, []]);
        cba_keybinding_actions setVariable [_action, nil];
    };
} forEach ["ltm_toggle", "ltm_toggle_mode"];
private _a3tiInfo = cba_keybinding_addons getVariable "A3TI";
if (!isNil "_a3tiInfo") then {
    _a3tiInfo set [1, (_a3tiInfo select 1) - ["ltm_toggle", "ltm_toggle_mode"]];
};

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

// Notch helper: per-frame draw (self-gates to F-35 inside the function)
addMissionEventHandler ["Draw3D", {call FUNC(drawNotchHelper)}];
