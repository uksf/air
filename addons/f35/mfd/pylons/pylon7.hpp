class Pylon7 {
    condition = "pylonMagazineEmpty7<1";
    class GreenWPN {
        color[] = { 0, 1, 0, 1 };
        condition = "pylonSelected7<1";
        class Pylon_Sidewinder {
            condition = "(user7>0)*(user7<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station7", { -0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "0.12" }, 1 },
                        { "Station7", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station7D", { -0.008, "-0.0056" }, 1 },
                        { "Station7D", { 0.008, "-0.0056" }, 1 },
                        { "Station7D", { 0.008, "0.0056" }, 1 },
                        { "Station7D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station7D", { -0.012, -0.0084 }, 1 },
                    { "Station7D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station7D", { 0.012, -0.0084 }, 1 },
                    { "Station7D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user7>1)*(user7<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station7", { -0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "0.12" }, 1 },
                        { "Station7", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station7D", { -0.011, "-0.0077" }, 1 },
                        { "Station7D", { 0.011, "-0.0077" }, 1 },
                        { "Station7D", { 0.011, "0.0077" }, 1 },
                        { "Station7D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station7D", { -0.016, -0.0112 }, 1 },
                    { "Station7D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station7D", { 0.016, -0.0112 }, 1 },
                    { "Station7D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
    };
    class WhiteWPN {
        color[] = { 1, 1, 1, 1 };
        condition = "pylonSelected7";
        class Pylon_Sidewinder {
            condition = "(user7>0)*(user7<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station7", { -0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "0.12" }, 1 },
                        { "Station7", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station7D", { -0.008, "-0.0056" }, 1 },
                        { "Station7D", { 0.008, "-0.0056" }, 1 },
                        { "Station7D", { 0.008, "0.0056" }, 1 },
                        { "Station7D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station7D", { -0.012, -0.0084 }, 1 },
                    { "Station7D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station7D", { 0.012, -0.0084 }, 1 },
                    { "Station7D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
        class Pylon_Ammram {
            condition = "(user7>1)*(user7<3)";
            class Ammram {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\amraam.paa";
                points[] = {
                    {
                        { "Station7", { -0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "-0.12" }, 1 },
                        { "Station7", { 0.07, "0.12" }, 1 },
                        { "Station7", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class AmmramDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station7D", { -0.011, "-0.0077" }, 1 },
                        { "Station7D", { 0.011, "-0.0077" }, 1 },
                        { "Station7D", { 0.011, "0.0077" }, 1 },
                        { "Station7D", { -0.011, "0.0077" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station7D", { -0.016, -0.0112 }, 1 },
                    { "Station7D", { 0.016, 0.0112 }, 1 },
                    {},
                    { "Station7D", { 0.016, -0.0112 }, 1 },
                    { "Station7D", { -0.016, 0.0112 }, 1 },
                    {}
                };
            };
        };
    };
};
