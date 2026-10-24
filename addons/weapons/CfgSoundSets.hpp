class CfgSoundShaders {
    class jsrs_2025_autocannon_small_closure_soundshader;
    class jsrs_2025_autocannon_small_close_shot_soundshader;
    class jsrs_2025_autocannon_small_closedistance_shot_soundshader;
    class jsrs_2025_autocannon_small_mediumdistance_shot_soundshader;
    class jsrs_2025_autocannon_small_fardistance_shot_soundshader;
    class GVAR(m230_cockpit_soundshader) : jsrs_2025_autocannon_small_closure_soundshader {
        samples[] = {
            { QPATHTOF(sounds\m230\cockpit_1.ogg), 1 },
            { QPATHTOF(sounds\m230\cockpit_2.ogg), 1 },
            { QPATHTOF(sounds\m230\cockpit_3.ogg), 1 },
            { QPATHTOF(sounds\m230\cockpit_4.ogg), 1 },
            { QPATHTOF(sounds\m230\cockpit_5.ogg), 1 },
            { QPATHTOF(sounds\m230\cockpit_6.ogg), 1 },
            { QPATHTOF(sounds\m230\cockpit_7.ogg), 1 },
            { QPATHTOF(sounds\m230\cockpit_8.ogg), 1 }
        };
    };
    class GVAR(m230_close_soundshader) : jsrs_2025_autocannon_small_close_shot_soundshader {
        samples[] = {
            { QPATHTOF(sounds\m230\close_1.ogg), 1 },
            { QPATHTOF(sounds\m230\close_2.ogg), 1 },
            { QPATHTOF(sounds\m230\close_3.ogg), 1 },
            { QPATHTOF(sounds\m230\close_4.ogg), 1 },
            { QPATHTOF(sounds\m230\close_5.ogg), 1 },
            { QPATHTOF(sounds\m230\close_6.ogg), 1 },
            { QPATHTOF(sounds\m230\close_7.ogg), 1 },
            { QPATHTOF(sounds\m230\close_8.ogg), 1 }
        };
    };
    class GVAR(m230_closedistance_soundshader) : jsrs_2025_autocannon_small_closedistance_shot_soundshader {
        samples[] = {
            { QPATHTOF(sounds\m230\closedist_1.ogg), 1 },
            { QPATHTOF(sounds\m230\closedist_2.ogg), 1 },
            { QPATHTOF(sounds\m230\closedist_3.ogg), 1 },
            { QPATHTOF(sounds\m230\closedist_4.ogg), 1 },
            { QPATHTOF(sounds\m230\closedist_5.ogg), 1 },
            { QPATHTOF(sounds\m230\closedist_6.ogg), 1 },
            { QPATHTOF(sounds\m230\closedist_7.ogg), 1 },
            { QPATHTOF(sounds\m230\closedist_8.ogg), 1 }
        };
    };
    class GVAR(m230_mediumdistance_soundshader) : jsrs_2025_autocannon_small_mediumdistance_shot_soundshader {
        samples[] = {
            { QPATHTOF(sounds\m230\medium_1.ogg), 1 },
            { QPATHTOF(sounds\m230\medium_2.ogg), 1 },
            { QPATHTOF(sounds\m230\medium_3.ogg), 1 },
            { QPATHTOF(sounds\m230\medium_4.ogg), 1 },
            { QPATHTOF(sounds\m230\medium_5.ogg), 1 },
            { QPATHTOF(sounds\m230\medium_6.ogg), 1 },
            { QPATHTOF(sounds\m230\medium_7.ogg), 1 },
            { QPATHTOF(sounds\m230\medium_8.ogg), 1 }
        };
    };
    class GVAR(m230_fardistance_soundshader) : jsrs_2025_autocannon_small_fardistance_shot_soundshader {
        samples[] = {
            { QPATHTOF(sounds\m230\far_1.ogg), 1 },
            { QPATHTOF(sounds\m230\far_2.ogg), 1 },
            { QPATHTOF(sounds\m230\far_3.ogg), 1 },
            { QPATHTOF(sounds\m230\far_4.ogg), 1 },
            { QPATHTOF(sounds\m230\far_5.ogg), 1 },
            { QPATHTOF(sounds\m230\far_6.ogg), 1 },
            { QPATHTOF(sounds\m230\far_7.ogg), 1 },
            { QPATHTOF(sounds\m230\far_8.ogg), 1 }
        };
    };
};

class CfgSoundSets {
    class jsrs_2025_autocannon_small_shot_soundset;
    class GVAR(m230_shot_soundset) : jsrs_2025_autocannon_small_shot_soundset {
        soundShaders[] = {
            "jsrs_2025_interior_casing_soundshader",
            "jsrs_2025_autocannon_shells_new_soundshader",
            QGVAR(m230_cockpit_soundshader),
            QGVAR(m230_close_soundshader),
            QGVAR(m230_closedistance_soundshader),
            QGVAR(m230_mediumdistance_soundshader),
            QGVAR(m230_fardistance_soundshader)
        };
        frequencyRandomizer = 0.5;
    };
};
