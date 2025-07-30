class GX_DRONE40_UAV_BASE : Helicopter_Base_F {
    destrType = "";
    class Turrets: Turrets {
        class MainTurret;
    };
    EGVAR(slingloading,supported) = 0;
};
class GX_DRONE40_UAV_RECON : GX_DRONE40_UAV_BASE {
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            weapons[] = {};
            magazines[] = {};
        };
    };
};
class GX_BLACK_HORNET_UAV_BASE : Helicopter_Base_F {
    destrType = "";
    class DestructionEffects {};
    EGVAR(slingloading,supported) = 0;
};
