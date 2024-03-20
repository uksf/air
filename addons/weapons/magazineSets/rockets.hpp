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
class UK3CB_BAF_12Rnd_CRV7_Base_PG : VehicleMagazine {
    initSpeed = 900;
};
