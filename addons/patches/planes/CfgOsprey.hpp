class CUP_B_MV22_USMC : Plane_Base_F {
    class AnimationSources;
    class Turrets : Turrets {
        class CopilotTurret;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_B_MV22_USMC_RAMPGUN : CUP_B_MV22_USMC {
    class AnimationSources : AnimationSources {
        class gatling_2 {
            source = "revolving";
            weapon = "CUP_Vlmg_M240_veh";
        };
        class gatling_2_muzzle_rot {
            source = "ammorandom";
            weapon = "CUP_Vlmg_M240_veh";
        };
    };
    class Turrets : Turrets {
        class RightDoorGun;
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
