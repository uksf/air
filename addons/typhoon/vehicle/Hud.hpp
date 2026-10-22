class MFD {
    class HUD {
        class Pos10Vector {
            type = "vector";
            pos0[] = { 0.4805, 0.4 };
            pos10[] = { 1.4425, 1.31 };
        };
        topLeft = "HUD LH";
        topRight = "HUD PH";
        bottomLeft = "HUD LD";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.15, 1, 0.15, 1 };
        class Bones {
            class PlaneW {
                type = "fixed";
                pos[] = { 0.4805, 0.4 };
            };
            class WeaponAim : Pos10Vector {
                source = "weapon";
            };
            class Target : Pos10Vector {
                source = "target";
            };
            class Velocity : Pos10Vector {
                type = "vector";
                source = "velocity";
                pos0[] = { 0.5, 0.4 };
                pos10[] = { 1.462, 1.31 };
            };
            class ILS_H {
                type = "ils";
                pos0[] = { 0.5, 0.4 };
                pos3[] = { 0.7886, 0.4 };
            };
            class ILS_W : ILS_H {
                pos3[] = { 0.5, 0.673 };
            };
            class Level0 : Pos10Vector {
                pos0[] = { 0.5, 0.4 };
                pos10[] = { 1.462, 1.31 };
                type = "horizon";
                angle = 0;
            };
            class LevelP5 : Level0 {
                angle = 5;
            };
            class LevelM5 : Level0 {
                angle = -5;
            };
            class LevelP10 : Level0 {
                angle = 10;
            };
            class LevelM10 : Level0 {
                angle = -10;
            };
            class LevelP15 : Level0 {
                angle = 15;
            };
            class LevelM15 : Level0 {
                angle = -15;
            };
            class LevelP20 : Level0 {
                angle = 20;
            };
            class LevelM20 : Level0 {
                angle = -20;
            };
            class LevelP25 : Level0 {
                angle = 25;
            };
            class LevelM25 : Level0 {
                angle = -25;
            };
            class LevelP30 : Level0 {
                angle = 30;
            };
            class LevelM30 : Level0 {
                angle = -30;
            };
            class LevelP35 : Level0 {
                angle = 35;
            };
            class LevelM35 : Level0 {
                angle = -35;
            };
            class LevelP40 : Level0 {
                angle = 40;
            };
            class LevelM40 : Level0 {
                angle = -40;
            };
            class LevelP45 : Level0 {
                angle = 45;
            };
            class LevelM45 : Level0 {
                angle = -45;
            };
            class LevelP50 : Level0 {
                angle = 50;
            };
            class LevelP55 : Level0 {
                angle = 55;
            };
            class LevelP60 : Level0 {
                angle = 60;
            };
            class LevelP65 : Level0 {
                angle = 65;
            };
            class LevelP70 : Level0 {
                angle = 70;
            };
            class LevelP75 : Level0 {
                angle = 75;
            };
            class LevelP80 : Level0 {
                angle = 80;
            };
            class LevelP85 : Level0 {
                angle = 85;
            };
            class LevelM50 : Level0 {
                angle = -50;
            };
            class LevelM55 : Level0 {
                angle = -55;
            };
            class LevelM60 : Level0 {
                angle = -60;
            };
            class LevelM65 : Level0 {
                angle = -65;
            };
            class LevelM70 : Level0 {
                angle = -70;
            };
            class LevelM75 : Level0 {
                angle = -75;
            };
            class LevelM80 : Level0 {
                angle = -80;
            };
            class LevelM85 : Level0 {
                angle = -85;
            };
            class ASL_Instrument {
                type = "rotational";
                source = "altitudeASL";
                center[] = { 0.9, 0.340206 };
                min = 0;
                max = 20000;
                minAngle = 0;
                maxAngle = 236220;
                aspectRatio = 1.13402;
            };
            class ASL_Instrument_center {
                type = "fixed";
                pos[] = { 0.85, 0.5 };
            };
            class TargetDistanceMissile {
                type = "rotational";
                source = "targetDist";
                center[] = { 0.485, 0.4 };
                min = 0;
                max = 5000;
                minAngle = 0;
                maxAngle = 270;
            };
            class HorizonBankMGun {
                type = "rotational";
                source = "HorizonBank";
                center[] = { 0, 0 };
                min = -6.28319;
                max = 6.28319;
                minAngle = -360;
                maxAngle = 360;
                aspectRatio = 0.787097;
            };
            class VelocityNotCenter : Pos10Vector {
                type = "vector";
                source = "velocity";
                pos0[] = { -0.15, -0.12 };
                pos10[] = { 0.8575, 0.673 };
            };
            class TGPTarget {
                type = "vector";
                source = "pilotcameratarget";
                pos0[] = { 0.4747, 0.4 };
                pos10[] = { 1.051, 1.04 };
            };
            class TGPLimit {
                type = "limit";
                limits[] = { 0.05, 0.05, 0.95, 0.95 };
            };
        };
        class Draw {
            alpha = 1;
            color[] = { 0.15, 1, 0.15 };
            condition = "on";
            class PlaneW {
                clipTL[] = { 0, 1 };
                clipBR[] = { 1, 0 };
                type = "line";
                points[] = {
                    { "PlaneW", { -0.104, 0 }, 1 },
                    { "PlaneW", { -0.039, 0 }, 1 },
                    { "PlaneW", { -0.0195, 0.036891 }, 1 },
                    { "PlaneW", { 0, 0 }, 1 },
                    { "PlaneW", { 0.0195, 0.036891 }, 1 },
                    { "PlaneW", { 0.039, 0 }, 1 },
                    { "PlaneW", { 0.104, 0 }, 1 }
                };
            };
            class PlaneHeading {
                clipTL[] = { 0, 1 };
                clipBR[] = { 1, 0 };
                type = "line";
                points[] = {
                    { "Velocity", { 0, -0.024595 }, 1 },
                    { "Velocity", { 0.0182, -0.017216 }, 1 },
                    { "Velocity", { 0.026, 0 }, 1 },
                    { "Velocity", { 0.0182, 0.017216 }, 1 },
                    { "Velocity", { 0, 0.024595 }, 1 },
                    { "Velocity", { -0.0182, 0.017216 }, 1 },
                    { "Velocity", { -0.026, 0 }, 1 },
                    { "Velocity", { -0.0182, -0.017216 }, 1 },
                    { "Velocity", { 0, -0.024595 }, 1 },
                    {},
                    { "Velocity", { 0.052, 0 }, 1 },
                    { "Velocity", { 0.026, 0 }, 1 },
                    {},
                    { "Velocity", { -0.052, 0 }, 1 },
                    { "Velocity", { -0.026, 0 }, 1 },
                    {},
                    { "Velocity", { 0, -0.049189 }, 1 },
                    { "Velocity", { 0, -0.024595 }, 1 },
                    {}
                };
            };
            class Static {
                clipTL[] = { 0, 0.1 };
                clipBR[] = { 1, 0 };
                type = "line";
                points[] = {
                    { { 0.025, 0.475 }, 1 },
                    { { 0.11, 0.475 }, 1 },
                    { { 0.13, 0.5 }, 1 },
                    { { 0.11, 0.525 }, 1 },
                    { { 0.025, 0.525 }, 1 },
                    { { 0.025, 0.475 }, 1 },
                    {},
                    { { 0.52, "0.08+0.01" }, 1 },
                    { { 0.5, "0.06+0.01" }, 1 },
                    { { 0.48, "0.08+0.01" }, 1 },
                    {},
                    { { 0.9025, 0.445103 }, 1 },
                    { { 0.8975, 0.445103 }, 1 },
                    {},
                    { { 0.95687, 0.42507 }, 1 },
                    { { 0.95187, 0.42507 }, 1 },
                    {},
                    { { 0.990473, 0.372621 }, 1 },
                    { { 0.985473, 0.372621 }, 1 },
                    {},
                    { { 0.990473, 0.307791 }, 1 },
                    { { 0.985473, 0.307791 }, 1 },
                    {},
                    { { 0.95687, 0.255343 }, 1 },
                    { { 0.95187, 0.255343 }, 1 },
                    {},
                    { { 0.9025, 0.235309 }, 1 },
                    { { 0.8975, 0.235309 }, 1 },
                    {},
                    { { 0.84813, 0.255343 }, 1 },
                    { { 0.84313, 0.255343 }, 1 },
                    {},
                    { { 0.814527, 0.307791 }, 1 },
                    { { 0.809527, 0.307791 }, 1 },
                    {},
                    { { 0.814527, 0.372621 }, 1 },
                    { { 0.809527, 0.372621 }, 1 },
                    {},
                    { { 0.84813, 0.42507 }, 1 },
                    { { 0.84313, 0.42507 }, 1 },
                    {},
                    { "ASL_Instrument", { 0, 0.065 }, 1 },
                    { "ASL_Instrument", { 0, 0.085 }, 1 },
                    {}
                };
            };
            class SpeedScale {
                type = "scale";
                scale = 1;
                source = "speed";
                sourceScale = 1.94384;
                align = "left";
                pos[] = { 0.01, 0.17 };
                right[] = { 0.01, 0.17 };
                down[] = { 0.01, 0.17 };
                lineXleft = 0.15;
                lineYright = 0.145;
                lineXleftMajor = 0.155;
                lineYrightMajor = 0.135;
                bottom = 0.75;
                center = 0.5;
                top = 0.3;
                step = 20;
                StepSize = "(0.85- 0.2)/20";
                horizontal = 0;
                min = "none";
                max = "none";
                numberEach = 100;
                majorLineEach = 5;
            };
            class SpeedNumber {
                type = "text";
                source = "speed";
                scale = 1;
                sourceScale = 1.94384;
                align = "center";
                pos[] = { { 0.075, 0.48 }, 1 };
                right[] = { { 0.125, 0.48 }, 1 };
                down[] = { { 0.075, 0.52 }, 1 };
            };
            class Horizont {
                clipTL[] = { 0, 0 };
                clipBR[] = { 1, 1 };
                class Dimmed {
                    class Level0 {
                        type = "line";
                        points[] = {
                            { "Level0", { -0.26, 0 }, 1 },
                            { "Level0", { -0.065, 0 }, 1 },
                            {},
                            { "Level0", { 0.065, 0 }, 1 },
                            { "Level0", { 0.26, 0 }, 1 }
                        };
                    };
                    class VALM_1_0 {
                        type = "text";
                        source = "static";
                        text = 0;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "Level0", { -0.299, -0.0325 }, 1 };
                        right[] = { "Level0", { -0.169, -0.0325 }, 1 };
                        down[] = { "Level0", { -0.299, 0.0325 }, 1 };
                    };
                    class VALM_2_0 : VALM_1_0 {
                        align = "right";
                        pos[] = { "Level0", { 0.286, -0.0325 }, 1 };
                        right[] = { "Level0", { 0.416, -0.0325 }, 1 };
                        down[] = { "Level0", { 0.286, 0.0325 }, 1 };
                    };
                    class LevelM5 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM5", { -0.26, -0.039 }, 1 },
                            { "LevelM5", { -0.26, 0 }, 1 },
                            { "LevelM5", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM5", { -0.13, 0 }, 1 },
                            { "LevelM5", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM5", { 0.065, 0 }, 1 },
                            { "LevelM5", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM5", { 0.195, 0 }, 1 },
                            { "LevelM5", { 0.26, 0 }, 1 },
                            { "LevelM5", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_5 {
                        type = "text";
                        source = "static";
                        text = -5;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM5", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM5", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM5", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_5 : VALM_1_5 {
                        align = "right";
                        pos[] = { "LevelM5", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM5", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM5", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP5 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP5", { -0.26, 0.039 }, 1 },
                            { "LevelP5", { -0.26, 0 }, 1 },
                            { "LevelP5", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP5", { 0.065, 0 }, 1 },
                            { "LevelP5", { 0.26, 0 }, 1 },
                            { "LevelP5", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_5 {
                        type = "text";
                        source = "static";
                        text = "5";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP5", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP5", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP5", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_5 : VALP_1_5 {
                        align = "right";
                        pos[] = { "LevelP5", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP5", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP5", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM10 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM10", { -0.26, -0.039 }, 1 },
                            { "LevelM10", { -0.26, 0 }, 1 },
                            { "LevelM10", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM10", { -0.13, 0 }, 1 },
                            { "LevelM10", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM10", { 0.065, 0 }, 1 },
                            { "LevelM10", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM10", { 0.195, 0 }, 1 },
                            { "LevelM10", { 0.26, 0 }, 1 },
                            { "LevelM10", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_10 {
                        type = "text";
                        source = "static";
                        text = -10;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM10", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM10", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM10", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_10 : VALM_1_10 {
                        align = "right";
                        pos[] = { "LevelM10", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM10", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM10", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP10 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP10", { -0.26, 0.039 }, 1 },
                            { "LevelP10", { -0.26, 0 }, 1 },
                            { "LevelP10", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP10", { 0.065, 0 }, 1 },
                            { "LevelP10", { 0.26, 0 }, 1 },
                            { "LevelP10", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_10 {
                        type = "text";
                        source = "static";
                        text = "10";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP10", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP10", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP10", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_10 : VALP_1_10 {
                        align = "right";
                        pos[] = { "LevelP10", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP10", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP10", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM15 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM15", { -0.26, -0.039 }, 1 },
                            { "LevelM15", { -0.26, 0 }, 1 },
                            { "LevelM15", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM15", { -0.13, 0 }, 1 },
                            { "LevelM15", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM15", { 0.065, 0 }, 1 },
                            { "LevelM15", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM15", { 0.195, 0 }, 1 },
                            { "LevelM15", { 0.26, 0 }, 1 },
                            { "LevelM15", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_15 {
                        type = "text";
                        source = "static";
                        text = -15;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM15", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM15", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM15", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_15 : VALM_1_15 {
                        align = "right";
                        pos[] = { "LevelM15", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM15", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM15", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP15 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP15", { -0.26, 0.039 }, 1 },
                            { "LevelP15", { -0.26, 0 }, 1 },
                            { "LevelP15", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP15", { 0.065, 0 }, 1 },
                            { "LevelP15", { 0.26, 0 }, 1 },
                            { "LevelP15", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_15 {
                        type = "text";
                        source = "static";
                        text = "15";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP15", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP15", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP15", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_15 : VALP_1_15 {
                        align = "right";
                        pos[] = { "LevelP15", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP15", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP15", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM20 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM20", { -0.26, -0.039 }, 1 },
                            { "LevelM20", { -0.26, 0 }, 1 },
                            { "LevelM20", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM20", { -0.13, 0 }, 1 },
                            { "LevelM20", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM20", { 0.065, 0 }, 1 },
                            { "LevelM20", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM20", { 0.195, 0 }, 1 },
                            { "LevelM20", { 0.26, 0 }, 1 },
                            { "LevelM20", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_20 {
                        type = "text";
                        source = "static";
                        text = -20;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM20", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM20", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM20", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_20 : VALM_1_20 {
                        align = "right";
                        pos[] = { "LevelM20", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM20", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM20", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP20 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP20", { -0.26, 0.039 }, 1 },
                            { "LevelP20", { -0.26, 0 }, 1 },
                            { "LevelP20", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP20", { 0.065, 0 }, 1 },
                            { "LevelP20", { 0.26, 0 }, 1 },
                            { "LevelP20", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_20 {
                        type = "text";
                        source = "static";
                        text = "20";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP20", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP20", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP20", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_20 : VALP_1_20 {
                        align = "right";
                        pos[] = { "LevelP20", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP20", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP20", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM25 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM25", { -0.26, -0.039 }, 1 },
                            { "LevelM25", { -0.26, 0 }, 1 },
                            { "LevelM25", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM25", { -0.13, 0 }, 1 },
                            { "LevelM25", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM25", { 0.065, 0 }, 1 },
                            { "LevelM25", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM25", { 0.195, 0 }, 1 },
                            { "LevelM25", { 0.26, 0 }, 1 },
                            { "LevelM25", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_25 {
                        type = "text";
                        source = "static";
                        text = -25;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM25", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM25", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM25", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_25 : VALM_1_25 {
                        align = "right";
                        pos[] = { "LevelM25", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM25", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM25", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP25 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP25", { -0.26, 0.039 }, 1 },
                            { "LevelP25", { -0.26, 0 }, 1 },
                            { "LevelP25", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP25", { 0.065, 0 }, 1 },
                            { "LevelP25", { 0.26, 0 }, 1 },
                            { "LevelP25", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_25 {
                        type = "text";
                        source = "static";
                        text = "25";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP25", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP25", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP25", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_25 : VALP_1_25 {
                        align = "right";
                        pos[] = { "LevelP25", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP25", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP25", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM30 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM30", { -0.26, -0.039 }, 1 },
                            { "LevelM30", { -0.26, 0 }, 1 },
                            { "LevelM30", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM30", { -0.13, 0 }, 1 },
                            { "LevelM30", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM30", { 0.065, 0 }, 1 },
                            { "LevelM30", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM30", { 0.195, 0 }, 1 },
                            { "LevelM30", { 0.26, 0 }, 1 },
                            { "LevelM30", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_30 {
                        type = "text";
                        source = "static";
                        text = -30;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM30", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM30", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM30", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_30 : VALM_1_30 {
                        align = "right";
                        pos[] = { "LevelM30", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM30", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM30", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP30 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP30", { -0.26, 0.039 }, 1 },
                            { "LevelP30", { -0.26, 0 }, 1 },
                            { "LevelP30", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP30", { 0.065, 0 }, 1 },
                            { "LevelP30", { 0.26, 0 }, 1 },
                            { "LevelP30", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_30 {
                        type = "text";
                        source = "static";
                        text = "30";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP30", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP30", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP30", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_30 : VALP_1_30 {
                        align = "right";
                        pos[] = { "LevelP30", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP30", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP30", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM35 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM35", { -0.26, -0.039 }, 1 },
                            { "LevelM35", { -0.26, 0 }, 1 },
                            { "LevelM35", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM35", { -0.13, 0 }, 1 },
                            { "LevelM35", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM35", { 0.065, 0 }, 1 },
                            { "LevelM35", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM35", { 0.195, 0 }, 1 },
                            { "LevelM35", { 0.26, 0 }, 1 },
                            { "LevelM35", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_35 {
                        type = "text";
                        source = "static";
                        text = -35;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM35", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM35", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM35", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_35 : VALM_1_35 {
                        align = "right";
                        pos[] = { "LevelM35", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM35", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM35", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP35 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP35", { -0.26, 0.039 }, 1 },
                            { "LevelP35", { -0.26, 0 }, 1 },
                            { "LevelP35", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP35", { 0.065, 0 }, 1 },
                            { "LevelP35", { 0.26, 0 }, 1 },
                            { "LevelP35", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_35 {
                        type = "text";
                        source = "static";
                        text = "35";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP35", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP35", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP35", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_35 : VALP_1_35 {
                        align = "right";
                        pos[] = { "LevelP35", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP35", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP35", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM40 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM40", { -0.26, -0.039 }, 1 },
                            { "LevelM40", { -0.26, 0 }, 1 },
                            { "LevelM40", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM40", { -0.13, 0 }, 1 },
                            { "LevelM40", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM40", { 0.065, 0 }, 1 },
                            { "LevelM40", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM40", { 0.195, 0 }, 1 },
                            { "LevelM40", { 0.26, 0 }, 1 },
                            { "LevelM40", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_40 {
                        type = "text";
                        source = "static";
                        text = -40;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM40", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM40", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM40", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_40 : VALM_1_40 {
                        align = "right";
                        pos[] = { "LevelM40", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM40", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM40", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP40 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP40", { -0.26, 0.039 }, 1 },
                            { "LevelP40", { -0.26, 0 }, 1 },
                            { "LevelP40", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP40", { 0.065, 0 }, 1 },
                            { "LevelP40", { 0.26, 0 }, 1 },
                            { "LevelP40", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_40 {
                        type = "text";
                        source = "static";
                        text = "40";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP40", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP40", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP40", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_40 : VALP_1_40 {
                        align = "right";
                        pos[] = { "LevelP40", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP40", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP40", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM45 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM45", { -0.26, -0.039 }, 1 },
                            { "LevelM45", { -0.26, 0 }, 1 },
                            { "LevelM45", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM45", { -0.13, 0 }, 1 },
                            { "LevelM45", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM45", { 0.065, 0 }, 1 },
                            { "LevelM45", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM45", { 0.195, 0 }, 1 },
                            { "LevelM45", { 0.26, 0 }, 1 },
                            { "LevelM45", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_45 {
                        type = "text";
                        source = "static";
                        text = -45;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM45", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM45", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM45", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_45 : VALM_1_45 {
                        align = "right";
                        pos[] = { "LevelM45", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM45", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM45", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP45 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP45", { -0.26, 0.039 }, 1 },
                            { "LevelP45", { -0.26, 0 }, 1 },
                            { "LevelP45", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP45", { 0.065, 0 }, 1 },
                            { "LevelP45", { 0.26, 0 }, 1 },
                            { "LevelP45", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_45 {
                        type = "text";
                        source = "static";
                        text = "45";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP45", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP45", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP45", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_45 : VALP_1_45 {
                        align = "right";
                        pos[] = { "LevelP45", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP45", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP45", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM50 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM50", { -0.26, -0.039 }, 1 },
                            { "LevelM50", { -0.26, 0 }, 1 },
                            { "LevelM50", { -0.195, 0 }, 1 },
                            {},
                            { "LevelM50", { -0.13, 0 }, 1 },
                            { "LevelM50", { -0.065, 0 }, 1 },
                            {},
                            { "LevelM50", { 0.065, 0 }, 1 },
                            { "LevelM50", { 0.13, 0 }, 1 },
                            {},
                            { "LevelM50", { 0.195, 0 }, 1 },
                            { "LevelM50", { 0.26, 0 }, 1 },
                            { "LevelM50", { 0.26, -0.039 }, 1 }
                        };
                    };
                    class VALM_1_50 {
                        type = "text";
                        source = "static";
                        text = -50;
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM50", { -0.299, -0.1105 }, 1 };
                        right[] = { "LevelM50", { -0.169, -0.1105 }, 1 };
                        down[] = { "LevelM50", { -0.299, -0.0455 }, 1 };
                    };
                    class VALM_2_50 : VALM_1_50 {
                        align = "right";
                        pos[] = { "LevelM50", { 0.286, -0.1105 }, 1 };
                        right[] = { "LevelM50", { 0.416, -0.1105 }, 1 };
                        down[] = { "LevelM50", { 0.286, -0.0455 }, 1 };
                    };
                    class LevelP50 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP50", { -0.26, 0.039 }, 1 },
                            { "LevelP50", { -0.26, 0 }, 1 },
                            { "LevelP50", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP50", { 0.065, 0 }, 1 },
                            { "LevelP50", { 0.26, 0 }, 1 },
                            { "LevelP50", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_50 {
                        type = "text";
                        source = "static";
                        text = "50";
                        align = "left";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP50", { -0.299, 0.0455 }, 1 };
                        right[] = { "LevelP50", { -0.169, 0.0455 }, 1 };
                        down[] = { "LevelP50", { -0.299, 0.1105 }, 1 };
                    };
                    class VALP_2_50 : VALP_1_50 {
                        align = "right";
                        pos[] = { "LevelP50", { 0.286, 0.0455 }, 1 };
                        right[] = { "LevelP50", { 0.416, 0.0455 }, 1 };
                        down[] = { "LevelP50", { 0.286, 0.1105 }, 1 };
                    };
                    class LevelM55 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM55", { -0.26, 0.0715 }, 1 },
                            { "LevelM55", { -0.221, 0.0572 }, 1 },
                            {},
                            { "LevelM55", { -0.182, 0.0429 }, 1 },
                            { "LevelM55", { -0.143, 0.0286 }, 1 },
                            {},
                            { "LevelM55", { -0.104, 0.0143 }, 1 },
                            { "LevelM55", { -0.065, 0 }, 1 },
                            { "LevelM55", { -0.065, -0.039 }, 1 },
                            {},
                            { "LevelM55", { 0.065, -0.039 }, 1 },
                            { "LevelM55", { 0.065, 0 }, 1 },
                            { "LevelM55", { 0.104, 0.0143 }, 1 },
                            {},
                            { "LevelM55", { 0.143, 0.0286 }, 1 },
                            { "LevelM55", { 0.182, 0.0429 }, 1 },
                            {},
                            { "LevelM55", { 0.221, 0.0572 }, 1 },
                            { "LevelM55", { 0.26, 0.0715 }, 1 }
                        };
                    };
                    class VALM_1_55 {
                        type = "text";
                        source = "static";
                        text = -55;
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM55", { -0.234, -0.1066 }, 1 };
                        right[] = { "LevelM55", { -0.13, -0.1066 }, 1 };
                        down[] = { "LevelM55", { -0.234, -0.0416 }, 1 };
                    };
                    class LevelP55 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP55", { -0.26, 0.039 }, 1 },
                            { "LevelP55", { -0.26, 0 }, 1 },
                            { "LevelP55", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP55", { 0.065, 0 }, 1 },
                            { "LevelP55", { 0.26, 0 }, 1 },
                            { "LevelP55", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_55 {
                        type = "text";
                        source = "static";
                        text = "55";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP55", { -0.234, 0.0416 }, 1 };
                        right[] = { "LevelP55", { -0.13, 0.0416 }, 1 };
                        down[] = { "LevelP55", { -0.234, 0.1066 }, 1 };
                    };
                    class LevelM60 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM60", { -0.26, 0.078 }, 1 },
                            { "LevelM60", { -0.221, 0.0624 }, 1 },
                            {},
                            { "LevelM60", { -0.182, 0.0468 }, 1 },
                            { "LevelM60", { -0.143, 0.0312 }, 1 },
                            {},
                            { "LevelM60", { -0.104, 0.0156 }, 1 },
                            { "LevelM60", { -0.065, 0 }, 1 },
                            { "LevelM60", { -0.065, -0.039 }, 1 },
                            {},
                            { "LevelM60", { 0.065, -0.039 }, 1 },
                            { "LevelM60", { 0.065, 0 }, 1 },
                            { "LevelM60", { 0.104, 0.0156 }, 1 },
                            {},
                            { "LevelM60", { 0.143, 0.0312 }, 1 },
                            { "LevelM60", { 0.182, 0.0468 }, 1 },
                            {},
                            { "LevelM60", { 0.221, 0.0624 }, 1 },
                            { "LevelM60", { 0.26, 0.078 }, 1 }
                        };
                    };
                    class VALM_1_60 {
                        type = "text";
                        source = "static";
                        text = -60;
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM60", { -0.234, -0.1066 }, 1 };
                        right[] = { "LevelM60", { -0.13, -0.1066 }, 1 };
                        down[] = { "LevelM60", { -0.234, -0.0416 }, 1 };
                    };
                    class LevelP60 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP60", { -0.26, 0.039 }, 1 },
                            { "LevelP60", { -0.26, 0 }, 1 },
                            { "LevelP60", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP60", { 0.065, 0 }, 1 },
                            { "LevelP60", { 0.26, 0 }, 1 },
                            { "LevelP60", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_60 {
                        type = "text";
                        source = "static";
                        text = "60";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP60", { -0.234, 0.0416 }, 1 };
                        right[] = { "LevelP60", { -0.13, 0.0416 }, 1 };
                        down[] = { "LevelP60", { -0.234, 0.1066 }, 1 };
                    };
                    class LevelM65 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM65", { -0.26, 0.0845 }, 1 },
                            { "LevelM65", { -0.221, 0.0676 }, 1 },
                            {},
                            { "LevelM65", { -0.182, 0.0507 }, 1 },
                            { "LevelM65", { -0.143, 0.0338 }, 1 },
                            {},
                            { "LevelM65", { -0.104, 0.0169 }, 1 },
                            { "LevelM65", { -0.065, 0 }, 1 },
                            { "LevelM65", { -0.065, -0.039 }, 1 },
                            {},
                            { "LevelM65", { 0.065, -0.039 }, 1 },
                            { "LevelM65", { 0.065, 0 }, 1 },
                            { "LevelM65", { 0.104, 0.0169 }, 1 },
                            {},
                            { "LevelM65", { 0.143, 0.0338 }, 1 },
                            { "LevelM65", { 0.182, 0.0507 }, 1 },
                            {},
                            { "LevelM65", { 0.221, 0.0676 }, 1 },
                            { "LevelM65", { 0.26, 0.0845 }, 1 }
                        };
                    };
                    class VALM_1_65 {
                        type = "text";
                        source = "static";
                        text = -65;
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM65", { -0.234, -0.1066 }, 1 };
                        right[] = { "LevelM65", { -0.13, -0.1066 }, 1 };
                        down[] = { "LevelM65", { -0.234, -0.0416 }, 1 };
                    };
                    class LevelP65 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP65", { -0.26, 0.039 }, 1 },
                            { "LevelP65", { -0.26, 0 }, 1 },
                            { "LevelP65", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP65", { 0.065, 0 }, 1 },
                            { "LevelP65", { 0.26, 0 }, 1 },
                            { "LevelP65", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_65 {
                        type = "text";
                        source = "static";
                        text = "65";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP65", { -0.234, 0.0416 }, 1 };
                        right[] = { "LevelP65", { -0.13, 0.0416 }, 1 };
                        down[] = { "LevelP65", { -0.234, 0.1066 }, 1 };
                    };
                    class LevelM70 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM70", { -0.26, 0.091 }, 1 },
                            { "LevelM70", { -0.221, 0.0728 }, 1 },
                            {},
                            { "LevelM70", { -0.182, 0.0546 }, 1 },
                            { "LevelM70", { -0.143, 0.0364 }, 1 },
                            {},
                            { "LevelM70", { -0.104, 0.0182 }, 1 },
                            { "LevelM70", { -0.065, 0 }, 1 },
                            { "LevelM70", { -0.065, -0.039 }, 1 },
                            {},
                            { "LevelM70", { 0.065, -0.039 }, 1 },
                            { "LevelM70", { 0.065, 0 }, 1 },
                            { "LevelM70", { 0.104, 0.0182 }, 1 },
                            {},
                            { "LevelM70", { 0.143, 0.0364 }, 1 },
                            { "LevelM70", { 0.182, 0.0546 }, 1 },
                            {},
                            { "LevelM70", { 0.221, 0.0728 }, 1 },
                            { "LevelM70", { 0.26, 0.091 }, 1 }
                        };
                    };
                    class VALM_1_70 {
                        type = "text";
                        source = "static";
                        text = -70;
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM70", { -0.234, -0.1066 }, 1 };
                        right[] = { "LevelM70", { -0.13, -0.1066 }, 1 };
                        down[] = { "LevelM70", { -0.234, -0.0416 }, 1 };
                    };
                    class LevelP70 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP70", { -0.26, 0.039 }, 1 },
                            { "LevelP70", { -0.26, 0 }, 1 },
                            { "LevelP70", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP70", { 0.065, 0 }, 1 },
                            { "LevelP70", { 0.26, 0 }, 1 },
                            { "LevelP70", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_70 {
                        type = "text";
                        source = "static";
                        text = "70";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP70", { -0.234, 0.0416 }, 1 };
                        right[] = { "LevelP70", { -0.13, 0.0416 }, 1 };
                        down[] = { "LevelP70", { -0.234, 0.1066 }, 1 };
                    };
                    class LevelM75 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM75", { -0.26, 0.0975 }, 1 },
                            { "LevelM75", { -0.221, 0.078 }, 1 },
                            {},
                            { "LevelM75", { -0.182, 0.0585 }, 1 },
                            { "LevelM75", { -0.143, 0.039 }, 1 },
                            {},
                            { "LevelM75", { -0.104, 0.0195 }, 1 },
                            { "LevelM75", { -0.065, 0 }, 1 },
                            { "LevelM75", { -0.065, -0.039 }, 1 },
                            {},
                            { "LevelM75", { 0.065, -0.039 }, 1 },
                            { "LevelM75", { 0.065, 0 }, 1 },
                            { "LevelM75", { 0.104, 0.0195 }, 1 },
                            {},
                            { "LevelM75", { 0.143, 0.039 }, 1 },
                            { "LevelM75", { 0.182, 0.0585 }, 1 },
                            {},
                            { "LevelM75", { 0.221, 0.078 }, 1 },
                            { "LevelM75", { 0.26, 0.0975 }, 1 }
                        };
                    };
                    class VALM_1_75 {
                        type = "text";
                        source = "static";
                        text = -75;
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM75", { -0.234, -0.1066 }, 1 };
                        right[] = { "LevelM75", { -0.13, -0.1066 }, 1 };
                        down[] = { "LevelM75", { -0.234, -0.0416 }, 1 };
                    };
                    class LevelP75 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP75", { -0.26, 0.039 }, 1 },
                            { "LevelP75", { -0.26, 0 }, 1 },
                            { "LevelP75", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP75", { 0.065, 0 }, 1 },
                            { "LevelP75", { 0.26, 0 }, 1 },
                            { "LevelP75", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_75 {
                        type = "text";
                        source = "static";
                        text = "75";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP75", { -0.234, 0.0416 }, 1 };
                        right[] = { "LevelP75", { -0.13, 0.0416 }, 1 };
                        down[] = { "LevelP75", { -0.234, 0.1066 }, 1 };
                    };
                    class LevelM80 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM80", { -0.26, 0.104 }, 1 },
                            { "LevelM80", { -0.221, 0.0832 }, 1 },
                            {},
                            { "LevelM80", { -0.182, 0.0624 }, 1 },
                            { "LevelM80", { -0.143, 0.0416 }, 1 },
                            {},
                            { "LevelM80", { -0.104, 0.0208 }, 1 },
                            { "LevelM80", { -0.065, 0 }, 1 },
                            { "LevelM80", { -0.065, -0.039 }, 1 },
                            {},
                            { "LevelM80", { 0.065, -0.039 }, 1 },
                            { "LevelM80", { 0.065, 0 }, 1 },
                            { "LevelM80", { 0.104, 0.0208 }, 1 },
                            {},
                            { "LevelM80", { 0.143, 0.0416 }, 1 },
                            { "LevelM80", { 0.182, 0.0624 }, 1 },
                            {},
                            { "LevelM80", { 0.221, 0.0832 }, 1 },
                            { "LevelM80", { 0.26, 0.104 }, 1 }
                        };
                    };
                    class VALM_1_80 {
                        type = "text";
                        source = "static";
                        text = -80;
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM80", { -0.234, -0.1066 }, 1 };
                        right[] = { "LevelM80", { -0.13, -0.1066 }, 1 };
                        down[] = { "LevelM80", { -0.234, -0.0416 }, 1 };
                    };
                    class LevelP80 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP80", { -0.26, 0.039 }, 1 },
                            { "LevelP80", { -0.26, 0 }, 1 },
                            { "LevelP80", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP80", { 0.065, 0 }, 1 },
                            { "LevelP80", { 0.26, 0 }, 1 },
                            { "LevelP80", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_80 {
                        type = "text";
                        source = "static";
                        text = "80";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP80", { -0.234, 0.0416 }, 1 };
                        right[] = { "LevelP80", { -0.13, 0.0416 }, 1 };
                        down[] = { "LevelP80", { -0.234, 0.1066 }, 1 };
                    };
                    class LevelM85 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelM85", { -0.26, 0.1105 }, 1 },
                            { "LevelM85", { -0.221, 0.0884 }, 1 },
                            {},
                            { "LevelM85", { -0.182, 0.0663 }, 1 },
                            { "LevelM85", { -0.143, 0.0442 }, 1 },
                            {},
                            { "LevelM85", { -0.104, 0.0221 }, 1 },
                            { "LevelM85", { -0.065, 0 }, 1 },
                            { "LevelM85", { -0.065, -0.039 }, 1 },
                            {},
                            { "LevelM85", { 0.065, -0.039 }, 1 },
                            { "LevelM85", { 0.065, 0 }, 1 },
                            { "LevelM85", { 0.104, 0.0221 }, 1 },
                            {},
                            { "LevelM85", { 0.143, 0.0442 }, 1 },
                            { "LevelM85", { 0.182, 0.0663 }, 1 },
                            {},
                            { "LevelM85", { 0.221, 0.0884 }, 1 },
                            { "LevelM85", { 0.26, 0.1105 }, 1 }
                        };
                    };
                    class VALM_1_85 {
                        type = "text";
                        source = "static";
                        text = -85;
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM85", { -0.234, -0.1066 }, 1 };
                        right[] = { "LevelM85", { -0.13, -0.1066 }, 1 };
                        down[] = { "LevelM85", { -0.234, -0.0416 }, 1 };
                    };
                    class LevelP85 : Level0 {
                        type = "line";
                        points[] = {
                            { "LevelP85", { -0.26, 0.039 }, 1 },
                            { "LevelP85", { -0.26, 0 }, 1 },
                            { "LevelP85", { -0.065, 0 }, 1 },
                            {},
                            { "LevelP85", { 0.065, 0 }, 1 },
                            { "LevelP85", { 0.26, 0 }, 1 },
                            { "LevelP85", { 0.26, 0.039 }, 1 }
                        };
                    };
                    class VALP_1_85 {
                        type = "text";
                        source = "static";
                        text = "85";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP85", { -0.234, 0.0416 }, 1 };
                        right[] = { "LevelP85", { -0.13, 0.0416 }, 1 };
                        down[] = { "LevelP85", { -0.234, 0.1066 }, 1 };
                    };
                };
            };
            class RadarTargets {
                type = "radar";
                pos0[] = { 0.485, 0.4 };
                pos10[] = { 1.225, 1.1 };
                points[] = {
                    { { -0.05, -0.047297 }, 1 },
                    { { 0.05, -0.047297 }, 1 },
                    { { 0.05, 0.047297 }, 1 },
                    { { -0.05, 0.047297 }, 1 },
                    { { -0.05, -0.047297 }, 1 }
                };
            };
            class MGun {
                condition = "mgun";
                class Lines {
                    type = "line";
                    points[] = {
                        { "VelocityNotCenter", 0.001, "WeaponAim", 1, "HorizonBankMGun", { 0.26, 0 }, 1 },
                        { "VelocityNotCenter", 0.1, "WeaponAim", 1, "HorizonBankMGun", { 0.234, -0.013 }, 1 },
                        { "VelocityNotCenter", 0.2, "WeaponAim", 1, "HorizonBankMGun", { 0.208, -0.039 }, 1 },
                        { "VelocityNotCenter", 0.3, "WeaponAim", 1, "HorizonBankMGun", { 0.182, -0.078 }, 1 },
                        { "VelocityNotCenter", 0.4, "WeaponAim", 1, "HorizonBankMGun", { 0.156, -0.13 }, 1 },
                        { "VelocityNotCenter", 0.5, "WeaponAim", 1, "HorizonBankMGun", { 0.13, -0.195 }, 1 },
                        { "VelocityNotCenter", 0.6, "WeaponAim", 1, "HorizonBankMGun", { 0.104, -0.273 }, 1 },
                        { "VelocityNotCenter", 0.7, "WeaponAim", 1, "HorizonBankMGun", { 0.078, -0.364 }, 1 },
                        { "VelocityNotCenter", 0.8, "WeaponAim", 1, "HorizonBankMGun", { 0.052, -0.52 }, 1 },
                        {},
                        { "VelocityNotCenter", 0.001, "WeaponAim", 1, "HorizonBankMGun", { -0.26, 0 }, 1 },
                        { "VelocityNotCenter", 0.1, "WeaponAim", 1, "HorizonBankMGun", { -0.234, -0.013 }, 1 },
                        { "VelocityNotCenter", 0.2, "WeaponAim", 1, "HorizonBankMGun", { -0.208, -0.039 }, 1 },
                        { "VelocityNotCenter", 0.3, "WeaponAim", 1, "HorizonBankMGun", { -0.182, -0.078 }, 1 },
                        { "VelocityNotCenter", 0.4, "WeaponAim", 1, "HorizonBankMGun", { -0.156, -0.13 }, 1 },
                        { "VelocityNotCenter", 0.5, "WeaponAim", 1, "HorizonBankMGun", { -0.13, -0.195 }, 1 },
                        { "VelocityNotCenter", 0.6, "WeaponAim", 1, "HorizonBankMGun", { -0.104, -0.273 }, 1 },
                        { "VelocityNotCenter", 0.7, "WeaponAim", 1, "HorizonBankMGun", { -0.078, -0.364 }, 1 },
                        { "VelocityNotCenter", 0.8, "WeaponAim", 1, "HorizonBankMGun", { -0.052, -0.52 }, 1 }
                    };
                };
                class Crosshair {
                    type = "line";
                    points[] = {
                        { "WeaponAim", { 0.065, 0 }, 1 },
                        { "WeaponAim", { 0.0195, 0 }, 1 },
                        {},
                        { "WeaponAim", { 0, 0.051162 }, 1 },
                        { "WeaponAim", { 0, 0.015349 }, 1 },
                        {},
                        { "WeaponAim", { -0.065, 0 }, 1 },
                        { "WeaponAim", { -0.0195, 0 }, 1 },
                        {},
                        { "WeaponAim", { 0, -0.051162 }, 1 },
                        { "WeaponAim", { 0, -0.015349 }, 1 }
                    };
                };
            };
            class Bomb {
                condition = "bomb";
                class Circle {
                    type = "line";
                    points[] = {
                        { "WeaponAim", { 0, -0.221351 }, 1 },
                        { "WeaponAim", { 0.117, -0.192575 }, 1 },
                        { "WeaponAim", { 0.20358, -0.110676 }, 1 },
                        { "WeaponAim", { 0.234, 0 }, 1 },
                        { "WeaponAim", { 0.20358, 0.110676 }, 1 },
                        { "WeaponAim", { 0.117, 0.192575 }, 1 },
                        { "WeaponAim", { 0, 0.221351 }, 1 },
                        { "WeaponAim", { -0.117, 0.192575 }, 1 },
                        { "WeaponAim", { -0.20358, 0.110676 }, 1 },
                        { "WeaponAim", { -0.234, 0 }, 1 },
                        { "WeaponAim", { -0.20358, -0.110676 }, 1 },
                        { "WeaponAim", { -0.117, -0.192575 }, 1 },
                        { "WeaponAim", { 0, -0.221351 }, 1 },
                        {},
                        { "WeaponAim", { 0, -0.172162 }, 1 },
                        { "WeaponAim", { 0.091, -0.149781 }, 1 },
                        { "WeaponAim", { 0.15834, -0.086081 }, 1 },
                        { "WeaponAim", { 0.182, 0 }, 1 },
                        { "WeaponAim", { 0.15834, 0.086081 }, 1 },
                        { "WeaponAim", { 0.091, 0.149781 }, 1 },
                        { "WeaponAim", { 0, 0.172162 }, 1 },
                        { "WeaponAim", { -0.091, 0.149781 }, 1 },
                        { "WeaponAim", { -0.15834, 0.086081 }, 1 },
                        { "WeaponAim", { -0.182, 0 }, 1 },
                        { "WeaponAim", { -0.15834, -0.086081 }, 1 },
                        { "WeaponAim", { -0.091, -0.149781 }, 1 },
                        { "WeaponAim", { 0, -0.172162 }, 1 },
                        {},
                        { "TargetDistanceMissile", { 0, 0.135 }, 1 },
                        { "TargetDistanceMissile", { 0, 0.17 }, 1 },
                        {},
                        { "Velocity", 0.001, "WeaponAim", { 0, 0 }, 1 },
                        { "Velocity", { 0, 0 }, 1 },
                        {},
                        { "Target", { 0, -0.086081 }, 1 },
                        { "Target", { 0.091, 0 }, 1 },
                        { "Target", { 0, 0.086081 }, 1 },
                        { "Target", { -0.091, 0 }, 1 },
                        { "Target", { 0, -0.086081 }, 1 }
                    };
                };
            };
            class AAMissile {
                condition = "AAmissile";
                class tDistLabelAA {
                    type = "text";
                    source = "static";
                    text = "TGT:";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = { { 0.85, 0.6 }, 1 };
                    right[] = { { 0.9, 0.6 }, 1 };
                    down[] = { { 0.85, 0.65 }, 1 };
                };
                class tDistNumberAA {
                    type = "text";
                    source = "targetDist";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = { { 0.85, 0.65 }, 1 };
                    right[] = { { 0.9, 0.65 }, 1 };
                    down[] = { { 0.85, 0.7 }, 1 };
                };
                class Circle {
                    type = "line";
                    points[] = {
                        { "TargetDistanceMissile", { 0, 0.14 }, 1 },
                        { "TargetDistanceMissile", { 0, 0.175 }, 1 },
                        {},
                        { "WeaponAim", { 0, -0.307432 }, 1 },
                        { "WeaponAim", { 0.1625, -0.267466 }, 1 },
                        { "WeaponAim", { 0.28275, -0.153716 }, 1 },
                        { "WeaponAim", { 0.325, 0 }, 1 },
                        { "WeaponAim", { 0.28275, 0.153716 }, 1 },
                        { "WeaponAim", { 0.1625, 0.267466 }, 1 },
                        { "WeaponAim", { 0, 0.307432 }, 1 },
                        { "WeaponAim", { -0.1625, 0.267466 }, 1 },
                        { "WeaponAim", { -0.28275, 0.153716 }, 1 },
                        { "WeaponAim", { -0.325, 0 }, 1 },
                        { "WeaponAim", { -0.28275, -0.153716 }, 1 },
                        { "WeaponAim", { -0.1625, -0.267466 }, 1 },
                        { "WeaponAim", { 0, -0.307432 }, 1 },
                        {},
                        { "Target", { 0, -0.086081 }, 1 },
                        { "Target", { 0.091, 0 }, 1 },
                        { "Target", { 0, 0.086081 }, 1 },
                        { "Target", { -0.091, 0 }, 1 },
                        { "Target", { 0, -0.086081 }, 1 }
                    };
                };
            };
            class ATMissile {
                condition = "ATmissile";
                class tDistLabelAT {
                    type = "text";
                    source = "static";
                    text = "TGT:";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = { { 0.85, 0.6 }, 1 };
                    right[] = { { 0.9, 0.6 }, 1 };
                    down[] = { { 0.85, 0.65 }, 1 };
                };
                class tDistNumberAT {
                    type = "text";
                    source = "targetDist";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = { { 0.85, 0.65 }, 1 };
                    right[] = { { 0.9, 0.65 }, 1 };
                    down[] = { { 0.85, 0.7 }, 1 };
                };
                class Circle {
                    type = "line";
                    points[] = {
                        { "TargetDistanceMissile", { 0, 0.14 }, 1 },
                        { "TargetDistanceMissile", { 0, 0.175 }, 1 },
                        {},
                        { "WeaponAim", { 0, -0.221351 }, 1 },
                        { "WeaponAim", { 0.117, -0.192575 }, 1 },
                        { "WeaponAim", { 0.20358, -0.110676 }, 1 },
                        { "WeaponAim", { 0.234, 0 }, 1 },
                        { "WeaponAim", { 0.20358, 0.110676 }, 1 },
                        { "WeaponAim", { 0.117, 0.192575 }, 1 },
                        { "WeaponAim", { 0, 0.221351 }, 1 },
                        { "WeaponAim", { -0.117, 0.192575 }, 1 },
                        { "WeaponAim", { -0.20358, 0.110676 }, 1 },
                        { "WeaponAim", { -0.234, 0 }, 1 },
                        { "WeaponAim", { -0.20358, -0.110676 }, 1 },
                        { "WeaponAim", { -0.117, -0.192575 }, 1 },
                        { "WeaponAim", { 0, -0.221351 }, 1 },
                        {},
                        { "Target", { 0, -0.086081 }, 1 },
                        { "Target", { 0.091, 0 }, 1 },
                        { "Target", { 0, 0.086081 }, 1 },
                        { "Target", { -0.091, 0 }, 1 },
                        { "Target", { 0, -0.086081 }, 1 }
                    };
                };
            };
            class Rockets {
                condition = "Rocket";
                class Circle {
                    type = "line";
                    points[] = {
                        { "WeaponAim", { 0.013, 0 }, 1 },
                        { "WeaponAim", { -0.013, 0 }, 1 },
                        {},
                        { "WeaponAim", { 0, 0.012297 }, 1 },
                        { "WeaponAim", { 0, -0.012297 }, 1 },
                        {},
                        { "WeaponAim", { 0, -0.147568 }, 1 },
                        { "WeaponAim", { 0.078, -0.128384 }, 1 },
                        { "WeaponAim", { 0.13572, -0.073784 }, 1 },
                        { "WeaponAim", { 0.156, 0 }, 1 },
                        { "WeaponAim", { 0.13572, 0.073784 }, 1 },
                        { "WeaponAim", { 0.078, 0.128384 }, 1 },
                        { "WeaponAim", { 0, 0.147568 }, 1 },
                        { "WeaponAim", { -0.078, 0.128384 }, 1 },
                        { "WeaponAim", { -0.13572, 0.073784 }, 1 },
                        { "WeaponAim", { -0.156, 0 }, 1 },
                        { "WeaponAim", { -0.13572, -0.073784 }, 1 },
                        { "WeaponAim", { -0.078, -0.128384 }, 1 },
                        { "WeaponAim", { 0, -0.147568 }, 1 },
                        {}
                    };
                };
            };
            class AltNumber {
                type = "text";
                source = "altitudeAGL";
                scale = 1;
                sourceScale = 3.28084;
                align = "center";
                pos[] = { { 0.9, 0.311856 }, 1 };
                right[] = { { 0.96, 0.311856 }, 1 };
                down[] = { { 0.9, 0.368557 }, 1 };
            };
            class Gear {
                condition = "ils";
                class text {
                    type = "text";
                    source = "static";
                    text = "GEAR";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = { { 0.84, 0.85 }, 1 };
                    right[] = { { 0.9, 0.85 }, 1 };
                    down[] = { { 0.84, 0.89 }, 1 };
                };
            };
            class Flaps {
                condition = "flaps";
                class text {
                    type = "text";
                    source = "static";
                    text = "FLAPS";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = { { 0.84, 0.9 }, 1 };
                    right[] = { { 0.9, 0.9 }, 1 };
                    down[] = { { 0.84, 0.94 }, 1 };
                };
            };
            class weapons {
                type = "text";
                source = "weapon";
                align = "right";
                scale = 1;
                sourceScale = 1;
                pos[] = { { 0.1, 0.88 }, 1 };
                right[] = { { 0.15, 0.88 }, 1 };
                down[] = { { 0.1, 0.92 }, 1 };
            };
            class ammo {
                type = "text";
                source = "ammo";
                align = "center";
                scale = 1;
                sourceScale = 1;
                pos[] = { { 0.1, 0.93 }, 1 };
                right[] = { { 0.15, 0.93 }, 1 };
                down[] = { { 0.1, 0.97 }, 1 };
            };
            class FuelLabel {
                condition = "on";
                class text {
                    type = "text";
                    source = "static";
                    text = "FUEL:";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = { { 0.84, 0.945 }, 1 };
                    right[] = { { 0.89, 0.945 }, 1 };
                    down[] = { { 0.84, 0.99 }, 1 };
                };
            };
            class Fuel {
                type = "text";
                source = "fuel";
                align = "right";
                scale = 1;
                sourceScale = 100;
                pos[] = { { 0.945, 0.95 }, 1 };
                right[] = { { 0.995, 0.95 }, 1 };
                down[] = { { 0.945, 0.99 }, 1 };
            };
            class VspeedLabel {
                condition = "on";
                class text {
                    type = "text";
                    source = "static";
                    text = "V.SPD:";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = { { 0.8, 0.12 }, 1 };
                    right[] = { { 0.85, 0.12 }, 1 };
                    down[] = { { 0.8, 0.17 }, 1 };
                };
            };
            class VspeedNumber {
                type = "text";
                align = "right";
                scale = 1;
                source = "vspeed";
                sourceScale = 196.85;
                pos[] = { { 0.92, "0.52-0.4" }, 1 };
                right[] = { { 0.98, "0.52-0.4" }, 1 };
                down[] = { { 0.92, "0.57-0.4" }, 1 };
            };
            class HeadingScale {
                type = "scale";
                scale = 1;
                source = "Heading";
                sourceScale = 1;
                align = "center";
                pos[] = { "0.21-0.01", 0 };
                right[] = { "0.29-0.01", 0 };
                down[] = { "0.21-0.01", 0.05 };
                lineXleft = 0.06;
                lineYright = 0.05;
                lineXleftMajor = 0.06;
                lineYrightMajor = 0.04;
                bottom = 0.8;
                center = 0.5;
                top = 0.2;
                step = "18/9";
                StepSize = "(0.80- 0.2)/20";
                horizontal = 1;
                min = "none";
                max = "none";
                numberEach = 5;
                majorLineEach = 5;
            };
            class ILS {
                condition = "ils";
                class Glideslope {
                    clipTL[] = { 0, 0 };
                    clipBR[] = { 1, 1 };
                    class ILS {
                        type = "line";
                        points[] = {
                            { "ILS_W", { -0.312, 0 }, 1 },
                            { "ILS_W", { 0.312, 0 }, 1 },
                            {},
                            { "ILS_W", { 0, 0.029514 }, 1 },
                            { "ILS_W", { 0, -0.029514 }, 1 },
                            {},
                            { "ILS_W", { 0.156, 0.029514 }, 1 },
                            { "ILS_W", { 0.156, -0.029514 }, 1 },
                            {},
                            { "ILS_W", { 0.312, 0.029514 }, 1 },
                            { "ILS_W", { 0.312, -0.029514 }, 1 },
                            {},
                            { "ILS_W", { -0.156, 0.029514 }, 1 },
                            { "ILS_W", { -0.156, -0.029514 }, 1 },
                            {},
                            { "ILS_W", { -0.312, 0.029514 }, 1 },
                            { "ILS_W", { -0.312, -0.029514 }, 1 },
                            {},
                            { "ILS_H", { 0, -0.295135 }, 1 },
                            { "ILS_H", { 0, 0.295135 }, 1 },
                            {},
                            { "ILS_H", { 0.0312, 0 }, 1 },
                            { "ILS_H", { -0.0312, 0 }, 1 },
                            {},
                            { "ILS_H", { 0.0312, 0.147568 }, 1 },
                            { "ILS_H", { -0.0312, 0.147568 }, 1 },
                            {},
                            { "ILS_H", { 0.0312, 0.295135 }, 1 },
                            { "ILS_H", { -0.0312, 0.295135 }, 1 },
                            {},
                            { "ILS_H", { 0.0312, -0.147568 }, 1 },
                            { "ILS_H", { -0.0312, -0.147568 }, 1 },
                            {},
                            { "ILS_H", { 0.0312, -0.295135 }, 1 },
                            { "ILS_H", { -0.0312, -0.295135 }, 1 }
                        };
                    };
                };
            };
            class CentreDot {
                type = "line";
                width = 4;
                points[] = {
                    { "PlaneW", { 0, -0.0052 }, 1 },
                    { "PlaneW", { 0, 0.0052 }, 1 },
                    {},
                    { "PlaneW", { -0.0052, 0 }, 1 },
                    { "PlaneW", { 0.0052, 0 }, 1 }
                };
            };
            class TGPSquare {
                condition = "pilotcameralock";
                class Box {
                    type = "line";
                    width = 2;
                    points[] = {
                        { "TGPTarget", 1, "TGPLimit", 1, { -0.052, -0.052 }, 1 },
                        { "TGPTarget", 1, "TGPLimit", 1, { 0.052, -0.052 }, 1 },
                        { "TGPTarget", 1, "TGPLimit", 1, { 0.052, 0.052 }, 1 },
                        { "TGPTarget", 1, "TGPLimit", 1, { -0.052, 0.052 }, 1 },
                        { "TGPTarget", 1, "TGPLimit", 1, { -0.052, -0.052 }, 1 }
                    };
                };
            };
        };
        enableParallax = 1;
    };
    class MFD_LH;
    class MFD_RH;
};
