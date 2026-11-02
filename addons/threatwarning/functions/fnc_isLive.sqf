#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether the aircraft threat warning system can run: aircraft alive, engine on, system switched on, avionics not destroyed

    Parameters:
        0: Aircraft <OBJECT>

    Return value:
        System is live <BOOL>

    Example:
        [_aircraft] call uksf_air_threatwarning_fnc_isLive
*/
params ["_aircraft"];

alive _aircraft
&& {isEngineOn _aircraft}
&& {!(_aircraft getVariable [QGVAR(off), false])}
&& {([_aircraft getHitPointDamage "HitAvionics"] param [0, 0]) < 1}
