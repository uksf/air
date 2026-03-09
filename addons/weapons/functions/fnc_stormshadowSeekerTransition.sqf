#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Transition condition for cruise missile seeker switch: GPS -> SALH.
        Only transitions during terminal phase if SALH can find an active laser spot
        matching the configured laser code. If no laser is found, the missile stays
        on GPS guidance all the way to the target.

    Parameter(s):
        0: Guidance Arg Array <ARRAY>
        1: Timestep <NUMBER>

    Return Value:
        Should transition <BOOL>
*/

params ["_args"];
_args params ["_firedEH", "_launchParams", "", "_seekerParams", "_stateParams"];
_firedEH params ["","","","","","","_projectile"];
_launchParams params ["","","","","","_laserInfo"];
_seekerParams params ["_seekerAngle", "", "_seekerMaxRange"];
_stateParams params ["", "", "_attackProfileStateParams"];
_laserInfo params ["_laserCode", "_wavelengthMin", "_wavelengthMax"];

// STAGE_TERMINAL = 6
private _stage = _attackProfileStateParams param [0, 0];

// Only consider transition during terminal phase
if (_stage < 6) exitWith { false };

// Check if SALH can find an active laser spot with the configured code
private _laserResult = [getPosASL _projectile, vectorDir _projectile, _seekerAngle, _seekerMaxRange, [_wavelengthMin, _wavelengthMax], _laserCode, _projectile] call EFUNC(laser,seekerFindLaserSpot);
private _foundTargetPosition = _laserResult select 0;

!isNil "_foundTargetPosition"
