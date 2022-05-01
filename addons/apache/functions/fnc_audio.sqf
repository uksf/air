#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Plays audio from queue with delays

    Parameters:
        None

    Return value:
        Nothing
*/
// TODO: Make this use a proper queue

if (GVAR(audioQueue) isEqualTo []) exitWith {
    GVAR(audioProcessing) = false;
};

if (GVAR(audioProcessing)) exitWith {};
GVAR(audioProcessing) = true;

private _audio = GVAR(audioQueue) deleteAt 0;
_audio params ["_sound", "_delay"];

playsound [_sound, true];

[{GVAR(audioProcessing) = false; call FUNC(audio)}, [], _delay] call CBA_fnc_waitAndExecute;
