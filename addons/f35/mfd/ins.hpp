class INSDisplay {
    topLeft = "INS LH";
    topRight = "INS PH";
    bottomLeft = "INS LD";
    borderLeft = 0.188;
    borderRight = 0.078;
    borderTop = -0.358;
    borderBottom = 0.225;
    color[] = { 0.34, 0.56, 0.85, 1 };
    enableParallax = 0;
    class material {
        ambient[] = { 1, 1, 1, 1 };
        diffuse[] = { 1, 1, 1, 1 };
        emissive[] = { 100, 100, 100, 1 };
    };
    class Bones {
        class Center {
            type = "fixed";
            pos[] = { 0.37, 0.37 };
        };
        class Middle {
            type = "fixed";
            pos[] = { 0.5, 0.5 };
        };
        class Level0 {
            pos0[] = { 0.5, 0.60999999 };
            pos10[] = { 0.94, 1.08000001 };
            type = "horizon";
            angle = 0;
        };
        class LevelP10 : Level0 {
            angle = 10;
        };
        class LevelM10 : Level0 {
            angle = -10;
        };
        class LevelP20 : Level0 {
            angle = 20;
        };
        class LevelM20 : Level0 {
            angle = -20;
        };
        class LevelP30 : Level0 {
            angle = 30;
        };
        class LevelM30 : Level0 {
            angle = -30;
        };
        class LevelP40 : Level0 {
            angle = 40;
        };
        class LevelM40 : Level0 {
            angle = -40;
        };
        class LevelP50 : Level0 {
            angle = 50;
        };
        class LevelM50 : Level0 {
            angle = -50;
        };
        class LevelP60 : Level0 {
            angle = 60;
        };
        class LevelM60 : Level0 {
            angle = -60;
        };
        class LevelP70 : Level0 {
            angle = 70;
        };
        class LevelM70 : Level0 {
            angle = -70;
        };
        class LevelP80 : Level0 {
            angle = 80;
        };
        class LevelM80 : Level0 {
            angle = -80;
        };
        class LevelP90 : Level0 {
            angle = 90;
        };
        class LevelM90 : Level0 {
            angle = -90;
        };
        class HorizonBankRot {
            type = "rotational";
            source = "horizonBank";
            center[] = { 0.5, 0.5 };
            min = -1.0472;
            max = 1.0472;
            minAngle = -29.5;
            maxAngle = 29.5;
            aspectRatio = 1.21;
        };
    };
    class Draw {
        alpha = 1;
        condition = "on*rpm";

        class Background {
            color[] = { 0, 0, 0, 1 };
            alpha = 1;
            class PolygonR_1 {
                type = "polygon";
                points[] = {
                    { { { 0, 0 }, 1 },
                      { { 1, 0 }, 1 },
                      { { 1, 1 }, 1 },
                      { { 0, 1 }, 1 } }
                };
            };
        };
        class startup {
            condition = "(rpm*1000)>950";
            class Square {
                color[] = { 0.00197, 0.00197, 0.015 };
                alpha = 0.12;
                //color[]={0.00197,0.00197,0.01};
                //alpha=0.15
                class PolygonLeft {
                    type = "polygon";
                    points[] = { { { { 0, 0 }, 1 },
                                   { { 0.22, 0 }, 1 },
                                   { { 0.22, 1 }, 1 },
                                   { { 0, 1 }, 1 } } };
                };
                class PolygonRight {
                    type = "polygon";
                    points[] = { { { { 1, 0 }, 1 },
                                   { { 0.78, 0 }, 1 },
                                   { { 0.78, 1 }, 1 },
                                   { { 1, 1 }, 1 } } };
                };
            };

            class HorizonBack {
                clipTL[] = { 0.22, 0 };
                clipBR[] = { 0.78, 1 };
                class Dimmed {
                    type = "group";
                    color[] = { 0.00209, 0.01, 0.02 };
                    //alpha=0.993
                    alpha = 1;
                    class PolygonTop {
                        type = "polygon";
                        points[] = {
                            { { "Level0", { -1, 0 }, 1 },
                              { "Level0", { 1, 0 }, 1 },
                              { "Level0", { 1, -5 }, 1 },
                              { "Level0", { -1, -5 }, 1 } }
                        };
                    };
                };
                class Dimmed2 {
                    type = "group";
                    color[] = { 0.02, 0.01, 0.00197 };
                    alpha = 0.42;
                    class PolygonBottom {
                        type = "polygon";
                        points[] = {
                            { { "Level0", { -1, 0 }, 1 },
                              { "Level0", { 1, 0 }, 1 },
                              { "Level0", { 1, 5 }, 1 },
                              { "Level0", { -1, 5 }, 1 } }
                        };
                    };
                };
            };
            class MiddleTrianglePolygon {
                color[] = { 0, 0, 0 };
                class LeftSquare {
                    type = "polygon";
                    points[] = {
                        { { "Middle", { 0.2, 0.012 }, 1 },
                          { "Middle", { 0.25, 0.012 }, 1 },
                          { "Middle", { 0.25, -0.012 }, 1 },
                          { "Middle", { 0.2, -0.012 }, 1 } }
                    };
                };
                class Left {
                    type = "polygon";
                    points[] = {
                        { { "Middle", { 0, 0 }, 1 },
                          { "Middle", { -0.17, 0.07 }, 1 },
                          { "Middle", { -0.07, 0.07 }, 1 } }
                    };
                };
                class Right {
                    type = "polygon";
                    points[] = {
                        { { "Middle", { 0, 0 }, 1 },
                          { "Middle", { 0.17, 0.07 }, 1 },
                          { "Middle", { 0.07, 0.07 }, 1 } }
                    };
                };
                class RightSquare {
                    type = "polygon";
                    points[] = {
                        { { "Middle", { -0.2, 0.012 }, 1 },
                          { "Middle", { -0.25, 0.012 }, 1 },
                          { "Middle", { -0.25, -0.012 }, 1 },
                          { "Middle", { -0.2, -0.012 }, 1 } }
                    };
                };
            };
            class MiddleTriangle {
                type = "line";
                width = 10;
                points[] = {
                    { "Middle", { 0, 0 }, 1 },
                    { "Middle", { -0.17, 0.07 }, 1 },
                    { "Middle", { -0.07, 0.07 }, 1 },
                    { "Middle", { 0, 0 }, 1 },
                    { "Middle", { 0.17, 0.07 }, 1 },
                    { "Middle", { 0.07, 0.07 }, 1 },
                    { "Middle", { 0, 0 }, 1 },
                    {},

                    { "Middle", { 0.2, 0.012 }, 1 },
                    { "Middle", { 0.25, 0.012 }, 1 },
                    { "Middle", { 0.25, -0.012 }, 1 },
                    { "Middle", { 0.2, -0.012 }, 1 },
                    { "Middle", { 0.2, 0.012 }, 1 },
                    {},

                    { "Middle", { -0.2, 0.012 }, 1 },
                    { "Middle", { -0.25, 0.012 }, 1 },
                    { "Middle", { -0.25, -0.012 }, 1 },
                    { "Middle", { -0.2, -0.012 }, 1 },
                    { "Middle", { -0.2, 0.012 }, 1 }
                };
            };
            class HorizonWhite {
                clipTL[] = { 0.22, 0 };
                clipBR[] = { 0.78, 1 };
                class Dimmed {
                    class Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "Level0", { -0.27, 0 }, 1 },
                            { "Level0", { 0.27, 0 }, 1 }
                        };
                    };

                    class LevelM10 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM10", { -0.09, 0 }, 1 },
                            { "LevelM10", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM10", { -0.025, -0.1125 }, 1 },
                            { "LevelM10", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM10", { -0.05, -0.225 }, 1 },
                            { "LevelM10", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM10", { -0.025, -0.3375 }, 1 },
                            { "LevelM10", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM10 {
                        type = "text";
                        source = "static";
                        text = "10";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM10", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM10", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM10", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP10 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP10", { -0.09, 0 }, 1 },
                            { "LevelP10", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP10", { -0.025, 0.1125 }, 1 },
                            { "LevelP10", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP10", { -0.05, 0.225 }, 1 },
                            { "LevelP10", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP10", { -0.025, 0.3375 }, 1 },
                            { "LevelP10", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP10 {
                        type = "text";
                        source = "static";
                        text = "10";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP10", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP10", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP10", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM20 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM20", { -0.09, 0 }, 1 },
                            { "LevelM20", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM20", { -0.025, -0.1125 }, 1 },
                            { "LevelM20", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM20", { -0.05, -0.225 }, 1 },
                            { "LevelM20", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM20", { -0.025, -0.3375 }, 1 },
                            { "LevelM20", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM20 {
                        type = "text";
                        source = "static";
                        text = "20";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM20", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM20", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM20", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP20 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP20", { -0.09, 0 }, 1 },
                            { "LevelP20", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP20", { -0.025, 0.1125 }, 1 },
                            { "LevelP20", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP20", { -0.05, 0.225 }, 1 },
                            { "LevelP20", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP20", { -0.025, 0.3375 }, 1 },
                            { "LevelP20", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP20 {
                        type = "text";
                        source = "static";
                        text = "20";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP20", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP20", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP20", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM30 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM30", { -0.09, 0 }, 1 },
                            { "LevelM30", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM30", { -0.025, -0.1125 }, 1 },
                            { "LevelM30", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM30", { -0.05, -0.225 }, 1 },
                            { "LevelM30", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM30", { -0.025, -0.3375 }, 1 },
                            { "LevelM30", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM30 {
                        type = "text";
                        source = "static";
                        text = "30";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM30", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM30", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM30", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP30 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP30", { -0.09, 0 }, 1 },
                            { "LevelP30", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP30", { -0.025, 0.1125 }, 1 },
                            { "LevelP30", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP30", { -0.05, 0.225 }, 1 },
                            { "LevelP30", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP30", { -0.025, 0.3375 }, 1 },
                            { "LevelP30", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP30 {
                        type = "text";
                        source = "static";
                        text = "30";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP30", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP30", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP30", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM40 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM40", { -0.09, 0 }, 1 },
                            { "LevelM40", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM40", { -0.025, -0.1125 }, 1 },
                            { "LevelM40", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM40", { -0.05, -0.225 }, 1 },
                            { "LevelM40", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM40", { -0.025, -0.3375 }, 1 },
                            { "LevelM40", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM40 {
                        type = "text";
                        source = "static";
                        text = "40";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM40", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM40", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM40", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP40 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP40", { -0.09, 0 }, 1 },
                            { "LevelP40", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP40", { -0.025, 0.1125 }, 1 },
                            { "LevelP40", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP40", { -0.05, 0.225 }, 1 },
                            { "LevelP40", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP40", { -0.025, 0.3375 }, 1 },
                            { "LevelP40", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP40 {
                        type = "text";
                        source = "static";
                        text = "40";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP40", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP40", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP40", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM50 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM50", { -0.09, 0 }, 1 },
                            { "LevelM50", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM50", { -0.025, -0.1125 }, 1 },
                            { "LevelM50", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM50", { -0.05, -0.225 }, 1 },
                            { "LevelM50", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM50", { -0.025, -0.3375 }, 1 },
                            { "LevelM50", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM50 {
                        type = "text";
                        source = "static";
                        text = "50";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM50", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM50", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM50", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP50 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP50", { -0.09, 0 }, 1 },
                            { "LevelP50", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP50", { -0.025, 0.1125 }, 1 },
                            { "LevelP50", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP50", { -0.05, 0.225 }, 1 },
                            { "LevelP50", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP50", { -0.025, 0.3375 }, 1 },
                            { "LevelP50", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP50 {
                        type = "text";
                        source = "static";
                        text = "50";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP50", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP50", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP50", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM60 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM60", { -0.09, 0 }, 1 },
                            { "LevelM60", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM60", { -0.025, -0.1125 }, 1 },
                            { "LevelM60", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM60", { -0.05, -0.225 }, 1 },
                            { "LevelM60", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM60", { -0.025, -0.3375 }, 1 },
                            { "LevelM60", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM60 {
                        type = "text";
                        source = "static";
                        text = "60";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM60", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM60", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM60", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP60 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP60", { -0.09, 0 }, 1 },
                            { "LevelP60", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP60", { -0.025, 0.1125 }, 1 },
                            { "LevelP60", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP60", { -0.05, 0.225 }, 1 },
                            { "LevelP60", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP60", { -0.025, 0.3375 }, 1 },
                            { "LevelP60", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP60 {
                        type = "text";
                        source = "static";
                        text = "60";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP60", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP60", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP60", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM70 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM70", { -0.09, 0 }, 1 },
                            { "LevelM70", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM70", { -0.025, -0.1125 }, 1 },
                            { "LevelM70", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM70", { -0.05, -0.225 }, 1 },
                            { "LevelM70", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM70", { -0.025, -0.3375 }, 1 },
                            { "LevelM70", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM70 {
                        type = "text";
                        source = "static";
                        text = "70";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM70", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM70", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM70", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP70 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP70", { -0.09, 0 }, 1 },
                            { "LevelP70", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP70", { -0.025, 0.1125 }, 1 },
                            { "LevelP70", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP70", { -0.05, 0.225 }, 1 },
                            { "LevelP70", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP70", { -0.025, 0.3375 }, 1 },
                            { "LevelP70", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP70 {
                        type = "text";
                        source = "static";
                        text = "70";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP70", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP70", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP70", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM80 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM80", { -0.09, 0 }, 1 },
                            { "LevelM80", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM80", { -0.025, -0.1125 }, 1 },
                            { "LevelM80", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM80", { -0.05, -0.225 }, 1 },
                            { "LevelM80", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM80", { -0.025, -0.3375 }, 1 },
                            { "LevelM80", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM80 {
                        type = "text";
                        source = "static";
                        text = "80";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM80", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM80", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM80", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP80 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP80", { -0.09, 0 }, 1 },
                            { "LevelP80", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP80", { -0.025, 0.1125 }, 1 },
                            { "LevelP80", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP80", { -0.05, 0.225 }, 1 },
                            { "LevelP80", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP80", { -0.025, 0.3375 }, 1 },
                            { "LevelP80", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP80 {
                        type = "text";
                        source = "static";
                        text = "80";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP80", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP80", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP80", { 0.09, 0.075 }, 1 };
                    };

                    class LevelM90 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelM90", { -0.09, 0 }, 1 },
                            { "LevelM90", { 0.09, 0 }, 1 },
                            {},
                            { "LevelM90", { -0.025, -0.1125 }, 1 },
                            { "LevelM90", { 0.025, -0.1125 }, 1 },
                            {},
                            { "LevelM90", { -0.05, -0.225 }, 1 },
                            { "LevelM90", { 0.05, -0.225 }, 1 },
                            {},
                            { "LevelM90", { -0.025, -0.3375 }, 1 },
                            { "LevelM90", { 0.025, -0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextM90 {
                        type = "text";
                        source = "static";
                        text = "90";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelM90", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelM90", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelM90", { 0.09, 0.075 }, 1 };
                    };
                    class LevelP90 : Level0 {
                        type = "line";
                        width = 12;
                        points[] = {
                            { "LevelP90", { -0.09, 0 }, 1 },
                            { "LevelP90", { 0.09, 0 }, 1 },
                            {},
                            { "LevelP90", { -0.025, 0.1125 }, 1 },
                            { "LevelP90", { 0.025, 0.1125 }, 1 },
                            {},
                            { "LevelP90", { -0.05, 0.225 }, 1 },
                            { "LevelP90", { 0.05, 0.225 }, 1 },
                            {},
                            { "LevelP90", { -0.025, 0.3375 }, 1 },
                            { "LevelP90", { 0.025, 0.3375 }, 1 },
                            {}
                        };
                    };
                    class TextP90 {
                        type = "text";
                        source = "static";
                        text = "90";
                        align = "right";
                        scale = 1;
                        sourceScale = 1;
                        pos[] = { "LevelP90", { 0.09, -0.075 }, 1 };
                        right[] = { "LevelP90", { 0.24, -0.075 }, 1 };
                        down[] = { "LevelP90", { 0.09, 0.075 }, 1 };
                    };
                };
            };

            class Bank_Marks {
                type = "line";
                width = 8;
                points[] = {
                    { { 0.696000, 0.075648 }, 1 },  //60
                    { { 0.672000, 0.127609 }, 1 },
                    {},
                    { { 0.634072, 0.039551 }, 1 },  //70
                    { { 0.623127, 0.077138 }, 1 },
                    {},
                    { { 0.568070, 0.017444 }, 1 },  //80
                    { { 0.562513, 0.056837 }, 1 },
                    {},
                    { { 0.500000, 0.010000 }, 1 },  //90
                    { { 0.500000, 0.050000 }, 1 },
                    {},
                    { { 0.431930, 0.017444 }, 1 },  //100
                    { { 0.437487, 0.056837 }, 1 },
                    {},
                    { { 0.365928, 0.039551 }, 1 },  //110
                    { { 0.376873, 0.077138 }, 1 },
                    {},
                    { { 0.304000, 0.075648 }, 1 },  //120
                    { { 0.328000, 0.127609 }, 1 },
                    {}
                };
            };
            class Bank_Indicator {
                type = "line";
                width = 8;
                points[] = {
                    { "HorizonBankRot", { 0, 0.35 }, 1 },
                    { "HorizonBankRot", { -0.011, 0.31 }, 1 },
                    { "HorizonBankRot", { 0.011, 0.31 }, 1 },
                    { "HorizonBankRot", { 0, 0.35 }, 1 }
                };
            };
            class altitude_scale {
                type = "scale";
                scale = 1;
                source = "altitudeASL";
                sourceScale = 3.28084;
                align = "right";
                width = 10;
                lineXleft = 0.830;
                lineYright = 0.860;
                lineXleftMajor = 0.830;
                lineYrightMajor = 0.860;
                top = "1";
                center = "0.5";
                bottom = "0";
                step = 20;
                StepSize = "(1)/15";
                horizontal = 0;
                numberEach = 5;
                majorLineEach = 5;
                pos[] = { 0.860, 0.95 };
                right[] = { 0.960, 0.95 };
                down[] = { 0.860, 1.05 };
            };
            class speed_scale {
                type = "scale";
                scale = 2;
                source = "speed";
                sourceScale = 1.94384;
                sourcelength = 1;
                align = "left";
                width = 10;
                lineXleft = 0.128;
                lineYright = 0.158;
                lineXleftMajor = 0.128;
                lineYrightMajor = 0.158;
                top = "1";
                center = "0.5";
                bottom = "0";
                step = 10;
                StepSize = "(1)/8";
                horizontal = 0;
                numberEach = 2;
                majorLineEach = 2;
                pos[] = { 0.09, 0.95 };
                right[] = { 0.19, 0.95 };
                down[] = { 0.09, 1.05 };
            };
            class Speed_Scale_line {
                type = "line";
                width = 10;
                points[] = {
                    { { 0.158, 0 }, 1 },
                    { { 0.158, 1 }, 1 }
                };
            };
            class Speed_Scale_Arrow {
                type = "line";
                width = 8;
                points[] = {
                    { { 0.158, 0.5 }, 1 },
                    { { 0.19, 0.54 }, 1 },
                    { { 0.19, 0.46 }, 1 },
                    { { 0.158, 0.5 }, 1 },
                    {},
                    { { 0.19, 0.5 }, 1 },
                    { { 0.207, 0.5 }, 1 }
                };
            };
            class Alt_Scale_Arrow {
                type = "line";
                width = 8;
                points[] = {
                    { { 1, 0.45 }, 1 },
                    { { 0.830, 0.45 }, 1 },
                    { { 0.820, 0.42 }, 1 },
                    { { 0.790, 0.42 }, 1 },
                    {},

                    { { 1, 0.55 }, 1 },
                    { { 0.830, 0.55 }, 1 },
                    { { 0.820, 0.58 }, 1 },
                    { { 0.790, 0.58 }, 1 },
                    {}
                };
            };
        };
    };
};
