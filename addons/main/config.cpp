#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            // Vanilla
            "A3_Data_F_Tank_Loadorder",

            // CBA
            "cba_ui",
            "cba_xeh",

            // ACE
            "ace_main",
            "ace_common",
            "ace_aircraft",
            "ace_cargo",
            "ace_dragging",
            "ace_hellfire",
            "ace_interaction",
            "ace_rearm",
            "ace_refuel"
        };
        author = QUOTE(UKSF);
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgMods {
    class Mod_Base;
    class PREFIX: Mod_Base {
        dir = "@uksf_air";
        name = "UKSF Air";
        author = "UKSF";
        picture = QPATHTO_R(data\uksf_logo_ca);
        logo = QPATHTO_R(data\uksf_logo_ca);
        logoOver = QPATHTO_R(data\uksf_logo_ca);
        logoSmall = QPATHTO_R(data\uksf_logo_ca);
        hideName = 0;
        hidePicture = 0;
        actionName = "Website";
        action = "http://uk-sf.co.uk/";
        description = "Issue Tracker: https://github.com/uksf/modpack/issues";
        tooltip = "UKSF Air";
        tooltipOwned = "UKSF Air - Owned";
        overview = "Air Vehicles for UKSF";
    };
};

#include "CfgSettings.hpp"
