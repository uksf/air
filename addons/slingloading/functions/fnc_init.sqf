#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Init slingloading functions. This is a temporary solution until functions are properly extracted/rewritten (TM)

    Parameter(s):
        None

    Return Value:
        Nothing
*/

FUNC(Get_Sling_Load_Points) = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _slingLoadPointsArray = [];
    private _cornerPoints = [_vehicle] call FUNC(Get_Corner_Points);
    private _frontCenterPoint = (((_cornerPoints #2) vectorDiff (_cornerPoints #3)) vectorMultiply 0.5) vectorAdd (_cornerPoints #3);
    private _rearCenterPoint = (((_cornerPoints #0) vectorDiff (_cornerPoints #1)) vectorMultiply 0.5) vectorAdd (_cornerPoints #1);
    _rearCenterPoint = ((_frontCenterPoint vectorDiff _rearCenterPoint) vectorMultiply 0.2) vectorAdd _rearCenterPoint;
    _frontCenterPoint = ((_rearCenterPoint vectorDiff _frontCenterPoint) vectorMultiply 0.2) vectorAdd _frontCenterPoint;
    private _middleCenterPoint = ((_frontCenterPoint vectorDiff _rearCenterPoint) vectorMultiply 0.5) vectorAdd _rearCenterPoint;
    private _vehicleUnitVectorUp = vectorNormalized (vectorUp _vehicle);
    private _slingLoadPointHeightOffset = [-0.05, -0.05, -0.05];
    {
        if (_vehicle isKindOf _x #0) exitWith {
            _slingLoadPointHeightOffset = _x #1;
            // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Get_Sling_Load_Points)) _vehicle ", _vehicle, " isKindOf ", _x #0, ", _slingLoadPointHeightOffsetfset: ", _slingLoadPointHeightOffset];
        };
    } forEach GVAR(classLoadPointOffsets);
    private _slingLoadPoints = [];
    private ["_modelPoint",
        "_modelPointASL", 
        "_surfaceIntersectStartASL", 
        "_surfaceIntersectEndASL", 
        "_la", 
        "_lb", 
        "_n", 
        "_p0", 
        "_l",
        "_d",
        "_surfaces", 
        "_intersectionASL",
        "_intersectionObject"
    ];
    {
        _modelPoint = _x;
        _modelPointASL = AGLToASL (_vehicle modelToWorldVisual _modelPoint);
        _surfaceIntersectStartASL = _modelPointASL vectorAdd (_vehicleUnitVectorUp vectorMultiply -5);
        _surfaceIntersectEndASL = _modelPointASL vectorAdd (_vehicleUnitVectorUp vectorMultiply 5);
        
        // Determine if the surface intersection line crosses below ground level
        // If if does, move surfaceIntersectStartASL above ground level (lineIntersectsSurfaces
        // doesn't work if starting below ground level for some reason)
        // See: https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
        _la = ASLToAGL _surfaceIntersectStartASL;
        _lb = ASLToAGL _surfaceIntersectEndASL;
        if (_la #2 < 0 && _lb #2 > 0) then {
            _n = [0, 0, 1];
            _p0 = [0, 0, 0.1];
            _l = (_la vectorFromTo _lb);
            if ((_l vectorDotProduct _n) != 0) then {
                _d = ((_p0 vectorAdd (_la vectorMultiply -1)) vectorDotProduct _n) / (_l vectorDotProduct _n);
                _surfaceIntersectStartASL = AGLToASL ((_l vectorMultiply _d) vectorAdd _la);
            };
        };
        
        _surfaces = lineIntersectsSurfaces [_surfaceIntersectStartASL, _surfaceIntersectEndASL, objNull, objNull, true, 100];
        _intersectionASL = [];
        {
            _intersectionObject = _x #2;
            if (_intersectionObject == _vehicle) exitWith {
                _intersectionASL = _x #0;
            };
        } forEach _surfaces;
        if (count _intersectionASL > 0) then {
            _intersectionASL = _intersectionASL vectorAdd ((_surfaceIntersectStartASL vectorFromTo _surfaceIntersectEndASL) vectorMultiply (_slingLoadPointHeightOffset #(count _slingLoadPoints)));
            _slingLoadPoints pushBack (_vehicle worldToModelVisual (ASLToAGL _intersectionASL));
        } else {
            _slingLoadPoints pushBack [];
        };
    } forEach [_frontCenterPoint, _middleCenterPoint, _rearCenterPoint];
    
    if (count (_slingLoadPoints #1) > 0) then {
        _slingLoadPointsArray pushBack [_slingLoadPoints #1];
        if (count (_slingLoadPoints #0) > 0 && count (_slingLoadPoints #2) > 0) then {
            if (((_slingLoadPoints #0) distance (_slingLoadPoints #2)) > 3) then {
                _slingLoadPointsArray pushBack [_slingLoadPoints #0, _slingLoadPoints #2];
                if (((_slingLoadPoints #0) distance (_slingLoadPoints #1)) > 3) then {
                    _slingLoadPointsArray pushBack [_slingLoadPoints #0, _slingLoadPoints #1, _slingLoadPoints #2];
                };
            };
        };
    };
    _slingLoadPointsArray;
};

FUNC(Get_Corner_Points) = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _widthFactor    = 0.5;
    private _lengthFactor    = 0.5;
    if (_vehicle isKindOf "Air") then {                     // Correct width and length factor for air
        _widthFactor        = 0.3;
    };
    if (_vehicle isKindOf "Helicopter") then {
        _widthFactor        = 0.2;
        _lengthFactor        = 0.45;
    };
    private _centerOfMass     = getCenterOfMass _vehicle;
    private _bbr            = boundingBoxReal _vehicle;
    private _p1                = _bbr #0;
    private _p2                = _bbr #1;
    private _maxWidth        = abs ((_p2 #0) - (_p1 #0));
    private _widthOffset    = ((_maxWidth / 2) - abs (_centerOfMass #0)) * _widthFactor;
    private _maxLength        = abs ((_p2 #1) - (_p1 #1));
    private _lengthOffset    = ((_maxLength / 2) - abs (_centerOfMass #1)) * _lengthFactor;
    private _maxHeight        = abs ((_p2 #2) - (_p1 #2));
    private _heightOffset    = _maxHeight / 6;
    private _rearCorner        = [(_centerOfMass #0) + _widthOffset, (_centerOfMass #1) - _lengthOffset, (_centerOfMass #2) + _heightOffset];
    private _rearCorner2    = [(_centerOfMass #0) - _widthOffset, (_centerOfMass #1) - _lengthOffset, (_centerOfMass #2) + _heightOffset];
    private _frontCorner    = [(_centerOfMass #0) + _widthOffset, (_centerOfMass #1) + _lengthOffset, (_centerOfMass #2) + _heightOffset];
    private _frontCorner2    = [(_centerOfMass #0) - _widthOffset, (_centerOfMass #1) + _lengthOffset, (_centerOfMass #2) + _heightOffset];
    [_rearCorner, _rearCorner2, _frontCorner, _frontCorner2];
};

FUNC(Rope_Get_Lift_Capability) = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _slingLoadMaxCargoMass = getNumber (configOf _vehicle >> "slingLoadMaxCargoMass");
    if (_slingLoadMaxCargoMass <= 0) then {
        _slingLoadMaxCargoMass = GVAR(DefaultLiftableMass);
    };
    {
        if (_vehicle isKindOf _x #0) exitWith {_slingLoadMaxCargoMass = _x #1};
    } forEach GVAR(liftCapacity);
    _slingLoadMaxCargoMass;
};

FUNC(Rope_Set_Mass) = {
    params [["_cargo", objNull], ["_mass", 0]];
    if (isNull _cargo || _mass == 0) exitWith {};
    _cargo setMass _mass;
};

    // diag_log formatText [
    //     "%1%2%3%4%5%6%7%8%9%10%11", time, 
    //     "s  (FUNC(Rope_Adjust_Mass)) _cargo: ",    _cargo,
    //     "    _originalMass: ", _originalMass,
    //     "    _vehicle: ", _vehicle,
    //     "    _lift: ", _lift,
    //     "    _heavyLiftMinLift: ", _heavyLiftMinLift
    // ];
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Rope_Adjust_Mass)) Mass is being adjusted!"];
FUNC(Rope_Adjust_Mass) = {
    params [["_vehicle", objNull], ["_cargo", objNull], ["_ropes", []]];
    if (isNull _vehicle || isNull _cargo) exitWith {};
    private _lift = [_vehicle] call FUNC(Rope_Get_Lift_Capability);
    private _maxLiftableMass = _lift * GVAR(MaxLiftableMassFactor);
    private _originalMass = getMass _cargo;
    private _heavyLiftMinLift = missionNamespace getVariable [QGVAR(HEAVY_LIFTING_MIN_LIFT_OVERRIDE), 5000];
    if (_originalMass >= _lift * 0.8 && _lift >= _heavyLiftMinLift && _originalMass <= _maxLiftableMass) then {
        [QGVAR(Rope_Set_Mass), [_cargo, _originalMass], _cargo] call CBA_fnc_targetEvent;
        [_vehicle, _cargo, _originalMass, _lift, _maxLiftableMass] spawn {
            params [["_vehicle", objNull], ["_cargo", objNull], ["_originalMass", 0], ["_lift", 0], ["_maxLiftableMass", 0]];
            if (isNull _vehicle || isNull _cargo || _originalMass == 0 || _lift == 0 || _maxLiftableMass == 0) exitWith {};
            [QGVAR(Rope_Set_Mass), [_cargo, (_lift * 0.8 + ((_originalMass / _maxLiftableMass) * (_lift * 0.2)))], _cargo] call CBA_fnc_targetEvent;
        };
    };
    sleep 0.3;
    [_vehicle, _originalMass, _lift] spawn {
        params [["_vehicle", objNull], ["_originalMass", 0], ["_lift", 0]];
        if (isNull _vehicle || _originalMass == 0 || _lift == 0) exitWith {};
        sleep 0.2;
        private _messages = [[LLSTRING(SLING_MASS)]];
        private _totalSlingMass = 0;
        {
            _totalSlingMass = _totalSlingMass + getMass _x;
        } forEach ropeAttachedObjects _vehicle;
        if (_totalSlingMass > _lift) then {
            _messages pushback [LLSTRING(OVERLOAD)];
            _messages pushback [format [LLSTRING(OVERLOAD_MASS), (_totalSlingMass / 1000) toFixed 2, (_lift / 1000) toFixed 2]];
        } else {
            _messages pushback [format [LLSTRING(SLING_MASS_REMAINING), ((_lift - _totalSlingMass) / 1000) toFixed 2, (_lift / 1000) toFixed 2]];
        };
        _messages pushBack true;
        _messages call CBA_fnc_notify;
    };
};

/* Constructs an array of all active (or inactive) rope indexes and position labels 
    (e.g. [[rope index,"Front"], [rope index,"Rear"]]) for a specified vehicle */
FUNC(Get_Active_Ropes) = {
    params [["_vehicle", objNull], ["_active", false]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Get_Ropes)) _vehicle: ", _vehicle, "    _active: ", _active];
    if (isNull _vehicle) exitWith {false};
    private _activeRopes = [];
    private _existingRopes = _vehicle getVariable [QGVAR(Ropes), []];
    private _ropeLabelSets = [
        [LLSTRING(CENTER)],
        [LLSTRING(FRONT), LLSTRING(REAR)],
        [LLSTRING(FRONT), LLSTRING(CENTER), LLSTRING(REAR)]
    ];
    private _totalExistingRopes = count _existingRopes;
    private ["_ropeLabels"];
    {
        if ((_active && count _x > 0) || (!_active && count _x == 0)) then {
            _ropeLabels = _ropeLabelSets #(_totalExistingRopes - 1);
            _activeRopes pushBack [_foreachindex, _ropeLabels #_foreachindex];
        };
    } forEach _existingRopes;
    _activeRopes;
};

FUNC(Get_Active_Ropes_With_Cargo) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    private _activeRopesWithCargo = [];
    private _existingCargo = _vehicle getVariable [QGVAR(Cargo), []];
    private _activeRopes = [_vehicle, true] call FUNC(Get_Active_Ropes);
    private ["_cargo"];
    {
        _cargo = _existingCargo select (_x #0);
        if (!isNull _cargo) then {
            if (!alive _cargo || ropeAttachedTo _cargo != _vehicle) exitWith {
                [_vehicle, _unit, _foreachindex] call FUNC(Release_Cargo); // in case cargo destroyed
            };
            _activeRopesWithCargo pushBack _x;
        };
    } forEach _activeRopes;
    _activeRopesWithCargo;
};

FUNC(Get_Active_Ropes_Without_Cargo) = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _activeRopesWithoutCargo = [];
    private _existingCargo = _vehicle getVariable [QGVAR(Cargo), []];
    private _activeRopes = [_vehicle, true] call FUNC(Get_Active_Ropes);
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Get_Active_Ropes_Without_Cargo)) _vehicle: ", _vehicle, ", _existingCargo: ", _existingCargo, ", _activeRopes: ", _activeRopes];
    private ["_cargo"];
    {
        _cargo = _existingCargo select (_x #0);
        if (isNull _cargo) then {
            _activeRopesWithoutCargo pushBack _x;
        };
    } forEach _activeRopes;
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Get_Active_Ropes_Without_Cargo)) _activeRopesWithoutCargo: ", _activeRopesWithoutCargo];
    _activeRopesWithoutCargo;
};

FUNC(Get_Ropes) = {
    params [["_vehicle", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    private _selectedRopes = [];
    private _allRopes = _vehicle getVariable [QGVAR(Ropes), []];
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Is_Unit_Authorized)) _vehicle: ", _vehicle, ", _ropesIndex: ", _ropesIndex], ", _allRopes: ", _allRopes;
    if (count _allRopes > _ropesIndex) then {
        _selectedRopes = _allRopes #_ropesIndex;
    };
    _selectedRopes;
};

FUNC(Get_Ropes_Count) = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    count (_vehicle getVariable [QGVAR(Ropes), []]);
};

FUNC(Get_Cargo) = {
    params [["_vehicle", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    private _selectedCargo = objNull;
    private _allCargo = _vehicle getVariable [QGVAR(Cargo), []];
    if (count _allCargo > _ropesIndex) then {
        _selectedCargo = _allCargo #_ropesIndex;
    };
    _selectedCargo;
};

FUNC(Get_Ropes_And_Cargo) = {
    params [["_vehicle", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    private _selectedCargo = (_this call FUNC(Get_Cargo));
    private _selectedRopes = (_this call FUNC(Get_Ropes));
    [_selectedRopes, _selectedCargo];
};

FUNC(Extend_Ropes_Action_Check) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Extend_Ropes_Action_Check)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if ([getConnectedUAV _unit, _unit] call FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Extend_Ropes_Action_Check)) EXIT 1, can release: ", [getConnectedUAV _unit, _unit] call FUNC(Can_Release_Cargo)];
        [getConnectedUAV _unit, _toGround] call FUNC(Can_Extend_Ropes)
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call FUNC(Is_Unit_Authorized)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Extend_Ropes_Action_Check)) EXIT 2, can release: ", [_vehicle, _unit] call FUNC(Can_Release_Cargo)];
        [_vehicle, _toGround] call FUNC(Can_Extend_Ropes)
    };
    false
};

FUNC(Is_Unit_Authorized) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Is_Unit_Authorized)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if (driver _vehicle == _unit || gunner _vehicle == _unit) exitWith {true};
    private _turrets = configOf _vehicle >> "turrets";
    private _isTurret = false;
    for "_i" from 0 to (count _turrets - 1) do {
        if ((_vehicle turretUnit [_i]) == _unit) exitWith {_isTurret = true};
    };
    _isTurret
};

FUNC(Can_Extend_Ropes) = {
    params [["_vehicle", objNull], ["_toGround", false]];
    if (isNull _vehicle) exitWith {false};
    if !([_vehicle] call FUNC(Is_Supported_Vehicle)) exitWith {false};
    private _allRopes = _vehicle getVariable [QGVAR(Ropes), []];
    if (count _allRopes == 0) exitWith {false};
    if (count ([_vehicle, true] call FUNC(Get_Active_Ropes)) == 0) exitWith {false};
    private _exit = false;
    if (_toGround) then {
        if (ropeEndPosition (_allRopes #0 #0) #1 #2 < GVAR(ExtendShortenRopeLength)) exitWith {_exit = true};
        private _vehicleHeight = getPos _vehicle #2;
        if (_vehicleHeight < GVAR(ExtendShortenRopeLength) || _vehicleHeight > GVAR(MaxRopeLength)) then {_exit = true};
    };
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Extend_Ropes)) _vehicle: ", _vehicle, "    _toGround: ", _toGround];
    if (_exit) exitWith {false};
    true;
};

FUNC(Extend_Ropes_Action) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Extend_Ropes_Action)) _vehicle: ", _vehicle, ", _unit: ", _unit, ", _toGround: ", _toGround];
    if (isNull _vehicle || isNull _unit) exitWith {};
    private _activeRopes = [_vehicle, true] call FUNC(Get_Active_Ropes);
    private _canReleaseCargo = false;
    if (_toGround) then {
        _canReleaseCargo = [_vehicle, _unit] call FUNC(Can_Release_Cargo);
    };
    if (count _activeRopes == 1) exitWith {
        private _ropeLength = [_vehicle, _activeRopes #0 #0, _toGround] call FUNC(Extend_Ropes);
        if (_ropeLength <= GVAR(MaxRopeLength)) exitWith {
            private _messages = [[format [LLSTRING(ROPES_EXTENDED_TO), _ropeLength]]];
            if (_toGround) then {_messages set [0, [format [LLSTRING(ROPES_EXTENDED_TO_G), _ropeLength]]]};
            if (_ropeLength == GVAR(MaxRopeLength)) then {
                _messages set [0, [format ["%1%2", _messages#0#0, " (max)"]]]
            };
            _messages pushBack true;
            _messages call CBA_fnc_notify;
            // diag_log formatText ["%1%2%3%4%5%6%7%8%9", time, "s  (FUNC(Extend_Ropes_Action)) can release cargo: ", [_vehicle, _unit] call FUNC(Can_Release_Cargo)];
            if (_toGround && _canReleaseCargo) then {
                private _rope = (_vehicle getVariable QGVAR(Ropes)) #0 #0;
                private _cargo = (_vehicle getVariable QGVAR(Cargo)) #0;
                [_vehicle, _unit, _rope, _ropeLength, _cargo] spawn FUNC(Release_Cargo_Near_Ground);
            };
        };
        [[format [LLSTRING(ALREADY_MAX_LENGTH), GVAR(MaxRopeLength)]], true] call CBA_fnc_notify;
    };
    GVAR(actionContext) = [ACTION_CONTEXT_EXTEND, ACTION_CONTEXT_EXTENDTOGROUND] select _toGround;
    [LLSTRING(EXTEND), QFUNC(Extend_Ropes_Index_Action), _activeRopes, LLSTRING(ROPE), _vehicle, _unit, _toGround] call FUNC(Show_Select_Ropes_Menu);
    private _extendedRopes = _vehicle getVariable [QGVAR(Ropes_Change), []];
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9", time, "s  (FUNC(Extend_Ropes_Action)) _extendedRopes: ", _extendedRopes, ", _activeRopes: ", _activeRopes];
    if (count _extendedRopes == 0) exitWith {};
    private ["_extendedRopeIndex", "_activeCargoRopes"];
    private _messages = [[LLSTRING(ROPES_EXTENDED)]];
    if (_toGround) then {
        _messages set [0, [format [LLSTRING(ROPES_EXTENDED_TG), _messages#0#0]]];
        _activeCargoRopes = [_vehicle, _unit] call FUNC(Get_Active_Ropes_With_Cargo);
    };
    {
        if (_x #1 <= GVAR(MaxRopeLength)) then {
            _extendedRopeIndex = _x #0;
            _messages pushBack [format [LLSTRING(ROPES_EXTENDED_TO_IND), (_activeRopes select {_x #0 == _extendedRopeIndex}) #0 #1, _x #1]];
            if (_x #1 == GVAR(MaxRopeLength)) then {
                _messages set [1, [format ["%1%2", _messages#1#0, " (max)"]]];
            };
            // diag_log formatText [
            //     "%1%2%3%4%5%6%7%8%9", time,
            //     "s  (FUNC(Extend_Ropes_Action)) can release cargo: ", [_vehicle, _unit] call FUNC(Can_Release_Cargo),
            //     ", _extendedRopeIndex: ", _extendedRopeIndex
            // ];
            if (_toGround && _canReleaseCargo) then {
                private _rope = (_vehicle getVariable QGVAR(Ropes)) #_extendedRopeIndex #0;
                private _cargo = (_vehicle getVariable QGVAR(Cargo)) #_extendedRopeIndex;
                [_vehicle, _unit, _rope, _x #1, _cargo, _extendedRopeIndex] spawn FUNC(Release_Cargo_Near_Ground);
            };
        } else {
            _messages pushBack [format [LLSTRING(ALREADY_MAX_LENGTH), GVAR(MaxRopeLength)]];
        };
    } forEach _extendedRopes;
    _messages pushBack true;
    _messages call CBA_fnc_notify;
    _vehicle setVariable [QGVAR(Ropes_Change), nil];
};

FUNC(Release_Cargo_Near_Ground) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_rope", objNull], ["_ropeLength", 0], ["_cargo", objNull], ["_ropesIndex", 0]];
    // diag_log formatText [
    //     "%1%2%3%4%5%6%7%8%9%10%11%12%13", time,
    //     "s  (FUNC(Release_Cargo_Near_Ground)) _vehicle: ", _vehicle,
    //     ", _unit: ", _unit,
    //     ", _rope: ", _rope,
    //     ", _ropeLength: ", _ropeLength,
    //     ", _cargo: ", _cargo
    // ];
    if (isNull _vehicle || isNull _unit || isNull _rope || _ropeLength == 0 || isNull _cargo) exitWith {};
    private _future = time + 20 + 100 / GVAR(RopeUnwindSpeed);
    sleep 1;
    while {
        !ropeUnwound _rope && 
        alive _vehicle &&
        time < _future && 
        ropeLength _rope < _ropeLength &&
        alive _cargo &&
        getPos _cargo #2 > 1
    } do {sleep 1};
    // diag_log formatText [
    //     "%1%2%3%4%5%6%7%8%9%10%11%12%13", time,
    //     "s  (FUNC(Release_Cargo_Near_Ground)) EXIT LOOP! ropeUnwound: ", !ropeUnwound _rope,
    //     ", alive _vehicle: ", alive _vehicle,
    //     ", time < _future: ", time < _future,
    //     ", ropeLength _rope < _ropeLength: ", ropeLength _rope < _ropeLength,
    //     ", alive _cargo: ", alive _cargo,
    //     ", getPos _cargo #2 > 1: ", getPos _cargo #2 > 1
    // ];
    if (!alive _vehicle || (getPos _cargo #2 > 5 && getPosASL _cargo #2 > 5 && alive _cargo)) exitWith {};
    [_ropesIndex, _vehicle, _unit] call FUNC(Release_Cargo_Index_Action);
};

FUNC(Show_Select_Ropes_Menu) = {
    params ["_title", "_functionName", "_ropesIndexAndLabelArray", ["_ropesLabel", LLSTRING(ROPE)], ["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15", time, "s  (FUNC(Show_Select_Ropes_Menu)) _title: ", _title, ", _functionName: ", _functionName, ", _ropesIndexAndLabelArray: ", _ropesIndexAndLabelArray, ", _ropesLabel: ", _ropesLabel, ", _vehicle: ", _vehicle, ", _unit: ", _unit, ", _toGround: ", _toGround];
    if (isNull _vehicle || isNull _unit) exitWith {};
    GVAR(Show_Select_Ropes_Menu_Array) = [[_title, false]];
    GVAR(Vehicle) = _vehicle;
    GVAR(Unit) = _unit;
    GVAR(toGround) = _toGround;

    GVAR(Show_Select_Ropes_Menu_Array) pushBack [format ["%1 %2", LLSTRING(ALL), _ropesLabel], [0], "", -5, [["expression", format [QUOTE({[ARR_4(_x,GVAR(Vehicle),GVAR(Unit),GVAR(toGround))] call %1} forEach [ARR_3(0,1,2)]), _functionName]]], "1", "1"];
    {
        GVAR(Show_Select_Ropes_Menu_Array) pushBack [format ["%1 %2", _x#1, _ropesLabel], [0], "", -5, [["expression", format [QUOTE([ARR_4(%1,GVAR(Vehicle),GVAR(Unit),GVAR(toGround))] call %2), _x#0, _functionName]]], "1", "1"];
    } forEach _ropesIndexAndLabelArray;
    
    showCommandingMenu "";
    showCommandingMenu QUOTE(#USER:GVAR(Show_Select_Ropes_Menu_Array));
    waitUntil {commandingMenu == ""};
    GVAR(actionContext) = ACTION_CONTEXT_EMPTY;
};

FUNC(Extend_Ropes_Index_Action) = {
    params ["_ropesIndex", ["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9", time, "s  (FUNC(Extend_Ropes_Index_Action)) _ropesIndex: ", _ropesIndex, ", _vehicle: ", _vehicle, ", _unit: ", _unit, ", _toGround: ", _toGround];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && !isNull _vehicle && [_vehicle, _toGround] call FUNC(Can_Extend_Ropes)) then {
        private _ropeLength = [_vehicle, _ropesIndex, _toGround] call FUNC(Extend_Ropes);
        [_vehicle, _ropeLength, _ropesIndex] call FUNC(Save_Rope_Change);
    };
};

FUNC(Save_Rope_Change) = {
    params [["_vehicle", objNull], ["_ropeLength", 0], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9", time, "s  (FUNC(Save_Rope_Change)) _ropeLength: ", _ropeLength, ", _ropesIndex: ", _ropesIndex];
    private _existingRopes = [_vehicle, _ropesIndex] call FUNC(Get_Ropes);
    if (count _existingRopes == 0 || _ropeLength == 0) exitWith {};
    private _changedRopes = _vehicle getVariable [QGVAR(Ropes_Change), []];
    _changedRopes pushBack [_ropesIndex, _ropeLength];
    _vehicle setVariable [QGVAR(Ropes_Change), _changedRopes];
};

FUNC(Extend_Ropes) = {
    params [["_vehicle", objNull], ["_ropesIndex", 0], ["_toGround", false]];
    if (isNull _vehicle) exitWith {};
    if !(local _vehicle) exitWith {[QGVAR(Extend_Ropes), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopes = [_vehicle, _ropesIndex] call FUNC(Get_Ropes);
    if (count _existingRopes == 0) exitWith {0};
    private _ropeLength = ropeLength (_existingRopes #0);
    if (_ropeLength >= GVAR(MaxRopeLength)) exitWith {GVAR(MaxRopeLength) + 1};
    private _unwindLength = GVAR(ExtendShortenRopeLength);
    if (_toGround) then {
        _unwindLength = ceil((getPos _vehicle #2) - _ropeLength + 5);
        /*
            'getPos' will return the height of the vehicle above the next object underneath. 
            So, if the vehicle has a sling load, it is likely the height will be measured false
            from vehicle to the sling load underneath. If there is a cargo, recalculate unwind
            length from sling load to ground.
        */
        private _allCargo = _vehicle getVariable [QGVAR(Cargo), []];
        private _cargo = _allCargo #_ropesIndex;
        if (isNull _cargo) exitWith {};
        _unwindLength = ceil(getPos _cargo #2) + 3;
    };
    if (_ropeLength + _unwindLength > GVAR(MaxRopeLength)) then {
        _unwindLength = GVAR(MaxRopeLength) - _ropeLength;
    };
    // diag_log formatText [
    //     "%1%2%3%4%5%6%7%8%9%10%11%12%13", time,
    //     "s  (FUNC(Extend_Ropes)) _unwindLength: ", _unwindLength,
    //     ", vehicle height: ", getPos _vehicle #2,
    //     ", GVAR(MaxRopeLength): ", GVAR(MaxRopeLength),
    //     ", _ropeLength: ", _ropeLength,
    //     ", _ropesIndex: ", _ropesIndex
    // ];
    [_vehicle, _existingRopes, GVAR(RopeUnwindSpeed), _unwindLength] spawn FUNC(Unwind_Ropes);
    _ropeLength = _ropeLength + _unwindLength;
    _ropeLength
};

FUNC(Unwind_Ropes) = {
    params [["_vehicle", objNull], ["_ropes", []], ["_speed", 3], ["_length", 0], ["_relative", true]];
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9", time, "s  (FUNC(Unwind_Ropes)) _vehicle: ", _vehicle, ", _ropes: ", _ropes, ", _length: ", _length, ", _relative: ", _relative];
    if (isNull _vehicle) exitWith {};
    private _sound = QGVAR(SlingLoadUpExt);
    if (_length > 0) then {_sound = QGVAR(SlingLoadDownExt)};
    {
        ropeUnwind [_x, _speed, _length, _relative];
        private _dummy = "#particlesource" createVehicleLocal ropeEndPosition _x #0;
        _dummy attachTo [_vehicle, _vehicle worldToModelVisual ropeEndPosition _x #0];
        [_vehicle, _dummy, _x, _sound] spawn {
            params [["_vehicle", objNull], ["_dummy", objNull], ["_rope", objNull], ["_sound", ""]];
            if (isNull _vehicle || isNull _dummy || isNull _rope) exitWith {};
            while {!ropeUnwound _rope && alive _vehicle && alive _rope} do {
                _dummy say3D _sound;
                sleep 1;
            };
            deleteVehicle _dummy;
        };
    } forEach _ropes;
};

FUNC(Shorten_Ropes_Action_Check) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Shorten_Ropes_Action_Check)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if ([getConnectedUAV _unit, _unit] call FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Shorten_Ropes_Action_Check)) EXIT 1, can release: ", [getConnectedUAV _unit, _unit] call FUNC(Can_Release_Cargo)];
        [getConnectedUAV _unit] call FUNC(Can_Shorten_Ropes)
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call FUNC(Is_Unit_Authorized)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Shorten_Ropes_Action_Check)) EXIT 2, can release: ", [_vehicle, _unit] call FUNC(Can_Release_Cargo)];
        [_vehicle] call FUNC(Can_Shorten_Ropes)
    };
    false
};

FUNC(Can_Shorten_Ropes) = {
    params ["_vehicle"];
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    if !([_vehicle] call FUNC(Is_Supported_Vehicle)) exitWith {false};
    if (count (_vehicle getVariable [QGVAR(Ropes), []]) == 0) exitWith {false};
    if (count ([_vehicle, true] call FUNC(Get_Active_Ropes)) == 0) exitWith {false};
    true
};

FUNC(Shorten_Ropes_Action) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Shorten_Ropes_Action)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !([_vehicle] call FUNC(Can_Shorten_Ropes)) exitWith {false};
    private _activeRopes = [_vehicle, true] call FUNC(Get_Active_Ropes);
    if (count _activeRopes == 1) exitWith {
        private _ropeLength = [_vehicle, _unit, _activeRopes#0#0] call FUNC(Shorten_Ropes);
        if (_ropeLength >= GVAR(MinRopeLength)) exitWith {
            private _messages = [[format [LLSTRING(ROPES_SHORTENED_TO), _ropeLength]]];
            if (_ropeLength == GVAR(MinRopeLength)) then {
                _messages set [0, [format ["%1%2", _messages#0#0, " (min)"]]]
            };
            _messages pushBack true;
            _messages call CBA_fnc_notify;
        };
        [[format [LLSTRING(ALREADY_MIN_LENGTH), GVAR(MinRopeLength)]], true] call CBA_fnc_notify;
    };
    GVAR(actionContext) = ACTION_CONTEXT_SHORTEN;
    [LLSTRING(SHORTEN), QFUNC(Shorten_Ropes_Index_Action), _activeRopes, LLSTRING(ROPE), _vehicle, _unit] call FUNC(Show_Select_Ropes_Menu);
    private _shortenedRopes = _vehicle getVariable [QGVAR(Ropes_Change), []];
    if (count _shortenedRopes > 0) then {
        private _messages = [[LLSTRING(ROPES_SHORTENED)]];
        private ["_shortenedRopesIndex"];
        {
            if (_x #1 >= GVAR(MinRopeLength)) then {
                _shortenedRopesIndex = _x#0;
                _messages pushBack [format [LLSTRING(ROPES_SHORTENED_TO_IND), (_activeRopes select {_x #0 == _shortenedRopesIndex}) #0 #1, _x #1]];
                if (_x #1 == GVAR(MinRopeLength)) then {
                    private _messageIndex = (count _messages) - 1;
                    _messages set [_messageIndex, [format ["%1%2", _messages#_messageIndex#0, " (min)"]]];
                };
            } else {
                _messages pushBack [format [LLSTRING(ALREADY_MIN_LENGTH), GVAR(MinRopeLength)]];
            };
        } forEach _shortenedRopes;
        _messages pushBack true;
        _messages call CBA_fnc_notify;
        _vehicle setVariable [QGVAR(Ropes_Change), nil];
    };
};

FUNC(Shorten_Ropes_Index_Action) = {
    params [["_ropesIndex", 0], ["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && !isNull _vehicle && [_vehicle] call FUNC(Can_Shorten_Ropes)) then {
        private _ropeLength = [_vehicle, _unit, _ropesIndex] call FUNC(Shorten_Ropes);
        [_vehicle, _ropeLength, _ropesIndex] call FUNC(Save_Rope_Change);
    };
};

FUNC(Shorten_Ropes) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {[QGVAR(Shorten_Ropes), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopes = [_vehicle, _ropesIndex] call FUNC(Get_Ropes);
    private _ropeLength = -1;
    if (count _existingRopes > 0) then {
        _ropeLength = ropeLength (_existingRopes #0);
        if (_ropeLength <= GVAR(MinRopeLength)) exitWith {
            if (GVAR(MinRopeLengthDropCargo)) then {
                [_vehicle, _unit, _ropesIndex] call FUNC(Release_Cargo);
            };
            _ropeLength = GVAR(MinRopeLength) - 1;
        };
        private _unwindLength = GVAR(ExtendShortenRopeLength);
        if (_ropeLength - _unwindLength < 5) then {
            _unwindLength = _ropeLength - 5;
        };
        if (_ropeLength < 10) then {_unwindLength = 1};
        [_vehicle, _existingRopes, GVAR(RopeUnwindSpeed), -_unwindLength] spawn FUNC(Unwind_Ropes);
        _ropeLength = _ropeLength - _unwindLength;
    };
    _ropeLength
};

FUNC(Release_Cargo_Action_Check) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Release_Cargo_Action_Check)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if ([getConnectedUAV _unit, _unit] call FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Release_Cargo_Action_Check)) EXIT 1, can release: ", [getConnectedUAV _unit, _unit] call FUNC(Can_Release_Cargo)];
        [getConnectedUAV _unit, _unit] call FUNC(Can_Release_Cargo)
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call FUNC(Is_Unit_Authorized)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Release_Cargo_Action_Check)) EXIT 2, can release: ", [_vehicle, _unit] call FUNC(Can_Release_Cargo)];
        [_vehicle, _unit] call FUNC(Can_Release_Cargo)
    };
    false
};

FUNC(Can_Release_Cargo) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !([_vehicle] call FUNC(Is_Supported_Vehicle)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Release_Cargo)) EXIT 1"];
        false
    };
    _existingRopes = _vehicle getVariable [QGVAR(Ropes), []];
    if (count _existingRopes == 0) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Release_Cargo)) EXIT 2"];
        false
    };
    private _activeRopes = [_vehicle, _unit] call FUNC(Get_Active_Ropes_With_Cargo);
    if (count _activeRopes == 0) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Release_Cargo)) EXIT 3"];
        false
    };
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Release_Cargo)) _existingRopes: ", _existingRopes];
    true
};

FUNC(Release_Cargo_Action) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Release_Cargo_Action)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !([_vehicle, _unit] call FUNC(Can_Release_Cargo)) exitWith {false};
    private _activeRopes = [_vehicle, _unit] call FUNC(Get_Active_Ropes_With_Cargo);
    if (count _activeRopes == 1) exitWith {
        [_vehicle, _unit, (_activeRopes#0)#0] call FUNC(Release_Cargo)
    };
    GVAR(actionContext) = ACTION_CONTEXT_RELEASE;
    [LLSTRING(RELEASE), QFUNC(Release_Cargo_Index_Action), _activeRopes, LLSTRING(CARGO), _vehicle, _unit] call FUNC(Show_Select_Ropes_Menu);
};

FUNC(Release_Cargo_Index_Action) = {
    params [["_ropesIndex", 0], ["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Release_Cargo_Index_Action)) _vehicle: ", _vehicle, ", _unit: ", _unit, ", _ropesIndex: ", _ropesIndex];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && [_vehicle, _unit] call FUNC(Can_Release_Cargo)) then {
        [_vehicle, _unit, _ropesIndex] call FUNC(Release_Cargo);
    };
};

FUNC(Release_Cargo) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !(local _vehicle) exitWith {[QGVAR(Release_Cargo), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopesAndCargo = [_vehicle, _ropesIndex] call FUNC(Get_Ropes_And_Cargo);
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Release_Cargo)) _vehicle: ", _vehicle, ", _unit: ", _unit, ", _existingRopesAndCargo: ", _existingRopesAndCargo];
    private _existingRopes = _existingRopesAndCargo #0;
    private _existingCargo = _existingRopesAndCargo #1;
    {
        _existingCargo ropeDetach _x;
    } forEach _existingRopes;
    private _allCargo = _vehicle getVariable [QGVAR(Cargo), []];
    _allCargo set [_ropesIndex, objNull];
    _vehicle setVariable [QGVAR(Cargo), _allCargo, true];
    _this call FUNC(Retract_Ropes);
};

FUNC(Get_Display_Name) = {
    params [["_object", objNull]];
    if (isNull _object || !alive _object) exitWith {""};
    private ["_type"];
    if ((typeName _object) == "OBJECT") then {
        _type = (typeof _object);
    } else {
        _type = _object;
    };
    private _cfg_type = "CfgVehicles";
    {
        if (isClass(configFile >> _x >> _type)) exitWith {_cfg_type = _x};
    } forEach ["CfgMagazines", "CfgWeapons", "CfgGlasses"];
    private _return = getText (configFile >> _cfg_type >> _type >> "displayName");
    _return
};

FUNC(Retract_Ropes_Action_Check) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes_Action_Check)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if ([getConnectedUAV _unit, _unit] call FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes_Action_Check)) EXIT 1"];
        [getConnectedUAV _unit, _unit] call FUNC(Can_Retract_Ropes)
    };
    if (vehicle _unit == _unit) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes_Action_Check)) EXIT 2"];
        [cursorObject, _unit, true] call FUNC(Can_Retract_Ropes)
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call FUNC(Is_Unit_Authorized)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes_Action_Check)) EXIT 3"];
        [_vehicle, _unit] call FUNC(Can_Retract_Ropes)
    };
    false
};

FUNC(Can_Retract_Ropes) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_distanceCheck", false]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_distanceCheck && _unit distance _vehicle > GVAR(MaxDeployRetractDistance) + (sizeOf typeOf _vehicle / 10 max 1)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Retract_Ropes)) EXIT 1"];
        false
    };
    if !([_vehicle] call FUNC(Is_Supported_Vehicle)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Retract_Ropes)) EXIT 2"];
        false
    };
    private _existingRopes = _vehicle getVariable [QGVAR(Ropes), []];
    if (count _existingRopes == 0) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Retract_Ropes)) EXIT 3"];
        false
    };
    private _activeRopes = [_vehicle] call FUNC(Get_Active_Ropes_Without_Cargo);
    if (count _activeRopes == 0) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Retract_Ropes)) EXIT 5"];
        false
    };
    true;
};

FUNC(Retract_Ropes_Action) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes_Action)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if (isNull _vehicle || isNull _unit) exitWith {};
    private _activeRopes = [_vehicle] call FUNC(Get_Active_Ropes_Without_Cargo);
    if (count _activeRopes == 1) exitWith {        
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes_Action)) inactive ropes: ", [_vehicle] call FUNC(Get_Active_Ropes), ", existing ropes: ", _vehicle getVariable [QGVAR(Ropes), []]];
        [_vehicle, _unit, (_activeRopes #0) #0] call FUNC(Retract_Ropes);
        [[LLSTRING(ROPES_RETRACTED)], true] call CBA_fnc_notify;
    };
    GVAR(actionContext) = ACTION_CONTEXT_RETRACT;
    [LLSTRING(RETRACT), QFUNC(Retract_Ropes_Index_Action), _activeRopes, LLSTRING(ROPE), _vehicle, _unit] call FUNC(Show_Select_Ropes_Menu);
};

FUNC(Retract_Ropes_Index_Action) = {
    params ["_ropesIndex", ["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Retract_Ropes_Index_Action)) _unit: ", _unit, ", _vehicle: ", _vehicle, ", _ropesIndex: ", _ropesIndex];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0) then {
        [_vehicle, _unit, _ropesIndex] call FUNC(Retract_Ropes);
    };
};

FUNC(Retract_Ropes) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !(local _vehicle) exitWith {[QGVAR(Retract_Ropes), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopesAndCargo = [_vehicle, _ropesIndex] call FUNC(Get_Ropes_And_Cargo);
    private _existingRopes = _existingRopesAndCargo #0;
    private _existingCargo = _existingRopesAndCargo #1;
    private _cargoArray = ropeAttachedObjects _vehicle;
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes)) _vehicle: ", _vehicle, "    _cargoArray: ", _cargoArray];
    if (count _cargoArray > 0) then {
        private _helper = (_cargoArray select {_x getVariable [QGVAR(Ropes_Pick_Up_Helper), false]}) #0;
        if (isNil {_helper}) exitWith {};
        private _ropeHolder = attachedTo _helper;
        if (!isNull _ropeHolder) then {_unit = _ropeHolder};
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Retract_Ropes)) _helper: ", _helper, "    _ropeHolder: ", _ropeHolder];
    };
    if (isNull _existingCargo) then {
        [_vehicle, _unit, _ropesIndex] call FUNC(Drop_Ropes);
        // diag_log formatText [
        //     "%1%2%3%4%5%6%7%8%9%10%11%12", time,
        //     "s  (FUNC(Retract_Ropes)) _existingRopes: ", _existingRopes,
        //     // ", Ropes_Without_Cargo: ", [_vehicle] call FUNC(Get_Active_Ropes_Without_Cargo),
        //     // ", _allRopes: ", _vehicle getVariable [QGVAR(Ropes), []],
        //     ", _activeRopes: ", [_vehicle, true] call FUNC(Get_Active_Ropes),
        //     ", _inactiveRopes: ", [_vehicle] call FUNC(Get_Active_Ropes)
        // ];
        [_vehicle, _existingRopes, GVAR(RopeUnwindSpeed), 0, false] spawn FUNC(Unwind_Ropes);
        {
            [_vehicle, _x] spawn {
                params [["_vehicle", objNull], ["_rope", objNull]];
                if (isNull _vehicle || isNull _rope) exitWith {false};
                sleep 1;
                if (isNull _rope || isNull _vehicle) exitWith {};
                private _future = time + 20 + 100 / GVAR(RopeUnwindSpeed);
                while {!ropeUnwound _rope && alive _vehicle && time < _future} do {sleep 1};
                // diag_log formatText [
                //     "%1%2%3%4%5%6%7%8%9%10%11%12", time,
                //     "s  (FUNC(Retract_Ropes)) Rope destroyed! !ropeUnwound _rope: ", !ropeUnwound _rope,
                //     ", vehicle alive: ", alive _vehicle,
                //     ", time < _future: ", time < _future
                // ];
                GVAR(allRopes) deleteAt (GVAR(allRopes) find _rope);
                GVAR(allRopes) = GVAR(allRopes) - [objNull];
                publicVariable QGVAR(allRopes);
                ropeDestroy _rope;
            };
        } forEach _existingRopes;
        private _allRopes = _vehicle getVariable [QGVAR(Ropes), []];
        _allRopes set [_ropesIndex, []];
        _vehicle setVariable [QGVAR(Ropes), _allRopes, true];
    };
    private _activeRopes = [_vehicle, true] call FUNC(Get_Active_Ropes);
    if (count _activeRopes == 0) then {
        _vehicle setVariable [QGVAR(Ropes), nil, true];
    };
};

FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit) = {
    params [["_UAV", objNull], ["_unit", objNull]];
    if (isNull _UAV || isNull _unit) exitWith {false};
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit)) _UAV: ", _UAV, "    _unit: ", _unit];
    if (UAVControl _UAV #0 == _unit && (UAVControl _UAV #1 == "GUNNER" || UAVControl _UAV #1 == "DRIVER")) exitWith {
        // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit)) EXIT 1: unit is UAV gunner or driver"];
        true
    };
    false
};

FUNC(Deploy_Ropes_Action_Check) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Deploy_Ropes_Action_Check)) _vehicle: ", _vehicle, "    _unit: ", _unit];
    if ([getConnectedUAV _unit, _unit] call FUNC(Vehicle_Is_UAV_And_Currently_Operatied_By_Unit)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Deploy_Ropes_Action_Check)) EXIT 1"];
        [getConnectedUAV _unit, _unit] call FUNC(Can_Deploy_Ropes)
    };
    if (vehicle _unit == _unit) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Deploy_Ropes_Action_Check)) EXIT 2"];
        [cursorObject, _unit, true] call FUNC(Can_Deploy_Ropes)
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call FUNC(Is_Unit_Authorized)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Deploy_Ropes_Action_Check)) EXIT 3"];
        [_vehicle, _unit] call FUNC(Can_Deploy_Ropes)
    };

    false
};

