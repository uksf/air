class ace_gbu_PylonMissile_Bomb_GBU12_x1 : PylonMissile_Bomb_GBU12_x1 {
    displayName = "GBU-12 x1";
    hardpoints[] += { "B_GBU12_ACE_Only" };
};
class ace_gbu_PylonMissile_Bomb_GBU12_x1_Drone : ace_gbu_PylonMissile_Bomb_GBU12_x1 {
    model = "\A3\Weapons_F\DynamicLoadout\PylonMissile_1x_Bomb_04_F.p3d";
    hardpoints[] = { "B_GBU12_ACE_DRONE" };
};
class ace_gbu_PylonRack_Bomb_GBU12_x2 : PylonRack_Bomb_GBU12_x2 {
    displayName = "GBU-12 x2";
    hardpoints[] += { "B_GBU12_DUAL_RAIL_ACE_Only" };
};
class ace_sdb_PylonRack_bomb_SDB_x4 : PylonRack_Bomb_SDB_x4 {
    displayName = "GBU-39 x4";
    hardpoints[] += { "B_GBU39_ACE_Only" };
};
