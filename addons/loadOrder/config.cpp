#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            // Vanilla
            "A3_Data_F_Tank_Loadorder",

            // CBA
            "cba_main",
            "cba_ui",
            "cba_xeh",

            // ACE
            "ace_aim120",
            "ace_aim9",
            "ace_aircraft",
            "ace_cargo",
            "ace_common",
            "ace_compat_cup_vehicles",
            "ace_gbu",
            "ace_hellfire",
            "ace_main",
            "ace_rearm",
            "ace_refuel",
            "ace_sdb",

            // CUP
            "CUP_AirVehicles_LoadOrder",
            "CUP_Weapons_Ammunition",
            "CUP_Weapons_DynamicLoadout",
            "CUP_Weapons_VehicleWeapons",

            // 3CB
            "UK3CB_BAF_Vehicles_LoadOrder",
            "UK3CB_BAF_Vehicles_Merlin",
            "UK3CB_BAF_Vehicles_MQ9_Reaper",
            "UK3CB_BAF_Vehicles_Wildcat",

            // Other
            "A400M",
            "ATASK",
            "CXS_LightSticks",
            "HAFM_EC635",
            "MEA_Panther",
            "rksla3_aw159",
            "rksla3_pumahc",
            "Starstreak"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};