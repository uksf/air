#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets the painted pilot-name panel texture for the aircraft's driver.
        Pilots without a panel texture get the blank panel (index 0).
        Single player has no Steam UID, so the pilot is matched by surname instead.

    Parameter(s):
        0: Aircraft <OBJECT>
        1: Hidden selection index <NUMBER>
        2: Texture path with %1 for the panel index <STRING>

    Return Value:
        Nothing

    Example:
        [_plane, 1, "\u\uksf_air\addons\f35\data\name_%1_ca.paa"] call uksf_air_common_fnc_setNamePlate
*/
#define PILOT_UIDS ["76561198041153310", "76561198136488003", "76561198052764916"]
#define PILOT_SURNAMES ["beswick", "carr", "gilbert"]

params ["_plane", "_selection", "_texture"];

if (isNull _plane || {!local _plane}) exitWith {};

private _driver = driver _plane;
private _index = 1 + (PILOT_UIDS find getPlayerUID _driver);
if (_index == 0 && {!isMultiplayer} && {isPlayer _driver}) then {
    private _name = toLower name _driver;
    _index = 1 + (PILOT_SURNAMES findIf { _x in _name });
};
private _path = format [_texture, _index];
if ((getObjectTextures _plane) param [_selection, ""] == _path) exitWith {};

_plane setObjectTextureGlobal [_selection, _path];