FUNC(Can_Deploy_Ropes) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_distanceCheck", false]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if (_distanceCheck && _unit distance _vehicle > GVAR(MaxDeployRetractDistance) + (sizeOf typeOf _vehicle / 10 max 1)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Deploy_Ropes)) EXIT 1"];
        false
    };
    if !([_vehicle] call FUNC(Is_Supported_Vehicle)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Deploy_Ropes)) EXIT 2"];
        false
    };
    private _existingVehicle = _unit getVariable [QGVAR(Ropes_Vehicle), []];
    if (count _existingVehicle > 0) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Deploy_Ropes)) EXIT 3"];
        false
    };
    if (getPos _vehicle #2 > GVAR(MaxRopeDeployHeight)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Deploy_Ropes)) EXIT 4"];
        false
    };
    _existingRopes = _vehicle getVariable [QGVAR(Ropes), []];
    if (count _existingRopes == 0) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Deploy_Ropes)) EXIT 5"];
        true
    };
    private _activeRopes = [_vehicle, true] call FUNC(Get_Active_Ropes);
    if (count _existingRopes > 0 && (count _existingRopes) == (count _activeRopes)) exitWith {
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Can_Deploy_Ropes)) EXIT 6"];
        false
    };
    true
};

FUNC(Deploy_Ropes_Action) = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Deploy_Ropes_Action)) _this: ", _this];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (locked _vehicle > 1 && !(missionNamespace getVariable [QGVAR(LOCKED_VEHICLES_ENABLED), false])) exitWith {
        [[LLSTRING(CANNOT_DEPLOY)], true] call CBA_fnc_notify;
    };
    private _inactiveRopes = [_vehicle] call FUNC(Get_Active_Ropes);
    
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Deploy_Ropes_Action)) _inactiveRopes: ", _inactiveRopes];
    if (count _inactiveRopes > 0) exitWith {
        if (count _inactiveRopes > 1) then {
            [LLSTRING(DEPLOY), QFUNC(Deploy_Ropes_Index_Action), _inactiveRopes, _vehicle, _unit] call FUNC(Show_Select_Ropes_Menu);
        } else {
            [_vehicle, _unit, (_inactiveRopes #0) #0] call FUNC(Deploy_Ropes_Index);
        };
    };
    private _slingLoadPoints = [_vehicle] call FUNC(Get_Sling_Load_Points);
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9%10", time, "s  (FUNC(Deploy_Ropes_Action)) _slingLoadPoints: ", _slingLoadPoints, ", _unit: ", _unit];
    if (count _slingLoadPoints == 1) exitWith {
        [_vehicle, _unit] call FUNC(Deploy_Ropes);
    };
    // _unit setVariable [QGVAR(Deploy_Count_Vehicle), _vehicle];
    GVAR(Deploy_Ropes_Count_Menu) = [[LLSTRING(ROPES), false]];
    GVAR(Vehicle) = _vehicle;
    GVAR(Unit) = _unit;
    GVAR(Deploy_Ropes_Count_Menu) pushBack [LLSTRING(SINGLE), [0], "", -5, [["expression", QUOTE([ARR_3(1,GVAR(Vehicle),GVAR(Unit))] call FUNC(Deploy_Ropes_Count_Action))]], "1", "1"];
    if (count _slingLoadPoints > 1) then {
        GVAR(Deploy_Ropes_Count_Menu) pushBack [LLSTRING(DOUBLE), [0], "", -5, [["expression", QUOTE([ARR_3(2,GVAR(Vehicle),GVAR(Unit))] call FUNC(Deploy_Ropes_Count_Action))]], "1", "1"];
    };
    if (count _slingLoadPoints > 2) then {
        GVAR(Deploy_Ropes_Count_Menu) pushBack [LLSTRING(TRIPLE), [0], "", -5, [["expression", QUOTE([ARR_3(3,GVAR(Vehicle),GVAR(Unit))] call FUNC(Deploy_Ropes_Count_Action))]], "1", "1"];
    };
    showCommandingMenu "";
    showCommandingMenu QUOTE(#USER:GVAR(Deploy_Ropes_Count_Menu));
};

FUNC(Deploy_Ropes_Index_Action) = {
    params ["_ropesIndex", ["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && !isNull _vehicle && [_vehicle, _unit] call FUNC(Can_Deploy_Ropes)) then {
        [_vehicle, _unit, _ropesIndex] call FUNC(Deploy_Ropes_Index);
    };
};

FUNC(Deploy_Ropes_Count_Action) = {
    params ["_count", ["_vehicle", objNull], ["_unit", objNull]];
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9%10", time, "s  (FUNC(Deploy_Ropes_Count_Action)) _count: ", _count, ", GVAR(ParamMenuUnit): ", GVAR(ParamMenuUnit)];
    if (_count > 0 && !isNull _vehicle && [_vehicle, _unit] call FUNC(Can_Deploy_Ropes)) then {
        [_vehicle, _unit, _count] call FUNC(Deploy_Ropes);
    };
};

FUNC(Deploy_Ropes) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_cargoCount", 1]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !(local _vehicle) exitWith {[QGVAR(Deploy_Ropes), _this, _vehicle] call CBA_fnc_targetEvent;};
    if (!alive _vehicle) exitWith {[_vehicle] call FUNC(Add_Vehicle_Actions)};
    private _existingRopes = _vehicle getVariable [QGVAR(Ropes), []];
    if (count _existingRopes > 0) exitWith {
        [QUGVAR(common,notify), [[LLSTRING(ALREADY)], true], _unit] call CBA_fnc_targetEvent;
    };
    private _slingLoadPoints = [_vehicle] call FUNC(Get_Sling_Load_Points);
    if (count _slingLoadPoints == 0) exitWith {
        [QUGVAR(common,notify), [[LLSTRING(DOESNT_SUPPORT)], true], _unit] call CBA_fnc_targetEvent;
    };
    if (count _slingLoadPoints < _cargoCount) exitWith {
        [QUGVAR(common,notify), [[format [LLSTRING(DOESNT_SUPPORT_X), _cargoCount]], true], _unit] call CBA_fnc_targetEvent;
    };
    private _cargoRopes = [];
    private _cargo = [];
    for "_i" from 0 to (_cargoCount - 1) do {
        _cargoRopes pushBack [];
        _cargo pushBack objNull;
    };
    _vehicle setVariable [QGVAR(Ropes), _cargoRopes, true];
    _vehicle setVariable [QGVAR(Cargo), _cargo, true];
    for "_i" from 0 to (_cargoCount - 1) do    {
        [_vehicle, _unit, _i] call FUNC(Deploy_Ropes_Index);
    };
};

FUNC(Deploy_Ropes_Index) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {[QGVAR(Deploy_Ropes_Index), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopes = [_vehicle, _ropesIndex] call FUNC(Get_Ropes);
    if (count _existingRopes > 0) exitWith {};
    private _existingRopesCount = [_vehicle] call FUNC(Get_Ropes_Count);
    private _slingLoadPoints = [_vehicle] call FUNC(Get_Sling_Load_Points);
    private _cargoRopes = [];
    private ["_rope"];
    for "_i" from 1 to 4 do {
        _rope = ropeCreate [_vehicle, (_slingLoadPoints select (_existingRopesCount - 1)) #_ropesIndex, 0];
        _rope allowDamage false;
        _rope setVariable [QGVAR(Ropes_Vehicle), [_vehicle, _ropesIndex], true]; // memory vehicle and rope index on each rope 
        _cargoRopes pushBack _rope; 
        GVAR(allRopes) pushBack _rope;
    };
    publicVariable QGVAR(allRopes);
    [_vehicle, _cargoRopes, GVAR(RopeUnwindSpeed) + 2, GVAR(InitialDeployRopeLength), false] spawn FUNC(Unwind_Ropes);
    private _allRopes = _vehicle getVariable [QGVAR(Ropes), []];
    _allRopes set [_ropesIndex, _cargoRopes];
    _vehicle setVariable [QGVAR(Ropes), _allRopes, true];
    [_vehicle] spawn FUNC(Rope_Monitor_Vehicle);
    [QUGVAR(common,notify), [[format [localize LLSTRING(ROPES_DEPLOYED), GVAR(InitialDeployRopeLength)]], true], _unit] call CBA_fnc_targetEvent;
};

FUNC(Pickup_Ropes_Action_Check) = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {false};
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Pickup_Ropes_Action_Check)) _target: ", _target, ", _this: ", _this];
    if (vehicle _unit != _unit) exitWith {false};
    if !(isNil{_unit getVariable QGVAR(Ropes_Pick_Up_Helper)}) exitWith {false};
    
    private _ropeHandlingDistance = GVAR(RopeHandlingDistance);
    private _nearRopes = GVAR(allRopes) select {
        alive _x &&
        _unit distance ((ropeEndPosition _x)#1) < _ropeHandlingDistance
    };
    _nearRopes isNotEqualTo []
};

FUNC(Pickup_Ropes_Action) = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {};
    
    private _ropeHandlingDistance = GVAR(RopeHandlingDistance);
    private _nearRopes = GVAR(allRopes) select {
        alive _x &&
        _unit distance ((ropeEndPosition _x)#1) < _ropeHandlingDistance
    } apply {[_unit distance ((ropeEndPosition _x)#1), _x]};
    if (_nearRopes isEqualTo []) exitWith {};

    _nearRopes sort true;
    private _closestRope = _nearRopes#0#1;
    private _vehicle = (_closestRope getVariable QGVAR(Ropes_Vehicle)) #0;
    if (isNull _vehicle) exitWith {};
    if (locked _vehicle > 1 && !(missionNamespace getVariable [QGVAR(LOCKED_VEHICLES_ENABLED), false])) exitWith {
        [[LLSTRING(CANT_PICKUP)], true] call CBA_fnc_notify;
    };
    private _ropesIndex = (_closestRope getVariable QGVAR(Ropes_Vehicle)) #1;
    [_vehicle, _unit, _ropesIndex] call FUNC(Pickup_Ropes);
};

FUNC(Pickup_Ropes) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {[QGVAR(Pickup_Ropes), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopesAndCargo = [_vehicle, _ropesIndex] call FUNC(Get_Ropes_And_Cargo);
    private _existingRopes = _existingRopesAndCargo #0;
    private _existingCargo = _existingRopesAndCargo #1;
    if (!isNull _existingCargo) then {
        {
            _existingCargo ropeDetach _x;
        } forEach _existingRopes;
        private _allCargo = _vehicle getVariable [QGVAR(Cargo), []];
        _allCargo set [_ropesIndex, objNull];
        _vehicle setVariable [QGVAR(Cargo), _allCargo, true];
    };
    private _helper = "Land_Can_V2_F" createVehicle position _unit;
    _helper setVariable [QGVAR(Ropes_Pick_Up_Helper), true, true];
    {
        [_helper, [0, 0, 0], [0, 0, -1]] ropeAttachTo _x;
        _helper attachTo [_unit, [-0.1, 0.1, 0.15], "Pelvis"];
    } forEach _existingRopes;
    hideObjectGlobal _helper;
    _unit setVariable [QGVAR(Ropes_Vehicle), [_vehicle, _ropesIndex], true];
    _unit setVariable [QGVAR(Ropes_Pick_Up_Helper), _helper, true];
};

FUNC(Attach_Ropes_Action_Check) = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {false};

    private _cargo = cursorObject;
    if (isNull _cargo) exitWith {false};

    private _vehicle = (_unit getVariable [QGVAR(Ropes_Vehicle), [objNull, 0]]) #0;
    // private _ropeAttachDistance = GVAR(RopeHandlingDistance);
    // private _ropeAttachDistance = GVAR(RopeHandlingDistance) + (sizeOf typeOf _cargo / 10 max 2);
    private _ropeAttachDistance = GVAR(MaxDeployRetractDistance) + (sizeOf typeOf _cargo / 10 max 1);     
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Attach_Ropes_Action_Check)) check 1"];
    if (vehicle _unit != _unit || _unit distance _cargo > _ropeAttachDistance || _vehicle == _cargo || !alive _cargo) exitWith {false};
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Attach_Ropes_Action_Check)) check 2"];
    if (_vehicle == _cargo getVariable [QGVAR(CarrierVehicle), objNull]) exitWith {false}; // let's not attach another rope from same vehicle to same cargo
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Attach_Ropes_Action_Check)) check 2"];
    [_vehicle, _cargo] call FUNC(Is_Supported_Cargo)
};

