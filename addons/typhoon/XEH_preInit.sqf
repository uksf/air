#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(base), "init", {call FUNC(initPlane)}, true, nil, true] call CBA_fnc_addClassEventHandler;
private _nameplate = {[_this select 0, 37] call EFUNC(common,setNamePlate)};
[QGVAR(base), "init", _nameplate, true, [], true] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getin", _nameplate] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getout", _nameplate] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "seatswitched", _nameplate] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "local", _nameplate] call CBA_fnc_addClassEventHandler;

ADDON = true;
