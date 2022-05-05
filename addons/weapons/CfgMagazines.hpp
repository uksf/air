class CfgMagazines {
    class VehicleMagazine;
    class GVAR(gunpod_magazine) : VehicleMagazine {
        scope = 1;
        displayName = "GAU-22/A";
        displayNameShort = "GAU-22/A";
        descriptionShort = "25mm External Gun Pod\n  Capacity: 220 rounds";
        ammo = QGVAR(gunpod_25mm_apex);
        count = 220;
        initSpeed = 1036;
        tracersEvery = 1;
        mass = 104;
        nameSound = "cannon";
    };
    class GVAR(gunpod_pylon) : GVAR(gunpod_magazine) {
        muzzlePos = "muzzle_start";
        muzzleEnd = "muzzle_end";
        model = QPATHTOF(data\uksf_air_weapons_gunpod.p3d);
        pylonWeapon = QGVAR(gunpod);
        hardpoints[] = { QGVAR(gunpod) };
    };
    class PylonMissile_Bomb_GBU12_x1;
    class ace_gbu_PylonMissile_Bomb_GBU12_x1 : PylonMissile_Bomb_GBU12_x1 {
        displayName = "GBU-12 x1";
        hardpoints[] += { "B_GBU12_ACE_Only" };
    };
    class PylonRack_Bomb_GBU12_x2;
    class ace_gbu_PylonRack_Bomb_GBU12_x2 : PylonRack_Bomb_GBU12_x2 {
        displayName = "GBU-12 x2";
        hardpoints[] += { "B_GBU12_DUAL_RAIL_ACE_Only" };
    };
    class PylonRack_Bomb_SDB_x4;
    class ace_sdb_PylonRack_bomb_SDB_x4 : PylonRack_Bomb_SDB_x4 {
        displayName = "GBU-39 x4";
        hardpoints[] += { "B_GBU39_ACE_Only" };
    };
    class ace_aim9_PylonRack_1Rnd_aim132;
    class ace_aim9_PylonRack_aim132_x1: ace_aim9_PylonRack_1Rnd_aim132 {
        displayName = "AIM-132 x1";
        model = "\A3\Weapons_F_Jets\Ammo\PylonPod_Missile_AA_08_Rail_x1_F";
        hardpoints[] += { "B_AIM132_RAIL_ACE_Only" };
    };
    class ace_aim9_PylonRack_aim132_x2: ace_aim9_PylonRack_aim132_x1 {
        displayName = "AIM-132 x2";
        count = 2;
        model = "\A3\Weapons_F_Jets\Ammo\PylonPod_Missile_AA_08_DualRail_x2_F";
        hardpoints[] = { "B_AIM132_DUAL_RAIL_ACE_Only" };
        mass = 250;
    };
    class PylonRack_Missile_AMRAAM_D_x1;
    class ace_aim120_PylonRack_Missile_d_x1 : PylonRack_Missile_AMRAAM_D_x1 {
        displayName = "AIM-120D x1";
        hardpoints[] += { "B_AMRAAM_D_RAIL_ACE_Only" };
    };
    class PylonRack_Missile_AMRAAM_D_x2;
    class ace_aim120_PylonRack_Missile_d_x2: PylonRack_Missile_AMRAAM_D_x2 {
        displayName = "AIM-120D x2";
        hardpoints[] += { "B_AMRAAM_D_DUAL_RAIL_ACE_Only" };
    };
    class PylonMissile_Missile_AMRAAM_D_INT_x1;
    class ace_aim120_PylonMissile_Missile_d_INT_x1 : PylonMissile_Missile_AMRAAM_D_INT_x1 {
        displayName = "AIM-120D x1";
        hardpoints[] += { "B_AMRAAM_D_INT_ACE_Only" };
    };

    // Hellfire K
    class 6Rnd_ACE_Hellfire_AGM114K;
    class PylonMissile_1Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K x1";
        // hardpoints[] = { "SCALPEL_1RND" };
    };
    class PylonRack_1Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K x1";
        // hardpoints[] = { "B_MISSILE_PYLON", "SCALPEL_1RND_EJECTOR", "B_ASRRAM_EJECTOR", "UNI_SCALPEL" };
    };
    class PylonRack_3Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K x3";
        // hardpoints[] = { "B_MISSILE_PYLON", "UNI_SCALPEL" };
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K x4";
        hardpoints[] += { "B_HELLFIRE" };
    };
    class PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K x2";
        ammo = "ACE_Hellfire_AGM114K_drone";
        model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
        count = 2;
        mass = 170;
        pylonWeapon = "ace_hellfire_launcher_drone";
        hardpoints[] = { "B_HELLFIRE_DRONE" };
    };

    // Hellfire N
    class PylonRack_4Rnd_ACE_Hellfire_AGM114N : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114N x4";
    };
    class PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114N {
        displayName = "AGM-114N x2";
        ammo = "ACE_Hellfire_AGM114N_drone";
        model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
        count = 2;
        mass = 170;
        pylonWeapon = "ace_hellfire_launcher_drone_N";
        hardpoints[] = { "B_HELLFIRE_DRONE" };
    };

    // Hellfire L
    class PylonRack_4Rnd_ACE_Hellfire_AGM114L : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114L x4";
    };

    class CUP_14Rnd_FFAR_M;
    class CUP_12Rnd_CRV7_FAT_M : CUP_14Rnd_FFAR_M {
        initSpeed = 900;
    };
    class CUP_19Rnd_CRV7_FAT_M;
    class CUP_PylonPod_19Rnd_CRV7_FAT_M : CUP_19Rnd_CRV7_FAT_M {
        hardpoints[] += { "B_CRV7" };
        model = QPATHTOEF(apache,PylonRocket_19Rnd_CRV7_HEISAP.p3d);
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };
    class CUP_PylonPod_12Rnd_CRV7_FAT_M : CUP_19Rnd_CRV7_FAT_M {
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };
    class CUP_PylonPod_19Rnd_CRV7_HE_M : CUP_PylonPod_19Rnd_CRV7_FAT_M {
        hardpoints[] += { "B_CRV7" };
        model = QPATHTOEF(apache,PylonRocket_19Rnd_CRV7_HEISAP.p3d);
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };
    class CUP_PylonPod_12Rnd_CRV7_HE_M : CUP_PylonPod_12Rnd_CRV7_FAT_M {
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };
    class UK3CB_BAF_12Rnd_CRV7_Base_PG : VehicleMagazine {
        initSpeed = 900;
    };
    class CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M;
    class CUP_PylonPod_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M : CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M {
        CUP_PilotControl = 0;
        GVAR(pilotControl) = 1;
    };
};
