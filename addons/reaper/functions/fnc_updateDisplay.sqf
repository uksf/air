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

private _display = ;

private _targetPosition = if !(isNull cursorTarget) then {
    getPosATL (cursorTarget);
} else {
    screenToWorld [0.5, 0.5];
};
private _targetPositionASL = ATLToASL _targetPosition;

private _uavPositionASL = getPosASL _uav;
private _uavPosition = getPosATL _uav;

private _hat = round ((_uavPositionASL#2) - (_targetPositionASL#2));
private _hatString = str _hat;
if (_hat >= 1e3) then {
    _hatLastThree = _hatString select [(count _hatString)-3,3];
    _hatFirstStuff = _hatString select [0,(count _hatString)-3];
    if (count _hatFirstStuff > 0) then {
        _hatString = _hatFirstStuff + "," + _hatLastThree;
    };
};
(_display displayCtrl OWN_ALT) ctrlSetText _hatString;

private _mgrs = [worldName] call ace_common_fnc_getMGRSdata;
_mgrs params ["_gzd", "_g100km"];
private _grid = [_uavPosition] call ace_common_fnc_getMapGridFromPos;
private _grid params ["_easting", "_northing"];
(_display displayCtrl OWN_MGRS_1) ctrlSetText _gzd;
(_display displayCtrl OWN_MGRS_2) ctrlSetText _g100km;
(_display displayCtrl OWN_GRID_1) ctrlSetText _easting;
(_display displayCtrl OWN_GRID_2) ctrlSetText _northing;

(_display displayCtrl OWN_BEARING) ctrlSetText str (round (getDir _uav) mod 360);

private _visionMode = call A3TI_fnc_getA3TIVision;
(_display displayCtrl VISION_MODE) ctrlSetText _visionMode;

([] call A3TI_fnc_getA3TIBrightnessContrast) params ["_brightness", "_contrast"];
private _brightnessAndContrast = format ["%1/%2", _brightness * 350, round (_contrast * 450)];
(_display displayCtrl BRIGHT_CONT) ctrlSetText _brightnessAndContrast;

_temps = call USAF_MQ9_fnc_getTemperature;
(_display displayCtrl TEMP) ctrlSetText format ["%1C", round(_temps select 1)];

//laser code
_laserCode = _uav getVariable ["ace_laser_code",1111];
(_display displayCtrl LASER_CODE) ctrlSetText str(_laserCode);

//laser firing
_laserFire = ctrlShown (_display displayCtrl LASER_FIRE);
_laserBoxText = "";
_laserText = "";
_blinkTime = 0.3;
if (_laserFire) then {
    if (time < (uiNamespace getVariable ["USAF_MQ9_UI_LSR_NEXT_BLINK", 0])) then {
        _laserBoxText = getText(configfile >> "RscInGameUI" >> "Rsc_USAF_MQ9_Turret_UI" >> "CA_IGUI_elements_group" >> "controls" >> LASER_BOX_CLASSNAME >> "text");
        _laserText = getText(configfile >> "RscInGameUI" >> "Rsc_USAF_MQ9_Turret_UI" >> "CA_IGUI_elements_group" >> "controls" >> LASER_TEXT_CLASSNAME >> "text");
    } else {
        if (time > ((uiNamespace getVariable ["USAF_MQ9_UI_LSR_NEXT_BLINK", 0]) + _blinkTime)) then {
            //systemChat "TIME EXTENTION!!";
            uiNamespace setVariable ["USAF_MQ9_UI_LSR_NEXT_BLINK",time + _blinkTime];
        };
    };
} else {
    uiNamespace setVariable ["USAF_MQ9_UI_LSR_NEXT_BLINK",nil];
};
(_display displayCtrl LASER_BOX) ctrlSetText _laserBoxText;
(_display displayCtrl LASER_TEXT) ctrlSetText _laserText;

//for some reason ctrlShow not work :(
//(_display displayCtrl LASER_BOX) ctrlShow _laserFire;
//(_display displayCtrl LASER_BOX) ctrlCommit 0;

//turret movement stuff
([_uav,[0]] call usaf_mq9_fnc_getTurretAzEl) params ["_azimuth", "_elevation"];
(_display displayCtrl TURRET_EZ_TXT) ctrlSetText str(round(_elevation));
(_display displayCtrl TURRET_AZ_TXT) ctrlSetText str(round(_azimuth));

_turretAZcarrotCtrlPos = ctrlPosition (_display displayCtrl TURRET_AZ_CARROT);
_turretAZtextCtrlPos = ctrlPosition (_display displayCtrl TURRET_AZ_TXT);
_turretEZcarrotCtrlPos = ctrlPosition (_display displayCtrl TURRET_EZ_CARROT);
_turretEZtextCtrlPos = ctrlPosition (_display displayCtrl TURRET_EZ_TXT);

(_display displayCtrl TURRET_AZ_CARROT) ctrlSetPosition [TURRET_AZ_BEG + (((_azimuth+180)/360)*TURRET_AZ_DIS),_turretAZcarrotCtrlPos select 1, _turretAZcarrotCtrlPos select 2, _turretAZcarrotCtrlPos select 3];
(_display displayCtrl TURRET_AZ_CARROT) ctrlCommit 0;
(_display displayCtrl TURRET_AZ_TXT) ctrlSetPosition [TURRET_AZ_BEG + TURRET_AZ_NUM_OFFSET + (((_azimuth+180)/360)*TURRET_AZ_DIS),_turretAZtextCtrlPos select 1, _turretAZtextCtrlPos select 2, _turretAZtextCtrlPos select 3];
(_display displayCtrl TURRET_AZ_TXT) ctrlCommit 0;

//-60 deg = 0
//-15 deg = 0.25
//30 deg = 0.5
//52.5 deg = 0.625
//75 deg = 0.75
//97.5 deg = 0.875
//120 deg = 1
//formula y = (-1/180)*x + (1/3)
_elevPos = TURRET_EZ_BEG + (((-1/180)*_elevation + (1/3))*TURRET_EZ_DIS);

(_display displayCtrl TURRET_EZ_CARROT) ctrlSetPosition [_turretEZcarrotCtrlPos select 0, _elevPos, _turretEZcarrotCtrlPos select 2, _turretEZcarrotCtrlPos select 3];
(_display displayCtrl TURRET_EZ_CARROT) ctrlCommit 0;
(_display displayCtrl TURRET_EZ_TXT) ctrlSetPosition [_turretEZtextCtrlPos select 0, _elevPos, _turretEZtextCtrlPos select 2, _turretEZtextCtrlPos select 3];
(_display displayCtrl TURRET_EZ_TXT) ctrlCommit 0;
//(_azimuth+180)/360 //between 0-1

//target data

//l to r
_lSide = screenToWorld [0,0.5];
_rSide = screenToWorld [1, 0.5];
_lToRDist = _lSide distance _rSide;

(_display displayCtrl VIEW_L_R) ctrlSetText format["%1  M+",round(_lToRDist)];

//t to b
_bSide = screenToWorld [0.5, 0];
_tSide = screenToWorld [0.5, 1];
_btoTDist = _bSide distance _tSide;

(_display displayCtrl VIEW_T_B) ctrlSetText format["%1  M+",round(_btoTDist)];

//ground rng
_grndRng = _uavPosition distance2D _targetPosition;
/*_fix = 2;
if (_grndRng >= 1e4) then {
    _fix = 1;
};
if (_grndRng >= 1e5) then {
    _fix = 0;
};*/
(_display displayCtrl TGT_DIST_2D) ctrlSetText format ["%1M+", round(_grndRng)];

//slant rng
_slantRng = _uavPosition distance _targetPosition;
/*_fix = 2;
if (_slantRng >= 1e4) then {
    _fix = 1;
};
if (_slantRng >= 1e5) then {
    _fix = 0;
};*/
(_display displayCtrl TGT_DIST_P) ctrlSetText format ["%1M+", round(_slantRng)];

//tgt bearing
_mq9Dir = getDir _uav;

_adjacent = ((_targetPosition select 0) - (_uavPosition select 0));
_opposite = ((_targetPosition select 1) - (_uavPosition select 1));
_hypotenuse = sqrt((_adjacent^2) + (_opposite^2));
//_opposite is X (cos), _adjacent is Y(sin)
private _tgtBearing = "---";
if !((isNil "_hypotenuse") || (_hypotenuse isEqualTo 0)) then {
    _tgtBearing = round(acos(_opposite/_hypotenuse));

    //trying to make sure that it displays 0 to 360 rather than -180 to 180
    //positive region
    /*if (((_opposite > 0) && (_adjacent > 0)) || ((_opposite < 0) && (_adjacent > 0)))then {

    };
    if ((_opposite < 0) && (_adjacent > 0)) then {

    };*/
    //for 180 degrees to 360 degrees *doesn't take aircraft direction into account*
    if (((_opposite < 0) && (_adjacent < 0)) || ((_opposite > 0) && (_adjacent < 0))) then {
        _tgtBearing = 180+(180 - _tgtBearing);
    };
    /*if ((_opposite > 0) && (_adjacent < 0)) then {
        _tgtBearing = 180+(180 - _tgtBearing);
    };*/
    //_tgtBearing = round((getDir _uav)-([_uavPosition, _targetPosition] call BIS_fnc_dirTo));


    //add aircraft heading to bearing now
    _tgtBearing = (_tgtBearing - round(_mq9Dir));
    if (_tgtBearing < 0) then {
        _tgtBearing = (_tgtBearing + 360);
    };

    //ensure within 360
    _tgtBearing = _tgtBearing mod 360;
} else {
    _tgtBearing = "---"
};

(_display displayCtrl TGT_BEARING) ctrlSetText format ["%1  M",_tgtBearing];

//tgt elev
_tgtElev = (_targetPositionASL select 2);
/*_fix = 2;
if (_tgtElev >= 1e4) then {
    _fix = 1;
};
if (_tgtElev >= 1e5) then {
    _fix = 0;
};*/
(_display displayCtrl TGT_ELEV) ctrlSetText format ["%1 M+", round(_tgtElev)];

//tgt mgrs & grid
_tgtGrid = [_targetPosition] call ace_common_fnc_getMapGridFromPos;
_tgtGrid params ["_tgtEasting", "_tgtNorthing"];
(_display displayCtrl TGT_MGRS_1) ctrlSetText _gzd;
(_display displayCtrl TGT_MGRS_2) ctrlSetText _g100km;
(_display displayCtrl TGT_GRID_1) ctrlSetText (_tgtEasting) + "+";
(_display displayCtrl TGT_GRID_2) ctrlSetText (_tgtNorthing) + "+";


//compass N
private _compassXPos = (0.5*safeZoneW)+(sin((_azimuth+180)+_mq9Dir)*(0.2 * safeZoneW));
private _compassYPos = (0.5*safeZoneH)+(cos((_azimuth+180)+_mq9Dir)*(0.2 * safeZoneH));

(_display displayCtrl COMPASS_N_TXT) ctrlSetPosition [_compassXPos,_compassYPos];
(_display displayCtrl COMPASS_N_TXT) ctrlCommit 0;
