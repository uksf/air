class CUP_AV8B_Base : Plane {
    ace_refuel_fuelCapacity = 4318; // AV-8B Harrier II real internal: 2746 L wings + 4 fuselage tanks ~= 4318 L
};

HIDE_CLASS_WITH_BASE(CUP_B_GR9_DYN_GB,CUP_GR9_DYN_Base);
HIDE_CLASS(CUP_B_GR9_CAP_GB,CUP_AV8B_Base);
HIDE_CLASS(CUP_B_GR9_Mk82_GB,CUP_AV8B_Base);
HIDE_CLASS(CUP_B_GR9_GBU12_GB,CUP_AV8B_Base);
HIDE_CLASS(CUP_B_GR9_AGM_GB,CUP_AV8B_Base);
