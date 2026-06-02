// Root-scope sensor templates (required for `: SensorTemplateX` to resolve to the real engine
// template — declaring them inside CfgVehicles creates empty shadows that wipe the sensor).
class SensorTemplateIR;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class SensorTemplateNV;
class SensorTemplateLaser;

class CfgVehicles {
    class ace_rearm_defaultCarriedObject;
    class GVAR(ACE_Hellfire_AGM114): ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-cvwp\agm\rksl_agm114k_proxy.p3d";
    };
    class GVAR(crv7): ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-aw159\weapons\rksla3_crv7_m151_fired.p3d";
    };
    class GVAR(ammo_Missile_BIM9X): ace_rearm_defaultCarriedObject {
        model = "\A3\Weapons_F_Jets\Ammo\Missile_AA_08_F.p3d";
    };
    class GVAR(ammo_Missile_AIM132): ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-cvwp\aam\rksl_aim132asraam_proxy.p3d";
    };
    class GVAR(ammo_Missile_AMRAAM_D): ace_rearm_defaultCarriedObject {
        model = "\A3\Weapons_F_Jets\Ammo\Missile_AA_06_fly_F.p3d";
    };
    class GVAR(ammo_Bomb_SDB): ace_rearm_defaultCarriedObject {
        model = "\A3\Weapons_F_Sams\Ammo\Bomb_05_F.p3d";
    };
    class ace_rearm_Bo_GBU12_LGB: ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-cvwp\bombs\rksl_uk_pw4_500_proxy.p3d";
    };
    class GVAR(ammo_missile_brimstone3): ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-cvwp\agm\rksl_brimstone_3_proxy.p3d";
    };
    class GVAR(ammo_missile_meteor): ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-cvwp\aam\rksl_meteor_proxy.p3d";
    };
    class GVAR(ammo_missile_spear3): ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-cvwp\stow\rksl_spear3_proxy.p3d";
    };
    class GVAR(ammo_missile_stormshadow): ace_rearm_defaultCarriedObject {
        model = "\rksla3\rksla3-cvwp\stow\rksl_stormshadow_proxy.p3d";
    };

    // ─────────────────────────────────────────────────────────────────────────
    // Air-defence engagement overhaul — enemy SAM platform air-detection sensors.
    // These IR-guided AA vehicles carry a 5-6 km missile but their platform IR sensor only sees
    // ~2.5-3 km, so the AI engages far too close. Raise the IRSensorComponent AirTarget cap to the
    // missile envelope. The full IRSensorComponent block (componentType + AirTarget + GroundTarget +
    // cone) is replicated deliberately: a bare re-open of an inherited sensor wipes GroundTarget +
    // componentType (verified via RPT). Parents are declared with their own parent + a Components
    // forward-decl so `class Components : Components` resolves to the real inherited Components.
    // ─────────────────────────────────────────────────────────────────────────
    class Car_F;
    class Helicopter_Base_H;
    class CUP_HMMWV_Base : Car_F { class Components; };
    class CUP_nHMMWV_Base : Car_F { class Components; };
    class CUP_KA50_Base : Helicopter_Base_H { class Components; };
    class CUP_B_M2Bradley_USA_D;

    // Boeing Avenger (HMMWV) FIM-92 Stinger SPAAD: IR air sensor 2500 -> 6000.
    class CUP_HMMWV_Avenger_Base : CUP_HMMWV_Base {
        irScanRangeMax = 6000;
        class Components : Components {
            class SensorsManagerComponent {
                class Components {
                    class IRSensorComponent : SensorTemplateIR {
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 45;
                        angleRangeVertical = 45;
                        typeRecognitionDistance = 1500;
                        groundNoiseDistanceCoef = -1;
                        class AirTarget { minRange = 250; maxRange = 6000; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                        class GroundTarget { minRange = 250; maxRange = 2000; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                    };
                };
            };
        };
    };

    // Avenger on the nM1097 hull (same Avenger IR turret sensor).
    class CUP_nM1097_Avenger_Base : CUP_nHMMWV_Base {
        irScanRangeMax = 6000;
        class Components : Components {
            class SensorsManagerComponent {
                class Components {
                    class IRSensorComponent : SensorTemplateIR {
                        animDirection = "MainTurret";
                        angleRangeHorizontal = 45;
                        angleRangeVertical = 45;
                        typeRecognitionDistance = 1500;
                        groundNoiseDistanceCoef = -1;
                        class AirTarget { minRange = 250; maxRange = 6000; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                        class GroundTarget { minRange = 250; maxRange = 2000; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                    };
                };
            };
        };
    };

    // Ka-50 AA gunship (9K38 Igla): IR air sensor 3000 -> 5500. The full sensor set (Visual/NV/
    // PassiveRadar/Laser) must be replicated — overriding the Components inherits an empty shell, so
    // any sensor not redeclared here is lost. Only the IR AirTarget maxRange changes; rest verbatim.
    class CUP_KA50_AA_Base : CUP_KA50_Base {
        irScanRangeMax = 5500;
        class Components : Components {
            class SensorsManagerComponent {
                class Components {
                    class IRSensorComponent : SensorTemplateIR {
                        aimDown = 0;
                        angleRangeHorizontal = 360;
                        angleRangeVertical = 360;
                        typeRecognitionDistance = 1500;
                        class AirTarget { minRange = 50; maxRange = 5500; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                        class GroundTarget { minRange = 50; maxRange = 3000; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                    };
                    class PassiveRadarComponent : SensorTemplatePassiveRadar {};
                    class VisualSensorComponent : SensorTemplateVisual {
                        aimDown = 0;
                        angleRangeHorizontal = 360;
                        angleRangeVertical = 360;
                        maxTrackableSpeed = 110;
                        typeRecognitionDistance = 1000;
                        class AirTarget { minRange = 50; maxRange = 2500; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                        class GroundTarget { minRange = 50; maxRange = 2500; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                    };
                    class NVSensorComponent : SensorTemplateNV {
                        aimDown = 0;
                        angleRangeHorizontal = 360;
                        angleRangeVertical = 360;
                        typeRecognitionDistance = 1500;
                        class AirTarget { minRange = 50; maxRange = 3000; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                        class GroundTarget { minRange = 50; maxRange = 3000; objectDistanceLimitCoef = 1; viewDistanceLimitCoef = 1; };
                    };
                    class LaserSensorComponent : SensorTemplateLaser {};
                };
            };
        };
    };

    // M6 Linebacker (Bradley + Stinger). Legacy irScan only (no AirTarget sensor block); 4.5 -> 5.5 km.
    // All faction variants (USA_W / NATO_T / AFU) inherit this root.
    class CUP_B_M6LineBacker_USA_D : CUP_B_M2Bradley_USA_D {
        irScanRangeMax = 5500;
    };
};
