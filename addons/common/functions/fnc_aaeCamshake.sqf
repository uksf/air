#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Wrapper for AAE camshake function replacement

    Parameter(s):
        0: Plane <OBJECT>

    Return Value:
        Nothing
*/
private _plane = _this;

if ((_plane isKindOf "UAV_02_base_F") || (_plane isKindOf "UAV_04_base_F")) exitWith {};

private _distance = player distance _plane;
if (_distance < camshake_sdr) then {
	addCamShake [
		linearConversion [5, camshake_sdr, _distance, 1, 0.01, true],
		1,
		linearConversion [50, camshake_sdr,_distance, 25, 15, true]
	];
};
