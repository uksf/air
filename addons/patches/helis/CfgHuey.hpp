class CUP_UH1H_base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class side_door_extension_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class RightDoorGun;
        class LeftDoorGun;
        class CopilotTurret;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_UH1H_gunship_base : CUP_UH1H_base {};
class CUP_O_UH1H_gunship_TKA : CUP_UH1H_gunship_base {};
class CUP_UH1H_armed_base : CUP_UH1H_base {};
class CUP_B_UH1D_armed_GER_KSK : CUP_UH1H_armed_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_B_UH1D_armed_GER_KSK_Des : CUP_UH1H_armed_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_B_UH1D_GER_KSK : CUP_UH1H_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_B_UH1D_GER_KSK_Des : CUP_UH1H_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_B_UH1D_gunship_GER_KSK : CUP_UH1H_gunship_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_B_UH1D_gunship_GER_KSK_Des : CUP_UH1H_gunship_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_UH1H_slick_base : CUP_UH1H_base {
    class Turrets : Turrets {
        class RightDoorGun;
        class LeftDoorGun;
        class CopilotTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_UH1D_slick_GER_KSK : CUP_UH1H_slick_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_UH1D_slick_GER_KSK_Des : CUP_UH1H_slick_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_UH1Y_Base : Helicopter_Base_H {
    class Turrets;
};
class CUP_B_UH1Y_GUNSHIP_USMC : CUP_B_UH1Y_Base {
    class Turrets : Turrets {
        class MainTurret;
        class RightDoorGun : MainTurret {
            class HitPoints {};
        };
        class CoPilotObs : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_UH1H_Armed_RACS : CUP_UH1H_armed_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_I_UH1H_armed_TK_GUE : CUP_UH1H_armed_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_I_UH1H_gunship_RACS : CUP_UH1H_gunship_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_I_UH1H_gunship_TK_GUE : CUP_UH1H_gunship_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_I_UH1H_RACS : CUP_UH1H_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_I_UH1H_Slick_RACS : CUP_UH1H_slick_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_I_UH1H_slick_TK_GUE : CUP_UH1H_slick_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_I_UH1H_TK_GUE : CUP_UH1H_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_O_UH1H_armed_SLA : CUP_UH1H_armed_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_O_UH1H_armed_TKA : CUP_UH1H_armed_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_O_UH1H_gunship_SLA : CUP_UH1H_gunship_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_O_UH1H_gunship_SLA_TKA : CUP_O_UH1H_gunship_TKA {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_O_UH1H_SLA : CUP_UH1H_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
class CUP_O_UH1H_slick_SLA : CUP_UH1H_slick_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_O_UH1H_slick_TKA : CUP_UH1H_slick_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_O_UH1H_TKA : CUP_UH1H_base {
    class Turrets : Turrets {
        class RightDoorGun : RightDoorGun {};
        class LeftDoorGun : LeftDoorGun {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
    };
};
