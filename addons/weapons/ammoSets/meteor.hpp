// Meteor: 25kg HE-fragmentation warhead, ramjet sustain, BVR. Pre-formed steel/tungsten
// fragments dominate lethality; small overpressure plateau (~5m). Vanilla MediumRangeAA
// reference: hit=600 iH=125 iHR=13. Meteor sized higher hit (bigger warhead) but smaller
// iHR (frag-dominant — overpressure isn't the killer at BVR ranges).
// Speed clamped to 1000 m/s (real Mach 4+) to keep terminal closure manageable for
// CPA prediction + AugmentedProportionalNavigation tracking under server desync.
class rksla3_ammo_meteor : ammo_Missile_LongRangeAABase {
    hit = 750;
    indirectHit = 130;
    indirectHitRange = 5;
    maneuvrability = 23;
    initTime = 0.1;
    maxSpeed = 1000;
    thrust = 400;
    thrustTime = 60;
    timeToLive = 150;
    airFriction = 0.06;
    sideAirFriction = 0.18;
    ace_rearm_dummy = QGVAR(ammo_missile_meteor);
    A2A_FRAG(4500,9500,bvr);      // ~4.5kg HE (PBX) / ~9.5kg pre-formed fragments
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet" };

    flightProfiles[] = { "Direct", "TopDown" };
    class Direct {};
    class TopDown { textureType = "topDown"; };

    class ace_missileguidance : ace_missileguidance_type_AMRAAM {
        enabled = 1;
        pitchRate = 60;
        yawRate = 60;
        proximityRadius = 15;       // BVR-class envelope - larger than AMRAAM baseline (10m); extra margin for tick-skip
        proximityArmingTime = 0.5;  // arm within ~500m for close head-on shots
        defaultNavigationType = "AugmentedProportionalNavigation";  // real Meteor uses APN-class law w/ target accel feedforward
        navigationTypes[] = { "AugmentedProportionalNavigation" };
        navigationGain = 3;
        minimumSpeedFilter = 10;
        minimumTimeFilter = 5e-05;
        maxTerrainCheck = 20000;
        seekerAngle = 60;
        seekerMaxRange = 4000;
        seekerMinRange = 75;
    };
};
