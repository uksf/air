// Removed from init

If (!Local Player) ExitWith {};
private ["_plane"];
_plane = _this select 0;
_F22_pilot = driver _plane;

if(isnil "c17_initstate") then
{
_digital_clock = [_plane] execvm "\USAF_C17\scripts\digital_clock.sqf";
c17_initstate = true;
};

c17_digit = compile preprocessFileLineNumbers "\USAF_C17\scripts\c17_digit.sqf";
c17_digitten = compile preprocessFileLineNumbers "\USAF_C17\scripts\c17_digitten.sqf";

waitUntil {!(isNull _plane)};

if(isNil "F22_initstate") then
{
	for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'off',true]; };
	F22_initstate = true;
};

if((getpos _plane select 2) > 15 and driver _plane == player) then
{
	for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'on',true]; };
};

while{(alive _plane) && !(isNull _plane)} do
{

	waitUntil {!isNull (driver _plane)};

	if((isengineon _plane) && (driver _plane == player)) then
	{
		for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'on',true]; };
	} else {
		for "_i" from 1 to 11 do {  _plane setVariable [(format["screen_%1",_i]),'off',true]; };
	};
	
	if(_plane getVariable ["screen_1",'off'] isEqualTo 'off') then {_plane setobjecttexture [22,"\USAF_c17\data\cockpit\black_co.paa"];} else {_plane setobjecttexture [22,"\USAF_c17\data\cockpit\02361da0.paa"];};
	if(_plane getVariable ["screen_2",'off'] isEqualTo 'off') then {_plane setobjecttexture [23,"\USAF_c17\data\cockpit\black_co.paa"];} else {_plane setobjecttexture [23,"\USAF_c17\data\cockpit\ch47f_monitory_ca.paa"];};
	if(_plane getVariable ["screen_3",'off'] isEqualTo 'off') then {_plane setobjecttexture [24,"\USAF_c17\data\cockpit\black_co.paa"];} else {_plane setobjecttexture [24,"\USAF_c17\data\cockpit\ch47f_monitory_ca.paa"];};
	if(_plane getVariable ["screen_4",'off'] isEqualTo 'off') then {_plane setobjecttexture [25,"\USAF_c17\data\cockpit\black_co.paa"];} else {_plane setobjecttexture [25,"\USAF_c17\data\cockpit\02361da0.paa"];};

If !(alive _plane) ExitWith {};
sleep 0.01;
};
