class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;
class CfgVehicles {
    class Plane_Base_F;
    class Plane_Fighter_03_base_F : Plane_Base_F {
        class Components;
        // EAWS defines no Wheels, so the Buzzard's wheel classes are inherited from here.
        class Wheels {
            class Wheel_1;
            class Wheel_2;
            class Wheel_3;
        };
    };
    class EAWS_EF2000 : Plane_Fighter_03_base_F {
        class AnimationSources;
        class EventHandlers;
        // The glass HUD is patched here in place. The engine draws only a Draw class's own elements, so
        // subclassing Draw to change a few would drop every inherited line, scale and ladder.
        class MFD {
            class HUD {
                // Same green as the shared HMD (f35/hmd/hmd.hpp). EAWS drew every symbol in a dark
                // {0, 0.3, 0.05} that vanished against a daylight sky.
                color[] = { 0.15, 1, 0.15, 1 };
                class Bones {
                    // altimeter needle: one turn per 100 ft (EAWS: per 100 m)
                    class ASL_Instrument {
                        maxAngle = 236220;
                    };
                };
                // Knots and feet like the HMD; EAWS read km/h and metres.
                class Draw {
                    color[] = { 0.15, 1, 0.15 };
                    alpha = 1;
                    class SpeedScale {
                        sourceScale = 1.94384;
                    };
                    class SpeedNumber {
                        sourceScale = 1.94384;
                    };
                    class AltNumber {
                        sourceScale = 3.28084;
                    };
                    // feet per minute
                    class VspeedNumber {
                        sourceScale = 196.85;
                    };
                };
            };
            class MFD_LH;
            class MFD_RH;
        };
        class pilotCamera;
    };
    class GVAR(base) : EAWS_EF2000 {
        scope = 1;
        scopeCurator = 0;
        author = QUOTE(UKSF);
        displayName = "Typhoon FGR4";
        side = 1;
        faction = "CUP_B_GB";
        crew = "UKSF_B_Pilot_617";
        typicalCargo[] = { "UKSF_B_Pilot_617" };
        FUEL(6215,80); // Typhoon real internal: ~4,996 kg / ~6,215 L
        unitInfoType = "RscUnitInfoAirPlaneNoSpeed";
        unitInfoTypeLite = "RscUnitInfoAirPlaneNoSpeed";
        driverWeaponsInfoType = "RscOptics_CAS_01_TGP";
        armor = 100;
        threat[] = { 0.1, 1, 1 };
        camouflage = 20;
        audible = 25;
        radarTargetSize = 0.7;
        visualTargetSize = 0.8;
        irTargetSize = 0.9;
        showAllTargets = 2;
        countermeasureActivationRadius = 32000;
        // EAWS used the old pre-PhysX "airplane" model: no physics body, so no mass and no scripted forces.
        simulation = "airplaneX";
#include "vehicle\Flight.hpp"
#include "vehicle\Wheels.hpp"

        // The rebuilt model splits the camo: camo1 is the upper sheet, camo_lower the underside sheet,
        // camo_pilot the pilot-view LOD on the original layout. Every camo selection comes first so
        // hiddenSelectionsMaterials only lists those. fnc_afterburnerVisuals addresses the flame discs
        // by index; the RWR lamps are only indexed by the disabled EAWS incoming-missile script.
        hiddenSelections[] = {
            "camo1", "camo_lower", "camo_pilot", "misc_parts", "pylons", "camo2", "burner_fire_1_left", "burner_fire_1_right",
            "rwr_LL", "rwr_LR", "rwr_UL", "rwr_UR", "rwr_U", "rwr_D", "rwr_L", "rwr_R",
            "rwr_1oclock", "rwr_2oclock", "rwr_3oclock", "rwr_4oclock", "rwr_5oclock", "rwr_6oclock",
            "rwr_7oclock", "rwr_8oclock", "rwr_9oclock", "rwr_10oclock", "rwr_11oclock", "rwr_12oclock",
            "rwr_00", "rwr_45", "rwr_90", "rwr_120", "rwr_180", "rwr_225", "rwr_270", "rwr_315", "rwr_CLOSE"
        };

        weapons[] = { "CUP_weapon_mastersafe", "EAWS_BK27", "Laserdesignator_pilotCamera", "UK3CB_BAF_CMFlareLauncher" };
        magazines[] = { "EAWS_150Rnd_BK27", "Laserbatteries", "240Rnd_CMFlare_Chaff_Magazine" };
        memoryPointCM[] = { "flare_launcher1", "flare_launcher2" };
        memoryPointCMDir[] = { "flare_launcher1_dir", "flare_launcher2_dir" };

        disableInventory = 0;
        supplyRadius = 4; // doplnovani is in the cockpit, ~3.2 m from a player at the ladder
        maximumLoad = 200;
        transportMaxBackpacks = 1;
        class TransportItems {};
        class TransportMagazines {};
        class TransportWeapons {};

