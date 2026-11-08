#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(inGroup) = true;

[QGVAR(base), "init", {call FUNC(initPlane)}, true, nil, true] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getin", {call FUNC(getIn)}] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getout", {call FUNC(getOut)}] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "init", {[_this select 0, 1] call EFUNC(common,setNamePlate)}, true, [], true] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "seatswitched", {[_this select 0, 1] call EFUNC(common,setNamePlate)}] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "local", {[_this select 0, 1] call EFUNC(common,setNamePlate)}] call CBA_fnc_addClassEventHandler;

["ace_pylons_setPylonLoadOutEvent", {
    params ["_plane"];

    if (_plane isKindOf QGVAR(base)) then {
        [_plane] call FUNC(setMfdLoadout);
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
