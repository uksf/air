class rksla3_mag_brimstone_3_sglrail_x1;
class rksla3_mag_brimstone_3_x3 : rksla3_mag_brimstone_3_sglrail_x1 {
    displayName = "Brimstone III x3";
    pylonWeapon = "rksla3_wpn_brimstone_3";
    hardpoints[] += { QGVAR(brimstone3_pylon) };
};

delete GX_RKSL_BRIMSTONE_DM_X2;
delete rksla3_mag_brimstone_dm_x3;
