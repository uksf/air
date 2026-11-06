#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops every playing threat warning cue, one-shot radar cues included, and forgets announced threats, so current threats are announced again when the system comes back

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_air_threatwarning_fnc_silence
*/
if (!GVAR(active)) exitWith {};
GVAR(active) = false;

["", false] call FUNC(setLoop);
if (GVAR(voiceId) isNotEqualTo -1) then {
    stopSound GVAR(voiceId);
};
GVAR(voiceId) = -1;
GVAR(voiceMissile) = objNull;
{stopSound _x} forEach GVAR(oneShots);
GVAR(oneShots) = [];
GVAR(voiceEnd) = 0;
GVAR(radarsSeen) = [];
GVAR(missilesCalled) = [];
