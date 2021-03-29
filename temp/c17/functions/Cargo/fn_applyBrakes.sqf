/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: OBJECT - Cargo vehicle to be slowed down to 0 km/h (to simulate parachute braking)

    Returns:
    NIL
*/
_obj = _this select 0;

hint "Brakes Active!";

while {round (speed _obj) > 0} do
{
	_vel = velocity _obj;
	_obj setVelocity [(_vel select 0)/ 1.06, (_vel select 1)/ 1.06, (_vel select 2)/ 1.06];
	sleep 0.1;
};