class UAV_01_base_F : Helicopter_Base_F {
    class Turrets;
};
class sps_black_hornet_01_Base_F : UAV_01_base_F {
    FUEL(20,30);
    maxSpeed = 30;
    epeImpulseDamageCoef = 10;
    damageEffect = "";
    destrType = "";
    dustEffect = "";
    waterEffect = "";
    washDownDiameter = 0;
    washDownStrength = 0;
    ace_tagging_canTag = 0;
    acre_hasInfantryPhone = 0;
    EGVAR(slingloading,supported) = 0;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class sps_black_hornet_01_F : sps_black_hornet_01_Base_F {
    faction = "CUP_B_GB";
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            weapons[] = { "Laserdesignator_mounted_blank" };
            magazines[] = { "Laserbatteries" };
        };
    };
};
class sps_black_hornet_01_F_laser : sps_black_hornet_01_Base_F {
    faction = "CUP_B_GB";
    displayName = "Black Hornet (Laser)";
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            weapons[] = { "Laserdesignator_mounted_blank" };
            magazines[] = { "Laserbatteries" };
        };
    };
};
