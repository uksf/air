class CfgWeapons {
    class B_UavTerminal;
    class GVAR(terminal): B_UavTerminal {
        displayName = "ATC Terminal";
    };

    class UGVAR(atc,terminal): GVAR(terminal) {
        scope = 1;
    };
    // DEPRECATE_CLASS(UGVAR(atc,terminal),GVAR(terminal));
};
