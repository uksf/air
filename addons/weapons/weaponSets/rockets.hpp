class CUP_Vmlauncher_CRV7_veh : CUP_Vmlauncher_FFAR_veh {
    class Single;
    class Double : Single {
        displayName = "Ripple 2";
    };
    class Quadruple : Single {
        displayName = "Ripple 4";
    };
};
class rksla3_aw159_wpn_crv7_lau5003 : missiles_DAR {
    modes[] = { "Far_AI", "Medium_AI", "Ripple1", "Ripple2", "Ripple4" };
    class Ripple1 : RocketPods {
        displayName = "Ripple 1";
        textureType = "semi";
        burst = 1;
        soundContinuous = 0;
        autoFire = 0;
        reloadTime = 0.08;
        dispersion = 0.015;
        aiRateOfFire = 1;
        aiRateOfFireDistance = 10;
        minRange = 0;
        minRangeProbab = 0.01;
        midRange = 1;
        midRangeProbab = 0.01;
        maxRange = 2;
        maxRangeProbab = 0.01;
        sounds[] = { "StandardSound" };
        class StandardSound {
            begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_8", 1.77828, 1.2, 1600 };
            soundBegin[] = { "begin1", 1 };
            soundSetShot[] = { "jsrs_2025_rocketpods_shot_soundset" };
        };
    };
    class Ripple2 : Ripple1 {
        displayName = "Ripple 2";
        textureType = "burst";
        burst = 2;
    };
    class Ripple4 : Ripple1 {
        displayName = "Ripple 4";
        textureType = "fullAuto";
        burst = 4;
    };
};
