class MFD {
    class HUD {
        helmetMountedDisplay = 1;
        enableParallax = 0;
        helmetPosition[] = { -0.01945, 0.01099, 0.1 };
        helmetRight[] = { 0.0401, 0, 0 };
        helmetDown[] = { 0, -0.02748, 0 };
        color[] = { 0.15, 1, 0.15, 1 };
        class Pos10Vector {
            pos0[] = { 0.485, 0.4 };
            pos10[] = { 1.024, 1.186 };
        };
        class Bones {
            class PlaneW {
                type = "vector";
                source = "forward";
                pos0[] = { 0.485, 0.4 };
                pos10[] = { 1.024, 1.186 };
            };
            class WeaponAim : Pos10Vector {
                source = "weaponToView";
            };
            class Target : Pos10Vector {
                source = "targetToView";
            };
            class Velocity : Pos10Vector {
                source = "velocityToView";
                pos0[] = { 0.485, 0.4 };
                pos10[] = { 1.024, 1.186 };
            };
            class Level0 : Pos10Vector {
                type = "horizontoview";
                pos0[] = { 0.485, 0.4 };
                pos10[] = { 1.024, 1.186 };
            };
            class VelocityNotCenter : Pos10Vector {
                source = "velocityToView";
                pos0[] = { 0, 0 };
                pos10[] = { 0.539, 0.786 };
            };
            class ASL_Instrument {
                maxAngle = 236220;
            };
        };
        class Draw {
            color[] = { 0.15, 1, 0.15 };
            alpha = 1;
            condition = "on*(user40<0.5)";
            class SpeedScale {
                sourceScale = 1.94384;
            };
            class SpeedNumber {
                sourceScale = 1.94384;
            };
            class AltNumber {
                sourceScale = 3.28084;
            };
            class VspeedNumber {
                sourceScale = 196.85;
            };
        };
    };
    class MFD_LH {
        class Draw {
            color[] = { 0.15, 1, 0.15 };
        };
    };
    class MFD_RH {
        class Draw {
            color[] = { 0.15, 1, 0.15 };
        };
    };
};
