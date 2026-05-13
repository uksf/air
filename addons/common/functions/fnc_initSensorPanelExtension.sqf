#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        On RscCustomInfoSensors (IDD 314) load, ctrlCreate a single structured
        text control anchored above the SENS panel background (IDC 15110).
        Geometry is read from the actual background's ctrlPosition so the
        extension lines up whether the player has the sensor panel slotted on
        the left or the right custom-info column. The render PFH builds
        coloured "RDR" / "IR" / "RDR IR" markup each tick from the player
        vehicle's activeThreats hashmap, gated on the SENS background being
        shown (panel can be cycled or toggled off independently).

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

private _background = _display displayCtrl 15110;
if (isNull _background) exitWith {};
_display setVariable [QGVAR(panelExtAttached), true];

(ctrlPosition _background) params ["_bgX", "_bgY", "_bgW", "_bgH"];
private _pixelH = (((safezoneW / safezoneH) min 1.2) / 1.2) / 25;
private _labelH = 1.0 * _pixelH;
private _yAnchor = _bgY - 1.2 * _pixelH;

private _sourcesCtrl = _display ctrlCreate ["RscStructuredText", -1];
_sourcesCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
_sourcesCtrl ctrlSetPosition [_bgX, _yAnchor, _bgW, _labelH];
_sourcesCtrl ctrlCommit 0;

private _pfhId = [{
    params ["_args", "_idPFH"];
    _args params ["_display", "_sourcesCtrl", "_background"];
    if (isNull _display) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
    [_sourcesCtrl, _background] call FUNC(renderSensorPanel);
}, 0.1, [_display, _sourcesCtrl, _background]] call CBA_fnc_addPerFrameHandler;

_display displayAddEventHandler ["Unload", {
    params ["_display"];
    private _id = _display getVariable [QGVAR(renderPFHID), -1];
    if (_id != -1) then {
        [_id] call CBA_fnc_removePerFrameHandler;
    };
}];

_display setVariable [QGVAR(renderPFHID), _pfhId];
