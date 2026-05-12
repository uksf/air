#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        On RscCustomInfoSensors (IDD 314) load, ctrlCreate a single structured
        text control anchored 1 cell above the existing SENS panel. The render
        PFH builds coloured "RDR" / "IR" / "RDR IR" markup each tick from the
        player vehicle's activeThreats hashmap and applies blink alpha.

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

// Single structured-text control sitting 1.2 pixel rows above SENS title
private _yAnchor = -1.2 * _pixelH;
private _labelH = 1.0 * _pixelH;
private _labelW = _cellW;

private _sourcesCtrl = _display ctrlCreate ["RscStructuredText", -1];
_sourcesCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
_sourcesCtrl ctrlSetPosition [0, _yAnchor, _labelW, _labelH];
_sourcesCtrl ctrlCommit 0;

private _pfhId = [{
    params ["_args", "_idPFH"];
    _args params ["_display", "_sourcesCtrl"];
    if (isNull _display) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
    [_sourcesCtrl] call FUNC(renderSensorPanel);
}, 0.1, [_display, _sourcesCtrl]] call CBA_fnc_addPerFrameHandler;

_display displayAddEventHandler ["Unload", {
    params ["_display"];
    private _id = _display getVariable [QGVAR(renderPFHID), -1];
    if (_id != -1) then {
        [_id] call CBA_fnc_removePerFrameHandler;
    };
}];

_display setVariable [QGVAR(renderPFHID), _pfhId];
