#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds actions to attach towbar to aircraft

    Parameter(s):
        0: Aircraft <OBJECT>

    Return Value:
        Nothing
*/
params ["_aircraft"];

private _towbarConfig = configOf _aircraft >> QGVAR(towbarOffset);
if !(isArray _towbarConfig) exitWith {};

_fnc_attachTowbar = {
    params ["_aircraft"];
    
    [ACE_player, "Acts_carFixingWheel", 1] call ace_common_fnc_doAnimation;
    [4, _aircraft, {
        params ["_aircraft"];
        
        private _towbarConfig = configOf _aircraft >> QGVAR(towbarOffset);
        private _towbarOffset = getArray _towbarConfig;
        private _towbar = createVehicle [QGVAR(towbar), [0,0,0], [], 0, "NONE"];
        _towbar attachTo [_aircraft, _towbarOffset];
        _aircraft setVariable [QGVAR(attachedTowbar), _towbar, true];
        _aircraft setVariable ["LESH_canBeTowed", 1, true];
        [ACE_player, "", 2] call ace_common_fnc_doAnimation;
    }, {
        hint "Failed to attach towbar";
        [ACE_player, "", 2] call ace_common_fnc_doAnimation;
    }, "Attaching towbar"] call ace_common_fnc_progressBar;
};

_fnc_detachTowbar = {
    params ["_aircraft"];
    
    [ACE_player, "Acts_carFixingWheel", 1] call ace_common_fnc_doAnimation;
    [4, _aircraft, {
        params ["_aircraft"];

        private _towbar = _aircraft getVariable [QGVAR(attachedTowbar), objNull];
        deleteVehicle _towbar;
        _aircraft setVariable [QGVAR(attachedTowbar), objNull, true];
        _aircraft setVariable ["LESH_canBeTowed", 0, true];
        [ACE_player, "", 2] call ace_common_fnc_doAnimation;
    }, {
        hint "Failed to detach towbar";
        [ACE_player, "", 2] call ace_common_fnc_doAnimation;
    }, "Detaching towbar"] call ace_common_fnc_progressBar;
};

private _towbarActionMemoryPoint = getText (configOf _aircraft >> QGVAR(towbarActionMemoryPoint));
_aircraft addAction ["Attach Towbar", _fnc_attachTowbar, nil, 1.5, true, true, "", QUOTE([ARR_2(_target,true)] call FUNC(canAttachTowbar)), 4, false, "", _towbarActionMemoryPoint];
_aircraft addAction ["Detach Towbar", _fnc_detachTowbar, nil, 1.5, true, true, "", QUOTE([ARR_2(_target,false)] call FUNC(canAttachTowbar)), 4, false, "", _towbarActionMemoryPoint];
