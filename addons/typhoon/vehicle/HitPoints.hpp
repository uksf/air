        class HitPoints : HitPoints {
            class HitHull : HitHull {
                armor = 3.5;
                explosionShielding = 3;
                passThrough = 1;
                radius = 0.45;
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
                radius = 0.6;
            };
            class HitEngine2 : HitEngine {
                name = "motor_2";
                visual = "";
            };
            class HitAvionics : HitHull {
                armor = 1.5;
                explosionShielding = 4;
                name = "elektronika";
                visual = "elektronika";
                passThrough = 0.4;
                radius = 0.3;
            };
            class HitFuel : HitHull {
                armor = 4;
                explosionShielding = 5;
                name = "palivo";
                visual = "palivo";
                passThrough = 0.6;
                radius = 0.3;
            };
            class HitGlass1 : HitHull {
                armor = 1.5;
                explosionShielding = 3;
                name = "glass1";
                visual = "glass1";
                passThrough = 0;
                radius = 0.2;
                minimalHit = 0.1;
            };
            class HitGlass2 : HitGlass1 {
                name = "glass2";
            };
            class HitLAileron : HitHull {
                armor = 1.8;
                explosionShielding = 3.5;
                name = "hit_elevon_l_2";
                visual = "";
                passThrough = 0.3;
                radius = 0.35;
            };
            class HitRAileron : HitLAileron {
                name = "hit_elevon_r_2";
            };
            class HitLCRudder : HitLAileron {
                name = "hit_rudder";
            };
            class HitRRudder : HitLAileron {
                name = "hit_rudder";
            };
            class HitLCElevator : HitLAileron {
                name = "hit_elevon_l_1";
            };
            class HitRElevator : HitLAileron {
                name = "hit_elevon_r_1";
            };
        };
