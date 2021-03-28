#include "script_component.hpp"
#include "keybinds.sqf"

[QEGVAR(plane,base), "init", {_this call FUNC(initPlane)}, true, nil, true] call CBA_fnc_addClassEventHandler;
[QEGVAR(plane,base), "getin", {_this call FUNC(getIn)}] call CBA_fnc_addClassEventHandler;
[QEGVAR(plane,base), "getout", {_this call FUNC(getOut)}] call CBA_fnc_addClassEventHandler;

["ace_pylons_setPylonLoadOutEvent", {
    params ["_plane"];

    if (_plane isKindOf QEGVAR(plane,base)) then {
        [_plane] call FUNC(setMfdLoadout);
    };
}] call CBA_fnc_addEventHandler;
