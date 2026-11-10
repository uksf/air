private _planes = [];
{
    _x params ['_type', '_y'];
    {
        _x params ['_label', '_fraction', '_xpos'];
        private _v = createVehicle [_type, [_xpos, _y, 0], [], 0, 'CAN_COLLIDE'];
        _v allowDamage false;
        private _stores = getPylonMagazines _v;
        {
            if (_fraction < 2 && {(_fraction == 0) || {_forEachIndex mod 2 == 1}}) then {
                _v setPylonLoadOut [_forEachIndex + 1, '', true];
            };
        } forEach _stores;
        _v setFuel ([0.05, 0.5, 1] select _fraction);
        createVehicleCrew _v;
        { _x disableAI 'MOVE'; _x disableAI 'FSM'; } forEach crew _v;
        _v engineOn true;
        _planes pushBack [_type, _label, _v, _stores];
    } forEach [['empty', 0, 100], ['half', 1, 150], ['full', 2, 200]];
} forEach [['uksf_air_typhoon_raf', 100], ['uksf_air_f35_raf', 200]];
uiSleep 15;
{
    _x params ['_type', '_label', '_v'];
    _x pushBack (getPosASL _v);
    format ['ground start %1 %2 pos=%3 mass=%4 fuel=%5 engine=%6 throttle=%7 pylons=%8', _type, _label, getPosASL _v, getMass _v, fuel _v, isEngineOn _v, airplaneThrottle _v, getPylonMagazines _v] call vc_fnc_log;
} forEach _planes;
for '_tick' from 1 to 4 do {
    uiSleep 30;
    {
        _x params ['_type', '_label', '_v', '_stores', '_start'];
        format ['ground t=%1 type=%2 load=%3 drift=%4 pos=%5 mass=%6 engine=%7 throttle=%8', _tick * 30, _type, _label, (getPosASL _v) distance2D _start, getPosASL _v, getMass _v, isEngineOn _v, airplaneThrottle _v] call vc_fnc_log;
        if (_tick == 2 && {_label == 'empty'}) then {
            {
                if (_x != '') then { _v setPylonLoadOut [_forEachIndex + 1, _x, true]; };
            } forEach _stores;
            format ['rearm %1 start=%2 pylons=%3', _type, getPosASL _v, getPylonMagazines _v] call vc_fnc_log;
            _x pushBack (getPosASL _v);
        };
        if (_tick > 2 && {_label == 'empty'}) then {
            format ['rearm %1 elapsed=%2 drift=%3 mass=%4', _type, (_tick - 2) * 30, (getPosASL _v) distance2D (_x select 5), getMass _v] call vc_fnc_log;
        };
    } forEach _planes;
};
{ { deleteVehicle _x; } forEach crew (_x select 2); deleteVehicle (_x select 2); } forEach _planes;
{
private _type = _x;
private _v = createVehicle [_type, [300, 300, 0], [], 0, 'CAN_COLLIDE'];
_v allowDamage false;
_v setFuel 0.5;
player moveInDriver _v;
_v engineOn true;
_v setVariable ['uksf_air_typhoon_reheatSuppressed', true, true];
private _hold = [{
    params ['_args'];
    private _v = _args select 0;
    _v engineOn true;
    _v setAirplaneThrottle (_args select 1);
    _v animateSource ['gear', 1, true];
    _v animateSource ['gearx', 1, true];
}, 0, [_v, 0.89]] call CBA_fnc_addPerFrameHandler;
{
    _x params ['_label', '_pitch', '_speed'];
    private _dir = [0, cos _pitch, sin _pitch];
    _v setPosASL [2000, 2000, 1000];
    _v setVectorDirAndUp [_dir, [0, -(sin _pitch), cos _pitch]];
    _v setVelocity (_dir vectorMultiply _speed);
    _v setAngularVelocity [0, 0, 0];
    uiSleep 0.3;
    private _t = diag_tickTime;
    private _start = velocity _v;
    uiSleep 4;
    format ['flight %1 %2 elapsed=%3 v0=%4 v1=%5 pitch=%6 mass=%7 throttle=%8 typhoonReheat=%9 f35Reheat=%10 gear=%11', _type, _label, diag_tickTime - _t, _start, velocity _v, asin ((vectorDir _v) select 2), getMass _v, airplaneThrottle _v, _v getVariable ['uksf_air_typhoon_afterburnerEngaged', false], _v getVariable ['uksf_air_f35_afterburnerEngaged', false], _v animationSourcePhase 'gear'] call vc_fnc_log;
} forEach [['level120', 0, 120], ['level160', 0, 160], ['climb30', 30, 160]];
if (_type == 'uksf_air_typhoon_raf') then {
    [_hold] call CBA_fnc_removePerFrameHandler;
    _v setVariable ['uksf_air_typhoon_reheatSuppressed', false, true];
    _hold = [{
        params ['_args'];
        private _v = _args select 0;
        _v engineOn true;
        _v setAirplaneThrottle 1;
    }, 0, [_v]] call CBA_fnc_addPerFrameHandler;
    _v setPosASL [2000, 2000, 1000];
    _v setVectorDirAndUp [[0, 1, 0], [0, 0, 1]];
    _v setVelocity [0, 160, 0];
    _v setAngularVelocity [0, 0, 0];
    uiSleep 0.3;
    private _start = velocity _v;
    uiSleep 4;
    format ['flight reheat v0=%1 v1=%2 throttle=%3 reheat=%4 pitch=%5', _start, velocity _v, airplaneThrottle _v, _v getVariable ['uksf_air_typhoon_afterburnerEngaged', false], asin ((vectorDir _v) select 2)] call vc_fnc_log;
};
[_hold] call CBA_fnc_removePerFrameHandler;
moveOut player;
deleteVehicle _v;
} forEach ['uksf_air_typhoon_raf', 'uksf_air_f35_raf', 'B_Plane_Fighter_01_F'];
call vc_fnc_done;
