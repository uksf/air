class CUP_Ka60_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class reloadanim {
            source = "reload";
            weapon = "CUP_M32_heli";
        };
        class revolving {
            source = "revolving";
            weapon = "CUP_M32_heli";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class CopilotTurret;
    };
};
class CUP_Ka60_GL_BASE : CUP_Ka60_Base {};
class CUP_I_Ka60_GL_Blk_ION : CUP_Ka60_GL_BASE {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_Ka60_GL_Digi_AAF : CUP_Ka60_GL_BASE {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Ka60_GL_Blk_CSAT : CUP_Ka60_GL_BASE {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Ka60_GL_Hex_CSAT : CUP_Ka60_GL_BASE {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Ka60_GL_Whale_CSAT : CUP_Ka60_GL_BASE {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
