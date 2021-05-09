#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(loopPFHID) = -1;
GVAR(aircraft) = [];
GVAR(aew) = [];

["Air", "init", {
    params ["_aircraft"];

    GVAR(aircraft) pushBack _aircraft;

    if (_aircraft isKindOf QEGVAR(reaper,raf)) then {
        GVAR(aew) pushBack _aircraft;
    };
}, true, nil, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
