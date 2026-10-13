class CUP_Ka52_Base : Helicopter_Base_H {
    class Turrets;
};
class CUP_Ka52_Dynamic_Base : CUP_Ka52_Base {
    class Turrets : Turrets {
        class MainTurret;
        class SecondaryTurret;
    };
};
class CUP_O_Ka52_Blk_RU : CUP_Ka52_Dynamic_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SecondaryTurret : SecondaryTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Ka52_Grey_RU : CUP_Ka52_Dynamic_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SecondaryTurret : SecondaryTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Ka52_GreyCamo_RU : CUP_Ka52_Dynamic_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SecondaryTurret : SecondaryTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_Ka52_RU : CUP_Ka52_Dynamic_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SecondaryTurret : SecondaryTurret {
            class HitPoints {};
        };
    };
};
