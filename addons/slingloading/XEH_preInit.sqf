#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(MinRopeLength) = 2;
GVAR(MaxRopeLength) = 100;
GVAR(MaxDeployRetractDistance) = 10;
GVAR(MaxRopeDeployHeight) = 100;
GVAR(MinVehicleMass) = 0;
GVAR(RopeHandlingDistance) = 5;
GVAR(InitialDeployRopeLength) = 15;
GVAR(ExtendShortenRopeLength) = 5;
GVAR(DefaultLiftableMass) = 4000;
GVAR(MinRopeLengthDropCargo) = false;
GVAR(RopeUnwindSpeed) = 3;
GVAR(MaxLiftableMassFactor) = 8;

GVAR(classLoadPointOffsets) = [
    ["CUP_CH47F_base", [-0.05, -2, -0.05]],  
    ["CUP_AW159_Unarmed_Base", [-0.05, -0.06, -0.05]]
];
GVAR(classHookPointOverrides) = [
    ["TBD_M119", [[0.3,-2.3,0.4], [-0.3,-2.3,0.4], [0.8,0.3,0.45], [-0.8,0.3,0.45]]]
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
    ["VTOL_02_base_F", 7000],
    ["CUP_CH47F_base", 15000]
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
    ["Air", "CAN_SLING", "ReammoBox_F"],
    ["Air", "CAN_SLING", QUGVAR(vehicles,L119)],
    ["Air", "CAN_SLING", "Pod_Heli_Transport_04_crewed_base_F"]
];

GVAR(actionContext) = ACTION_CONTEXT_EMPTY;
GVAR(allRopes) = [];

call FUNC(init);

[QGVAR(Rope_Set_Mass), {call FUNC(Rope_Set_Mass)}] call CBA_fnc_addEventHandler;
[QGVAR(Extend_Ropes), {call FUNC(Extend_Ropes)}] call CBA_fnc_addEventHandler;
[QGVAR(Shorten_Ropes), {call FUNC(Shorten_Ropes)}] call CBA_fnc_addEventHandler;
[QGVAR(Release_Cargo), {call FUNC(Release_Cargo)}] call CBA_fnc_addEventHandler;
[QGVAR(Retract_Ropes), {call FUNC(Retract_Ropes)}] call CBA_fnc_addEventHandler;
[QGVAR(Deploy_Ropes), {call FUNC(Deploy_Ropes)}] call CBA_fnc_addEventHandler;
[QGVAR(Deploy_Ropes_Index), {call FUNC(Deploy_Ropes_Index)}] call CBA_fnc_addEventHandler;
[QGVAR(Pickup_Ropes), {call FUNC(Pickup_Ropes)}] call CBA_fnc_addEventHandler;
[QGVAR(Attach_Ropes), {call FUNC(Attach_Ropes)}] call CBA_fnc_addEventHandler;
[QGVAR(Drop_Ropes), {call FUNC(Drop_Ropes)}] call CBA_fnc_addEventHandler;

ADDON = true;
