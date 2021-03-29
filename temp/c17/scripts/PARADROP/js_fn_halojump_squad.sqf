_plane = _this select 0;
_group_leader = _this select 1;
_group = group _group_leader;
_exit_door = 1;
_units = units _group_leader;
_unit_count = count _units;


sleep 1;

for "_x" from 0 to (_unit_count -1) do 
{
_unit_selected = _units select ((_unit_count -1) -_x);

if (_exit_door == 1) then {_exit_door = 2} else {_exit_door = 1};

//hintsilent format["SELECTED UNIT= \n%1 \n EXIT %2",_unit_selected, _exit_door];
sleep 0.5;

_plane say "usaf_c17_ramp";
_plane animate ["back_ramp_half",1];
_plane animate ["back_ramp_door_main",1];

sleep 15;

[_unit_selected, _plane, _exit_door] execVM "\USAF_C17\scripts\PARADROP\js_fn_halojump_soldier.sqf";
};

Exit;



