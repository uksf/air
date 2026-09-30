class pilotCamera : pilotCamera {
    class OpticsIn {
        class Wide {
            opticsDisplayName = "WFOV";
            initAngleX = 0;
            minAngleX = 0;
            maxAngleX = 0;
            initAngleY = 0;
            minAngleY = 0;
            maxAngleY = 0;
            initFov = "(75 / 120)";
            minFov = "(75 / 120)";
            maxFov = "(75 / 120)";
            directionStabilized = 1;
            visionMode[] = { "Normal", "NVG", "Ti" };
            thermalMode[] = { 0, 1 };
            gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
            opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
        };
        class LWide : Wide {
            opticsDisplayName = "LWFOV";
            initFov = "(25 / 120)";
            minFov = "(25 / 120)";
            maxFov = "(25 / 120)";
            gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
        };
        class Medium : Wide {
            opticsDisplayName = "MFOV";
            initFov = "(14.4 / 120)";
            minFov = "(14.4 / 120)";
            maxFov = "(14.4 / 120)";
            gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
        };
        class Narrow : Wide {
            opticsDisplayName = "NFOV";
            initFov = "(4.8 / 120)";
            minFov = "(4.8 / 120)";
            maxFov = "(4.8 / 120)";
            gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
        };
        class VNarrow : Wide {
            opticsDisplayName = "VNFOV";
            initFov = "(2 / 120)";
            minFov = "(2 / 120)";
            maxFov = "(2 / 120)";
            gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
        };
        class VVNarrow : Wide {
            opticsDisplayName = "VVNFOV";
            initFov = "(1 / 120)";
            minFov = "(1 / 120)";
            maxFov = "(1 / 120)";
            gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
        };
    };
};
