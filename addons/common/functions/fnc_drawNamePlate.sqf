#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws the stored pilot name into a nameplate UI texture display.
        Runs from the display onLoad, so the name returns each time the engine recreates the texture.
        The texture is 1024x128. A 16:9 UI blit into that 8:1 target stretches the glyphs,
        and the rail quads map only the top 2/9, which cancels it.

    Parameter(s):
        0: Nameplate display <DISPLAY>

    Return Value:
        Nothing

    Example:
        [_display] call uksf_air_common_fnc_drawNamePlate
*/

params ["_display"];

private _text = (uiNamespace getVariable [QGVAR(nameplates), createHashMap]) getOrDefault [displayUniqueName _display, ""];
private _band = 2 / 9;
private _height = _band * 0.78;
private _ctrl = _display displayCtrl 1001;
_ctrl ctrlSetPosition [0, 0, 1, _band];
_ctrl ctrlCommit 0;
_ctrl ctrlSetFont "RobotoCondensedBold";
_ctrl ctrlSetFontHeight _height;
_ctrl ctrlSetText _text;
private _width = ctrlTextWidth _ctrl;
if (_width > 0.7) then {
    _ctrl ctrlSetFontHeight (_height * 0.7 / _width);
};
displayUpdate _display;
