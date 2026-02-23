class GVAR(penetrator_hellfire) : ammo_Penetrator_Base {
    caliber = 80;
    warheadName = "TandemHEAT";
    hit = 7500;
};
class ACE_Hellfire_AGM114K : M_Scalpel_AT {
    hit = 450;  // 150 (javelin 350)
    submunitionAmmo = QGVAR(penetrator_hellfire);
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet", "JPEX_Big_Debris_SoundSet" };
    model = "\rksla3\rksla3-cvwp\agm\rksl_agm114k_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\agm\rksl_agm114k_proxy.p3d";
    ace_rearm_dummy = QGVAR(ACE_Hellfire_AGM114);
    effectsMissileInit = "PylonBackEffects";
    class ace_missileguidance;
};

class ACE_Hellfire_AGM114K_drone : ACE_Hellfire_AGM114K {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
        seekerAngle = 175;
    };
};
class ACE_Hellfire_AGM114N : ACE_Hellfire_AGM114K {
    class ace_missileguidance;
};
class ACE_Hellfire_AGM114N_drone : ACE_Hellfire_AGM114N {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
        seekerAngle = 175;
    };
};
class ACE_Hellfire_AGM114L : ACE_Hellfire_AGM114K {
    model = "\rksla3\rksla3-cvwp\agm\rksl_agm114l_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\agm\rksl_agm114l_proxy.p3d";
    class ace_missileguidance : ace_missileguidance {};
};
class ACE_Hellfire_AGM114R9X : ACE_Hellfire_AGM114K {
    displayName = "AGM-114R9X";
    displayNameShort = "AGM-114R9X";
    description = "AGM-114R9X";
    descriptionShort = "AGM-114R9X";
    model = "\rksla3\rksla3-cvwp\agm\rksl_agm114r9x_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\agm\rksl_agm114r9x_proxy.p3d";
    hit = 175;
    indirectHit = 2;
    indirectHitRange = 1;
    warheadName = "";
    submunitionAmmo = "";
    explosionEffects = QGVAR(R9X_Impact);
    SoundSetExplosion[] = { "jsrs_2025_shell_blunt_hit_soundset" };
    class ace_missileguidance;
};
class ACE_Hellfire_AGM114R9X_drone : ACE_Hellfire_AGM114R9X {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
        seekerAngle = 175;
    };
};
