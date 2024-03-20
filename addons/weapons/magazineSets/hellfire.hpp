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
    hardpoints[] += { "B_HELLFIRE" };
};
class PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114K x2";
    ammo = "ACE_Hellfire_AGM114K_drone";
    model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
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
    model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
    count = 2;
    mass = 170;
    pylonWeapon = "ace_hellfire_launcher_drone_N";
    hardpoints[] = { "B_HELLFIRE_DRONE" };
};

// Hellfire L
class PylonRack_4Rnd_ACE_Hellfire_AGM114L : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
    displayName = "AGM-114L x4";
};
