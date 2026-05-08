class UK3CB_BAF_M_CRV7_Base_PG : UK3CB_BAF_M_CRV7_Base {
    class ace_missileguidance : ace_missileguidance_type_Dagr {
        enabled = 1;
        pitchRate = 12;
        yawRate = 12;
        seekerMaxRange = 5000;
        seekerAngle = 40;
    };
};

class UK3CB_BAF_M_CRV7_PG_HEISAP : UK3CB_BAF_M_CRV7_Base_PG {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
    };
};

class UK3CB_BAF_M_CRV7_PG_FAT : UK3CB_BAF_M_CRV7_Base_PG {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
    };
};

class UK3CB_BAF_M_CRV7_PG_GPF : UK3CB_BAF_M_CRV7_Base_PG {
    class ace_missileguidance : ace_missileguidance {
        enabled = 1;
    };
};
