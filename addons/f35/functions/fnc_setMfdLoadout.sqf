#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets plane loadout on MFD

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
#define AIM9 ["ace_missile_aim9_PylonRack_aim132_x1", "ace_missile_aim9_PylonRack_aim132_x2"]
#define AMMRAM ["ace_missile_aim120_PylonRack_Missile_d_x1", "ace_missile_aim120_PylonRack_Missile_d_x2", "ace_missile_aim120_PylonMissile_Missile_d_INT_x1", "rksla3_mag_meteor_lau127x1", "rksla3_mag_meteor_directx1"]
#define GBU ["ace_missile_gbu_PylonMissile_Bomb_GBU12_x1", "ace_missile_gbu_PylonRack_Bomb_GBU12_x2", "ace_missile_gbu_PylonRack_Bomb_GBU12_x3"]
#define JDAM []
#define SDB ["ace_missile_sdb_PylonRack_bomb_SDB_x4", "rksla3_mag_brimstone_3_x3", "rksla3_mag_spear3_directx1", "rksla3_mag_spear3_bru61_x4"]
#define HEAVY []

params ["_plane"];

if (!local _plane) exitWith {};

{
    private _index = _forEachIndex + 1;
    switch (true) do {
        case (_x in AIM9): {_plane setUserMFDValue [_index, 1]};
        case (_x in AMMRAM): {_plane setUserMFDValue [_index, 2]};
        case (_x in GBU): {_plane setUserMFDValue [_index, 4]};
        case (_x in JDAM): {_plane setUserMFDValue [_index, 3]};
        case (_x in SDB): {_plane setUserMFDValue [_index, 8]};
        case (_x in HEAVY): {_plane setUserMFDValue [_index, 10]};
    };
} forEach getPylonMagazines _plane;
