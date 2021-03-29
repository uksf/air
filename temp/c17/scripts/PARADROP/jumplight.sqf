_plane = _this select 0;

_jump_light = createVehicle ["#lightpoint", position _plane, [], 0, "NONE"];
_jump_light setLightBrightness 0.5;
_jump_light setLightAmbient[1, 0, 0];
_jump_light setLightColor[1, 0, 0];
_jump_light lightAttachObject [_plane,[0,-1,5]];

