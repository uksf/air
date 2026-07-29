#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Pure notch geometry for one inbound radar missile. Computes the beam
        (doppler-null) azimuth the pilot must fly toward, the box angular
        half-width (the closing-speed tolerance band), whether the aircraft is
        currently in the notch, the chosen beam side (with hysteresis vs the
        previous side), and the missile range in km.

        Closing speed matches ACE shouldFilterRadarHit: the aircraft velocity
        component along the missile->aircraft line of sight. In-notch when that
        is below the missile's minimumSpeedFilter.

    Parameter(s):
        0: Aircraft <OBJECT>
        1: Missile <OBJECT>
        2: Previous beam side (-1 / 0 / 1) <NUMBER>

    Return Value:
        [_beamAzimuth, _halfWidth, _inNotch, _side, _rangeKm] <ARRAY>
        Empty [] if geometry is not computable (e.g. near-stationary).

    Example:
        [_plane, _missile, 0] call uksf_air_common_fnc_computeNotchGeometry
*/
#define HYSTERESIS_MARGIN 15
#define HALFWIDTH_MAX 60

params ["_aircraft", "_missile", ["_prevSide", 0]];

private _aircraftPos = getPosASLVisual _aircraft;
private _missilePos = getPosASLVisual _missile;
private _velocity = velocity _aircraft;
private _speed = vectorMagnitude _velocity;
if (_speed < 1) exitWith { [] };

// Bearing aircraft -> missile (2D compass), and missile->aircraft LOS unit
private _delta = _missilePos vectorDiff _aircraftPos;
private _bearing = (_delta select 0) atan2 (_delta select 1);
private _losMissileToAircraft = _missilePos vectorFromTo _aircraftPos;

// Closing speed = aircraft velocity along LOS (ACE convention)
private _closingSpeed = abs (_velocity vectorDotProduct _losMissileToAircraft);

// Per-missile doppler threshold from ammo config
private _minimumSpeed = [configOf _missile >> "ace_missileguidance" >> "minimumSpeedFilter", "NUMBER", 30] call CBA_fnc_getConfigEntry;

private _inNotch = _closingSpeed <= _minimumSpeed;

// Solve the notch window exactly. Along a heading h, the closing speed is
// A * cos(h - bearing) + C, where A is the horizontal velocity component scaled by the
// horizontal part of the LOS and C is the vertical contribution. In-notch is
// |A * cos(h - bearing) + C| <= minimumSpeed, which gives an interval of cos values.
// The window is neither centred on the 90 deg beam nor symmetric once the missile is
// above or below the aircraft, so derive both the centre and the half-width from it.
private _horizSpeed = vectorMagnitude [_velocity select 0, _velocity select 1, 0];
private _losUnit = vectorNormalized _delta;
private _scale = _horizSpeed * (vectorMagnitude [_losUnit select 0, _losUnit select 1, 0]);
private _verticalTerm = (_velocity select 2) * (_losUnit select 2);

private _centreOffset = 90;
private _halfWidth = 0;
if (_scale < 0.1) then {
    // No horizontal component to trade: heading cannot change the closing speed
    if (abs _verticalTerm <= _minimumSpeed) then { _halfWidth = HALFWIDTH_MAX };
} else {
    private _cosHigh = ((_minimumSpeed - _verticalTerm) / _scale) max -1 min 1;
    private _cosLow = ((- _minimumSpeed - _verticalTerm) / _scale) max -1 min 1;
    private _angleNear = acos _cosHigh;
    private _angleFar = acos _cosLow;
    if (_angleFar < _angleNear) then {
        // Window closed: sit on the heading with the lowest achievable closing speed
        _centreOffset = acos (((- _verticalTerm) / _scale) max -1 min 1);
    } else {
        _centreOffset = (_angleNear + _angleFar) / 2;
        _halfWidth = ((_angleFar - _angleNear) / 2) min HALFWIDTH_MAX;
    };
};

// Two beam solutions; pick side nearest velocity heading, with hysteresis
private _velHeading = (_velocity select 0) atan2 (_velocity select 1);
private _beamPlus = _bearing + _centreOffset;   // side = 1
private _beamMinus = _bearing - _centreOffset;  // side = -1

// Angular distance helper (0..180)
private _angDiff = {
    params ["_a", "_b"];
    private _d = abs (_a - _b) % 360;
    _d min (360 - _d)
};

private _diffPlus = [_velHeading, _beamPlus] call _angDiff;
private _diffMinus = [_velHeading, _beamMinus] call _angDiff;

private _side = _prevSide;
if (_side == 0) then {
    // First acquisition: nearest beam
    _side = [1, -1] select (_diffMinus < _diffPlus);
} else {
    // Hysteresis: only flip if the other beam is closer by more than the margin
    private _chosenDiff = [_diffPlus, _diffMinus] select (_side < 0);
    private _otherDiff = [_diffMinus, _diffPlus] select (_side < 0);
    if (_otherDiff + HYSTERESIS_MARGIN < _chosenDiff) then {
        _side = - _side;
    };
};

private _beamAzimuth = _bearing + (_centreOffset * _side);
private _rangeKm = (_aircraftPos vectorDistance _missilePos) / 1000;

[_beamAzimuth, _halfWidth, _inNotch, _side, _rangeKm]
