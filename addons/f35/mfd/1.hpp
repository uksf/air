class MFD1 {
    enableParallax = 0;
    class Pos10Vector {
        type = "vector";
        pos0[] = { 0.5, 0.5 };
        pos10[] = { 0.71132398, 0.79310501 };
    };
    topLeft = "MFD1_LH";
    topRight = "MFD1_RH";
    bottomLeft = "MFD1_LD";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    color[] = { 0, 0.843, 0, 1 };
    class material {
        ambient[] = { 1, 1, 1, 1 };
        diffuse[] = { 1, 1, 1, 1 };
        emissive[] = { 100, 100, 100, 1 };
    };
    class Bones {
    };
    class Draw {
        condition = "on*(rpm>0.4)*(user31<1)";
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
