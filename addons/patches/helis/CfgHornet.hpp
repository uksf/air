class UAV_01_base_F;
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
};
class sps_black_hornet_01_F : sps_black_hornet_01_Base_F {
    faction = "CUP_B_GB";
};
