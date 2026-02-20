class M_Air_AA : MissileBase {
    ace_rearm_dummy = QGVAR(ammo_Missile_AIM132);
    model = "\rksla3\rksla3-cvwp\aam\rksl_aim132asraam_fired.p3d";
    proxyShape = "\rksla3\rksla3-cvwp\aam\rksl_aim132asraam_proxy.p3d";
    hit = 400;
    indirectHitRange = 10;
    proximityExplosionDistance = 20;
    fuseDistance = 100;
    trackOversteer = 1.6;
    missileLockCone = 180;
    missileKeepLockedCone = 180;
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
