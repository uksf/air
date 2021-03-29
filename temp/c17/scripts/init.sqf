params ["_plane"];
[_plane] spawn USAF_fnc_aiFormlights;

if(is3DEN || !hasInterface) exitWith {};

if ('usaf_utility_core_allow_move_in_cargo' call CBA_settings_fnc_get) then {
	_plane addAction ["<t color='#f0ff00'>Move Inside</t>", { _this spawn USAF_C17_fnc_moveInside }, nil, 1, false, true, "", "(_this in _target) && (toLower((assignedVehicleRole _this) select 0) isEqualTo 'cargo')"];
};
