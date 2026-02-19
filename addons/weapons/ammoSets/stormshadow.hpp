class rksla3_ammo_kepd350;
class rksla3_ammo_stormshadow : rksla3_ammo_kepd350 {
    maneuvrability = 0;
    ace_rearm_dummy = QGVAR(ammo_missile_stormshadow);
    SoundSetExplosion[] = { "JPEX_Missile_EXPLOSION_SoundSet", "JPEX_Missile_REFLECTOR_SoundSet", "JPEX_Big_Debris_SoundSet" };

    weaponLockSystem = 0;
    laserLock = 0;
    irLock = 0;
    airLock = 0;

    // Flight physics — override rksla3 values based on vanilla ammo_Missile_CruiseBase
    // Vanilla cruise: thrust=35, airFriction=0.45, maxSpeed=194, thrustTime=200
    // Storm Shadow is slightly faster (Mach 0.8), so bump maxSpeed and thrust proportionally
    maxSpeed = 220;
    thrust = 45;
    thrustTime = 200;
    airFriction = 0.35;
    sideAirFriction = 0.4;
    initTime = 1;

    class ace_missileguidance : ace_missileguidance_type_CruiseMissile {
        enabled = 1;
    };
};
