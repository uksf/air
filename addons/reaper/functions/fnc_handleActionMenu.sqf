#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handle action menu to override drone control

    Parameter(s):
        0: Action <STRING>

    Return Value:
        Block original action <BOOLEAN>
*/
params ["_action"];

if (_action == 'UAVTerminalOpen') exitWith {
    call FUNC(openDroneSelection);
    true
};

private _drone = getConnectedUAV ACE_player;
if (_action == 'BackFromUAV') exitWith {
    cutText ['', 'BLACK OUT', 1.5];
    cutText ['', 'BLACK IN', 1.5];
    objNull remoteControl (driver _drone);
    objNull remoteControl (gunner _drone);
    ACE_player switchCamera 'Internal';
    true
};

if (_action == 'SwitchToUAVDriver') exitWith {
    cutText ['', 'BLACK OUT', 1.5];
    cutText ['', 'BLACK IN', 1.5];
    objNull remoteControl (gunner _drone);
    ACE_player switchCamera 'Internal';
    ACE_player remoteControl (driver _drone);
    _drone switchCamera 'Internal';
    true
};

if (_action == 'SwitchToUAVGunner') exitWith {
    cutText ['', 'BLACK OUT', 1.5];
    cutText ['', 'BLACK IN', 1.5];
    objNull remoteControl (driver _drone);
    ACE_player switchCamera 'Internal';
    ACE_player remoteControl (gunner _drone);
    _drone switchCamera 'Internal';
    true
};

false
