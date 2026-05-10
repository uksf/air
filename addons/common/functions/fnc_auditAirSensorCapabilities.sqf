#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Diagnostic — walks every CfgVehicles class belonging to a UKSF-shipped
        airframe (or used by UKSF in modpack), and reports which ones are
        missing the engine signals required by the RWR source classifier:
        - incomingMissileDetectionSystem with bit 16 set (else IncomingMissile
          EH never fires)
        - PassiveRadarSensorComponent under SensorsManagerComponent (else the
          SENS panel doesn't render at all and our extension never displays)

        Output is diag_log'd and returned. Not wired into postInit; invoked
        manually for one-off audits.

    Parameter(s):
        None

    Return Value:
        Hashmap: { "missingMWS": [...], "missingRWR": [...], "ok": [...] }

    Example:
        call uksf_air_common_fnc_auditAirSensorCapabilities
*/

private _targets = [
    // UKSF-shipped airframes
    "uksf_air_apache_aac",
    "uksf_air_c130_raf",
    "uksf_air_f35_raf",
    "uksf_air_f35_raf_stealth",
    "uksf_f35_plane_raf",
    "uksf_f35_plane_raf_stealth",
    "uksf_air_reaper_raf",
    "uksf_air_reaper_raf_recon",
    "UK3CB_BAF_MQ9_Reaper",
    "uksf_air_dauphin",
    "uksf_air_patches_a400m_raf",
    "uksf_air_patches_pe_mh6",
    "uksf_air_patches_pe_ah6",
    "uksf_air_patches_pe_uh60",
    "uksf_air_patches_pe_uh60m",
    "uksf_air_patches_pe_mh60l",
    "uksf_air_patches_eh101_idap",
    "UKSF_B_L39",
    "UKSF_B_L39_Unarmed",
    // UK3CB BAF airframes used at UKSF
    "UK3CB_BAF_Wildcat_AH1",
    "UK3CB_BAF_Merlin_HC4",
    "UK3CB_BAF_CH47F_GB",
    "UK3CB_BAF_CH47F_VIV_GB"
];

private _missingMWS = [];
private _missingRWR = [];
private _ok = [];

{
    private _class = _x;
    private _cfg = configFile >> "CfgVehicles" >> _class;
    if (!isClass _cfg) then {
        diag_log format ["[uksf_air audit] class not found: %1", _class];
    } else {
        private _imds = getNumber (_cfg >> "incomingMissileDetectionSystem");
        // string form "8 + 16" returns 0 from getNumber — fall back to text + parse
        if (_imds == 0) then {
            private _imdsText = getText (_cfg >> "incomingMissileDetectionSystem");
            if (_imdsText isNotEqualTo "") then {
                _imds = call compile _imdsText;
            };
        };
        // bit 16 set (16, 24, 48, etc.)
        private _hasMWS = ((floor (_imds / 16)) % 2) == 1;

        private _passiveRadar = _cfg >> "Components" >> "SensorsManagerComponent" >> "Components" >> "PassiveRadarSensorComponent";
        private _hasRWR = isClass _passiveRadar;

        if (!_hasMWS) then { _missingMWS pushBack _class; };
        if (!_hasRWR) then { _missingRWR pushBack _class; };
        if (_hasMWS && _hasRWR) then { _ok pushBack _class; };
    };
} forEach _targets;

private _report = createHashMapFromArray [
    ["missingMWS", _missingMWS],
    ["missingRWR", _missingRWR],
    ["ok", _ok]
];

diag_log format ["[uksf_air audit] missingMWS (%1): %2", count _missingMWS, _missingMWS];
diag_log format ["[uksf_air audit] missingRWR (%1): %2", count _missingRWR, _missingRWR];
diag_log format ["[uksf_air audit] ok (%1): %2", count _ok, _ok];

_report
