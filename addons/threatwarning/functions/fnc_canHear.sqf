#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether a unit hears the aircraft threat warnings: always in a flight seat, otherwise only while connected to the aircraft's crew intercom, whatever the seat.

    Parameters:
        0: Aircraft <OBJECT>
        1: Unit <OBJECT>

    Return value:
        Unit hears the warnings <BOOL>

    Example:
        [_aircraft, player] call uksf_air_threatwarning_fnc_canHear
*/
params ["_aircraft", "_unit"];

if ([_aircraft, _unit] call FUNC(isFlightSeat)) exitWith {true};

!isNil "acre_sys_intercom_fnc_isInIntercom" && {[_aircraft, _unit, 0] call acre_sys_intercom_fnc_isInIntercom}
