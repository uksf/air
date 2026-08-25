class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};

class Extended_Init_EventHandlers {
    class GVAR(raf) {
        class ADDON {
            init = QUOTE((_this select 0) setVehicleRadar 1; (_this select 0) setVehicleReportRemoteTargets true);
        };
    };
};

class Extended_Local_EventHandlers {
    class GVAR(raf) {
        class ADDON {
            local = QUOTE(if (_this select 1) then { (_this select 0) setVehicleRadar 1; (_this select 0) setVehicleReportRemoteTargets true; });
        };
    };
};
