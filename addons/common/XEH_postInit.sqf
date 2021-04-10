#include "script_component.hpp"
#include "keybinds.sqf"

["Air", "init", {call FUNC(attachTowbarActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;
