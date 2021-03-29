private ["_number","_plane","_exit_pos","_pos_para","_pos_p ara_actual","_soldier","_Parachute"];
_soldier = _this select 0;
_plane = _this select 1;
_exit_pos = _this select 2;


_soldier action ["eject", _plane];
WaitUntil {(vehicle _soldier) != _plane};


_soldier attachTo [_plane, [0,0,0], "jumppoint"];
sleep 0.1;

detach _Soldier;



sleep 1.5;


_Parachute = _Soldier addBackpack "B_Parachute";



Exit;




