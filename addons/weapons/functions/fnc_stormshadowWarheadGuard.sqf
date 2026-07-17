#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Attach ground-impact warhead guard to a Storm Shadow projectile.
        Engine shotMissile does not spawn triggerOnImpact submunitions on bare
        terrain (vanilla Titan/Hellfire same). Solid objects work. If Explode
        fires without SubmunitionCreated, manually spawn the AP penetrator
        (ShellBase) which does chain into the HE payload on ground.

    Parameter(s):
        0: Projectile <OBJECT>

    Return Value:
        None
*/
params [["_projectile", objNull]];
if (isNull _projectile) exitWith {};
if (_projectile getVariable [QGVAR(ssGuard), false]) exitWith {};
_projectile setVariable [QGVAR(ssGuard), true];
_projectile setVariable [QGVAR(ssSubSpawned), false];

_projectile addEventHandler ["SubmunitionCreated", {
    params ["_projectile"];
    _projectile setVariable [QGVAR(ssSubSpawned), true];
}];

_projectile addEventHandler ["Explode", {
    params ["_projectile", ["_pos", [0, 0, 0]], ["_velocity", [0, 0, -1]]];
    if (_projectile getVariable [QGVAR(ssSubSpawned), false]) exitWith {};

    if ((vectorMagnitude _pos) < 1) then {
        _pos = getPosASL _projectile;
    };
    if ((vectorMagnitude _velocity) < 1) then {
        _velocity = [0, 0, -1000];
    };

    private _dir = vectorNormalized _velocity;
    if ((_dir select 2) > -0.15) then {
        _dir = vectorNormalized [(_dir select 0) * 0.3, (_dir select 1) * 0.3, -1];
    };

    private _spawnPos = _pos vectorAdd [0, 0, 0.5];
    private _penClass = QGVAR(penetrator_stormshadow);
    private _pen = _penClass createVehicle [0, 0, 0];
    _pen setPosASL _spawnPos;
    _pen setVectorDirAndUp [_dir, [0, 0, 1]];
    _pen setVelocity (_dir vectorMultiply 1000);

    private _log = missionNamespace getVariable [QGVAR(ssGuardLog), []];
    _log pushBack ["manual_pen", _penClass, _spawnPos, !isNull _pen];
    missionNamespace setVariable [QGVAR(ssGuardLog), _log];
}];
