#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Tracking loop. Draws BFT markers for friendly forces and aircraft radar contacts.
        Tier 1 (air crew): friendly BFT only.
        Tier 2 (AWACS terminal): friendly BFT + enemy aircraft radar + detailed flight info.

    Parameter(s):
        0: Player <OBJECT>
        1: State <BOOL>
        2: Tier <NUMBER> - 0 = off, 1 = air crew BFT, 2 = AWACS terminal

    Return Value:
        None

    Example:
        [_player, true, 1] call uksf_air_tracking_fnc_loop
*/

#define INTERVAL 1
#define MULTIPLIER_FEET 3.28084
#define MULTIPLIER_SPEED 1.852
#define RADIUS_2D 10000
#define RADIUS_AEW_2D 5000

params ["_player", "_state", "_tier"];

if (!_state) exitWith {
    if (GVAR(loopPFHID) != -1) then {
        [GVAR(loopPFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(loopPFHID) = -1;
    };
    {deleteMarkerLocal _x} forEach GVAR(markers);
    GVAR(markers) = [];
};

if (GVAR(loopPFHID) != -1) then {
    [GVAR(loopPFHID)] call CBA_fnc_removePerFrameHandler;
    GVAR(loopPFHID) = -1;
    {deleteMarkerLocal _x} forEach GVAR(markers);
    GVAR(markers) = [];
};

GVAR(loopPFHID) = [{
    params ["_args"];
    _args params ["_player", "_tier", "_time"];

    if (CBA_missionTime > (_time + INTERVAL)) then {
        {deleteMarkerLocal _x} forEach GVAR(markers);
        GVAR(markers) = [];

        private _playerSide = side _player;

        // --- BFT: Friendly groups (Tier 1+) ---
        private _drawnVehicles = [];
        {
            private _leader = leader _x;
            if (!alive _leader) then {continue};
            private _leaderVehicle = objectParent _leader;
            private _markerType = if (!isNull _leaderVehicle && {_leaderVehicle isKindOf "Air"}) then {
                [_leaderVehicle] call FUNC(getAircraftMarker)
            } else {
                [_x] call FUNC(getVehicleMarker)
            };
            private _markerName = format [QGVAR(group_%1), _forEachIndex];
            private _marker = createMarkerLocal [_markerName, getPos _leader];
            _marker setMarkerTypeLocal _markerType;
            _marker setMarkerColorLocal "ColorWEST";

            private _text = groupId _x;
            if (_tier isEqualTo 2 && {!isNull _leaderVehicle} && {_leaderVehicle isKindOf "Air"}) then {
                private _speed = (speed _leaderVehicle) / MULTIPLIER_SPEED;
                private _altitudeATL = (getPos _leaderVehicle) select 2 * MULTIPLIER_FEET;
                private _altitudeASL = (getPosASL _leaderVehicle) select 2 * MULTIPLIER_FEET;
                private _direction = round (getDir _leaderVehicle);
                private _formattedSpeed = if (_speed > 50) then {ROUND_TO_10(_speed)} else {round _speed};
                private _formattedAltitudeATL = if (_altitudeATL > 100) then {ROUND_TO_10(_altitudeATL)} else {round _altitudeATL};
                private _formattedAltitudeASL = if (_altitudeASL > 100) then {ROUND_TO_10(_altitudeASL)} else {round _altitudeASL};
                _text = format ["%1 %2kn %3ft %4ft %5°", _text, _formattedSpeed, _formattedAltitudeATL, _formattedAltitudeASL, (round (_direction / 5)) * 5];
                _marker setMarkerDirLocal _direction;
            };

            _marker setMarkerTextLocal _text;
            GVAR(markers) pushBack _markerName;

            if (!isNull _leaderVehicle) then {
                _drawnVehicles pushBack _leaderVehicle;
            };
        } forEach (allGroups select {side _x isEqualTo _playerSide});

        // --- BFT: Friendly crewed vehicles not already drawn via groups (Tier 1+) ---
        {
            if (_x in _drawnVehicles) then {continue};
            if (count crew _x isEqualTo 0) then {continue};
            if (_x isKindOf "StaticWeapon") then {continue};

            private _markerType = if (_x isKindOf "Air") then {
                [_x] call FUNC(getAircraftMarker)
            } else {
                private _tempGroup = group (crew _x select 0);
                [_tempGroup] call FUNC(getVehicleMarker)
            };
            private _markerName = format [QGVAR(vehicle_%1), _forEachIndex];
            private _marker = createMarkerLocal [_markerName, _x];
            _marker setMarkerTypeLocal _markerType;
            _marker setMarkerColorLocal "ColorWEST";
            _marker setMarkerTextLocal (groupId group (crew _x select 0));

            if (_tier isEqualTo 2 && {_x isKindOf "Air"}) then {
                private _speed = (speed _x) / MULTIPLIER_SPEED;
                private _altitudeATL = (getPos _x) select 2 * MULTIPLIER_FEET;
                private _altitudeASL = (getPosASL _x) select 2 * MULTIPLIER_FEET;
                private _direction = round (getDir _x);
                private _formattedSpeed = if (_speed > 50) then {ROUND_TO_10(_speed)} else {round _speed};
                private _formattedAltitudeATL = if (_altitudeATL > 100) then {ROUND_TO_10(_altitudeATL)} else {round _altitudeATL};
                private _formattedAltitudeASL = if (_altitudeASL > 100) then {ROUND_TO_10(_altitudeASL)} else {round _altitudeASL};
                _marker setMarkerTextLocal format ["%1 %2kn %3ft %4ft %5°", groupId group (crew _x select 0), _formattedSpeed, _formattedAltitudeATL, _formattedAltitudeASL, (round (_direction / 5)) * 5];
            };

            _marker setMarkerDirLocal (getDir _x);
            GVAR(markers) pushBack _markerName;
        } forEach (vehicles select {side _x isEqualTo _playerSide && {!(_x isKindOf "Static")}});

        // --- Radar: Enemy aircraft (Tier 2 only) ---
        if (_tier isEqualTo 2) then {
            GVAR(aircraft) = GVAR(aircraft) select {!isNull _x && {alive _x}};

            private _enemyAircraft = GVAR(aircraft) select {
                (isEngineOn _x || {isCollisionLightOn _x})
                && {((side _player) getFriend (side _x)) < 0.6}
                && {(_x distance2D _player) <= RADIUS_2D || {
                    private _aircraft = _x;
                    GVAR(aew) findIf {_aircraft distance2D _x <= RADIUS_AEW_2D} != -1
                }}
            };

            {
                private _speed = (speed _x) / MULTIPLIER_SPEED;
                private _altitudeATL = (getPos _x) select 2 * MULTIPLIER_FEET;
                private _altitudeASL = (getPosASL _x) select 2 * MULTIPLIER_FEET;
                private _direction = round (getDir _x);
                private _formattedSpeed = if (_speed > 50) then {ROUND_TO_10(_speed)} else {round _speed};
                private _formattedAltitudeATL = if (_altitudeATL > 100) then {ROUND_TO_10(_altitudeATL)} else {round _altitudeATL};
                private _formattedAltitudeASL = if (_altitudeASL > 100) then {ROUND_TO_10(_altitudeASL)} else {round _altitudeASL};
                private _markerName = format [QGVAR(enemy_%1), _forEachIndex];
                private _marker = createMarkerLocal [_markerName, _x];
                _marker setMarkerShapeLocal "ICON";
                _marker setMarkerTypeLocal ([_x] call FUNC(getAircraftMarker));
                _marker setMarkerTextLocal format ["%1kn %2ft %3ft %4°", _formattedSpeed, _formattedAltitudeATL, _formattedAltitudeASL, (round (_direction / 5)) * 5];
                _marker setMarkerDirLocal _direction;
                _marker setMarkerColorLocal "ColorEAST";
                GVAR(markers) pushBack _markerName;
            } forEach _enemyAircraft;
        };

        _args set [2, CBA_missionTime];
    } else {
        {
            private _step = CBA_missionTime - _time;
            _x setMarkerAlphaLocal (0.25 + (1 - _step));
        } forEach GVAR(markers);
    };
}, 0, [_player, _tier, INTERVAL]] call CBA_fnc_addPerFrameHandler;
