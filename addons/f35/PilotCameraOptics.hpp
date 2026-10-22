#define PILOT_CAMERA_RETICLE_WIDE "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d"
#define PILOT_CAMERA_RETICLE_MEDIUM "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d"
#define PILOT_CAMERA_RETICLE_NARROW "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d"
#define PILOT_CAMERA_STEP(NAME,LABEL,FOV,RETICLE) class NAME : Wide { \
    opticsDisplayName = LABEL; \
    initFov = FOV; \
    minFov = FOV; \
    maxFov = FOV; \
    gunnerOpticsModel = RETICLE; \
}

class OpticsIn {
    class Wide {
        opticsDisplayName = "WFOV";
        initAngleX = 0;
        minAngleX = 0;
        maxAngleX = 0;
        initAngleY = 0;
        minAngleY = 0;
        maxAngleY = 0;
        initFov = 0.625;
        minFov = 0.625;
        maxFov = 0.625;
        directionStabilized = 1;
        visionMode[] = { "Normal", "NVG", "Ti" };
        thermalMode[] = { 0, 1 };
        gunnerOpticsModel = PILOT_CAMERA_RETICLE_WIDE;
        opticsPPEffects[] = { "OpticsCHAbera2", "OpticsBlur2" };
    };
    PILOT_CAMERA_STEP(Medium,"MFOV",0.25,PILOT_CAMERA_RETICLE_MEDIUM);
    PILOT_CAMERA_STEP(Narrow,"NFOV",0.1,PILOT_CAMERA_RETICLE_MEDIUM);
    PILOT_CAMERA_STEP(VNarrow,"VNFOV",0.05,PILOT_CAMERA_RETICLE_NARROW);
    PILOT_CAMERA_STEP(Zoom2,"VNFOV x2.5",0.02,PILOT_CAMERA_RETICLE_NARROW);
    PILOT_CAMERA_STEP(Zoom5,"VNFOV x5",0.01,PILOT_CAMERA_RETICLE_NARROW);
    PILOT_CAMERA_STEP(Zoom10,"VNFOV x10",0.005,PILOT_CAMERA_RETICLE_NARROW);
};
