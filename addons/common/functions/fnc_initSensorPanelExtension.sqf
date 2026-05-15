#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        On RscCustomInfoSensors (IDD 314) load, ctrlCreate a single structured
        text control anchored above the SENS Title control (IDC 15112).
        Geometry is read from the actual Title's ctrlPosition so the
        extension lines up whether the player has the sensor panel slotted on
        the left or the right custom-info column. The render PFH builds
        coloured "RDR" / "IR" / "RDR IR" markup each tick from the player
        vehicle's activeThreats hashmap.

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

private _title = _display displayCtrl 15112;
if (isNull _title) exitWith {};
_display setVariable [QGVAR(panelExtAttached), true];

(ctrlPosition _title) params ["_titleX", "_titleY", "_titleW", "_titleH"];
private _yAnchor = _titleY - 1.2 * _titleH;

private _sourcesCtrl = _display ctrlCreate ["RscStructuredText", -1];
_sourcesCtrl ctrlSetBackgroundColor [0, 0, 0, 0];
_sourcesCtrl ctrlSetPosition [_titleX, _yAnchor, _titleW, _titleH];
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
