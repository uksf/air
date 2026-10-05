#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        No-op stub that replaces A3TI's LTM (Laser Target Marker) functions via
        CfgFunctions override. The LTM binds "Toggle LTM" to bare L, defaults to
        a 0.3s blinking beam, renders for every unit in NVG, and its enable flag
        (A3TI_LTM_StartTime) can never be cleared on an uncontrolled UAV, so it
        sticks on aircraft/drones for a whole op. UKSF does not use LTM.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        Registered in CfgFunctions as A3TI_fnc_createLTM, A3TI_fnc_pfhLTM,
        A3TI_fnc_toggleLTM and A3TI_fnc_toggleLTMmode; not invoked directly
*/
