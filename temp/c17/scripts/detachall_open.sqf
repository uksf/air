_plane = _this select 0;
_plane allowDamage false;
_player = _this select 2;
_null = objNull;
_technics = position _plane nearEntities 30;
_cnt = count _technics;
_vel = velocity _plane;
sleep 0.01;

if (_cnt > 0) then
{
	{
		if ((_x)!=(_plane)) then
		{			
			sleep 0.01;
			_x attachTo [_plane,[0,-20,-5]];
			sleep 0.05;
			detach _x;
			sleep 0.01;
			_plane setVelocity [(_vel select 0),(_vel select 1),(_vel select 2)];
			sleep 1;
			nul=[_plane,_x] execVM "\USAF_C17\scripts\dropit.sqf";
			_x setfuel 1;
			_x enableSimulation true;
			_x allowDamage true;
		}
	}
	forEach _technics;
};
_plane setVelocity [(_vel select 0),(_vel select 1),(_vel select 2)];
sleep 1;
_plane allowDamage true;
_plane say "usaf_c17_ramp";
_plane animate ["back_ramp_half",0];
_plane animate ["back_ramp_st_half",0];
_plane animate ["back_ramp_p",0];
_plane animate ["back_ramp_p_2",0];
_plane animate ["back_ramp_door_main",0];
if (true) exitWith {};
