#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "CUP_AirVehicles_LoadOrder",
            "CUP_AirVehicles_C130J"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    delete CUP_B_C130J_GB;
    delete CUP_B_C130J_Cargo_GB;

    class UK3CB_BAF_Wildcat_AH1_6_Base;
    RESET_INVENTORY(UK3CB_BAF_Wildcat_AH1_6_Armed,UK3CB_BAF_Wildcat_AH1_6_Base);

    class UK3CB_BAF_Wildcat_AH1_8_Base;
    RESET_INVENTORY(UK3CB_BAF_Wildcat_AH1_8_Armed,UK3CB_BAF_Wildcat_AH1_8_Base);
    RESET_INVENTORY(UK3CB_BAF_Wildcat_AH1_TRN_8A,UK3CB_BAF_Wildcat_AH1_8_Base);

    class UK3CB_BAF_Wildcat_HMA2_8_Base;
    RESET_INVENTORY(UK3CB_BAF_Wildcat_HMA2_TRN_8A,UK3CB_BAF_Wildcat_HMA2_8_Base);
};
