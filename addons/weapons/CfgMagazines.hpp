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
    class magazine_Bomb_GBU12_x1;
    class PylonMissile_Bomb_GBU12_x1 : magazine_Bomb_GBU12_x1 {
        hardpoints[] += { "B_GBU12_Only" };
    };
    class PylonRack_Bomb_GBU12_x2: magazine_Bomb_GBU12_x1 {
        hardpoints[] += { "B_GBU12_DUAL_RAIL_Only" };
    };

    // Hellfire K
    class 12Rnd_PG_missiles;
    class 6Rnd_ACE_Hellfire_AGM114K : 12Rnd_PG_missiles {
        displayName = "AGM-114K";
    };
    class 4Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K";
        count = 4;
    };
    class 4Rnd_ACE_Hellfire_AGM114K_drone : 4Rnd_ACE_Hellfire_AGM114K {
        ammo = "ACE_Hellfire_AGM114K_drone";
    };
    class 2Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114K";
        count = 2;
    };
    class PylonMissile_1Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "1x AGM-114K";
        hardpoints[] = { "SCALPEL_1RND" };
    };
    class PylonRack_1Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "1x AGM-114K";
        hardpoints[] = { "B_MISSILE_PYLON", "SCALPEL_1RND_EJECTOR", "B_ASRRAM_EJECTOR", "UNI_SCALPEL" };
    };
    class PylonRack_3Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "3x AGM-114K";
        hardpoints[] = { "B_MISSILE_PYLON", "UNI_SCALPEL" };
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114K : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "4x AGM-114K";
        hardpoints[] = { "UNI_SCALPEL", "B_HELLFIRE" };
    };
    class PylonRack_2Rnd_ACE_Hellfire_AGM114K_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "2x AGM-114K";
        ammo = "ACE_Hellfire_AGM114K_drone";
        model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
        count = 2;
        mass = 170;
        pylonWeapon = "ace_hellfire_launcher_drone";
        hardpoints[] = { "B_HELLFIRE_DRONE" };
    };

    // Hellfire N
    class 6Rnd_ACE_Hellfire_AGM114N : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114N";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
    };
    class 2Rnd_ACE_Hellfire_AGM114N : 6Rnd_ACE_Hellfire_AGM114N {
        count = 2;
    };
    class 4Rnd_ACE_Hellfire_AGM114N : 6Rnd_ACE_Hellfire_AGM114N {
        count = 4;
    };
    class 4Rnd_ACE_Hellfire_AGM114N_drone : 4Rnd_ACE_Hellfire_AGM114N {
        ammo = "ACE_Hellfire_AGM114N_drone";
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114N : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "4x AGM-114N";
        displayNameShort = "AGM-114N";
        descriptionShort = "AGM-114N";
        pylonWeapon = "ace_hellfire_launcher_N";
    };
    class PylonRack_2Rnd_ACE_Hellfire_AGM114N_Drone : PylonRack_4Rnd_ACE_Hellfire_AGM114N {
        displayName = "2x AGM-114N";
        ammo = "ACE_Hellfire_AGM114N_drone";
        model = "\CUP\Weapons\CUP_Weapons_DynamicLoadout\AGM114\CUP_AGM114_dual_drone.p3d";
        count = 2;
        mass = 170;
        pylonWeapon = "ace_hellfire_launcher_drone_N";
        hardpoints[] = { "B_HELLFIRE_DRONE" };
    };

    // Hellfire L
    class 6Rnd_ACE_Hellfire_AGM114L : 6Rnd_ACE_Hellfire_AGM114K {
        displayName = "AGM-114L";
    };
    class 2Rnd_ACE_Hellfire_AGM114L : 6Rnd_ACE_Hellfire_AGM114L {
        count = 2;
    };
    class 4Rnd_ACE_Hellfire_AGM114L : 6Rnd_ACE_Hellfire_AGM114L {
        count = 4;
    };
    class PylonRack_4Rnd_ACE_Hellfire_AGM114L : PylonRack_4Rnd_ACE_Hellfire_AGM114K {
        displayName = "4x AGM-114L";
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
