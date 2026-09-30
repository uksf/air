// Pylon N draws at the model's pylon proxy N. Numbered right to left: outer rail, three underwing
// stations, rear and front semi-conformal, centreline, then the mirror image.
#define AAM_RAIL "B_AIM132_RAIL_ACE_Only", "B_AMRAAM_D_RAIL_ACE_Only"
#define AAM_WING AAM_RAIL, "B_AIM132_DUAL_RAIL_ACE_Only", "B_AMRAAM_D_DUAL_RAIL_ACE_Only", QEGVAR(weapons,meteor_pylon)
#define AG_LIGHT "B_GBU12_ACE_Only", "B_GBU12_DUAL_RAIL_ACE_Only", QEGVAR(weapons,brimstone3_pylon), QEGVAR(weapons,spear3_pylon), QEGVAR(weapons,spear3_pylon_quad)
#define AG_HEAVY AG_LIGHT, "B_GBU12_TRIPLE_RAIL_ACE_Only", QEGVAR(weapons,stormshadow_pylon)

#define ASRAAM "ace_missile_aim9_PylonRack_aim132_x1"
#define METEOR "rksla3_mag_meteor_directx1"
#define METEOR_RAIL "rksla3_mag_meteor_lau127x1"
#define SPEAR_X4 "rksla3_mag_spear3_bru61_x4"
#define GBU12_X2 "ace_missile_gbu_PylonRack_Bomb_GBU12_x2"

class TransportPylonsComponent {
    uiPicture = QPATHTOF(data\ui\loadout_ca.paa);
    // Meteor is the air-to-air missile; SPEAR 3 and Paveway (GBU-12) are the default air-to-ground stores.
    class presets {
        class Empty {
            displayName = "Empty";
            attachment[] = { "", "", "", "", "", "", "", "", "", "", "", "", "" };
        };
        class Default {
            displayName = "Multi-Role";
            attachment[] = {
                ASRAAM, METEOR_RAIL, SPEAR_X4, GBU12_X2,
                METEOR, METEOR, "", METEOR, METEOR,
                GBU12_X2, SPEAR_X4, METEOR_RAIL, ASRAAM
            };
        };
        class CAP {
            displayName = "CAP";
            attachment[] = {
                ASRAAM, METEOR_RAIL, METEOR_RAIL, "",
                METEOR, METEOR, "", METEOR, METEOR,
                "", METEOR_RAIL, METEOR_RAIL, ASRAAM
            };
        };
        class CAS {
            displayName = "CAS";
            attachment[] = {
                ASRAAM, METEOR_RAIL, SPEAR_X4, GBU12_X2,
                METEOR, METEOR, SPEAR_X4, METEOR, METEOR,
                GBU12_X2, SPEAR_X4, METEOR_RAIL, ASRAAM
            };
        };
        class Strike {
            displayName = "Strike";
            attachment[] = {
                ASRAAM, METEOR_RAIL, GBU12_X2, "rksla3_mag_stormshadow_directx1",
                METEOR, METEOR, "", METEOR, METEOR,
                "rksla3_mag_stormshadow_directx1", GBU12_X2, METEOR_RAIL, ASRAAM
            };
        };
    };
    class pylons {
        class pylons1 {
            // right outer rail
            UIposition[] = { 0.47, 0.038 };
            hardpoints[] = { AAM_RAIL };
            attachment = "ace_missile_aim9_PylonRack_aim132_x1";
            maxweight = 300;
            priority = 5;
        };
        class pylons2 : pylons1 {
            // right outboard
            UIposition[] = { 0.443, 0.071 };
            hardpoints[] = { AAM_WING, AG_LIGHT };
            attachment = "rksla3_mag_meteor_lau127x1";
            maxweight = 1000;
            priority = 4;
        };
        class pylons3 : pylons2 {
            // right mid
            UIposition[] = { 0.398, 0.122 };
            hardpoints[] = { AAM_WING, AG_HEAVY };
            attachment = SPEAR_X4;
            maxweight = 2500;
            priority = 3;
        };
        class pylons4 : pylons3 {
            // right inboard
            UIposition[] = { 0.343, 0.16 };
            attachment = GBU12_X2;
            maxweight = 5000;
            priority = 2;
        };
        class pylons5 {
            // right rear semi-conformal
            UIposition[] = { 0.498, 0.199 };
            hardpoints[] = { "B_AMRAAM_D_INT_ACE_Only", QEGVAR(weapons,meteor_pylon_INT) };
            attachment = "rksla3_mag_meteor_directx1";
            maxweight = 350;
            priority = 1;
        };
        class pylons6 : pylons5 {
            // right front semi-conformal
            UIposition[] = { 0.345, 0.222 };
        };
        class pylons7 {
            // centreline
            UIposition[] = { 0.421, 0.25 };
            hardpoints[] = { "B_GBU12_ACE_Only", QEGVAR(weapons,spear3_pylon_quad) };
            attachment = "";
            maxweight = 1000;
            priority = 1;
        };
        class pylons8 : pylons6 {
            // left front semi-conformal
            UIposition[] = { 0.344, 0.278 };
            mirroredMissilePos = 6;
        };
        class pylons9 : pylons5 {
            // left rear semi-conformal
            UIposition[] = { 0.498, 0.301 };
            mirroredMissilePos = 5;
        };
        class pylons10 : pylons4 {
            // left inboard
            UIposition[] = { 0.343, 0.34 };
            mirroredMissilePos = 4;
        };
        class pylons11 : pylons3 {
            // left mid
            UIposition[] = { 0.398, 0.379 };
            mirroredMissilePos = 3;
        };
        class pylons12 : pylons2 {
            // left outboard
            UIposition[] = { 0.443, 0.429 };
            mirroredMissilePos = 2;
        };
        class pylons13 : pylons1 {
            // left outer rail
            UIposition[] = { 0.47, 0.462 };
            mirroredMissilePos = 1;
        };
    };
};
