/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT           - To check see if cargo is found and then the nearest vehicle
    1: BOOL(OPTIONAL)   - Debug

    Returns:
    NIL
*/
_carrier = _this select 0;
_cargo = _carrier getVariable ["c17_cargo",[]];
_loadpos = _carrier ModelToWorld [0,-20,-3.45];
_debug = [_this,1,false] call bis_fnc_param;

//if (count _cargo > 0) exitWith { hint "Cargo is already full." };
_near = nearestObjects [_loadpos, ["LandVehicle","Ship","ThingX","Air"], 15];
_near = _near - _cargo;
_obj = _near select 0;

if (isNil {_obj}) exitWith { hint 'No vehicle(s) found'};

if (_debug) then { (driver _carrier) vehicleChat str _obj; hint str _obj };
_bound = boundingBoxReal _obj;
_width = (_bound select 1 select 0) - (_bound select 0 select 0);
_length = (_bound select 1 select 1) - (_bound select 0 select 1);
_height = (_bound select 1 select 2) - (_bound select 0 select 2);
_weight = getMass _obj;
if (_weight == 0) then { _weight = 250; hint "That object doesn't have any weight!\n defaulting to 250kg" };
    if (count _cargo > 0) then {
        {_length = ((boundingBoxReal _x select 1 select 1) - (boundingBoxReal _x select 0 select 1)) + _length; _weight = getMass _x + _weight}forEach _cargo;
    };

if (count _near > 0) then {
	if (_debug) then {
        (driver _carrier) vehicleChat format ["x:%1 y:%2 z:%3",_width,_length,_height];
		hint format ["x:%1 y:%2 z:%3",_width,_length,_height];
	};
    if ((_width <= 10) && (_length <= 22) && (_height <= 6) && (_weight <= 137250)) then {
        //_carrier setVariable ["c17_cargo","loading",true];
        _veh_name = getText (configFile >> "cfgVehicles" >> typeof _obj >> "displayName");
        (driver _carrier) vehicleChat format ["Loading %1 into cargo",_veh_name];
        if (_carrier animationPhase "back_ramp_switch" == 0) then
        {
            _carrier setVariable ["c17_cargo_loading",true,true];
            _carrier animate ["back_ramp_switch",1];
            [_carrier] execVM "\USAF_C17\scripts\back_rampdown.sqf";
            waitUntil {(_carrier animationPhase "back_ramp_door_main") == 1};
            waitUntil {(_carrier animationPhase "back_ramp") == 1};
            _carrier setVariable ["c17_cargo_loading",false,true];
        };
			[[_carrier, _obj], "Lala_C17_fnc_loadCargo"] spawn BIS_fnc_MP;
		/*sleep 3;
        _carrier animate ["ramp_top", 0];
        _carrier animate ["ramp_bottom", 0];*/
    } else {
        (driver _carrier) vehicleChat "This won't fit in the cargospace";
        hint "This won't fit in the cargospace";
    };
} else {
    (driver _carrier) vehicleChat "Nothing in range";
    hint "Nothing in range";
};