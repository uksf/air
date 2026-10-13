class Heli_Transport_04_base_F : Helicopter_Base_H {
    class Turrets : Turrets {
        class CopilotTurret;
        class LoadmasterTurret;
    };
};
class O_Heli_Transport_04_repair_F : Heli_Transport_04_base_F {};
class O_Heli_Transport_04_medevac_F : Heli_Transport_04_base_F {};
class O_Heli_Transport_04_fuel_F : Heli_Transport_04_base_F {};
class O_Heli_Transport_04_box_F : Heli_Transport_04_base_F {};
class O_Heli_Transport_04_F : Heli_Transport_04_base_F {};
class O_Heli_Transport_04_ammo_F : Heli_Transport_04_base_F {};
class O_Heli_Transport_04_ammo_black_F : O_Heli_Transport_04_ammo_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
    };
};
class O_Heli_Transport_04_bench_F : Heli_Transport_04_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoTurret_07;
        class CargoTurret_08;
    };
};
class O_Heli_Transport_04_black_F : O_Heli_Transport_04_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
    };
};
class O_Heli_Transport_04_box_black_F : O_Heli_Transport_04_box_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
    };
};
class O_Heli_Transport_04_covered_F : Heli_Transport_04_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class O_Heli_Transport_04_fuel_black_F : O_Heli_Transport_04_fuel_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
    };
};
class O_Heli_Transport_04_medevac_black_F : O_Heli_Transport_04_medevac_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
    };
};
class O_Heli_Transport_04_repair_black_F : O_Heli_Transport_04_repair_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LoadmasterTurret : LoadmasterTurret {
            class HitPoints {};
        };
    };
};