FUNC(Attach_Ropes_Action) = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {};
    private _cargo = cursorObject;
    private _vehicle = (_unit getVariable [QGVAR(Ropes_Vehicle), [objNull, 0]]) #0;
    if (locked _cargo > 1 && !(missionNamespace getVariable [QGVAR(LOCKED_VEHICLES_ENABLED), false])) exitWith {
        [[LLSTRING(CANT_ATTACH)], true] call CBA_fnc_notify;
    };
    private _canBeAttached = true;
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Attach_Ropes)) _unit: ", _unit, ", _self: ", _self];
    [_cargo, _unit] call FUNC(Attach_Ropes);
};

FUNC(Attach_Ropes) = {
    params [["_cargo", objNull], ["_unit", objNull]];
    if (isNull _cargo || isNull _unit) exitWith {};
    private _vehicleWithIndex = _unit getVariable [QGVAR(Ropes_Vehicle), [objNull, 0]];
    private _vehicle = _vehicleWithIndex #0;
    if (isNull _vehicle) exitWith {};
    if !(local _vehicle) exitWith {[QGVAR(Attach_Ropes), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _ropes = [_vehicle, _vehicleWithIndex #1] call FUNC(Get_Ropes);
    if (count _ropes != 4) exitWith {};
    private _attachmentPoints = [_cargo] call FUNC(Get_Corner_Points);
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Attach_Ropes)) _attachmentPoints: ", _attachmentPoints, ", _self: ", _self];
    private _ropeLength = (ropeLength (_ropes #0));
    private _objDistance = (_cargo distance _vehicle) + 2;
    if (_objDistance > _ropeLength) exitWith {[QUGVAR(common,notify), [[LLSTRING(TOO_SHORT)], true], _unit] call CBA_fnc_targetEvent;};
    private _ropesIndex = _vehicleWithIndex #1;
    _cargo setVariable [QGVAR(CarrierVehicle), _vehicle, true];
    [_vehicle, _cargo] spawn {
        params [["_vehicle", objNull], ["_cargo", objNull]];
        if (isNull _vehicle || isNull _cargo) exitWith {};
        while {alive _vehicle && alive _cargo && _cargo in ropeAttachedObjects _vehicle} do {
            sleep 1;
        };
        _cargo setVariable [QGVAR(CarrierVehicle), nil, true];
    };
    [_vehicle, _unit, _ropesIndex] call FUNC(Drop_Ropes);
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Attach_Ropes)) _vehicle: ", _vehicle, ", _unit: ", _unit, ", _ropesIndex: ", _ropesIndex];
    for "_i" from 0 to 3 do {
        [_cargo, _attachmentPoints #_i, [0, 0, -1]] ropeAttachTo (_ropes #_i);
    };
    private _allCargo = _vehicle getVariable [QGVAR(Cargo), []];
    _allCargo set [(_vehicleWithIndex #1), _cargo];
    _vehicle setVariable [QGVAR(Cargo), _allCargo, true];
    if (missionNamespace getVariable [QGVAR(HEAVY_LIFTING_ENABLED), true]) then {
        [_vehicle, _cargo, _ropes] spawn FUNC(Rope_Adjust_Mass);
    };
    _unit setVariable [QGVAR(Ropes_Pick_Up_Helper), nil, true];
    _unit setVariable [QGVAR(Ropes_Vehicle), nil, true];
};

FUNC(Drop_Ropes_Action_Check) = {
    params [["_unit", objNull]];
    if (isNull _unit || vehicle _unit != _unit) exitWith {false};

    (_unit getVariable [QGVAR(Ropes_Vehicle), []]) isNotEqualTo []
};

FUNC(Drop_Ropes_Action) = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {false};
    private _vehicleAndIndex = _unit getVariable [QGVAR(Ropes_Vehicle), []];
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Drop_Ropes_Action))    _unit: ", _unit, ", _self: ", _self, ", _vehicleAndIndex: ", _vehicleAndIndex];
    if (count _vehicleAndIndex == 2) then {
        [_vehicleAndIndex #0, _unit, _vehicleAndIndex #1] call FUNC(Drop_Ropes);
    };
};

FUNC(Drop_Ropes) = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {[QGVAR(Drop_Ropes), _this, _vehicle] call CBA_fnc_targetEvent;};
    private _helper = (_unit getVariable [QGVAR(Ropes_Pick_Up_Helper), objNull]);
    // diag_log formatText ["%1%2%3%4%5%6%7%8%9", time, "s  (FUNC(Drop_Ropes))    _unit: ", _unit, ", _self: ", _self, ", _vehicle: ", _vehicle, ", _ropesIndex: ", _ropesIndex];
    if (!isNull _helper) then {
        private _existingRopes = [_vehicle, _ropesIndex] call FUNC(Get_Ropes);
        {
            _helper ropeDetach _x;
        } forEach _existingRopes;
        detach _helper;
        _unit setVariable [QGVAR(Ropes_Vehicle), nil, true];
        deleteVehicle _helper;
    };
    _unit setVariable [QGVAR(Ropes_Pick_Up_Helper), nil, true];
};

FUNC(Is_Supported_Vehicle) = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {false};
    private _isSupported = false;
    {
        if (_vehicle isKindOf _x) exitWith {_isSupported = true};
    } forEach (missionNamespace getVariable [QGVAR(SUPPORTED_VEHICLES_OVERRIDE), GVAR(supportedVehicles)]);
    _isSupported
};

