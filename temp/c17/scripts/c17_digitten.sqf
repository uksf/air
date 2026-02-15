private ["_plane","_char","_digtt"];
_plane = _this select 0;
_char = _this select 1;

_digtt = round(10*(((floor(_plane * 0.1)) * 0.1) - floor((floor(_plane * 0.1)) * 0.1)));
_digformat = _char + (format ["%1",_digtt]) + "_ca.paa";

_digformat;
