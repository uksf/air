// Pylon N draws at the model's pylon proxy N. Numbered left to right: outer rail, three underwing
// stations, rear-left and front-left semi-conformal, centreline, then the mirror image.
#define AAM_RAIL "B_AIM132_RAIL_ACE_Only", "B_AMRAAM_D_RAIL_ACE_Only"
#define AAM_WING AAM_RAIL, "B_AIM132_DUAL_RAIL_ACE_Only", "B_AMRAAM_D_DUAL_RAIL_ACE_Only", QEGVAR(weapons,meteor_pylon)
#define AG_LIGHT "B_GBU12_ACE_Only", "B_GBU12_DUAL_RAIL_ACE_Only", QEGVAR(weapons,brimstone3_pylon), QEGVAR(weapons,spear3_pylon), QEGVAR(weapons,spear3_pylon_quad)
#define AG_HEAVY AG_LIGHT, "B_GBU12_TRIPLE_RAIL_ACE_Only", QEGVAR(weapons,stormshadow_pylon)

class TransportPylonsComponent {
    uiPicture = "\A3\Air_F_Gamma\Plane_Fighter_03\Data\UI\Plane_A143_3DEN_CA.paa";
    class presets {
        class Empty {
            displayName = "Empty";
            attachment[] = { "", "", "", "", "", "", "", "", "", "", "", "", "" };
        };
        class Default {
            displayName = "Multi-Role";
            attachment[] = {
                "ace_missile_aim9_PylonRack_aim132_x1", "rksla3_mag_meteor_lau127x1", "ace_missile_gbu_PylonRack_Bomb_GBU12_x2", "ace_missile_gbu_PylonRack_Bomb_GBU12_x2",
                "rksla3_mag_meteor_directx1", "rksla3_mag_meteor_directx1", "", "rksla3_mag_meteor_directx1", "rksla3_mag_meteor_directx1",
                "ace_missile_gbu_PylonRack_Bomb_GBU12_x2", "ace_missile_gbu_PylonRack_Bomb_GBU12_x2", "rksla3_mag_meteor_lau127x1", "ace_missile_aim9_PylonRack_aim132_x1"
            };
        };
        class CAP {
            displayName = "CAP";
            attachment[] = {
                "ace_missile_aim9_PylonRack_aim132_x1", "ace_missile_aim120_PylonRack_Missile_d_x1", "rksla3_mag_meteor_lau127x1", "",
                "rksla3_mag_meteor_directx1", "rksla3_mag_meteor_directx1", "", "rksla3_mag_meteor_directx1", "rksla3_mag_meteor_directx1",
                "", "rksla3_mag_meteor_lau127x1", "ace_missile_aim120_PylonRack_Missile_d_x1", "ace_missile_aim9_PylonRack_aim132_x1"
            };
        };
        class CAS {
            displayName = "CAS";
            attachment[] = {
                "ace_missile_aim9_PylonRack_aim132_x1", "rksla3_mag_brimstone_3_x3", "ace_missile_gbu_PylonRack_Bomb_GBU12_x2", "rksla3_mag_spear3_bru61_x4",
                "rksla3_mag_meteor_directx1", "ace_missile_aim120_PylonMissile_Missile_d_INT_x1", "", "ace_missile_aim120_PylonMissile_Missile_d_INT_x1", "rksla3_mag_meteor_directx1",
                "rksla3_mag_spear3_bru61_x4", "ace_missile_gbu_PylonRack_Bomb_GBU12_x2", "rksla3_mag_brimstone_3_x3", "ace_missile_aim9_PylonRack_aim132_x1"
            };
        };
        class Strike {
            displayName = "Strike";
            attachment[] = {
                "ace_missile_aim9_PylonRack_aim132_x1", "rksla3_mag_meteor_lau127x1", "", "rksla3_mag_stormshadow_directx1",
                "rksla3_mag_meteor_directx1", "rksla3_mag_meteor_directx1", "", "rksla3_mag_meteor_directx1", "rksla3_mag_meteor_directx1",
                "rksla3_mag_stormshadow_directx1", "", "rksla3_mag_meteor_lau127x1", "ace_missile_aim9_PylonRack_aim132_x1"
            };
        };
    };
    class pylons {
        class pylons1 {
            // left outer rail
            UIposition[] = { 0.06, 0.42 };
            hardpoints[] = { AAM_RAIL };
            attachment = "ace_missile_aim9_PylonRack_aim132_x1";
            maxweight = 300;
            priority = 5;
        };
        class pylons2 : pylons1 {
            // left outboard
            UIposition[] = { 0.11, 0.36 };
            hardpoints[] = { AAM_WING, AG_LIGHT };
            attachment = "rksla3_mag_meteor_lau127x1";
            maxweight = 1000;
            priority = 4;
        };
        class pylons3 : pylons2 {
            // left mid
            UIposition[] = { 0.17, 0.3 };
            hardpoints[] = { AAM_WING, AG_HEAVY };
            attachment = "ace_missile_gbu_PylonRack_Bomb_GBU12_x2";
            maxweight = 2500;
            priority = 3;
        };
        class pylons4 : pylons3 {
            // left inboard
            UIposition[] = { 0.23, 0.24 };
            maxweight = 5000;
            priority = 2;
        };
        class pylons5 {
            // left rear semi-conformal
            UIposition[] = { 0.29, 0.4 };
            hardpoints[] = { "B_AMRAAM_D_INT_ACE_Only", QEGVAR(weapons,meteor_pylon_INT) };
            attachment = "rksla3_mag_meteor_directx1";
            maxweight = 350;
            priority = 1;
        };
        class pylons6 : pylons5 {
            // left front semi-conformal
            UIposition[] = { 0.29, 0.18 };
        };
        class pylons7 {
            // centreline
            UIposition[] = { 0.33, 0.3 };
            hardpoints[] = { "B_GBU12_ACE_Only", QEGVAR(weapons,spear3_pylon_quad) };
            attachment = "";
            maxweight = 1000;
            priority = 1;
        };
        class pylons8 : pylons6 {
            // right front semi-conformal
            UIposition[] = { 0.37, 0.18 };
            mirroredMissilePos = 6;
        };
        class pylons9 : pylons5 {
            // right rear semi-conformal
            UIposition[] = { 0.37, 0.4 };
            mirroredMissilePos = 5;
        };
        class pylons10 : pylons4 {
            // right inboard
            UIposition[] = { 0.43, 0.24 };
            mirroredMissilePos = 4;
        };
        class pylons11 : pylons3 {
            // right mid
            UIposition[] = { 0.49, 0.3 };
            mirroredMissilePos = 3;
        };
        class pylons12 : pylons2 {
            // right outboard
            UIposition[] = { 0.55, 0.36 };
            mirroredMissilePos = 2;
        };
        class pylons13 : pylons1 {
            // right outer rail
            UIposition[] = { 0.6, 0.42 };
            mirroredMissilePos = 1;
        };
    };
};
