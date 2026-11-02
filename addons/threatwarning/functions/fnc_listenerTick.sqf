#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Listener loop. Plays the threat warning cues of the aircraft the local player can hear.
        Looping tone: launch warble while a radar missile is guided at the aircraft and closing, else steady lock tone while a radar has a lock.
        Voice: clock call for each new missile, repeated at most every CALL_REPEAT_INTERVAL seconds when the bearing moves two clock positions or more.
        Voice calls duck every tone.

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_air_threatwarning_fnc_listenerTick
*/
private _aircraft = vehicle player;

if (
    _aircraft isEqualTo player
    || {getNumber (configOf _aircraft >> QGVAR(enabled)) isNotEqualTo 1}
    || {!alive player}
    || {!([_aircraft] call FUNC(isLive))}
    || {!([_aircraft, player] call FUNC(canHear))}
) exitWith {
    call FUNC(silence);
};
GVAR(active) = true;

private _radars = _aircraft getVariable [QGVAR(radars), []];
private _missiles = (_aircraft getVariable [QGVAR(missiles), []]) select {alive (_x#0)};

if (GVAR(voiceEnd) <= CBA_missionTime) then {
    private _current = _missiles apply {_x#0};
    GVAR(missilesCalled) = GVAR(missilesCalled) select {_x#0 in _current};
    private _called = GVAR(missilesCalled) apply {_x#0};
    private _new = _missiles findIf {!(_x#0 in _called)};
    private _call = [];
    if (_new isNotEqualTo -1) then {
        private _missile = _missiles#_new#0;
        _call = [_aircraft, _missile] call FUNC(clockCall);
        GVAR(missilesCalled) pushBack [_missile, _call#0, CBA_missionTime];
    } else {
        {
            _x params ["_missile", "_lastClock", "_lastTime"];
            if (CBA_missionTime - _lastTime < CALL_REPEAT_INTERVAL) then {continue};
            private _position = [_aircraft, _missile] call FUNC(clockCall);
            private _shift = abs (_position#0 - _lastClock);
            if ((_shift min (12 - _shift)) >= 2) exitWith {
                GVAR(missilesCalled) set [_forEachIndex, [_missile, _position#0, CBA_missionTime]];
                _call = _position;
            };
        } forEach GVAR(missilesCalled);
    };

    if (_call isNotEqualTo []) then {
        _call params ["_clock", "_level"];
        GVAR(voiceId) = playSoundUI [format ["%1\call_%2_%3.ogg", QPATHTOF(data), _clock, _level], GVAR(volume), 1, false];
        GVAR(voiceEnd) = CBA_missionTime + VOICE_LENGTH;
    };
};

private _ducked = CBA_missionTime < GVAR(voiceEnd);
[_radars, _ducked] call FUNC(updateRadarCues);

private _loop = "";
if (_missiles findIf {_x#1} isNotEqualTo -1) then {
    _loop = "rwr_launch";
} else {
    if (_radars findIf {_x#1 isEqualTo 1} isNotEqualTo -1) then {
        _loop = "rwr_lock";
    };
};
[_loop, _ducked] call FUNC(setLoop);
