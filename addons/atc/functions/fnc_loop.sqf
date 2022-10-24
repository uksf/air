#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        ATC Radar loop and markers

    Parameter(s):
        0: Player <OBJECT>
        1: State <BOOL>

    Return Value:
        None
*/

#define INTERVAL 2
#define MULTIPLIER_FEET 3.28084
#define MULTIPLIER_SPEED 1.852
#define RADIUS_2D 8000
#define RADIUS_AEW_2D 6000

params ["_player", "_state"];

if (!_state) exitWith {
    [GVAR(loopPFHID)] call CBA_fnc_removePerFrameHandler;
    GVAR(loopPFHID) = -1;
    {deleteMarkerLocal _x} forEach GVAR(markers);
    GVAR(markers) = [];
};

GVAR(loopPFHID) = [{
    params ["_args"];
    _args params ["_player", "_time"];

    if (CBA_missionTime > (_time + INTERVAL)) then {
        {deleteMarkerLocal _x} forEach GVAR(markers);
        GVAR(markers) = [];
        GVAR(aircraft) = GVAR(aircraft) select {alive _x};

        private _aircraftInRange = GVAR(aircraft) select {
            (isEngineOn _x || isCollisionLightOn _x)
            && {getConnectedUAV _player != _x}
            && {
                (_x distance2D _player) <= RADIUS_2D
                || {
                    private _aircraft = _x;                
                    [GVAR(aew), {_aircraft distance2D _x <= RADIUS_AEW_2D}] call UFUNC(common,arrayAny)
                }
            }
        };
        {
            private _markerName = format ["%1%2", CBA_missionTime, random 9999];
            private _speed = KMH_TO_KNOTS(speed _x);
            private _altitudeATL = METERS_TO_FEET((getPos _x)#2);
            private _altitudeASL = METERS_TO_FEET((getPosASL _x)#2);
            private _direction = round (getDir _x);
            private _formattedSpeed = if (_speed > 50) then {ROUND_TO_NEAREST(_speed,10)} else {round _speed};
            private _formattedAltitudeATL = if (_altitudeATL > 100) then {ROUND_TO_NEAREST(_altitudeATL,100)} else {round _altitudeATL};
            private _formattedAltitudeASL = if (_altitudeASL > 100) then {ROUND_TO_NEAREST(_altitudeASL,100)} else {round _altitudeASL};
            private _marker = createMarkerLocal [_markerName, _x];
            _marker setMarkerShapeLocal "ICON";
            _marker setMarkerTypeLocal ([_x] call FUNC(getMarker));
            _marker setMarkerTextLocal format ["%1kn %2rft %3ft %4°", _formattedSpeed, _formattedAltitudeATL, _formattedAltitudeASL, (round (_direction / 5)) * 5];
            _marker setMarkerDirLocal _direction;
            if (((side _player) getFriend (side _x)) < 0.6) then {
                _marker setMarkerColorLocal "ColorEAST";
            } else {
                _marker setMarkerColorLocal "ColorWEST";
            };
            GVAR(markers) pushBack _marker;
        } forEach _aircraftInRange;
        _args set [1, CBA_missionTime];
    } else {
        {
            private _step = CBA_missionTime - _time;
            _x setMarkerAlphaLocal (0.25 + (1 - _step));
        } forEach GVAR(markers);
    };
}, 0, [_player, INTERVAL]] call CBA_fnc_addPerFrameHandler;
