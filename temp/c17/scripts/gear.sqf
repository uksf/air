// Removed from init

private ["_plane"];
_array = _this;
_plane = _this select 0;

while {(alive _plane)} do
{
if(_plane animationPhase "Gear_1" >0.5) then
{
_plane setobjecttexture [17,"\USAF_C17\data\texture\empty_ca.paa"];
_plane setobjecttexture [18,"\USAF_C17\data\texture\empty_ca.paa"];
_plane setobjecttexture [19,"\USAF_C17\data\texture\empty_ca.paa"];
_plane setobjecttexture [20,"\USAF_C17\data\texture\empty_ca.paa"];
_plane setobjecttexture [21,"\USAF_C17\data\texture\empty_ca.paa"];		
sleep 1.0;
};
if(_plane animationPhase "Gear_1" <0.5) then
{
_plane setobjecttexture [17,"\USAF_C17\data\cockpit\c17_instruments.paa"];
_plane setobjecttexture [18,"\USAF_C17\data\cockpit\c17_instruments.paa"];
_plane setobjecttexture [19,"\USAF_C17\data\cockpit\c17_instruments.paa"];
_plane setobjecttexture [20,"\USAF_C17\data\cockpit\c17_instruments.paa"];
_plane setobjecttexture [21,"\USAF_C17\data\cockpit\c17_instruments.paa"];		
sleep 1.0;
};
};


