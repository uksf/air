class GVAR(penetrator_hellfire_stage2) : ammo_Penetrator_Base {
    caliber = 80;
    warheadName = "HEAT";
    hit = 7500;
};
class GVAR(penetrator_hellfire_stage1) : GVAR(penetrator_hellfire_stage2) {
    warheadName = "TandemHEAT";
    submunitionAmmo = QGVAR(penetrator_hellfire_stage2);
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionInitSpeed = 1000;
    submunitionParentSpeedCoef = 0;
    submunitionInitialOffset[] = { 0, 0, -0.4 };
    triggerOnImpact = 1;
    deleteParentWhenTriggered = 0;
};
class ACE_Hellfire_AGM114K : M_Scalpel_AT {
    hit = 450;  // 150 (javelin 350)
    submunitionAmmo = QGVAR(penetrator_hellfire_stage1);
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
        seekerAngle = 350;
    };
};
class ACE_Hellfire_AGM114N : ACE_Hellfire_AGM114K {
    class ace_missileguidance;
};
class ACE_Hellfire_AGM114N_drone : ACE_Hellfire_AGM114N {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
        seekerAngle = 350;
    };
};
class ACE_Hellfire_AGM114L : ACE_Hellfire_AGM114K {
    model = "\rksla3\rksla3-cvwp\agm\rksl_agm114l_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\agm\rksl_agm114l_proxy.p3d";
    class ace_missileguidance : ace_missileguidance {};
};
class ACE_Hellfire_AGM114R9X : ACE_Hellfire_AGM114K {
    model = "\rksla3\rksla3-cvwp\agm\rksl_agm114r9x_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\agm\rksl_agm114r9x_proxy.p3d";
    hit = 150;
    indirectHit = 1;
    indirectHitRange = 2;
    warheadName = "HE";
    submunitionAmmo = "";
    explosionEffects = "";
    class ace_missileguidance;
};
class ACE_Hellfire_AGM114R9X_drone : ACE_Hellfire_AGM114R9X {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
        seekerAngle = 350;
    };
};
