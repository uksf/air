if (!isNil 'uksf_fuelLog_pfh') exitWith {
    [uksf_fuelLog_pfh] call CBA_fnc_removePerFrameHandler;
    uksf_fuelLog_pfh = nil;
    hintSilent '';
    systemChat 'Fuel log stopped';
};

private _vehicle = vehicle player;
private _capacity = getNumber (configOf _vehicle >> 'ace_refuel_fuelCapacity');
if (_vehicle isEqualTo player || {_capacity <= 0}) exitWith {
    systemChat 'Fuel log: get in a vehicle with ace_refuel_fuelCapacity set';
};

systemChat 'Fuel log started. Run again to stop.';
uksf_fuelLog_pfh = [{
    params ['_args'];
    _args params ['_vehicle', '_capacity', '_last'];
    _last params ['_lastTime', '_lastFuel'];
    private _elapsed = time - _lastTime;
    if (_elapsed <= 0) exitWith {};

    private _fuel = fuel _vehicle;
    private _litresPerHour = (_lastFuel - _fuel) / _elapsed * _capacity * 3600;
    private _minutesLeft = if (_litresPerHour > 0) then {round (_fuel * _capacity / _litresPerHour * 60)} else {-1};
    private _line = format [
        'Fuel %1 L/h | %2 L left | %3 min left | throttle %4 | %5 km/h',
        round _litresPerHour, round (_fuel * _capacity), _minutesLeft, (airplaneThrottle _vehicle) toFixed 2, round speed _vehicle
    ];
    hintSilent _line;
    diag_log text _line;
    _args set [2, [time, _fuel]];
}, 5, [_vehicle, _capacity, [time, fuel _vehicle]]] call CBA_fnc_addPerFrameHandler;
