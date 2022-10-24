#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Strike position, diving towards the target to enable munitions lock

    Parameter(s):
        0: Drone <OBJECT>

    Return Value:
        Nothing
*/
params ["_drone"];

// Handler to:
// - Calculate distances
// - Move drone away from target if needed (<1000m?)
// - Move drone towards target and nose down
// - Reset to observer mode once within 200m of target
