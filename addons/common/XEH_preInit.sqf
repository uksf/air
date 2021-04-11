#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

["Air", "init", {call FUNC(attachTowbarActions)}, true, nil, true] call CBA_fnc_addClassEventHandler;
[QEGVAR(c130,base), "init", {
    params ["_plane"];
    
    _plane addAction ["Jump (Static Line)", QUOTE(call FUNC(staticLineJump)), nil, 5, true, true, "", QUOTE([ARR_2(_target,_this)] call FUNC(canStaticLineJump))];
}] call CBA_fnc_addClassEventHandler;

ADDON = true;
