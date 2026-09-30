#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(base), "init", {call FUNC(initPlane)}, true, nil, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
