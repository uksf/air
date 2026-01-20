class CUP_12Rnd_CRV7_FAT_M : CUP_14Rnd_FFAR_M {
    initSpeed = 900;
};
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
class UK3CB_BAF_PylonPod_19Rnd_CRV7_PG_HEISAP : UK3CB_BAF_PylonPod_19Rnd_CRV7_PG_Base {
    hardpoints[] = { "B_CRV7" };
    initSpeed = 900;
    CUP_PilotControl = 0;
    GVAR(pilotControl) = 1;
};
class UK3CB_BAF_PylonPod_19Rnd_CRV7_PG_FAT : UK3CB_BAF_PylonPod_19Rnd_CRV7_PG_HEISAP {
    CUP_PilotControl = 0;
    GVAR(pilotControl) = 1;
    pylonWeapon = "UK3CB_BAF_Missiles_CRV7_PG_FAT";
};
class UK3CB_BAF_PylonPod_19Rnd_CRV7_PG_GPF : UK3CB_BAF_PylonPod_19Rnd_CRV7_PG_HEISAP {
    CUP_PilotControl = 0;
    GVAR(pilotControl) = 1;
    pylonWeapon = "UK3CB_BAF_Missiles_CRV7_PG_GPF";
};
