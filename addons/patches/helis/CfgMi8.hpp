class CUP_Mi8_base : Helicopter_Base_H {
    class Turrets : Turrets {
        class MainTurret;
        class BackTurret;
        class CopilotTurret;
    };
};
class CUP_Mi171Sh_Base : CUP_Mi8_base {
    class Turrets : Turrets {
        class LeftTurret;
        class BackTurret;
        class RightTurret;
        class CopilotTurret;
    };
};
class CUP_B_Mi171Sh_ACR : CUP_Mi171Sh_Base {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_Mi171Sh_AFU : CUP_Mi171Sh_Base {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_Mi171Sh_CDF : CUP_Mi171Sh_Base {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_Mi17_AFU : CUP_Mi8_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_Mi17_CDF : CUP_Mi8_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_Mi17_UN : CUP_Mi8_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_Mi8_MTV3_base : CUP_Mi8_base {
    class Turrets : Turrets {
        class SideTurret;
        class BackTurret;
        class FrontTurret;
        class CopilotTurret;
    };
};
class CUP_O_Mi17_TK : CUP_Mi8_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Mi8_CHDKZ : CUP_Mi8_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Mi8_RU : CUP_Mi8_MTV3_base {
    class Turrets : Turrets {
        class SideTurret : SideTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class FrontTurret : FrontTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Mi8_SLA_1 : CUP_Mi8_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Mi8_SLA_2 : CUP_Mi8_MTV3_base {
    class Turrets : Turrets {
        class SideTurret : SideTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class FrontTurret : FrontTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Mi8AMT_RU : CUP_Mi8_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_Mi171Sh_Unarmed_Base : CUP_Mi171Sh_Base {};
class CUP_B_Mi171Sh_Unarmed_ACR : CUP_Mi171Sh_Unarmed_Base {};
class uksf_acr_Mi17 : CUP_B_Mi171Sh_Unarmed_ACR {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
