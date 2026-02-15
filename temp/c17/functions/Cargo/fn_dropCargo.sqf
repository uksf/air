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
private["_carrier","_obj","_id","_chute","_strobe","_smoke","_pls"];
_carrier = _this select 0;
_obj = _this select 1;
_obj disableCollisionWith _carrier;
/*_helper = "Sign_Sphere10cm_F" createVehicle getPos _obj;
_helper disableCollisionWith _carrier;
_helper setObjectTextureGlobal [0,""];
_helper setVelocity (velocity _carrier);
_helper attachTo [_obj,[0,0,0]];
detach _helper;
_obj attachTo [_helper,[0,0,0]];
waitUntil {_obj distance _carrier > 60};
detach _obj;
deleteVehicle _helper;*/
_obj attachTo [_carrier,[0,-30,(-5.55 + (boundingBoxReal _obj select 1 select 2))]];
sleep 0.5;
detach _obj;
_obj setVelocity (velocity _carrier);
_obj enableCollisionWith _carrier;
_carrier setVariable ["c17_cargo",((_carrier getVariable ["c17_cargo",[]]) - [_obj]),true];
if (isServer) then {
	_id = _obj getVariable "getoutevh";
	_obj removeEventHandler ["GetOut", _id];
//};
sleep 1;
waitUntil {getPosATLVisual _obj select 2 < 300};

//if (isServer) then {
    _pls = [(driver _carrier)] call Lala_C17_fnc_prepareForDrop;
    _chute = _pls select 0;
    _strobe = _pls select 1;
    _smoke = _pls select 2;
    [[_obj,_smoke,{(getPos (_this select 0) select 2 < 300 && getPos (_this select 0) select 2 > 1) && !(count crew (_this select 0) > 0)}], "Lala_C17_fnc_smoke"] spawn BIS_fnc_MP;
    _chute = _chute createVehicle getPos _obj;
    _strobe = _strobe createVehicle getPos _obj;

    _chute attachTo [_obj,[0,0,0]];
    _strobe attachTo [_obj,[0,-2,0.5]];
    detach _chute;
    if (_obj isKindOf "ReammoBox_F") then
    {
        _obj attachTo [_chute,[0,0,-0.5 -(boundingBoxReal _obj select 1 select 2)]];
    } else {
        _obj attachTo [_chute,[0,0,0]];
    };
    sleep 5;
    _chute setVectorUp [0,0,1];

    waitUntil {(getPosATLVisual _obj select 2) < 1 || isNull (_obj) || isNull (_chute)};
    detach _obj;
    _obj setVectorUp (surfaceNormal (getPos _obj));
    _obj setPos (getPosVisual _obj);

    detach _strobe;
    deleteVehicle _chute;
    sleep 1;
    _pos1 = getPosVisual _obj;
    waitUntil {count (crew _obj) > 0 || !(_pos1 isEqualTo getPosVisual _obj)};
    deleteVehicle _strobe;
};
