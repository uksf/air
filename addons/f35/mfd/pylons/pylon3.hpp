class Pylon3 {
    condition = "pylonMagazineEmpty3<1";
    class GreenWPN {
        color[] = { 0, 1, 0, 1 };
        condition = "pylonSelected3<1";
        class Pylon_Sidewinder {
            condition = "(user3>0)*(user3<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station3", { -0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "0.12" }, 1 },
                        { "Station3", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.008, "-0.0056" }, 1 },
                        { "Station3D", { 0.008, "-0.0056" }, 1 },
                        { "Station3D", { 0.008, "0.0056" }, 1 },
                        { "Station3D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.012, -0.0084 }, 1 },
                    { "Station3D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station3D", { 0.012, -0.0084 }, 1 },
                    { "Station3D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user3>1)*(user3<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station3", { -0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "0.12" }, 1 },
                        { "Station3", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.011, "-0.0077" }, 1 },
                        { "Station3D", { 0.011, "-0.0077" }, 1 },
                        { "Station3D", { 0.011, "0.0077" }, 1 },
                        { "Station3D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.016, -0.0112 }, 1 },
                    { "Station3D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station3D", { 0.016, -0.0112 }, 1 },
                    { "Station3D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
        class Pylon_JDAM {
            condition = "(user3>2)*(user3<4)";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station3", { -0.06, "-0.103" }, 1 },
                        { "Station3", { 0.06, "-0.103" }, 1 },
                        { "Station3", { 0.06, "0.103" }, 1 },
                        { "Station3", { -0.06, "0.103" }, 1 }
                    }
                };
            };
            class JdamDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "0.0112" }, 1 },
                        { "Station3D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.018, -0.0126 }, 1 },
                    { "Station3D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station3D", { 0.018, -0.0126 }, 1 },
                    { "Station3D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_GBU {
            condition = "(user3>3)*(user3<5)";
            class GBU {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\gbu.paa";
                points[] = {
                    {
                        { "Station3", { -0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "0.12" }, 1 },
                        { "Station3", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class GBUDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "0.0112" }, 1 },
                        { "Station3D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.018, -0.0126 }, 1 },
                    { "Station3D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station3D", { 0.018, -0.0126 }, 1 },
                    { "Station3D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
    };
    class Pylon_SDB {
        condition = "(user3>7)*(user3<9)";
        color[] = { 0, 1, 0, 1 };
        class ammo4 {
            condition = "pylonAmmo3>3";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station3", { -0.02, "0" }, 1 },
                        { "Station3", { 0.055, "0" }, 1 },
                        { "Station3", { 0.055, "0.12" }, 1 },
                        { "Station3", { -0.02, "0.12" }, 1 }
                    }
                };
            };
        };
        class ammo3 {
            condition = "pylonAmmo3>2";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station3", { 0.055, "-0.12" }, 1 },
                        { "Station3", { -0.02, "-0.12" }, 1 },
                        { "Station3", { -0.02, "0.0" }, 1 },
                        { "Station3", { 0.055, "0.0" }, 1 }
                    }
                };
            };
            class SDBDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { "-0.011+0.018", "-0.0077" }, 1 },
                        { "Station3D", { "0.011+0.018", "-0.0077" }, 1 },
                        { "Station3D", { "0.011+0.018", "0.0077" }, 1 },
                        { "Station3D", { "-0.011+0.018", "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { "-0.015+0.018", -0.005 }, 1 },
                    { "Station3D", { "0.015+0.018", 0.005 }, 1 },
                    {},
                    { "Station3D", { "-0.015+0.018", 0.005 }, 1 },
                    { "Station3D", { "0.015+0.018", -0.005 }, 1 },
                    {}
                };
            };
        };
        class ammo2 {
            condition = "pylonAmmo3>1";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station3", { -0.055, "0.0" }, 1 },
                        { "Station3", { 0.02, "0.0" }, 1 },
                        { "Station3", { 0.02, "0.12" }, 1 },
                        { "Station3", { -0.055, "0.12" }, 1 }
                    }
                };
            };
        };
        class ammo1 {
            condition = "pylonAmmo3>0";
            class SDB {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                points[] = {
                    {
                        { "Station3", { -0.055, "-0.12" }, 1 },
                        { "Station3", { 0.02, "-0.12" }, 1 },
                        { "Station3", { 0.02, "0.0" }, 1 },
                        { "Station3", { -0.055, "0.0" }, 1 }
                    }
                };
            };
            class SDBDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { "-0.011-0.018", "-0.0077" }, 1 },
                        { "Station3D", { "0.011-0.018", "-0.0077" }, 1 },
                        { "Station3D", { "0.011-0.018", "0.0077" }, 1 },
                        { "Station3D", { "-0.011-0.018", "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { "-0.015-0.018", -0.005 }, 1 },
                    { "Station3D", { "0.015-0.018", 0.005 }, 1 },
                    {},
                    { "Station3D", { "-0.015-0.018", 0.005 }, 1 },
                    { "Station3D", { "0.015-0.018", -0.005 }, 1 },
                    {}
                };
            };
        };
    };
    class Pylon_2JDAM {
        color[] = { 0, 1, 0, 1 };
        condition = "(user3>9)*(user3<11)";
        class ammo2 {
            condition = "pylonAmmo3>1";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station3", { -0.085, "-0.103" }, 1 },
                        { "Station3", { 0.035, "-0.103" }, 1 },
                        { "Station3", { 0.035, "0.103" }, 1 },
                        { "Station3", { -0.085, "0.103" }, 1 }
                    }
                };
            };
            class JDAMDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { 0.036, "-0.0112" }, 1 },
                        { "Station3D", { 0.004, "-0.0112" }, 1 },
                        { "Station3D", { 0.004, "0.0112" }, 1 },
                        { "Station3D", { 0.036, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { 0.04, -0.0126 }, 1 },
                    { "Station3D", { 0.000, 0.0126 }, 1 },
                    {},
                    { "Station3D", { 0.000, -0.0126 }, 1 },
                    { "Station3D", { 0.04, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class ammo1 {
            condition = "pylonAmmo3>0";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station3", { 0.085, "-0.103" }, 1 },
                        { "Station3", { -0.035, "-0.103" }, 1 },
                        { "Station3", { -0.035, "0.103" }, 1 },
                        { "Station3", { 0.085, "0.103" }, 1 }
                    }
                };
            };
            class JDAMDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.036, "-0.0112" }, 1 },
                        { "Station3D", { -0.004, "-0.0112" }, 1 },
                        { "Station3D", { -0.004, "0.0112" }, 1 },
                        { "Station3D", { -0.036, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.04, -0.0126 }, 1 },
                    { "Station3D", { 0.000, 0.0126 }, 1 },
                    {},
                    { "Station3D", { 0.000, -0.0126 }, 1 },
                    { "Station3D", { -0.04, 0.0126 }, 1 },
                    {}
                };
            };
        };
    };
    class WhiteWPN {
        color[] = { 1, 1, 1, 1 };
        condition = "pylonSelected3";
        class Pylon_Sidewinder {
            condition = "(user3>0)*(user3<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station3", { -0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "0.12" }, 1 },
                        { "Station3", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.008, "-0.0056" }, 1 },
                        { "Station3D", { 0.008, "-0.0056" }, 1 },
                        { "Station3D", { 0.008, "0.0056" }, 1 },
                        { "Station3D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.012, -0.0084 }, 1 },
                    { "Station3D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station3D", { 0.012, -0.0084 }, 1 },
                    { "Station3D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user3>1)*(user3<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station3", { -0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "0.12" }, 1 },
                        { "Station3", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.011, "-0.0077" }, 1 },
                        { "Station3D", { 0.011, "-0.0077" }, 1 },
                        { "Station3D", { 0.011, "0.0077" }, 1 },
                        { "Station3D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.016, -0.0112 }, 1 },
                    { "Station3D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station3D", { 0.016, -0.0112 }, 1 },
                    { "Station3D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
        class Pylon_JDAM {
            condition = "(user3>2)*(user3<4)";
            class JDAM {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                points[] = {
                    {
                        { "Station3", { -0.06, "-0.103" }, 1 },
                        { "Station3", { 0.06, "-0.103" }, 1 },
                        { "Station3", { 0.06, "0.103" }, 1 },
                        { "Station3", { -0.06, "0.103" }, 1 }
                    }
                };
            };
            class JdamDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "0.0112" }, 1 },
                        { "Station3D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.018, -0.0126 }, 1 },
                    { "Station3D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station3D", { 0.018, -0.0126 }, 1 },
                    { "Station3D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_GBU {
            condition = "(user3>3)*(user3<5)";
            class GBU {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\gbu.paa";
                points[] = {
                    {
                        { "Station3", { -0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "-0.12" }, 1 },
                        { "Station3", { 0.07, "0.12" }, 1 },
                        { "Station3", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class GBUDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station3D", { -0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "-0.0112" }, 1 },
                        { "Station3D", { 0.016, "0.0112" }, 1 },
                        { "Station3D", { -0.016, "0.0112" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station3D", { -0.018, -0.0126 }, 1 },
                    { "Station3D", { 0.018, 0.0126 }, 1 },
                    {},
                    { "Station3D", { 0.018, -0.0126 }, 1 },
                    { "Station3D", { -0.018, 0.0126 }, 1 },
                    {}
                };
            };
        };
        class Pylon_SDB {
            condition = "(user3>7)*(user3<9)";
            class ammo4 {
                condition = "(pylonAmmo3>3)*(pylonAmmo3<5)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station3", { -0.02, "0" }, 1 },
                            { "Station3", { 0.055, "0" }, 1 },
                            { "Station3", { 0.055, "0.12" }, 1 },
                            { "Station3", { -0.02, "0.12" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station3D", { "-0.011+0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011+0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011+0.018", "0.0077" }, 1 },
                            { "Station3D", { "-0.011+0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station3D", { "-0.015+0.018", -0.005 }, 1 },
                        { "Station3D", { "0.015+0.018", 0.005 }, 1 },
                        {},
                        { "Station3D", { "-0.015+0.018", 0.005 }, 1 },
                        { "Station3D", { "0.015+0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo3 {
                condition = "(pylonAmmo3>2)*(pylonAmmo3<4)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station3", { 0.055, "-0.12" }, 1 },
                            { "Station3", { -0.02, "-0.12" }, 1 },
                            { "Station3", { -0.02, "0.0" }, 1 },
                            { "Station3", { 0.055, "0.0" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station3D", { "-0.011+0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011+0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011+0.018", "0.0077" }, 1 },
                            { "Station3D", { "-0.011+0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station3D", { "-0.015+0.018", -0.005 }, 1 },
                        { "Station3D", { "0.015+0.018", 0.005 }, 1 },
                        {},
                        { "Station3D", { "-0.015+0.018", 0.005 }, 1 },
                        { "Station3D", { "0.015+0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo2 {
                condition = "(pylonAmmo3>1)*(pylonAmmo3<3)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station3", { -0.055, "0.0" }, 1 },
                            { "Station3", { 0.02, "0.0" }, 1 },
                            { "Station3", { 0.02, "0.12" }, 1 },
                            { "Station3", { -0.055, "0.12" }, 1 }
                        }

                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station3D", { "-0.011-0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011-0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011-0.018", "0.0077" }, 1 },
                            { "Station3D", { "-0.011-0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station3D", { "-0.015-0.018", -0.005 }, 1 },
                        { "Station3D", { "0.015-0.018", 0.005 }, 1 },
                        {},
                        { "Station3D", { "-0.015-0.018", 0.005 }, 1 },
                        { "Station3D", { "0.015-0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
            class ammo1 {
                condition = "(pylonAmmo3>0)*(pylonAmmo3<2)";
                class SDB {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\sdb.paa";
                    points[] = {
                        {
                            { "Station3", { -0.055, "-0.12" }, 1 },
                            { "Station3", { 0.02, "-0.12" }, 1 },
                            { "Station3", { 0.02, "0.0" }, 1 },
                            { "Station3", { -0.055, "0.0" }, 1 }
                        }
                    };
                };
                class SDBDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station3D", { "-0.011-0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011-0.018", "-0.0077" }, 1 },
                            { "Station3D", { "0.011-0.018", "0.0077" }, 1 },
                            { "Station3D", { "-0.011-0.018", "0.0077" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station3D", { "-0.015-0.018", -0.005 }, 1 },
                        { "Station3D", { "0.015-0.018", 0.005 }, 1 },
                        {},
                        { "Station3D", { "-0.015-0.018", 0.005 }, 1 },
                        { "Station3D", { "0.015-0.018", -0.005 }, 1 },
                        {}
                    };
                };
            };
        };
        class Pylon_2JDAM {
            condition = "(user3>9)*(user3<11)";
            class ammo2 {
                condition = "(pylonAmmo3>1)*(pylonAmmo3<3)";
                class JDAM {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                    points[] = {
                        {
                            { "Station3", { -0.085, "-0.103" }, 1 },
                            { "Station3", { 0.035, "-0.103" }, 1 },
                            { "Station3", { 0.035, "0.103" }, 1 },
                            { "Station3", { -0.085, "0.103" }, 1 }
                        }
                    };
                };
                class JDAMDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station3D", { 0.036, "-0.0112" }, 1 },
                            { "Station3D", { 0.004, "-0.0112" }, 1 },
                            { "Station3D", { 0.004, "0.0112" }, 1 },
                            { "Station3D", { 0.036, "0.0112" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station3D", { 0.04, -0.0126 }, 1 },
                        { "Station3D", { 0.000, 0.0126 }, 1 },
                        {},
                        { "Station3D", { 0.000, -0.0126 }, 1 },
                        { "Station3D", { 0.04, 0.0126 }, 1 },
                        {}
                    };
                };
            };
            class ammo1 {
                condition = "(pylonAmmo3>0)*(pylonAmmo3<2)";
                class JDAM {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\jdam.paa";
                    points[] = {
                        {
                            { "Station3", { 0.085, "-0.103" }, 1 },
                            { "Station3", { -0.035, "-0.103" }, 1 },
                            { "Station3", { -0.035, "0.103" }, 1 },
                            { "Station3", { 0.085, "0.103" }, 1 }
                        }
                    };
                };
                class JDAMDown {
                    type = "polygon";
                    texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                    points[] = {
                        {
                            { "Station3D", { -0.036, "-0.0112" }, 1 },
                            { "Station3D", { -0.004, "-0.0112" }, 1 },
                            { "Station3D", { -0.004, "0.0112" }, 1 },
                            { "Station3D", { -0.036, "0.0112" }, 1 }
                        }
                    };
                };
                class Fins {
                    type = "line";
                    width = 5;
                    points[] = {
                        { "Station3D", { -0.04, -0.0126 }, 1 },
                        { "Station3D", { 0.000, 0.0126 }, 1 },
                        {},
                        { "Station3D", { 0.000, -0.0126 }, 1 },
                        { "Station3D", { -0.04, 0.0126 }, 1 },
                        {}
                    };
                };
            };
        };
    };
};
