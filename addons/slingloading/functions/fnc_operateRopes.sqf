#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Opreate ropes for specified position

    Parameter(s):
        0: Position <STRING>

    Return Value:
        Nothing
*/
params ["_position"];

private _vehicle = vehicle ACE_player;

private _ropesWithCargo = [_vehicle, ACE_player] call FUNC(Get_Active_Ropes_With_Cargo);
private _anyRopesHaveCargo = _ropesWithCargo isNotEqualTo [];

private _deployingRopes = QGVAR(Deploy_Ropes_Count_Menu) in commandingMenu;
if ((_anyRopesHaveCargo && GVAR(actionContext) == ACTION_CONTEXT_EMPTY && !_deployingRopes) || GVAR(actionContext) == ACTION_CONTEXT_RELEASE) exitWith {
    if (_position isEqualTo "All") then {
        {[_x, _vehicle, ACE_player] call FUNC(Release_Cargo_Index_Action)} forEach [0, 1, 2];
    } else {
        private _index = _ropesWithCargo findIf {(_x#1) == _position};
        if (_index != -1) then {
            [_ropesWithCargo#_index#0, _vehicle, ACE_player] call FUNC(Release_Cargo_Index_Action);
        };
    };
    showCommandingMenu "";
};

if (GVAR(actionContext) == ACTION_CONTEXT_EXTENDTOGROUND) exitWith {
    if (_position isEqualTo "All") then {
        {[_x, _vehicle, ACE_player, true] call FUNC(Extend_Ropes_Index_Action)} forEach [0, 1, 2];
    } else {
        private _index = _ropesWithCargo findIf {(_x#1) == _position};
        if (_index != -1) then {
            [_ropesWithCargo#_index#0, _vehicle, ACE_player, true] call FUNC(Extend_Ropes_Index_Action);
        };
    };
    showCommandingMenu "";
};

private _ropes = [_vehicle, true] call FUNC(Get_Active_Ropes);
if (GVAR(actionContext) == ACTION_CONTEXT_EXTEND) exitWith {
    if (_position isEqualTo "All") then {
        {[_x, _vehicle, ACE_player] call FUNC(Extend_Ropes_Index_Action)} forEach [0, 1, 2];
    } else {
        private _index = _ropes findIf {(_x#1) == _position};
        if (_index != -1) then {
            [_ropes#_index#0, _vehicle, ACE_player] call FUNC(Extend_Ropes_Index_Action);
        };
    };
    showCommandingMenu "";
};

if (GVAR(actionContext) == ACTION_CONTEXT_SHORTEN) exitWith {
    if (_position isEqualTo "All") then {
        {[_x, _vehicle, ACE_player] call FUNC(Shorten_Ropes_Index_Action)} forEach [0, 1, 2];
    } else {
        private _index = _ropes findIf {(_x#1) == _position};
        if (_index != -1) then {
            [_ropes#_index#0, _vehicle, ACE_player] call FUNC(Shorten_Ropes_Index_Action);
        };
    };
    showCommandingMenu "";
};

if (GVAR(actionContext) == ACTION_CONTEXT_RETRACT) exitWith {
    if (_position isEqualTo "All") then {
        {[_x, _vehicle, ACE_player] call FUNC(Retract_Ropes_Index_Action)} forEach [0, 1, 2];
    } else {
        private _ropesWithoutCargo = [_vehicle] call FUNC(Get_Active_Ropes_Without_Cargo);
        private _index = _ropesWithoutCargo findIf {(_x#1) == _position};
        if (_index != -1) then {
            [_ropesWithoutCargo#_index#0, _vehicle, ACE_player] call FUNC(Retract_Ropes_Index_Action);
        };
    };
    showCommandingMenu "";
};
