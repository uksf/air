#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            QGVAR(towbar)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_air_main"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG_COMMON;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
