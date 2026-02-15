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
class CfgVehicles {
    class AllVehicles;
    class Air : AllVehicles {
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        reportOwnPosition = 1;
    };
    class UAV;
    class Helicopter : Air {
        explosionShielding = 0.7;
        epeImpulseDamageCoef = 4;
        crewCrashProtection = 1;
        class Turrets;
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
        class AnimationSources;
    };
    class Heli_Light_01_base_F : Helicopter_Base_H {
        epeImpulseDamageCoef = 4;
    };
    class Plane : Air {
        explosionShielding = 0.6;
        epeImpulseDamageCoef = 4;
        crewCrashProtection = 1;
    };
    class Plane_Base_F : Plane {
        class Turrets;
        class Components;
        class AnimationSources;
        class UserActions;
    };
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

    #include "helis\CfgApache.hpp"
    #include "helis\CfgChinook.hpp"
    #include "helis\CfgDauphin.hpp"
    #include "helis\CfgGxDrones.hpp"
    #include "helis\CfgHC135.hpp"
    #include "helis\CfgMerlin.hpp"
    #include "helis\CfgMerlinCUP.hpp"
    #include "helis\CfgPuma.hpp"
    #include "helis\CfgWildcat.hpp"
    #include "helis\CfgWildcatCUP.hpp"
    
    #include "helis\CfgPandaExpress.hpp"

    #include "planes\CfgA400.hpp"
    #include "planes\CfgBuzzard.hpp"
    #include "planes\CfgC130.hpp"
    #include "planes\CfgF35.hpp"
    #include "planes\CfgGR9.hpp"
};
