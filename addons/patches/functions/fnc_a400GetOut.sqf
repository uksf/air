#include "..\script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Place an A400M occupant clear of the airframe on get-out.
        In flight, cargo leaves aft of the open ramp, or out a para door when the ramp is shut.
        On the ground, a unit left on or under the fuselage is moved to the ramp or beside the crew door.

    Parameter(s):
        0: Plane <OBJECT>
        1: Role <STRING>
        2: Unit <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane, "cargo", _unit] call uksf_air_patches_fnc_a400GetOut
*/

params ["_plane", "_role", "_unit"];

if (!(_unit isEqualType objNull) || {!local _unit} || {!alive _unit} || {isNull _plane}) exitWith {};

private _height = (getPosATL _plane) select 2;
private _airborne = _height > 20 || {speed _plane > 40};
private _ramp = _plane animationSourcePhase "ramp_bottom";
private _slot = _plane getVariable [QGVAR(a400ExitSlot), 0];
_plane setVariable [QGVAR(a400ExitSlot), _slot + 1];
private _spread = ((_slot % 5) - 2) * 0.8;
private _model = [];

if (_airborne) then {
    _model = if (_ramp > 0.3) then { [_spread, -28, 1] } else { [-3.6 + (_spread * 0.2), -9.6, 1.2] };
} else {
    private _rel = _plane worldToModel (getPosATL _unit);
    private _head = (getPosWorld _unit) vectorAdd [0, 0, 1.6];
    private _overhead = lineIntersectsSurfaces [_head, _head vectorAdd [0, 0, 2.2], _unit, objNull, true, 2, "GEOM", "NONE"];
    private _under = _overhead findIf { (_x select 2) == _plane || {(_x select 3) == _plane} } >= 0;
    if ((_rel select 2) > 3 || {_under} || {_ramp < 0.3 && {_role == "cargo"}}) then {
        _model = if (_ramp > 0.3) then { [_spread, -18, 0.2] } else { [-5.5, 6.8, 0.05] };
    };
};

if (_model isEqualTo []) exitWith {};

_unit setPosWorld (_plane modelToWorldWorld _model);
_unit setVelocity (velocity _plane);
