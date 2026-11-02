class Components : Components {
    class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
        defaultDisplay = "EmptyDisplay";
        class Components {
            class VehicleGunnerDisplay {
                componentType = "TransportFeedDisplayComponent";
                source = "PrimaryGunner";
            };
            class SensorsDisplay {
                componentType = "SensorsDisplayComponent";
                range[] = { 16000, 8000, 4000, 2000 };
                showTargetTypes = "1+2+4+8+16+32+64+128+256+512+1024";
                resource = "RscCustomInfoSensors";
            };
            class CrewDisplay {
                componentType = "CrewDisplayComponent";
                resource = "RscCustomInfoCrew";
            };
            class MinimapDisplay {
                componentType = "MinimapDisplayComponent";
                resource = "RscCustomInfoMiniMap";
            };
            class EmptyDisplay {
                componentType = "EmptyDisplayComponent";
            };
        };
    };
    class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
        defaultDisplay = "SensorsDisplay";
        class Components {
            class VehicleGunnerDisplay {
                componentType = "TransportFeedDisplayComponent";
                source = "PrimaryGunner";
            };
            class SensorsDisplay {
                componentType = "SensorsDisplayComponent";
                range[] = { 16000, 8000, 4000, 2000 };
                showTargetTypes = "1+2+4+8+16+32+64+128+256+512+1024";
                resource = "RscCustomInfoSensors";
            };
            class CrewDisplay {
                componentType = "CrewDisplayComponent";
                resource = "RscCustomInfoCrew";
            };
            class MinimapDisplay {
                componentType = "MinimapDisplayComponent";
                resource = "RscCustomInfoMiniMap";
            };
            class EmptyDisplay {
                componentType = "EmptyDisplayComponent";
            };
        };
    };
    class TransportPylonsComponent {
        uiPicture = QPATHTOF(data\ui\Apache_EDEN_CA.paa);
        class Pylons {
            class PylonLeft1 {
                attachment = "CUP_PylonPod_19Rnd_CRV7_HE_M";
                priority = 5;
                bay = -1;
                hardpoints[] = { "B_CRV7", "B_HELLFIRE" };
                UIposition[] = { 0.13, 0.3 };
                turret[] = { 0 };
            };
            class PylonLeft2 : PylonLeft1 {
                attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114N";
                priority = 4;
                hardpoints[] = { "B_CRV7", "B_HELLFIRE" };
                UIposition[] = { 0.19, 0.35 };
            };
            class PylonRight2 : PylonLeft2 {
                attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114L";
                mirroredMissilePos = 2;
                UIposition[] = { 0.43, 0.35 };
            };
            class PylonRight1 : PylonLeft1 {
                mirroredMissilePos = 1;
                UIposition[] = { 0.50, 0.3 };
            };
        };
        class Presets {
            class Empty {
                displayName = "Empty";
                attachment[] = {};
            };
            class Default {
                displayName = "CAS";
                attachment[] = { "CUP_PylonPod_19Rnd_CRV7_FAT_M", "PylonRack_4Rnd_ACE_Hellfire_AGM114N", "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "CUP_PylonPod_19Rnd_CRV7_HE_M" };
            };
            class AT {
                displayName = "AT";
                attachment[] = { "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114L" };
            };
            class Escort {
                displayName = "Escort";
                attachment[] = { "CUP_PylonPod_19Rnd_CRV7_FAT_M", "CUP_PylonPod_19Rnd_CRV7_HE_M", "CUP_PylonPod_19Rnd_CRV7_HE_M", "CUP_PylonPod_19Rnd_CRV7_FAT_M" };
            };
            class Strike {
                displayName = "Strike";
                attachment[] = { "PylonRack_4Rnd_ACE_Hellfire_AGM114L", "PylonRack_4Rnd_ACE_Hellfire_AGM114N", "PylonRack_4Rnd_ACE_Hellfire_AGM114K", "PylonRack_4Rnd_ACE_Hellfire_AGM114L" };
            };
        };
    };
};
