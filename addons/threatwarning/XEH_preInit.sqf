#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(aircraft) = [];
GVAR(localMissiles) = [];
GVAR(missileTargets) = [];
GVAR(goneMissiles) = [];
GVAR(seat) = [objNull, [], false];
GVAR(active) = false;
GVAR(radarsSeen) = [];
GVAR(missilesCalled) = [];
GVAR(loop) = ["", -1, 0, false];
GVAR(voiceId) = -1;
GVAR(voiceMissile) = objNull;
GVAR(voiceEnd) = 0;
GVAR(oneShots) = [];
GVAR(listenerAircraft) = objNull;

[
    QGVAR(volume),
    "SLIDER",
    ["Threat warning volume", "Volume of the aircraft missile and radar warning cues"],
    "UKSF Air",
    [0, 2, 1, 2],
    0
] call CBA_fnc_addSetting;

["Air", "init", {call FUNC(onInit)}, true, nil, true] call CBA_fnc_addClassEventHandler;

{
    [_x, {
        params ["", "", "", "", "", "", "_projectile"];
        if (local _projectile && {_projectile isKindOf "MissileBase"}) then {
            GVAR(localMissiles) pushBack [_projectile, objNull];
        };
    }] call CBA_fnc_addEventHandler;
} forEach ["ace_firedPlayer", "ace_firedNonPlayer", "ace_firedPlayerVehicle", "ace_firedNonPlayerVehicle"];

if (isServer) then {
    addMissionEventHandler ["PlayerDisconnected", {
        params ["", "", "", "", "_owner"];
        private _missiles = (GVAR(missileTargets) select {owner (_x#0) isEqualTo _owner}) apply {_x#0};
        if (_missiles isNotEqualTo []) then {
            [QGVAR(missilesGone), [_missiles]] call CBA_fnc_globalEvent;
        };
    }];
};

[QGVAR(missilesGone), {
    params ["_missiles"];
    GVAR(goneMissiles) = GVAR(goneMissiles) select {!isNull _x};
    {GVAR(goneMissiles) pushBackUnique _x} forEach _missiles;
    GVAR(missileTargets) = GVAR(missileTargets) select {!((_x#0) in _missiles)};
    GVAR(localMissiles) = GVAR(localMissiles) select {!((_x#0) in _missiles)};
    if (GVAR(voiceMissile) in _missiles) then {
        if (GVAR(voiceId) isNotEqualTo -1) then {stopSound GVAR(voiceId)};
        GVAR(voiceId) = -1;
        GVAR(voiceMissile) = objNull;
        GVAR(voiceEnd) = 0;
    };
    if (hasInterface && {GVAR(active)}) then {call FUNC(listenerTick)};
}] call CBA_fnc_addEventHandler;

[QGVAR(missileTarget), {
    params ["_missile", "_target"];
    if (_missile in GVAR(goneMissiles)) exitWith {};
    private _index = GVAR(missileTargets) findIf {_x#0 isEqualTo _missile};
    if (_index isEqualTo -1) then {
        GVAR(missileTargets) pushBack [_missile, _target];
    } else {
        (GVAR(missileTargets) select _index) set [1, _target];
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
