class MFD4 {
    enableParallax = 0;
    topLeft = "MFD4_LH";
    topRight = "MFD4_RH";
    bottomLeft = "MFD4_LD";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    color[] = { 0, 0.875, 0, 1 };
    class material {
        ambient[] = { 1, 1, 1, 1 };
        diffuse[] = { 1, 1, 1, 1 };
        emissive[] = { 100, 100, 100, 1 };
    };
    class Bones {
        class Speed {
            type = "fixed";
            pos[] = { 0.15, 0.825 };
        };
        class Alt {
            type = "fixed";
            pos[] = { 0.39, 0.825 };
        };
        class FuelInt {
            type = "fixed";
            pos[] = { 0.895, 0.128 };
        };
    };
    class Draw {
        condition = "on*(rpm>0.4)*(user34<1)";
        class SpeedValue {
            type = "text";
            source = "speed";
            scale = 1;
            sourceScale = 1.94384;
            align = "center";
            pos[] = { "Speed", { "-0.020", "-0.02" }, 1 };
            right[] = { "Speed", { "0.035", "-0.02" }, 1 };
            down[] = { "Speed", { "-0.020", "0.02" }, 1 };
        };
        class AltValue {
            type = "text";
            source = "altitudeAGL";
            scale = 1;
            sourceScale = 3.28084;
            align = "center";
            pos[] = { "Alt", { "-0.020", "-0.02" }, 1 };
            right[] = { "Alt", { "0.035", "-0.02" }, 1 };
            down[] = { "Alt", { "-0.020", "0.02" }, 1 };
        };
        class FuelIntValue {
            type = "text";
            source = "fuel";
            scale = 1;
            sourceScale = 7500;
            align = "left";
            pos[] = { "FuelInt", { "-0.020", "-0.02" }, 1 };
            right[] = { "FuelInt", { "0.035", "-0.02" }, 1 };
            down[] = { "FuelInt", { "-0.020", "0.02" }, 1 };
        };
        class AltWarn {
            type = "group";
            condition = "altitudeAGL<150*(speed>40)*(ils<1)*(AoA<-20)";
            color[] = { 1, 0, 0, 1 };
            clipTL[] = { 0, 0 };
            clipBR[] = { 1, 0.93 };
            blinkingPattern[] = { 0.200000, 0.200000 };
            blinkingStartsOn = 1;
            class Cross {
                type = "line";
                width = 15;
                points[] = {
                    { { 0, 0 }, 1 },
                    { { 1, 1 }, 1 },
                    {},
                    { { 0, 1 }, 1 },
                    { { 1, 0 }, 1 },
                    {}
                };
            };
        };
    };
};
