#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
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

// ace_refuel_fuelCapacity overrides at the CUP/vanilla base class level for vehicles
// not directly customised by UKSF but used by faction packs or available in editor.
// Real-world internal fuel capacities in litres where applicable; vanilla fuelCapacity
// left untouched so flight characteristics stay intact for non-UKSF use. Where the
// vehicle is fictional (vanilla A3) and has no clean real-world analogue, the closest
// real-life equivalent's capacity is used so litre tracking gives meaningful numbers.
class CfgVehicles {
    // ─── Helicopters ───────────────────────────────────────────────────────

    class Helicopter_Base_F;
    class Helicopter_Base_H;

    class CUP_AH1Z_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1562; // Bell AH-1Z Viper: 412.5 US gal / 1562 L
    };

    class CUP_B_UH1Y_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1469; // Bell UH-1Y Venom: 388 US gal / 1469 L
    };

    class CUP_UH1H_base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 832; // Bell UH-1H Iroquois: 220 US gal / 832 L
    };

    class CUP_412_01_base_F : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1251; // Bell 412 / CH-146 Griffon: 331 US gal / 1251 L
    };

    class CUP_Mi24_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1840; // Mil Mi-24 / Mi-35 Hind: ~1840 L internal
    };

    class CUP_Mi8_base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1870; // Mil Mi-8 / Mi-17 Hip: 1870 L internal (2 tanks)
    };

    class CUP_KA50_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1800; // Kamov Ka-50 Black Shark: ~1800 L internal
    };

    class CUP_Ka60_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1500; // Kamov Ka-60 Kasatka: ~1500 L internal
    };

    class CUP_AW159_Unarmed_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1275; // AgustaWestland AW159 Wildcat: ~1275 L internal
    };

    class CUP_AH6_BASE : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 916; // MD-500 / AH-6 / MH-6 Little Bird: 242 US gal / 916 L
    };

    class CUP_Uh60_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1361; // Sikorsky UH-60 Black Hawk: 360 US gal / 1361 L
    };

    class UK3CB_BAF_Apache_AH1 : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1422; // AH-64D Apache (UK3CB BAF base): 376 US gal / 1422 L
    };

    class CUP_Merlin_HC3_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 4070; // AW101 Merlin HC3: ~4,070 L total internal
    };

    class CUP_Merlin_HC3_Lux_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 4070; // AW101 Merlin HC3 Lux variant
    };

    class CUP_Merlin_Rescue_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 4070; // AW101 Merlin HC3 Rescue variant
    };

    class CUP_MH47E_base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 3914; // Boeing MH-47E Chinook: ~3914 L (1034 US gal)
    };

    // Vanilla A3 Hummingbird (used by UKSF Panda Express, VAF as MH-6 stand-in)
    class Heli_Light_01_base_F : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 916; // MD-500 / MH-6 Little Bird: 242 US gal / 916 L
    };

    class CUP_AH64_base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1422; // CUP AH-64 Apache (covers AH-64A/D/MR variants): 1422 L
    };

    class CUP_Ka52_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1870; // Kamov Ka-52 Alligator: ~1870 L internal
    };

    class CUP_MH60S_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1361; // Sikorsky MH-60S Knighthawk: ~1361 L (UH-60 chassis)
    };

    class CUP_MI6A_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 16500; // Mil Mi-6 Hook (heavy transport): ~16,500 L internal
    };

    class CUP_CH53E_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 3850; // Sikorsky CH-53E Super Stallion: 1017 US gal / ~3,850 L
    };

    class CUP_SA330_Base : Helicopter_Base_H {
        ace_refuel_fuelCapacity = 1556; // Aerospatiale SA-330 Puma: ~1,556 L internal
    };

    // Vanilla A3 Heli_Attack_01 — fictional Comanche-like stealth attack heli
    class Heli_Attack_01_base_F : Helicopter_Base_F {
        ace_refuel_fuelCapacity = 1140; // Boeing-Sikorsky RAH-66 Comanche analogue: ~1140 L
    };

    // Vanilla A3 Heli_Attack_02 — fictional Mi-48 Kajman, Mi-28 analogue
    class Heli_Attack_02_base_F : Helicopter_Base_F {
        ace_refuel_fuelCapacity = 1500; // Mil Mi-28 Havoc analogue: ~1500 L
    };

    // Vanilla A3 UAV bases (fictional small drones — keep close to game values)
    class UAV_01_base_F : Helicopter_Base_F {
        ace_refuel_fuelCapacity = 90; // AR-2 Darter / MQ-1 Predator stand-in: ~90 L
    };

    class UAV_03_base_F : Helicopter_Base_F {
        ace_refuel_fuelCapacity = 30; // Falcon hybrid quadcopter: small
    };

    class UAV_06_base_F : Helicopter_Base_F {
        ace_refuel_fuelCapacity = 16; // Stomper / Saif quadrocopter: small fictional UAV
    };

    // ─── Fixed Wing ────────────────────────────────────────────────────────

    class Plane;
    class Plane_Base_F;
    class UAV;

    class CUP_Su25_base : Plane {
        ace_refuel_fuelCapacity = 3660; // Sukhoi Su-25 Frogfoot: ~3660 L internal
    };

    class CUP_SU34_BASE : Plane {
        ace_refuel_fuelCapacity = 15300; // Sukhoi Su-34 Fullback: 12,100 kg / ~15,300 L
    };

    class CUP_AN2_Base : Plane_Base_F {
        ace_refuel_fuelCapacity = 1200; // Antonov An-2 Colt: ~1200 L internal
    };

    class CUP_DC3_Base : Plane_Base_F {
        ace_refuel_fuelCapacity = 3045; // Douglas C-47 / DC-3 / Li-2: 804 US gal / 3045 L
    };

    class CUP_B_MV22_USMC : Plane_Base_F {
        ace_refuel_fuelCapacity = 6513; // Bell-Boeing MV-22 Osprey: 1721 US gal / 6513 L
    };

    class Plane_Fighter_04_Base_F : Plane {
        ace_refuel_fuelCapacity = 3800; // Saab JAS-39 Gripen C: 3000 kg / ~3800 L
    };

    class CUP_Pchela1T_Base : UAV {
        ace_refuel_fuelCapacity = 50; // Pchela-1T reconnaissance UAV: small
    };

    class UAV_04_base_F : UAV {
        ace_refuel_fuelCapacity = 1000; // K40 Ababil-3-class CAS UAV: keep game value (fictional)
    };

    // Vanilla A3 fictional aircraft (use closest real-world analogue)
    class Plane_Fighter_01_Base_F : Plane_Base_F {
        ace_refuel_fuelCapacity = 7750; // F-181 Black Wasp II / F-35-like fighter: ~7,750 L
    };

    class Plane_Fighter_02_Base_F : Plane_Base_F {
        ace_refuel_fuelCapacity = 10300; // To-201 Shikra / Su-57-like fighter: ~10,300 L
    };

    class VTOL_01_base_F : Plane_Base_F {
        ace_refuel_fuelCapacity = 6513; // V-44 X Blackfish / V-22 Osprey analogue: ~6,513 L
    };

    class VTOL_Base_F : Plane_Base_F {};
    class VTOL_02_base_F : VTOL_Base_F {
        ace_refuel_fuelCapacity = 6513; // Y-32 Xi'an / V-22-class VTOL transport: ~6,513 L
    };

    class Plane_Civil_01_base_F : Plane_Base_F {
        ace_refuel_fuelCapacity = 800; // Caesar BTT / Pilatus PC-9 analogue: ~800 L
    };

    class UAV_05_Base_F : UAV {
        ace_refuel_fuelCapacity = 800; // K40 Ababil-3-like long-range UAV: ~800 L
    };

    // CUP commercial aircraft (real-world values)
    class cup_cessna_base : Plane_Base_F {
        ace_refuel_fuelCapacity = 204; // Cessna 172 / T-41 Mescalero: 54 US gal / 204 L
    };

    class CUP_Ambient_Cessna172_Base : Plane_Base_F {
        ace_refuel_fuelCapacity = 204; // Cessna 172 Skyhawk: 54 US gal / 204 L
    };

    class CUP_Ambient_A330_Base : Plane_Base_F {
        ace_refuel_fuelCapacity = 139090; // Airbus A330: 139,090 L wing tanks (per A330-200)
    };

    class CUP_Ambient_B737_Base : Plane_Base_F {
        ace_refuel_fuelCapacity = 26020; // Boeing 737-800: 26,020 L (covers P-8A Poseidon variant too)
    };

    class CUP_MQ9_Base : UAV {
        ace_refuel_fuelCapacity = 2260; // General Atomics MQ-9 Reaper: 4,000 lb / 2,260 L
    };

    class CUP_A10_Base : Plane_Base_F {
        ace_refuel_fuelCapacity = 4990; // Fairchild A-10 Thunderbolt II: 1,320 US gal / 4,990 L
    };
};
