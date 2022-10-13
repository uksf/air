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
            "CUP_AirVehicles_CH47",
            "CUP_Vehicles_ACE_compat"
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
    delete UK3CB_BAF_Wildcat_AH1_CAS_6B;
    delete UK3CB_BAF_Wildcat_AH1_CAS_6C;
    delete UK3CB_BAF_Wildcat_AH1_CAS_6D;
    delete UK3CB_BAF_Wildcat_AH1_CAS_6A;
    delete UK3CB_BAF_Wildcat_AH1_CAS_8B;
    delete UK3CB_BAF_Wildcat_AH1_CAS_8C;
    delete UK3CB_BAF_Wildcat_AH1_CAS_8D;
    delete UK3CB_BAF_Wildcat_AH1_CAS_8A;
    
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
    class CUP_B_CH47F_GB : CUP_CH47F_base {
        class TransportMagazines {
            delete _xx_CUP_30Rnd_556x45_Stanag;
            delete _xx_CUP_M72A6_M;
            delete _xx_SmokeShell;
            delete _xx_SmokeShellOrange;
            delete _xx_Chemlight_Red;
        };
        class TransportItems {
            delete _xx_FirstAidKit;
            delete _xx_MediKit;
            delete _xx_ToolKit;
        };
        class TransportBackpacks {
            delete _xx_CUP_B_Bergen_BAF;
            delete _xx_B_Parachute;
        };
        class TransportWeapons {
            delete _xx_CUP_arifle_L85A2_G;
            delete _xx_CUP_launch_M72A6;
        };
    };
    class CUP_CH47F_VIV_base;
    class CUP_B_CH47F_VIV_GB : CUP_CH47F_VIV_base {
        class TransportMagazines {
            delete _xx_CUP_30Rnd_556x45_Stanag;
            delete _xx_CUP_M72A6_M;
            delete _xx_SmokeShell;
            delete _xx_SmokeShellOrange;
            delete _xx_Chemlight_Red;
        };
        class TransportItems {
            delete _xx_FirstAidKit;
            delete _xx_MediKit;
            delete _xx_ToolKit;
        };
        class TransportBackpacks {
            delete _xx_CUP_B_Bergen_BAF;
            delete _xx_B_Parachute;
        };
        class TransportWeapons {
            delete _xx_CUP_arifle_L85A2_G;
            delete _xx_CUP_launch_M72A6;
        };
    };
};
