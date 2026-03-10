#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles incoming missile — plays directional audio warning
        and auto-deploys countermeasures

    Parameters:
        0: Aircraft <OBJECT>
        1: Missile type <STRING>
        2: Unit who fired missile <OBJECT>

    Return value:
        Nothing

    Example:
        [_aircraft, _missileType, _hostile] call uksf_air_apache_fnc_incomingMissile
*/
#define MISSILE_WARNING_COOLDOWN 5

params ["_aircraft", "_missileType", "_hostile"];

if !(alive _aircraft || _missileType isKindOf "MissileBase") exitWith {};

private _pilot = driver _aircraft;
if !(local _pilot) exitWith {};

private _missile = nearestObject [_hostile, _missileType];
GVAR(trackedMissiles) = GVAR(trackedMissiles) - [objNull];
if (isNull _missile || {_missile in GVAR(trackedMissiles)}) exitWith {};
GVAR(trackedMissiles) pushBack _missile;

private _aircraftPosition = getPosASL _aircraft;
private _missilePosition = getPosASL _missile;
private _missileRelativeVertical = ["low", "high"] select (_missilePosition#2 > _aircraftPosition#2);

private _cmMode = _aircraft getVariable [QGVAR(cmMode), 0];

// Flares (cm auto)
if (isEngineOn _aircraft && _cmMode == 2) then {
    [{
        ((_this#0) distance (_this#1)) < (500 + random 250)
    }, {
        player forceWeaponFire ["UK3CB_BAF_CMFlareLauncher", "Burst5"];
    }, [_aircraft, _missile], 10] call CBA_fnc_waitUntilAndExecute;
};

// Audio warning (cm semi or auto)
if (isEngineOn _aircraft && _cmMode > 0) then {
    private _lastMissileWarning = GVAR(cooldowns) getOrDefault ["missile", -1];
    if (CBA_missionTime - _lastMissileWarning < MISSILE_WARNING_COOLDOWN) exitWith {};
    GVAR(cooldowns) set ["missile", CBA_missionTime];

    private _missileDirection = ((_missilePosition#0) - (_aircraftPosition#0)) atan2 ((_missilePosition#1) - (_aircraftPosition#1));
    if (_missileDirection < 0) then {
        _missileDirection = _missileDirection + 360;
    };

    private _relativeBearing = (_missileDirection - direction _aircraft + 360) mod 360;
    private _oclock = floor ((_relativeBearing + 15) / 30);
    if (_oclock isEqualTo 0 || {_oclock isEqualTo 12}) then {
        _oclock = 12;
    };

    private _clockSound = format [QUOTE(GVAR(%1oclock)), _oclock];
    private _verticalSound = format [QUOTE(GVAR(%1)), _missileRelativeVertical];
    private _clockDuration = GVAR(soundDurations) getOrDefault [_clockSound, 1.0];

    // Play clock direction then vertical for pilot
    playSound [_clockSound, true];
    [{
        playSound [_this, true];
    }, _verticalSound, _clockDuration] call CBA_fnc_waitAndExecute;

    // Notify gunner
    private _gunner = gunner _aircraft;
    if (!isNull _gunner && {!local _gunner}) then {
        [QGVAR(playWarning), [_clockSound, "missileDirection"], _gunner] call CBA_fnc_targetEvent;
        [{
            params ["_verticalSound", "_gunner"];
            [QGVAR(playWarning), [_verticalSound, "missileVertical"], _gunner] call CBA_fnc_targetEvent;
        }, [_verticalSound, _gunner], _clockDuration] call CBA_fnc_waitAndExecute;
    };
};
