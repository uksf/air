#include "script_component.hpp"

player setVariable ["UK3CB_voice_enabled", 0, true];
[QGVAR(a400m_raf), "GetOut", { call FUNC(a400GetOut) }] call CBA_fnc_addClassEventHandler;
