class CfgSoundShaders {
    class jsrs_2025_autocannon_small_closure_soundshader;
    class jsrs_2025_autocannon_small_close_shot_soundshader;
    class jsrs_2025_autocannon_small_closedistance_shot_soundshader;
    class jsrs_2025_autocannon_small_mediumdistance_shot_soundshader;
    class jsrs_2025_autocannon_small_fardistance_shot_soundshader;
    class jsrs_2025_tailsystem_autocannon_base_soundshader;
    class GVAR(m230_tail_base_soundshader) : jsrs_2025_tailsystem_autocannon_base_soundshader {
        rangeCurve[] = { {0, 0}, {20, 0.2}, {80, 1}, {250, 0} };
    };
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
        volume = "1.4*(1 - campos)";
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
        range = 120;
        rangeCurve[] = { {0, 0}, {5, 1}, {60, 1}, {120, 0} };
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
        rangeCurve[] = { {5, 0}, {40, 0.4}, {100, 1}, {300, 0} };
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
        volume = 2.1;
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
        volume = 3;
    };
};

class CfgDistanceFilters {
    class jsrs_2025_weapons_vehicle_lowpass_filter;
    class GVAR(m230_lowpass_filter) : jsrs_2025_weapons_vehicle_lowpass_filter {
        innerRange = 100;
    };
};

class CfgSoundSets {
    class jsrs_2025_tailsystem_Autocannon_soundset;
    class GVAR(m230_tail_soundset) : jsrs_2025_tailsystem_Autocannon_soundset {
        soundShaders[] = { QGVAR(m230_tail_base_soundshader), "jsrs_2025_tailsystem_Autocannon_scape_soundshader", "jsrs_2025_tailsystem_Autocannon_stereo_soundshader" };
    };
    class jsrs_2025_autocannon_small_shot_soundset;
    class GVAR(m230_shot_soundset) : jsrs_2025_autocannon_small_shot_soundset {
        soundShaders[] = {
            QGVAR(m230_close_soundshader),
            QGVAR(m230_closedistance_soundshader),
            QGVAR(m230_mediumdistance_soundshader),
            QGVAR(m230_fardistance_soundshader)
        };
        distanceFilter = QGVAR(m230_lowpass_filter);
        frequencyRandomizer = 0.5;
    };
    class GVAR(m230_mechanism_soundset) : jsrs_2025_autocannon_small_shot_soundset {
        soundShaders[] = { "jsrs_2025_interior_casing_soundshader", "jsrs_2025_autocannon_shells_new_soundshader" };
        frequencyRandomizer = 0.5;
    };
    class GVAR(m230_cockpit_soundset) : jsrs_2025_autocannon_small_shot_soundset {
        soundShaders[] = { QGVAR(m230_cockpit_soundshader) };
        frequencyRandomizer = 0.5;
    };
};
