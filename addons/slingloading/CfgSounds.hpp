class CfgSounds {
    sounds[] = {};
    class GVAR(SlingLoadDownExt) {
        sound[] = { "A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT", 1.2589254, 1, 500 };  // filename, volume, pitch, distance (optional)
        titles[] = {};
        frequency = 1;
        volume = "camPos * (slingLoadActive factor [0, -1])";
    };
    class GVAR(SlingLoadUpExt) {
        sound[] = { "A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT", 1.2589254, 1, 500 };
        titles[] = {};
        frequency = 1;
        volume = "camPos * (slingLoadActive factor [0, 1])";
    };
};
