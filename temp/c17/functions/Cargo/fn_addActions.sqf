/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - To check see if cargo is found and then the nearest vehicle

    Returns:
    NIL
*/
//[0,-20,-3.45]
_veh = _this select 0;
//if (isNil {_veh getVariable "Lala_actionsAdded"}) then {
	_veh addaction ["<t color='#FF0000'>Load cargo</t>", { [(_this select 0)] spawn Lala_C17_fnc_canLoad}, [],1,false,false,"",' (count (vehicle _target getVariable ["c17_cargo",[]]) >= 0) && count(nearestObjects [(_target ModelToWorld [0,-20,-3.45]), ["LandVehicle","Ship","ThingX"], 15] - (vehicle _target getVariable ["c17_cargo",[]])) > 0 && !(vehicle _target getVariable ["c17_cargo_loading",false]) && (getPosATL _target select 2 < 3)'];

	_veh addaction ["<t color='#FF0000'>Unload cargo</t>", { [(_this select 0)] spawn Lala_C17_fnc_canUnload }, [],1,false,false,"",'  (count (vehicle _target getVariable ["c17_cargo",[]]) > 0) && (getPosATL _target select 2 < 3) && !(vehicle _target getVariable ["c17_cargo_loading",false])'];

	_veh addaction ["<t color='#FF0000'>Lapes current cargo</t>", { [(_this select 0)] spawn Lala_C17_fnc_canLapes }, [],1,false,false,"",' (count (vehicle _target getVariable ["c17_cargo",[]]) > 0) && (getPosATL _target select 2 > 3) && (getPosATL _target select 2 < 15) && !(vehicle _target getVariable ["c17_cargo_loading",false])'];

    //&& (typeName (vehicle _target getVariable ["c17_cargo",[]] select (count (vehicle _target getVariable ["c17_cargo",[]] - 1))) == "OBJECT")

	_veh addaction ["<t color='#FF0000'>Drop cargo</t>", { [(_this select 0)] spawn Lala_C17_fnc_canDrop }, [],1,false,false,"",' (count (vehicle _target getVariable ["c17_cargo",[]]) > 0) && (getPosATL _target select 2 > 50) && !(vehicle _target getVariable ["c17_cargo_loading",false])'];
	//_veh setVariable ["Lala_actionsAdded",true,true];
//};