        soundSetSonicBoom[] = { "Plane_Fighter_SonicBoom_SoundSet" };
        soundEngineOnInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\I_Plane_Fighter_04_engine_start_int", 1, 1 };
        soundEngineOnExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\I_Plane_Fighter_04_engine_start_ext", 1.75, 1, 300 };
        soundEngineOffInt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\I_Plane_Fighter_04_engine_shut_int", 1, 1 };
        soundEngineOffExt[] = { "A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\I_Plane_Fighter_04_engine_shut_ext", 1.75, 1, 300 };
        soundLocked[] = { "A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedOn1", 1, 1 };
        soundIncommingMissile[] = { "A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedon2", 1, 1.5 };
        class Sounds {
            soundSets[] = {
                "Plane_Fighter_04_EngineLowExt_SoundSet",
                "Plane_Fighter_04_EngineHighExt_SoundSet",
                "Plane_Fighter_04_ForsageExt_SoundSet",
                "Plane_Fighter_04_WindNoiseExt_SoundSet",
                "Plane_Fighter_04_EngineExt_Dist_Front_SoundSet",
                "Plane_Fighter_04_EngineExt_Middle_SoundSet",
                "Plane_Fighter_04_EngineExt_Dist_Rear_SoundSet",
                "Plane_Fighter_04_EngineLowInt_SoundSet",
                "Plane_Fighter_04_EngineHighInt_SoundSet",
                "Plane_Fighter_04_ForsageInt_SoundSet",
                "Plane_Fighter_04_WindNoiseInt_SoundSet",
                "Plane_Fighter_04_VelocityInt_SoundSet"
            };
        };

        class AnimationSources : AnimationSources {
            // The model's tail hook follows this source instead of the gear; held stowed.
            class hook {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
#include "vehicle\Nozzles.hpp"
        };

        // The EAWS scripts need Firewill's AWS, which is not in the pack.
        class EventHandlers : EventHandlers {
            init = "";
            engine = "";
            fired = "";
            getOut = "";
            incomingMissile = "";
            // EAWS chute.sqf: deploys the drag chute and cuts speed by script on every touchdown,
            // which PhysX gear reports throughout a ground roll.
            landedTouchDown = "";
        };

        // Replaces every EAWS action (loadout dialog, reheat toggle, jammers, nosecone and the rest).
        driverCanEject = 0;
        class UserActions {
            class Typhoon_Eject {
                priority = 999;
                shortcut = "Eject";
                displayName = "Eject";
                condition = "player in this && {speed this > 1}";
                statement = "[this] spawn bis_fnc_planeEjection";
                position = "pilotcontrol";
                radius = 10;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
            };
            // Formation light strips: the model's lit (green, emissive) and unlit strip faces swap.
            class Typhoon_FormationLightsOn {
                priority = 1;
                displayName = "Formation lights on";
                condition = "player == driver this && {this animationPhase 'night_marker' > 0.5}";
                statement = "this animate ['night_marker', 0, true]; this animate ['night_marker_off', 1, true]";
                position = "pilotcontrol";
                radius = 10;
                onlyforplayer = 1;
                showWindow = 0;
                hideOnUse = 1;
            };
            class Typhoon_FormationLightsOff: Typhoon_FormationLightsOn {
                displayName = "Formation lights off";
                condition = "player == driver this && {this animationPhase 'night_marker' < 0.5}";
                statement = "this animate ['night_marker', 1, true]; this animate ['night_marker_off', 0, true]";
            };
        };
        class EjectionSystem {
            EjectionSeatEnabled = 1;
            EjectionDual = 0;
            EjectionSeatClass = "B_Ejection_Seat_Plane_Fighter_01_F";
            CanopyClass = "";
            canopyExplodes = 1;
            CanopyHideAnim = "";
            CanopyPos = "";
            // The model's own seat animation both hides the seat and stands in for the rail motion.
            EjectionSeatHideAnim = "ejectionSeat";
            EjectionSeatRailAnim = "ejectionSeat";
            EjectionSeatPos = "pos_eject";
            EjectionSoundExt = "Plane_Fighter_01_ejection_ext_sound";
            EjectionSoundInt = "Plane_Fighter_01_ejection_in_sound";
            EjectionSeatForce = 50;
            CanopyForce = 30;
            EjectionParachute = "NonSteerable_Parachute_F";
        };

#include "vehicle\Systems.hpp"

        class Components : Components {
#include "vehicle\Pylons.hpp"
#include "vehicle\Sensors.hpp"
#include "vehicle\Displays.hpp"
        };
    };
    class GVAR(raf) : GVAR(base) {
        scope = 2;
        scopeCurator = 2;
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\camo_upper_co.paa),
            QPATHTOF(data\camo_lower_co.paa),
            QPATHTOF(data\camo_pilot_co.paa),
            QPATHTOF(data\camo_upper_co.paa),
            QPATHTOF(data\camo_upper_co.paa),
            "",
            "\EAWS_EF2000\data\su35_engine_empty_ca.paa",
            "\EAWS_EF2000\data\su35_engine_empty_ca.paa"
        };
        hiddenSelectionsMaterials[] = {
            QPATHTOF(data\camo_upper.rvmat),
            QPATHTOF(data\camo_lower.rvmat),
            QPATHTOF(data\camo_pilot.rvmat),
            QPATHTOF(data\camo_upper.rvmat),
            QPATHTOF(data\camo_upper.rvmat)
        };
    };

#include "vehicle\Hidden.hpp"
};
