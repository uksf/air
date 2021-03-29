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
#define AIM9 ["PylonRack_Missile_BIM9X_x1", "PylonRack_Missile_BIM9X_x2", "PylonMissile_Missile_BIM9X_x1"]
#define AMMRAM ["PylonRack_Missile_AMRAAM_D_x1", "PylonRack_Missile_AMRAAM_D_x2", "PylonMissile_Missile_AMRAAM_D_INT_x1"]
#define GBU ["PylonMissile_Bomb_GBU12_x1", "PylonRack_Bomb_GBU12_x2"]
#define JDAM []
#define SDB ["PylonRack_Bomb_SDB_x4"]
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
