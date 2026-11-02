#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(aircraft) = [];
GVAR(guidance) = createHashMap;
GVAR(seat) = [objNull, [], false];
GVAR(active) = false;
GVAR(radarsSeen) = [];
GVAR(missilesCalled) = [];
GVAR(loop) = ["", -1, 0, false];
GVAR(voiceId) = -1;
GVAR(voiceEnd) = 0;

[
    QGVAR(volume),
    "SLIDER",
    ["Threat warning volume", "Volume of the aircraft missile and radar warning cues"],
    "UKSF Air",
    [0, 2, 1, 2],
    0
] call CBA_fnc_addSetting;

["Air", "init", {call FUNC(onInit)}, true, nil, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
