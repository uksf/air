class rksla3_mag_meteor_directx1 : VehicleMagazine {
    displayName = "Meteor x1";
    pylonWeapon = "rksla3_wpn_meteor";
    hardpoints[] += { QGVAR(meteor_pylon_INT) };
};
class rksla3_mag_meteor_lau127x1 : rksla3_mag_meteor_directx1 {
    displayName = "Meteor x1";
    hardpoints[] += { QGVAR(meteor_pylon) };
};
