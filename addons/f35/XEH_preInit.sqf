#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(inGroup) = true;

[QGVAR(base), "init", {call FUNC(initPlane)}, true, nil, true] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getin", {call FUNC(getIn)}] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getout", {call FUNC(getOut)}] call CBA_fnc_addClassEventHandler;
private _nameplate = {[_this select 0, 1, QPATHTOF(data\name_%1_ca.paa)] call EFUNC(common,setNamePlate)};
[QGVAR(base), "init", _nameplate, true, [], true] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getin", _nameplate] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "getout", _nameplate] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "seatswitched", _nameplate] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "local", _nameplate] call CBA_fnc_addClassEventHandler;
[QGVAR(base), "InitPost", {
    params ["_plane"];
    if (_plane getVariable [QGVAR(mfdPylonHandler), false]) exitWith {};
    _plane setVariable [QGVAR(mfdPylonHandler), true];
    _plane addEventHandler ["PylonChanged", {
        params ["_plane"];
        if (_plane getVariable [QGVAR(mfdPending), false]) exitWith {};
        _plane setVariable [QGVAR(mfdPending), true];
        [{
            params ["_plane"];
            _plane setVariable [QGVAR(mfdPending), false];
            [_plane] call FUNC(setMfdLoadout);
        }, [_plane]] call CBA_fnc_execNextFrame;
    }];
}, true, nil, true] call CBA_fnc_addClassEventHandler;

["ace_pylons_setPylonLoadOutEvent", {
    params ["_plane"];

    if (_plane isKindOf QGVAR(base)) then {
        [_plane] call FUNC(setMfdLoadout);
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
