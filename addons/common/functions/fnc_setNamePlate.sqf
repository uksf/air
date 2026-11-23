#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Paints the pilot name onto a hidden selection. Each client renders its own UI texture,
        whose display draws the stored name on load. Blank when the aircraft has no pilot.

    Parameter(s):
        0: Aircraft <OBJECT>
        1: Hidden selection index <NUMBER>

    Return Value:
        Nothing

    Example:
        [_plane, 1] call uksf_air_common_fnc_setNamePlate
*/

params ["_plane", "_selection"];

if (isNull _plane || {!alive _plane}) exitWith {};

private _pilot = driver _plane;
private _text = "";
if (!isNull _pilot && {alive _pilot}) then {
    _text = toUpper ([name _pilot, ".", ""] call CBA_fnc_replace);
};

private _key = "np" + ((netId _plane) splitString ":" joinString "x");
private _path = ["#(argb,8,8,1)color(0,0,0,0)", format ["#(argb,1024,128,1)ui(""%1"",""%2"")", QGVAR(nameplate), _key]] select (_text != "");

private _names = uiNamespace getVariable QGVAR(nameplates);
if (isNil "_names") then {
    _names = createHashMap;
    uiNamespace setVariable [QGVAR(nameplates), _names];
};
_names set [_key, _text];

_plane setObjectTexture [_selection, _path];
if (local _plane) then {
    _plane setObjectTextureGlobal [_selection, _path];
};

private _display = findDisplay _key;
if (!isNull _display) then {
    [_display] call FUNC(drawNamePlate);
};
