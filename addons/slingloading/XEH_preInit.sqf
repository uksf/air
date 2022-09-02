#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(MinRopeLength) = 2; // minimum rope length in meter
GVAR(MaxRopeLength) = 100; // maximum rope length in meter (As of Arma v2.04, this limit is hardcoded. No ropes longer than 100 m can be created or unwound)
GVAR(MaxDeployRetractDistance) = 10; // maximum rope deploy, retract distance in meter (when player is on foot)
GVAR(MaxRopeDeployHeight) = 100; // maximum height in meter the action 'Deploy Cargo Ropes' is available
GVAR(MinVehicleMass) = 0; // minimum mass a vehicle has to have to be able to deploy ropes
GVAR(RopeHandlingDistance) = 5; // maximum distance in meter a unit has to be from a rope end to be able to pick up the rope
GVAR(InitialDeployRopeLength) = 15; // initial rope length in meter, when rope is deployed
GVAR(ExtendShortenRopeLength) = 5; // rope length in meter, when rope is extended / shortened
GVAR(DefaultLiftableMass) = 4000; // default mass in kg, which can be lifted
GVAR(MinRopeLengthDropCargo) = false; // drop cargo, when minimum rope length is reached, and ropes are shortened once more
GVAR(RopeUnwindSpeed) = 3; // ropes unwinding speed
GVAR(MaxLiftableMassFactor) = 8; // maximum liftable mass factor (FUNC(Rope_Get_Lift_Capability) * GVAR(MaxLiftableMassFactor))

GVAR(classLoadPointOffsets) = [
    ["CUP_CH47F_base", [-0.05, -2, -0.05]],  
    ["CUP_AW159_Unarmed_Base", [-0.05, -0.06, -0.05]]
];

GVAR(liftCapacity) = [
    ["UAV_01_base_F", 50],
    ["UAV_06_base_F", 260],
    ["Heli_Light_01_base_F", 1700],
    ["Heli_Light_02_base_F", 2500],
    ["UAV_03_base_F", 2900],
    ["Heli_light_03_base_F", 3300],
    ["Heli_Transport_01_base_F", 3300],
    ["Heli_Attack_01_base_F", 5600],
    ["Heli_Transport_02_base_F", 5700],
    ["VTOL_01_base_F", 6700],
    ["VTOL_02_base_F", 7000]
];

GVAR(supportedVehicles) = [
    "Helicopter",
    "VTOL_Base_F"
];

GVAR(slingRules) = [
    ["Air", "CAN_SLING", "Car"],
    ["Air", "CAN_SLING", "Tank"],
    ["Air", "CAN_SLING", "Air"],
    ["Air", "CAN_SLING", "Boat_F"],
    ["Air", "CAN_SLING", "ReammoBox_F"]
];

call FUNC(init);

ADDON = true;
