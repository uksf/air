/*
    Author: Lala14

    Description:
    To-Do

    Parameter (NO ARRAY):
    0: OBJECT - Object where this stuff is done to
    1: CLASS  - Smoke type
    2: CODE   - Conditions for while e.g {getPos (_this select 0) select 2 < 300}

    Returns:
    NIL
*/
private ["_obj","_smoke","_code"];
_obj = _this select 0;
_smokeColour = [_this,1,"smokeShell"] call bis_fnc_param;
_code = [_this, 2, {getPos (_this select 0) select 2 < 300 && getPos (_this select 0) select 2 > 1}] call bis_fnc_param;

//while {getPos (_this select 0) select 2 < 300 && getPos (_this select 0) select 2 > 1} do {
while _code do
{
	_smoke = _smokeColour createVehicle [getPos _obj select 0,getPos _obj select 1, .2];
	_smoke attachTo [_obj,[0,0,0]];
	waitUntil {isNull _smoke};
};
