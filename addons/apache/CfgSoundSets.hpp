class CfgSoundShaders {
    class jsrs_2025_helicopter_ah64_apache_rotorext_soundshader;
    class jsrs_2025_helicopter_ah64_apache_evr_soundshader;
    class jsrs_2025_helicopter_ah64_apache_rotorint_soundshader;
    class jsrs_2025_helicopter_ah64_apache_rotordistance_soundshader;
    class jsrs_2025_helicopter_ah64_apache_enginedistance_soundshader;
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

class CfgSoundSets {
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
