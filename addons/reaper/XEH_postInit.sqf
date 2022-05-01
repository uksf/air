#include "script_component.hpp"

call FUNC(addDroneActions);

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
