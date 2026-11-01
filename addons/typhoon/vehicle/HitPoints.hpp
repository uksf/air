        class HitPoints : HitPoints {
            class HitHull : HitHull {
                armor = 3.5;
                explosionShielding = 3;
                passThrough = 1;
                radius = 0;
                minimalHit = 0.05;
                depends = "0";
                material = -1;
            };
            class HitEngine : HitHull {
                armor = 3;
                explosionShielding = 4.5;
                name = "motor";
                visual = "motor";
                passThrough = 0.8;
            };
            class HitEngine2 : HitEngine {
                name = "r_engine_nozzle";
                visual = "";
            };
            class HitAvionics : HitHull {
                armor = 1.5;
                explosionShielding = 4;
                name = "elektronika";
                visual = "elektronika";
                passThrough = 0.4;
            };
            class HitFuel : HitHull {
                armor = 4;
                explosionShielding = 5;
                name = "palivo";
                visual = "palivo";
                passThrough = 0.6;
            };
            class HitGlass1 : HitHull {
                armor = 1.5;
                explosionShielding = 3;
                name = "glass1";
                visual = "glass1";
                passThrough = 0;
                minimalHit = 0.1;
            };
            class HitGlass2 : HitGlass1 {};
            class HitLAileron : HitHull {
                armor = 1.8;
                explosionShielding = 3.5;
                name = "elevon_l_1";
                visual = "";
                passThrough = 0.3;
            };
            class HitRAileron : HitLAileron {
                name = "elevon_r_1";
            };
            class HitLCRudder : HitLAileron {
                name = "rudder";
            };
            class HitRRudder : HitLAileron {
                name = "rudder";
            };
            class HitLCElevator : HitLAileron {
                name = "canard_l";
            };
            class HitRElevator : HitLAileron {
                name = "canard_r";
            };
        };
