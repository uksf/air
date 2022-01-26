class AirplaneHUD {
    enableParallax = 1;
    helmetMountedDisplay = 1;
    helmetPosition[] = { -0.04, 0.03, 0.1 };
    helmetRight[] = { 0.08, 0, 0 };
    helmetDown[] = { 0, -0.06, 0 };
    class Pos10Vector {
        type = "vector";
        pos0[] = { 0.5, 0.5 };
        pos10[] = { 0.71132398, 0.79310501 };
    };
    topLeft = "HUD LH";
    topRight = "HUD PH";
    bottomLeft = "HUD LD";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    color[] = { 0.15000001, 1, 0.15000001, 0.1 };
    class Bones {
        class TGPTarget {
            source = "pilotcameratoview";
            type = "vector";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };
        class text_debug {
            type = "fixed";
            pos[] = { 0.75, 0.75 };
        };
        //WeaponDistBand
        class DogfightTargetDist {
            type = "linear";
            source = "targetDist";
            sourceScale = 1;
            min = 0;
            max = 12000;
            minPos[] = { "0.30+0.32-0.002+0.1", "0.40 - 0.28+0.27" };
            maxPos[] = { "0.30+0.32-0.002+0.1", "0.567 - 0.28+0.33" };
        };

        /*class DogfightAmmoMin: DogfightAmmoMax {
            source = "LarAmmoMin";
        };

        class DogfightTargetDist: DogfightAmmoMax {
            source = "LarTargetDist";
        };*/
        //
        //WeaponDistBandAG
        class AGTargetDist {
            type = "linear";
            source = "targetDist";
            sourceScale = 1;
            min = 0;
            max = 12000;
            minPos[] = { "0.321+0.32+0.04", "0.15" };
            maxPos[] = { "0.321+0.32+0.04", "0.567 - 0.28+0.33+0.02" };
        };

        /*class AGAmmoMin: AGAmmoMax {
            source = "LarAmmoMin";
        };

        class AGTargetDist: AGAmmoMax {
            source = "LarTargetDist";
        };*/
        //
        //
        //WeaponDistBandBomb
        class BombTargetDist {
            type = "linear";
            source = "targetDist";
            sourceScale = 1;
            min = 0;
            max = 12000;
            minPos[] = { "0.31+0.32-0.3", "0.40 - 0.28+0.27-0.2" };
            maxPos[] = { "0.31+0.32-0.3", "0.567 - 0.28+0.33-0.2" };
        };

        /*class BombAmmoMin: BombAmmoMax {
            source = "LarAmmoMin";
        };

        class BombTargetDist: BombAmmoMax {
            source = "LarTargetDist";
        };*/
        //

        class ForwardVec {
            type = "vector";
            source = "forward";
            pos0[] = { 0, 0 };
            pos10[] = { 0.21132436, 0.29310483 };
        };
        class WaypointHUD {
            source = "wppointtoview";
            type = "vector";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };
        class ForwardVecX {
            type = "vector";
            source = "forward";
            pos0[] = { 0, 0 };
            pos10[] = { 0.21132436, 0 };
        };
        class ForwardVecY {
            type = "vector";
            source = "forward";
            pos0[] = { 0, 0 };
            pos10[] = { 0, 0.29310483 };
        };
        class ImpactPoint {
            type = "vector";
            source = "impactpointtoview";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };
        class ImpactPointRelative {
            type = "vector";
            source = "impactpointtoviewweaponRelative";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };
        class PlaneW {
            type = "fixed";
            pos[] = { 0.5, 0.5 };
        };
        class center {
            type = "fixed";
            pos[] = {
                0.5,
                "PoxY0Center"
            };
        };
        class horizon_data {
            type = "fixed";
            pos[] = { 0.215, 0.45050001 };
        };

        class waypointIndicator {
            type = "linear";
            source = "heading";
            sourceScale = 1;
            min = 0;
            max = 360;
            minPos[] = { 0, 0 };
            maxPos[] = { 7.1999998, 0 };
        };
        class speedIndicator {
            type = "fixed";
            pos[] = { 0.205, 0.27500001 };
        };
        class altIndicator {
            type = "fixed";
            pos[] = { 0.79500002, 0.27500001 };
        };
        class emconIndicator {
            type = "fixed";
            pos[] = { 0.79000002, 0.80000001 };
        };
        class LittleVtol1 {
            type = "rotational";
            source = "vtolvectoring";
            center[] = { 0.175, 0.75 };
            min = 0;
            max = 1;
            minAngle = 0;
            maxAngle = 90;
            aspectRatio = 0.8;
        };
        class LittleVtol2 {
            type = "rotational";
            source = "vtolvectoring";
            center[] = { 0.24, 0.75 };
            min = 0;
            max = 1;
            minAngle = 0;
            maxAngle = 90;
            aspectRatio = 0.8;
        };

        class LittlePlane {
            type = "fixed";
            pos[] = { 0.2, 0.75 };
        };
        class weaponIndicator {
            type = "fixed";
            pos[] = { 0.20999999, 0.80000001 };
        };
        class bottomIndicator {
            type = "fixed";
            pos[] = { 0.5, 0.94999999 };
        };
        class weaponAim : Pos10Vector {
            source = "weapon";
        };
        class Target : Pos10Vector {
            type = "vector";
            source = "targetToView";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };
        class Limit0109 {
            type = "limit";
            limits[] = { 0.10000001, 0.10000001, 0.89999, 0.89999 };
        };

        class Airport1 {
            type = "vector";
            source = "airportCorner1ToView";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };

        class Airport2 : Airport1 {
            source = "airportCorner2ToView";
        };

        class Airport3 : Airport1 {
            source = "airportCorner3ToView";
        };

        class Airport4 : Airport1 {
            source = "airportCorner4ToView";
        };

        class Velocity : Pos10Vector {
            type = "vector";
            source = "velocity";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };
        class Velocity2 : Pos10Vector {
            type = "vector";
            source = "velocityToView";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.71132398, 0.79310501 };
        };
        class ILS_H {
            type = "ils";
            pos0[] = { 0.5, 0.5 };
            pos3[] = { 0.56339699, 0.5 };
        };
        class ILS_W : ILS_H {
            pos3[] = { 0.5, 0.58793098 };
        };

#include "horizon.hpp"
#include "missileFlightTime.hpp"
        class NormalizeBombCircle {
            type = "normalizedorsmaller";
            limit = 0.070000;
            aspectRatio = 1.250000;
        };
        class NormalizeBombCircleSmall {
            type = "normalizedorsmaller";
            limit = 0.020000;
            aspectRatio = 1.250000;
        };
    };
    class Draw {
        alpha = 0.40000001;
        color[] = { 0.15000001, 1, 0.15000001 };

        class WPHud {
            condition = "wpvalid";

            class WPHudDir {
                type = "line";
                width = 2;
                points[] = {
                    { "WaypointHUD", 1, "Limit0109", 1, { 0.000000, 0.02500 }, 1 },
                    { "WaypointHUD", 1, "Limit0109", 1, { 0.020000, 0.000000 }, 1 },
                    { "WaypointHUD", 1, "Limit0109", 1, { 0.000000, -0.02500 }, 1 },
                    { "WaypointHUD", 1, "Limit0109", 1, { -0.020000, 0.000000 }, 1 },
                    { "WaypointHUD", 1, "Limit0109", 1, { 0.000000, 0.025000 }, 1 },

                    {},
                    {},

                    { "WaypointHUD", 1, { 0.00000, 0.000000 }, 1 },
                    { "WaypointHUD", -1, "Velocity", 1, "NormalizeBombCircle", 1, "WaypointHUD", 1, { 0.000000, 0.000000 }, 1 }
                };
            };
            class WpDist {
                type = "text";
                align = "center";
                scale = 1;
                source = "wpdist";
                sourcelength = 2;
                sourceScale = 0.01;
                pos[] = { "WaypointHUD", { "0", "0.02" }, 1 };
                right[] = { "WaypointHUD", { 0.03, "0.02" }, 1 };
                down[] = { "WaypointHUD", { "0", "0.055" }, 1 };
            };
        };

        class centerPoint {
            type = "line";
            width = 4;
            points[] = {

                { "PlaneW",
                  { 0, -0.0024999999 },
                  1 },

                { "PlaneW",
                  { 0, 0.0024999999 },
                  1 },
                {},

                { "PlaneW",
                  { 0.0020000001, 0 },
                  1 },

                { "PlaneW",
                  { -0.0020000001, 0 },
                  1 },
                {}
            };
        };
        class flightPathVector {
            clipTL[] = { 0, 1 };
            clipBR[] = { 1, 0 };
            type = "line";
            width = 4;
            points[] = {

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0, 0.0138699 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0025881899, 0.0133973 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0049999999, 0.0120117 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0070710699, 0.0098075001 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0086602503, 0.0069349501 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0096592596, 0.0035897901 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0099999998, -6.0627298e-010 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0096592596, -0.0035898001 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0086602503, -0.0069349501 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0070710699, -0.0098075001 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0049999999, -0.0120117 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0025881899, -0.0133973 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -8.7422802e-010, -0.0138699 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0025881899, -0.0133973 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0049999999, -0.0120117 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0070710699, -0.0098075001 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0086602503, -0.0069349501 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0096592596, -0.0035897901 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0099999998, 1.65397e-010 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0096592596, 0.0035898001 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0086602503, 0.0069349599 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0070710699, 0.0098075001 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0049999999, 0.0120117 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0025881899, 0.0133973 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 1.74846e-009, 0.0138699 },
                  1 },
                {},

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.029999999, 0 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0.0099999998, 0 },
                  1 },
                {},

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.029999999, 0 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { -0.0099999998, 0 },
                  1 },
                {},

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0, -0.027739801 },
                  1 },

                { "Velocity",
                  1,
                  "ForwardVec",
                  { 0, -0.0138699 },
                  1 },
                {}
            };
        };
        class AltWarn {
            type = "group";
            condition = "altitudeAGL<150";
            class cond2 {
                type = "group";
                condition = "speed>40";
                class cond2 {
                    type = "group";
                    condition = "ils<1";
                    class cond3 {
                        type = "group";
                        condition = "AoA<-20";
                        clipTL[] = { 0, 0 };
                        clipBR[] = { 1, 0.93 };
                        blinkingPattern[] = { 0.200000, 0.200000 };
                        blinkingStartsOn = 1;
                        class Cross {
                            type = "line";
                            width = 3;
                            points[] = {
                                { "PlaneW", { -0.4, -0.4 }, 1 },
                                { "PlaneW", { -0.025, -0.02 }, 1 },
                                {},
                                { "PlaneW", { 0.025, 0.02 }, 1 },
                                { "PlaneW", { 0.4, 0.4 }, 1 },
                                {},
                                { "PlaneW", { 0.4, -0.4 }, 1 },
                                { "PlaneW", { 0.025, -0.02 }, 1 },
                                {},
                                { "PlaneW", { -0.025, 0.02 }, 1 },
                                { "PlaneW", { -0.4, 0.4 }, 1 },
                                {}
                            };
                        };
                        class PullUP {
                            type = "text";
                            source = "static";
                            text = "PULL-UP";
                            scale = 1;
                            sourceScale = 1;
                            align = "center";
                            pos[] = { "PlaneW", { -0.007, 0.050000 }, 1 };
                            right[] = { "PlaneW", { 0.043, 0.050000 }, 1 };
                            down[] = { "PlaneW", { -0.007, 0.1000 }, 1 };
                        };
                    };
                };
            };
        };
        class Horizon {
            class Horizon_1 {
                clipTL[] = { 0.26300001, 0.112 };
                clipBR[] = { 1, 1 };
                class Level0_1 {
                    type = "line";
                    width = 4;
                    points[] = {

                        { "Level0",
                          { 2, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "Level0",
                          { 0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "level0",
                          { -0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "level0",
                          { -2, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
            };
            class Horizon_2 {
                clipTL[] = { 0, 0.112 };
                clipBR[] = { 0.213, 1 };
                class Level0_2 {
                    type = "line";
                    width = 4;
                    points[] = {

                        { "Level0",
                          { 2, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "Level0",
                          { 0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "level0",
                          { -0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "level0",
                          { -2, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
            };
            class Horizon_3 {
                clipTL[] = { 0.213, 0.112 };
                clipBR[] = { 0.26300001, 0.45100001 };
                class Level0_3 {
                    type = "line";
                    width = 4;
                    points[] = {

                        { "Level0",
                          { 2, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "Level0",
                          { 0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "level0",
                          { -0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "level0",
                          { -2, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
            };
            class Horizon_4 {
                clipTL[] = { 0.213, 0.54049999 };
                clipBR[] = { 0.26300001, 1 };
                class Level0_4 {
                    type = "line";
                    width = 4;
                    points[] = {

                        { "Level0",
                          { 2, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "Level0",
                          { 0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "level0",
                          { -0.079999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "level0",
                          { -2, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
            };
            clipTL[] = { 0, 0.112 };
            clipBR[] = { 1, 1 };
            class HorizonLadder {
                class LevelM5 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM5",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM5",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM5",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_5 {
                    type = "text";
                    source = "static";
                    text = -5;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM5",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM5",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM5",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_5 {
                    type = "text";
                    source = "static";
                    text = -5;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM5",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM5",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM5",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP5 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP5",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP5",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP5",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP5",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP5",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP5",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_5 {
                    type = "text";
                    source = "static";
                    text = "5";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP5",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP5",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP5",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_5 {
                    type = "text";
                    source = "static";
                    text = "5";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP5",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP5",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP5",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM10 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM10",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM10",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM10",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_10 {
                    type = "text";
                    source = "static";
                    text = -10;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM10",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM10",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM10",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_10 {
                    type = "text";
                    source = "static";
                    text = -10;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM10",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM10",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM10",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP10 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP10",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP10",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP10",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP10",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP10",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP10",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_10 {
                    type = "text";
                    source = "static";
                    text = "10";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP10",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP10",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP10",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_10 {
                    type = "text";
                    source = "static";
                    text = "10";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP10",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP10",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP10",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM15 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM15",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM15",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM15",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_15 {
                    type = "text";
                    source = "static";
                    text = -15;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM15",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM15",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM15",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_15 {
                    type = "text";
                    source = "static";
                    text = -15;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM15",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM15",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM15",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP15 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP15",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP15",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP15",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP15",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP15",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP15",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_15 {
                    type = "text";
                    source = "static";
                    text = "15";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP15",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP15",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP15",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_15 {
                    type = "text";
                    source = "static";
                    text = "15";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP15",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP15",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP15",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM20 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM20",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM20",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM20",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_20 {
                    type = "text";
                    source = "static";
                    text = -20;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM20",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM20",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM20",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_20 {
                    type = "text";
                    source = "static";
                    text = -20;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM20",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM20",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM20",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP20 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP20",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP20",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP20",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP20",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP20",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP20",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_20 {
                    type = "text";
                    source = "static";
                    text = "20";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP20",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP20",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP20",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_20 {
                    type = "text";
                    source = "static";
                    text = "20";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP20",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP20",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP20",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM25 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM25",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM25",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM25",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_25 {
                    type = "text";
                    source = "static";
                    text = -25;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM25",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM25",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM25",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_25 {
                    type = "text";
                    source = "static";
                    text = -25;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM25",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM25",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM25",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP25 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP25",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP25",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP25",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP25",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP25",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP25",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_25 {
                    type = "text";
                    source = "static";
                    text = "25";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP25",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP25",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP25",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_25 {
                    type = "text";
                    source = "static";
                    text = "25";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP25",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP25",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP25",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM30 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM30",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM30",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM30",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_30 {
                    type = "text";
                    source = "static";
                    text = -30;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM30",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM30",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM30",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_30 {
                    type = "text";
                    source = "static";
                    text = -30;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM30",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM30",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM30",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP30 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP30",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP30",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP30",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP30",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP30",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP30",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_30 {
                    type = "text";
                    source = "static";
                    text = "30";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP30",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP30",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP30",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_30 {
                    type = "text";
                    source = "static";
                    text = "30";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP30",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP30",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP30",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM35 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM35",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM35",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM35",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_35 {
                    type = "text";
                    source = "static";
                    text = -35;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM35",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM35",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM35",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_35 {
                    type = "text";
                    source = "static";
                    text = -35;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM35",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM35",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM35",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP35 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP35",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP35",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP35",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP35",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP35",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP35",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_35 {
                    type = "text";
                    source = "static";
                    text = "35";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP35",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP35",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP35",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_35 {
                    type = "text";
                    source = "static";
                    text = "35";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP35",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP35",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP35",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM40 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM40",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM40",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM40",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_40 {
                    type = "text";
                    source = "static";
                    text = -40;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM40",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM40",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM40",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_40 {
                    type = "text";
                    source = "static";
                    text = -40;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM40",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM40",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM40",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP40 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP40",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP40",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP40",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP40",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP40",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP40",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_40 {
                    type = "text";
                    source = "static";
                    text = "40";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP40",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP40",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP40",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_40 {
                    type = "text";
                    source = "static";
                    text = "40";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP40",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP40",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP40",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM45 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM45",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM45",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM45",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_45 {
                    type = "text";
                    source = "static";
                    text = -45;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM45",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM45",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM45",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_45 {
                    type = "text";
                    source = "static";
                    text = -45;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM45",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM45",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM45",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP45 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP45",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP45",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP45",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP45",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP45",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP45",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_45 {
                    type = "text";
                    source = "static";
                    text = "45";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP45",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP45",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP45",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_45 {
                    type = "text";
                    source = "static";
                    text = "45";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP45",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP45",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP45",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM50 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM50",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM50",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM50",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_50 {
                    type = "text";
                    source = "static";
                    text = -50;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM50",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM50",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM50",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_50 {
                    type = "text";
                    source = "static";
                    text = -50;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM50",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM50",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM50",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP50 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP50",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP50",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP50",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP50",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP50",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP50",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_50 {
                    type = "text";
                    source = "static";
                    text = "50";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP50",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP50",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP50",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_50 {
                    type = "text";
                    source = "static";
                    text = "50";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP50",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP50",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP50",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM55 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM55",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM55",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM55",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_55 {
                    type = "text";
                    source = "static";
                    text = -55;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM55",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM55",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM55",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_55 {
                    type = "text";
                    source = "static";
                    text = -55;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM55",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM55",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM55",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP55 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP55",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP55",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP55",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP55",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP55",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP55",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_55 {
                    type = "text";
                    source = "static";
                    text = "55";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP55",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP55",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP55",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_55 {
                    type = "text";
                    source = "static";
                    text = "55";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP55",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP55",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP55",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM60 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM60",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM60",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM60",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_60 {
                    type = "text";
                    source = "static";
                    text = -60;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM60",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM60",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM60",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_60 {
                    type = "text";
                    source = "static";
                    text = -60;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM60",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM60",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM60",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP60 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP60",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP60",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP60",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP60",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP60",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP60",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_60 {
                    type = "text";
                    source = "static";
                    text = "60";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP60",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP60",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP60",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_60 {
                    type = "text";
                    source = "static";
                    text = "60";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP60",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP60",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP60",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM65 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM65",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM65",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM65",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_65 {
                    type = "text";
                    source = "static";
                    text = -65;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM65",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM65",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM65",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_65 {
                    type = "text";
                    source = "static";
                    text = -65;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM65",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM65",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM65",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP65 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP65",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP65",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP65",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP65",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP65",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP65",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_65 {
                    type = "text";
                    source = "static";
                    text = "65";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP65",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP65",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP65",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_65 {
                    type = "text";
                    source = "static";
                    text = "65";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP65",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP65",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP65",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM70 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM70",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM70",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM70",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_70 {
                    type = "text";
                    source = "static";
                    text = -70;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM70",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM70",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM70",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_70 {
                    type = "text";
                    source = "static";
                    text = -70;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM70",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM70",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM70",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP70 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP70",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP70",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP70",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP70",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP70",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP70",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_70 {
                    type = "text";
                    source = "static";
                    text = "70";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP70",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP70",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP70",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_70 {
                    type = "text";
                    source = "static";
                    text = "70";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP70",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP70",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP70",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM75 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM75",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM75",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM75",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_75 {
                    type = "text";
                    source = "static";
                    text = -75;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM75",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM75",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM75",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_75 {
                    type = "text";
                    source = "static";
                    text = -75;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM75",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM75",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM75",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP75 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP75",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP75",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP75",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP75",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP75",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP75",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_75 {
                    type = "text";
                    source = "static";
                    text = "75";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP75",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP75",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP75",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_75 {
                    type = "text";
                    source = "static";
                    text = "75";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP75",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP75",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP75",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM80 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM80",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM80",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM80",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_80 {
                    type = "text";
                    source = "static";
                    text = -80;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM80",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM80",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM80",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_80 {
                    type = "text";
                    source = "static";
                    text = -80;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM80",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM80",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM80",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP80 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP80",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP80",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP80",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP80",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP80",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP80",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_80 {
                    type = "text";
                    source = "static";
                    text = "80";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP80",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP80",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP80",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_80 {
                    type = "text";
                    source = "static";
                    text = "80";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP80",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP80",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP80",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM85 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM85",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM85",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM85",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_85 {
                    type = "text";
                    source = "static";
                    text = -85;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM85",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM85",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM85",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_85 {
                    type = "text";
                    source = "static";
                    text = -85;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM85",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM85",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM85",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP85 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP85",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP85",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP85",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP85",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP85",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP85",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_85 {
                    type = "text";
                    source = "static";
                    text = "85";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP85",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP85",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP85",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_85 {
                    type = "text";
                    source = "static";
                    text = "85";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP85",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP85",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP85",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelM90 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelM90",
                          { -0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { -0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { -0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { -0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { -0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { -0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { -0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { -0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { -0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { -0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { -0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { -0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { -0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { 0.18000001, -0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { 0.18000001, -0.0049999999 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { 0.175, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { 0.16500001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { 0.155, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { 0.145, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { 0.13500001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { 0.125, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { 0.115, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { 0.105, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { 0.094999999, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { 0.085000001, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelM90",
                          { 0.075000003, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelM90",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALM_1_90 {
                    type = "text";
                    source = "static";
                    text = -90;
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM90",
                        { 0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM90",
                        { 0.24250001, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM90",
                        { 0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALM_2_90 {
                    type = "text";
                    source = "static";
                    text = -90;
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelM90",
                        { -0.205, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelM90",
                        { -0.1675, -0.039999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelM90",
                        { -0.205, 0.0099999998 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class LevelP90 {
                    type = "line";
                    width = 1.2;
                    points[] = {

                        { "LevelP90",
                          { -0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP90",
                          { -0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP90",
                          { -0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },
                        {},

                        { "LevelP90",
                          { 0.064999998, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP90",
                          { 0.18000001, 0 },
                          1,
                          "ForwardVec",
                          1 },

                        { "LevelP90",
                          { 0.18000001, 0.015 },
                          1,
                          "ForwardVec",
                          1 }
                    };
                };
                class VALP_1_90 {
                    type = "text";
                    source = "static";
                    text = "90";
                    align = "left";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP90",
                        { -0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP90",
                        { -0.1675, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP90",
                        { -0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
                class VALP_2_90 {
                    type = "text";
                    source = "static";
                    text = "90";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "LevelP90",
                        { 0.205, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    right[] = {
                        "LevelP90",
                        { 0.24250001, -0.02 },
                        1,
                        "ForwardVec",
                        1
                    };
                    down[] = {
                        "LevelP90",
                        { 0.205, 0.029999999 },
                        1,
                        "ForwardVec",
                        1
                    };
                };
            };
        };
        class Horizon_data {
            class hAlpha {
                class aText {
                    type = "text";
                    source = "static";
                    text = "a";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "horizon_data",
                        { "0", 0 },
                        1
                    };
                    right[] = {
                        "horizon_data",
                        { "0.0300001", 0 },
                        1
                    };
                    down[] = {
                        "horizon_data",
                        { "0", 0.04 },
                        1
                    };
                };
                class aValue {
                    type = "text";
                    source = "AoA";
                    sourceScale = 0.1;
                    align = "right";
                    scale = 1;
                    pos[] = {
                        "horizon_data",
                        { 0.035, 0 },
                        1
                    };
                    right[] = {
                        "horizon_data",
                        { "0.035+0.03", 0 },
                        1
                    };
                    down[] = {
                        "horizon_data",
                        { 0.035, 0.04 },
                        1
                    };
                };
            };
            class hMach {
                class mText {
                    type = "text";
                    source = "static";
                    text = "M";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "horizon_data",
                        { "0", 0.030999999 },
                        1
                    };
                    right[] = {
                        "horizon_data",
                        { "0.03", 0.030999999 },
                        1
                    };
                    down[] = {
                        "horizon_data",
                        { "0", 0.071000001 },
                        1
                    };
                };
                class mValue {
                    type = "text";
                    source = "speed";
                    sourceScale = 0.00294;
                    sourceprecision = 2;
                    sourceLength = 1;
                    align = "right";
                    scale = 1;
                    pos[] = {
                        "horizon_data",
                        { 0.035, 0.030999999 },
                        1
                    };
                    right[] = {
                        "horizon_data",
                        { "0.035+0.03", 0.030999999 },
                        1
                    };
                    down[] = {
                        "horizon_data",
                        { 0.035, 0.071000001 },
                        1
                    };
                };
            };
            class hGforce {
                class gText {
                    type = "text";
                    source = "static";
                    text = "G";
                    align = "right";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "horizon_data",
                        { "0", 0.061999999 },
                        1
                    };
                    right[] = {
                        "horizon_data",
                        { "0.03", 0.061999999 },
                        1
                    };
                    down[] = {
                        "horizon_data",
                        { "0", 0.102 },
                        1
                    };
                };
                class gValue {
                    type = "text";
                    source = "gmeterGrav";
                    sourceScale = 0.1;
                    sourceprecision = 1;
                    align = "right";
                    scale = 1;
                    pos[] = {
                        "horizon_data",
                        { 0.035, 0.061999999 },
                        1
                    };
                    right[] = {
                        "horizon_data",
                        { "0.035+0.03", 0.061999999 },
                        1
                    };
                    down[] = {
                        "horizon_data",
                        { 0.035, 0.102 },
                        1
                    };
                };
            };
        };
        class speedIndicator {
            class indicatorBox {
                type = "line";
                width = 4;
                points[] = {

                    { "speedIndicator",
                      { 0, 0 },
                      1 },

                    { "speedIndicator",
                      { 0, 0.048960801 },
                      1 },

                    { "speedIndicator",
                      { 0.068834998, 0.048960801 },
                      1 },

                    { "speedIndicator",
                      { 0.068834998, 0 },
                      1 },

                    { "speedIndicator",
                      { 0, 0 },
                      1 }
                };
            };
            class speedKnots {
                type = "text";
                source = "speed";
                scale = 1;
                sourceScale = 1.94384;
                align = "center";
                pos[] = {
                    "speedIndicator",
                    { 0.034417499, -0.00385 },
                    1
                };
                right[] = {
                    "speedIndicator",
                    { 0.069417499, -0.00385 },
                    1
                };
                down[] = {
                    "speedIndicator",
                    { 0.034417499, 0.046149999 },
                    1
                };
            };
            class text_GS {
                type = "text";
                source = "static";
                text = "GS";
                scale = 1;
                sourceScale = 1;
                align = "right";
                pos[] = {
                    "speedIndicator",
                    { 0, 0.050299998 },
                    1
                };
                right[] = {
                    "speedIndicator",
                    { 0.0300001, 0.050299998 },
                    1
                };
                down[] = {
                    "speedIndicator",
                    { 0, 0.090300003 },
                    1
                };
            };
            class speedGround {
                type = "text";
                source = "speed";
                scale = 1;
                sourceScale = 2.05;
                align = "left";
                pos[] = {
                    "speedIndicator",
                    { 0.068834998, 0.050299998 },
                    1
                };
                right[] = {
                    "speedIndicator",
                    { 0.098835, 0.050299998 },
                    1
                };
                down[] = {
                    "speedIndicator",
                    { 0.068834998, 0.090300003 },
                    1
                };
            };
        };
        class altIndicator {
            class indicatorBox {
                type = "line";
                width = 4;
                points[] = {

                    { "altIndicator",
                      { 0, 0 },
                      1 },

                    { "altIndicator",
                      { 0, 0.048960801 },
                      1 },

                    { "altIndicator",
                      { -0.087191001, 0.048960801 },
                      1 },

                    { "altIndicator",
                      { -0.087191001, 0 },
                      1 },

                    { "altIndicator",
                      { 0, 0 },
                      1 }
                };
            };
            class altFeet {
                type = "text";
                source = "altitudeASL";
                scale = 1;
                sourceScale = 3.28084;
                align = "center";
                pos[] = {
                    "altIndicator",

                    { -0.0435955,
                      "-0.00385)" },
                    1
                };
                right[] = {
                    "altIndicator",

                    { "-0.0085955)",
                      -0.00385 },
                    1
                };
                down[] = {
                    "altIndicator",
                    { -0.0435955, 0.046149999 },
                    1
                };
            };
            class text_R {
                type = "text";
                source = "static";
                text = "R";
                scale = 1;
                sourceScale = 1;
                align = "right";
                pos[] = {
                    "altIndicator",
                    { -0.077191003, 0.050299998 },
                    1
                };
                right[] = {
                    "altIndicator",
                    { -0.04719, 0.050299998 },
                    1
                };
                down[] = {
                    "altIndicator",
                    { -0.077191003, 0.090300003 },
                    1
                };
            };
            class altRadar {
                type = "text";
                source = "altitudeAGL";
                scale = 1;
                sourceScale = 3.28084;
                align = "left";
                pos[] = {
                    "altIndicator",

                    { -0.0099999998,
                      "0.0353  + (	0.03	 / 2))" },
                    1
                };
                right[] = {
                    "altIndicator",
                    { 0.02, 0.050299998 },
                    1
                };
                down[] = {
                    "altIndicator",
                    { -0.0099999998, 0.090300003 },
                    1
                };
            };
        };
        class emconIndicator {
            class emcon {
                type = "text";
                source = "static";
                text = "EMCON";
                align = "center";
                scale = 1;
                sourceScale = 1;
                pos[] = {
                    "emconIndicator",
                    { 0, 0 },
                    1
                };
                right[] = {
                    "emconIndicator",

                    { "0.03*0.75",
                      0 },
                    1
                };
                down[] = {
                    "emconIndicator",
                    { 0, 0.029999999 },
                    1
                };
            };
            class emconValue {
                type = "text";
                source = "static";
                text = "DL 014";
                align = "center";
                scale = 1;
                sourceScale = 1;
                pos[] = {
                    "emconIndicator",
                    { 0, 0.029999999 },
                    1
                };
                right[] = {
                    "emconIndicator",

                    { "0.03*0.75",
                      0.029999999 },
                    1
                };
                down[] = {
                    "emconIndicator",

                    { 0,
                      "0.03*2" },
                    1
                };
            };
        };
        class Laser {
            condition = "laseron";
            class LaserText {
                type = "text";
                source = "static";
                text = "LASER";
                align = "left";
                scale = 1;
                pos[] = { { 0.932, 0.8 }, 1 };
                right[] = { { 0.987, 0.8 }, 1 };
                down[] = { { 0.932, 0.845 }, 1 };
            };
        };
        class LittlePlane {
            type = "line";
            width = 3;
            points[] = {
                { "LittlePlane", { 0.04, "-0.012" }, 1 },
                { "LittlePlane", { 0.043, "-0.012" }, 1 },
                { "LittlePlane", { 0.048, "-0.024" }, 1 },
                { "LittlePlane", { 0.06, "-0.024" }, 1 },
                { "LittlePlane", { 0.055, "0.00" }, 1 },
                { "LittlePlane", { 0.05, "0.007" }, 1 },
                { "LittlePlane", { -0.035, "0.007" }, 1 },
                { "LittlePlane", { -0.05, "0" }, 1 },
                { "LittlePlane", { -0.061, "0" }, 1 },  //tip
                { "LittlePlane", { -0.05, "0" }, 1 },
                { "LittlePlane", { -0.035, "-0.012" }, 1 },
                { "LittlePlane", { -0.03, "-0.012" }, 1 },
                {}
            };
        };
        class LittlePlaneThrust {
            type = "text";
            source = "throttle";
            sourceScale = 100;
            align = "center";
            scale = 1;
            pos[] = { "LittlePlane", { -0.00, -0.040000 }, 1 };
            right[] = { "LittlePlane", { 0.05, -0.040000 }, 1 };
            down[] = { "LittlePlane", { -0.00, 0.010000 }, 1 };
        };
        //VTOL
        class LittleVtol1_V {
            type = "text";
            source = "vtolvectoring";
            sourceScale = 90;
            min = 0;
            align = "center";
            scale = 1;
            pos[] = { "LittlePlane", { -0.03, 0.030000 }, 1 };
            right[] = { "LittlePlane", { 0.01, 0.030000 }, 1 };
            down[] = { "LittlePlane", { -0.03, 0.070000 }, 1 };
        };
        class LittleVtol2_V {
            type = "text";
            source = "vtolvectoring";
            sourceScale = 90;
            min = 0;
            align = "center";
            scale = 1;
            pos[] = { "LittlePlane", { 0.04, 0.030000 }, 1 };
            right[] = { "LittlePlane", { 0.08, 0.030000 }, 1 };
            down[] = { "LittlePlane", { 0.04, 0.070000 }, 1 };
        };
        class LittleVtol1_A {
            type = "line";
            width = 3;
            points[] = {
                { "LittleVtol1", { 0, "0" }, 1 },
                { "LittleVtol1", { 0.05, "0" }, 1 },
                {},
                { "LittleVtol1", { 0.045, "-0.005" }, 1 },
                { "LittleVtol1", { 0.05, "0" }, 1 },
                { "LittleVtol1", { 0.045, "0.005" }, 1 },
                {},
                { "LittleVtol2", { 0, "0" }, 1 },
                { "LittleVtol2", { 0.05, "0" }, 1 },
                {},
                { "LittleVtol2", { 0.045, "-0.005" }, 1 },
                { "LittleVtol2", { 0.05, "0" }, 1 },
                { "LittleVtol2", { 0.045, "0.005" }, 1 }
            };
        };

        class TargetingPodLockTerrain {
            condition = "pilotcameralock<2";
            class condition2 {
                condition = "pilotcameralock";
                class TargetDIR {
                    type = "line";
                    width = 2;
                    points[] = {
                        { "TGPTarget", { 0, -0.04 }, 1 },
                        { "TGPTarget", { 0.00417, -0.03 }, 1 },
                        {},
                        { "TGPTarget", { 0, -0.04 }, 1 },
                        { "TGPTarget", { -0.00417, -0.03 }, 1 },
                        {},

                        { "TGPTarget", { -0.00583, -0.026 }, 1 },
                        { "TGPTarget", { -0.00833, -0.02 }, 1 },
                        {},
                        { "TGPTarget", { 0.00583, -0.026 }, 1 },
                        { "TGPTarget", { 0.00833, -0.02 }, 1 },
                        {},

                        { "TGPTarget", { -0.01667, 0 }, 1 },
                        { "TGPTarget", { -0.01917, 0.006 }, 1 },
                        {},
                        { "TGPTarget", { 0.01667, 0 }, 1 },
                        { "TGPTarget", { 0.01917, 0.006 }, 1 },
                        {},

                        { "TGPTarget", { -0.02083, 0.01 }, 1 },
                        { "TGPTarget", { -0.025, 0.02 }, 1 },
                        {},
                        { "TGPTarget", { 0.02083, 0.01 }, 1 },
                        { "TGPTarget", { 0.025, 0.02 }, 1 },
                        {},

                        { "TGPTarget", { -0.02083, 0.01 }, 1 },
                        { "TGPTarget", { -0.025, 0.02 }, 1 },
                        {},
                        { "TGPTarget", { 0.02083, 0.01 }, 1 },
                        { "TGPTarget", { 0.025, 0.02 }, 1 },
                        {},
                        //__
                        { "TGPTarget", { -0.025, 0.02 }, 1 },
                        { "TGPTarget", { -0.017, 0.02 }, 1 },
                        {},
                        { "TGPTarget", { 0.025, 0.02 }, 1 },
                        { "TGPTarget", { 0.017, 0.02 }, 1 },
                        {},

                        { "TGPTarget", { -0.014, 0.02 }, 1 },
                        { "TGPTarget", { -0.009, 0.02 }, 1 },
                        {},
                        { "TGPTarget", { 0.014, 0.02 }, 1 },
                        { "TGPTarget", { 0.009, 0.02 }, 1 },
                        {}
                    };
                };
            };
        };
        class TargetingPodLockPoint {
            condition = "pilotcameralock>1";
            class TargetDIR {
                type = "line";
                width = 2;
                points[] = {
                    { "TGPTarget", { 0, -0.04 }, 1 },
                    { "TGPTarget", { 0.025, 0.02 }, 1 },
                    { "TGPTarget", { -0.025, 0.02 }, 1 },
                    { "TGPTarget", { 0, -0.04 }, 1 }
                };
            };
        };
        class TGPSquare {
            condition = "pilotcameralock";
            class TargetDIR {
                type = "line";
                width = 2;
                points[] = {
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.095 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.1 }, 1 },

                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.095 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.076, -0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.072, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.056, -0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0464, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0304, -0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0208, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0048, -0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0048, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0208, -0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0304, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0464, -0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.056, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.072, -0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.076, -0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.1 }, 1 },

                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.095 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.09 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.07 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.058 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.038 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.026 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, -0.006 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.006 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.026 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.038 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.058 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.07 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.09 }, 1 },
                    {},

                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.095 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.08, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.076, 0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.072, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.056, 0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0464, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0304, 0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0208, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { 0.0048, 0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0048, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0208, 0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0304, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.0464, 0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.056, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.072, 0.1 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.076, 0.1 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.1 }, 1 },

                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.095 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.09 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.07 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.058 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.038 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.026 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, 0.006 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.006 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.026 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.038 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.058 }, 1 },
                    {},
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.07 }, 1 },
                    { "TGPTarget", 1, "Limit0109", 1, { -0.08, -0.09 }, 1 },
                    {}
                };
            };
        };

        class weaponIndicator {
            class aamCondition {
                condition = "AAmissile";
                class aamIndicator {
                    type = "text";
                    source = "static";
                    text = "AA";
                    align = "center";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "weaponIndicator",
                        { 0, 0 },
                        1
                    };
                    right[] = {
                        "weaponIndicator",

                        { "0.03*0.75",
                          0 },
                        1
                    };
                    down[] = {
                        "weaponIndicator",
                        { 0, 0.029999999 },
                        1
                    };
                };
            };
            class agmCondition {
                condition = "ATmissile";
                class agmIndicator {
                    type = "text";
                    source = "static";
                    text = "AG";
                    align = "center";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "weaponIndicator",
                        { 0, 0 },
                        1
                    };
                    right[] = {
                        "weaponIndicator",

                        { "0.03*0.75",
                          0 },
                        1
                    };
                    down[] = {
                        "weaponIndicator",
                        { 0, 0.029999999 },
                        1
                    };
                };
            };
            class bombCondition {
                condition = "bomb";
                class bombIndicator {
                    type = "text";
                    source = "static";
                    text = "AG";
                    align = "center";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "weaponIndicator",
                        { 0, 0 },
                        1
                    };
                    right[] = {
                        "weaponIndicator",

                        { "0.03*0.75",
                          0 },
                        1
                    };
                    down[] = {
                        "weaponIndicator",
                        { 0, 0.029999999 },
                        1
                    };
                };
            };
            class weaponValue {
                type = "text";
                source = "weapon";
                align = "center";
                scale = 1;
                sourceScale = 1;
                pos[] = {
                    "weaponIndicator",
                    { 0, 0.029999999 },
                    1
                };
                right[] = {
                    "weaponIndicator",

                    { "0.03*0.75",
                      0.029999999 },
                    1
                };
                down[] = {
                    "weaponIndicator",

                    { 0,
                      "0.03 * 2" },
                    1
                };
            };
        };
        class planeHeading {
            class headingScroll {
                type = "scale";
                horizontal = 1;
                source = "heading";
                sourceScale = 0.1;
                width = 2;
                top = 0;
                center = 0.5;
                bottom = 1;
                lineXleft = 0.105;
                lineYright = 0.094999999;
                lineXleftMajor = 0.11;
                lineYrightMajor = 0.090000004;
                majorLineEach = 2;
                numberEach = 2;
                step = 0.5;
                stepsize = 0.1;
                align = "center";
                scale = 1;
                pos[] = { 0, 0.045000002 };
                right[] = { 0.029999999, 0.045000002 };
                down[] = { 0, 0.085000001 };
            };
            class headingIndicator {
                type = "text";
                source = "heading";
                sourceScale = 1;
                scale = 1;
                align = "center";
                pos[] = {
                    { 0.5, 0.0049999999 },
                    1
                };
                right[] = {
                    { 0.52999997, 0.0049999999 },
                    1
                };
                down[] = {
                    { 0.5, 0.045000002 },
                    1
                };
            };
            class headingIndicatorBox {
                type = "line";
                width = 2;
                points[] = {

                    { { 0.477, 0.0099999998 },
                      1 },

                    { { 0.523, 0.0099999998 },
                      1 },

                    { { 0.523, 0.041000001 },
                      1 },

                    { { 0.477, 0.041000001 },
                      1 },

                    { { 0.477, 0.0099999998 },
                      1 },
                    {},

                    { { 0.493, 0.041000001 },
                      1 },

                    { { 0.5, 0.050000001 },
                      1 },

                    { { 0.50700003, 0.041000001 },
                      1 }
                };
            };
            class waypointMarkers {
                class waypointIndicator68 {
                    class value_1_group68 {
                        clipTL[] = { 0.523, 0 };
                        clipBR[] = { 1, 1 };
                        class value_168 {
                            type = "text";
                            source = "static";
                            text = 68;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { 1.86, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { 1.89, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { 1.86, 0.045000002 },
                                1
                            };
                        };
                    };
                    class value_2_group68 {
                        clipTL[] = { 0, 0 };
                        clipBR[] = { 0.477, 1 };
                        class value_268 {
                            type = "text";
                            source = "static";
                            text = 68;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { -5.3400002, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { -5.3099999, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { -5.3400002, 0.045000002 },
                                1
                            };
                        };
                    };
                    class value_3_group68 {
                        clipTL[] = { 0, 0 };
                        clipBR[] = { 0.477, 1 };
                        class value_368 {
                            type = "text";
                            source = "static";
                            text = 68;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { 1.86, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { 1.89, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { 1.86, 0.045000002 },
                                1
                            };
                        };
                    };
                    class value_4_group68 {
                        clipTL[] = { 0.523, 0 };
                        clipBR[] = { 1, 1 };
                        class value_468 {
                            type = "text";
                            source = "static";
                            text = 68;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { -5.3400002, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { -5.3099999, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { -5.3400002, 0.045000002 },
                                1
                            };
                        };
                    };
                    class box68 {
                        type = "line";
                        width = 2;
                        points[] = {

                            { "waypointIndicator",
                              { 1.883, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { 1.837, 0.041000001 },
                              1 },
                            {},

                            { "waypointIndicator",
                              { 1.86, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { 1.86, 0.052999999 },
                              1 },
                            {},

                            { "waypointIndicator",
                              { -5.3169999, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { -5.3629999, 0.041000001 },
                              1 },
                            {},

                            { "waypointIndicator",
                              { -5.3400002, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { -5.3400002, 0.052999999 },
                              1 }
                        };
                    };
                };
                class waypointIndicator279 {
                    class value_1_group279 {
                        clipTL[] = { 0.523, 0 };
                        clipBR[] = { 1, 1 };
                        class value_1279 {
                            type = "text";
                            source = "static";
                            text = 279;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { 6.0799999, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { 6.1100001, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { 6.0799999, 0.045000002 },
                                1
                            };
                        };
                    };
                    class value_2_group279 {
                        clipTL[] = { 0, 0 };
                        clipBR[] = { 0.477, 1 };
                        class value_2279 {
                            type = "text";
                            source = "static";
                            text = 279;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { -1.12, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { -1.09, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { -1.12, 0.045000002 },
                                1
                            };
                        };
                    };
                    class value_3_group279 {
                        clipTL[] = { 0, 0 };
                        clipBR[] = { 0.477, 1 };
                        class value_3279 {
                            type = "text";
                            source = "static";
                            text = 279;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { 6.0799999, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { 6.1100001, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { 6.0799999, 0.045000002 },
                                1
                            };
                        };
                    };
                    class value_4_group279 {
                        clipTL[] = { 0.523, 0 };
                        clipBR[] = { 1, 1 };
                        class value_4279 {
                            type = "text";
                            source = "static";
                            text = 279;
                            sourceScale = 1;
                            scale = 1;
                            align = "center";
                            pos[] = {
                                "waypointIndicator",
                                { -1.12, 0.0049999999 },
                                1
                            };
                            right[] = {
                                "waypointIndicator",
                                { -1.09, 0.0049999999 },
                                1
                            };
                            down[] = {
                                "waypointIndicator",
                                { -1.12, 0.045000002 },
                                1
                            };
                        };
                    };
                    class box279 {
                        type = "line";
                        width = 2;
                        points[] = {

                            { "waypointIndicator",
                              { 6.1030002, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { 6.0570002, 0.041000001 },
                              1 },
                            {},

                            { "waypointIndicator",
                              { 6.0799999, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { 6.0799999, 0.052999999 },
                              1 },
                            {},

                            { "waypointIndicator",
                              { -1.097, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { -1.143, 0.041000001 },
                              1 },
                            {},

                            { "waypointIndicator",
                              { -1.12, 0.041000001 },
                              1 },

                            { "waypointIndicator",
                              { -1.12, 0.052999999 },
                              1 }
                        };
                    };
                };
            };
        };
        class bankRot {
            class bankRotScale {
                type = "line";
                width = 2;
                points[] = {

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.259808, 0.208049 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.26846799, 0.214983 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.22294299, 0.27842301 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.23037501, 0.28770399 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.17633601, 0.33662999 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.18221299, 0.34785101 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.122021, 0.380124 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.12608799, 0.39279401 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.0623735, 0.407004 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { -0.064452603, 0.420571 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.0623735, 0.407004 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.064452603, 0.420571 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.122021, 0.380124 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.12608799, 0.39279401 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.17633601, 0.33662999 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.18221299, 0.34785101 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.22294299, 0.27842301 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.23037501, 0.28770399 },
                      1 },
                    {},

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.259808, 0.208049 },
                      1 },

                    { "ForwardVec",
                      1,
                      "planeW",
                      { 0.26846799, 0.214983 },
                      1 }
                };
            };
            class bankRotZero {
                type = "text";
                source = "static";
                text = "0";
                align = "center";
                scale = 1;
                sourceScale = 1;
                pos[] = {
                    "ForwardVec",
                    1,
                    "planeW",
                    { 0, 0.40000001 },
                    1
                };
                right[] = {
                    "ForwardVec",
                    1,
                    "planeW",
                    { 0.029999999, 0.40000001 },
                    1
                };
                down[] = {
                    "ForwardVec",
                    1,
                    "planeW",
                    { 0, 0.435 },
                    1
                };
            };
            class HorizonBankRot {
                type = "line";
                width = 2;
                points[] = {

                    { "HorizonBankRot",
                      { 0, -0.28999999 },
                      1,
                      "ForwardVec",
                      1 },

                    { "HorizonBankRot",
                      { 0.0099999998, -0.27268001 },
                      1,
                      "ForwardVec",
                      1 },

                    { "HorizonBankRot",
                      { -0.0099999998, -0.27268001 },
                      1,
                      "ForwardVec",
                      1 },

                    { "HorizonBankRot",
                      { 0, -0.28999999 },
                      1,
                      "ForwardVec",
                      1 }
                };
            };
        };
        class bottomIndicator {
            class stallIndicator {
                condition = "stall";
                blinkingPattern[] = { 0.2, 0.2 };
                blinkingStartsOn = 1;
                class stallText {
                    type = "text";
                    source = "static";
                    text = "STALL";
                    align = "center";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "bottomIndicator",
                        { 0, -0.15000001 },
                        1
                    };
                    right[] = {
                        "bottomIndicator",
                        { 0.037500001, -0.15000001 },
                        1
                    };
                    down[] = {
                        "bottomIndicator",

                        { 0,
                          "0.05 - 0.15" },
                        1
                    };
                };
            };
            class gearIndicator {
                condition = "ils";
                class gearText {
                    type = "text";
                    source = "static";
                    text = "GEAR";
                    align = "center";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "bottomIndicator",
                        { -0.1, 0 },
                        1
                    };
                    right[] = {
                        "bottomIndicator",
                        { -0.07, 0 },
                        1
                    };
                    down[] = {
                        "bottomIndicator",
                        { -0.1, 0.039999999 },
                        1
                    };
                };
                class airport {
                    type = "line";
                    width = 1.5;
                    points[] = {
                        { "airport1", 1 },
                        { "airport2", 1 },
                        { "airport4", 1 },
                        { "airport3", 1 },
                        { "airport1", 1 }
                    };
                };
            };

            class flapsIndicator {
                condition = "flaps";
                class flapsText {
                    type = "text";
                    source = "static";
                    text = "FLAPS";
                    align = "center";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "bottomIndicator",
                        { 0.1, 0 },
                        1
                    };
                    right[] = {
                        "bottomIndicator",
                        { 0.13, 0 },
                        1
                    };
                    down[] = {
                        "bottomIndicator",
                        { 0.1, 0.039999999 },
                        1
                    };
                };
            };
            class gunIndicator {
                condition = "mgun";
                class gunText {
                    type = "text";
                    source = "static";
                    text = "GUN";
                    align = "center";
                    scale = 1;
                    sourceScale = 1;
                    pos[] = {
                        "bottomIndicator",
                        { 0, 0 },
                        1
                    };
                    right[] = {
                        "bottomIndicator",
                        { 0.029999999, 0 },
                        1
                    };
                    down[] = {
                        "bottomIndicator",
                        { 0, 0.039999999 },
                        1
                    };
                };
            };
            class noGunIndicator {
                condition = "ils";
                class conditionGun {
                    condition = "mgun";
                    class noGunCross {
                        type = "line";
                        width = 2;
                        points[] = {

                            { "bottomIndicator",
                              { -0.029999999, 0.0099999998 },
                              1 },

                            { "bottomIndicator",
                              { 0.029999999, 0.035 },
                              1 },
                            {},

                            { "bottomIndicator",
                              { 0.029999999, 0.0099999998 },
                              1 },

                            { "bottomIndicator",
                              { -0.029999999, 0.035 },
                              1 }
                        };
                    };
                };
            };
        };
#include "mgun.hpp"
#include "weapons.hpp"
        class PlaneW_AA {
            condition = "AAmissile";
            class reticle {
                type = "line";
                width = 2;
                points[] = {
                    { "weaponAim", 1, "ForwardVec", { 0.168000, 0.000000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.167361, 0.018303 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.165448, 0.036466 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.162276, 0.054352 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.157868, 0.071824 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.152260, 0.088750 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.145492, 0.105000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.137618, 0.120451 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.128695, 0.134985 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.118794, 0.148492 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.107988, 0.160869 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.096361, 0.172022 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.084000, 0.181865 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.071000, 0.190325 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.057459, 0.197335 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.043482, 0.202844 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.029173, 0.206810 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.014642, 0.209201 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.000000, 0.210000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.014642, 0.209201 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.029173, 0.206810 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.043482, 0.202844 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.057459, 0.197335 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.071000, 0.190325 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.084000, 0.181865 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.096361, 0.172022 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.107988, 0.160869 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.118794, 0.148492 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.128695, 0.134985 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.137618, 0.120451 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.145492, 0.105000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.152260, 0.088750 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.157868, 0.071824 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.162276, 0.054352 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.165448, 0.036466 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.167361, 0.018303 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.168000, 0.000000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.167361, -0.018303 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.165448, -0.036466 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.162276, -0.054352 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.157868, -0.071824 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.152260, -0.088750 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.145492, -0.105000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.137618, -0.120451 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.128695, -0.134985 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.118794, -0.148492 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.107988, -0.160869 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.096361, -0.172022 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.084000, -0.181865 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.071000, -0.190325 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.057459, -0.197335 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.043482, -0.202844 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.029173, -0.206810 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.014642, -0.209201 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { -0.000000, -0.210000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.014642, -0.209201 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.029173, -0.206810 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.043482, -0.202844 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.057459, -0.197335 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.071000, -0.190325 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.084000, -0.181865 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.096361, -0.172022 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.107988, -0.160869 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.118794, -0.148492 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.128695, -0.134985 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.137618, -0.120451 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.145492, -0.105000 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.152260, -0.088750 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.157868, -0.071824 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.162276, -0.054352 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.165448, -0.036466 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.167361, -0.018303 }, 1 },
                    { "weaponAim", 1, "ForwardVec", { 0.168000, -0.000000 }, 1 }
                };
            };

            class TargetLocked {
                condition = "missilelocked";

                class shape {
                    type = "line";
                    width = 2;
                    points[] = {
                        { "Target", { 0, -0.04 }, 1 },
                        { "Target", { 0.025, 0.02 }, 1 },
                        { "Target", { -0.025, 0.02 }, 1 },
                        { "Target", { 0, -0.04 }, 1 }
                    };
                };
            };

            class TargetLocking {
                condition = "missilelocking";
                blinkingPattern[] = { 0.2, 0.2 };
                blinkingStartsOn = 1;
                class shape {
                    type = "line";
                    width = 2;
                    points[] = {
                        { "Target", { 0, -0.04 }, 1 },
                        { "Target", { 0.025, 0.02 }, 1 },
                        { "Target", { -0.025, 0.02 }, 1 },
                        { "Target", { 0, -0.04 }, 1 }
                    };
                };
            };

            class RadarTargets {
                type = "group";
                condition = "missilelocked<1";
                class RADAR {
                    type = "radar";
                    pos0[] = { 0.5, 0.5 };
                    pos10[] = { 0.71132398, 0.79310501 };
                    width = 2;
                    points[] = {
                        { "ForwardVec", { -0.02, -0.027739801 }, 1 },
                        { "ForwardVec", { 0.02, -0.027739801 }, 1 },
                        { "ForwardVec", { 0.02, 0.027739801 }, 1 },
                        { "ForwardVec", { -0.02, 0.027739801 }, 1 },
                        { "ForwardVec", { -0.02, -0.027739801 }, 1 }
                    };
                };
            };

            class RangeBand_AAM {
                type = "line";
                width = 3.0;
                points[] = {
                    { "DogfightTargetDist", { 0.00, 0.0 }, 1 },
                    { "DogfightTargetDist", { -0.010, -0.0129 }, 1 },
                    {},
                    { "DogfightTargetDist", { -0.010, 0.0129 }, 1 },
                    { "DogfightTargetDist", { 0.00, 0.0 }, 1 }
                };
            };
            class RangeText_AAM {
                type = "text";
                align = "left";
                scale = 1;
                source = "targetdist";
                sourcelength = 2;
                sourceScale = 0.01;
                pos[] = { "DogfightTargetDist", { "0.017-0.03", "-0.010-0.0129" }, 1 };
                right[] = { "DogfightTargetDist", { 0.017, "-0.010-0.0129" }, 1 };
                down[] = { "DogfightTargetDist", { "0.017-0.03", "0.035-0.0129" }, 1 };
            };
            class Range_marks_AAM {
                type = "line";
                width = 3.0;
                points[] = {
                    //range marks
                    { { "0.29+0.32+0.009+0.1", "0.40 - 0.28+0.27" }, 1 },  // line h
                    { { "0.31+0.32+0.002+0.1", "0.40 - 0.28+0.27" }, 1 },
                    {},
                    { { "0.29+0.32+0.009+0.1", "0.567 - 0.28+0.33" }, 1 },  // line h
                    { { "0.31+0.32+0.1", "0.567 - 0.28+0.33" }, 1 },
                    {},
                    { { "0.29+0.32+0.009+0.1", "0.40 - 0.28+0.27" }, 1 },  // line v
                    { { "0.29+0.32+0.009+0.1", "0.567 - 0.28+0.33" }, 1 },
                    {},
                    { { "0.29+0.32+0.009+0.1", "0.20684+0.3" }, 1 },  //lockarea horizontal
                    { { "0.31+0.32+0.1", "0.20684+0.3" }, 1 },
                    {},
                    { { "0.31+0.32+0.1", "0.20684+0.3" }, 1 },  //lockarea vertical
                    { { "0.31+0.32+0.1", "0.567 - 0.28+0.33" }, 1 }

                };
            };
            class Targetline_locked {
                condition = "targetDist>1";
                type = "group";
                class Cond {
                    type = "line";
                    width = 2;
                    points[] = {
                        { "PlaneW", 1, { 0.00000, 0.000000 }, 1 },
                        { "PlaneW", -1, "Target", 1, "NormalizeBombCircle", 1, "PlaneW", 1, { 0.000000, 0.000000 }, 1 }
                    };
                };
            };
        };
        class PlaneW_bomb {
            condition = "bomb";
            class reticle {
                type = "line";
                width = 2;
                points[] = {

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { -0.039999999, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { -0.016000001, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { -0.0080000004, 0.02 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0.0080000004, 0.02 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0.016000001, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0.039999999, 0 },
                      1 }
                };
            };

            class Crosshairs_BOMB {
                type = "line";
                width = 2;
                points[] = {
                    { "impactpoint", { 0.016000, 0.000000 }, 1 },
                    { "impactpoint", { 0.015757, 0.003473 }, 1 },
                    { "impactpoint", { 0.015035, 0.006840 }, 1 },
                    { "impactpoint", { 0.013856, 0.010000 }, 1 },
                    { "impactpoint", { 0.012257, 0.012856 }, 1 },
                    { "impactpoint", { 0.010285, 0.015321 }, 1 },
                    { "impactpoint", { 0.008000, 0.017321 }, 1 },
                    { "impactpoint", { 0.005472, 0.018794 }, 1 },
                    { "impactpoint", { 0.002778, 0.019696 }, 1 },
                    { "impactpoint", { 0.000000, 0.020000 }, 1 },
                    { "impactpoint", { -0.002778, 0.019696 }, 1 },
                    { "impactpoint", { -0.005472, 0.018794 }, 1 },
                    { "impactpoint", { -0.008000, 0.017321 }, 1 },
                    { "impactpoint", { -0.010285, 0.015321 }, 1 },
                    { "impactpoint", { -0.012257, 0.012856 }, 1 },
                    { "impactpoint", { -0.013856, 0.010000 }, 1 },
                    { "impactpoint", { -0.015035, 0.006840 }, 1 },
                    { "impactpoint", { -0.015757, 0.003473 }, 1 },
                    { "impactpoint", { -0.016000, 0.000000 }, 1 },
                    { "impactpoint", { -0.015757, -0.003473 }, 1 },
                    { "impactpoint", { -0.015035, -0.006840 }, 1 },
                    { "impactpoint", { -0.013856, -0.010000 }, 1 },
                    { "impactpoint", { -0.012257, -0.012856 }, 1 },
                    { "impactpoint", { -0.010285, -0.015321 }, 1 },
                    { "impactpoint", { -0.008000, -0.017321 }, 1 },
                    { "impactpoint", { -0.005472, -0.018794 }, 1 },
                    { "impactpoint", { -0.002778, -0.019696 }, 1 },
                    { "impactpoint", { -0.000000, -0.020000 }, 1 },
                    { "impactpoint", { 0.002778, -0.019696 }, 1 },
                    { "impactpoint", { 0.005472, -0.018794 }, 1 },
                    { "impactpoint", { 0.008000, -0.017321 }, 1 },
                    { "impactpoint", { 0.010285, -0.015321 }, 1 },
                    { "impactpoint", { 0.012257, -0.012856 }, 1 },
                    { "impactpoint", { 0.013856, -0.010000 }, 1 },
                    { "impactpoint", { 0.015035, -0.006840 }, 1 },
                    { "impactpoint", { 0.015757, -0.003473 }, 1 },
                    { "impactpoint", { 0.016000, -0.000000 }, 1 },
                    {},
                    {},
                    { "ImpactPoint", -1, "Velocity2", 1, "NormalizeBombCircleSmall", 1, "ImpactPoint", 1, { 0.000000, 0.000000 }, 1 },
                    { "Velocity2", 1, "Limit0109", 1, { 0.000000, 0.000000 }, 1 }
                };
            };

            class RadarTargets {
                type = "group";
                condition = "missilelocked<1";
                color[] = { 1, 0, 0, 0.1 };
                class RADAR {
                    type = "radar";
                    pos0[] = { 0.5, 0.5 };
                    pos10[] = { 0.71132398, 0.79310501 };
                    width = 2;
                    points[] = {
                        { "ForwardVec", { 0, -0.025 }, 1 },
                        { "ForwardVec", { -0.022, 0.025 }, 1 },
                        { "ForwardVec", { 0.022, 0.025 }, 1 },
                        { "ForwardVec", { 0, -0.025 }, 1 }
                    };
                };
            };

            class RangeBand_Bomb {
                type = "line";
                width = 3.0;
                points[] = {
                    { "BombTargetDist", { 0.00, 0.0 }, 1 },
                    { "BombTargetDist", { -0.01, -0.011 }, 1 },
                    {},
                    { "BombTargetDist", { -0.01, 0.011 }, 1 },
                    { "BombTargetDist", { 0.00, 0.0 }, 1 }
                };
            };
            /*class RangeText_AG
                    {
                        type="text";
                        align="left";
                        scale=1;
                        source="targetdist";
                        sourcelength=2;
                        sourceScale=0.01;
                        pos[]={"BombTargetDist",{"0.017-0.03","-0.010-0.0129"},1};
                        right[]={"BombTargetDist",{0.017,"-0.010-0.0129"},1};
                        down[]={"BombTargetDist",{"0.017-0.03","0.035-0.0129"},1};
                    };*/
            class Range_marks_Bomb {
                type = "line";
                width = 3.0;
                points[] = {
                    //range marks
                    { { "0.29+0.32+0.009-0.3", "0.40 - 0.28+0.27-0.2" }, 1 },  // line h
                    { { "0.31+0.32+0.002-0.3", "0.40 - 0.28+0.27-0.2" }, 1 },
                    {},
                    { { "0.29+0.32+0.009-0.3", "0.567 - 0.28+0.33-0.2" }, 1 },  // line h
                    { { "0.31+0.32-0.3", "0.567 - 0.28+0.33-0.2" }, 1 },
                    {},
                    { { "0.31+0.32-0.3", "0.40 - 0.28+0.27-0.2" }, 1 },  // line v
                    { { "0.31+0.32-0.3", "0.567 - 0.28+0.33-0.2" }, 1 },
                    {},
                    { { "0.29+0.32+0.009-0.3", "0.17025+0.3-0.2" }, 1 },  //lockarea horizontal
                    { { "0.31+0.32-0.3", "0.17025+0.3-0.2" }, 1 },
                    {},
                    { { "0.29+0.32+0.009-0.3", "0.17025+0.3-0.2" }, 1 },  //lockarea vertical
                    { { "0.29+0.32+0.009-0.3", "0.567 - 0.28+0.33-0.2" }, 1 }

                };
            };
        };
        class PlaneW_AT {
            condition = "ATmissile";
            class reticle {
                type = "line";
                width = 2;
                points[] = {

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { -0.039999999, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { -0.016000001, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { -0.0080000004, 0.02 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0.0080000004, 0.02 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0.016000001, 0 },
                      1 },

                    { "ForwardVec",
                      1,
                      "PlaneW",
                      1,
                      { 0.039999999, 0 },
                      1 }
                };
            };
            class TargetLocked {
                condition = "missilelocked";

                class shape {
                    type = "line";
                    width = 2;
                    points[] = {
                        { "Target", 1, "Limit0109", 1, { 0.022192, 0.000000 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.020854, 0.009488 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.017000, 0.017831 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.011096, 0.024024 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.003854, 0.027319 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.003854, 0.027319 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.011096, 0.024024 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.017000, 0.017831 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.020854, 0.009488 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.022192, 0.000000 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.020854, -0.009488 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.017000, -0.017831 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.011096, -0.024024 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.003854, -0.027319 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.003854, -0.027319 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.011096, -0.024024 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.017000, -0.017831 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.020854, -0.009488 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.022192, -0.000000 }, 1 },
                        {},
                        {},

                        { "Target", 1, "Limit0109", 1, { -0.02, -0.027739801 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.02, -0.027739801 }, 1 },
                        { "Target", 1, "Limit0109", 1, { 0.02, 0.027739801 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.02, 0.027739801 }, 1 },
                        { "Target", 1, "Limit0109", 1, { -0.02, -0.027739801 }, 1 }
                    };
                };
            };

            class RadarTargets {
                type = "group";
                condition = "missilelocked<1";

                class RADAR {
                    type = "radar";
                    pos0[] = { 0.5, 0.5 };
                    pos10[] = { 0.71132398, 0.79310501 };
                    width = 2;
                    points[] = {
                        { "ForwardVec", { 0, -0.025 }, 1 },
                        { "ForwardVec", { -0.022, 0.025 }, 1 },
                        { "ForwardVec", { 0.022, 0.025 }, 1 },
                        { "ForwardVec", { 0, -0.025 }, 1 }
                    };
                };
            };

            class RangeBand_AG {
                type = "line";
                width = 3.0;
                points[] = {
                    { "AGTargetDist", { 0.00, 0.0 }, 1 },
                    { "AGTargetDist", { -0.010, -0.0129 }, 1 },
                    {},
                    { "AGTargetDist", { -0.010, 0.0129 }, 1 },
                    { "AGTargetDist", { 0.00, 0.0 }, 1 }
                };
            };
            class RangeText_AG {
                type = "text";
                align = "left";
                scale = 1;
                source = "targetdist";
                sourcelength = 2;
                sourceScale = 0.01;
                pos[] = { "AGTargetDist", { "0.017-0.03", "-0.010-0.0129" }, 1 };
                right[] = { "AGTargetDist", { 0.017, "-0.010-0.0129" }, 1 };
                down[] = { "AGTargetDist", { "0.017-0.03", "0.035-0.0129" }, 1 };
            };
            class Range_marks_AG {
                type = "line";
                width = 3.0;
                points[] = {
                    //range marks
                    //{ { "0.29+0.32+0.009+0.04","0.40 - 0.28+0.27" },1 },// line h
                    //{ { "0.47+0.32+0.04","0.40 - 0.28+0.27" },1 },
                    //{},
                    { { "0.31+0.32+0.04", "0.567 - 0.28+0.33" }, 1 },  // line h
                    { { "0.332+0.32+0.04", "0.567 - 0.28+0.33" }, 1 },
                    {},
                    { { "0.321+0.32+0.04", "0.40 - 0.28+0.27" }, 1 },  // line v
                    { { "0.321+0.32+0.04", "0.567 - 0.28+0.33+0.02" }, 1 },
                    {},
                    { { "0.31+0.32+0.04", "0.20684+0.3" }, 1 },  //lockarea horizontal
                    { { "0.332+0.32+0.04", "0.20684+0.3" }, 1 },
                    {},
                    { { "0.31+0.32+0.04", "0.20684+0.3" }, 1 },  //lockarea vertical
                    { { "0.31+0.32+0.04", "0.567 - 0.28+0.33" }, 1 },
                    {},
                    { { "0.332+0.32+0.04", "0.20684+0.3" }, 1 },  //lockarea vertical
                    { { "0.332+0.32+0.04", "0.567 - 0.28+0.33" }, 1 },
                    {},
                    { { "0.31+0.32+0.04-0.008", "0.567 - 0.28+0.33+0.02" }, 1 },  //lockarea Horizon_bottom
                    { { "0.332+0.32+0.04+0.008", "0.567 - 0.28+0.33+0.02" }, 1 }

                };
            };
            class Range_marks_AG_Inner {
                type = "line";
                width = 0.8;
                points[] = {
                    { { "0.321+0.32+0.04", "0.15" }, 1 },  // line v
                    { { "0.321+0.32+0.04", "0.40 - 0.28+0.27" }, 1 }
                };
            };
        };
        class RadarBoxes {
            type = "radartoview";
            pos0[] = { 0.5, 0.5 };
            pos10[] = { 0.773, 0.773 };
            width = 4;
            points[] = { { { -0.002, -0.002 }, 1 }, { { 0.002, -0.002 }, 1 }, { { 0.002, 0.002 }, 1 }, { { -0.002, 0.002 }, 1 }, { { -0.002, -0.002 }, 1 } };
        };
    };
};
