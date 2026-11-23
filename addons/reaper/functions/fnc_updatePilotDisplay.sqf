#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame handler that shows drone speed in knots and altitude above sea level in feet on the
        pilot display. Removes itself when the display closes.

    Parameter(s):
        0: Args <ARRAY>
            0: Pilot display <DISPLAY>
        1: PFH ID <SCALAR>

    Return Value:
        Nothing

    Example:
        [uksf_air_reaper_fnc_updatePilotDisplay, 0, [_display]] call CBA_fnc_addPerFrameHandler
*/
params ["_args", "_idPFH"];
_args params ["_display"];

if (isNull _display) exitWith {
    [_idPFH] call CBA_fnc_removePerFrameHandler;
};

private _uav = cameraOn;
private _hasTelemetry = alive _uav && {unitIsUAV _uav};
private _speed = ["", str round (KMH_TO_KNOTS(speed _uav))] select _hasTelemetry;
private _altitude = ["", str round (METERS_TO_FEET((getPosASL _uav)#2))] select _hasTelemetry;
(_display displayCtrl PILOT_OPTICS_SPEED) ctrlSetText _speed;
(_display displayCtrl PILOT_OPTICS_ALT) ctrlSetText _altitude;
