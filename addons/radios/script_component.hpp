#define COMPONENT radios
#define COMPONENT_BEAUTIFIED Radios
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define INTERCOM_AIR \
    class AcreIntercoms { \
        class Intercom_1 { \
            displayName = "Crew intercom"; \
            shortName = "Crew"; \
            allowedPositions[] = {"crew"}; \
            disabledPositions[] = {}; \
            limitedPositions[] = {{"cargo", "all"}}; \
            masterPositions[] = {"driver"}; \
            numLimitedPositions = 3; \
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
    };

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
    };

#define RACKS_AIR_FOUR \
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
        class Rack_4: Rack_1 { \
            displayName = "R4"; \
            shortName = "R4"; \
        }; \
    };

#define RACKS_AIR_GROUND \
    class AcreRacks { \
        class Rack_1 { \
            displayName = "R1"; \
            shortName = "R1"; \
            componentName = "ACRE_VRC103"; \
            allowedPositions[] = {"crew", "external"}; \
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
    };
