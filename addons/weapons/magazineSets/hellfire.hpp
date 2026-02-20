class PylonMissile_1Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114K x1";
    // hardpoints[] = { "SCALPEL_1RND" };
};
class PylonRack_1Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114K x1";
    // hardpoints[] = { "B_MISSILE_PYLON", "SCALPEL_1RND_EJECTOR", "B_ASRRAM_EJECTOR", "UNI_SCALPEL" };
};
class PylonRack_3Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114K x3";
    // hardpoints[] = { "B_MISSILE_PYLON", "UNI_SCALPEL" };
};
class PylonRack_4Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114K x4";
    model = "\rksla3\rksla3-cvwp\racks\rksla3_m299_4_rack.p3d";
    hardpoints[] += { "B_HELLFIRE" };
};
class PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114K x2";
    ammo = "ACE_Hellfire_AGM114K_drone";
    model = "\rksla3\rksla3-cvwp\racks\rksla3_m310_2_rack.p3d";
    count = 2;
    mass = 170;
    pylonWeapon = "ace_hellfire_launcher_drone";
    hardpoints[] = { "B_HELLFIRE_DRONE" };
};

// Hellfire N
class PylonRack_4Rnd_ACE_Hellfire_AGM114N : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114N x4";
};
class PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114N {
    displayName = "AGM-114N x2";
    ammo = "ACE_Hellfire_AGM114N_drone";
    model = "\rksla3\rksla3-cvwp\racks\rksla3_m310_2_rack.p3d";
    count = 2;
    mass = 170;
    pylonWeapon = "ace_hellfire_launcher_drone_N";
    hardpoints[] = { "B_HELLFIRE_DRONE" };
};

// Hellfire L
class PylonRack_4Rnd_ACE_Hellfire_AGM114L : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114L x4";
};

// Hellfire R9X
class PylonRack_4Rnd_ACE_Hellfire_AGM114R9X : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114R9X x4";
    ammo = "ACE_Hellfire_AGM114R9X";
    pylonWeapon = "ace_hellfire_launcher_R9X";
};
class PylonRack_2Rnd_ACE_Hellfire_AGM114R9X_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114R9X {
    displayName = "AGM-114R9X x2";
    ammo = "ACE_Hellfire_AGM114R9X_drone";
    model = "\rksla3\rksla3-cvwp\racks\rksla3_m310_2_rack.p3d";
    count = 2;
    mass = 170;
    pylonWeapon = "ace_hellfire_launcher_drone_R9X";
    hardpoints[] = { "B_HELLFIRE_DRONE" };
};
