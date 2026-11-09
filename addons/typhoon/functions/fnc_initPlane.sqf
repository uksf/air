#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the per-frame handler for a Typhoon. Hides the reheat flames until light-up, then runs afterburner, fuel burn and nozzles where the plane is local,
        landing lights off while the gear is up, because they sit in the main gear doors,
        burning fuel at real EJ200 rates: two engines burn about 9,500 kg/h at full dry power and 31,000 kg/h
        at full reheat (Rolls-Royce and EuroJet figures, jet fuel at 0.8 kg/L),
        real mass from the 11,000 kg basic empty mass (EuroJet) plus fuel, stores and crew,
        a park hold at zero throttle, because the nose-up stance rolls an unbraked jet,
        the reheat light-up kick and APU smoke on every client, and HMD visibility for the local pilot.

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing

    Example:
        [_plane] call uksf_air_typhoon_fnc_initPlane
*/
#define NOZZLE_INTERVAL 0.5
#define FUEL_INTERVAL 1
#define IDLE_LITRES_PER_HOUR 600
#define MAX_DRY_LITRES_PER_HOUR 11900
#define MAX_REHEAT_LITRES_PER_HOUR 38800
#define EMPTY_MASS 11000
#define REHEAT_FLAME_HIDE "afterburner_left_userhide"
#define REHEAT_FLAME_SHOWN 0.5
#define GEAR_SOURCE "gear"
#define GEAR_RETRACTED 0.5
#define PARK_THROTTLE 0.02
#define PARK_SPEED 6

params ["_plane"];

[_plane, EMPTY_MASS] call EFUNC(common,initMass);
if (local _plane) then {
    [_plane, false] call FUNC(afterburnerVisuals);
};

[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_nextNozzleCheck", "_engineWasOn", "_reheatWasOn", "_nextFuelBurn"];

    if (!alive _plane) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        if (local _plane) then {
            [_plane, false] call FUNC(afterburnerVisuals);
        };
    };

    if (local _plane) then {
        [_plane] call FUNC(afterburner);

        if (isTouchingGround _plane && {airplaneThrottle _plane < PARK_THROTTLE}) then {
            private _velocity = velocity _plane;
            private _horizontal = sqrt ((_velocity select 0) ^ 2 + (_velocity select 1) ^ 2);
            if (_horizontal > 0.05 && {_horizontal < PARK_SPEED}) then {
                _plane setVelocity [0, 0, _velocity select 2];
            };
        };

        if (CBA_missionTime > _nextNozzleCheck) then {
            [_plane] call FUNC(nozzles);
            if (isLightOn _plane && {_plane animationSourcePhase GEAR_SOURCE > GEAR_RETRACTED}) then {
                _plane setPilotLight false;
            };
            _args set [1, CBA_missionTime + NOZZLE_INTERVAL];
        };

        if (CBA_missionTime > _nextFuelBurn) then {
            [_plane, IDLE_LITRES_PER_HOUR, MAX_DRY_LITRES_PER_HOUR, MAX_REHEAT_LITRES_PER_HOUR] call EFUNC(common,fuelBurn);
            [_plane, EMPTY_MASS] call EFUNC(common,updateMass);
            _args set [4, CBA_missionTime + FUEL_INTERVAL];
        };
    };

    if (hasInterface) then {
        private _engineOn = isEngineOn _plane;
        if (_engineOn && {!_engineWasOn} && {speed _plane < 10}) then {
            [_plane] call FUNC(apuSmoke);
        };
        _args set [2, _engineOn];

        private _reheatOn = _plane animationPhase REHEAT_FLAME_HIDE < REHEAT_FLAME_SHOWN;
        if (_reheatOn && {!_reheatWasOn}) then {
            [_plane] call FUNC(reheatKick);
        };
        _args set [3, _reheatOn];
    };

    if (hasInterface && {ACE_player == driver _plane}) then {
        [_plane] call FUNC(hmdVisibility);
    };
}, 0, [_plane, 0, isEngineOn _plane, _plane animationPhase REHEAT_FLAME_HIDE < REHEAT_FLAME_SHOWN, 0]] call CBA_fnc_addPerFrameHandler;
