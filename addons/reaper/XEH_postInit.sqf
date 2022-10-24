#include "script_component.hpp"

if (hasInterface) then {
    FUNC(setUavAction) = {inGameUISetEventHandler ["Action", QUOTE([_this#3] call FUNC(handleActionMenu))]};

    call FUNC(addDroneActions);
    call FUNC(setUavAction);
    ["ace_interaction_hideMouseHint", FUNC(setUavAction)] call CBA_fnc_addEventHandler;

    ["ACE_controlledUAV", {
        params ["_drone", "_seatAI", "_turret", "_position"];
        TRACE_4("ACE_controlledUAV EH",_drone,_seatAI,_turret,_position);

        if (!isNull _seatAI) then {
            GVAR(displayHandlerId) = [{
                params ["_args", "_idPFH"];
                _args params ["_drone", "_position"];

                private _currentDrone = ACE_controlledUAV#0;
                if (isNull _currentDrone || {_currentDrone != _uav}) exitWith {
                    WARNING_2("Current drone (%1) is not the same as the context drone (%2)",_currentDrone,_drone);
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                    GVAR(displayHandlerId) = -1;
                };

                if (_position isEqualTo "GUNNER" && {cameraView isEqualTo "GUNNER"}) then {
                    [_drone] call FUNC(updateDisplay);
                    [_drone] call FUNC(updateDisplay);
                };
            }, 0, [_drone, _position, false, 1]] call CBA_fnc_addPerFrameHandler;
        } else {
            [GVAR(displayHandlerId)] call CBA_fnc_removePerFrameHandler;
            GVAR(displayHandlerId) = -1;
        };
    }] call CBA_fnc_addEventHandler;

    ["visibleMap", {
        params ["_player", "_mapOn"];

        if (_mapOn) then {
            [_player] call FUNC(map);
        };
    }] call CBA_fnc_addPlayerEventHandler;

    FUNC(map) = {
        params ["_player"];

        private _drone = getConnectedUAV _player;
        if (isNull _drone) exitWith {systemChat "no drone";};

        private _display = findDisplay 12;
        private _control = _display displayCtrl 51;
        if (!isNil QGVAR(mapDrawEH)) then {_control ctrlRemoveEventHandler ["Draw", GVAR(mapDrawEH)]};
        GVAR(mapDrawEH) = [_control, "Draw", {
            params ["_control"];
            _thisArgs params ["_drone"];

            private _group = group _drone;
            private _currentWaypoint = currentWaypoint _group;
            private _mousePosition = _control ctrlMapScreenToWorld getMousePosition;
            private _dronePosition = getPosASL _drone;
            private _waypointPosition = getWPPos [_group, _currentWaypoint];

            private _scale = (ctrlMapScale _control) * 100;
            private _color = (configFile >> "CfgMarkerColors" >> "ColorWEST" >> "color") call bis_fnc_colorConfigToRGBA;

            private _speed = KMH_TO_KNOTS(speed _drone);
            private _altitudeATL = METERS_TO_FEET((getPos _drone)#2);
            private _altitudeASL = METERS_TO_FEET(_dronePosition#2);
            private _direction = round (getDir _drone);
            private _formattedSpeed = if (_speed > 50) then {ROUND_TO_NEAREST(_speed,10)} else {round _speed};
            private _formattedAltitudeATL = if (_altitudeATL > 100) then {ROUND_TO_NEAREST(_altitudeATL,100)} else {round _altitudeATL};
            private _formattedAltitudeASL = if (_altitudeASL > 100) then {ROUND_TO_NEAREST(_altitudeASL,100)} else {round _altitudeASL};
            private _text = format ["%1kn %2rft %3ft %4°", _formattedSpeed, _formattedAltitudeATL, _formattedAltitudeASL, (round (_direction / 5)) * 5];
            _control drawIcon [QPATHTOEF(atc,data\markers\icon_reaper_ca.paa), _color, _dronePosition, _scale * 0.24, _scale * 0.24, _direction, "", 0, 0.05, "TahomaB", "center"];
            _control drawIcon ["#(rgb,1,1,1)color(1,1,1,1)", _color, _dronePosition vectorAdd [0, _scale * -10, 0], 0, 0, 0, _text, 0, 0.05, "TahomaB", "center"];
            _control drawEllipse [_dronePosition, _scale * 7, _scale * 7, 0, _color, ""];

            if (_waypointPosition isNotEqualTo [0,0,0]) then {
                _control drawLine [_dronePosition, _waypointPosition, _color];

                private _icon = "\a3\ui_f_curator\data\cfgcurator\waypoint_ca.paa";
                if (waypointType [_group, _currentWaypoint] == "LOITER") then {
                    _icon = "\a3\ui_f_curator\data\cfgcurator\waypointcycle_ca.paa";

                    private _radius = _drone getVariable [QGVAR(loiterRadius), 2000];
                    private _text = format ["%1m", _radius];
                    _control drawEllipse [_waypointPosition, _radius, _radius, 0, _color, ""];
                    _control drawIcon ["#(rgb,1,1,1)color(1,1,1,1)", _color, _waypointPosition vectorAdd [0, _radius, 0], 0, 0, 0, _text, 0, 0.05, "TahomaB", "center"];
                };

                private _altitude = _drone getVariable [QGVAR(altitude), 5000];
                private _text = format ["%1ft", _altitude];
                _control drawIcon [_icon, _color, _waypointPosition, 24, 24, 0, _text, 0, 0.05, "TahomaB", "right"];
            };
        }, [_drone]] call CBA_fnc_addBISEventHandler;


        // - update zen
        // - udpate ace
    };
};









uksf_air_reaper_fnc_map = {
params ["_player"];

private _drone = getConnectedUAV _player;
if (isNull _drone) exitWith {systemChat "no drone";};

private _display = findDisplay 12;
private _control = _display displayCtrl 51;
if (!isNil "uksf_air_reaper_mapDrawEH") then {_control ctrlRemoveEventHandler ["Draw", uksf_air_reaper_mapDrawEH]};
uksf_air_reaper_mapDrawEH = [_control, "Draw", {
params ["_control"];
_thisArgs params ["_drone"];

private _group = group _drone;
private _currentWaypoint = currentWaypoint _group;
private _mousePosition = _control ctrlMapScreenToWorld getMousePosition;
private _dronePosition = getPosASL _drone;
private _waypointPosition = getWPPos [_group, _currentWaypoint];

private _scale = (ctrlMapScale _control) * 100;
private _color = (configFile >> "CfgMarkerColors" >> "ColorWEST" >> "color") call bis_fnc_colorConfigToRGBA;

private _speed = (speed _drone) / 1.852;
private _altitudeATL = ((getPos _drone)#2) * 3.28084;
private _altitudeASL = (_dronePosition#2) * 3.28084;
private _direction = round (getDir _drone);
private _formattedSpeed = if (_speed > 50) then {(round ((_speed) / 10)) * 10} else {round _speed};
private _formattedAltitudeATL = if (_altitudeATL > 100) then {(round ((_altitudeATL) / 100)) * 100} else {round _altitudeATL};
private _formattedAltitudeASL = if (_altitudeASL > 100) then {(round ((_altitudeASL) / 100)) * 100} else {round _altitudeASL};
private _text = format ["%1kn %2rft %3ft %4°", _formattedSpeed, _formattedAltitudeATL, _formattedAltitudeASL, (round (_direction / 5)) * 5];
_control drawIcon ["\u\uksf_air\addons\atc\data\markers\icon_reaper_ca.paa", _color, _dronePosition, _scale * 0.24, _scale * 0.24, _direction, "", 0, 0.05, "TahomaB", "center"];
_control drawIcon ["#(rgb,1,1,1)color(1,1,1,1)", _color, _dronePosition vectorAdd [0, _scale * -11, 0], 0, 0, 0, _text, 0, 0.05, "TahomaB", "center"];
_control drawEllipse [_dronePosition, _scale * 7, _scale * 7, 0, _color, ""];

if (_waypointPosition isNotEqualTo [0,0,0]) then {
_control drawLine [_dronePosition, _waypointPosition, _color];

private _icon = "\a3\ui_f_curator\data\cfgcurator\waypoint_ca.paa";
if (waypointType [_group, _currentWaypoint] == "LOITER") then {
_icon = "\a3\ui_f_curator\data\cfgcurator\waypointcycle_ca.paa";

private _radius = _drone getVariable ["uksf_air_reaper_loiterRadius", 2000];
private _text = format ["%1m", _radius];
_control drawEllipse [_waypointPosition, _radius, _radius, 0, _color, ""];
_control drawIcon ["#(rgb,1,1,1)color(1,1,1,1)", _color, _waypointPosition vectorAdd [0, _radius, 0], 0, 0, 0, _text, 0, 0.05, "TahomaB", "center"];
};

private _altitude = _drone getVariable ["uksf_air_reaper_altitude", 5000];
private _text = format ["%1ft", _altitude];
_control drawIcon [_icon, _color, _waypointPosition, 24, 24, 0, _text, 0, 0.05, "TahomaB", "right"];
};
}, [_drone]] call CBA_fnc_addBISEventHandler;
};
