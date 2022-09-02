#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Release cargo from specified position

    Parameter(s):
        0: Position <STRING>

    Return Value:
        Nothing
*/
params ["_position"];

private _vehicle = vehicle ACE_player;
ACE_player setVariable [QGVAR(Release_Cargo_Index_Vehicle), _vehicle];

if (_position isEqualTo "All") then {
    {
        [_x, _vehicle, ACE_player] call FUNC(Release_Cargo_Index_Action);
    } forEach [0, 1, 2];
} else {
    private _ropesAndCargo = [_vehicle, ACE_player] call FUNC(Get_Active_Ropes_With_Cargo);
    private _index = _ropesAndCargo findIf {(_x#1) == _position};
    if (_index != -1) then {
        [_ropesAndCargo#_index#0, _vehicle, ACE_player] call FUNC(Release_Cargo_Index_Action);
    };
};
