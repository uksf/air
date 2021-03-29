class CfgMovesBasic {
    class DefaultDie;
    class ManActions {
        GVAR(pilot) = QGVAR(pilot);
        GVAR(cargo) = QGVAR(cargo);
        GVAR(load) = QGVAR(load);
    };
};
class CfgMovesMaleSdr : CfgMovesBasic {
    class States {
        class Crew;
        class GVAR(pilot_kia) : DefaultDie {
            actions = "DeadActions";
            file = QPATHTOF(data\animations\pilot_kia.rtm);
            speed = 0.5;
            looped = "false";
            terminal = 1;
            soundEnabled = 0;
            connectTo[] = { "DeadState", 0.1 };
        };
        class GVAR(pilot) : Crew {
            file = QPATHTOF(data\animations\pilot.rtm);
            interpolateTo[] = { QGVAR(pilot_kia),1 };
        };
        class GVAR(cargo_kia) : GVAR(pilot_kia) {};
        class GVAR(cargo) : Crew {
            file = QPATHTOF(data\animations\pilot.rtm);
            interpolateTo[] = { QGVAR(cargo_kia),1 };
        };
        class GVAR(load) : GVAR(cargo) {
            file = QPATHTOF(data\animations\load.rtm);
        };
    };
};
