sleep .01;
while{time > 0} do
{
_C17 = vehicle player;

_hour = round(floor daytime);
_min = round(floor((daytime - floor(daytime)) * 60));
_sec = floor((((daytime - floor daytime) * 60) - floor((daytime - floor daytime) * 60)) * 60);
_hourformat1 = [_hour,"\USAF_C17\data\NUM\G"] call c17_digitten;
_hourformat2 = [_hour,"\USAF_C17\data\NUM\G"] call c17_digit;
_minformat1 = [_min,"\USAF_C17\data\NUM\G"] call c17_digitten;
_minformat2 = [_min,"\USAF_C17\data\NUM\G"] call c17_digit;
_secformat1 = [_sec,"\USAF_C17\data\NUM\G"] call c17_digitten;
_secformat2 = [_sec,"\USAF_C17\data\NUM\G"] call c17_digit;
_C17 setobjecttexture [11,_hourformat1];
_C17 setobjecttexture [12,_hourformat2];
_C17 setobjecttexture [13,_minformat1];
_C17 setobjecttexture [14,_minformat2];
_C17 setobjecttexture [15,_secformat1];
_C17 setobjecttexture [16,_secformat2];
sleep 0.01;
};
