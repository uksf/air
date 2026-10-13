class Heli_Transport_03_base_F : Helicopter_Base_H {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class B_Heli_Transport_03_F : Heli_Transport_03_base_F {};
class B_Heli_Transport_03_black_F : B_Heli_Transport_03_F {
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
    };
};
class Heli_Transport_03_unarmed_base_F : Heli_Transport_03_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class B_Heli_Transport_03_unarmed_F : Heli_Transport_03_unarmed_base_F {};
class B_Heli_Transport_03_unarmed_green_F : B_Heli_Transport_03_unarmed_F {
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
    };
};
