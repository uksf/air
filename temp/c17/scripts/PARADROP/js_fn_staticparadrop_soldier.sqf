private ["_number","_plane","_exit_pos","_pos_para","_pos_p ara_actual","_soldier","_Parachute"];
_soldier = _this select 0;
_plane = _this select 1;
_exit_pos = _this select 2;

_pos_para = _plane selectionposition (format ["pos_para_%1",_exit_pos]);
_pos_para_actual = _plane ModelToWorld _pos_para;

_soldier action ["eject", _plane];
WaitUntil {(vehicle _soldier) != _plane};


_soldier attachTo [_plane, [0,0,0], "_pos_para"];
sleep 0.1;

detach _Soldier;
_soldier setpos _pos_para_actual;


sleep 1.5;


_Parachute = "NonSteerable_Parachute_F" createvehicle (getpos _soldier);
_Parachute setdir (getdir _soldier);
_Parachute setpos (getpos _soldier);
_soldier moveindriver _Parachute;



Exit;




