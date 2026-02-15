/*
    Author: Lala14

    Description:
    To-Do

    Parameter(s):
    0: UNIT - Return Side from this UNIT

    Returns:
    [parachute type, strobe type]
*/
private ["_unit","_chute","_strobe"];
_unit = _this select 0;

_chute = "B_Parachute_02_F";
_strobe = "NVG_TargetC";
_smoke = "smokeShell";

switch (side _unit) do
{
        case east: { _chute = "O_Parachute_02_F"; _strobe = "NVG_TargetW"; _smoke = "smokeShellRed" };
        case west: { _chute = "B_Parachute_02_F"; _strobe = "NVG_TargetE"; _smoke = "smokeShellBlue" };
        case resistance: { _chute = "I_Parachute_02_F"; _strobe = "NVG_TargetC"; _smoke = "smokeShellGreen" };
};
[_chute,_strobe,_smoke];
