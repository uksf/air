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
    class GVAR(HowlExt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\howl_ext.ogg), 1 } };
        frequency = "1.0 min (rpm + 0.5) * (rpm factor [0.5, 1.1])";
        volume = "0.6 * machcone * engineOn * camPos * (rpm factor [0, 1]) * (thrust factor [0, 0.9])";
        range = 4000;
        rangeCurve[] = { { 0, 1 }, { 1000, 0.75 }, { 2500, 0.25 }, { 4000, 0 } };
    };
    class GVAR(HowlInt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\howl_int.ogg), 1 } };
        frequency = "1.0 min (rpm + 0.25) * (rpm factor [0.25, 1.1])";
        volume = "engineOn * (1 - camPos) * (rpm factor [0, 1])";
    };
    class GVAR(BurnerExt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\burner_ext.ogg), 1 } };
        frequency = 1;
        volume = "1.15 * machcone * engineOn * camPos * (thrust factor [0.9, 1.0])";
        range = 5000;
        rangeCurve[] = { { 0, 1 }, { 1000, 0.75 }, { 3000, 0.25 }, { 5000, 0 } };
    };
    class GVAR(BurnerInt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\burner_int.ogg), 1 } };
        frequency = 1;
        volume = "1.15 * engineOn * (1 - camPos) * (rpm factor [0.9, 1]) * (thrust factor [0.9, 1.0])";
    };
    class GVAR(RumbleDist_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\rumble_dist.ogg), 1 } };
        frequency = 1;
        volume = "0.6 * machcone * camPos * (rpm factor [0.5, 1])";
        range = 5000;
        rangeCurve[] = { { 0, 0 }, { 50, 1 }, { 5000, 1 } };
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
    class GVAR(HowlExt_SoundSet) {
        soundShaders[] = { QGVAR(HowlExt_SoundShader) };
        volumeFactor = 1.1;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class GVAR(HowlInt_SoundSet) {
        soundShaders[] = { QGVAR(HowlInt_SoundShader) };
        volumeFactor = 1.2;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
    class GVAR(BurnerExt_SoundSet) {
        soundShaders[] = { QGVAR(BurnerExt_SoundShader) };
        volumeFactor = 1.15;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class GVAR(BurnerInt_SoundSet) {
        soundShaders[] = { QGVAR(BurnerInt_SoundShader) };
        volumeFactor = 1.3;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
    class GVAR(RumbleDist_SoundSet) {
        soundShaders[] = { QGVAR(RumbleDist_SoundShader) };
        volumeFactor = 1.5;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        shape = "RearSemispace20";
        sound3DProcessingType = "JetExt_Distant_3DProcessingType";
        occlusionFactor = 0.5;
        obstructionFactor = 0;
    };
};
