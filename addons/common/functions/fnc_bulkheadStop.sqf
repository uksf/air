#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Keeps a walking unit on the A400 cabin floor. The flight deck and stairs are not a walkable surface,
        so a unit that steps past the forward floor edge is put back on the floor instead of falling through.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_common_fnc_bulkheadStop
*/
#define BULKHEAD_Y 9.2
#define FLOOR_Y 8.6
#define FLOOR_Z 2.0

params ["_plane"];

[{
    params ["_args", "_idPFH"];
    _args params ["_plane"];

    if (!alive _plane) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    {
        if (!local _x || {!alive _x} || {!isNull objectParent _x}) then {
            continue
        };
        private _m = _plane worldToModel (ASLToAGL (getPosASL _x));
        if ((_m select 1) > BULKHEAD_Y && {(_m select 1) < 16} && {abs (_m select 0) < 2.2} && {(_m select 2) > -1} && {(_m select 2) < 4}) then {
            _x setPosASL (_plane modelToWorldWorld [_m select 0, FLOOR_Y, FLOOR_Z]);
            _x setVelocity [0, 0, 0];
        };
    } forEach (_plane nearEntities ["CAManBase", 30]);
}, 0, [_plane]] call CBA_fnc_addPerFrameHandler;
