#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Interrogates selected targets and active-radar contacts for local
        radar aircraft while their radar is on.

    Return Value:
        Nothing
*/
params ["", "_idPFH"];

GVAR(localRadarAircraft) = GVAR(localRadarAircraft) select {
    !isNull _x && {alive _x} && {local _x}
};

if (GVAR(localRadarAircraft) isEqualTo []) exitWith {
    [_idPFH] call CBA_fnc_removePerFrameHandler;
    if (GVAR(radarIffPFH) == _idPFH) then {
        GVAR(radarIffPFH) = -1;
    };
};

{
    private _aircraft = _x;
    if (isVehicleRadarOn _aircraft) then {
        private _targets = [];
        private _selectedTarget = assignedTarget _aircraft;
        if (!isNull _selectedTarget) then {
            _targets pushBack _selectedTarget;
        };

        {
            _x params ["_target", "", "", "_sensors"];
            if ("activeradar" in _sensors) then {
                _targets pushBackUnique _target;
            };
        } forEach getSensorTargets _aircraft;

        {
            [_aircraft, _x] call FUNC(interrogateTarget);
        } forEach _targets;
    };
} forEach GVAR(localRadarAircraft);
