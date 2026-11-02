#define THREAT_WARNING \
    GVAR(enabled) = 1; \
    incomingMissileDetectionSystem = 63; \
    soundLocked[] = { SOUND(silence), 0, 1 }; \
    soundIncommingMissile[] = { SOUND(silence), 0, 1 }

class CfgVehicles {
    class Helicopter_Base_H;
    class Heli_light_03_base_F;
    class Heli_Transport_02_base_F;
    class Plane_Base_F;
    class Plane_Fighter_01_Base_F;
    class EAWS_EF2000;
    class UK3CB_BAF_Apache_AH1_Generic;

    class EGVAR(apache,base) : UK3CB_BAF_Apache_AH1_Generic {
        THREAT_WARNING;
        GVAR(flightTurrets)[] = { { 0 } };
    };
    class UK3CB_BAF_Wildcat_Base : Heli_light_03_base_F {
        THREAT_WARNING;
    };
    class CUP_AW159_Unarmed_Base : Helicopter_Base_H {
        THREAT_WARNING;
    };
    class UK3CB_BAF_Merlin_Base : Heli_Transport_02_base_F {
        THREAT_WARNING;
    };
    class CUP_Merlin_HC3_Base : Helicopter_Base_H {
        THREAT_WARNING;
    };
    class CUP_CH47F_base : Helicopter_Base_H {
        THREAT_WARNING;
    };
    class rksla3_pumahc_base : Helicopter_Base_H {
        THREAT_WARNING;
    };
    class EGVAR(c130,base) : Plane_Base_F {
        THREAT_WARNING;
    };
    class A400M_base_F : Plane_Base_F {
        THREAT_WARNING;
    };
    class EGVAR(f35,base) : Plane_Fighter_01_Base_F {
        THREAT_WARNING;
    };
    class EGVAR(typhoon,base) : EAWS_EF2000 {
        THREAT_WARNING;
    };
};
