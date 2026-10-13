class CUP_412_01_base_F : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets;
};
class CUP_412_Civ_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Luxury_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Medic_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Mil_Transport_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Mil_Utility_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_412_Military_Radar_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_412_Police_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_412_Military_Armed_Base_F : CUP_412_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_412_dynamicLoadout_Base_F : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_412_Military_Armed_AT_Base_F : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_B_412_dynamicLoadout_HIL : CUP_412_dynamicLoadout_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_412_Mil_Utility_HIL : CUP_412_Mil_Utility_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_412_Military_Armed_HIL : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_412_Military_Radar_HIL : CUP_412_Military_Radar_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_C_412_Sheriff : CUP_412_Police_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_C_IDAP_412_Utility : CUP_412_Mil_Utility_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_412_dynamicLoadout_AAF : CUP_412_dynamicLoadout_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_I_412_dynamicLoadout_PMC : CUP_412_dynamicLoadout_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_I_412_Mil_Utility_AAF : CUP_412_Mil_Utility_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_412_Mil_Utility_PMC : CUP_412_Mil_Utility_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_412_Military_Armed_AAF : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_I_412_Military_Armed_AT_AAF : CUP_412_Military_Armed_AT_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_I_412_Military_Radar_AAF : CUP_412_Military_Radar_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_412_Military_Radar_PMC : CUP_412_Military_Radar_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_412_Military_Armed_AT_HIL : CUP_412_Military_Armed_AT_Base_F {};
class CUP_I_412_Military_Armed_AT_PMC : CUP_412_Military_Armed_AT_Base_F {};
class uksf_cdf_CH146_AT : CUP_I_412_Military_Armed_AT_PMC {};
class CUP_I_412_Military_Armed_PMC : CUP_412_Military_Armed_Base_F {};
class uksf_cdf_CH146_Armed : CUP_I_412_Military_Armed_PMC {};
class uksf_cdf_CH146_Armed_Woodland : uksf_cdf_CH146_Armed {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class uksf_cdf_CH146_AT_Woodland : uksf_cdf_CH146_AT {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class uksf_vaf_CH_54_Armed : CUP_B_412_Military_Armed_AT_HIL {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
