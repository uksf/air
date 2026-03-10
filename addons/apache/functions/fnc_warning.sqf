#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts damage warning PFH — checks hitpoints every 3 seconds,
        plays staggered audio warnings for pilot and gunner

    Parameters:
        0: Helicopter <OBJECT>

    Return value:
        Nothing

    Example:
        [_helicopter] call uksf_air_apache_fnc_warning
*/
params ["_helicopter"];

GVAR(damageHandlerPFHID) = [{
    params ["_args"];
    _args params ["_helicopter"];

    if !(alive _helicopter && {player isEqualTo driver _helicopter}) exitWith {
        [GVAR(damageHandlerPFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(damageHandlerPFHID) = -1;
    };

    private _warnings = [];

    // Tail rotor
    private _damage = _helicopter getHitPointDamage "HitVRotor";
    if (_damage > (_helicopter getVariable [QGVAR(previousTailDamage), 0])) then {
        if (_damage >= 0.8) then {
            _warnings pushBack [QGVAR(tailrotorFailure), "tailRotor"];
        } else {
            if (_damage > 0.4) then {
                _warnings pushBack [QGVAR(tailrotorDamaged), "tailRotor"];
            };
        };
        _helicopter setVariable [QGVAR(previousTailDamage), _damage, true];
    };

    // Main rotor
    _damage = _helicopter getHitPointDamage "HitHRotor";
    if (_damage > (_helicopter getVariable [QGVAR(previousMainDamage), 0])) then {
        if (_damage >= 0.8) then {
            _warnings pushBack [QGVAR(mainrotorFailure), "mainRotor"];
        } else {
            if (_damage > 0.4) then {
                _warnings pushBack [QGVAR(mainrotorDamaged), "mainRotor"];
            };
        };
        _helicopter setVariable [QGVAR(previousMainDamage), _damage, true];
    };

    // Engine 1
    _damage = _helicopter getHitPointDamage "HitEngine1";
    if (_damage > (_helicopter getVariable [QGVAR(previousE1Damage), 0])) then {
        if (_damage >= 0.8) then {
            _warnings pushBack [QGVAR(engineOneFailure), "engine1"];
        } else {
            if (_damage > 0.4) then {
                _warnings pushBack [QGVAR(engineOneDamaged), "engine1"];
            };
        };
        _helicopter setVariable [QGVAR(previousE1Damage), _damage, true];
    };

    // Engine 2
    _damage = _helicopter getHitPointDamage "HitEngine2";
    if (_damage > (_helicopter getVariable [QGVAR(previousE2Damage), 0])) then {
        if (_damage >= 0.8) then {
            _warnings pushBack [QGVAR(engineTwoFailure), "engine2"];
        } else {
            if (_damage > 0.4) then {
                _warnings pushBack [QGVAR(engineTwoDamaged), "engine2"];
            };
        };
        _helicopter setVariable [QGVAR(previousE2Damage), _damage, true];
    };

    // Gun
    _damage = _helicopter getHitPointDamage "HitGun";
    if (_damage > (_helicopter getVariable [QGVAR(previousGunDamage), 0])) then {
        if (_damage >= 0.8) then {
            _helicopter removeMagazine "UK3CB_BAF_1200Rnd_30mm_M230_HEDP_T";
            _helicopter addMagazine "UK3CB_BAF_JAM_30mm_M230_HEDP_T";
            _warnings pushBack [QGVAR(gunActuatorFailure), "gun"];
        };
        _helicopter setVariable [QGVAR(previousGunDamage), _damage, true];
    };

    // Avionics
    _damage = _helicopter getHitPointDamage "HitAvionics";
    if (_damage > (_helicopter getVariable [QGVAR(previousInsDamage), 0])) then {
        if (_damage >= 0.8) then {
            _warnings pushBack [QGVAR(instrumentFailure), "avionics"];
        };
        _helicopter setVariable [QGVAR(previousInsDamage), _damage, true];
    };

    if (_warnings isEqualTo []) exitWith {};

    // Play locally (pilot) with stagger based on sound duration
    private _delay = 0;
    {
        _x params ["_sound", "_cooldownKey"];
        [{
            _this call FUNC(audio);
        }, [_sound, _cooldownKey], _delay] call CBA_fnc_waitAndExecute;
        _delay = _delay + (GVAR(soundDurations) getOrDefault [_sound, 1.5]);
    } forEach _warnings;

    // Notify gunner
    private _gunner = gunner _helicopter;
    if (!isNull _gunner && {!local _gunner}) then {
        _delay = 0;
        {
            _x params ["_sound", "_cooldownKey"];
            [{
                params ["_sound", "_cooldownKey", "_gunner"];
                [QGVAR(playWarning), [_sound, _cooldownKey], _gunner] call CBA_fnc_targetEvent;
            }, [_sound, _cooldownKey, _gunner], _delay] call CBA_fnc_waitAndExecute;
            _delay = _delay + (GVAR(soundDurations) getOrDefault [_sound, 1.5]);
        } forEach _warnings;
    };
}, 3, [_helicopter]] call CBA_fnc_addPerFrameHandler;
