class ammo_Missile_LongRangeAABase;
class rksla3_ammo_meteor : ammo_Missile_LongRangeAABase {
    hit = 750;
    indirectHit = 155;
    maneuvrability = 0;
    initTime = 0.5;
    maxSpeed = 1340;
    thrust = 400;
    thrustTime = 60;
    timeToLive = 150;
    airFriction = 0.06;
    sideAirFriction = 0.18;
    ace_rearm_dummy = QGVAR(ammo_missile_meteor);
    ace_frag_skip = 0;
    ace_frag_charge = 80;
    ace_frag_metal = 145;
    ace_frag_classes[] = { "ace_frag_small", "ace_frag_medium", "ace_frag_medium" };
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet" };

    flightProfiles[] = { "Direct", "TopDown" };
    class Direct {};
    class TopDown { textureType = "topDown"; };

    class ace_missileguidance : ace_missileguidance_type_AMRAAM {
        enabled = 1;
        pitchRate = 45;
        yawRate = 45;
        navigationGain = 4;
        minimumSpeedFilter = 10;
        minimumTimeFilter = 5e-05;
        maxTerrainCheck = 20000;
        seekerAngle = 60;
        seekerMaxRange = 4000;
        seekerMinRange = 75;
    };
};
