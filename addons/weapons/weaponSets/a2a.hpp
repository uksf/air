class ace_missile_aim9_aim132 : missiles_ASRAAM {
    displayName = "AIM-132";
    magazines[] = {
        "ace_missile_aim9_aim132_2Rnd",
        "ace_missile_aim9_aim132_2Rnd_MI02",
        "ace_missile_aim9_aim132_2Rnd_MI06",
        "ace_missile_aim9_aim132_4Rnd",
        "ace_missile_aim9_aim132_4Rnd_MI02",
        "ace_missile_aim9_PylonRack_1Rnd_aim132",
        "ace_missile_aim9_PylonMissile_1Rnd_aim132",
        "ace_missile_aim9_PylonRack_aim132_x1",
        "ace_missile_aim9_PylonRack_aim132_x2"
    };
};
class ace_missile_aim120_aim120Launcher : weapon_AMRAAMLauncher {
    displayName = "AIM-120D";
    class Direct : MissileLauncher {
        displayName = "Direct";
        textureType = "semi";
    };
    class Loft : Direct {
        displayName = "Loft";
        textureType = "LOFT";
    };
};
