#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets plane nameplate

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_f35_fnc_setNamePlate
*/
#define UID_BESWICK "76561198041153310"
#define UID_CARR "76561198136488003"
#define UID_GILBERT "76561198052764916"
#define UID_ARRAY [UID_BESWICK, UID_CARR, UID_GILBERT]
#define NAME_SELECTION 1

params ["_plane"];

if (!local _plane) exitWith {};

private _id = getPlayerUID ACE_player;
private _index = UID_ARRAY find _id;

_plane setObjectTextureGlobal [NAME_SELECTION, format [QPATHTOF(data\name_%1_ca.paa), _index + 1]];
