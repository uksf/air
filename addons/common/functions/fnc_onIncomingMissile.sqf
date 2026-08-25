#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        IncomingMissile event handler. Classifies the inbound missile and
        registers it on the target aircraft's activeThreats hashmap so the
        sensor panel extension can render its source label.

        Read-only — does not deploy countermeasures or play audio. Apache's
        own fnc_incomingMissile is unaffected and continues to handle those.

    Parameter(s):
        0: Aircraft (target) <OBJECT>
        1: Missile ammo type <STRING>
        2: Firer (instigator) <OBJECT>
        (engine passes 5 args; only first 3 used — matches apache convention)

    Return Value:
        Nothing

    Example:
        params via classEH on "Air"
*/
#define THREAT_TTL_SECONDS 12

params ["_aircraft", "_ammoType", "_firer"];

if (!alive _aircraft) exitWith {};

if (local _aircraft && {isVehicleRadarOn _aircraft}) then {
    [_aircraft, _firer] call FUNC(interrogateTarget);
};

if (!hasInterface) exitWith {};
if (vehicle player isNotEqualTo _aircraft) exitWith {};

private _source = [_ammoType] call FUNC(classifyMissileGuidance);
if (_source isEqualTo "") exitWith {};

private _missile = nearestObject [_firer, _ammoType];
if (isNull _missile) exitWith {};

private _threats = _aircraft getVariable [QGVAR(activeThreats), createHashMap];
_threats set [netId _missile, [_source, CBA_missionTime + THREAT_TTL_SECONDS, _missile]];
_aircraft setVariable [QGVAR(activeThreats), _threats];
