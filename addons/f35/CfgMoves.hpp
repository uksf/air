class CfgMovesBasic {
    class DefaultDie;
    class ManActions {
        GVAR(pilot) = QGVAR(pilot);
        GVAR(pilot_enter) = QGVAR(pilot_getin);
        GVAR(pilot_exit) = QGVAR(pilot_getout);
    };
};
class CfgMovesMaleSdr : CfgMovesBasic {
    class States {
        class pilot_plane_cas_01;
        class GVAR(pilot) : pilot_plane_cas_01 {
            file = QPATHTOF(data\animations\pilot.rtm);
            speed = 0.33;
        };
        class pilot_plane_cas_01_getin;
        class GVAR(pilot_getin) : pilot_plane_cas_01_getin {
            file = QPATHTOF(data\animations\pilot_getin.rtm);
        };
        class pilot_plane_cas_01_getout;
        class GVAR(pilot_getout) : pilot_plane_cas_01_getout {
            file = QPATHTOF(data\animations\pilot_getout.rtm);
        };
    };
};
