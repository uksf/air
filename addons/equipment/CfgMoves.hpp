class CfgMovesBasic {
    class ManActions {
        GVAR(takeMarshallSticks) = QGVAR(takeMarshallSticks);
    };
    class Actions {
        class NoActions : ManActions {
            GVAR(takeMarshallSticks)[] = { QGVAR(takeMarshallSticks),"Gesture" };
        };
    };
};
class CfgGesturesMale {
    class Default;
    class BlendAnims {
        GVAR(takeMarshallSticks)[] = { "LeftShoulder",0,"LeftArm",0,"LeftArmRoll",0,"LeftForeArm",0,"LeftForeArmRoll",0,"LeftHand",0,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandPinky1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",0,"RightArm",0,"RightArmRoll",0,"RightForeArm",0,"RightForeArmRoll",0,"RightHand",0,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandPinky1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1 };
    };
    class States {
        class GVAR(takeMarshallSticks_base) : Default {
            actions = "NoActions";
            canPullTrigger = 0;
            connectAs = "";
            connectFrom[] = {};
            connectTo[] = {};
            disableWeapons = 1;
            enableBinocular = 0;
            enableMissile = 0;
            enableOptics = 0;
            equivalentTo = "";
            file = "\A3\anims_f\Data\Anim\Sdr\gst\GestureHi.rtm";
            forceAim = 0;
            headBobMode = 0;
            headBobStrength = 0;
            interpolateFrom[] = {};
            interpolateTo[] = {};
            interpolateWith[] = {};
            interpolationRestart = 0;
            interpolationSpeed = 6;
            looped = 1;
            mask = QGVAR(takeMarshallSticks);
            minPlayTime = 0.5;
            preload = 0;
            ragdoll = 0;
            relSpeedMax = 1;
            relSpeedMin = 1;
            showHandGun = 0;
            showItemInHand = 0;
            showItemInRightHand = 0;
            showWeaponAim = 1;
            soundEdge[] = { 0.5, 1 };
            soundEnabled = 1;
            soundOverride = "";
            speed = -2;
            static = 0;
            terminal = 0;
            Walkcycles = 1;
            weaponIK = 1;
        };
        class GVAR(takeMarshallSticks) : GVAR(takeMarshallSticks_base) {
            file = QPATHTOF(data\anims\aircraftsignals_idle.rtm);
            speed = 1;
        };
    };
};
