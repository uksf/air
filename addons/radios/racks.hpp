// ACRE rack macros, shared with aircraft addons outside radios.
#define RACKS_AIR \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "R1"; \
            shortName = "R1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"driver", "copilot", "gunner", "commander"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 0; \
            intercom[] = {}; \
        }; \
        class Rack_2: Rack_1 { \
            displayName = "R2"; \
            shortName = "R2"; \
        }; \
        class Rack_3: Rack_1 { \
            displayName = "R3"; \
            shortName = "R3"; \
        }; \
    }

#define RACKS_AIR_FOUR \
    class AcreRacks { \
        class Rack_Shared1 { \
            displayName = "RS1"; \
            shortName = "RS1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"driver", "copilot", "gunner", "commander"}; \
            disabledPositions[] = {}; \
            defaultComponents[] = {}; \
            mountedRadio = "ACRE_PRC117F"; \
            isRadioRemovable = 0; \
            intercom[] = {}; \
        }; \
        class Rack_Shared2: Rack_Shared1 { \
            displayName = "RS2"; \
            shortName = "RS2"; \
        }; \
        class Rack_Pilot1: Rack_Shared1 { \
            displayName = "R3"; \
            shortName = "R3"; \
            allowedPositions[] = {"driver"}; \
        }; \
        class Rack_Pilot2: Rack_Pilot1 { \
            displayName = "R4"; \
            shortName = "R4"; \
            allowedPositions[] = {"driver"}; \
        }; \
        class Rack_Gunner1: Rack_Pilot1 { \
            allowedPositions[] = {"gunner"}; \
        }; \
        class Rack_Gunner2: Rack_Pilot2 { \
            allowedPositions[] = {"gunner"}; \
        }; \
    }
