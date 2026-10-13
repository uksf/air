class CUP_MH60S_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_Uh60_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class pylons_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_Uh60L_Base : CUP_Uh60_Base {};
class CUP_UH60_Unarmed_Base : CUP_Uh60_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_Uh60S_Base : CUP_Uh60_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class pylons_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_Uh60_Unarmed_FFV_Base : CUP_UH60_Unarmed_Base {
    class AnimationSources;
};
class CUP_MH60S_Unarmed_FFV_Base : CUP_Uh60_Unarmed_FFV_Base {};
class CUP_MH60S_Unarmed_FFV_USN : CUP_MH60S_Unarmed_FFV_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_MH60S_Unarmed_USN : CUP_UH60_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_MH60L_Dap_4x_Base : CUP_Uh60_Base {
    class Turrets;
};
class CUP_MH60L_Dap_2x_Base : CUP_MH60L_Dap_4x_Base {
    class Turrets;
};
class CUP_MH60L_Dap_2x_AT_Base : CUP_MH60L_Dap_2x_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_2x_AT_US : CUP_MH60L_Dap_2x_AT_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_MH60L_DAP_2x_AT_USN : CUP_MH60L_Dap_2x_AT_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_MH60L_Dap_2x_Escort_Base : CUP_MH60L_Dap_2x_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_2x_Escort_US : CUP_MH60L_Dap_2x_Escort_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_MH60L_DAP_2x_Escort_USN : CUP_MH60L_Dap_2x_Escort_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_MH60L_Dap_2x_Multi_Base : CUP_MH60L_Dap_2x_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_2x_Multi_US : CUP_MH60L_Dap_2x_Multi_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_MH60L_DAP_2x_Multi_USN : CUP_MH60L_Dap_2x_Multi_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_MH60L_Dap_2x_Dynamic_Base : CUP_Uh60_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_2x_US : CUP_MH60L_Dap_2x_Dynamic_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_UH60S_Dap_2x_Dynamic_Base : CUP_Uh60S_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_2x_USN : CUP_UH60S_Dap_2x_Dynamic_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_MH60L_Dap_4x_AT_Base : CUP_MH60L_Dap_4x_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_4x_AT_US : CUP_MH60L_Dap_4x_AT_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_MH60L_DAP_4x_AT_USN : CUP_MH60L_Dap_4x_AT_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_MH60L_Dap_4x_Escort_Base : CUP_MH60L_Dap_4x_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_4x_Escort_US : CUP_MH60L_Dap_4x_Escort_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_MH60L_DAP_4x_Escort_USN : CUP_MH60L_Dap_4x_Escort_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_MH60L_Dap_4x_Multi_Base : CUP_MH60L_Dap_4x_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_4x_Multi_US : CUP_MH60L_Dap_4x_Multi_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_MH60L_DAP_4x_Multi_USN : CUP_MH60L_Dap_4x_Multi_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_UH60S_Dap_4x_Dynamic_Base : CUP_Uh60S_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_B_MH60L_DAP_4x_USN : CUP_UH60S_Dap_4x_Dynamic_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_MH60S_FFV_Base : CUP_MH60S_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_MH60S_FFV_USMC : CUP_MH60S_FFV_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_MH60S_USMC : CUP_MH60S_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_Uh60_FFV_Base : CUP_Uh60_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_Uh60L_FFV_Base : CUP_Uh60_FFV_Base {};
class CUP_B_UH60L_FFV_US : CUP_Uh60L_FFV_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_UH60L_US : CUP_Uh60L_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_UH60M_US : CUP_Uh60_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_B_UH60S_USN : CUP_Uh60S_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
class CUP_I_UH60L_FFV_RACS : CUP_Uh60L_FFV_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_I_UH60L_RACS : CUP_Uh60L_Base {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
    };
};
