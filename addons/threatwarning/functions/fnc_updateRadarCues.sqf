#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Plays the one-shot radar cues for the local listener.
        New contact on the RWR, or one that returns after lost contact: status chirp, aircraft-radar waterfall for airborne emitters.
        Emitter that has the aircraft marked: soft ping every SEARCH_PING_INTERVAL seconds.
        Lost emitters are forgotten after RADAR_LOST_AFTER seconds.
        Playing one-shots are kept so a voice call or silence can stop them.

    Parameters:
        0: Published radars [[emitter, state 0 on the RWR, 1 marked, 2 locked], ...] <ARRAY>
        1: Ducked under a voice call <BOOL>

    Return value:
        Nothing

    Example:
        [_radars, false] call uksf_air_threatwarning_fnc_updateRadarCues
*/
params ["_radars", "_ducked"];

GVAR(oneShots) = GVAR(oneShots) select {soundParams _x isNotEqualTo []};

private _volume = GVAR(volume) * ([1, DUCKED_LEVEL] select _ducked);

{
    _x params ["_emitter", "_state"];
    private _index = GVAR(radarsSeen) findIf {_x#0 isEqualTo _emitter};
    if (_index isEqualTo -1) then {
        private _chirp = ["rwr_new", "rwr_new_air"] select (_emitter isKindOf "Air");
        GVAR(oneShots) pushBack playSoundUI [QPATHTOF(data) + "\" + _chirp + ".ogg", _volume, 1, false];
        GVAR(radarsSeen) pushBack [_emitter, CBA_missionTime, CBA_missionTime + SEARCH_PING_INTERVAL];
        continue;
    };
    private _entry = GVAR(radarsSeen) select _index;
    _entry set [1, CBA_missionTime];
    if (_state isEqualTo 1 && {CBA_missionTime >= _entry#2}) then {
        GVAR(oneShots) pushBack playSoundUI [SOUND(rwr_search), _volume, 1, false];
        _entry set [2, CBA_missionTime + SEARCH_PING_INTERVAL];
    };
} forEach _radars;

GVAR(radarsSeen) = GVAR(radarsSeen) select {CBA_missionTime - _x#1 < RADAR_LOST_AFTER};
