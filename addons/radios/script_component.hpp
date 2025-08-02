#define COMPONENT radios
#define COMPONENT_BEAUTIFIED Radios
#include "\u\uksf_air\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf_air\addons\main\script_macros.hpp"

#define INTERCOM_AIR \
    class AcreIntercoms { \
        class Intercom_1 { \
            displayName = "Crew intercom"; \
            shortName = "Crew"; \
            allowedPositions[] = {"crew"}; \
            disabledPositions[] = {}; \
            limitedPositions[] = {{"cargo", "all"}}; \
            masterPositions[] = {"driver"}; \
            numLimitedPositions = 5; \
            connectedByDefault = 1; \
        }; \
        class Intercom_2: Intercom_1 { \
            displayName = "Passenger intercom"; \
            shortName = "Passenger"; \
            allowedPositions[] = {"crew", {"cargo", "all"}}; \
            limitedPositions[] = {}; \
            numLimitedPositions = 0; \
            connectedByDefault = 0; \
        }; \
    }

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
