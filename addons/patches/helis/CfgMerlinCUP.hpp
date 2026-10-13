class CUP_Merlin_HC3_Base : Helicopter_Base_H {
    class AnimationSources;
};
class CUP_Merlin_HC3_Lux_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class addgunholder {
            source = "user";
            animPeriod = 1e-06;
            initPhase = 0;
        };
        class dvere_l {
            source = "door";
            animPeriod = 1.3;
            initPhase = 0;
        };
        class dvere_p {
            source = "door";
            animPeriod = 1.3;
            initPhase = 0;
        };
        class hide_radar {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class hidepipmfdco {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class hidepipmfdpi {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class rampa {
            source = "door";
            animPeriod = 6;
            initPhase = 0;
        };
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class winchsection2 {
            source = "user";
            initPhase = 0;
        };
    };
};
class CUP_Merlin_HC3_VIV_Base : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_Merlin_HM2_Base : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_Merlin_Rescue_Base : Helicopter_Base_H {
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret : MainTurret {
            class HitPoints {};
        };
        class LoadmasterTurret : MainTurret {
            class HitPoints {};
        };
    };
    class AnimationSources;
};
class CUP_B_Merlin_HC3_GB : CUP_Merlin_HC3_Base {
    HIDE;
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_C_Merlin_HC3_CIV_Rescue : CUP_Merlin_Rescue_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_C_Merlin_HC3_IDAP_Rescue : CUP_Merlin_Rescue_Base {
    class Components;
    class Turrets : Turrets {
        class CopilotTurret;
    };
    class AnimationSources : AnimationSources {
        class flir_gun {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class flir_turret {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_Merlin_HC3A_Base : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_Merlin_HC3_Armed_Base : CUP_Merlin_HC3_Base {
    class Turrets;
};
class CUP_Merlin_HC3A_Armed_Base : CUP_Merlin_HC3_Armed_Base {};
class CUP_B_Merlin_HC3_Armed_GB : CUP_Merlin_HC3_Armed_Base {
    HIDE;
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_Merlin_HC3_GB_Armed : CUP_B_Merlin_HC3_Armed_GB {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_Merlin_HC3A_Armed_GB : CUP_Merlin_HC3A_Armed_Base {
    HIDE;
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_Merlin_HC3A_GB_Armed : CUP_B_Merlin_HC3A_Armed_GB {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
HIDE_CLASS(CUP_B_Merlin_HC3_VIV_GB,CUP_Merlin_HC3_VIV_Base);
HIDE_CLASS(CUP_B_Merlin_HC3A_GB,CUP_Merlin_HC3A_Base);
HIDE_CLASS(CUP_B_Merlin_HC4_GB,CUP_Merlin_HM2_Base);
