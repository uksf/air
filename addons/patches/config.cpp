#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(dauphin),

            // Panda Express
            QGVAR(pe_mh6),

            // Obsolete
            "UKSF_B_L39",
            "UKSF_B_L39_Unarmed",
            "uksf_air_dauphin",
            "uksf_f35_plane_raf",
            "uksf_f35_plane_raf_stealth"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "uksf_units",
            "CUP_AirVehicles_LoadOrder",
            "CUP_Vehicles_ACE_compat",
            "UK3CB_BAF_Vehicles_Merlin",
            "UK3CB_BAF_Vehicles_Wildcat",
            "rksla3_pumahc",
            "rksla3_aw159",
            "MEA_Panther",
            "HAFM_EC635",
            "uksf_air_f35",
            "uksf_air_patches_prep"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
    class UK3CB_BAF_Vehicles_Apache {
        name = "UK3CB_BAF_Vehicles_Apache";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {};
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class RscInGameUI {
    class RscUnitInfoAir;
    class RscUnitInfoNoSpeed : RscUnitInfoAir {
        controls[] = { "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_VehicleTogglesBackground", "CA_VehicleToggles", "CA_ValueFuel", "WeaponInfoControlsGroupRight" };
    };
    class RscUnitInfoAirPlane;
    class RscUnitInfoAirPlaneNoSpeed : RscUnitInfoAirPlane {
        controls[] = { "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_VehicleTogglesBackground", "CA_VehicleToggles", "CA_ValueFuel", "WeaponInfoControlsGroupRight", "CA_Throttle" };
    };
};

#include "CfgEditorSubcategories.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
