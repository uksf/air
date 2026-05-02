// ASRAAM (AIM-132): ~10kg HE blast-frag warhead, IR short-range. Vanilla short-range
// reference: hit=400 iH=85 iHR=10. Tightened iHR for frag-dominant kill profile.
class M_Air_AA : MissileBase {
    ace_rearm_dummy = QGVAR(ammo_Missile_AIM132);
    model = "\rksla3\rksla3-cvwp\aam\rksl_aim132asraam_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\aam\rksl_aim132asraam_proxy.p3d";
    hit = 400;
    indirectHit = 95;
    indirectHitRange = 4;
    fuseDistance = 100;
    trackOversteer = 1.6;
    missileLockCone = 180;
    missileKeepLockedCone = 180;
    ace_frag_skip = 0;
    ace_frag_force = 1;
    ace_frag_charge = 1800;       // ~1.8kg HE
    ace_frag_metal = 3800;        // ~3.8kg fragments
    ace_frag_gurney_c = 2700;
    ace_frag_gurney_k = 0.5;
    ace_frag_classes[] = { QGVAR(frag_a2a_sr) };
    class Components {
        class SensorsManagerComponent {
            class Components {
                class IRSensorComponent {
                    componentType = "IRSensorComponent";
                    class AirTarget {
                        minRange = 500;
                        maxRange = 8000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 8000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    angleRangeHorizontal = 180;
                    angleRangeVertical = 180;
                };
            };
        };
    };
};
class ace_missile_aim9_aim132 : M_Air_AA {
    missileLockCone = 180;
    missileKeepLockedCone = 180;
};

// A2A frag classes for AAM warheads. Pure kinetic (no explosive), tungsten/steel rod fragments.
// caliber=30 chosen as the threshold that passes fast-jet HitPoint penetration gates;
// vanilla ACE frag classes (caliber 1.2-2.8) are rejected by plane fire-geometry and
// route to root structural only. hit value scales the per-fragment kinetic energy.
// Per-missile total frag count is driven by ace_frag_charge/metal on the warhead.
class GVAR(frag_a2a_base) : BulletBase {
    timeToLive = 4;
    typicalSpeed = 1500;
    maxSpeed = 1500;
    airFriction = -0.01;
    deflecting = 65;
    caliber = 30;
    hit = 80;
    ace_frag_skip = 1;
    ACE_damageType = "grenade";
};
// BVR (Meteor): largest pre-formed fragments
class GVAR(frag_a2a_bvr) : GVAR(frag_a2a_base) { hit = 100; };
// Medium-range (AMRAAM): mid-size fragments
class GVAR(frag_a2a_mr)  : GVAR(frag_a2a_base) { hit = 80; };
// Short-range (ASRAAM/Sidewinder): smaller per-frag energy, fewer total frags
class GVAR(frag_a2a_sr)  : GVAR(frag_a2a_base) { hit = 60; };
// MANPADS (Stinger/Igla/Strela): ~1kg warhead, smallest per-frag energy
class GVAR(frag_a2a_manpad) : GVAR(frag_a2a_base) { hit = 50; };
// Naval CIWS (RIM-116 RAM): 9.1kg blast-frag, larger per-frag than SR
class GVAR(frag_a2a_naval_ciws) : GVAR(frag_a2a_base) { hit = 90; };
// Naval medium-range (ESSM / Sea Sparrow): ~39kg warhead, large pre-formed fragments
class GVAR(frag_a2a_naval_mr) : GVAR(frag_a2a_base) { hit = 130; };
// Long-range strategic SAM (Patriot / S-400): massive warhead, heaviest fragments
class GVAR(frag_a2a_sam_lr) : GVAR(frag_a2a_base) { hit = 160; };

