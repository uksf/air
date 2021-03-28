class Pylon9 {
    condition = "pylonMagazineEmpty9<1";
    class GreenWPN {
        color[] = { 0, 1, 0, 1 };
        condition = "pylonSelected9<1";
        class Pylon_Sidewinder {
            condition = "(user9>0)*(user9<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station9", { -0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "0.12" }, 1 },
                        { "Station9", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.008, "-0.0056" }, 1 },
                        { "Station9D", { 0.008, "-0.0056" }, 1 },
                        { "Station9D", { 0.008, "0.0056" }, 1 },
                        { "Station9D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.012, -0.0084 }, 1 },
                    { "Station9D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station9D", { 0.012, -0.0084 }, 1 },
                    { "Station9D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user9>1)*(user9<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station9", { -0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "0.12" }, 1 },
                        { "Station9", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.011, "-0.0077" }, 1 },
                        { "Station9D", { 0.011, "-0.0077" }, 1 },
                        { "Station9D", { 0.011, "0.0077" }, 1 },
                        { "Station9D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.016, -0.0112 }, 1 },
                    { "Station9D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station9D", { 0.016, -0.0112 }, 1 },
                    { "Station9D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
        class Pylon_JDAM {
            condition = "(user9>2)*(user9<4)";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station9", { -0.06, "-0.103" }, 1 },
                        { "Station9", { 0.06, "-0.103" }, 1 },
                        { "Station9", { 0.06, "0.103" }, 1 },
                        { "Station9", { -0.06, "0.103" }, 1 }
                    }
                };
            };
            class JdamDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "0.0112" }, 1 },
                        { "Station9D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.018, -0.0126 }, 1 },
                    { "Station9D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station9D", { 0.018, -0.0126 }, 1 },
                    { "Station9D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_GBU {
            condition = "(user9>3)*(user9<5)";
            class GBU {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\gbu.paa";
                points[] = {
                    {
                        { "Station9", { -0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "0.12" }, 1 },
                        { "Station9", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class GBUDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "0.0112" }, 1 },
                        { "Station9D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.018, -0.0126 }, 1 },
                    { "Station9D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station9D", { 0.018, -0.0126 }, 1 },
                    { "Station9D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
    };
    class Pylon_SDB {
        condition = "(user9>7)*(user9<9)";
        color[] = { 0, 1, 0, 1 };
        class ammo4 {
            condition = "pylonAmmo9>3";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station9", { -0.055, "0.0" }, 1 },
                        { "Station9", { 0.02, "0.0" }, 1 },
                        { "Station9", { 0.02, "0.12" }, 1 },
                        { "Station9", { -0.055, "0.12" }, 1 }
                    }
                };
            };
        };
        class ammo3 {
            condition = "pylonAmmo9>2";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station9", { -0.055, "-0.12" }, 1 },
                        { "Station9", { 0.02, "-0.12" }, 1 },
                        { "Station9", { 0.02, "0.0" }, 1 },
                        { "Station9", { -0.055, "0.0" }, 1 }
                    }
                };
            };
            class SDBDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { "-0.011-0.018", "-0.0077" }, 1 },
                        { "Station9D", { "0.011-0.018", "-0.0077" }, 1 },
                        { "Station9D", { "0.011-0.018", "0.0077" }, 1 },
                        { "Station9D", { "-0.011-0.018", "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { "-0.015-0.018", -0.005 }, 1 },
                    { "Station9D", { "0.015-0.018", 0.005 }, 1 },
                    {},
                    { "Station9D", { "-0.015-0.018", 0.005 }, 1 },
                    { "Station9D", { "0.015-0.018", -0.005 }, 1 },
                    {}
                };
            };
        };
        class ammo2 {
            condition = "pylonAmmo9>1";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station9", { -0.02, "0" }, 1 },
                        { "Station9", { 0.055, "0" }, 1 },
                        { "Station9", { 0.055, "0.12" }, 1 },
                        { "Station9", { -0.02, "0.12" }, 1 }
                    }

                };
            };
        };
        class ammo1 {
            condition = "pylonAmmo9>0";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station9", { 0.055, "-0.12" }, 1 },
                        { "Station9", { -0.02, "-0.12" }, 1 },
                        { "Station9", { -0.02, "0.0" }, 1 },
                        { "Station9", { 0.055, "0.0" }, 1 }
                    }
                };
            };
            class SDBDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { "-0.011+0.018", "-0.0077" }, 1 },
                        { "Station9D", { "0.011+0.018", "-0.0077" }, 1 },
                        { "Station9D", { "0.011+0.018", "0.0077" }, 1 },
                        { "Station9D", { "-0.011+0.018", "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { "-0.015+0.018", -0.005 }, 1 },
                    { "Station9D", { "0.015+0.018", 0.005 }, 1 },
                    {},
                    { "Station9D", { "-0.015+0.018", 0.005 }, 1 },
                    { "Station9D", { "0.015+0.018", -0.005 }, 1 },
                    {}
                };
            };
        };
    };
    class Pylon_2JDAM {
        color[] = { 0, 1, 0, 1 };
        condition = "(user9>9)*(user9<11)";
        class ammo2 {
            condition = "pylonAmmo9>1";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station9", { -0.085, "-0.103" }, 1 },
                        { "Station9", { 0.035, "-0.103" }, 1 },
                        { "Station9", { 0.035, "0.103" }, 1 },
                        { "Station9", { -0.085, "0.103" }, 1 }
                    }
                };
            };
            class JDAMDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.036, "-0.0112" }, 1 },
                        { "Station9D", { -0.004, "-0.0112" }, 1 },
                        { "Station9D", { -0.004, "0.0112" }, 1 },
                        { "Station9D", { -0.036, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.04, -0.0126 }, 1 },
                    { "Station9D", { 0.000, 0.0126 }, 1 },
                    {},
                    { "Station9D", { 0.000, -0.0126 }, 1 },
                    { "Station9D", { -0.04, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class ammo1 {
            condition = "pylonAmmo9>0";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station9", { 0.085, "-0.103" }, 1 },
                        { "Station9", { -0.035, "-0.103" }, 1 },
                        { "Station9", { -0.035, "0.103" }, 1 },
                        { "Station9", { 0.085, "0.103" }, 1 }
                    }
                };
            };
            class JdamDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { 0.036, "-0.0112" }, 1 },
                        { "Station9D", { 0.004, "-0.0112" }, 1 },
                        { "Station9D", { 0.004, "0.0112" }, 1 },
                        { "Station9D", { 0.036, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { 0.04, -0.0126 }, 1 },
                    { "Station9D", { 0.000, 0.0126 }, 1 },
                    {},
                    { "Station9D", { 0.000, -0.0126 }, 1 },
                    { "Station9D", { 0.04, 0.0126 }, 1 },
                    {}
                };
            };
        };
    };
    class WhiteWPN {
        color[] = { 1, 1, 1, 1 };
        condition = "pylonSelected9";
        class Pylon_Sidewinder {
            condition = "(user9>0)*(user9<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station9", { -0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "0.12" }, 1 },
                        { "Station9", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.008, "-0.0056" }, 1 },
                        { "Station9D", { 0.008, "-0.0056" }, 1 },
                        { "Station9D", { 0.008, "0.0056" }, 1 },
                        { "Station9D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.012, -0.0084 }, 1 },
                    { "Station9D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station9D", { 0.012, -0.0084 }, 1 },
                    { "Station9D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user9>1)*(user9<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station9", { -0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "0.12" }, 1 },
                        { "Station9", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.011, "-0.0077" }, 1 },
                        { "Station9D", { 0.011, "-0.0077" }, 1 },
                        { "Station9D", { 0.011, "0.0077" }, 1 },
                        { "Station9D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.016, -0.0112 }, 1 },
                    { "Station9D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station9D", { 0.016, -0.0112 }, 1 },
                    { "Station9D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
        class Pylon_JDAM {
            condition = "(user9>2)*(user9<4)";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station9", { -0.06, "-0.103" }, 1 },
                        { "Station9", { 0.06, "-0.103" }, 1 },
                        { "Station9", { 0.06, "0.103" }, 1 },
                        { "Station9", { -0.06, "0.103" }, 1 }
                    }
                };
            };
            class JdamDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "0.0112" }, 1 },
                        { "Station9D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.018, -0.0126 }, 1 },
                    { "Station9D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station9D", { 0.018, -0.0126 }, 1 },
                    { "Station9D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_GBU {
            condition = "(user9>3)*(user9<5)";
            class GBU {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\gbu.paa";
                points[] = {
                    {
                        { "Station9", { -0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "-0.12" }, 1 },
                        { "Station9", { 0.07, "0.12" }, 1 },
                        { "Station9", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class GBUDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station9D", { -0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "-0.0112" }, 1 },
                        { "Station9D", { 0.016, "0.0112" }, 1 },
                        { "Station9D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station9D", { -0.018, -0.0126 }, 1 },
                    { "Station9D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station9D", { 0.018, -0.0126 }, 1 },
                    { "Station9D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_SDB {
            condition = "(user9>7)*(user9<9)";
            class ammo4 {
                condition = "(pylonAmmo9>3)*(pylonAmmo9<5)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station9", { -0.055, "0.0" }, 1 },
                            { "Station9", { 0.02, "0.0" }, 1 },
                            { "Station9", { 0.02, "0.12" }, 1 },
                            { "Station9", { -0.055, "0.12" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station9D", { "-0.011-0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011-0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011-0.018", "0.0077" }, 1 },
                            { "Station9D", { "-0.011-0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station9D", { "-0.015-0.018", -0.005 }, 1 },
                        { "Station9D", { "0.015-0.018", 0.005 }, 1 },
                        {},
                        { "Station9D", { "-0.015-0.018", 0.005 }, 1 },
                        { "Station9D", { "0.015-0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo3 {
                condition = "(pylonAmmo9>2)*(pylonAmmo9<4)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station9", { -0.055, "-0.12" }, 1 },
                            { "Station9", { 0.02, "-0.12" }, 1 },
                            { "Station9", { 0.02, "0.0" }, 1 },
                            { "Station9", { -0.055, "0.0" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station9D", { "-0.011-0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011-0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011-0.018", "0.0077" }, 1 },
                            { "Station9D", { "-0.011-0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station9D", { "-0.015-0.018", -0.005 }, 1 },
                        { "Station9D", { "0.015-0.018", 0.005 }, 1 },
                        {},
                        { "Station9D", { "-0.015-0.018", 0.005 }, 1 },
                        { "Station9D", { "0.015-0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo2 {
                condition = "(pylonAmmo9>1)*(pylonAmmo9<3)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station9", { -0.02, "0" }, 1 },
                            { "Station9", { 0.055, "0" }, 1 },
                            { "Station9", { 0.055, "0.12" }, 1 },
                            { "Station9", { -0.02, "0.12" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station9D", { "-0.011+0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011+0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011+0.018", "0.0077" }, 1 },
                            { "Station9D", { "-0.011+0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station9D", { "-0.015+0.018", -0.005 }, 1 },
                        { "Station9D", { "0.015+0.018", 0.005 }, 1 },
                        {},
                        { "Station9D", { "-0.015+0.018", 0.005 }, 1 },
                        { "Station9D", { "0.015+0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo1 {
                condition = "(pylonAmmo9>0)*(pylonAmmo9<2)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station9", { 0.055, "-0.12" }, 1 },
                            { "Station9", { -0.02, "-0.12" }, 1 },
                            { "Station9", { -0.02, "0.0" }, 1 },
                            { "Station9", { 0.055, "0.0" }, 1 }
                        }

                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station9D", { "-0.011+0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011+0.018", "-0.0077" }, 1 },
                            { "Station9D", { "0.011+0.018", "0.0077" }, 1 },
                            { "Station9D", { "-0.011+0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station9D", { "-0.015+0.018", -0.005 }, 1 },
                        { "Station9D", { "0.015+0.018", 0.005 }, 1 },
                        {},
                        { "Station9D", { "-0.015+0.018", 0.005 }, 1 },
                        { "Station9D", { "0.015+0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
        };
        class Pylon_2JDAM {
            condition = "(user9>9)*(user9<11)";
            class ammo2 {
                condition = "(pylonAmmo9>1)*(pylonAmmo9<3)";
                class JDAM {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                    points[] = {
                        {
                            { "Station9", { -0.085, "-0.103" }, 1 },
                            { "Station9", { 0.035, "-0.103" }, 1 },
                            { "Station9", { 0.035, "0.103" }, 1 },
                            { "Station9", { -0.085, "0.103" }, 1 }
                        }
                    };
                };
                class JDAMDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station9D", { 0.036, "-0.0112" }, 1 },
                            { "Station9D", { 0.004, "-0.0112" }, 1 },
                            { "Station9D", { 0.004, "0.0112" }, 1 },
                            { "Station9D", { 0.036, "0.0112" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station9D", { 0.04, -0.0126 }, 1 },
                        { "Station9D", { 0.000, 0.0126 }, 1 },
                        {},
                        { "Station9D", { 0.000, -0.0126 }, 1 },
                        { "Station9D", { 0.04, 0.0126 }, 1 },
                        {}
                    };
                };
            };
            class ammo1 {
                condition = "(pylonAmmo9>0)*(pylonAmmo9<2)";
                class JDAM {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                    points[] = {
                        {
                            { "Station9", { 0.085, "-0.103" }, 1 },
                            { "Station9", { -0.035, "-0.103" }, 1 },
                            { "Station9", { -0.035, "0.103" }, 1 },
                            { "Station9", { 0.085, "0.103" }, 1 }
                        }
                    };
                };
                class JDAMDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station9D", { 0.036, "-0.0112" }, 1 },
                            { "Station9D", { 0.004, "-0.0112" }, 1 },
                            { "Station9D", { 0.004, "0.0112" }, 1 },
                            { "Station9D", { 0.036, "0.0112" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station9D", { 0.04, -0.0126 }, 1 },
                        { "Station9D", { 0.000, 0.0126 }, 1 },
                        {},
                        { "Station9D", { 0.000, -0.0126 }, 1 },
                        { "Station9D", { 0.04, 0.0126 }, 1 },
                        {}
                    };
                };
            };
        };
    };
};
