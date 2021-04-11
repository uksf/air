#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs on get in

    Parameters:
        0: Heli <OBJECT>
        1: Position <STRING>
        2: Unit <OBJECT>
        3: Turret <ARRAY>

    Return value:
        Nothing
*/

GVAR(soundPlaying) = false;
[GVAR(soundHandler)] call CBA_fnc_removePerFrameHandler;
