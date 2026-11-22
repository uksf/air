if (!hasInterface || {!canSuspend}) exitWith {private _r = "A3CMD|A4|FAIL|Run with execVM on client"; diag_log _r; _r};
private _cases = [
    ["uksf_air_typhoon_raf", 0, 600], ["uksf_air_typhoon_raf", 0.5, 6611], ["uksf_air_typhoon_raf", 1, 38800],
    ["uksf_air_f35_raf", 0, 600], ["uksf_air_f35_raf", 0.5, 6167], ["uksf_air_f35_raf", 1, 48800]
];
private _results = [];
private _ok = true;
private _plane = objNull;
{
    _x params ["_type", "_throttle", "_expected"];
    if (typeOf _plane != _type) then {
        if (!isNull _plane) then {moveOut player; deleteVehicle _plane; uiSleep 1};
        _plane = createVehicle [_type, player modelToWorld [0, 80, 0], [], 0, "NONE"];
        _plane allowDamage false;
        player moveInDriver _plane;
        uiSleep 2;
    };
    _plane setFuelConsumptionCoef 1;
    _plane setFuel 0.8;
    _plane setVelocity [0, 0, 0];
    _plane engineOn true;
    uksf_air_A4_hold = [_plane, _throttle];
    private _pfh = [{
        uksf_air_A4_hold params ["_v", "_t"];
        _v engineOn true;
        _v setAirplaneThrottle _t;
        _v setVelocity [0, 0, 0];
    }, 0] call CBA_fnc_addPerFrameHandler;
    private _eh = addMissionEventHandler ["EachFrame", {
        uksf_air_A4_hold params ["_v", "_t"];
        _v setAirplaneThrottle _t;
    }];
    uiSleep 4;
    private _fuel = fuel _plane;
    private _time = CBA_missionTime;
    uiSleep 20;
    private _litresPerHour = (_fuel - fuel _plane) * getNumber (configOf _plane >> "fuelCapacity") * 3600 / (CBA_missionTime - _time);
    [_pfh] call CBA_fnc_removePerFrameHandler;
    removeMissionEventHandler ["EachFrame", _eh];
    private _caseOk = abs (_litresPerHour - _expected) <= 0.03 * _expected && {getFuelConsumptionCoef _plane == 0};
    _ok = _ok && _caseOk;
    _results pushBack [_type, _throttle, round _litresPerHour, _expected, getFuelConsumptionCoef _plane];
} forEach _cases;
moveOut player;
_plane allowDamage true;
_plane engineOn false;
_plane setFuelConsumptionCoef 0;
_plane setFuel 1;
_plane setHitPointDamage ["HitFuel", 1];
uiSleep 10;
private _leaked = 1 - fuel _plane;
_ok = _ok && {_leaked > 0};
deleteVehicle _plane;
private _result = format ["A3CMD|A4|%1|cases=%2 leakFractionCoefZero=%3", ["FAIL", "PASS"] select _ok, _results, _leaked];
diag_log _result;
_result
