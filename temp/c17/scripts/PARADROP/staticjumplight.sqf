_plane = _this select 0;

_jump_light = createVehicle ["#lightpoint", position _plane, [], 0, "NONE"];
_jump_light setLightBrightness 1;
_jump_light setLightAmbient[1, 0, 0];
_jump_light setLightColor[1, 0, 0];
_jump_light lightAttachObject [_plane,[0,0,-5]];

sleep 3;

Deletevehicle _jump_light;

_jump_light2 = createVehicle ["#lightpoint", position _plane, [], 0, "NONE"];
_jump_light2 setLightBrightness 1;
_jump_light2 setLightAmbient[0, 1, 0];
_jump_light2 setLightColor[0, 1, 0];
_jump_light2 lightAttachObject [_plane,[0,0,5]];

sleep 10;

Deletevehicle _jump_light2;