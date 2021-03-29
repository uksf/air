/*
    Author: Lala14

    Description:
    attaches an object and moves it towards a point *SPAWN THIS*

    Parameter(s):
    0: OBJECT 	- Attach this vehicle
    1: OBJECT	- The Vehicle that the object is being attached to
    2: ARRAY	- Where the object starts (model space)
    3: ARRAY	- Move object to here (model space)
    4: NUMBER	- Step take	(optional) default 1
    5: NUMBER	- Sleep time (optional) default 0.1
    6: NUMBER	- DIRECTION	(optional) default 0
    7: ARRAY	- SetVectorDirAndUp	(optional) default [[0,0,0],[0,0,0]]
    8: BOOL		- DEBUG	(optional) default false

    Returns:
    NIL
*/
/*null = _this spawn
{*/
	_obj = _this select 0;
	_attachTo = _this select 1;
	_attachToInit = _this select 2;
	_moveToPart = _this select 3;
	_step = [_this,4,1] call bis_fnc_param;
	_sleep = [_this,5,0.1] call bis_fnc_param;
	_dir = [_this,6,0] call bis_fnc_param;
	_vectordirandup = [_this,7,[[0,0,0],[0,0,0]]] call bis_fnc_param;
	_debug = [_this,8,false] call bis_fnc_param;

	_steps = 1;

	_attachToInitx = _attachToInit select 0;
	_attachToInity = _attachToInit select 1;
	_attachToInitz = _attachToInit select 2;

	_moveToPartx = _moveToPart select 0;
	_moveToParty = _moveToPart select 1;
	_moveToPartz = _moveToPart select 2;

	_x = _moveToPartx - _attachToInitx;
	_y = _moveToParty - _attachToInity;
	_z = _moveToPartz - _attachToInitz;

	if (_debug) then {systemChat format ["x:%1 y:%2 z:%3",_x,_y,_z];};

	switch (true) do {
	    case (((abs _x) > (abs _y)) && ((abs _x) > (abs _z))): { _steps = round ((abs _x) / _step); };
	    case (((abs _y) > (abs _z)) && ((abs _y) > (abs _x))): { _steps = round ((abs _y) / _step); };
	    case (((abs _z) > (abs _y)) && ((abs _z) > (abs _x))): { _steps = round ((abs _z) / _step); };
	};

	if (_debug) then {systemChat format ["steps: %1",_steps];};
	_obj attachTo [_attachTo,_attachToInit];
	if (_dir != 0) then {[[_obj,_dir],"setDir"] spawn bis_fnc_MP};
	if !(_vectordirandup isEqualTo [[0,0,0],[0,0,0]]) then {_obj setVectorDirAndUp _vectordirandup};

	for "_i" from 0 to _steps do {
		_pos = [(((_x / _steps) * _i) + _attachToInitx), (((_y / _steps) * _i) + _attachToInity), (((_z / _steps) * _i) + _attachToInitz)];
		if (_debug) then {systemChat str _pos;};
		_obj AttachTo [_attachTo, _pos];
		sleep _sleep;
	};

	if (_dir != 0) then {[[_obj,_dir],"setDir"] spawn bis_fnc_MP};
	if !(_vectordirandup isEqualTo [[0,0,0],[0,0,0]]) then {_obj setVectorDirAndUp _vectordirandup};
//};

true;