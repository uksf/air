#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Maps a missile ammo type to a short radar-seeker display token for the
        notch helper label. Reads ACE missileguidance defaultSeekerType.

    Parameter(s):
        0: Ammo type classname <STRING>

    Return Value:
        "ARH" / "SARH" / "ARM" / "RDR" <STRING>

    Example:
        ["ace_missile_AIM120D_C"] call uksf_air_common_fnc_radarSeekerToken
*/
params [["_ammoType", "", [""]]];

private _seekerType = getText (configFile >> "CfgAmmo" >> _ammoType >> "ace_missileguidance" >> "defaultSeekerType");

switch (toLower _seekerType) do {
    case "arh";
    case "activeradar": { "ARH" };
    case "sarh";
    case "dopplerradar": { "SARH" };
    case "antiradiation": { "ARM" };
    default { "RDR" };
};
