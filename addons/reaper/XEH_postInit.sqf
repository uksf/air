#include "script_component.hpp"

[QGVAR(raf), "init", {call FUNC(init)}, true, nil, true] call CBA_fnc_addClassEventHandler;

call FUNC(addDroneActions);
