class MFD2 {
    enableParallax = 0;
    topLeft = "MFD2_LH";
    topRight = "MFD2_RH";
    bottomLeft = "MFD2_LD";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    color[] = { 0, 1, 0, 1 };
    class material {
        ambient[] = { 1, 1, 1, 1 };
        diffuse[] = { 1, 1, 1, 1 };
        emissive[] = { 100, 100, 100, 1 };
    };
    class Bones {
        class Thrust {
            type = "rotational";
            source = "vtolvectoring";
            center[] = { 0.45, 0.129 };
            min = 0;
            max = 1;
            minAngle = 0;
            maxAngle = 90;
            aspectRatio = 0.7;
        };
        class ThrustVal {
            type = "fixed";
            pos[] = { 0.47, 0.240 };
        };
        class Thrust2 {
            type = "rotational";
            source = "vtolvectoring";
            center[] = { 0.83, 0.129 };
            min = 0;
            max = 1;
            minAngle = 0;
            maxAngle = 90;
            aspectRatio = 0.7;
        };
        class Tailhook {
            type = "rotational";
            source = "throttle";
            center[] = { 0.80, 0.167 };
            min = 0;
            max = 1;
            minAngle = -12;
            maxAngle = 45;
            aspectRatio = 0.7;
        };
        class ThrustVal2 {
            type = "fixed";
            pos[] = { 0.85, 0.240 };
        };
        class WPN {
            type = "fixed";
            pos[] = { 0.27, 0.85 };
        };
    };
    class Draw {
        condition = "on*(rpm>0.4)*(user32<1)";
        class NOWPNName {
            condition = "mgun+missile+bomb+rocket";
            color[] = { 1, 1, 1, 1 };
            class WEAPONName {
                type = "text";
                source = "weapon";
                scale = 1;
                sourceScale = 1;
                align = "center";
                pos[] = { "WPN", { "-0.020", "-0.019" }, 1 };
                right[] = { "WPN", { "0.035", "-0.019" }, 1 };
                down[] = { "WPN", { "-0.020", "0.019" }, 1 };
            };
            class Box {
                type = "line";
                width = 5;
                points[] = {
                    { "WPN", { -0.25, -0.02 }, 1 },
                    { "WPN", { 0.23, -0.02 }, 1 },
                    { "WPN", { 0.23, 0.02 }, 1 },
                    { "WPN", { -0.25, 0.02 }, 1 },
                    { "WPN", { -0.25, -0.02 }, 1 }
                };
            };
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
        class WPNName {
            condition = "(mgun+missile+bomb+rocket)<1";
            color[] = { 0, 1, 0, 1 };
            class NoWEAPON {
                type = "text";
                source = "static";
                text = "NO WPN SELECTED";
                scale = 1;
                sourceScale = 1;
                align = "center";
                pos[] = { "WPN", { "-0.020", "-0.019" }, 1 };
                right[] = { "WPN", { "0.035", "-0.019" }, 1 };
                down[] = { "WPN", { "-0.020", "0.019" }, 1 };
            };
            class Box {
                type = "line";
                width = 5;
                points[] = {
                    { "WPN", { -0.25, -0.02 }, 1 },
                    { "WPN", { 0.23, -0.02 }, 1 },
                    { "WPN", { 0.23, 0.02 }, 1 },
                    { "WPN", { -0.25, 0.02 }, 1 },
                    { "WPN", { -0.25, -0.02 }, 1 }
                };
            };
        };
        //VTOL ARROWS
        class VTOL_Arrow {
            type = "line";
            width = 4;
            points[] = {
                { "Thrust", { 0, -0.005 }, 1 },
                { "Thrust", { 0.09, -0.005 }, 1 },
                { "Thrust", { 0.09, -0.012 }, 1 },
                { "Thrust", { 0.12, 0 }, 1 },
                { "Thrust", { 0.09, 0.012 }, 1 },
                { "Thrust", { 0.09, 0.005 }, 1 },
                { "Thrust", { 0, 0.005 }, 1 },
                { "Thrust", { 0, -0.005 }, 1 },
                {},
                { "Thrust2", { 0, -0.005 }, 1 },
                { "Thrust2", { 0.09, -0.005 }, 1 },
                { "Thrust2", { 0.09, -0.012 }, 1 },
                { "Thrust2", { 0.12, 0 }, 1 },
                { "Thrust2", { 0.09, 0.012 }, 1 },
                { "Thrust2", { 0.09, 0.005 }, 1 },
                { "Thrust2", { 0, 0.005 }, 1 },
                { "Thrust2", { 0, -0.005 }, 1 }
            };
        };
        class VTOL_Left_Text {
            type = "text";
            source = "throttle";
            scale = 1;
            sourceScale = 90;
            align = "center";
            pos[] = { "ThrustVal", { "-0.025", "-0.025" }, 1 };
            right[] = { "ThrustVal", { "0.04", "-0.025" }, 1 };
            down[] = { "ThrustVal", { "-0.025", "0.025" }, 1 };
        };
        class VTOL_RIGHT_Text {
            type = "text";
            source = "throttle";
            scale = 1;
            sourceScale = 90;
            align = "center";
            pos[] = { "ThrustVal2", { "-0.025", "-0.025" }, 1 };
            right[] = { "ThrustVal2", { "0.04", "-0.025" }, 1 };
            down[] = { "ThrustVal2", { "-0.025", "0.025" }, 1 };
        };
        class VTOL_THRUST_Text {
            type = "text";
            source = "throttle";
            scale = 1;
            sourceScale = 100;
            align = "center";
            pos[] = { { "0.6675", "0.104" }, 1 };
            right[] = { { "0.7325", "0.104" }, 1 };
            down[] = { { "0.6675", "0.154" }, 1 };
        };
    };
};
