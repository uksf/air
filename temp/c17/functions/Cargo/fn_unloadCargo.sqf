/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - To check see if cargo is found and then the nearest vehicle
    1: OBJECT - Object that is to be detached

    Returns:
    NIL
*/
private["_carrier","_obj","_id"];
_carrier = _this select 0;
_obj = _this select 1;
_cargo = _carrier getVariable ["c17_cargo",[]];

if (isServer) then {
    _carrier setVariable ["c17_cargo",((_carrier getVariable ["c17_cargo",[]]) - [_obj]),true];
    _carrier setVariable ["c17_cargo_loading",true,true];
    _xoffset = (boundingBoxReal _obj select 1 select 2);
    _yoffset = (boundingBoxReal _obj select 1 select 1);
    if (count _cargo > 0) then {
        _cargo = _cargo - [_obj];
        {_yoffset = ((boundingBoxReal _x select 1 select 1) - (boundingBoxReal _x select 0 select 1)) + _yoffset}forEach _cargo;
    };
     _wait = [_obj,_carrier,[0,(15 - _yoffset),(-1.4 + _xoffset)],[0,-3 - (boundingBoxReal _obj select 1 select 1),(-1.4 + _xoffset)],0.1,0.01,180] spawn Lala_C17_fnc_attachToSmooth;
     waitUntil {scriptDone _wait};
     _wait2 = [_obj,_carrier,[0,-3 - (boundingBoxReal _obj select 1 select 1),(-1.4 + _xoffset)],[0,-21,(-3.5 + _xoffset)],0.1,0.01,180] spawn Lala_C17_fnc_attachToSmooth;
     waitUntil {scriptDone _wait2};
     _carrier setVariable ["c17_cargo_loading",false,true];

    detach _obj;
    _obj setVelocity (velocity _carrier);

	_id = _obj getVariable "getoutevh";
	_obj removeEventHandler ["GetOut", _id];
};
