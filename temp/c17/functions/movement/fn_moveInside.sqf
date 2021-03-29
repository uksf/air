/*
a: reyhard
adds ability to move around flying c17 cargo bay
kind of attachToWithMovment but using attachTo command
*/

_v = _this select 0;
_p = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];;
//_pos = _v worldToModel (getPosATLVisual player); //this was to place the player out from their seat pos doesn't work as good as I want it
_heightOffset = -1.22;
_pos = [0,11,_heightOffset];
_pos set [2, _heightOffset];
moveOut _p;
unassignVehicle _p;
USAF_c130J_attached = true;
_posOld = _pos;
_p attachTo [_v,_pos];

_vc = [0,0,0];
_h1 = [0,0,0];
_h2 = [0,0,0];
_h3 = [0,0,0];

_dir = getdir _p;

hint format["to get back to seat press %1",actionKeysNames "LockTarget"];
_prevWalk = isForcedWalk _p;
_p forceWalk true;
while {USAF_c130J_attached} do
{

	if(inputAction "LockTarget" > 0)exitWith
	{
		detach _p;
		USAF_c130J_attached = false;
		_p setVelocity [0,0,0];
		_p moveInCargo _v;
	};
	if(inputAction "moveForward" > 0)then
	{
		_pos = _pos vectorAdd (([(vectorDir _p),getDirVisual _v] call BIS_fnc_rotateVector2D) vectorMultiply 0.05);
	};
	if(inputAction "moveBack" > 0)then
	{
		_pos = _pos vectorAdd (([(vectorDir _p),getDirVisual _v] call BIS_fnc_rotateVector2D) vectorMultiply -(0.05));
	};
	if(inputAction "turnLeft" > 0)then
	{
		_vc = [vectorDirVisual _p,(getDirVisual _v)-90] call BIS_fnc_rotateVector2D;
		_pos = _pos vectorAdd (_vc vectorMultiply -0.05);
	};
	if(inputAction "turnRight" > 0)then
	{
		_vc = [vectorDirVisual _p,(getDirVisual _v)+90] call BIS_fnc_rotateVector2D;
		_pos = _pos vectorAdd ( _vc vectorMultiply -(0.05) );
	};
	if(not(_pos isEqualTo _posOld))then
	{
		if ((getPos _p select 2) > 0 && (getPos _p select 2) < 1) then {
			_heightOffset = _heightOffset - (getPos _p select 2);
		};
		if ((getPos _p select 2) < 0) then {
			_heightOffset = _heightOffset + abs(getPos _p select 2);
		};

		_pos set [2, _heightOffset];

		if( (getPosASL _v select 2) > (getPosATL _v select 2) )then{
			_h1=ATLToASL(_v modelToWorldVisual [(_pos select 0 )*1.2,(_pos select 1)*1.2,(_pos select 2)+0.2]);
			_h2=ATLToASL(_v modelToWorldVisual (_posOld vectorAdd [0,0,0.1]));
		}else{
			_h1=(_v modelToWorldVisual [(_pos select 0)*1.2,(_pos select 1)*1.2,(_pos select 2)+0.2]);
			_h2=(_v modelToWorldVisual (_posOld vectorAdd [0,0,0.2]));
		};
		if(not(lineIntersects [_h1,_h2]))then{_p attachTo [_v, _pos]; _posOld = _pos}else{_pos = _posOld};
		if((getpos _p select 2) > 1)exitWith{
			_prevDamage = isDamageAllowed _p;
			_p allowDamage false;
			detach _p;
			_p setVelocity [0,0,0];
			USAF_c130J_attached = false;
			sleep 1;
			_p allowDamage _prevDamage;
		};
		if (!alive _v) exitWith {
			USAF_c130J_attached = false;
			detach _p;
		};
	};
	if (inputAction "AimRight" > 0) then {_dir = _dir+(2*(inputAction "AimRight")); _p setdir _dir;};
	if (inputAction "AimLeft" > 0) then 	{_dir = _dir-(2*(inputAction "AimLeft")); _p setdir _dir;};
	sleep 0.01;
};
_p forceWalk _prevWalk;