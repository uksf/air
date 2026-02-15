/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - Carrier
    1: OBJECT - To be loaded into first object

    Returns:
    NIL
*/
private["_carrier","_obj","_id"];
_carrier = _this select 0;
_obj = _this select 1;
_cargo = _carrier getVariable ["c17_cargo",[]];
if ((_carrier modelToWorldVisual [0,-20,-3.45]) distance _obj > 15) then {
	_carrier setVariable ["c17_cargo",((_carrier getVariable ["c17_cargo",[]]) - [_obj]),true];
} else {
	_carrier setVariable ["c17_cargo",((_carrier getVariable ["c17_cargo",[]]) + [_obj]),true];
	_xoffset = (boundingBoxReal _obj select 1 select 2);
	_yoffset = (boundingBoxReal _obj select 1 select 1);
	if (count _cargo > 0) then {
		{_yoffset = ((boundingBoxReal _x select 1 select 1) - (boundingBoxReal _x select 0 select 1)) + _yoffset}forEach _cargo;
	};
	if (isServer) then {
		_wait = [_obj,_carrier,[0,-21,(-3.5 + _xoffset)],[0,-3 - (boundingBoxReal _obj select 1 select 1),(-1.4 + _xoffset)],0.1,0.01,	180] spawn Lala_C17_fnc_attachToSmooth;
		waitUntil {scriptDone _wait};
		_wait2 = [_obj,_carrier,[0,-3 - (boundingBoxReal _obj select 1 select 1),(-1.4 + _xoffset)],[0,(15 - _yoffset),(-1.4 + _xoffset)],0.1,0.01,	180] spawn Lala_C17_fnc_attachToSmooth;
		waitUntil {scriptDone _wait2};

		_id = _obj addEventHandler ["GetOut", {(_this select 2) moveInCargo (_this select 0 getvariable "carrier")}];
		_obj setVariable ["getoutevh",_id,false]; // remembers the eventhandler so it can be removed again later on
		_obj setVariable ["carrier",_carrier,false]; // tells the eventhandler what plane we're on
	};
};
