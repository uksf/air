#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Paints the pilot name onto a hidden selection. Each client renders its own UI texture.
        The texture is 16:9 so the UI blit does not stretch the glyphs. The text sits in the top
        2/9 of that texture, the strip the rail quads map, so an 8:1 plate shows the name undistorted.
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
private _path = ["#(argb,8,8,1)color(0,0,0,0)", format ["#(argb,1024,576,1)ui(""%1"",""%2"")", QGVAR(nameplate), _key]] select (_text != "");

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
    private _band = 2 / 9;
    private _aspect = (getResolution select 4) max 1.2;
    private _byWidth = _aspect / (((count _text) max 1) * 0.56);
    private _height = _byWidth min (_band * 0.78);
    private _ctrl = _display displayCtrl 1001;
    _ctrl ctrlSetPosition [0, 0, 1, _band];
    _ctrl ctrlCommit 0;
    _ctrl ctrlSetFont "RobotoCondensedBold";
    _ctrl ctrlSetFontHeight _height;
    _ctrl ctrlSetText _text;
    displayUpdate _display;
};
