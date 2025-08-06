#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(dauphin),
            QGVAR(a400m_raf),

            // Panda Express
            QGVAR(pe_mh6),
            QGVAR(pe_ah6),
            QGVAR(pe_uh60),
            QGVAR(pe_uh60m),
            QGVAR(pe_mh60l),
            QGVAR(eh101_idap),

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
            "uksf_air_f35",
            QGVAR(prep)
        };
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
