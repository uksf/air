class CfgSoundSets {
    class GVAR(sonicboom_soundset) {
        soundShaders[] = { QGVAR(SonicBoom_SoundShader) };
        volumeFactor = 4;
        spatial = 1;
        loop = 0;
        speedOfSound = 0;
        sound3DProcessingType = "JetExt_Distant_3DProcessingType";
    };
    class GVAR(enginelowext_soundset) {
        soundShaders[] = { "Plane_Fighter_04_EngineLowExt_SoundShader" };
        volumeFactor = 1;
        spatial = 1;
        loop = 1;
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
    };
    class GVAR(howlext_soundset) {
        soundShaders[] = { QGVAR(HowlExt_SoundShader) };
        volumeFactor = 1.5;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class GVAR(forsageexthigh_soundset) {
        soundShaders[] = { QGVAR(ForsageExtHigh_SoundShader) };
        volumeFactor = 1.15;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class GVAR(windnoiseext_soundset) {
        soundShaders[] = { "Plane_Fighter_04_WindNoiseExt_SoundShader" };
        volumeFactor = 1;
        spatial = 1;
        loop = 1;
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
    };
    class GVAR(engineext_middle_soundset) {
        soundShaders[] = { "Plane_Fighter_04_EngineExt_Middle_SoundShader" };
        volumeFactor = 1.4;
        spatial = 1;
        loop = 1;
        shape = "FrontSemispace10";
        volumeCurve = "InverseSquare3Curve";
        sound3DProcessingType = "JetExt_Middle_3DProcessingType";
        occlusionFactor = 0.5;
        obstructionFactor = 0;
    };
    class GVAR(engineext_dist_front_soundset) {
        soundShaders[] = { "Plane_Fighter_04_EngineExt_Dist_Front_SoundShader" };
        volumeFactor = 1.3;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare3Curve";
        shape = "FrontSemispace60";
        sound3DProcessingType = "JetExt_Distant_3DProcessingType";
        occlusionFactor = 0.5;
        obstructionFactor = 0;
    };
    class GVAR(engineext_dist_rear_soundset) {
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
    class GVAR(HowlInt_SoundSet) {
        soundShaders[] = { QGVAR(HowlInt_SoundShader) };
        volumeFactor = 1.2;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
    class GVAR(ForsageIntHigh_SoundSet) {
        soundShaders[] = { QGVAR(ForsageIntHigh_SoundShader) };
        volumeFactor = 1.15;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
};
class CfgSoundShaders {
    class GVAR(SonicBoom_SoundShader) {
        samples[] = { { "A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_sonicboom", 1 } };
        frequency = 1;
        volume = 2;
        range = 7500;
    };
    class GVAR(HowlExt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\howl_ext.ogg), 1 } };
        frequency = "1.0 min (rpm + 0.5) * (rpm factor [0.5, 1.1])";
        volume = "0.6 * machcone * engineOn * camPos * (rpm factor [0, 1]) * (thrust factor [0, 0.9])";
        range = 4000;
        rangeCurve[] = { { 0, 1 }, { 1000, 0.75 }, { 2500, 0.25 }, { 4000, 0 } };
    };
    class GVAR(ForsageExtHigh_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\burner_ext.ogg), 1 } };
        frequency = 1;
        volume = "1.15 * machcone * engineOn * camPos * (thrust factor [0.9, 1.0])";
        range = 5000;
        rangeCurve[] = { { 0, 1 }, { 1000, 0.75 }, { 3000, 0.25 }, { 5000, 0 } };
    };
    class GVAR(RumbleDist_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\rumble_dist.ogg), 1 } };
        frequency = 1;
        volume = "0.6 * machcone * camPos * (rpm factor [0.5, 1])";
        range = 5000;
        rangeCurve[] = { { 0, 0 }, { 50, 1 }, { 5000, 1 } };
    };
    class GVAR(HowlInt_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\howl_int.ogg), 1 } };
        frequency = "1.0 min (rpm + 0.25) * (rpm factor [0.25, 1.1])";
        volume = "engineOn * (1 - camPos) * (rpm factor [0, 1])";
    };
    class GVAR(ForsageIntHigh_SoundShader) {
        samples[] = { { QPATHTOF(data\sounds\burner_int.ogg), 1 } };
        frequency = 1;
        volume = "1.15 * engineOn * (1 - camPos) * (rpm factor [0.9, 1]) * (thrust factor [0.9, 1.0])";
    };
};
