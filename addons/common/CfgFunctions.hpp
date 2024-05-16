class CfgFunctions {
    class A3_Jets {
        class AircrfatCarrier {
            class Carrier01CatapultActionAdd {
                file = QPATHTOF(functions\fnc_carrier01catapultactionadd.sqf);
            };
        };
        class AAE {
            delete Carrier01CatapultActionAdd;
        };
    };
    class AAE {
        class GeneralFn {
            class camshake {
                file = QPATHTOF(functions\fnc_aaeCamshakeWrapper.sqf);
            };
        };
    };
};
