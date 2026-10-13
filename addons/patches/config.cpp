#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(dauphin),
            QGVAR(a400m_raf),

            QGVAR(pe_mh6),
            QGVAR(pe_ah6),
            QGVAR(pe_uh60),
            QGVAR(pe_uh60m),
            QGVAR(pe_mh60l),
            QGVAR(eh101_idap),

            "UKSF_B_L39",
            "UKSF_B_L39_Unarmed",
            "uksf_air_dauphin",
            "uksf_f35_plane_raf",
            "uksf_f35_plane_raf_stealth"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "uksf_units",
            "uksf_air_f35",
            "A3_Air_F",
            "A3_Air_F_Beta",
            "A3_Air_F_Beta_Heli_Transport_01",
            "A3_Air_F_EPC_Plane_CAS_01",
            "A3_Air_F_EPC_Plane_CAS_02",
            "A3_Air_F_Exp",
            "A3_Air_F_Exp_Plane_Civil_01",
            "A3_Air_F_Exp_VTOL_01",
            "A3_Air_F_Gamma_Plane_Fighter_03",
            "A3_Air_F_Heli",
            "A3_Air_F_Heli_Heli_Transport_03",
            "A3_Air_F_Heli_Heli_Transport_04",
            "A3_Air_F_Heli_Light_01",
            "A3_Air_F_Heli_Light_02",
            "A3_Air_F_Jets_Plane_Fighter_01",
            "A3_Air_F_Jets_Plane_Fighter_02",
            "A3_Air_F_Jets_Plane_Fighter_04",
            "A3_Air_F_Jets_UAV_05",
            "A400M",
            "CUP_AirVehciles_Cessna",
            "CUP_AirVehciles_KA60",
            "CUP_AirVehciles_MH47E",
            "CUP_AirVehciles_UH1Y",
            "CUP_AirVehicles_412",
            "CUP_AirVehicles_A10",
            "CUP_AirVehicles_AH6",
            "CUP_AirVehicles_AN2",
            "CUP_AirVehicles_AmbientPlanes",
            "CUP_AirVehicles_C130J",
            "CUP_AirVehicles_DC3",
            "CUP_AirVehicles_HC3",
            "CUP_AirVehicles_Ka52",
            "CUP_AirVehicles_L39",
            "CUP_AirVehicles_MH60S",
            "CUP_AirVehicles_MI6",
            "CUP_AirVehicles_MV22",
            "CUP_AirVehicles_Mi8",
            "CUP_AirVehicles_UH1H",
            "CUP_AirVehicles_UH60",
            "EAWS_EF2000",
            "HAFM_EC635",
            "MEA_Panther",
            "gx_drones_compat_rksl_cvwp",
            "rksla3_aw159",
            "rksla3_pumahc",
            "uksf_acr",
            "uksf_aug",
            "uksf_cartel",
            "uksf_cdf",
            "uksf_common",
            "uksf_eug",
            "uksf_inegal",
            "uksf_radios",
            "uksf_saf",
            "uksf_vaf",
            "uksf_vehicles",
            "uksf_zgf",
            QGVAR(prep),
            QGVAR(fuel)
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class RscInGameUI {
    class RscUnitInfoAir;
    class RscUnitInfoNoSpeed : RscUnitInfoAir {
        controls[] = { "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_VehicleTogglesBackground", "CA_VehicleToggles", "CA_ValueFuel", "WeaponInfoControlsGroupRight" };
    };
    class RscUnitInfoAirPlane;
    class RscUnitInfoAirPlaneNoSpeed : RscUnitInfoAirPlane {
        controls[] = { "CA_BackgroundVehicle", "CA_BackgroundVehicleTitle", "CA_BackgroundVehicleTitleDark", "CA_BackgroundFuel", "CA_Vehicle", "CA_VehicleRole", "CA_HitZones", "CA_VehicleTogglesBackground", "CA_VehicleToggles", "CA_ValueFuel", "WeaponInfoControlsGroupRight", "CA_Throttle" };
    };
};

#include "CfgEditorSubcategories.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMoves.hpp"
#include "CfgVehicles.hpp"
