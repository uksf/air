class Pylon5 {
    condition = "pylonMagazineEmpty5<1";
    class GreenWPN {
        color[] = { 0, 1, 0, 1 };
        condition = "pylonSelected5<1";
        class Pylon_Sidewinder {
            condition = "(user5>0)*(user5<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station5", { -0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "0.12" }, 1 },
                        { "Station5", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.008, "-0.0056" }, 1 },
                        { "Station5D", { 0.008, "-0.0056" }, 1 },
                        { "Station5D", { 0.008, "0.0056" }, 1 },
                        { "Station5D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.012, -0.0084 }, 1 },
                    { "Station5D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station5D", { 0.012, -0.0084 }, 1 },
                    { "Station5D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user5>1)*(user5<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station5", { -0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "0.12" }, 1 },
                        { "Station5", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.011, "-0.0077" }, 1 },
                        { "Station5D", { 0.011, "-0.0077" }, 1 },
                        { "Station5D", { 0.011, "0.0077" }, 1 },
                        { "Station5D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.016, -0.0112 }, 1 },
                    { "Station5D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station5D", { 0.016, -0.0112 }, 1 },
                    { "Station5D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
        class Pylon_JDAM {
            condition = "(user5>2)*(user5<4)";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station5", { -0.06, "-0.103" }, 1 },
                        { "Station5", { 0.06, "-0.103" }, 1 },
                        { "Station5", { 0.06, "0.103" }, 1 },
                        { "Station5", { -0.06, "0.103" }, 1 }
                    }
                };
            };
            class JdamDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "0.0112" }, 1 },
                        { "Station5D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.018, -0.0126 }, 1 },
                    { "Station5D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station5D", { 0.018, -0.0126 }, 1 },
                    { "Station5D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_GBU {
            condition = "(user5>3)*(user5<5)";
            class GBU {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\gbu.paa";
                points[] = {
                    {
                        { "Station5", { -0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "0.12" }, 1 },
                        { "Station5", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class GBUDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "0.0112" }, 1 },
                        { "Station5D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.018, -0.0126 }, 1 },
                    { "Station5D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station5D", { 0.018, -0.0126 }, 1 },
                    { "Station5D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
    };
    class Pylon_SDB {
        condition = "(user5>7)*(user5<9)";
        color[] = { 0, 1, 0, 1 };
        class ammo4 {
            condition = "pylonAmmo5>3";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station5", { -0.02, "0" }, 1 },
                        { "Station5", { 0.055, "0" }, 1 },
                        { "Station5", { 0.055, "0.12" }, 1 },
                        { "Station5", { -0.02, "0.12" }, 1 }
                    }
                };
            };
        };
        class ammo3 {
            condition = "pylonAmmo5>2";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station5", { 0.055, "-0.12" }, 1 },
                        { "Station5", { -0.02, "-0.12" }, 1 },
                        { "Station5", { -0.02, "0.0" }, 1 },
                        { "Station5", { 0.055, "0.0" }, 1 }
                    }
                };
            };
            class SDBDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { "-0.011+0.018", "-0.0077" }, 1 },
                        { "Station5D", { "0.011+0.018", "-0.0077" }, 1 },
                        { "Station5D", { "0.011+0.018", "0.0077" }, 1 },
                        { "Station5D", { "-0.011+0.018", "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { "-0.015+0.018", -0.005 }, 1 },
                    { "Station5D", { "0.015+0.018", 0.005 }, 1 },
                    {},
                    { "Station5D", { "-0.015+0.018", 0.005 }, 1 },
                    { "Station5D", { "0.015+0.018", -0.005 }, 1 },
                    {}
                };
            };
        };
        class ammo2 {
            condition = "pylonAmmo5>1";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station5", { -0.055, "0.0" }, 1 },
                        { "Station5", { 0.02, "0.0" }, 1 },
                        { "Station5", { 0.02, "0.12" }, 1 },
                        { "Station5", { -0.055, "0.12" }, 1 }
                    }
                };
            };
        };
        class ammo1 {
            condition = "pylonAmmo5>0";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station5", { -0.055, "-0.12" }, 1 },
                        { "Station5", { 0.02, "-0.12" }, 1 },
                        { "Station5", { 0.02, "0.0" }, 1 },
                        { "Station5", { -0.055, "0.0" }, 1 }
                    }
                };
            };
            class SDBDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { "-0.011-0.018", "-0.0077" }, 1 },
                        { "Station5D", { "0.011-0.018", "-0.0077" }, 1 },
                        { "Station5D", { "0.011-0.018", "0.0077" }, 1 },
                        { "Station5D", { "-0.011-0.018", "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { "-0.015-0.018", -0.005 }, 1 },
                    { "Station5D", { "0.015-0.018", 0.005 }, 1 },
                    {},
                    { "Station5D", { "-0.015-0.018", 0.005 }, 1 },
                    { "Station5D", { "0.015-0.018", -0.005 }, 1 },
                    {}
                };
            };
        };
    };
    class WhiteWPN {
        color[] = { 1, 1, 1, 1 };
        condition = "pylonSelected5";
        class Pylon_Sidewinder {
            condition = "(user5>0)*(user5<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station5", { -0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "0.12" }, 1 },
                        { "Station5", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.008, "-0.0056" }, 1 },
                        { "Station5D", { 0.008, "-0.0056" }, 1 },
                        { "Station5D", { 0.008, "0.0056" }, 1 },
                        { "Station5D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.012, -0.0084 }, 1 },
                    { "Station5D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station5D", { 0.012, -0.0084 }, 1 },
                    { "Station5D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user5>1)*(user5<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station5", { -0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "0.12" }, 1 },
                        { "Station5", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.011, "-0.0077" }, 1 },
                        { "Station5D", { 0.011, "-0.0077" }, 1 },
                        { "Station5D", { 0.011, "0.0077" }, 1 },
                        { "Station5D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.016, -0.0112 }, 1 },
                    { "Station5D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station5D", { 0.016, -0.0112 }, 1 },
                    { "Station5D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
        class Pylon_JDAM {
            condition = "(user5>2)*(user5<4)";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station5", { -0.06, "-0.103" }, 1 },
                        { "Station5", { 0.06, "-0.103" }, 1 },
                        { "Station5", { 0.06, "0.103" }, 1 },
                        { "Station5", { -0.06, "0.103" }, 1 }
                    }
                };
            };
            class JdamDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "0.0112" }, 1 },
                        { "Station5D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.018, -0.0126 }, 1 },
                    { "Station5D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station5D", { 0.018, -0.0126 }, 1 },
                    { "Station5D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_GBU {
            condition = "(user5>3)*(user5<5)";
            class GBU {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\gbu.paa";
                points[] = {
                    {
                        { "Station5", { -0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "-0.12" }, 1 },
                        { "Station5", { 0.07, "0.12" }, 1 },
                        { "Station5", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class GBUDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station5D", { -0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "-0.0112" }, 1 },
                        { "Station5D", { 0.016, "0.0112" }, 1 },
                        { "Station5D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station5D", { -0.018, -0.0126 }, 1 },
                    { "Station5D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station5D", { 0.018, -0.0126 }, 1 },
                    { "Station5D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_SDB {
            condition = "(user5>7)*(user5<9)";
            class ammo4 {
                condition = "(pylonAmmo5>3)*(pylonAmmo5<5)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station5", { -0.02, "0" }, 1 },
                            { "Station5", { 0.055, "0" }, 1 },
                            { "Station5", { 0.055, "0.12" }, 1 },
                            { "Station5", { -0.02, "0.12" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station5D", { "-0.011+0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011+0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011+0.018", "0.0077" }, 1 },
                            { "Station5D", { "-0.011+0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station5D", { "-0.015+0.018", -0.005 }, 1 },
                        { "Station5D", { "0.015+0.018", 0.005 }, 1 },
                        {},
                        { "Station5D", { "-0.015+0.018", 0.005 }, 1 },
                        { "Station5D", { "0.015+0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo3 {
                condition = "(pylonAmmo5>2)*(pylonAmmo5<4)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station5", { 0.055, "-0.12" }, 1 },
                            { "Station5", { -0.02, "-0.12" }, 1 },
                            { "Station5", { -0.02, "0.0" }, 1 },
                            { "Station5", { 0.055, "0.0" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station5D", { "-0.011+0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011+0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011+0.018", "0.0077" }, 1 },
                            { "Station5D", { "-0.011+0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station5D", { "-0.015+0.018", -0.005 }, 1 },
                        { "Station5D", { "0.015+0.018", 0.005 }, 1 },
                        {},
                        { "Station5D", { "-0.015+0.018", 0.005 }, 1 },
                        { "Station5D", { "0.015+0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo2 {
                condition = "(pylonAmmo5>1)*(pylonAmmo5<3)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station5", { -0.055, "0.0" }, 1 },
                            { "Station5", { 0.02, "0.0" }, 1 },
                            { "Station5", { 0.02, "0.12" }, 1 },
                            { "Station5", { -0.055, "0.12" }, 1 }
                        }

                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station5D", { "-0.011-0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011-0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011-0.018", "0.0077" }, 1 },
                            { "Station5D", { "-0.011-0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station5D", { "-0.015-0.018", -0.005 }, 1 },
                        { "Station5D", { "0.015-0.018", 0.005 }, 1 },
                        {},
                        { "Station5D", { "-0.015-0.018", 0.005 }, 1 },
                        { "Station5D", { "0.015-0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo1 {
                condition = "(pylonAmmo5>0)*(pylonAmmo5<2)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station5", { -0.055, "-0.12" }, 1 },
                            { "Station5", { 0.02, "-0.12" }, 1 },
                            { "Station5", { 0.02, "0.0" }, 1 },
                            { "Station5", { -0.055, "0.0" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station5D", { "-0.011-0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011-0.018", "-0.0077" }, 1 },
                            { "Station5D", { "0.011-0.018", "0.0077" }, 1 },
                            { "Station5D", { "-0.011-0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station5D", { "-0.015-0.018", -0.005 }, 1 },
                        { "Station5D", { "0.015-0.018", 0.005 }, 1 },
                        {},
                        { "Station5D", { "-0.015-0.018", 0.005 }, 1 },
                        { "Station5D", { "0.015-0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
        };
    };
};
