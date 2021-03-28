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
};
