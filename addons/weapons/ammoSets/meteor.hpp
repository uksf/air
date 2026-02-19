class ammo_Missile_LongRangeAABase;
class rksla3_ammo_meteor : ammo_Missile_LongRangeAABase {
    hit = 600;
    indirectHit = 120;
    maneuvrability = 0;
    ace_rearm_dummy = QGVAR(ammo_missile_meteor);
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet" };

    flightProfiles[] = { "Direct", "TopDown" };
    class Direct {};
    class TopDown { textureType = "topDown"; };

    class ace_missileguidance : ace_missileguidance_type_AMRAAM {
        enabled = 1;
        pitchRate = 50;
        yawRate = 50;
        minimumSpeedFilter = 10;
        minimumTimeFilter = 5e-05;
        maxTerrainCheck = 20000;
        seekerAngle = 60;
        seekerMaxRange = 4000;
        seekerMinRange = 75;
    };
};
