/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - To check see if cargo is found and then the nearest vehicle

    Returns:
    NIL
*/
_veh = _this select 0;
_veh animate ["cargo_hide_now",1];
_transport = getNumber (configFile >> "CfgVehicles" >> typeof _veh >> "transportSoldier");
for "_i" from 0 to _transport do {
	if (isNil {_veh lockedCargo _i}) exitWith {};
	_veh lockCargo [_i,true];
};
