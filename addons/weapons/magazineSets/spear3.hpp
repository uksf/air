class rksla3_mag_spear3_directx1 : VehicleMagazine {
    displayName = "SPEAR 3 x1";
    pylonWeapon = "rksla3_wpn_spear3";
    hardpoints[] += { QGVAR(spear3_pylon) };
};
class rksla3_mag_spear3_bru61_x4 : rksla3_mag_spear3_directx1 {
    displayName = "SPEAR 3 x4";
    pylonWeapon = "rksla3_wpn_spear3";
    hardpoints[] += { QGVAR(spear3_pylon_quad) };
};
