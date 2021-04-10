#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if aircraft functions can be controlled from the current position.
        Effectively disables control for pilot and copilot if loadmaster is present.

    Parameter(s):
        0: Plane <OBJECT>
        1: Can loadmaster control <BOOLEAN>

    Return Value:
        True if control possible <BOOLEAN>
*/
params ["_plane", ["_canLoadmasterControl", false]];

private _isPilotOrCopilot = ACE_player == driver _plane || ACE_player == _plane turretUnit [0];
if !(_canLoadmasterControl) exitWith {
    _isPilotOrCopilot
};

private _loadmaster1 = _plane turretUnit [2];
private _loadmaster2 = _plane turretUnit [3];
private _loadmaster3 = _plane turretUnit [4];
private _isLoadmaster = ACE_player == _loadmaster1 || ACE_player == _loadmaster2 || ACE_player == _loadmaster3;
private _hasLoadmaster = !(isNull _loadmaster1) || !(isNull _loadmaster2) || !(isNull _loadmaster3);

_isLoadmaster || {_isPilotOrCopilot && !_hasLoadmaster}
