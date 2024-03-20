class GVAR(C130FlareLauncher) : CMFlareLauncher {
    modes[] = { "Single", "Burst1", "Burst2", "Burst3", "Burst4", "Burst5", "Burst6", "AIBurst" };
    class Single : Mode_SemiAuto {
        reloadTime = 0.125;
        autoFire = "false";
        displayName = "4F/-";
        burst = 1;
        multiplier = 4;
        sounds[] = { "StandardSound" };
        class StandardSound {
            begin1[] = { "A3\Sounds_F\weapons\HMG\HMG_grenade", 1, 1, 300 };
            soundBegin[] = { "begin1", 1 };
            weaponSoundEffect = "DefaultRifle";
        };
    };
    class Burst1 : Mode_Burst {
        reloadTime = 0.125;
        autoFire = "true";
        displayName = "40F/1.25S";
        burst = 10;
        sounds[] = { "StandardSound" };
        class StandardSound {
            begin1[] = { "A3\Sounds_F\weapons\HMG\HMG_grenade", 1, 1, 300 };
            soundBegin[] = { "begin1", 1 };
            weaponSoundEffect = "DefaultRifle";
        };
    };
    class Burst2 : Burst1 {
        reloadTime = 0.25;
        displayName = "40F/2.5S";
    };
    class Burst3 : Burst2 {
        reloadTime = 0.5;
        displayName = "40F/5S";
        burst = 10;
    };
    class Burst4 : Burst3 {
        reloadTime = 0.125;
        displayName = "80F/2.5S";
        burst = 20;
    };
    class Burst5 : Burst4 {
        reloadTime = 0.25;
        displayName = "80F/5S";
    };
    class Burst6 : Burst5 {
        reloadTime = 0.5;
        displayName = "80F/10S";
    };
};
class UK3CB_BAF_CMFlareLauncher : CMFlareLauncher {
    modes[] = { "Single", "Burst2", "Burst5", "Burst8", "AIBurst" };
    // Burst2 = 8/1s
    // Burst5 = 16/1s
    // Burst8 = 16/8s
};
