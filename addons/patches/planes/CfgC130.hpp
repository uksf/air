class CUP_C130J_Base : Plane_Base_F {
    ace_refuel_fuelCapacity = 25553; // C-130J real internal: 6755 US gal / ~25,553 L
};

DEPRECATE_CLASS_WITH_BASE(CUP_B_C130J_GB,EGVAR(c130,raf));
DEPRECATE_CLASS_WITH_BASE(CUP_B_C130J_Cargo_GB,EGVAR(c130,raf_cargo));
