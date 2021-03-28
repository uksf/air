/*
    Author:
        Tim Beswick

    Description:
        Get out plane

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

[GVAR(pilotGroupPFH)] call CBA_fnc_removePerFrameHandler;
if (!GVAR(inGroup)) then {
    [ACE_player] joinSilent GVAR(group);
    GVAR(inGroup) = true;
};
