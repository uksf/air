#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(aircraft) = [];
GVAR(localMissiles) = [];
GVAR(missileTargets) = [];
GVAR(seat) = [objNull, [], false];
GVAR(active) = false;
GVAR(radarsSeen) = [];
GVAR(missilesCalled) = [];
GVAR(loop) = ["", -1, 0, false];
GVAR(voiceId) = -1;
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
        private _pending = GVAR(missileTargets) select {alive (_x#0) && {owner (_x#0) isEqualTo _owner}};
        private _recover = {
            {
                _x params ["_missile", "_target"];
                if (alive _missile && {local _missile} && {GVAR(localMissiles) findIf {_x#0 isEqualTo _missile} isEqualTo -1}) then {
                    GVAR(localMissiles) pushBack [_missile, _target];
                };
            } forEach GVAR(missileTargets);
        };
        [{_this isNotEqualTo [] && {_this findIf {alive (_x#0) && {!local (_x#0)}} isEqualTo -1}}, _recover, _pending, 5, _recover] call CBA_fnc_waitUntilAndExecute;
    }];
};

[QGVAR(missileTarget), {
    params ["_missile", "_target"];
    private _index = GVAR(missileTargets) findIf {_x#0 isEqualTo _missile};
    if (_index isEqualTo -1) then {
        GVAR(missileTargets) pushBack [_missile, _target];
    } else {
        (GVAR(missileTargets) select _index) set [1, _target];
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
