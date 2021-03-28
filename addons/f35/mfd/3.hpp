class MFD3 {
    enableParallax = 0;
    topLeft = "MFD3_LH";
    topRight = "MFD3_RH";
    bottomLeft = "MFD3_LD";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    color[] = { 0.063, 0.792, 0.808, 1 };
    class material {
        ambient[] = { 1, 1, 1, 1 };
        diffuse[] = { 1, 1, 1, 1 };
        emissive[] = { 100, 100, 100, 1 };
    };
    class Bones {
        class SAFEARM {
            type = "fixed";
            pos[] = { 0.51, 0.0215 };
        };
        class FLARES {
            type = "fixed";
            pos[] = { 0.625, 0.534 };
        };
        class CHAFF {
            type = "fixed";
            pos[] = { 0.625, 0.495 };
        };
        class WPN {
            type = "fixed";
            pos[] = { 0.5, 0.45 };
        };
        class Station1 {
            type = "fixed";
            pos[] = { 0.93, 0.3 };
        };
        class Station2 {
            type = "fixed";
            pos[] = { 0.83, 0.29 };
        };
        class Station3 {
            type = "fixed";
            pos[] = { 0.73, 0.26 };
        };
        class Station4 {
            type = "fixed";
            pos[] = { 0.64, 0.23 };
        };
        class Station5 {
            type = "fixed";
            pos[] = { 0.57, 0.23 };
        };
        class Station6 {
            type = "fixed";
            pos[] = { 0.42, 0.23 };
        };
        class Station7 {
            type = "fixed";
            pos[] = { 0.35, 0.23 };
        };
        class Station8 {
            type = "fixed";
            pos[] = { 0.26, 0.26 };
        };
        class Station9 {
            type = "fixed";
            pos[] = { 0.16, 0.29 };
        };
        class Station10 {
            type = "fixed";
            pos[] = { 0.06, 0.3 };
        };
        class Station1D {
            type = "fixed";
            pos[] = { 0.91, 0.748 };
        };
        class Station2D {
            type = "fixed";
            pos[] = { 0.85, 0.75 };
        };
        class Station3D {
            type = "fixed";
            pos[] = { 0.75, 0.75 };
        };
        class Station4D {
            type = "fixed";
            pos[] = { 0.62, 0.785 };
        };
        class Station5D {
            type = "fixed";
            pos[] = { 0.543, 0.805 };
        };
        class Station6D {
            type = "fixed";
            pos[] = { 0.44, 0.805 };
        };
        class Station7D {
            type = "fixed";
            pos[] = { 0.36, 0.785 };
        };
        class Station8D {
            type = "fixed";
            pos[] = { 0.23, 0.75 };
        };
        class Station9D {
            type = "fixed";
            pos[] = { 0.13, 0.75 };
        };
        class Station10D {
            type = "fixed";
            pos[] = { 0.06, 0.748 };
        };
    };
    class Draw {
        condition = "on*(rpm>0.4)*(user33<1)";
#include "pylons\pylon1.hpp"
#include "pylons\pylon2.hpp"
#include "pylons\pylon3.hpp"
#include "pylons\pylon4.hpp"
#include "pylons\pylon5.hpp"
#include "pylons\pylon6.hpp"
#include "pylons\pylon7.hpp"
#include "pylons\pylon8.hpp"
#include "pylons\pylon9.hpp"
#include "pylons\pylon10.hpp"
        class White {
            color[] = { 1, 1, 1, 1 };
            class NOWPNName {
                condition = "mgun+missile+bomb+rocket";
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

            class SafeMODE {
                condition = "(mgun+atmissile+aamissile+atmissile+rocket+bomb)<1";
                class SAFE {
                    type = "text";
                    source = "static";
                    text = "SAFE";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { "SAFEARM", { "-0.020", "-0.019" }, 1 };
                    right[] = { "SAFEARM", { "0.035", "-0.019" }, 1 };
                    down[] = { "SAFEARM", { "-0.020", "0.019" }, 1 };
                };
            };
            class ARMMODE {
                condition = "(mgun+atmissile+aamissile+atmissile+rocket+bomb)";
                class ARM {
                    type = "text";
                    source = "static";
                    text = "ARM";
                    scale = 1;
                    sourceScale = 1;
                    align = "center";
                    pos[] = { "SAFEARM", { "-0.020", "-0.019" }, 1 };
                    right[] = { "SAFEARM", { "0.035", "-0.019" }, 1 };
                    down[] = { "SAFEARM", { "-0.020", "0.019" }, 1 };
                };
            };
            class CHAFFText {
                type = "text";
                source = "static";
                text = "CHAFF";
                scale = 1;
                sourceScale = 1;
                align = "right";
                pos[] = { "CHAFF", { "-0.020-0.23", "-0.02" }, 1 };
                right[] = { "CHAFF", { "0.035-0.23", "-0.02" }, 1 };
                down[] = { "CHAFF", { "-0.020-0.23", "0.02" }, 1 };
            };
            class FLARESText {
                type = "text";
                source = "static";
                text = "FLARE";
                scale = 1;
                sourceScale = 1;
                align = "right";
                pos[] = { "FLARES", { "-0.020-0.23", "-0.02" }, 1 };
                right[] = { "FLARES", { "0.035-0.23", "-0.02" }, 1 };
                down[] = { "FLARES", { "-0.020-0.23", "0.02" }, 1 };
            };
            // class GUNText {
            //     type = "text";
            //     source = "static";
            //     text = "GUN";
            //     scale = 1;
            //     sourceScale = 1;
            //     align = "right";
            //     pos[] = { "GUN", { "-0.020-0.23", "-0.02" }, 1 };
            //     right[] = { "GUN", { "0.035-0.23", "-0.02" }, 1 };
            //     down[] = { "GUN", { "-0.020-0.23", "0.02" }, 1 };
            // };
            class CHAFF {
                type = "text";
                source = "cmAmmo";
                sourceScale = 1;
                scale = 1;
                align = "left";
                pos[] = { "CHAFF", { "-0.020", "-0.02" }, 1 };
                right[] = { "CHAFF", { "0.035", "-0.02" }, 1 };
                down[] = { "CHAFF", { "-0.020", "0.02" }, 1 };
            };
            class FLARES {
                type = "text";
                source = "cmAmmo";
                sourceScale = 1;
                scale = 1;
                align = "left";
                pos[] = { "FLARES", { "-0.020", "-0.02" }, 1 };
                right[] = { "FLARES", { "0.035", "-0.02" }, 1 };
                down[] = { "FLARES", { "-0.020", "0.02" }, 1 };
            };
            // class GUN {
            //     type = "text";
            //     source = "ammo";
            //     sourceIndex = 4;
            //     scale = 1;
            //     sourceScale = 1;
            //     align = "left";
            //     pos[] = { "GUN", { "-0.020", "-0.02" }, 1 };
            //     right[] = { "GUN", { "0.035", "-0.02" }, 1 };
            //     down[] = { "GUN", { "-0.020", "0.02" }, 1 };
            // };
        };

        class DOORS {
            type = "text";
            source = "static";
            text = "DOORS";
            scale = 1;
            sourceScale = 1;
            align = "right";
            pos[] = { { "0.015", "0.44" }, 1 };
            right[] = { { "0.070", "0.44" }, 1 };
            down[] = { { "0.015", "0.48" }, 1 };
        };
        class BayOpen {
            condition = "pylonSelected4*(pylonMagazineEmpty4<1)+pylonSelected5*(pylonMagazineEmpty5<1)+pylonSelected6*(pylonMagazineEmpty6<1)+pylonSelected7*(pylonMagazineEmpty7<1)";
            class Color1 {
                color[] = { 1, 1, 1, 1 };
                class Open {
                    type = "text";
                    source = "static";
                    text = "OPEN";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.015", "0.49" }, 1 };
                    right[] = { { "0.070", "0.49" }, 1 };
                    down[] = { { "0.015", "0.53" }, 1 };
                };
                class Box {
                    type = "line";
                    width = 5;
                    points[] = {
                        { { 0.012, 0.493 }, 1 },
                        { { 0.012, 0.533 }, 1 },
                        { { 0.17, 0.533 }, 1 },
                        { { 0.17, 0.493 }, 1 },
                        { { 0.012, 0.493 }, 1 }
                    };
                };
            };
            class Color2 {
                color[] = { 0.063, 0.792, 0.808, 1 };
                class Closed {
                    type = "text";
                    source = "static";
                    text = "CLOSED";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.015", "0.53" }, 1 };
                    right[] = { { "0.070", "0.53" }, 1 };
                    down[] = { { "0.015", "0.57" }, 1 };
                };
            };
        };
        class BayClosed {
            condition = "(pylonSelected4+pylonSelected5+pylonSelected6+pylonSelected7)<1";
            class Color1 {
                color[] = { 1, 1, 1, 1 };
                class Closed {
                    type = "text";
                    source = "static";
                    text = "CLOSED";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.015", "0.53" }, 1 };
                    right[] = { { "0.070", "0.53" }, 1 };
                    down[] = { { "0.015", "0.57" }, 1 };
                };
                class Box {
                    type = "line";
                    width = 5;
                    points[] = {
                        { { 0.012, 0.533 }, 1 },
                        { { 0.012, 0.573 }, 1 },
                        { { 0.17, 0.573 }, 1 },
                        { { 0.17, 0.533 }, 1 },
                        { { 0.012, 0.533 }, 1 }
                    };
                };
            };
            class Color2 {
                color[] = { 0.063, 0.792, 0.808, 1 };
                class Open {
                    type = "text";
                    source = "static";
                    text = "OPEN";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.015", "0.49" }, 1 };
                    right[] = { { "0.070", "0.49" }, 1 };
                    down[] = { { "0.015", "0.53" }, 1 };
                };
            };
        };
        class BayClosed2 {
            condition = "pylonSelected4*(pylonMagazineEmpty4)+pylonSelected5*(pylonMagazineEmpty5)+pylonSelected6*(pylonMagazineEmpty6)+pylonSelected7*(pylonMagazineEmpty7)";
            class Color1 {
                color[] = { 1, 1, 1, 1 };
                class Closed {
                    type = "text";
                    source = "static";
                    text = "CLOSED";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.015", "0.53" }, 1 };
                    right[] = { { "0.070", "0.53" }, 1 };
                    down[] = { { "0.015", "0.57" }, 1 };
                };
                class Box {
                    type = "line";
                    width = 5;
                    points[] = {
                        { { 0.012, 0.533 }, 1 },
                        { { 0.012, 0.573 }, 1 },
                        { { 0.17, 0.573 }, 1 },
                        { { 0.17, 0.533 }, 1 },
                        { { 0.012, 0.533 }, 1 }
                    };
                };
            };
            class Color2 {
                color[] = { 0.063, 0.792, 0.808, 1 };
                class Open {
                    type = "text";
                    source = "static";
                    text = "OPEN";
                    scale = 1;
                    sourceScale = 1;
                    align = "right";
                    pos[] = { { "0.015", "0.49" }, 1 };
                    right[] = { { "0.070", "0.49" }, 1 };
                    down[] = { { "0.015", "0.53" }, 1 };
                };
            };
        };
    };
};
