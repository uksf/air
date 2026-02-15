/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - To check see if cargo is found and then the nearest vehicle

    Returns:
    NIL
*/
private["_carrier","_obj","_id","_chute","_strobe","_pls"];
_carrier = _this select 0;
_obj = _this select 1;
_obj disableCollisionWith _carrier;
/*_helper = "Sign_Sphere10cm_F" createVehicle getPos _obj;
_helper disableCollisionWith _carrier;
_helper hideObject true;
_helper attachTo [_obj,[0,0,0]];
detach _helper;
_obj attachTo [_helper,[0,0,0]];
waitUntil {_obj distance _carrier > 60};
detach _obj;
deleteVehicle _helper;*/
_obj attachTo [_carrier,[0,-30,(-5.55 + (boundingBoxReal _obj select 1 select 2))]];
sleep 0.1;
detach _obj;
_obj setVelocity (velocity _carrier);
_obj enableCollisionWith _carrier;
_obj setVelocity (velocity _carrier);
_carrier setVariable ["c17_cargo",((_carrier getVariable ["c17_cargo",[]]) - [_obj]),true];
if (isServer) then {
	_id = _obj getVariable "getoutevh";
	_obj removeEventHandler ["GetOut", _id];
//};

sleep 1;
//if (isServer) then {
    _pls = [_carrier,_obj] call Lala_C17_fnc_prepareForDrop;
    _chute = _pls select 0;
    _strobe = _pls select 1;
    _chute = createVehicle [_chute, position _obj, [], 0, "CAN_COLLIDE"];
    _strobe = _strobe createVehicle getPos _obj;

    _chute attachTo [_obj,[0,0,3]];
    _chute setVectorUp [0.99,0,0.01];
    _chute setDir 90;
    _strobe attachTo [_obj,[0,-2,0.5]];
    /*detach _chute;
    _obj attachTo [_chute,[0,0,-3]];
    _chute setVectorUp [0,-0.99,0.01];
    _obj setVectorUp [0.99,0,0];*/
    [_obj] spawn Lala_C17_fnc_applyBrakes;

    //sleep 6;
    waitUntil {speed _obj < 25};
    detach _obj;

	detach _strobe;
	deleteVehicle _chute;
};
