class DefaultVehicleSystemsDisplayManagerRight;
class DefaultVehicleSystemsDisplayManagerLeft;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class SensorTemplateDataLink;
class CBA_Extended_EventHandlers_base;
class CfgVehicles {
    class All {
        class AnimationSources;
    };
    class Thing : All {};
    class ThingX : Thing {};
    class Items_base_F : ThingX {};
    class AllVehicles : All {
        class NewTurret;
    };
    class Air : AllVehicles {
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        reportOwnPosition = 1;
        class AnimationSources;
    };
    class Helicopter : Air {
        explosionShielding = 0.7;
        epeImpulseDamageCoef = 4;
        crewCrashProtection = 1;
        class Turrets;
        class AnimationSources;
    };
    class Helicopter_Base_F : Helicopter {
        class ACE_Actions;
        class Turrets : Turrets {
            class MainTurret;
            class NewTurret;
        };
    };
    class Helicopter_Base_H : Helicopter_Base_F {
        class ACE_Actions : ACE_Actions {
            class ACE_MainActions;
        };
        class ViewOptics;
        class ViewPilot;
        class Turrets : Turrets {
            class MainTurret;
            class CopilotTurret;
        };
        class Components;
        class AnimationSources : AnimationSources {
            class HitEngine2 {
                hitpoint = "HitEngine2";
            };
        };
    };
    class Heli_Light_01_base_F : Helicopter_Base_H {
        epeImpulseDamageCoef = 4;
        class AnimationSources : AnimationSources {
            class hideweapons {
                source = "user";
                animPeriod = 1e-06;
                initPhase = 1;
            };
        };
    };
    class Plane : Air {
        explosionShielding = 0.6;
        epeImpulseDamageCoef = 4;
        crewCrashProtection = 1;
        class Turrets;
    };
    class UAV : Plane {};
    class Plane_Base_F : Plane {
        class Turrets;
        class Components;
        class AnimationSources;
        class UserActions;
    };
    class VTOL_Base_F;
    class Plane_CAS_01_base_F : Plane_Base_F {
        epeImpulseDamageCoef = 4;
    };
    class Plane_CAS_02_base_F : Plane_Base_F {
        epeImpulseDamageCoef = 4;
    };
    class Plane_Fighter_01_Base_F : Plane_Base_F {
        epeImpulseDamageCoef = 4;
    };
    class Plane_Fighter_02_Base_F : Plane_Base_F {
        epeImpulseDamageCoef = 4;
    };
    class Plane_Fighter_03_base_F : Plane_Base_F {
        epeImpulseDamageCoef = 4;
    };
    class Plane_Fighter_04_Base_F : Plane_Base_F {
        epeImpulseDamageCoef = 4;
    };
    class UAV_05_Base_F : UAV {
        epeImpulseDamageCoef = 4;
    };
    class UAV_06_base_F : Helicopter_Base_F {
        epeImpulseDamageCoef = 4;
    };

    class UAV_02_base_F : UAV {
        class AnimationSources : AnimationSources {
            class hideweapons {
                source = "user";
                animPeriod = 1e-06;
                initPhase = 1;
            };
        };
    };
    class B_UAV_02_LM_G : UAV_02_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Plane_Civil_01_base_F : Plane_Base_F {
        class AnimationSources : AnimationSources {
            class hitengine {
                source = "Hit";
                hitpoint = "HitEngine";
                raw = 1;
            };
        };
    };

    #include "helis\CfgApache.hpp"
    #include "helis\CfgBell412.hpp"
    #include "helis\CfgBlackHawk.hpp"
    #include "helis\CfgChinook.hpp"
    #include "helis\CfgDauphin.hpp"
    #include "helis\CfgGxDrones.hpp"
    #include "helis\CfgHC135.hpp"
    #include "helis\CfgHuey.hpp"
    #include "helis\CfgHuron.hpp"
    #include "helis\CfgKa52.hpp"
    #include "helis\CfgKasatka.hpp"
    #include "helis\CfgLittleBird.hpp"
    #include "helis\CfgMerlin.hpp"
    #include "helis\CfgMerlinCUP.hpp"
    #include "helis\CfgMi6.hpp"
    #include "helis\CfgMi8.hpp"
    #include "helis\CfgPuma.hpp"
    #include "helis\CfgTaru.hpp"
    #include "helis\CfgWildcat.hpp"
    #include "helis\CfgWildcatCUP.hpp"

    #include "helis\CfgPandaExpress.hpp"

    #include "planes\CfgA400.hpp"
    #include "planes\CfgBlackfish.hpp"
    #include "planes\CfgBuzzard.hpp"
    #include "planes\CfgC130.hpp"
    #include "planes\CfgF35.hpp"
    #include "planes\CfgGR9.hpp"
    #include "planes\CfgOsprey.hpp"
};
