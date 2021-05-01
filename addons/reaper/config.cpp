#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(raf),
            QGVAR(raf_recon),
            
            // Obsolete
            "UK3CB_BAF_MQ9_Reaper"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "UK3CB_BAF_Vehicles_MQ9_Reaper",
            QGVAR(prep)
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgRscUI.hpp"
#include "CfgVehicles.hpp"
