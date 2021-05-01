class CfgWeapons {
    class ACE_NVG_Pilot;
    class GVAR(marshallSticks) : ACE_NVG_Pilot {
        author = "UKSF";
        displayName = "Aircraft Light Sticks";
        picture = QPATHTOF(data\marshall_sticks\lightsticks_ui.paa);
        model = "cxs_lightsticks\cxs_lightsticks_ground.p3d";
        class ItemInfo {
            type = 616;
            hmdType = 0;
            picture = QPATHTOF(data\marshall_sticks\lightsticks_ui.paa);
            uniformModel = "cxs_lightsticks\cxs_lightsticks.p3d";
            modelOff = "cxs_lightsticks\cxs_lightsticks.p3d";
            mass = 0;
        };
    };
};
