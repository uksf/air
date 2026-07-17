#include "script_component.hpp"

addMissionEventHandler ["ProjectileCreated", {
    params ["_projectile"];
    if (!local _projectile) exitWith {};
    if ((typeOf _projectile) isNotEqualTo "rksla3_ammo_stormshadow") exitWith {};
    [_projectile] call FUNC(stormshadowWarheadGuard);
}];
