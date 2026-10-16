class MFD {
    class HUD {
        enableParallax = 1;
        color[] = { 0.15, 1, 0.15, 1 };
        class Bones {
            class ASL_Instrument {
                maxAngle = 236220;
            };
        };
        class Draw {
            color[] = { 0.15, 1, 0.15 };
            alpha = 1;
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
    class MFD_LH;
    class MFD_RH;
};
