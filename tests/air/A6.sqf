private _condition = getText (missionConfigFile >> "A3CMD_A6" >> "MFD" >> "B_Plane_Fighter_01_static_HUD" >> "Draw" >> "Horizont" >> "HideOnTurn" >> "condition");
private _expected = "5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
private _result = format ["A3CMD|A6|%1|fixtureConfigCondition=%2 expected=%3; dormant source fixture, not a loaded aircraft HUD", ["FAIL", "PASS"] select (_condition isEqualTo _expected), _condition, _expected];
diag_log _result;
_result
