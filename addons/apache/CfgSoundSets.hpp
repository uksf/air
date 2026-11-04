class CfgSoundShaders {
    class jsrs_2025_helicopter_ah64_apache_rotorext_soundshader;
    class jsrs_2025_helicopter_ah64_apache_evr_soundshader;
    class jsrs_2025_helicopter_ah64_apache_rotorint_soundshader;
    class jsrs_2025_helicopter_ah64_apache_rotordistance_soundshader;
    class jsrs_2025_helicopter_ah64_apache_enginedistance_soundshader;
    class jsrs_2025_helicopter_ah64_apache_engineext_soundshader;
    class jsrs_2025_helicopter_ah64_apache_engineint_soundshader;
    class GVAR(engineext_soundshader) : jsrs_2025_helicopter_ah64_apache_engineext_soundshader {
        volume = "1.6 * camPos * (0 max (rotorspeed - 0.18)) * (1 + rotorthrust)";
        range = 1200;
        rangeCurve[] = { {0, 1}, {300, 1}, {800, 0.7}, {1200, 0} };
    };
    class GVAR(engineint_soundshader) : jsrs_2025_helicopter_ah64_apache_engineint_soundshader {
        volume = "0.8 * (1 - camPos) * (0 max (rotorspeed - 0.12)) * (1 + rotorthrust) * (gmeterZ factor[5, 1])";
    };
    class GVAR(rotorext_soundshader) : jsrs_2025_helicopter_ah64_apache_rotorext_soundshader {
        samples[] = { { QPATHTOF(data\sounds\rotor_ext.ogg), 1 } };
    };
    class GVAR(evr_soundshader) : jsrs_2025_helicopter_ah64_apache_evr_soundshader {
        samples[] = { { QPATHTOF(data\sounds\rotor_echo.ogg), 1 } };
    };
    class GVAR(rotorint_soundshader) : jsrs_2025_helicopter_ah64_apache_rotorint_soundshader {
        samples[] = { { QPATHTOF(data\sounds\rotor_int.ogg), 1 } };
        frequency = "rotorspeed * (1 - rotorthrust / 15)";
    };
    class GVAR(rotordistance_soundshader) : jsrs_2025_helicopter_ah64_apache_rotordistance_soundshader {
        samples[] = { { QPATHTOF(data\sounds\rotor_dist.ogg), 1 } };
    };
    class GVAR(enginedistance_soundshader) : jsrs_2025_helicopter_ah64_apache_enginedistance_soundshader {
        samples[] = { { QPATHTOF(data\sounds\turbine_dist.ogg), 1 } };
        frequency = "rotorspeed * (1 - rotorthrust / 15)";
    };
};

class CfgSoundShapes {
    class GVAR(engine_shape) {
        type = "cone";
        innerVolume = 1;
        outerVolume = 0.6;
        innerAngle = 180;
        outerAngle = 300;
        azimuth = 180;
        elevation = 0;
    };
};

class CfgSoundSets {
    class jsrs_2025_helicopter_ah64_apache_engineext_soundset;
    class jsrs_2025_helicopter_ah64_apache_engineint_soundset;
    class GVAR(engineext_soundset) : jsrs_2025_helicopter_ah64_apache_engineext_soundset {
        soundShaders[] = { QGVAR(engineext_soundshader) };
        shape = QGVAR(engine_shape);
    };
    class GVAR(engineint_soundset) : jsrs_2025_helicopter_ah64_apache_engineint_soundset {
        soundShaders[] = { QGVAR(engineint_soundshader) };
    };
    class jsrs_2025_helicopter_ah64_apache_rotorext_soundset;
    class jsrs_2025_helicopter_ah64_apache_evr_soundset;
    class jsrs_2025_helicopter_ah64_apache_rotorint_soundset;
    class jsrs_2025_helicopter_ah64_apache_rotordistance_soundset;
    class jsrs_2025_helicopter_ah64_apache_enginedistance_soundset;
    class GVAR(rotorext_soundset) : jsrs_2025_helicopter_ah64_apache_rotorext_soundset {
        soundShaders[] = { QGVAR(rotorext_soundshader) };
    };
    class GVAR(evr_soundset) : jsrs_2025_helicopter_ah64_apache_evr_soundset {
        soundShaders[] = { QGVAR(evr_soundshader) };
    };
    class GVAR(rotorint_soundset) : jsrs_2025_helicopter_ah64_apache_rotorint_soundset {
        soundShaders[] = { QGVAR(rotorint_soundshader) };
    };
    class GVAR(rotordistance_soundset) : jsrs_2025_helicopter_ah64_apache_rotordistance_soundset {
        soundShaders[] = { QGVAR(rotordistance_soundshader) };
    };
    class GVAR(enginedistance_soundset) : jsrs_2025_helicopter_ah64_apache_enginedistance_soundset {
        soundShaders[] = { QGVAR(enginedistance_soundshader) };
    };
};
