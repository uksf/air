#include "script_component.hpp"

[QGVAR(base), "init", {call FUNC(init)}, true, nil, true] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getin", {call FUNC(getIn)}] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getout", {call FUNC(getOut)}] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "killed", {call FUNC(getOut)}] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "incomingMissile", {call FUNC(incomingMissile)}] call CBA_fnc_addClassEventHandler;
