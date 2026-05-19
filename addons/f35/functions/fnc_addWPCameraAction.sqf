#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds an ACE self-action to the F-35 pilot's interaction menu that
        toggles the white-phosphor pilot-camera filter. State is stored on
        the player as a local variable; the gating PFEH reads it each frame.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_air_f35_fnc_addWPCameraAction
*/

private _action = [
    QGVAR(wpCameraToggle),
    "WP Camera Filter",
    "",
    {
        ACE_player setVariable [
            QGVAR(wpCamera),
            !(ACE_player getVariable [QGVAR(wpCamera), ace_nightvision_alwaysUseWP])
        ];
    },
    {vehicle ACE_player isKindOf QGVAR(base)},
    {},
    [],
    {[0, 0, 0]},
    2
] call ace_interact_menu_fnc_createAction;

[QGVAR(base), 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