FUNC(Is_Supported_Cargo) = {
    params [["_vehicle", objNull], ["_cargo", objNull]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Is_Supported_Cargo))        _vehicle: ", _vehicle, ", _cargo: ", _cargo];
    if (isNull _vehicle || isNull _cargo) exitWith {false};
    private _canSling = false;
    {
        if (_vehicle isKindOf (_x #0) && _cargo isKindOf (_x #2) && (toUpper (_x #1)) == "CAN_SLING") exitWith {_canSling = true};
    } forEach (missionNamespace getVariable [QGVAR(SLING_RULES_OVERRIDE), GVAR(slingRules)]);
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Is_Supported_Cargo))        _canSling: ", _canSling];
    _canSling
};

FUNC(Switch_Vehicles_Actions) = {
    {
        [_x] call FUNC(Add_Vehicle_Actions);
    } foreach vehicles;
};

FUNC(Add_Vehicle_Actions) = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    if !([_vehicle] call FUNC(Is_Supported_Vehicle)) exitWith {};
    // diag_log formatText ["%1%2%3%4%5%6%7", time, "s  (FUNC(Add_Vehicle_Actions))    _vehicle: ", _vehicle, ", mass: ", getMass _vehicle, ", min: ", GVAR(MinVehicleMass)];
    if (getMass _vehicle < GVAR(MinVehicleMass) || !alive _vehicle) exitWith {
        [_vehicle, [QGVAR(ActionID_Deploy), QGVAR(ActionID_Retract), QGVAR(ActionID_Extend), QGVAR(ActionID_Shorten), QGVAR(ActionID_Release)]] call FUNC(Remove_Actions);
    };
    private _actionID = -1;
    if (isNil{_vehicle getVariable QGVAR(ActionID_Deploy)}) then {
        _actionID = _vehicle addAction [
            LLSTRING(DEPLOY),
            {[_this #0, _this #1] call FUNC(Deploy_Ropes_Action)},
            nil,
            100,
            false,
            true,
            "",
            QUOTE([ARR_2(_target,_this)] call FUNC(Deploy_Ropes_Action_Check))
        ];
        _vehicle setVariable [QGVAR(ActionID_Deploy), _actionID];
    };
    if (isNil{_vehicle getVariable QGVAR(ActionID_Retract)}) then {
        _actionID = _vehicle addAction [
            LLSTRING(RETRACT),
            {[_this #0, _this #1] call FUNC(Retract_Ropes_Action)},
            nil,
            50,
            false,
            true,
            "",
            QUOTE([ARR_2(_target,_this)] call FUNC(Retract_Ropes_Action_Check))
        ];
        _vehicle setVariable [QGVAR(ActionID_Retract), _actionID];
    };
    if (isNil{_vehicle getVariable QGVAR(ActionID_Extend)}) then {
        _actionID = _vehicle addAction [
            LLSTRING(EXTEND),
            {[_this #0, _this #1] call FUNC(Extend_Ropes_Action)},
            nil,
            199,
            false,
            true,
            "",
            QUOTE([ARR_2(_target,_this)] call FUNC(Extend_Ropes_Action_Check))
        ];
        _vehicle setVariable [QGVAR(ActionID_Extend), _actionID];
    };
    if (isNil{_vehicle getVariable QGVAR(ActionID_ExtendTG)}) then {
        _actionID = _vehicle addAction [
            LLSTRING(EXTEND_TG),
            {[_this #0, _this #1, true] call FUNC(Extend_Ropes_Action)},
            nil,
            198,
            false,
            true,
            "",
            QUOTE([ARR_3(_target,_this,true)] call FUNC(Extend_Ropes_Action_Check))
        ];
        _vehicle setVariable [QGVAR(ActionID_ExtendTG), _actionID];
    };
    if (isNil{_vehicle getVariable QGVAR(ActionID_Shorten)}) then {
        _actionID = _vehicle addAction [
            LLSTRING(SHORTEN),
            {[_this #0, _this #1] call FUNC(Shorten_Ropes_Action)},
            nil,
            197,
            false,
            true,
            "",
            QUOTE([ARR_2(_target,_this)] call FUNC(Shorten_Ropes_Action_Check))
        ];
        _vehicle setVariable [QGVAR(ActionID_Shorten), _actionID];
    };
    if (isNil{_vehicle getVariable QGVAR(ActionID_Release)}) then {
        _actionID = _vehicle addAction [
            format ["<t color='#FF0000'>%1</t>", LLSTRING(RELEASE)],
            {[_this#0, _this#1] call FUNC(Release_Cargo_Action)},
            nil,
            195,
            false,
            true,
            "",
            QUOTE([ARR_2(_target,_this)] call FUNC(Release_Cargo_Action_Check))
        ];
        _vehicle setVariable [QGVAR(ActionID_Release), _actionID];
    };
};

FUNC(addActions) = {
    params ["_unit"];

    private _actionID = -1;
    if (isNil {_unit getVariable QGVAR(ActionID_Pickup)}) then {
        _actionID = _unit addAction [
            LLSTRING(PICKUP),
            {[_this#0] call FUNC(Pickup_Ropes_Action)},
            nil,
            250,
            true,
            true,
            "",
            QUOTE([_this] call FUNC(Pickup_Ropes_Action_Check))
        ];
        _unit setVariable [QGVAR(ActionID_Pickup), _actionID];
    };
    if (isNil {_unit getVariable QGVAR(ActionID_Attach)}) then {
        _actionID = _unit addAction [
            LLSTRING(ATTACH) localize,
            {[_this#0] call FUNC(Attach_Ropes_Action)},
            nil,
            230,
            true,
            true,
            "",
            QUOTE([_this] call FUNC(Attach_Ropes_Action_Check))
        ];
        _unit setVariable [QGVAR(ActionID_Attach), _actionID];
    };
    if (isNil {_unit getVariable QGVAR(ActionID_Drop)}) then {
        _actionID = _unit addAction [
            LLSTRING(DROP) localize,
            {[_this#0] call FUNC(Drop_Ropes_Action)},
            nil,
            225,
            true,
            true,
            "",
            QUOTE([_this] call FUNC(Drop_Ropes_Action_Check))
        ];
        _unit setVariable [QGVAR(ActionID_Drop), _actionID];
    };
};

FUNC(Remove_Actions) = {
    params [["_object", objNull], ["_actions", []]];
    // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Remove_Actions)) _object: ", _object, "    _actions: ", _actions];
    if (isNull _object || count _actions == 0) exitWith {};
    private ["_actionID"];
    {
        _actionID = _object getVariable [_x, -1];
        // diag_log formatText ["%1%2%3%4%5", time, "s  (FUNC(Remove_Actions)) removing _actionID: ", _actionID];
        if (_actionID > -1) then {
            _object removeAction _actionID;
            _object setVariable [_x, nil];
        };
    } forEach _actions;
};

if (hasInterface) then {
    ["Air", "init", {_this call FUNC(Add_Vehicle_Actions)}, true] call CBA_fnc_addClassEventHandler;
    
    ["CAManBase", "respawn", {call FUNC(addActions)}, true, [], true] call CBA_fnc_addClassEventHandler;
    [player] call FUNC(addActions);
};
