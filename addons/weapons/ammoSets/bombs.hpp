class ammo_Bomb_LaserGuidedBase : LaserBombCore {
    hit = 10000; // 5000
    indirectHit = 2000; // 1100
    indirectHitRange = 20;  // 12
};
class Bo_GBU12_LGB : ammo_Bomb_LaserGuidedBase {
    model = "\rksla3\rksla3-cvwp\bombs\rksl_uk_pw4_500_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\bombs\rksl_uk_pw4_500_proxy.p3d";
};
class CUP_Bo_GBU12_LGB : Bo_GBU12_LGB {
    model = "\rksla3\rksla3-cvwp\bombs\rksl_uk_pw4_500_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\bombs\rksl_uk_pw4_500_proxy.p3d";
};
class ammo_Bomb_SmallDiameterBase : ammo_Bomb_LaserGuidedBase {
    hit = 4000; // 1800
    indirectHit = 200; // 85
    indirectHitRange = 6;  // 3
};
class ammo_Bomb_SDB : ammo_Bomb_SmallDiameterBase {
    ace_rearm_dummy = QGVAR(ammo_Bomb_SDB);
};
