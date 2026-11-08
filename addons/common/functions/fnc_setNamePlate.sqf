#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Paints the pilot name onto a hidden selection. Each client renders its own UI texture.
        Blank when the aircraft has no pilot.

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

_plane setObjectTexture [_selection, _path];
if (local _plane) then {
    _plane setObjectTextureGlobal [_selection, _path];
};

if (_text == "") exitWith {};

[_plane, _key, _text] spawn {
    params ["_plane", "_key", "_text"];
    if (!alive _plane) exitWith {};
    private _display = displayNull;
    private _until = diag_tickTime + 4;
    waitUntil {
        _display = findDisplay _key;
        !isNull _display || {diag_tickTime > _until} || {!alive _plane}
    };
    if (isNull _display) exitWith {};
    private _height = 0.62;
    if (count _text > 16) then { _height = 0.46 };
    if (count _text > 24) then { _height = 0.34 };
    private _ctrl = _display displayCtrl 1001;
    _ctrl ctrlSetFont "RobotoCondensedBold";
    _ctrl ctrlSetFontHeight _height;
    _ctrl ctrlSetText _text;
    displayUpdate _display;
};
