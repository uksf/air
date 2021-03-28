#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            QGVAR(gunpod)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_air_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgWeapons.hpp"
