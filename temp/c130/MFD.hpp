class MFD {
    class AirplaneHUD {
        topLeft = "HUD LH";
        topRight = "HUD PH";
        bottomLeft = "HUD LD";
        borderLeft = 0;
        borderRight = 0;
        borderTop = 0;
        borderBottom = 0;
        color[] = { 0.15, 1, 0.15, 1 };
        enableParallax = 0;
        class Bones {
            class PlaneOrientation {
                type = "fixed";
                pos[] = { 0.5, "0.53 + -0.13" };
            };
            class WeaponAim {
                type = "vector";
                source = "weapon";
                pos0[] = { 0.5, "0.53 + -0.13" };
                pos10[] = { 1.5, "1.53 + -0.13 + -0.25" };
            };
            class Velocity {
                type = "vector";
                source = "velocity";
                pos0[] = { 0.5, "0.53 + -0.13" };
                pos10[] = { 1.5, "1.53 + -0.13 + -0.25" };
            };
            class Level0 {
                type = "horizon";
                pos0[] = { 0.5, "0.53 + -0.13" };
                pos10[] = { 1.5, "1.53 + -0.13 + -0.25" };
                angle = 0;
            };
            class ILS_H {
                type = "ils";
                pos0[] = { 0.5, 0.3 };
                pos3[] = { 0.62, 0.3 };
            };
            class ILS_W : ILS_H {
                pos3[] = { 0.5, 0.435 };
            };
            class TerrainBone {
                type = "linear";
                source = "altitudeAGL";
                sourceScale = 1;
                min = 0;
                max = 200;
                minPos[] = { 0, 0.666 };
                maxPos[] = { 0, 0.4 };
            };
        };
        class Draw {
            color[] = { 0.18, 1, 0.18 };
            alpha = 0.9;
            condition = "on";
            class Horizont {
                clipTL[] = { 0.15, 0.15 };
                clipBR[] = { 0.85, 0.85 };
                class Dimmed {
                    class Level00 {
                        type = "line";
                        width = 4;
                        points[] = { { "Level0", { "-0.200 * 1.4", "0 * 1.4" }, 1 }, { "Level0", { "-0.125 * 1.4", "0 * 1.4" }, 1 }, {}, { "Level0", { "-0.045 * 1.4", "0 * 1.4" }, 1 }, { "Level0", { "-0.005 * 1.4", "0 * 1.4" }, 1 }, {}, { "Level0", { "0.005 * 1.4", "0 * 1.4" }, 1 }, { "Level0", { "0.045 * 1.4", "0 * 1.4" }, 1 }, {}, { "Level0", { "0.125 * 1.4", "0 * 1.4" }, 1 }, { "Level0", { "0.200 * 1.4", "0 * 1.4" }, 1 } };
                    };
                    class Level2M5 : Level00 {
                        type = "line";
                        points[] = { { "Level0", { "-0.200 * 1.4", "-1.0 / 10 * 5" }, 1 }, { "Level0", { "-0.125 * 1.4", "-1.0 / 10 * 5" }, 1 }, {}, { "Level0", { "+0.125 * 1.4", "-1.0 / 10 * 5" }, 1 }, { "Level0", { "+0.200 * 1.4", "-1.0 / 10 * 5" }, 1 } };
                    };
                    class VALM2_1_5 {
                        type = "text";
                        source = "static";
                        text = 5;
                        align = "center";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "Level0", { "0.000 * 1.4", "-0.020 * 1.4 - 1.0 / 10 * 5" }, 1 };
                        right[] = { "Level0", { "0.050 * 1.4", "-0.020 * 1.4 - 1.0 / 10 * 5" }, 1 };
                        down[] = { "Level0", { "0.000 * 1.4", "+0.020 * 1.4 - 1.0 / 10 * 5" }, 1 };
                    };
                    class Level2P5 : Level00 {
                        type = "line";
                        points[] = { { "Level0", { "-0.200 * 1.4", "+1.0 / 10 * 5" }, 1 }, { "Level0", { "-0.125 * 1.4", "+1.0 / 10 * 5" }, 1 }, {}, { "Level0", { "+0.125 * 1.4", "+1.0 / 10 * 5" }, 1 }, { "Level0", { "+0.200 * 1.4", "+1.0 / 10 * 5" }, 1 } };
                    };
                    class VALP2_1_5 {
                        type = "text";
                        source = "static";
                        text = -5;
                        align = "center";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "Level0", { "0.000 * 1.4", "-0.020 * 1.4 + 1.0 / 10 * 5" }, 1 };
                        right[] = { "Level0", { "0.050 * 1.4", "-0.020 * 1.4 + 1.0 / 10 * 5" }, 1 };
                        down[] = { "Level0", { "0.000 * 1.4", "+0.020 * 1.4 + 1.0 / 10 * 5" }, 1 };
                    };
                    class Level2M10 : Level00 {
                        type = "line";
                        points[] = { { "Level0", { "-0.200 * 1.4", "-1.0 / 10 * 10" }, 1 }, { "Level0", { "-0.125 * 1.4", "-1.0 / 10 * 10" }, 1 }, {}, { "Level0", { "+0.125 * 1.4", "-1.0 / 10 * 10" }, 1 }, { "Level0", { "+0.200 * 1.4", "-1.0 / 10 * 10" }, 1 } };
                    };
                    class VALM2_1_10 {
                        type = "text";
                        source = "static";
                        text = 10;
                        align = "center";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "Level0", { "0.000 * 1.4", "-0.020 * 1.4 - 1.0 / 10 * 10" }, 1 };
                        right[] = { "Level0", { "0.050 * 1.4", "-0.020 * 1.4 - 1.0 / 10 * 10" }, 1 };
                        down[] = { "Level0", { "0.000 * 1.4", "+0.020 * 1.4 - 1.0 / 10 * 10" }, 1 };
                    };
                    class Level2P10 : Level00 {
                        type = "line";
                        points[] = { { "Level0", { "-0.200 * 1.4", "+1.0 / 10 * 10" }, 1 }, { "Level0", { "-0.125 * 1.4", "+1.0 / 10 * 10" }, 1 }, {}, { "Level0", { "+0.125 * 1.4", "+1.0 / 10 * 10" }, 1 }, { "Level0", { "+0.200 * 1.4", "+1.0 / 10 * 10" }, 1 } };
                    };
                    class VALP2_1_10 {
                        type = "text";
                        source = "static";
                        text = -10;
                        align = "center";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "Level0", { "0.000 * 1.4", "-0.020 * 1.4 + 1.0 / 10 * 10" }, 1 };
                        right[] = { "Level0", { "0.050 * 1.4", "-0.020 * 1.4 + 1.0 / 10 * 10" }, 1 };
                        down[] = { "Level0", { "0.000 * 1.4", "+0.020 * 1.4 + 1.0 / 10 * 10" }, 1 };
                    };
                    class Level2M15 : Level00 {
                        type = "line";
                        points[] = { { "Level0", { "-0.200 * 1.4", "-1.0 / 10 * 15" }, 1 }, { "Level0", { "-0.125 * 1.4", "-1.0 / 10 * 15" }, 1 }, {}, { "Level0", { "+0.125 * 1.4", "-1.0 / 10 * 15" }, 1 }, { "Level0", { "+0.200 * 1.4", "-1.0 / 10 * 15" }, 1 } };
                    };
                    class VALM2_1_15 {
                        type = "text";
                        source = "static";
                        text = 15;
                        align = "center";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "Level0", { "0.000 * 1.4", "-0.020 * 1.4 - 1.0 / 10 * 15" }, 1 };
                        right[] = { "Level0", { "0.050 * 1.4", "-0.020 * 1.4 - 1.0 / 10 * 15" }, 1 };
                        down[] = { "Level0", { "0.000 * 1.4", "+0.020 * 1.4 - 1.0 / 10 * 15" }, 1 };
                    };
                    class Level2P15 : Level00 {
                        type = "line";
                        points[] = { { "Level0", { "-0.200 * 1.4", "+1.0 / 10 * 15" }, 1 }, { "Level0", { "-0.125 * 1.4", "+1.0 / 10 * 15" }, 1 }, {}, { "Level0", { "+0.125 * 1.4", "+1.0 / 10 * 15" }, 1 }, { "Level0", { "+0.200 * 1.4", "+1.0 / 10 * 15" }, 1 } };
                    };
                    class VALP2_1_15 {
                        type = "text";
                        source = "static";
                        text = -15;
                        align = "center";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "Level0", { "0.000 * 1.4", "-0.020 * 1.4 + 1.0 / 10 * 15" }, 1 };
                        right[] = { "Level0", { "0.050 * 1.4", "-0.020 * 1.4 + 1.0 / 10 * 15" }, 1 };
                        down[] = { "Level0", { "0.000 * 1.4", "+0.020 * 1.4 + 1.0 / 10 * 15" }, 1 };
                    };
                };
            };
            class PlaneOrientationCrosshair {
                type = "line";
                width = 4;
                points[] = { { "PlaneOrientation", { -0.125, 0 }, 1 }, { "PlaneOrientation", { -0.05, 0 }, 1 }, { "PlaneOrientation", { -0.025, 0.05 }, 1 }, { "PlaneOrientation", { 0, 0 }, 1 }, { "PlaneOrientation", { 0.025, 0.05 }, 1 }, { "PlaneOrientation", { 0.05, 0 }, 1 }, { "PlaneOrientation", { 0.125, 0 }, 1 } };
            };
            class PlaneMovementCrosshair {
                type = "line";
                width = 4;
                points[] = { { "Velocity", { 0, -0.02 }, 1 }, { "Velocity", { 0.01, -0.01732 }, 1 }, { "Velocity", { 0.01732, -0.01 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, { "Velocity", { 0.01732, 0.01 }, 1 }, { "Velocity", { 0.01, 0.01732 }, 1 }, { "Velocity", { 0, 0.02 }, 1 }, { "Velocity", { -0.01, 0.01732 }, 1 }, { "Velocity", { -0.01732, 0.01 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, { "Velocity", { -0.01732, -0.01 }, 1 }, { "Velocity", { -0.01, -0.01732 }, 1 }, { "Velocity", { 0, -0.02 }, 1 }, {}, { "Velocity", { 0.04, 0 }, 1 }, { "Velocity", { 0.02, 0 }, 1 }, {}, { "Velocity", { -0.04, 0 }, 1 }, { "Velocity", { -0.02, 0 }, 1 }, {}, { "Velocity", { 0, -0.04 }, 1 }, { "Velocity", { 0, -0.02 }, 1 } };
            };
            class WeaponName {
                type = "text";
                source = "weapon";
                sourceScale = 1;
                align = "right";
                scale = 1;
                pos[] = { { 0.03, 0.94 }, 1 };
                right[] = { { 0.08, 0.94 }, 1 };
                down[] = { { 0.03, 0.98 }, 1 };
            };
            class AmmoCount {
                type = "text";
                source = "ammo";
                sourceScale = 1;
                align = "right";
                scale = 1;
                pos[] = { { 0.03, 0.89 }, 1 };
                right[] = { { 0.08, 0.89 }, 1 };
                down[] = { { 0.03, 0.93 }, 1 };
            };
            class FlapsGroup {
                type = "group";
                condition = "flaps";
                class FlapsText {
                    type = "text";
                    source = "static";
                    text = "FLAPS";
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.03, "0.53 - 0.045" }, 1 };
                    right[] = { { 0.08, "0.53 - 0.045" }, 1 };
                    down[] = { { 0.03, "0.53 - 0.005" }, 1 };
                };
            };
            class GearGroup {
                type = "group";
                condition = "ils";
                class GearText {
                    type = "text";
                    source = "static";
                    text = "GEAR";
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.03, "0.53 + 0.005" }, 1 };
                    right[] = { { 0.08, "0.53 + 0.005" }, 1 };
                    down[] = { { 0.03, "0.53 + 0.045" }, 1 };
                };
            };
            class StallGroup {
                type = "group";
                condition = "stall";
                color[] = { 1, 0, 0 };
                blinkingPattern[] = { 0.2, 0.2 };
                blinkingStartsOn = 1;
                class StallText {
                    type = "text";
                    source = "static";
                    text = "STALL";
                    align = "center";
                    scale = 1;
                    pos[] = { { 0.5, "0.53 - 0.25" }, 1 };
                    right[] = { { 0.55, "0.53 - 0.25" }, 1 };
                    down[] = { { 0.5, "0.53 - 0.21" }, 1 };
                };
            };
            class LightsGroup {
                type = "group";
                condition = "lights";
                class LightsText {
                    type = "text";
                    source = "static";
                    text = "LIGHTS";
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.03, "0.53 + 0.055" }, 1 };
                    right[] = { { 0.08, "0.53 + 0.055" }, 1 };
                    down[] = { { 0.03, "0.53 + 0.095" }, 1 };
                };
            };
            class CollisionLightsGroup {
                type = "group";
                condition = "collisionlights";
                class CollisionLightsText {
                    type = "text";
                    source = "static";
                    text = "A-COL";
                    align = "right";
                    scale = 1;
                    pos[] = { { 0.03, "0.53 + 0.105" }, 1 };
                    right[] = { { 0.08, "0.53 + 0.105" }, 1 };
                    down[] = { { 0.03, "0.53 + 0.145" }, 1 };
                };
            };
            class PitchNumber {
                type = "text";
                source = "horizonDive";
                sourceScale = 57.2958;
                align = "right";
                scale = 1;
                pos[] = { { 0.51, 0.89 }, 1 };
                right[] = { { 0.56, 0.89 }, 1 };
                down[] = { { 0.51, 0.93 }, 1 };
            };
            class PitchText {
                type = "text";
                source = "static";
                text = "PITCH";
                align = "left";
                scale = 1;
                pos[] = { { 0.49, 0.89 }, 1 };
                right[] = { { 0.54, 0.89 }, 1 };
                down[] = { { 0.49, 0.93 }, 1 };
            };
            class RollNumber {
                type = "text";
                source = "horizonBank";
                sourceScale = 57.2958;
                align = "right";
                scale = 1;
                pos[] = { { 0.51, 0.94 }, 1 };
                right[] = { { 0.56, 0.94 }, 1 };
                down[] = { { 0.51, 0.98 }, 1 };
            };
            class RollText {
                type = "text";
                source = "static";
                text = "ROLL";
                align = "left";
                scale = 1;
                pos[] = { { 0.49, 0.94 }, 1 };
                right[] = { { 0.54, 0.94 }, 1 };
                down[] = { { 0.49, 0.98 }, 1 };
            };
            class SpeedNumber {
                type = "text";
                source = "speed";
                sourceScale = 1.94384;
                align = "right";
                scale = 1;
                pos[] = { { 0.13, 0.14 }, 1 };
                right[] = { { 0.18, 0.14 }, 1 };
                down[] = { { 0.13, 0.18 }, 1 };
            };
            class SpeedText {
                type = "text";
                source = "static";
                text = "IAS";
                align = "left";
                scale = 1;
                pos[] = { { 0.11, 0.14 }, 1 };
                right[] = { { 0.16, 0.14 }, 1 };
                down[] = { { 0.11, 0.18 }, 1 };
            };
            class TerrainGroup {
                type = "group";
                clipTL[] = { 0, 0 };
                clipBR[] = { 1, 0.6 };
                class TerrainArrow {
                    type = "line";
                    width = 4;
                    points[] = { { { "0.86 - 0.018", 0.4 }, 1 }, { { 0.86, 0.4 }, 1 }, {}, { "TerrainBone", { "0.86 - 0.018", "0.0 - 0.016" }, 1 }, { "TerrainBone", { 0.86, 0 }, 1 }, { "TerrainBone", { "0.86 - 0.018", "0.0 + 0.016" }, 1 } };
                };
            };
            class TerrainText {
                type = "text";
                source = "static";
                text = "ATL";
                align = "left";
                scale = 1;
                pos[] = { { 0.85, 0.1 }, 1 };
                right[] = { { 0.9, 0.1 }, 1 };
                down[] = { { 0.85, 0.14 }, 1 };
            };
            class TerrainNumber {
                type = "text";
                source = "altitudeAGL";
                sourceScale = 3.28084;
                align = "left";
                scale = 1;
                pos[] = { { 0.85, 0.14 }, 1 };
                right[] = { { 0.9, 0.14 }, 1 };
                down[] = { { 0.85, 0.18 }, 1 };
            };
            class AltitudeNumber {
                type = "text";
                source = "altitudeASL";
                sourceScale = 3.28084;
                align = "right";
                scale = 1;
                pos[] = { { 0.89, 0.14 }, 1 };
                right[] = { { 0.94, 0.14 }, 1 };
                down[] = { { 0.89, 0.18 }, 1 };
            };
            class AltitudeText {
                type = "text";
                source = "static";
                text = "ASL";
                align = "right";
                scale = 1;
                pos[] = { { 0.89, 0.1 }, 1 };
                right[] = { { 0.94, 0.1 }, 1 };
                down[] = { { 0.89, 0.14 }, 1 };
            };
            class AltitudeArrow {
                type = "line";
                width = 4;
                points[] = { { { "0.88 + 0.018", "0.40 - 0.016" }, 1 }, { { 0.88, 0.4 }, 1 }, { { "0.88 + 0.018", "0.40 + 0.016" }, 1 } };
            };
            class AltitudeLine {
                type = "line";
                width = 4;
                points[] = { { { 0.87, 0.6 }, 1 }, { { 0.87, 0.2 }, 1 } };
            };
            class AltitudeScale {
                type = "scale";
                horizontal = 0;
                source = "altitudeASL";
                sourceScale = 3.28084;
                width = 4;
                top = 0.6;
                center = 0.4;
                bottom = 0.2;
                lineXleft = 0.88;
                lineYright = 0.89;
                lineXleftMajor = 0.88;
                lineYrightMajor = 0.9;
                majorLineEach = 5;
                numberEach = 5;
                step = 20;
                stepSize = "(0.60 - 0.20) / 15";
                align = "right";
                scale = 1;
                pos[] = { 0.91, 0.58 };
                right[] = { 0.96, 0.58 };
                down[] = { 0.91, 0.62 };
            };
            class ClimbNumber {
                type = "text";
                source = "vspeed";
                sourceScale = 1;
                align = "right";
                scale = 1;
                pos[] = { { 0.89, 0.94 }, 1 };
                right[] = { { 0.94, 0.94 }, 1 };
                down[] = { { 0.89, 0.98 }, 1 };
            };
            class ClimbText {
                type = "text";
                source = "static";
                text = "CLIMB";
                align = "left";
                scale = 1;
                pos[] = { { 0.87, 0.94 }, 1 };
                right[] = { { 0.92, 0.94 }, 1 };
                down[] = { { 0.87, 0.98 }, 1 };
            };
            class ClimbArrow {
                type = "line";
                width = 4;
                points[] = { { { "0.88 + 0.018", "0.80 - 0.016" }, 1 }, { { 0.88, 0.8 }, 1 }, { { "0.88 + 0.018", "0.80 + 0.016" }, 1 } };
            };
            class ClimbLine {
                type = "line";
                width = 4;
                points[] = { { { 0.87, 0.925 }, 1 }, { { 0.87, 0.675 }, 1 } };
            };
            class ClimbScale {
                type = "scale";
                horizontal = 0;
                source = "vspeed";
                sourceScale = 1;
                width = 4;
                top = 0.925;
                center = 0.8;
                bottom = 0.675;
                lineXleft = 0.88;
                lineYright = 0.89;
                lineXleftMajor = 0.88;
                lineYrightMajor = 0.9;
                majorLineEach = 2;
                numberEach = 4;
                step = 5;
                stepSize = "(0.925 - 0.675) / 15";
                align = "right";
                scale = 1;
                pos[] = { 0.91, 0.905 };
                right[] = { 0.96, 0.905 };
                down[] = { 0.91, 0.945 };
            };
            class HeadingArrow {
                type = "line";
                width = 3;
                points[] = { { { "0.5 - 0.02", "0.11 - 0.02" }, 1 }, { { 0.5, 0.11 }, 1 }, { { "0.5 + 0.02", "0.11 - 0.02" }, 1 } };
            };
            class HeadingLine {
                type = "line";
                width = 4;
                points[] = { { { 0.3, 0.12 }, 1 }, { { 0.7, 0.12 }, 1 } };
            };
            class HeadingScale {
                type = "scale";
                horizontal = 1;
                source = "heading";
                sourceScale = 1;
                width = 4;
                top = 0.3;
                center = 0.5;
                bottom = 0.7;
                lineXleft = "0.06 + 0.05";
                lineYright = "0.05 + 0.05";
                lineXleftMajor = "0.06 + 0.05";
                lineYrightMajor = "0.04 + 0.05";
                majorLineEach = 5;
                numberEach = 5;
                step = "18 / 9";
                stepSize = "(0.70 - 0.3) / 15";
                align = "center";
                scale = 1;
                pos[] = { 0.3, "0.0 + 0.05" };
                right[] = { 0.35, "0.0 + 0.05" };
                down[] = { 0.3, "0.04 + 0.05" };
            };
            class AAMissileCrosshairGroup {
                type = "group";
                condition = "AAmissile";
                class AAMissileCrosshair {
                    type = "line";
                    width = 4;
                    points[] = { { "WeaponAim", { 0, -0.25 }, 1 }, { "WeaponAim", { 0.0434, -0.2462 }, 1 }, { "WeaponAim", { 0.0855, -0.234925 }, 1 }, { "WeaponAim", { 0.125, -0.2165 }, 1 }, { "WeaponAim", { 0.1607, -0.1915 }, 1 }, { "WeaponAim", { 0.1915, -0.1607 }, 1 }, { "WeaponAim", { 0.2165, -0.125 }, 1 }, { "WeaponAim", { 0.234925, -0.0855 }, 1 }, { "WeaponAim", { 0.2462, -0.0434 }, 1 }, { "WeaponAim", { 0.25, 0 }, 1 }, { "WeaponAim", { 0.2462, 0.0434 }, 1 }, { "WeaponAim", { 0.234925, 0.0855 }, 1 }, { "WeaponAim", { 0.2165, 0.125 }, 1 }, { "WeaponAim", { 0.1915, 0.1607 }, 1 }, { "WeaponAim", { 0.1607, 0.1915 }, 1 }, { "WeaponAim", { 0.125, 0.2165 }, 1 }, { "WeaponAim", { 0.0855, 0.234925 }, 1 }, { "WeaponAim", { 0.0434, 0.2462 }, 1 }, { "WeaponAim", { 0, 0.25 }, 1 }, { "WeaponAim", { -0.0434, 0.2462 }, 1 }, { "WeaponAim", { -0.0855, 0.234925 }, 1 }, { "WeaponAim", { -0.125, 0.2165 }, 1 }, { "WeaponAim", { -0.1607, 0.1915 }, 1 }, { "WeaponAim", { -0.1915, 0.1607 }, 1 }, { "WeaponAim", { -0.2165, 0.125 }, 1 }, { "WeaponAim", { -0.234925, 0.0855 }, 1 }, { "WeaponAim", { -0.2462, 0.0434 }, 1 }, { "WeaponAim", { -0.25, 0 }, 1 }, { "WeaponAim", { -0.2462, -0.0434 }, 1 }, { "WeaponAim", { -0.234925, -0.0855 }, 1 }, { "WeaponAim", { -0.2165, -0.125 }, 1 }, { "WeaponAim", { -0.1915, -0.1607 }, 1 }, { "WeaponAim", { -0.1607, -0.1915 }, 1 }, { "WeaponAim", { -0.125, -0.2165 }, 1 }, { "WeaponAim", { -0.0855, -0.234925 }, 1 }, { "WeaponAim", { -0.0434, -0.2462 }, 1 }, { "WeaponAim", { 0, -0.25 }, 1 } };
                };
            };
            class ATMissileCrosshairGroup {
                condition = "ATmissile";
                type = "group";
                class ATMissileCrosshair {
                    type = "line";
                    width = 4;
                    points[] = { { "WeaponAim", { -0.15, -0.15 }, 1 }, { "WeaponAim", { -0.15, "-0.15 + 0.02" }, 1 }, {}, { "WeaponAim", { -0.15, 0.15 }, 1 }, { "WeaponAim", { -0.15, "0.15 - 0.02" }, 1 }, {}, { "WeaponAim", { 0.15, -0.15 }, 1 }, { "WeaponAim", { 0.15, "-0.15 + 0.02" }, 1 }, {}, { "WeaponAim", { 0.15, 0.15 }, 1 }, { "WeaponAim", { 0.15, "0.15 - 0.02" }, 1 }, {}, { "WeaponAim", { -0.15, -0.15 }, 1 }, { "WeaponAim", { "-0.15 + 0.02", -0.15 }, 1 }, {}, { "WeaponAim", { -0.15, 0.15 }, 1 }, { "WeaponAim", { "-0.15 + 0.02", 0.15 }, 1 }, {}, { "WeaponAim", { 0.15, -0.15 }, 1 }, { "WeaponAim", { "0.15 - 0.02", -0.15 }, 1 }, {}, { "WeaponAim", { 0.15, 0.15 }, 1 }, { "WeaponAim", { "0.15 - 0.02", 0.15 }, 1 } };
                };
            };
            class BombCrosshairGroup {
                type = "group";
                condition = "bomb";
                class BombCrosshair {
                    type = "line";
                    width = 4;
                    points[] = { { "WeaponAim", { 0, -0.1 }, 1 }, { "WeaponAim", { 0.01736, -0.09848 }, 1 }, { "WeaponAim", { 0.0342, -0.09397 }, 1 }, { "WeaponAim", { 0.05, -0.0866 }, 1 }, { "WeaponAim", { 0.06428, -0.0766 }, 1 }, { "WeaponAim", { 0.0766, -0.06428 }, 1 }, { "WeaponAim", { 0.0866, -0.05 }, 1 }, { "WeaponAim", { 0.09397, -0.0342 }, 1 }, { "WeaponAim", { 0.09848, -0.01736 }, 1 }, { "WeaponAim", { 0.1, 0 }, 1 }, { "WeaponAim", { 0.09848, 0.01736 }, 1 }, { "WeaponAim", { 0.09397, 0.0342 }, 1 }, { "WeaponAim", { 0.0866, 0.05 }, 1 }, { "WeaponAim", { 0.0766, 0.06428 }, 1 }, { "WeaponAim", { 0.06428, 0.0766 }, 1 }, { "WeaponAim", { 0.05, 0.0866 }, 1 }, { "WeaponAim", { 0.0342, 0.09397 }, 1 }, { "WeaponAim", { 0.01736, 0.09848 }, 1 }, { "WeaponAim", { 0, 0.1 }, 1 }, { "WeaponAim", { -0.01736, 0.09848 }, 1 }, { "WeaponAim", { -0.0342, 0.09397 }, 1 }, { "WeaponAim", { -0.05, 0.0866 }, 1 }, { "WeaponAim", { -0.06428, 0.0766 }, 1 }, { "WeaponAim", { -0.0766, 0.06428 }, 1 }, { "WeaponAim", { -0.0866, 0.05 }, 1 }, { "WeaponAim", { -0.09397, 0.0342 }, 1 }, { "WeaponAim", { -0.09848, 0.01736 }, 1 }, { "WeaponAim", { -0.1, 0 }, 1 }, { "WeaponAim", { -0.09848, -0.01736 }, 1 }, { "WeaponAim", { -0.09397, -0.0342 }, 1 }, { "WeaponAim", { -0.0866, -0.05 }, 1 }, { "WeaponAim", { -0.0766, -0.06428 }, 1 }, { "WeaponAim", { -0.06428, -0.0766 }, 1 }, { "WeaponAim", { -0.05, -0.0866 }, 1 }, { "WeaponAim", { -0.0342, -0.09397 }, 1 }, { "WeaponAim", { -0.01736, -0.09848 }, 1 }, { "WeaponAim", { 0, -0.1 }, 1 }, {}, { "Velocity", 0.001, "WeaponAim", { 0, 0 }, 1 }, { "Velocity", { 0, 0 }, 1 } };
                };
            };
            class ILS {
                condition = "ils";
                class Glideslope {
                    clipTL[] = { 0, 0 };
                    clipBR[] = { 1, 1 };
                    class ILS {
                        type = "line";
                        points[] = { { "ILS_W", { -0.24, 0 }, 1 }, { "ILS_W", { 0.24, 0 }, 1 }, {}, { "ILS_W", { 0, 0.027 }, 1 }, { "ILS_W", { 0, -0.027 }, 1 }, {}, { "ILS_W", { 0.12, 0.027 }, 1 }, { "ILS_W", { 0.12, -0.027 }, 1 }, {}, { "ILS_W", { 0.24, 0.027 }, 1 }, { "ILS_W", { 0.24, -0.027 }, 1 }, {}, { "ILS_W", { -0.12, 0.027 }, 1 }, { "ILS_W", { -0.12, -0.027 }, 1 }, {}, { "ILS_W", { -0.24, 0.027 }, 1 }, { "ILS_W", { -0.24, -0.027 }, 1 }, {}, { "ILS_H", { 0, -0.27 }, 1 }, { "ILS_H", { 0, 0.27 }, 1 }, {}, { "ILS_H", { 0.024, 0 }, 1 }, { "ILS_H", { -0.024, 0 }, 1 }, {}, { "ILS_H", { 0.024, 0.135 }, 1 }, { "ILS_H", { -0.024, 0.135 }, 1 }, {}, { "ILS_H", { 0.024, 0.27 }, 1 }, { "ILS_H", { -0.024, 0.27 }, 1 }, {}, { "ILS_H", { 0.024, -0.135 }, 1 }, { "ILS_H", { -0.024, -0.135 }, 1 }, {}, { "ILS_H", { 0.024, -0.27 }, 1 }, { "ILS_H", { -0.024, -0.27 }, 1 } };
                    };
                };
            };
        };
    };
    class AirPlaneHUD2 : AirplaneHUD {
        topLeft = "HUD2 LH";
        topRight = "HUD2 PH";
        bottomLeft = "HUD2 LD";
    };
};
