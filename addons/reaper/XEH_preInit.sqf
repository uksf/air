#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(displayHandlerId) = -1;
GVAR(flyToAltitudeHandlerId) = -1;

[QGVAR(raf), "init", {call FUNC(init)}, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
