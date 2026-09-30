class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
    class Components {
        class EmptyDisplay {
            componentType = "EmptyDisplayComponent";
        };
        class MinimapDisplay {
            componentType = "MinimapDisplayComponent";
            resource = "RscCustomInfoAirborneMiniMap";
        };
        class UAVDisplay {
            componentType = "UAVFeedDisplayComponent";
        };
        class VehicleDriverDisplay {
            componentType = "TransportFeedDisplayComponent";
            source = "Driver";
        };
        class VehicleMissileDisplay {
            componentType = "TransportFeedDisplayComponent";
            source = "Missile";
        };
        class SensorDisplay {
            componentType = "SensorsDisplayComponent";
            range[] = { 16000, 8000, 4000, 2000, 32000 };
            resource = "RscCustomInfoSensors";
        };
    };
};
class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
    defaultDisplay = "SensorDisplay";
    class Components {
        class EmptyDisplay {
            componentType = "EmptyDisplayComponent";
        };
        class MinimapDisplay {
            componentType = "MinimapDisplayComponent";
            resource = "RscCustomInfoAirborneMiniMap";
        };
        class UAVDisplay {
            componentType = "UAVFeedDisplayComponent";
        };
        class VehicleDriverDisplay {
            componentType = "TransportFeedDisplayComponent";
            source = "Driver";
        };
        class VehicleMissileDisplay {
            componentType = "TransportFeedDisplayComponent";
            source = "Missile";
        };
        class SensorDisplay {
            componentType = "SensorsDisplayComponent";
            range[] = { 16000, 8000, 4000, 2000, 32000 };
            resource = "RscCustomInfoSensors";
        };
    };
};
