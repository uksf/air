#include "script_component.hpp"

player setVariable ["UK3CB_voice_enabled", 0, true];
[QGVAR(a400m_raf), "GetOut", { call FUNC(a400GetOut) }] call CBA_fnc_addClassEventHandler;
{
    [_x, "init", { [_this select 0] call EFUNC(common,parkHold) }, true, [], true] call CBA_fnc_addClassEventHandler;
} forEach [QGVAR(a400m_raf), QEGVAR(typhoon,base)];
