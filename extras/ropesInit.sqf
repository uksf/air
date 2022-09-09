uksf_air_slingloading_fnc_Get_Sling_Load_Points = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _slingLoadPointsArray = [];
    private _cornerPoints = [_vehicle] call uksf_air_slingloading_fnc_Get_Corner_Points;
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
            
        };
    } forEach uksf_air_slingloading_classLoadPointOffsets;
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

uksf_air_slingloading_fnc_Get_Corner_Points = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _widthFactor    = 0.5;
    private _lengthFactor    = 0.5;
    if (_vehicle isKindOf "Air") then {                     
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

uksf_air_slingloading_fnc_Rope_Get_Lift_Capability = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _slingLoadMaxCargoMass = getNumber (configOf _vehicle >> "slingLoadMaxCargoMass");
    if (_slingLoadMaxCargoMass <= 0) then {
        _slingLoadMaxCargoMass = uksf_air_slingloading_DefaultLiftableMass;
    };
    {
        if (_vehicle isKindOf _x #0) exitWith {_slingLoadMaxCargoMass = _x #1};
    } forEach uksf_air_slingloading_liftCapacity;
    _slingLoadMaxCargoMass;
};

uksf_air_slingloading_fnc_Rope_Set_Mass = {
    params [["_cargo", objNull], ["_mass", 0]];
    if (isNull _cargo || _mass == 0) exitWith {};
    _cargo setMass _mass;
};

    
    
    
    
    
    
    
    
        
uksf_air_slingloading_fnc_Rope_Adjust_Mass = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_cargo", objNull], ["_ropes", []]];
    if (isNull _vehicle || isNull _cargo) exitWith {};
    private _lift = [_vehicle] call uksf_air_slingloading_fnc_Rope_Get_Lift_Capability;
    private _maxLiftableMass = _lift * uksf_air_slingloading_MaxLiftableMassFactor;
    private _originalMass = getMass _cargo;
    private _heavyLiftMinLift = missionNamespace getVariable ["uksf_air_slingloading_HEAVY_LIFTING_MIN_LIFT_OVERRIDE", 5000];
    if (_originalMass >= _lift * 0.8 && _lift >= _heavyLiftMinLift && _originalMass <= _maxLiftableMass) then {
        ["uksf_air_slingloading_Rope_Set_Mass", [_cargo, _originalMass], _cargo] call CBA_fnc_targetEvent;
        [_vehicle, _cargo, _originalMass, _lift, _maxLiftableMass] spawn {
            params [["_vehicle", objNull], ["_cargo", objNull], ["_originalMass", 0], ["_lift", 0], ["_maxLiftableMass", 0]];
            if (isNull _vehicle || isNull _cargo || _originalMass == 0 || _lift == 0 || _maxLiftableMass == 0) exitWith {};
            ["uksf_air_slingloading_Rope_Set_Mass", [_cargo, (_lift * 0.8 + ((_originalMass / _maxLiftableMass) * (_lift * 0.2)))], _cargo] call CBA_fnc_targetEvent;
        };
    };
    sleep 0.3;
    [_vehicle, _unit, _originalMass, _lift] spawn {
        params [["_vehicle", objNull], ["_unit", objNull], ["_originalMass", 0], ["_lift", 0]];
        if (isNull _vehicle || _originalMass == 0 || _lift == 0) exitWith {};
        sleep 0.2;
        private _messages = [[localize "STR_uksf_air_slingloading_SLING_MASS"]];
        private _totalSlingMass = 0;
        {
            _totalSlingMass = _totalSlingMass + getMass _x;
        } forEach ropeAttachedObjects _vehicle;
        if (_totalSlingMass > _lift) then {
            _messages pushback [localize "STR_uksf_air_slingloading_OVERLOAD"];
            _messages pushback [format [localize "STR_uksf_air_slingloading_OVERLOAD_MASS", (_totalSlingMass / 1000) toFixed 2, (_lift / 1000) toFixed 2]];
        } else {
            _messages pushback [format [localize "STR_uksf_air_slingloading_SLING_MASS_REMAINING", ((_lift - _totalSlingMass) / 1000) toFixed 2, (_lift / 1000) toFixed 2]];
        };
        _messages pushBack true;
        ["uksf_common_notify", _messages, _unit] call CBA_fnc_targetEvent;
    };
};



