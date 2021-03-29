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
*/
#define UID_BESWICK "76561198041153310"
#define UID_JOHNSON "76561198006819449"
#define UID_ELLIOTT "76561198010140456"
#define UID_ARRAY [UID_BESWICK, UID_JOHNSON, UID_ELLIOTT]
#define NAME_SELECTION 1

params ["_plane"];

if (!local _plane) exitWith {};

private _id = getPlayerUID ACE_player;
private _index = UID_ARRAY find _id;

_plane setObjectTextureGlobal [NAME_SELECTION, format [QPATHTOEF(plane,data\name_%1_ca.paa), _index + 1]];
