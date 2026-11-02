#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Records a missile reported by the IncomingMissile event as a threat candidate on the aircraft owner

    Parameters:
        0: Aircraft <OBJECT>
        1: Ammo type <STRING>
        2: Firing vehicle <OBJECT>
        3: Instigator <OBJECT>
        4: Missile <OBJECT>

    Return value:
        Nothing

    Example:
        [_aircraft, _ammo, _vehicle, _instigator, _missile] call uksf_air_threatwarning_fnc_onIncomingMissile
*/
params ["_aircraft", "", "", "", ["_missile", objNull]];

if (!local _aircraft || {isNull _missile}) exitWith {};

private _candidates = _aircraft getVariable [QGVAR(candidates), []];
if (_candidates findIf {_x#0 isEqualTo _missile} isNotEqualTo -1) exitWith {};
_candidates pushBack [_missile, CBA_missionTime, _missile distance _aircraft];
_aircraft setVariable [QGVAR(candidates), _candidates];