uksf_air_slingloading_fnc_Get_Active_Ropes = {
    params [["_vehicle", objNull], ["_active", false]];
    
    if (isNull _vehicle) exitWith {false};
    private _activeRopes = [];
    private _existingRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    private _ropeLabelSets = [
        [localize "STR_uksf_air_slingloading_CENTER"],
        [localize "STR_uksf_air_slingloading_FRONT", localize "STR_uksf_air_slingloading_REAR"],
        [localize "STR_uksf_air_slingloading_FRONT", localize "STR_uksf_air_slingloading_CENTER", localize "STR_uksf_air_slingloading_REAR"]
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

uksf_air_slingloading_fnc_Get_Active_Ropes_With_Cargo = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    private _activeRopesWithCargo = [];
    private _existingCargo = _vehicle getVariable ["uksf_air_slingloading_Cargo", []];
    private _activeRopes = [_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes;
    private ["_cargo"];
    {
        _cargo = _existingCargo select (_x #0);
        if (!isNull _cargo) then {
            if (!alive _cargo || ropeAttachedTo _cargo != _vehicle) exitWith {
                [_vehicle, _unit, _foreachindex] call uksf_air_slingloading_fnc_Release_Cargo; 
            };
            _activeRopesWithCargo pushBack _x;
        };
    } forEach _activeRopes;
    _activeRopesWithCargo;
};

uksf_air_slingloading_fnc_Get_Active_Ropes_Without_Cargo = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    private _activeRopesWithoutCargo = [];
    private _existingCargo = _vehicle getVariable ["uksf_air_slingloading_Cargo", []];
    private _activeRopes = [_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes;
    
    private ["_cargo"];
    {
        _cargo = _existingCargo select (_x #0);
        if (isNull _cargo) then {
            _activeRopesWithoutCargo pushBack _x;
        };
    } forEach _activeRopes;
    
    _activeRopesWithoutCargo;
};

uksf_air_slingloading_fnc_Get_Ropes = {
    params [["_vehicle", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    private _selectedRopes = [];
    private _allRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    
    if (count _allRopes > _ropesIndex) then {
        _selectedRopes = _allRopes #_ropesIndex;
    };
    _selectedRopes;
};

uksf_air_slingloading_fnc_Get_Ropes_Count = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    count (_vehicle getVariable ["uksf_air_slingloading_Ropes", []]);
};

uksf_air_slingloading_fnc_Get_Cargo = {
    params [["_vehicle", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    private _selectedCargo = objNull;
    private _allCargo = _vehicle getVariable ["uksf_air_slingloading_Cargo", []];
    if (count _allCargo > _ropesIndex) then {
        _selectedCargo = _allCargo #_ropesIndex;
    };
    _selectedCargo;
};

uksf_air_slingloading_fnc_Get_Ropes_And_Cargo = {
    params [["_vehicle", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    private _selectedCargo = (_this call uksf_air_slingloading_fnc_Get_Cargo);
    private _selectedRopes = (_this call uksf_air_slingloading_fnc_Get_Ropes);
    [_selectedRopes, _selectedCargo];
};

uksf_air_slingloading_fnc_Extend_Ropes_Action_Check = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if ([getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Vehicle_Is_UAV_And_Currently_Operatied_By_Unit) exitWith {
        
        [getConnectedUAV _unit, _toGround] call uksf_air_slingloading_fnc_Can_Extend_Ropes
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call uksf_air_slingloading_fnc_Is_Unit_Authorized) exitWith {
        
        [_vehicle, _toGround] call uksf_air_slingloading_fnc_Can_Extend_Ropes
    };
    false
};

uksf_air_slingloading_fnc_Is_Unit_Authorized = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if (driver _vehicle == _unit || gunner _vehicle == _unit) exitWith {true};
    private _turrets = configOf _vehicle >> "turrets";
    private _isTurret = false;
    for "_i" from 0 to (count _turrets - 1) do {
        if ((_vehicle turretUnit [_i]) == _unit) exitWith {_isTurret = true};
    };
    _isTurret
};

uksf_air_slingloading_fnc_Can_Extend_Ropes = {
    params [["_vehicle", objNull], ["_toGround", false]];
    if (isNull _vehicle) exitWith {false};
    if !([_vehicle] call uksf_air_slingloading_fnc_Is_Supported_Vehicle) exitWith {false};
    private _allRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    if (count _allRopes == 0) exitWith {false};
    if (count ([_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes) == 0) exitWith {false};
    private _exit = false;
    if (_toGround) then {
        if (ropeEndPosition (_allRopes #0 #0) #1 #2 < uksf_air_slingloading_ExtendShortenRopeLength) exitWith {_exit = true};
        private _vehicleHeight = getPos _vehicle #2;
        if (_vehicleHeight < uksf_air_slingloading_ExtendShortenRopeLength || _vehicleHeight > uksf_air_slingloading_MaxRopeLength) then {_exit = true};
    };
    
    if (_exit) exitWith {false};
    true;
};

uksf_air_slingloading_fnc_Extend_Ropes_Action = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    
    if (isNull _vehicle || isNull _unit) exitWith {};
    private _activeRopes = [_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes;
    private _canReleaseCargo = false;
    if (_toGround) then {
        _canReleaseCargo = [_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Release_Cargo;
    };
    if (count _activeRopes == 1) exitWith {
        private _ropeLength = [_vehicle, _activeRopes #0 #0, _toGround] call uksf_air_slingloading_fnc_Extend_Ropes;
        if (_ropeLength <= uksf_air_slingloading_MaxRopeLength) exitWith {
            private _messages = [[format [localize "STR_uksf_air_slingloading_ROPES_EXTENDED_TO", _ropeLength]]];
            if (_toGround) then {_messages set [0, [format [localize "STR_uksf_air_slingloading_ROPES_EXTENDED_TO_G", _ropeLength]]]};
            if (_ropeLength == uksf_air_slingloading_MaxRopeLength) then {
                _messages set [0, [format ["%1%2", _messages#0#0, " (max)"]]]
            };
            _messages pushBack true;
            _messages call CBA_fnc_notify;
            
            if (_toGround && _canReleaseCargo) then {
                private _rope = (_vehicle getVariable "uksf_air_slingloading_Ropes") #0 #0;
                private _cargo = (_vehicle getVariable "uksf_air_slingloading_Cargo") #0;
                [_vehicle, _unit, _rope, _ropeLength, _cargo] spawn uksf_air_slingloading_fnc_Release_Cargo_Near_Ground;
            };
        };
        [[format [localize "STR_uksf_air_slingloading_ALREADY_MAX_LENGTH", uksf_air_slingloading_MaxRopeLength]], true] call CBA_fnc_notify;
    };
    uksf_air_slingloading_actionContext = ["uksf_air_slingloading_extend", "uksf_air_slingloading_extendToGround"] select _toGround;
    [localize "STR_uksf_air_slingloading_EXTEND", "uksf_air_slingloading_fnc_Extend_Ropes_Index_Action", _activeRopes, localize "STR_uksf_air_slingloading_ROPE", _vehicle, _unit, _toGround] call uksf_air_slingloading_fnc_Show_Select_Ropes_Menu;
    private _extendedRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes_Change", []];
    
    if (count _extendedRopes == 0) exitWith {};
    private ["_extendedRopeIndex", "_activeCargoRopes"];
    private _messages = [[localize "STR_uksf_air_slingloading_ROPES_EXTENDED"]];
    if (_toGround) then {
        _messages set [0, [format [localize "STR_uksf_air_slingloading_ROPES_EXTENDED_TG", _messages#0#0]]];
        _activeCargoRopes = [_vehicle, _unit] call uksf_air_slingloading_fnc_Get_Active_Ropes_With_Cargo;
    };
    {
        if (_x #1 <= uksf_air_slingloading_MaxRopeLength) then {
            _extendedRopeIndex = _x #0;
            _messages pushBack [format [localize "STR_uksf_air_slingloading_ROPES_EXTENDED_TO_IND", (_activeRopes select {_x #0 == _extendedRopeIndex}) #0 #1, _x #1]];
            if (_x #1 == uksf_air_slingloading_MaxRopeLength) then {
                _messages set [1, [format ["%1%2", _messages#1#0, " (max)"]]];
            };
            
            
            
            
            
            if (_toGround && _canReleaseCargo) then {
                private _rope = (_vehicle getVariable "uksf_air_slingloading_Ropes") #_extendedRopeIndex #0;
                private _cargo = (_vehicle getVariable "uksf_air_slingloading_Cargo") #_extendedRopeIndex;
                [_vehicle, _unit, _rope, _x #1, _cargo, _extendedRopeIndex] spawn uksf_air_slingloading_fnc_Release_Cargo_Near_Ground;
            };
        } else {
            _messages pushBack [format [localize "STR_uksf_air_slingloading_ALREADY_MAX_LENGTH", uksf_air_slingloading_MaxRopeLength]];
        };
    } forEach _extendedRopes;
    _messages pushBack true;
    _messages call CBA_fnc_notify;
    _vehicle setVariable ["uksf_air_slingloading_Ropes_Change", nil];
};

uksf_air_slingloading_fnc_Release_Cargo_Near_Ground = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_rope", objNull], ["_ropeLength", 0], ["_cargo", objNull], ["_ropesIndex", 0]];
    
    
    
    
    
    
    
    
    if (isNull _vehicle || isNull _unit || isNull _rope || _ropeLength == 0 || isNull _cargo) exitWith {};
    private _future = time + 20 + 100 / uksf_air_slingloading_RopeUnwindSpeed;
    sleep 1;
    while {
        !ropeUnwound _rope && 
        alive _vehicle &&
        time < _future && 
        ropeLength _rope < _ropeLength &&
        alive _cargo &&
        getPos _cargo #2 > 1
    } do {sleep 1};
    
    
    
    
    
    
    
    
    
    if (!alive _vehicle || (getPos _cargo #2 > 5 && getPosASL _cargo #2 > 5 && alive _cargo)) exitWith {};
    [_ropesIndex, _vehicle, _unit] call uksf_air_slingloading_fnc_Release_Cargo_Index_Action;
};

uksf_air_slingloading_fnc_Show_Select_Ropes_Menu = {
    params ["_title", "_functionName", "_ropesIndexAndLabelArray", ["_ropesLabel", localize "STR_uksf_air_slingloading_ROPE"], ["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    
    if (isNull _vehicle || isNull _unit) exitWith {};
    uksf_air_slingloading_Show_Select_Ropes_Menu_Array = [[_title, false]];
    uksf_air_slingloading_Vehicle = _vehicle;
    uksf_air_slingloading_Unit = _unit;
    uksf_air_slingloading_toGround = _toGround;

    uksf_air_slingloading_Show_Select_Ropes_Menu_Array pushBack [format ["%1 %2", localize "STR_uksf_air_slingloading_ALL", _ropesLabel], [0], "", -5, [["expression", format ["{[_x, uksf_air_slingloading_Vehicle, uksf_air_slingloading_Unit, uksf_air_slingloading_toGround] call %1} forEach [0, 1, 2]", _functionName]]], "1", "1"];
    {
        uksf_air_slingloading_Show_Select_Ropes_Menu_Array pushBack [format ["%1 %2", _x#1, _ropesLabel], [0], "", -5, [["expression", format ["[%1, uksf_air_slingloading_Vehicle, uksf_air_slingloading_Unit, uksf_air_slingloading_toGround] call %2", _x#0, _functionName]]], "1", "1"];
    } forEach _ropesIndexAndLabelArray;
    
    showCommandingMenu "";
    showCommandingMenu "#USER:uksf_air_slingloading_Show_Select_Ropes_Menu_Array";
    waitUntil {commandingMenu == ""};
    uksf_air_slingloading_actionContext = "uksf_air_slingloading_empty";
};

uksf_air_slingloading_fnc_Extend_Ropes_Index_Action = {
    params ["_ropesIndex", ["_vehicle", objNull], ["_unit", objNull], ["_toGround", false]];
    
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && !isNull _vehicle && [_vehicle, _toGround] call uksf_air_slingloading_fnc_Can_Extend_Ropes) then {
        private _ropeLength = [_vehicle, _ropesIndex, _toGround] call uksf_air_slingloading_fnc_Extend_Ropes;
        [_vehicle, _ropeLength, _ropesIndex] call uksf_air_slingloading_fnc_Save_Rope_Change;
    };
};

uksf_air_slingloading_fnc_Save_Rope_Change = {
    params [["_vehicle", objNull], ["_ropeLength", 0], ["_ropesIndex", 0]];
    if (isNull _vehicle) exitWith {};
    
    private _existingRopes = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes;
    if (count _existingRopes == 0 || _ropeLength == 0) exitWith {};
    private _changedRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes_Change", []];
    _changedRopes pushBack [_ropesIndex, _ropeLength];
    _vehicle setVariable ["uksf_air_slingloading_Ropes_Change", _changedRopes];
};

uksf_air_slingloading_fnc_Extend_Ropes = {
    params [["_vehicle", objNull], ["_ropesIndex", 0], ["_toGround", false]];
    if (isNull _vehicle) exitWith {};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Extend_Ropes", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopes = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes;
    if (count _existingRopes == 0) exitWith {0};
    private _ropeLength = ropeLength (_existingRopes #0);
    if (_ropeLength >= uksf_air_slingloading_MaxRopeLength) exitWith {uksf_air_slingloading_MaxRopeLength + 1};
    private _unwindLength = uksf_air_slingloading_ExtendShortenRopeLength;
    if (_toGround) then {
        _unwindLength = ceil((getPos _vehicle #2) - _ropeLength + 5);
        





        private _allCargo = _vehicle getVariable ["uksf_air_slingloading_Cargo", []];
        private _cargo = _allCargo #_ropesIndex;
        if (isNull _cargo) exitWith {};
        _unwindLength = ceil(getPos _cargo #2) + 3;
    };
    if (_ropeLength + _unwindLength > uksf_air_slingloading_MaxRopeLength) then {
        _unwindLength = uksf_air_slingloading_MaxRopeLength - _ropeLength;
    };
    
    
    
    
    
    
    
    
    [_vehicle, _existingRopes, uksf_air_slingloading_RopeUnwindSpeed, _unwindLength] spawn uksf_air_slingloading_fnc_Unwind_Ropes;
    _ropeLength = _ropeLength + _unwindLength;
    _ropeLength
};

uksf_air_slingloading_fnc_Unwind_Ropes = {
    params [["_vehicle", objNull], ["_ropes", []], ["_speed", 3], ["_length", 0], ["_relative", true]];
    
    if (isNull _vehicle) exitWith {};
    private _sound = "uksf_air_slingloading_SlingLoadUpExt";
    if (_length > 0) then {_sound = "uksf_air_slingloading_SlingLoadDownExt"};
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

uksf_air_slingloading_fnc_Shorten_Ropes_Action_Check = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if ([getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Vehicle_Is_UAV_And_Currently_Operatied_By_Unit) exitWith {
        
        [getConnectedUAV _unit] call uksf_air_slingloading_fnc_Can_Shorten_Ropes
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call uksf_air_slingloading_fnc_Is_Unit_Authorized) exitWith {
        
        [_vehicle] call uksf_air_slingloading_fnc_Can_Shorten_Ropes
    };
    false
};

uksf_air_slingloading_fnc_Can_Shorten_Ropes = {
    params ["_vehicle"];
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    if !([_vehicle] call uksf_air_slingloading_fnc_Is_Supported_Vehicle) exitWith {false};
    if (count (_vehicle getVariable ["uksf_air_slingloading_Ropes", []]) == 0) exitWith {false};
    if (count ([_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes) == 0) exitWith {false};
    true
};

uksf_air_slingloading_fnc_Shorten_Ropes_Action = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !([_vehicle] call uksf_air_slingloading_fnc_Can_Shorten_Ropes) exitWith {false};
    private _activeRopes = [_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes;
    if (count _activeRopes == 1) exitWith {
        private _ropeLength = [_vehicle, _unit, _activeRopes#0#0] call uksf_air_slingloading_fnc_Shorten_Ropes;
        if (_ropeLength >= uksf_air_slingloading_MinRopeLength) exitWith {
            private _messages = [[format [localize "STR_uksf_air_slingloading_ROPES_SHORTENED_TO", _ropeLength]]];
            if (_ropeLength == uksf_air_slingloading_MinRopeLength) then {
                _messages set [0, [format ["%1%2", _messages#0#0, " (min)"]]]
            };
            _messages pushBack true;
            _messages call CBA_fnc_notify;
        };
        [[format [localize "STR_uksf_air_slingloading_ALREADY_MIN_LENGTH", uksf_air_slingloading_MinRopeLength]], true] call CBA_fnc_notify;
    };
    uksf_air_slingloading_actionContext = "uksf_air_slingloading_shorten";
    [localize "STR_uksf_air_slingloading_SHORTEN", "uksf_air_slingloading_fnc_Shorten_Ropes_Index_Action", _activeRopes, localize "STR_uksf_air_slingloading_ROPE", _vehicle, _unit] call uksf_air_slingloading_fnc_Show_Select_Ropes_Menu;
    private _shortenedRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes_Change", []];
    if (count _shortenedRopes > 0) then {
        private _messages = [[localize "STR_uksf_air_slingloading_ROPES_SHORTENED"]];
        private ["_shortenedRopesIndex"];
        {
            if (_x #1 >= uksf_air_slingloading_MinRopeLength) then {
                _shortenedRopesIndex = _x#0;
                _messages pushBack [format [localize "STR_uksf_air_slingloading_ROPES_SHORTENED_TO_IND", (_activeRopes select {_x #0 == _shortenedRopesIndex}) #0 #1, _x #1]];
                if (_x #1 == uksf_air_slingloading_MinRopeLength) then {
                    private _messageIndex = (count _messages) - 1;
                    _messages set [_messageIndex, [format ["%1%2", _messages#_messageIndex#0, " (min)"]]];
                };
            } else {
                _messages pushBack [format [localize "STR_uksf_air_slingloading_ALREADY_MIN_LENGTH", uksf_air_slingloading_MinRopeLength]];
            };
        } forEach _shortenedRopes;
        _messages pushBack true;
        _messages call CBA_fnc_notify;
        _vehicle setVariable ["uksf_air_slingloading_Ropes_Change", nil];
    };
};

uksf_air_slingloading_fnc_Shorten_Ropes_Index_Action = {
    params [["_ropesIndex", 0], ["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && !isNull _vehicle && [_vehicle] call uksf_air_slingloading_fnc_Can_Shorten_Ropes) then {
        private _ropeLength = [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Shorten_Ropes;
        [_vehicle, _ropeLength, _ropesIndex] call uksf_air_slingloading_fnc_Save_Rope_Change;
    };
};

uksf_air_slingloading_fnc_Shorten_Ropes = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Shorten_Ropes", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopes = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes;
    private _ropeLength = -1;
    if (count _existingRopes > 0) then {
        _ropeLength = ropeLength (_existingRopes #0);
        if (_ropeLength <= uksf_air_slingloading_MinRopeLength) exitWith {
            if (uksf_air_slingloading_MinRopeLengthDropCargo) then {
                [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Release_Cargo;
            };
            _ropeLength = uksf_air_slingloading_MinRopeLength - 1;
        };
        private _unwindLength = uksf_air_slingloading_ExtendShortenRopeLength;
        if (_ropeLength - _unwindLength < 5) then {
            _unwindLength = _ropeLength - 5;
        };
        if (_ropeLength < 10) then {_unwindLength = 1};
        [_vehicle, _existingRopes, uksf_air_slingloading_RopeUnwindSpeed, -_unwindLength] spawn uksf_air_slingloading_fnc_Unwind_Ropes;
        _ropeLength = _ropeLength - _unwindLength;
    };
    _ropeLength
};

uksf_air_slingloading_fnc_Release_Cargo_Action_Check = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if ([getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Vehicle_Is_UAV_And_Currently_Operatied_By_Unit) exitWith {
        
        [getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Can_Release_Cargo
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call uksf_air_slingloading_fnc_Is_Unit_Authorized) exitWith {
        
        [_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Release_Cargo
    };
    false
};

uksf_air_slingloading_fnc_Can_Release_Cargo = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !([_vehicle] call uksf_air_slingloading_fnc_Is_Supported_Vehicle) exitWith {
        
        false
    };
    _existingRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    if (count _existingRopes == 0) exitWith {
        
        false
    };
    private _activeRopes = [_vehicle, _unit] call uksf_air_slingloading_fnc_Get_Active_Ropes_With_Cargo;
    if (count _activeRopes == 0) exitWith {
        
        false
    };
    
    true
};

uksf_air_slingloading_fnc_Release_Cargo_Action = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !([_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Release_Cargo) exitWith {false};
    private _activeRopes = [_vehicle, _unit] call uksf_air_slingloading_fnc_Get_Active_Ropes_With_Cargo;
    if (count _activeRopes == 1) exitWith {
        [_vehicle, _unit, (_activeRopes#0)#0] call uksf_air_slingloading_fnc_Release_Cargo
    };
    uksf_air_slingloading_actionContext = "uksf_air_slingloading_release";
    [localize "STR_uksf_air_slingloading_RELEASE", "uksf_air_slingloading_fnc_Release_Cargo_Index_Action", _activeRopes, localize "STR_uksf_air_slingloading_CARGO", _vehicle, _unit] call uksf_air_slingloading_fnc_Show_Select_Ropes_Menu;
};

uksf_air_slingloading_fnc_Release_Cargo_Index_Action = {
    params [["_ropesIndex", 0], ["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && [_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Release_Cargo) then {
        [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Release_Cargo;
    };
};

uksf_air_slingloading_fnc_Release_Cargo = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Release_Cargo", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopesAndCargo = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes_And_Cargo;
    
    private _existingRopes = _existingRopesAndCargo #0;
    private _existingCargo = _existingRopesAndCargo #1;
    {
        _existingCargo ropeDetach _x;
    } forEach _existingRopes;
    private _allCargo = _vehicle getVariable ["uksf_air_slingloading_Cargo", []];
    _allCargo set [_ropesIndex, objNull];
    _vehicle setVariable ["uksf_air_slingloading_Cargo", _allCargo, true];
    _this call uksf_air_slingloading_fnc_Retract_Ropes;
};

uksf_air_slingloading_fnc_Get_Display_Name = {
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

uksf_air_slingloading_fnc_Retract_Ropes_Action_Check = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    
    if ([getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Vehicle_Is_UAV_And_Currently_Operatied_By_Unit) exitWith {
        
        [getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Can_Retract_Ropes
    };
    if (vehicle _unit == _unit) exitWith {
        
        [cursorObject, _unit, true] call uksf_air_slingloading_fnc_Can_Retract_Ropes
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call uksf_air_slingloading_fnc_Is_Unit_Authorized) exitWith {
        
        [_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Retract_Ropes
    };
    false
};

uksf_air_slingloading_fnc_Can_Retract_Ropes = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_distanceCheck", false]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_distanceCheck && _unit distance _vehicle > uksf_air_slingloading_MaxDeployRetractDistance + (sizeOf typeOf _vehicle / 10 max 1)) exitWith {
        
        false
    };
    if !([_vehicle] call uksf_air_slingloading_fnc_Is_Supported_Vehicle) exitWith {
        
        false
    };
    private _existingRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    if (count _existingRopes == 0) exitWith {
        
        false
    };
    private _activeRopes = [_vehicle] call uksf_air_slingloading_fnc_Get_Active_Ropes_Without_Cargo;
    if (count _activeRopes == 0) exitWith {
        
        false
    };
    true;
};

uksf_air_slingloading_fnc_Retract_Ropes_Action = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {};
    private _activeRopes = [_vehicle] call uksf_air_slingloading_fnc_Get_Active_Ropes_Without_Cargo;
    if (count _activeRopes == 1) exitWith {        
        
        [_vehicle, _unit, (_activeRopes #0) #0] call uksf_air_slingloading_fnc_Retract_Ropes;
        [[localize "STR_uksf_air_slingloading_ROPES_RETRACTED"], true] call CBA_fnc_notify;
    };
    uksf_air_slingloading_actionContext = "uksf_air_slingloading_retract";
    [localize "STR_uksf_air_slingloading_RETRACT", "uksf_air_slingloading_fnc_Retract_Ropes_Index_Action", _activeRopes, localize "STR_uksf_air_slingloading_ROPE", _vehicle, _unit] call uksf_air_slingloading_fnc_Show_Select_Ropes_Menu;
};

uksf_air_slingloading_fnc_Retract_Ropes_Index_Action = {
    params ["_ropesIndex", ["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0) then {
        [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Retract_Ropes;
    };
};

uksf_air_slingloading_fnc_Retract_Ropes = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Retract_Ropes", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopesAndCargo = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes_And_Cargo;
    private _existingRopes = _existingRopesAndCargo #0;
    private _existingCargo = _existingRopesAndCargo #1;
    private _cargoArray = ropeAttachedObjects _vehicle;
    
    if (count _cargoArray > 0) then {
        private _helper = (_cargoArray select {_x getVariable ["uksf_air_slingloading_Ropes_Pick_Up_Helper", false]}) #0;
        if (isNil {_helper}) exitWith {};
        private _ropeHolder = attachedTo _helper;
        if (!isNull _ropeHolder) then {_unit = _ropeHolder};
        
    };
    if (isNull _existingCargo) then {
        [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Drop_Ropes;
        
        
        
        
        
        
        
        
        [_vehicle, _existingRopes, uksf_air_slingloading_RopeUnwindSpeed, 0, false] spawn uksf_air_slingloading_fnc_Unwind_Ropes;
        {
            [_vehicle, _x] spawn {
                params [["_vehicle", objNull], ["_rope", objNull]];
                if (isNull _vehicle || isNull _rope) exitWith {false};
                sleep 1;
                if (isNull _rope || isNull _vehicle) exitWith {};
                private _future = time + 20 + 100 / uksf_air_slingloading_RopeUnwindSpeed;
                while {!ropeUnwound _rope && alive _vehicle && time < _future} do {sleep 1};
                
                
                
                
                
                
                uksf_air_slingloading_allRopes deleteAt (uksf_air_slingloading_allRopes find _rope);
                uksf_air_slingloading_allRopes = uksf_air_slingloading_allRopes - [objNull];
                publicVariable "uksf_air_slingloading_allRopes";
                ropeDestroy _rope;
            };
        } forEach _existingRopes;
        private _allRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
        _allRopes set [_ropesIndex, []];
        _vehicle setVariable ["uksf_air_slingloading_Ropes", _allRopes, true];
    };
    private _activeRopes = [_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes;
    if (count _activeRopes == 0) then {
        _vehicle setVariable ["uksf_air_slingloading_Ropes", nil, true];
    };
};

uksf_air_slingloading_fnc_Vehicle_Is_UAV_And_Currently_Operatied_By_Unit = {
    params [["_UAV", objNull], ["_unit", objNull]];
    if (isNull _UAV || isNull _unit) exitWith {false};
    
    if (UAVControl _UAV #0 == _unit && (UAVControl _UAV #1 == "GUNNER" || UAVControl _UAV #1 == "DRIVER")) exitWith {
        
        true
    };
    false
};

uksf_air_slingloading_fnc_Deploy_Ropes_Action_Check = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    
    if ([getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Vehicle_Is_UAV_And_Currently_Operatied_By_Unit) exitWith {
        
        [getConnectedUAV _unit, _unit] call uksf_air_slingloading_fnc_Can_Deploy_Ropes
    };
    if (vehicle _unit == _unit) exitWith {
        
        [cursorObject, _unit, true] call uksf_air_slingloading_fnc_Can_Deploy_Ropes
    };
    if (vehicle _unit == _vehicle && [_vehicle, _unit] call uksf_air_slingloading_fnc_Is_Unit_Authorized) exitWith {
        
        [_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Deploy_Ropes
    };

    false
};

uksf_air_slingloading_fnc_Can_Deploy_Ropes = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_distanceCheck", false]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if (_distanceCheck && _unit distance _vehicle > uksf_air_slingloading_MaxDeployRetractDistance + (sizeOf typeOf _vehicle / 10 max 1)) exitWith {
        
        false
    };
    if !([_vehicle] call uksf_air_slingloading_fnc_Is_Supported_Vehicle) exitWith {
        
        false
    };
    private _existingVehicle = _unit getVariable ["uksf_air_slingloading_Ropes_Vehicle", []];
    if (count _existingVehicle > 0) exitWith {
        
        false
    };
    if (getPos _vehicle #2 > uksf_air_slingloading_MaxRopeDeployHeight) exitWith {
        
        false
    };
    _existingRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    if (count _existingRopes == 0) exitWith {
        
        true
    };
    private _activeRopes = [_vehicle, true] call uksf_air_slingloading_fnc_Get_Active_Ropes;
    if (count _existingRopes > 0 && (count _existingRopes) == (count _activeRopes)) exitWith {
        
        false
    };
    true
};

uksf_air_slingloading_fnc_Deploy_Ropes_Action = {
    params [["_vehicle", objNull], ["_unit", objNull]];
    
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (locked _vehicle > 1 && !(missionNamespace getVariable ["uksf_air_slingloading_LOCKED_VEHICLES_ENABLED", false])) exitWith {
        [[localize "STR_uksf_air_slingloading_CANNOT_DEPLOY"], true] call CBA_fnc_notify;
    };
    private _inactiveRopes = [_vehicle] call uksf_air_slingloading_fnc_Get_Active_Ropes;
    
    
    if (count _inactiveRopes > 0) exitWith {
        if (count _inactiveRopes > 1) then {
            [localize "STR_uksf_air_slingloading_DEPLOY", "uksf_air_slingloading_fnc_Deploy_Ropes_Index_Action", _inactiveRopes, _vehicle, _unit] call uksf_air_slingloading_fnc_Show_Select_Ropes_Menu;
        } else {
            [_vehicle, _unit, (_inactiveRopes #0) #0] call uksf_air_slingloading_fnc_Deploy_Ropes_Index;
        };
    };
    private _slingLoadPoints = [_vehicle] call uksf_air_slingloading_fnc_Get_Sling_Load_Points;
    
    if (count _slingLoadPoints == 1) exitWith {
        [_vehicle, _unit] call uksf_air_slingloading_fnc_Deploy_Ropes;
    };
    
    uksf_air_slingloading_Deploy_Ropes_Count_Menu = [[localize "STR_uksf_air_slingloading_ROPES", false]];
    uksf_air_slingloading_Vehicle = _vehicle;
    uksf_air_slingloading_Unit = _unit;
    uksf_air_slingloading_Deploy_Ropes_Count_Menu pushBack [localize "STR_uksf_air_slingloading_SINGLE", [0], "", -5, [["expression", "[1, uksf_air_slingloading_Vehicle, uksf_air_slingloading_Unit] call uksf_air_slingloading_fnc_Deploy_Ropes_Count_Action"]], "1", "1"];
    if (count _slingLoadPoints > 1) then {
        uksf_air_slingloading_Deploy_Ropes_Count_Menu pushBack [localize "STR_uksf_air_slingloading_DOUBLE", [0], "", -5, [["expression", "[2, uksf_air_slingloading_Vehicle, uksf_air_slingloading_Unit] call uksf_air_slingloading_fnc_Deploy_Ropes_Count_Action"]], "1", "1"];
    };
    if (count _slingLoadPoints > 2) then {
        uksf_air_slingloading_Deploy_Ropes_Count_Menu pushBack [localize "STR_uksf_air_slingloading_TRIPLE", [0], "", -5, [["expression", "[3, uksf_air_slingloading_Vehicle, uksf_air_slingloading_Unit] call uksf_air_slingloading_fnc_Deploy_Ropes_Count_Action"]], "1", "1"];
    };
    showCommandingMenu "";
    showCommandingMenu "#USER:uksf_air_slingloading_Deploy_Ropes_Count_Menu";
};

uksf_air_slingloading_fnc_Deploy_Ropes_Index_Action = {
    params ["_ropesIndex", ["_vehicle", objNull], ["_unit", objNull]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if (_ropesIndex >= 0 && !isNull _vehicle && [_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Deploy_Ropes) then {
        [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Deploy_Ropes_Index;
    };
};

uksf_air_slingloading_fnc_Deploy_Ropes_Count_Action = {
    params ["_count", ["_vehicle", objNull], ["_unit", objNull]];
    
    if (_count > 0 && !isNull _vehicle && [_vehicle, _unit] call uksf_air_slingloading_fnc_Can_Deploy_Ropes) then {
        [_vehicle, _unit, _count] call uksf_air_slingloading_fnc_Deploy_Ropes;
    };
};

uksf_air_slingloading_fnc_Deploy_Ropes = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_cargoCount", 1]];
    if (isNull _vehicle || isNull _unit) exitWith {false};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Deploy_Ropes", _this, _vehicle] call CBA_fnc_targetEvent;};
    if (!alive _vehicle) exitWith {[_vehicle] call uksf_air_slingloading_fnc_Add_Vehicle_Actions};
    private _existingRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    if (count _existingRopes > 0) exitWith {
        ["uksf_common_notify", [[localize "STR_uksf_air_slingloading_ALREADY"], true], _unit] call CBA_fnc_targetEvent;
    };
    private _slingLoadPoints = [_vehicle] call uksf_air_slingloading_fnc_Get_Sling_Load_Points;
    if (count _slingLoadPoints == 0) exitWith {
        ["uksf_common_notify", [[localize "STR_uksf_air_slingloading_DOESNT_SUPPORT"], true], _unit] call CBA_fnc_targetEvent;
    };
    if (count _slingLoadPoints < _cargoCount) exitWith {
        ["uksf_common_notify", [[format [localize "STR_uksf_air_slingloading_DOESNT_SUPPORT_X", _cargoCount]], true], _unit] call CBA_fnc_targetEvent;
    };
    private _cargoRopes = [];
    private _cargo = [];
    for "_i" from 0 to (_cargoCount - 1) do {
        _cargoRopes pushBack [];
        _cargo pushBack objNull;
    };
    _vehicle setVariable ["uksf_air_slingloading_Ropes", _cargoRopes, true];
    _vehicle setVariable ["uksf_air_slingloading_Cargo", _cargo, true];
    for "_i" from 0 to (_cargoCount - 1) do    {
        [_vehicle, _unit, _i] call uksf_air_slingloading_fnc_Deploy_Ropes_Index;
    };
};

uksf_air_slingloading_fnc_Deploy_Ropes_Index = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Deploy_Ropes_Index", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopes = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes;
    if (count _existingRopes > 0) exitWith {};
    private _existingRopesCount = [_vehicle] call uksf_air_slingloading_fnc_Get_Ropes_Count;
    private _slingLoadPoints = [_vehicle] call uksf_air_slingloading_fnc_Get_Sling_Load_Points;
    private _cargoRopes = [];
    private ["_rope"];
    for "_i" from 1 to 4 do {
        _rope = ropeCreate [_vehicle, (_slingLoadPoints select (_existingRopesCount - 1)) #_ropesIndex, 0];
        _rope allowDamage false;
        _rope setVariable ["uksf_air_slingloading_Ropes_Vehicle", [_vehicle, _ropesIndex], true]; 
        _cargoRopes pushBack _rope; 
        uksf_air_slingloading_allRopes pushBack _rope;
    };
    publicVariable "uksf_air_slingloading_allRopes";
    [_vehicle, _cargoRopes, uksf_air_slingloading_RopeUnwindSpeed + 2, uksf_air_slingloading_InitialDeployRopeLength, false] spawn uksf_air_slingloading_fnc_Unwind_Ropes;
    private _allRopes = _vehicle getVariable ["uksf_air_slingloading_Ropes", []];
    _allRopes set [_ropesIndex, _cargoRopes];
    _vehicle setVariable ["uksf_air_slingloading_Ropes", _allRopes, true];
    [_vehicle] spawn uksf_air_slingloading_fnc_Rope_Monitor_Vehicle;
    ["uksf_common_notify", [[format [localize "STR_uksf_air_slingloading_ROPES_DEPLOYED", uksf_air_slingloading_InitialDeployRopeLength]], true], _unit] call CBA_fnc_targetEvent;
};

uksf_air_slingloading_fnc_Pickup_Ropes_Action_Check = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {false};
    
    if (vehicle _unit != _unit) exitWith {false};
    if !(isNil{_unit getVariable "uksf_air_slingloading_Ropes_Pick_Up_Helper"}) exitWith {false};
    
    private _ropeHandlingDistance = uksf_air_slingloading_RopeHandlingDistance;
    private _nearRopes = uksf_air_slingloading_allRopes select {
        alive _x &&
        _unit distance ((ropeEndPosition _x)#1) < _ropeHandlingDistance
    };
    _nearRopes isNotEqualTo []
};

uksf_air_slingloading_fnc_Pickup_Ropes_Action = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {};
    
    private _ropeHandlingDistance = uksf_air_slingloading_RopeHandlingDistance;
    private _nearRopes = uksf_air_slingloading_allRopes select {
        alive _x &&
        _unit distance ((ropeEndPosition _x)#1) < _ropeHandlingDistance
    } apply {[_unit distance ((ropeEndPosition _x)#1), _x]};
    if (_nearRopes isEqualTo []) exitWith {};

    _nearRopes sort true;
    private _closestRope = _nearRopes#0#1;
    private _vehicle = (_closestRope getVariable "uksf_air_slingloading_Ropes_Vehicle") #0;
    if (isNull _vehicle) exitWith {};
    if (locked _vehicle > 1 && !(missionNamespace getVariable ["uksf_air_slingloading_LOCKED_VEHICLES_ENABLED", false])) exitWith {
        [[localize "STR_uksf_air_slingloading_CANT_PICKUP"], true] call CBA_fnc_notify;
    };
    private _ropesIndex = (_closestRope getVariable "uksf_air_slingloading_Ropes_Vehicle") #1;
    [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Pickup_Ropes;
};

uksf_air_slingloading_fnc_Pickup_Ropes = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Pickup_Ropes", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _existingRopesAndCargo = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes_And_Cargo;
    private _existingRopes = _existingRopesAndCargo #0;
    private _existingCargo = _existingRopesAndCargo #1;
    if (!isNull _existingCargo) then {
        {
            _existingCargo ropeDetach _x;
        } forEach _existingRopes;
        private _allCargo = _vehicle getVariable ["uksf_air_slingloading_Cargo", []];
        _allCargo set [_ropesIndex, objNull];
        _vehicle setVariable ["uksf_air_slingloading_Cargo", _allCargo, true];
    };
    private _helper = "Land_Can_V2_F" createVehicle position _unit;
    _helper setVariable ["uksf_air_slingloading_Ropes_Pick_Up_Helper", true, true];
    {
        [_helper, [0, 0, 0], [0, 0, -1]] ropeAttachTo _x;
        _helper attachTo [_unit, [-0.1, 0.1, 0.15], "Pelvis"];
    } forEach _existingRopes;
    hideObjectGlobal _helper;
    _unit setVariable ["uksf_air_slingloading_Ropes_Vehicle", [_vehicle, _ropesIndex], true];
    _unit setVariable ["uksf_air_slingloading_Ropes_Pick_Up_Helper", _helper, true];
};

uksf_air_slingloading_fnc_Attach_Ropes_Action_Check = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {false};

    private _cargo = cursorObject;
    if (isNull _cargo) exitWith {false};

    private _vehicle = (_unit getVariable ["uksf_air_slingloading_Ropes_Vehicle", [objNull, 0]]) #0;
    
    
    private _ropeAttachDistance = uksf_air_slingloading_MaxDeployRetractDistance + (sizeOf typeOf _cargo / 10 max 1);     
    
    if (vehicle _unit != _unit || _unit distance _cargo > _ropeAttachDistance || _vehicle == _cargo || !alive _cargo) exitWith {false};
    
    if (_vehicle == _cargo getVariable ["uksf_air_slingloading_CarrierVehicle", objNull]) exitWith {false}; 
    
    [_vehicle, _cargo] call uksf_air_slingloading_fnc_Is_Supported_Cargo
};

uksf_air_slingloading_fnc_Attach_Ropes_Action = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {};
    private _cargo = cursorObject;
    private _vehicle = (_unit getVariable ["uksf_air_slingloading_Ropes_Vehicle", [objNull, 0]]) #0;
    if (locked _cargo > 1 && !(missionNamespace getVariable ["uksf_air_slingloading_LOCKED_VEHICLES_ENABLED", false])) exitWith {
        [[localize "STR_uksf_air_slingloading_CANT_ATTACH"], true] call CBA_fnc_notify;
    };
    private _canBeAttached = true;
    
    [_cargo, _unit] call uksf_air_slingloading_fnc_Attach_Ropes;
};

uksf_air_slingloading_fnc_Attach_Ropes = {
    params [["_cargo", objNull], ["_unit", objNull]];
    if (isNull _cargo || isNull _unit) exitWith {};
    private _vehicleWithIndex = _unit getVariable ["uksf_air_slingloading_Ropes_Vehicle", [objNull, 0]];
    private _vehicle = _vehicleWithIndex #0;
    if (isNull _vehicle) exitWith {};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Attach_Ropes", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _ropes = [_vehicle, _vehicleWithIndex #1] call uksf_air_slingloading_fnc_Get_Ropes;
    if (count _ropes != 4) exitWith {};
    private _attachmentPoints = [_cargo] call uksf_air_slingloading_fnc_Get_Corner_Points;
    
    private _ropeLength = (ropeLength (_ropes #0));
    private _objDistance = (_cargo distance _vehicle) + 2;
    if (_objDistance > _ropeLength) exitWith {["uksf_common_notify", [[localize "STR_uksf_air_slingloading_TOO_SHORT"], true], _unit] call CBA_fnc_targetEvent;};
    private _ropesIndex = _vehicleWithIndex #1;
    _cargo setVariable ["uksf_air_slingloading_CarrierVehicle", _vehicle, true];
    [_vehicle, _cargo] spawn {
        params [["_vehicle", objNull], ["_cargo", objNull]];
        if (isNull _vehicle || isNull _cargo) exitWith {};
        while {alive _vehicle && alive _cargo && _cargo in ropeAttachedObjects _vehicle} do {
            sleep 1;
        };
        _cargo setVariable ["uksf_air_slingloading_CarrierVehicle", nil, true];
    };
    [_vehicle, _unit, _ropesIndex] call uksf_air_slingloading_fnc_Drop_Ropes;
    
    for "_i" from 0 to 3 do {
        [_cargo, _attachmentPoints #_i, [0, 0, -1]] ropeAttachTo (_ropes #_i);
    };
    private _allCargo = _vehicle getVariable ["uksf_air_slingloading_Cargo", []];
    _allCargo set [(_vehicleWithIndex #1), _cargo];
    _vehicle setVariable ["uksf_air_slingloading_Cargo", _allCargo, true];
    if (missionNamespace getVariable ["uksf_air_slingloading_HEAVY_LIFTING_ENABLED", true]) then {
        [_vehicle, _unit, _cargo, _ropes] spawn uksf_air_slingloading_fnc_Rope_Adjust_Mass;
    };
    _unit setVariable ["uksf_air_slingloading_Ropes_Pick_Up_Helper", nil, true];
    _unit setVariable ["uksf_air_slingloading_Ropes_Vehicle", nil, true];
};

uksf_air_slingloading_fnc_Drop_Ropes_Action_Check = {
    params [["_unit", objNull]];
    if (isNull _unit || vehicle _unit != _unit) exitWith {false};

    (_unit getVariable ["uksf_air_slingloading_Ropes_Vehicle", []]) isNotEqualTo []
};

uksf_air_slingloading_fnc_Drop_Ropes_Action = {
    params [["_unit", objNull]];
    if (isNull _unit) exitWith {false};
    private _vehicleAndIndex = _unit getVariable ["uksf_air_slingloading_Ropes_Vehicle", []];
    
    if (count _vehicleAndIndex == 2) then {
        [_vehicleAndIndex #0, _unit, _vehicleAndIndex #1] call uksf_air_slingloading_fnc_Drop_Ropes;
    };
};

uksf_air_slingloading_fnc_Drop_Ropes = {
    params [["_vehicle", objNull], ["_unit", objNull], ["_ropesIndex", 0]];
    if (isNull _vehicle || isNull _unit) exitWith {};
    if !(local _vehicle) exitWith {["uksf_air_slingloading_Drop_Ropes", _this, _vehicle] call CBA_fnc_targetEvent;};
    private _helper = (_unit getVariable ["uksf_air_slingloading_Ropes_Pick_Up_Helper", objNull]);
    
    if (!isNull _helper) then {
        private _existingRopes = [_vehicle, _ropesIndex] call uksf_air_slingloading_fnc_Get_Ropes;
        {
            _helper ropeDetach _x;
        } forEach _existingRopes;
        detach _helper;
        _unit setVariable ["uksf_air_slingloading_Ropes_Vehicle", nil, true];
        deleteVehicle _helper;
    };
    _unit setVariable ["uksf_air_slingloading_Ropes_Pick_Up_Helper", nil, true];
};

uksf_air_slingloading_fnc_Is_Supported_Vehicle = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {false};
    private _isSupported = false;
    {
        if (_vehicle isKindOf _x) exitWith {_isSupported = true};
    } forEach (missionNamespace getVariable ["uksf_air_slingloading_SUPPORTED_VEHICLES_OVERRIDE", uksf_air_slingloading_supportedVehicles]);
    _isSupported
};

uksf_air_slingloading_fnc_Is_Supported_Cargo = {
    params [["_vehicle", objNull], ["_cargo", objNull]];
    
    if (isNull _vehicle || isNull _cargo) exitWith {false};
    private _canSling = false;
    {
        if (_vehicle isKindOf (_x #0) && _cargo isKindOf (_x #2) && (toUpper (_x #1)) == "CAN_SLING") exitWith {_canSling = true};
    } forEach (missionNamespace getVariable ["uksf_air_slingloading_SLING_RULES_OVERRIDE", uksf_air_slingloading_slingRules]);
    
    _canSling
};

uksf_air_slingloading_fnc_Switch_Vehicles_Actions = {
    {
        [_x] call uksf_air_slingloading_fnc_Add_Vehicle_Actions;
    } foreach vehicles;
};

uksf_air_slingloading_fnc_Add_Vehicle_Actions = {
    params [["_vehicle", objNull]];
    if (isNull _vehicle) exitWith {};
    if !([_vehicle] call uksf_air_slingloading_fnc_Is_Supported_Vehicle) exitWith {};
    
    if (getMass _vehicle < uksf_air_slingloading_MinVehicleMass || !alive _vehicle) exitWith {
        [_vehicle, ["uksf_air_slingloading_ActionID_Deploy", "uksf_air_slingloading_ActionID_Retract", "uksf_air_slingloading_ActionID_Extend", "uksf_air_slingloading_ActionID_Shorten", "uksf_air_slingloading_ActionID_Release"]] call uksf_air_slingloading_fnc_Remove_Actions;
    };
    private _actionID = -1;
    if (isNil{_vehicle getVariable "uksf_air_slingloading_ActionID_Deploy"}) then {
        _actionID = _vehicle addAction [
            localize "STR_uksf_air_slingloading_DEPLOY",
            {[_this #0, _this #1] call uksf_air_slingloading_fnc_Deploy_Ropes_Action},
            nil,
            100,
            false,
            true,
            "",
            "[_target, _this] call uksf_air_slingloading_fnc_Deploy_Ropes_Action_Check"
        ];
        _vehicle setVariable ["uksf_air_slingloading_ActionID_Deploy", _actionID];
    };
    if (isNil{_vehicle getVariable "uksf_air_slingloading_ActionID_Retract"}) then {
        _actionID = _vehicle addAction [
            localize "STR_uksf_air_slingloading_RETRACT",
            {[_this #0, _this #1] call uksf_air_slingloading_fnc_Retract_Ropes_Action},
            nil,
            50,
            false,
            true,
            "",
            "[_target, _this] call uksf_air_slingloading_fnc_Retract_Ropes_Action_Check"
        ];
        _vehicle setVariable ["uksf_air_slingloading_ActionID_Retract", _actionID];
    };
    if (isNil{_vehicle getVariable "uksf_air_slingloading_ActionID_Extend"}) then {
        _actionID = _vehicle addAction [
            localize "STR_uksf_air_slingloading_EXTEND",
            {[_this #0, _this #1] call uksf_air_slingloading_fnc_Extend_Ropes_Action},
            nil,
            199,
            false,
            true,
            "",
            "[_target, _this] call uksf_air_slingloading_fnc_Extend_Ropes_Action_Check"
        ];
        _vehicle setVariable ["uksf_air_slingloading_ActionID_Extend", _actionID];
    };
    if (isNil{_vehicle getVariable "uksf_air_slingloading_ActionID_ExtendTG"}) then {
        _actionID = _vehicle addAction [
            localize "STR_uksf_air_slingloading_EXTEND_TG",
            {[_this #0, _this #1, true] call uksf_air_slingloading_fnc_Extend_Ropes_Action},
            nil,
            198,
            false,
            true,
            "",
            "[_target, _this, true] call uksf_air_slingloading_fnc_Extend_Ropes_Action_Check"
        ];
        _vehicle setVariable ["uksf_air_slingloading_ActionID_ExtendTG", _actionID];
    };
    if (isNil{_vehicle getVariable "uksf_air_slingloading_ActionID_Shorten"}) then {
        _actionID = _vehicle addAction [
            localize "STR_uksf_air_slingloading_SHORTEN",
            {[_this #0, _this #1] call uksf_air_slingloading_fnc_Shorten_Ropes_Action},
            nil,
            197,
            false,
            true,
            "",
            "[_target, _this] call uksf_air_slingloading_fnc_Shorten_Ropes_Action_Check"
        ];
        _vehicle setVariable ["uksf_air_slingloading_ActionID_Shorten", _actionID];
    };
    if (isNil{_vehicle getVariable "uksf_air_slingloading_ActionID_Release"}) then {
        _actionID = _vehicle addAction [
            format ["<t color='#FF0000'>%1</t>", localize "STR_uksf_air_slingloading_RELEASE"],
            {[_this#0, _this#1] call uksf_air_slingloading_fnc_Release_Cargo_Action},
            nil,
            195,
            false,
            true,
            "",
            "[_target, _this] call uksf_air_slingloading_fnc_Release_Cargo_Action_Check"
        ];
        _vehicle setVariable ["uksf_air_slingloading_ActionID_Release", _actionID];
    };
};

uksf_air_slingloading_fnc_addActions = {
    params ["_unit"];

    private _actionID = -1;
    if (isNil {_unit getVariable "uksf_air_slingloading_ActionID_Pickup"}) then {
        _actionID = _unit addAction [
            localize "STR_uksf_air_slingloading_PICKUP",
            {[_this#0] call uksf_air_slingloading_fnc_Pickup_Ropes_Action},
            nil,
            250,
            true,
            true,
            "",
            "[_this] call uksf_air_slingloading_fnc_Pickup_Ropes_Action_Check"
        ];
        _unit setVariable ["uksf_air_slingloading_ActionID_Pickup", _actionID];
    };
    if (isNil {_unit getVariable "uksf_air_slingloading_ActionID_Attach"}) then {
        _actionID = _unit addAction [
            localize "STR_uksf_air_slingloading_ATTACH",
            {[_this#0] call uksf_air_slingloading_fnc_Attach_Ropes_Action},
            nil,
            230,
            true,
            true,
            "",
            "[_this] call uksf_air_slingloading_fnc_Attach_Ropes_Action_Check"
        ];
        _unit setVariable ["uksf_air_slingloading_ActionID_Attach", _actionID];
    };
    if (isNil {_unit getVariable "uksf_air_slingloading_ActionID_Drop"}) then {
        _actionID = _unit addAction [
            localize "STR_uksf_air_slingloading_DROP",
            {[_this#0] call uksf_air_slingloading_fnc_Drop_Ropes_Action},
            nil,
            225,
            true,
            true,
            "",
            "[_this] call uksf_air_slingloading_fnc_Drop_Ropes_Action_Check"
        ];
        _unit setVariable ["uksf_air_slingloading_ActionID_Drop", _actionID];
    };
};

uksf_air_slingloading_fnc_Remove_Actions = {
    params [["_object", objNull], ["_actions", []]];
    
    if (isNull _object || count _actions == 0) exitWith {};
    private ["_actionID"];
    {
        _actionID = _object getVariable [_x, -1];
        
        if (_actionID > -1) then {
            _object removeAction _actionID;
            _object setVariable [_x, nil];
        };
    } forEach _actions;
};

if (hasInterface) then {
    ["Air", "init", {_this call uksf_air_slingloading_fnc_Add_Vehicle_Actions}, true] call CBA_fnc_addClassEventHandler;
    
    ["CAManBase", "respawn", {call uksf_air_slingloading_fnc_addActions}, true, [], true] call CBA_fnc_addClassEventHandler;
    [player] call uksf_air_slingloading_fnc_addActions;
};
