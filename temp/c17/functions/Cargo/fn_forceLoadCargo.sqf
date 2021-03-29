/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT           - Vehicle (c17) where the cargo will be attached
    1: OBJECT           - Vehicle (cargo), this will be attached to the (c17)
    2: BOOL(OPTIONAL)   - Debug

    Returns:
    NIL
*/
private ["_carrier","_obj","_cargo","_debug"];
_carrier = _this select 0;
_obj = _this select 1;
if (isNil {_obj} || isNil {_carrier}) exitWith { hint "forceLoadCargo, Parameters invaild"; };
//waitUntil {!isNull (_carrier) && !isNull (_obj)};
_cargo = _carrier getVariable ["c17_cargo",[]];
_debug = [_this,2,false] call bis_fnc_param;

if (_debug) then { (driver _carrier) vehicleChat str _obj; hint str _obj };
if (isNil {_carrier} || isNil {_obj}) exitWith { hint "Params not defined correctly!" };

if (_debug) then {
	(driver _carrier) vehicleChat format ["x:%1 y:%2 z:%3",(boundingBoxReal _obj select 1 select 0) - (boundingBoxReal _obj select 0 select 0),(boundingBoxReal _obj select 1 select 1) - (boundingBoxReal _obj select 0 select 1),(boundingBoxReal _obj select 1 select 2) - (boundingBoxReal _obj select 0 select 2)];
};
_carrier setVariable ["c17_cargo",((_carrier getVariable ["c17_cargo",[]]) + [_obj]),true];
_xoffset = (boundingBoxReal _obj select 1 select 2);
_yoffset = (boundingBoxReal _obj select 1 select 1);
if (count _cargo > 0) then {
    {_yoffset = ((boundingBoxReal _x select 1 select 1) - (boundingBoxReal _x select 0 select 1)) + _yoffset}forEach _cargo;
};
_obj attachTo [_carrier,[0,(15 - _yoffset),(-1.4 + _xoffset)]];
_obj setDir 180;

_id = _obj addEventHandler ["GetOut", {(_this select 2) moveInCargo (_this select 0 getvariable "carrier")}];
_obj setVariable ["getoutevh",_id,false]; // remembers the eventhandler so it can be removed again later on
_obj setVariable ["carrier",_carrier,false]; // tells the eventhandler what plane we're on