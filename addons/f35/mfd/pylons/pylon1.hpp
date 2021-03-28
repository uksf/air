class Pylon1 {
    condition = "pylonMagazineEmpty1<1";
    class GreenWPN {
        color[] = { 0, 1, 0, 1 };
        condition = "pylonSelected1<1";
        class Pylon_Sidewinder {
            condition = "(user1>0)*(user1<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station1", { -0.07, "-0.12" }, 1 },
                        { "Station1", { 0.07, "-0.12" }, 1 },
                        { "Station1", { 0.07, "0.12" }, 1 },
                        { "Station1", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station1D", { -0.008, "-0.0056" }, 1 },
                        { "Station1D", { 0.008, "-0.0056" }, 1 },
                        { "Station1D", { 0.008, "0.0056" }, 1 },
                        { "Station1D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station1D", { -0.012, -0.0084 }, 1 },
                    { "Station1D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station1D", { 0.012, -0.0084 }, 1 },
                    { "Station1D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
    };
    class WhiteWPN {
        color[] = { 1, 1, 1, 1 };
        condition = "pylonSelected1";
        class Pylon_Sidewinder {
            condition = "(user1>0)*(user1<2)";
            class Sidewinder {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\sidewinder.paa";
                points[] = {
                    {
                        { "Station1", { -0.07, "-0.12" }, 1 },
                        { "Station1", { 0.07, "-0.12" }, 1 },
                        { "Station1", { 0.07, "0.12" }, 1 },
                        { "Station1", { -0.07, "0.12" }, 1 }
                    }
                };
            };
            class SidewinderDown {
                type = "polygon";
                texture = "u\uksf_air\addons\f35\mfd\circle.paa";
                points[] = {
                    {
                        { "Station1D", { -0.008, "-0.0056" }, 1 },
                        { "Station1D", { 0.008, "-0.0056" }, 1 },
                        { "Station1D", { 0.008, "0.0056" }, 1 },
                        { "Station1D", { -0.008, "0.0056" }, 1 }
                    }
                };
            };
            class Fins {
                type = "line";
                width = 5;
                points[] = {
                    { "Station1D", { -0.012, -0.0084 }, 1 },
                    { "Station1D", { 0.012, 0.0084 }, 1 },
                    {},
                    { "Station1D", { 0.012, -0.0084 }, 1 },
                    { "Station1D", { -0.012, 0.0084 }, 1 },
                    {}
                };
            };
        };
    };
};
