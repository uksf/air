#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "MEA_Panther",
            "UK3CB_BAF_Vehicles_Wildcat",
            "CUP_AirVehicles_LoadOrder",
            "CUP_Vehicles_ACE_compat"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgVehicles {    
    class UK3CB_BAF_Wildcat_AH1_6_Base;
    class UK3CB_BAF_Wildcat_AH1_8_Base;
    class UK3CB_BAF_Wildcat_HMA2_8_Base;
    RESET_INVENTORY(UK3CB_BAF_Wildcat_AH1_6_Armed,UK3CB_BAF_Wildcat_AH1_6_Base);
    RESET_INVENTORY(UK3CB_BAF_Wildcat_AH1_8_Armed,UK3CB_BAF_Wildcat_AH1_8_Base);
    RESET_INVENTORY(UK3CB_BAF_Wildcat_AH1_TRN_8A,UK3CB_BAF_Wildcat_AH1_8_Base);
    RESET_INVENTORY(UK3CB_BAF_Wildcat_HMA2_TRN_8A,UK3CB_BAF_Wildcat_HMA2_8_Base);

    class MEA_Pantera_Base;
    RESET_INVENTORY(uksf_air_patches_dauphin,MEA_Pantera_Base);
    
    class CUP_CH47F_base;
    class CUP_CH47F_VIV_base;
    RESET_INVENTORY(CUP_B_CH47F_GB,CUP_CH47F_base);
    RESET_INVENTORY(CUP_B_CH47F_VIV_GB,CUP_CH47F_VIV_base);
};
