class CfgSoundShaders {
    class GVAR(RoarExt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\roar_ext.ogg), 1 } };
        frequency = "0.85 + 0.25 * thrust";
        volume = "engineOn * camPos * (thrust factor[0.3, 1])";
        range = 2500;
        rangeCurve[] = { { 0, 1 }, { 400, 0.7 }, { 1500, 0.25 }, { 2500, 0 } };
    };
    class GVAR(RoarInt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\roar_int.ogg), 1 } };
        frequency = "0.85 + 0.25 * thrust";
        volume = "engineOn * (1 - camPos) * (thrust factor[0.3, 1])";
    };
};

class CfgSoundSets {
    class GVAR(RoarExt_SoundSet) {
        soundShaders[] = { QGVAR(RoarExt_SoundShader) };
        volumeFactor = 1.2;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class GVAR(RoarInt_SoundSet) {
        soundShaders[] = { QGVAR(RoarInt_SoundShader) };
        volumeFactor = 0.9;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
};
