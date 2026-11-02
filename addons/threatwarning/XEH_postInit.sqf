#include "script_component.hpp"

[FUNC(ownerTick), TICK_OWNER] call CBA_fnc_addPerFrameHandler;

if (!hasInterface) exitWith {};

call FUNC(addActions);
[FUNC(listenerTick), TICK_LISTENER] call CBA_fnc_addPerFrameHandler;
