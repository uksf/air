/*
    Author:
        Tim Beswick

    Description:
        Get in plane

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

[{_this call FUNC(setNamePlate)}, _this] call CBA_fnc_execNextFrame;

// Workaround for 100% throttle bug
GVAR(pilotGroupPFH) = [{
    params ["_args", "_idPFH"];
    _args params ["_plane"];
        
    if (!alive _plane) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (vehicle ACE_player != _plane) exitWith {};

    if ((getPosVisual _plane)#2 < 20) then {
        if (GVAR(inGroup)) then {
            GVAR(group) = group ACE_player;
            GVAR(inGroup) = false;
            [ACE_player] joinSilent grpNull;
        };
    } else {
        if (!GVAR(inGroup)) then {
            [ACE_player] joinSilent GVAR(group);
            GVAR(inGroup) = true;
        };
    };
}, 2, [_plane]] call CBA_fnc_addPerFrameHandler;
