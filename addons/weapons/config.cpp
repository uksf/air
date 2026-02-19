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
            "uksf_air_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class ace_missileguidance_type_AMRAAM;
class ace_missileguidance_type_Jdam;
class ace_missileguidance_type_CruiseMissile;

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
