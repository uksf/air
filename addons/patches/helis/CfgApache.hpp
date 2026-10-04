HIDE_CLASS_WITH_BASE(CUP_B_AH1_NO_BAF,CUP_B_AH64D_NO_USA);
HIDE_CLASS_WITH_BASE(CUP_B_AH1_AT_BAF,CUP_B_AH64D_AT_USA);
HIDE_CLASS_WITH_BASE(CUP_B_AH1_ES_BAF,CUP_B_AH64D_ES_USA);
HIDE_CLASS_WITH_BASE(CUP_B_AH1_BAF,CUP_B_AH64D_USA);
HIDE_CLASS_WITH_BASE(CUP_B_AH1_MR_BAF,CUP_B_AH64D_MR_USA);
HIDE_CLASS_WITH_BASE(CUP_B_AH1_DL_BAF,CUP_B_AH64D_DL_USA);

// CUP gives every pylon bay = 1, but the AH-64 has no Bays, so the engine cannot init them.
class CUP_AH64_base;
class CUP_AH64D_Base : CUP_AH64_base {
    class Components;
};
class CUP_AH64D_dynamic_base : CUP_AH64D_Base {
    class Components : Components {
        class TransportPylonsComponent {
            class pylons {
                class pylonLeft1 {
                    bay = -1;
                };
            };
        };
    };
};
