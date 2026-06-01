#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draw3D handler body for the F-35 notch helper. For each inbound radar
        (RDR) threat on the player vehicle's activeThreats hashmap, draws an
        always-on-top dot-matrix box (drawIcon3D filled circles, never occluded)
        at the beam/doppler-null azimuth plus a "<seeker> <range>km" label.
        Dots are world-positioned across the rectangle so the box stays
        world-vertical naturally (appears sideways at 90 deg roll) without any
        sprite-angle hack. Flashes amber while seeking, solid green when the
        velocity vector is in the notch. Only runs for uksf_air_f35_base
        aircraft.

    Parameter(s):
        None (reads vehicle player)

    Return Value:
        Nothing

    Example:
        call uksf_air_common_fnc_drawNotchHelper  // from a Draw3D mission EH
*/
#define BOX_DISTANCE 10000
#define BOX_HALF_ANGLE 13
#define DOT_TEXTURE QPATHTOEF(f35,mfd\circle.paa)
#define DOT_COLS 3
#define DOT_ROWS 9
#define DOT_SIZE 0.35
#define LABEL_MARGIN_DEG 3
#define BLINK_PERIOD 0.6

private _vehicle = vehicle player;
if !(_vehicle isKindOf QEGVAR(f35,base)) exitWith {};

private _threats = _vehicle getVariable QGVAR(activeThreats);
if (isNil "_threats" || {count _threats == 0}) exitWith {};

private _blinkOn = ((CBA_missionTime / (BLINK_PERIOD / 2)) mod 2) < 1;
private _aircraftPos = getPosASLVisual _vehicle;

{
    _y params ["_source", "", "_missile"];
    if (_source isNotEqualTo "RDR") then { continue };
    if (isNull _missile) then { continue };

    private _prevSide = _missile getVariable [QGVAR(notchSide), 0];
    private _geom = [_vehicle, _missile, _prevSide] call FUNC(computeNotchGeometry);
    if (_geom isEqualTo []) then { continue };
    _geom params ["_beam", "_halfWidth", "_inNotch", "_side", "_rangeKm"];
    _missile setVariable [QGVAR(notchSide), _side];

    // Box centre at compass = beam azimuth, elevation = velocity-vector pitch (tracks
    // the aircraft up/down through dynamic maneuvering, so the helper stays near the
    // pilot's velocity vector instead of stuck on the world horizon). World-up still
    // drives the strip's vertical axis so the box remains world-vertical (rotates with
    // roll). drawIcon3D dots = always-on-top HMD overlay.
    private _velocity = velocity _vehicle;
    private _speed = vectorMagnitude _velocity;
    private _pitchSin = (_velocity select 2) / (_speed max 1);
    private _pitchCos = sqrt (1 - _pitchSin * _pitchSin);
    private _beamDir = [sin _beam * _pitchCos, cos _beam * _pitchCos, _pitchSin];
    private _centre = _aircraftPos vectorAdd (_beamDir vectorMultiply BOX_DISTANCE);
    private _perp = [sin (_beam + 90), cos (_beam + 90), 0];
    private _halfHorizontal = (tan _halfWidth) * BOX_DISTANCE;
    private _halfVertical = (tan BOX_HALF_ANGLE) * BOX_DISTANCE;

    private _colour = if (_inNotch) then {
        [0, 1, 0, 1]
    } else {
        [1, 0.8, 0, [0.3, 1] select _blinkOn]
    };

    for "_col" from 0 to (DOT_COLS - 1) do {
        private _fx = -1 + (2 * _col / (DOT_COLS - 1));
        private _hOffset = _perp vectorMultiply (_halfHorizontal * _fx);
        for "_row" from 0 to (DOT_ROWS - 1) do {
            private _fy = -1 + (2 * _row / (DOT_ROWS - 1));
            private _dot = _centre vectorAdd _hOffset vectorAdd [0, 0, _halfVertical * _fy];
            drawIcon3D [DOT_TEXTURE, _colour, ASLToAGL _dot, DOT_SIZE, DOT_SIZE, 0, "", 0];
        };
    };

    private _token = [typeOf _missile] call FUNC(radarSeekerToken);
    private _label = format ["%1 %2km", _token, _rangeKm toFixed 1];
    private _labelGap = (tan LABEL_MARGIN_DEG) * BOX_DISTANCE;
    private _labelPos = ASLToAGL (_centre vectorDiff [0, 0, _halfVertical + _labelGap]);
    drawIcon3D ["", _colour, _labelPos, 0, 0, 0, _label, 0, 0.04, "RobotoCondensedBold", "center"];
} forEach _threats;
