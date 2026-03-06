#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(playWarning), {
    _this call FUNC(audio);
}] call CBA_fnc_addEventHandler;

GVAR(soundDurations) = createHashMapFromArray [
    [QGVAR(1oclock), 1.0],
    [QGVAR(2oclock), 1.0],
    [QGVAR(3oclock), 1.0],
    [QGVAR(4oclock), 1.0],
    [QGVAR(5oclock), 1.0],
    [QGVAR(6oclock), 1.0],
    [QGVAR(7oclock), 1.0],
    [QGVAR(8oclock), 1.0],
    [QGVAR(9oclock), 1.0],
    [QGVAR(10oclock), 1.0],
    [QGVAR(11oclock), 1.0],
    [QGVAR(12oclock), 1.0],
    [QGVAR(high), 0.5],
    [QGVAR(low), 0.5],
    [QGVAR(tailrotorDamaged), 1.7],
    [QGVAR(tailrotorFailure), 1.8],
    [QGVAR(mainrotorDamaged), 1.7],
    [QGVAR(mainrotorFailure), 1.7],
    [QGVAR(engineOneDamaged), 1.7],
    [QGVAR(engineOneFailure), 1.7],
    [QGVAR(engineTwoDamaged), 1.7],
    [QGVAR(engineTwoFailure), 1.7],
    [QGVAR(gunActuatorFailure), 1.9],
    [QGVAR(instrumentFailure), 1.7]
];

GVAR(trackedMissiles) = [];
GVAR(cooldowns) = createHashMap;
GVAR(damageHandlerPFHID) = -1;

ADDON = true;
