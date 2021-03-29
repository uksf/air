/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - To check see if cargo is found and then the nearest vehicle
    1: NUMBER - (0, 1, 2) For door setting (0 = closed, 1 = half, 2 = open)

    Returns:
    NIL
*/
params [["_veh", objNull],["_num",0]];
if (isNull _veh) exitWith {};

switch (_num) do
{
	case 0: { _veh animateSource ["back_ramp",0,true]; _veh animateSource ["back_ramp_half",0,true]; _veh animateSource ["back_ramp_switch",0,true]; _veh animateSource ["back_ramp_half_switch",0,true]; };
	case 1: { _veh animateSource ["back_ramp",0,true]; _veh animateSource ["back_ramp_half",1,true]; _veh animateSource ["back_ramp_switch",0,true]; _veh animateSource ["back_ramp_half_switch",1,true]; };
	case 2: { _veh animateSource ["back_ramp",1,true]; _veh animateSource ["back_ramp_half",0,true]; _veh animateSource ["back_ramp_switch",1,true]; _veh animateSource ["back_ramp_half_switch",0,true]; };
};