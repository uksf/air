#include "script_component.hpp"

[QGVAR(base), "init", {call FUNC(initPlane)}, true, nil, true] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "gear", {call FUNC(gear)}] call CBA_fnc_addClassEventHandler;
