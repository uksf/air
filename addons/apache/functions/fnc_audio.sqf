#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Plays a warning sound if not on cooldown for the given category

    Parameters:
        0: Sound class name <STRING>
        1: Cooldown key <STRING>

    Return value:
        Nothing

    Example:
        [_sound, _cooldownKey] call uksf_air_apache_fnc_audio
*/
params ["_sound", "_cooldownKey"];

private _cooldownDuration = GVAR(soundDurations) getOrDefault [_sound, 1.5];
private _lastPlayed = GVAR(cooldowns) getOrDefault [_cooldownKey, -1];
if (CBA_missionTime - _lastPlayed < _cooldownDuration) exitWith {};

GVAR(cooldowns) set [_cooldownKey, CBA_missionTime];
playSound [_sound, true];
