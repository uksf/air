// Meteor: 25kg HE-fragmentation warhead, Mach 4 ramjet, BVR. Pre-formed steel/tungsten
// fragments dominate lethality; small overpressure plateau (~5m). Vanilla MediumRangeAA
// reference: hit=600 iH=125 iHR=13. Meteor sized higher hit (bigger warhead) but smaller
// iHR (frag-dominant — overpressure isn't the killer at BVR ranges).
class rksla3_ammo_meteor : ammo_Missile_LongRangeAABase {
    hit = 750;
    indirectHit = 130;
    indirectHitRange = 5;
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
    ace_frag_force = 1;
    ace_frag_charge = 4500;       // ~4.5kg HE (PBX)
    ace_frag_metal = 9500;        // ~9.5kg pre-formed fragments
    ace_frag_gurney_c = 2700;     // PBX/RDX modern HE
    ace_frag_gurney_k = 0.5;      // cylindrical geometry
    ace_frag_classes[] = { QGVAR(frag_a2a_bvr) };
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet" };

    flightProfiles[] = { "Direct", "TopDown" };
    class Direct {};
    class TopDown { textureType = "topDown"; };

    class ace_missileguidance : ace_missileguidance_type_AMRAAM {
        enabled = 1;
        pitchRate = 45;
        yawRate = 45;
        proximityRadius = 12;       // BVR-class envelope - larger than AMRAAM baseline (10m)
        navigationGain = 4;
        minimumSpeedFilter = 10;
        minimumTimeFilter = 5e-05;
        maxTerrainCheck = 20000;
        seekerAngle = 60;
        seekerMaxRange = 4000;
        seekerMinRange = 75;
    };
};
