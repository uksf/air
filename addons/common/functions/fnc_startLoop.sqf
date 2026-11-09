#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts a per-frame handler for a vehicle, unless one already runs under the same key or the
        condition is false. Each frame the handler stops itself the first time the condition is false,
        and otherwise runs the code. An event such as Engine, Local or GetIn starts it again, so the
        handler runs only on machines and at times where the vehicle needs it.

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Key, the vehicle variable that holds the handler ID <STRING>
        2: Condition, called with [vehicle] <CODE>
        3: Code, called each frame with [vehicle, state] <CODE>
        4: State, an array that the code can change between frames <ARRAY> (default: [])

    Return Value:
        Nothing

    Example:
        [_plane, "uksf_air_typhoon_localLoop", {local (_this select 0)}, {}, []] call uksf_air_common_fnc_startLoop
*/

params ["_vehicle", "_key", "_condition", "_code", ["_state", []]];

if (!isNil {_vehicle getVariable _key} || {!([_vehicle] call _condition)}) exitWith {};

_vehicle setVariable [_key, [{
    params ["_args", "_idPFH"];
    _args params ["_vehicle", "_key", "_condition", "_code", "_state"];

    if !([_vehicle] call _condition) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        _vehicle setVariable [_key, nil];
    };

    [_vehicle, _state] call _code;
}, 0, [_vehicle, _key, _condition, _code, _state]] call CBA_fnc_addPerFrameHandler];
