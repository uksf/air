class Pylon10 {
    condition = "pylonMagazineEmpty10<1";
    class GreenWPN {
        color[] = { 0, 1, 0, 1 };
        condition = "pylonSelected10<1";
        class Pylon_Sidewinder {
            condition = "(user10>0)*(user10<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station10", { -0.07, "-0.12" }, 1 },
                        { "Station10", { 0.07, "-0.12" }, 1 },
                        { "Station10", { 0.07, "0.12" }, 1 },
                        { "Station10", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station10D", { -0.008, "-0.0056" }, 1 },
                        { "Station10D", { 0.008, "-0.0056" }, 1 },
                        { "Station10D", { 0.008, "0.0056" }, 1 },
                        { "Station10D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station10D", { -0.012, -0.0084 }, 1 },
                    { "Station10D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station10D", { 0.012, -0.0084 }, 1 },
                    { "Station10D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
    };
    class WhiteWPN {
        color[] = { 1, 1, 1, 1 };
        condition = "pylonSelected10";
        class Pylon_Sidewinder {
            condition = "(user10>0)*(user10<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station10", { -0.07, "-0.12" }, 1 },
                        { "Station10", { 0.07, "-0.12" }, 1 },
                        { "Station10", { 0.07, "0.12" }, 1 },
                        { "Station10", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station10D", { -0.008, "-0.0056" }, 1 },
                        { "Station10D", { 0.008, "-0.0056" }, 1 },
                        { "Station10D", { 0.008, "0.0056" }, 1 },
                        { "Station10D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station10D", { -0.012, -0.0084 }, 1 },
                    { "Station10D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station10D", { 0.012, -0.0084 }, 1 },
                    { "Station10D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
    };
};
