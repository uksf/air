class ace_missile_aim9_PylonRack_aim132_x1 : ace_missile_aim9_PylonRack_1Rnd_aim132 {
    displayName = "ASRAAM x1";
    model = "\rksla3\rksla3-cvwp\racks\rksla3_lau127.p3d";
    hardpoints[] += { "B_AIM132_RAIL_ACE_Only" };
};
class ace_missile_aim9_PylonRack_aim132_x2 : ace_missile_aim9_PylonRack_aim132_x1 {
    displayName = "ASRAAM x2";
    count = 2;
    model = "\A3\Weapons_F_Jets\Ammo\PylonPod_Missile_AA_08_DualRail_x2_F";
    hardpoints[] = { "B_AIM132_DUAL_RAIL_ACE_Only" };
    mass = 250;
};
class ace_missile_aim120_PylonRack_Missile_d_x1 : PylonRack_Missile_AMRAAM_D_x1 {
    displayName = "AIM-120D x1";
    hardpoints[] += { "B_AMRAAM_D_RAIL_ACE_Only" };
};
class ace_missile_aim120_PylonRack_Missile_d_x2 : PylonRack_Missile_AMRAAM_D_x2 {
    displayName = "AIM-120D x2";
    hardpoints[] += { "B_AMRAAM_D_DUAL_RAIL_ACE_Only" };
};
class ace_missile_aim120_PylonMissile_Missile_d_INT_x1 : PylonMissile_Missile_AMRAAM_D_INT_x1 {
    displayName = "AIM-120D x1";
    hardpoints[] += { "B_AMRAAM_D_INT_ACE_Only" };
};
