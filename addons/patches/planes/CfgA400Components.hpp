class Components : Components {
    class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
        defaultDisplay = "EmptyDisplay";
        class Components {
            class SensorsDisplay {
                componentType = "SensorsDisplayComponent";
                range[] = { 16000, 8000, 4000, 2000 };
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
            class SensorsDisplay {
                componentType = "SensorsDisplayComponent";
                range[] = { 16000, 8000, 4000, 2000 };
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
    class SensorsManagerComponent {
        class Components {
            class PassiveSensorComponent : SensorTemplatePassiveRadar {};
            class DataLinkSensorComponent : SensorTemplateDataLink {};
        };
    };
};
