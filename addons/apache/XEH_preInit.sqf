#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(processAudio), {
    GVAR(audioQueue) pushBack _this;
    call FUNC(audio);
}] call CBA_fnc_addEventHandler;

GVAR(trackedMissiles) = [];
GVAR(audioQueue) = [];
GVAR(audioProcessing) = false;
GVAR(damageHandlerPFHID) = -1;

ADDON = true;
