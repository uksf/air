#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds actions to static line jump to aircraft

    Parameter(s):
        0: Aircraft <OBJECT>

    Return Value:
        Nothing
*/
params ["_aircraft"];

private _jumpPointConfig = configOf _aircraft >> QGVAR(staticLineJumpPoints);
if !(isArray _jumpPointConfig) exitWith {};

_aircraft addAction ["Jump (Static Line)", QUOTE(call FUNC(staticLineJump)), nil, 5, true, true, "", QUOTE([ARR_2(_target,_this)] call FUNC(canStaticLineJump))];
