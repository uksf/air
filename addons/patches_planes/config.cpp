#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "uksf_f35_plane_raf",
            "uksf_f35_plane_raf_stealth",
            "uksf_f35_plane_usmc",
            "uksf_f35_plane_raf_stealth"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "CUP_AirVehicles_F35",
            "uksf_air_f35"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
