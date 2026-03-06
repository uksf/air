#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(handlerUav) = -1;

[QGVAR(raf), "init", {call FUNC(init)}, true] call CBA_fnc_addClassEventHandler;

[QGVAR(flyInHeightASL), {_this#0 flyInHeightASL _this#1}] call CBA_fnc_addEventHandler;
[QGVAR(forceSpeed), {_this#0 forceSpeed _this#1}] call CBA_fnc_addEventHandler;

["ACE_controlledUAV", {
    params ["_uav", "_seatAI", "_turret", "_position"];
    TRACE_4("ACE_controlledUAV EH",_uav,_seatAI,_turret,_position);

    if (!isNull _seatAI) then {
        GVAR(handlerUav) = [FUNC(handleDronePFH), 0, [_uav, _position, false, 1]] call CBA_fnc_addPerFrameHandler;
    } else {
        [GVAR(handlerUav)] call CBA_fnc_removePerFrameHandler;
        GVAR(handlerUav) = -1;
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
