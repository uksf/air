#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Keeps the looping RWR tone (lock or launch) playing. Restarts the tone when it ends,
        when a different tone is wanted, or when voice ducking starts or stops.

    Parameters:
        0: Tone name, "" for none <STRING>
        1: Ducked under a voice call <BOOL>

    Return value:
        Nothing

    Example:
        ["rwr_lock", false] call uksf_air_threatwarning_fnc_setLoop
*/
params ["_name", "_ducked"];

GVAR(loop) params ["_current", "_id", "_end", "_wasDucked"];

if (_name isEqualTo _current && {_ducked isEqualTo _wasDucked} && {CBA_missionTime < _end}) exitWith {};

if (_id isNotEqualTo -1) then {
    stopSound _id;
};

if (_name isEqualTo "") exitWith {
    GVAR(loop) = ["", -1, 0, false];
};

private _volume = GVAR(volume) * ([1, DUCKED_LEVEL] select _ducked);
private _newId = playSoundUI [QPATHTOF(data) + "\" + _name + ".ogg", _volume, 1, false];
GVAR(loop) = [_name, _newId, CBA_missionTime + 1.95, _ducked];
