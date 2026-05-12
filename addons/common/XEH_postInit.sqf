#include "script_component.hpp"
#include "initKeybinds.inc.sqf"

if (!hasInterface) exitWith {};

[{
    private _display = uiNamespace getVariable ["RscCustomInfoSensors", displayNull];
    if (isNull _display) exitWith {};
    if (_display getVariable [QGVAR(panelExtAttached), false]) exitWith {};
    [_display] call FUNC(initSensorPanelExtension);
}, 0.5] call CBA_fnc_addPerFrameHandler;
