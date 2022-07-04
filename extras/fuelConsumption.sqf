private _plane = vehicle player;
startFuel = fuel _plane;
endFuel = startFuel;
fuelConsumedPerSecond = [];
endCollection = false;
[{
    params ["_args", "_idPFH"];
    _args params ["_plane", "_time"];

    if (endCollection) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (CBA_missionTime > (_time + 1)) then {
        endFuel = fuel _plane;
        private _diff = (startFuel - endFuel);
        fuelConsumedPerSecond pushBack _diff;
        startFuel = endFuel;

        systemChat str _diff;
        _args set [1, CBA_missionTime];
    };

}, 0, [_plane, 0]] call cba_fnc_addPerFrameHandler;



endCollection = true;
private _totalFuelConsumedPerSecond = 0;
{
    if (_x > 0) then {
        _totalFuelConsumedPerSecond = _totalFuelConsumedPerSecond + _x;
    };
} forEach fuelConsumedPerSecond;
private _averageFuelConsumedPerSecond = _totalFuelConsumedPerSecond / (count fuelConsumedPerSecond);
diag_log _averageFuelConsumedPerSecond;
_averageFuelConsumedPerSecond



[idPfh] call CBA_fnc_removePerFrameHandler;

private _plane = vehicle player; 
_plane setFuel 1; 
startTime = CBA_missionTime; 
idPfh = [{ 
    params ["_args", "_idPFH"]; 
    _args params ["_plane"]; 
 
    systemChat str (fuel _plane); 
 
    if (fuel _plane <= 0.995) exitWith { 
        [_idPFH] call CBA_fnc_removePerFrameHandler; 
        private _timeTaken = CBA_missionTime - startTime; 
        diag_log str _timeTaken; 
        systemChat str _timeTaken; 
    }; 
 
}, 0, [_plane]] call cba_fnc_addPerFrameHandler;
