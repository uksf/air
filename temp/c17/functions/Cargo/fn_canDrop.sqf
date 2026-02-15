/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - To-Do

    Returns:
    NIL
*/
_carrier = _this select 0;
_cargos = _carrier getVariable ["c17_cargo",[]];
if (count _cargos <= 0) exitWith { hint "Found no cargo to drop." };
_cargo = _cargos select (count (_cargos) - 1);

if (_carrier animationPhase "back_ramp_switch" == 1) then {
    _carrier animate ["back_ramp_switch",0];
    _carrier animate ["back_ramp",0];
    _carrier animate ["back_ramp_st",0];
    _carrier animate ["back_ramp_p",0];
    _carrier animate ["back_ramp_p_2",0];
    _carrier animate ["back_ramp_door_main",0];
};
if (_carrier animationPhase "back_ramp_half_switch" == 0) then
{
    _carrier setVariable ["c17_cargo_loading",true,true];
    _carrier animate ["back_ramp_half_switch",1];
    [_carrier] execVM "\USAF_C17\scripts\back_rampdown_half.sqf";
    waitUntil {(_carrier animationPhase "back_ramp_door_main") == 1};
    waitUntil {(_carrier animationPhase "back_ramp_half") == 1};
    _carrier setVariable ["c17_cargo_loading",false,true];
};
    _veh_name = getText (configFile >> "cfgVehicles" >> typeof _cargo >> "displayName");
    (driver _carrier) vehicleChat format ["%1 dropped from cargo",_veh_name];
    hint format ["%1 dropped from cargo",_veh_name];
	[[_carrier, _cargo], "Lala_C17_fnc_dropCargo"] spawn BIS_fnc_MP;
/*waitUntil {isNil {_carrier getVariable "c17_cargo"}};
_carrier animate ["ramp_top", 0];
_carrier animate ["ramp_bottom", 0];*/
