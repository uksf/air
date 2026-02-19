class ace_hellfire_launcher : RocketPods {
    displayName = "AGM-114K";
};
class ace_hellfire_launcher_N : ace_hellfire_launcher {
    displayName = "AGM-114N";
};
class ace_hellfire_launcher_drone : ace_hellfire_launcher {
    magazines[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone" };
};
class ace_hellfire_launcher_drone_N : ace_hellfire_launcher_N {
    magazines[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone" };
};
class ace_hellfire_launcher_L : ace_hellfire_launcher {
    displayName = "AGM-114L";
};
class ace_hellfire_launcher_R9X : ace_hellfire_launcher {
    displayName = "AGM-114R9X";
    magazines[] = { "PylonRack_4Rnd_ACE_Hellfire_AGM114R9X" };
};
class ace_hellfire_launcher_drone_R9X : ace_hellfire_launcher_R9X {
    magazines[] = { "PylonRack_2Rnd_ACE_Hellfire_AGM114R9X_Drone" };
};
