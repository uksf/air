#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            QGVAR(gunpod),
            QGVAR(C130FlareLauncher)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_air_common",
            "CUP_Weapons_Ammunition",
            "CUP_Weapons_VehicleWeapons",
            "CUP_Weapons_DynamicLoadout",
            "rksla3_aw159",
            "ace_aim9",
            "ace_aim120",
            "ace_gbu",
            "ace_sdb"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

class CfgInGameUI {
    class CfgWeaponModeTextures {
        LOFT = QPATHTOF(data\mode_loft_ca.paa);
    };
};
class PreloadTextures {
    class CfgInGameUI {
        LOFT = "*";
    };
};
