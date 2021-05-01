#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if aircraft functions can be controlled from the current position.
        With 2nd param true, effectively disables control for pilot and copilot if loadmaster is present.

    Parameter(s):
        0: Plane <OBJECT>
        1: Can loadmaster control (Optional) <BOOLEAN>

    Return Value:
        True if control possible <BOOLEAN>
*/
params ["_plane", ["_canLoadmasterControl", false]];

private _isPilotOrCopilot = ACE_player == driver _plane || ACE_player == _plane turretUnit [0];
if !(_canLoadmasterControl) exitWith {
    _isPilotOrCopilot
};

private _loadmasters = [2, 3, 4, 5] apply {_plane turretUnit [_x]};
private _isLoadmaster = [_loadmasters, {ACE_player == _x}] call UFUNC(common,arrayAny);
private _hasLoadmaster = [_loadmasters, {!(isNull _x)}] call UFUNC(common,arrayAny);

_isLoadmaster || {_isPilotOrCopilot && !_hasLoadmaster}
