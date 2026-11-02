#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the clock position and high or low call for a missile relative to the aircraft

    Parameters:
        0: Aircraft <OBJECT>
        1: Missile <OBJECT>

    Return value:
        [Clock position 1-12, "high" or "low"] <ARRAY>

    Example:
        [_aircraft, _missile] call uksf_air_threatwarning_fnc_clockCall
*/
params ["_aircraft", "_missile"];

private _clock = round ((_aircraft getRelDir _missile) / 30) mod 12;
if (_clock isEqualTo 0) then {
    _clock = 12;
};
private _level = ["low", "high"] select ((getPosASL _missile)#2 >= (getPosASL _aircraft)#2);

[_clock, _level]
