class CUP_L39_base : Plane_Base_F {
    ace_refuel_fuelCapacity = 1255; // L-39 Albatros real internal: 1055 L main + 200 L wingtips = 1255 L
};
class CUP_L39_DYN_Base;
class CUP_B_L39_CZ : CUP_L39_DYN_Base {
    class Components;
};
class UKSF_B_L39 : CUP_B_L39_CZ {
    scope = 1;
    scopeCurator = 0;
};
class UKSF_B_L39_Unarmed : UKSF_B_L39 {
    scope = 1;
    scopeCurator = 0;
};
