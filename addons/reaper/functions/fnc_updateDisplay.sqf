#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates drone display

    Parameter(s):
        0: UAV <OBJECT>

    Return Value:
        Nothing
*/

params ["_uav"];

private _display = (uiNamespace getVariable ["RscOptics_UAV_reaper_gunner", displayNull]);

private _targetPosition = [getPosATL (cursorTarget), screenToWorld [0.5, 0.5]] select (isNull cursorTarget);
private _targetPositionASL = ATLToASL _targetPosition;
private _uavPositionASL = getPosASL _uav;
private _uavPosition = getPosATL _uav;
private _uavDirection = getDir _uav;

private _altitude = round (METERS_TO_FEET(_uavPositionASL#2));
(_display displayCtrl OWN_ALT) ctrlSetText (str _altitude);

([worldName] call ace_common_fnc_getMGRSdata) params ["_gzd", "_g100km"];
([_uavPosition] call ace_common_fnc_getMapGridFromPos) params ["_easting", "_northing"];
(_display displayCtrl OWN_MGRS_1) ctrlSetText _gzd;
(_display displayCtrl OWN_MGRS_2) ctrlSetText _g100km;
(_display displayCtrl OWN_GRID_1) ctrlSetText (format ["%1", _easting]);
(_display displayCtrl OWN_GRID_2) ctrlSetText (format ["%1", _northing]);

(_display displayCtrl OWN_BEARING) ctrlSetText (str round _uavDirection);

private _visionMode = call A3TI_fnc_getA3TIVision;
if (isNil "_visionMode") then {
    _visionMode = "DTV";
};
(_display displayCtrl VISION_MODE) ctrlSetText _visionMode;

([] call A3TI_fnc_getA3TIBrightnessContrast) params ["_brightness", "_contrast"];
if (isNil "_contrast") then {
    (_display displayCtrl BRIGHT_CONT) ctrlSetText "---/---";
} else {    
    (_display displayCtrl BRIGHT_CONT) ctrlSetText (format ["%1/%2", _brightness * 350, round (_contrast * 450)]);
};

(_display displayCtrl TEMP) ctrlSetText (format ["%1C", ace_weather_currentTemperature]);

private _laserCode = _uav getVariable ["ace_laser_code", 1111];
(_display displayCtrl LASER_CODE) ctrlSetText (str _laserCode);

private _laserFire = ctrlShown (_display displayCtrl LASER_FIRE);
private _laserBoxText = ["", QPATHTOF(data\square_CA.paa)] select _laserFire;
private _laserText = ["", "LRD LASE DES"] select _laserFire;
(_display displayCtrl LASER_BOX) ctrlSetText _laserBoxText;
(_display displayCtrl LASER_TEXT) ctrlSetText _laserText;

private _turretConfig = [_uav, [0]] call BIS_fnc_turretConfig;
private _turretElevAnimation = getText (_turretConfig >> "animationSourceGun");
private _turretAzAnimation = getText (_turretConfig >> "animationSourceBody");
private _elevation = deg (_uav animationSourcePhase _turretElevAnimation);
private _azimuth = deg (_uav animationSourcePhase _turretAzAnimation);
(_display displayCtrl TURRET_EZ_TXT) ctrlSetText str (round _elevation);
(_display displayCtrl TURRET_AZ_TXT) ctrlSetText str (round _azimuth);

private _turretAZcaretCtrlPos = ctrlPosition (_display displayCtrl TURRET_AZ_CARET);
private _turretAZtextCtrlPos = ctrlPosition (_display displayCtrl TURRET_AZ_TXT);
private _turretEZcaretCtrlPos = ctrlPosition (_display displayCtrl TURRET_EZ_CARET);
private _turretEZtextCtrlPos = ctrlPosition (_display displayCtrl TURRET_EZ_TXT);
(_display displayCtrl TURRET_AZ_CARET) ctrlSetPosition [TURRET_AZ_BEG + (((_azimuth + 180) / 360) * TURRET_AZ_DIS), _turretAZcaretCtrlPos#1, _turretAZcaretCtrlPos#2, _turretAZcaretCtrlPos#3];
(_display displayCtrl TURRET_AZ_CARET) ctrlCommit 0;
(_display displayCtrl TURRET_AZ_TXT) ctrlSetPosition [TURRET_AZ_BEG + TURRET_AZ_NUM_OFFSET + (((_azimuth + 180) / 360) * TURRET_AZ_DIS), _turretAZtextCtrlPos#1, _turretAZtextCtrlPos#2, _turretAZtextCtrlPos#3];
(_display displayCtrl TURRET_AZ_TXT) ctrlCommit 0;

private _turretElevationPosition = TURRET_EZ_BEG + (((-1 / 180) * _elevation + (1 / 3)) * TURRET_EZ_DIS);
(_display displayCtrl TURRET_EZ_CARET) ctrlSetPosition [_turretEZcaretCtrlPos#0, _turretElevationPosition, _turretEZcaretCtrlPos#2, _turretEZcaretCtrlPos#3];
(_display displayCtrl TURRET_EZ_CARET) ctrlCommit 0;
(_display displayCtrl TURRET_EZ_TXT) ctrlSetPosition [_turretEZtextCtrlPos#0, _turretElevationPosition, _turretEZtextCtrlPos#2, _turretEZtextCtrlPos#3];
(_display displayCtrl TURRET_EZ_TXT) ctrlCommit 0;

private _screenLeft = screenToWorld [0,0.5];
private _screenRight = screenToWorld [1, 0.5];
private _screenTop = screenToWorld [0.5, 1];
private _screenBottom = screenToWorld [0.5, 0];
private _screenLeftToRightDistance = _screenLeft distance _screenRight;
private _screenTopToBottomDistance = _screenBottom distance _screenTop;
(_display displayCtrl VIEW_L_R) ctrlSetText format["%1 M+", round _screenLeftToRightDistance];
(_display displayCtrl VIEW_T_B) ctrlSetText format ["%1 M+", round _screenTopToBottomDistance];

private _range2d = _uavPosition distance2D _targetPosition;
private _rangeSlant = _uavPosition distance _targetPosition;
(_display displayCtrl TGT_DIST_2D) ctrlSetText format ["%1 M+", round _range2d];
(_display displayCtrl TGT_DIST_P) ctrlSetText format ["%1 M+", round _rangeSlant];

private _adjacent = (_targetPosition#0) - (_uavPosition#0);
private _opposite = (_targetPosition#1) - (_uavPosition#1);
private _hypotenuse = sqrt ((_adjacent ^ 2) + (_opposite ^ 2));
private _targetBearing = round (acos (_opposite / _hypotenuse));
if (((_opposite < 0) && (_adjacent < 0)) || ((_opposite > 0) && (_adjacent < 0))) then {
    _targetBearing = 180 + (180 - _targetBearing);
};
_targetBearing = (_targetBearing - round _uavDirection);
if (_targetBearing < 0) then {
    _targetBearing = _targetBearing + 360;
};

(_display displayCtrl TGT_BEARING) ctrlSetText format ["%1  M+", _targetBearing mod 360];

private _targetElevation = (_targetPositionASL#2);
(_display displayCtrl TGT_ELEV) ctrlSetText format ["%1 FT+", round (METERS_TO_FEET(_targetElevation))];

([_targetPosition] call ace_common_fnc_getMapGridFromPos) params ["_targetEasting", "_targetNorthing"];
(_display displayCtrl TGT_MGRS_1) ctrlSetText _gzd;
(_display displayCtrl TGT_MGRS_2) ctrlSetText _g100km;
(_display displayCtrl TGT_GRID_1) ctrlSetText (format ["%1 M+", _targetEasting]);
(_display displayCtrl TGT_GRID_2) ctrlSetText (format ["%1 M+", _targetNorthing]);

if (_uav getVariable [QGVAR(compassState), false]) then {
    private _zoom = (call CBA_fnc_getFov) select 1;
    private _factor = 500 / _zoom;
    private _halfFactor = _factor / 2;
    private _center = screenToWorld [0.5,0.5];
    {
        _x params ["_letter", "_color", "_offset1", "_offset2"];
        drawIcon3D ["", _color, _center vectorAdd _offset1, 0, 0, 0, _letter, 2, 0.05, "PuristaMedium"];
        drawIcon3D ["", _color, _center vectorAdd _offset2, 0, 0, 0, ".", 2, 0.05, "PuristaMedium"];
    } forEach [
        ["N", [1,1,1,1], [0,_factor,0], [0,_halfFactor,0]],
        ["S", [1,1,1,0.7], [0,-_factor,0], [0,-_halfFactor,0]],
        ["E", [1,1,1,0.7], [_factor,0,0], [_halfFactor,0,0]],
        ["W", [1,1,1,0.7], [-_factor,0,0], [-_halfFactor,0,0]]
    ];
};
