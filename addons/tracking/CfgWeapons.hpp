class CfgWeapons {
    class B_UavTerminal;
    class GVAR(terminal): B_UavTerminal {
        displayName = "AWACS Terminal";
    };

    class uksf_air_atc_terminal: GVAR(terminal) {
        scope = 1;
    };
};
