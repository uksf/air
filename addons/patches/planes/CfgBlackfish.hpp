class VTOL_01_base_F : VTOL_Base_F {
    class Turrets;
};
class VTOL_01_armed_base_F : VTOL_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class GunnerTurret_01;
        class GunnerTurret_02;
    };
};
class B_T_VTOL_01_armed_F : VTOL_01_armed_base_F {};
class B_T_VTOL_01_armed_blue_F : B_T_VTOL_01_armed_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class GunnerTurret_01 : GunnerTurret_01 {
            class HitPoints {};
        };
        class GunnerTurret_02 : GunnerTurret_02 {
            class HitPoints {};
        };
    };
};
class B_T_VTOL_01_armed_olive_F : B_T_VTOL_01_armed_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class GunnerTurret_01 : GunnerTurret_01 {
            class HitPoints {};
        };
        class GunnerTurret_02 : GunnerTurret_02 {
            class HitPoints {};
        };
    };
};
