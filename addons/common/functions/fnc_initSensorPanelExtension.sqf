#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        On RscCustomInfoSensors (IDD 314) load, ctrlCreate two coloured text
        controls (RDR, IR) anchored 1 cell above the existing SENS panel.
        Starts a per-display render PFH (fnc_renderSensorPanel) that drives
        text/visibility/blink from the player vehicle's activeThreats hashmap.

        Idempotent: marks the display with an attached flag and bails early
        on re-entry. PFH is removed on display unload via display EH.

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        Nothing

    Example:
        [_display] call uksf_air_common_fnc_initSensorPanelExtension
*/
params ["_display"];

if (isNull _display) exitWith {};
if (_display getVariable [QGVAR(panelExtAttached), false]) exitWith {};
_display setVariable [QGVAR(panelExtAttached), true];

private _cellW = profileNamespace getVariable ["IGUI_GRID_CUSTOMINFORIGHT_W", (10 * (((safezoneW / safezoneH) min 1.2) / 40))];
private _cellH = profileNamespace getVariable ["IGUI_GRID_CUSTOMINFORIGHT_H", (10 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))];
private _pixelW = ((safezoneW / safezoneH) min 1.2) / 40;
private _pixelH = (((safezoneW / safezoneH) min 1.2) / 1.2) / 25;

// Two side-by-side text controls, sitting 1.2 pixel rows above SENS title
private _yAnchor = -1.2 * _pixelH;
private _labelH = 1.0 * _pixelH;
private _labelW = 0.5 * _cellW - 0.125 * _pixelW;

private _rdrCtrl = _display ctrlCreate ["RscIGUIText", -1];
_rdrCtrl ctrlSetText "RDR";
_rdrCtrl ctrlSetTextColor [1, 0.2, 0.2, 0];
_rdrCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
_rdrCtrl ctrlSetPosition [0, _yAnchor, _labelW, _labelH];
_rdrCtrl ctrlCommit 0;

private _irCtrl = _display ctrlCreate ["RscIGUIText", -1];
_irCtrl ctrlSetText "IR";
_irCtrl ctrlSetTextColor [1, 1, 0.2, 0];
_irCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
_irCtrl ctrlSetPosition [_labelW + 0.25 * _pixelW, _yAnchor, _labelW, _labelH];
_irCtrl ctrlCommit 0;

private _pfhId = [{
    params ["_args", "_idPFH"];
    _args params ["_display", "_rdrCtrl", "_irCtrl"];
    if (isNull _display) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
    [_rdrCtrl, _irCtrl] call FUNC(renderSensorPanel);
}, 0.1, [_display, _rdrCtrl, _irCtrl]] call CBA_fnc_addPerFrameHandler;

_display displayAddEventHandler ["Unload", {
    params ["_display"];
    private _id = _display getVariable [QGVAR(renderPFHID), -1];
    if (_id != -1) then {
        [_id] call CBA_fnc_removePerFrameHandler;
    };
}];

_display setVariable [QGVAR(renderPFHID), _pfhId];
