class CfgVehicles {
    class Helicopter;
    class Helicopter_Base_F : Helicopter {
        class Turrets;
    };
    class Heli_Attack_01_base_F : Helicopter_Base_F {
        class Turrets : Turrets {
            class MainTurret;
        };
        class CargoTurret;
    };
    class EGVAR(apache,base) : Heli_Attack_01_base_F {
        class AcreIntercoms {
            class Intercom_1 {
                displayName = "Crew intercom";
                shortName = "Crew";
                allowedPositions[] = { "crew" };
                disabledPositions[] = { { "ffv", "all" } };
                limitedPositions[] = {};
                numLimitedPositions = 0;
                masterPositions[] = { "driver" };
                connectedByDefault = 1;
            };
        };
        class ACRE {
            class attenuation {
                class Compartment1 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
                class Compartment2 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
                class Compartment3 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
                class Compartment4 {
                    Compartment1 = 1;
                    Compartment2 = 1;
                    Compartment3 = 1;
                    Compartment4 = 1;
                };
            };
        };
        attenuationEffectType = "ThickGlassAttenuation";
        class Turrets : Turrets {
            class MainTurret : MainTurret {
                soundAttenuationTurret = "ThickGlassAttenuation";
            };
            class CargoTurret_01 : CargoTurret {
                disableSoundAttenuation = 1;
            };
            class CargoTurret_02 : CargoTurret_01 {};
        };
        RACKS_AIR_FOUR;
    };
    class Plane_Base_F;
    class EGVAR(c130,base) : Plane_Base_F {
        INTERCOM_AIR;
        RACKS_AIR;
    };
    class Plane_Fighter_01_Base_F;
    class EGVAR(f35,base) : Plane_Fighter_01_Base_F {
        RACKS_AIR;
    };
    class Helicopter_Base_H;
    class CUP_CH47F_base : Helicopter_Base_H {
        INTERCOM_AIR;
        RACKS_AIR;
    };
    class Heli_Transport_02_base_F;
    class UK3CB_BAF_Merlin_Base : Heli_Transport_02_base_F {
        INTERCOM_AIR;
        RACKS_AIR;
    };
    class Heli_light_03_base_F;
    class UK3CB_BAF_Wildcat_Base : Heli_light_03_base_F {
        INTERCOM_AIR;
        RACKS_AIR;
    };
    class rksla3_aw159_base;
    class rksla3_aw159_hma2 : rksla3_aw159_base {
        INTERCOM_AIR;
        RACKS_AIR;
    };
    class rksla3_pumahc_base : Helicopter_Base_H {
        INTERCOM_AIR;
        RACKS_AIR;
    };
};
