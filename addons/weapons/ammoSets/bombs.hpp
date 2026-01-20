
class ammo_Bomb_LaserGuidedBase : LaserBombCore {
    hit = 10000; // 5000
    indirectHit = 2000; // 1100
    indirectHitRange = 20;  // 12
};
class Bo_GBU12_LGB : ammo_Bomb_LaserGuidedBase {
    model = "\A3\Weapons_F_EPC\Ammo\Bomb_04_fly_F";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Bomb_04_F";
};
class CUP_Bo_GBU12_LGB : Bo_GBU12_LGB {
    model = "\A3\Weapons_F_EPC\Ammo\Bomb_04_fly_F";
    proxyShape = "\A3\Weapons_F_EPC\Ammo\Bomb_04_F";
};
class ammo_Bomb_SmallDiameterBase : ammo_Bomb_LaserGuidedBase {
    hit = 4000; // 1800
    indirectHit = 200; // 85
    indirectHitRange = 6;  // 3
};
class ammo_Bomb_SDB : ammo_Bomb_SmallDiameterBase {
    ace_rearm_dummy = QGVAR(ammo_Bomb_SDB);
};
