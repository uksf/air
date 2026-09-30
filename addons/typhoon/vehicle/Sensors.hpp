// Typhoon FGR4 sensor fit. Ranges follow the F-35's game scale; coverage follows the real aircraft:
// a wide forward radar (Captor-E), a forward IRST (PIRATE) and DASS passive warning, but no 360 degree
// distributed aperture like the F-35.
#define SENSOR_TRACKING \
    groundNoiseDistanceCoef = -1; \
    maxGroundNoiseDistance = -1; \
    minSpeedThreshold = 0; \
    maxSpeedThreshold = 0; \
    minTrackableSpeed = -1e+010; \
    maxTrackableSpeed = 1e+010; \
    minTrackableATL = -1e+010; \
    maxTrackableATL = 1e+010
#define SENSOR_RANGE(AIR,GROUND) \
    class AirTarget { \
        minRange = AIR; \
        maxRange = AIR; \
        objectDistanceLimitCoef = -1; \
        viewDistanceLimitCoef = -1; \
    }; \
    class GroundTarget { \
        minRange = GROUND; \
        maxRange = GROUND; \
        objectDistanceLimitCoef = -1; \
        viewDistanceLimitCoef = -1; \
    }

class SensorsManagerComponent {
    class Components {
        class ActiveRadarSensorComponent {
            componentType = "ActiveRadarSensorComponent";
            SENSOR_RANGE(32000,16000);
            typeRecognitionDistance = 16000;
            angleRangeHorizontal = 140;
            angleRangeVertical = 60;
            maxSpeedThreshold = 1000;
            allowsMarking = 1;
            animDirection = "";
            aimDown = 0;
            color[] = { 0, 1, 1, 1 };
            groundNoiseDistanceCoef = -1;
            maxGroundNoiseDistance = -1;
            minSpeedThreshold = 0;
            minTrackableSpeed = -1e+010;
            maxTrackableSpeed = 1e+010;
            minTrackableATL = -1e+010;
            maxTrackableATL = 1e+010;
        };
        class IRSensorComponent {
            componentType = "IRSensorComponent";
            SENSOR_RANGE(12000,6000);
            typeRecognitionDistance = 4000;
            angleRangeHorizontal = 120;
            angleRangeVertical = 60;
            maxFogSeeThrough = 0.995;
            allowsMarking = 1;
            animDirection = "";
            aimDown = 0;
            color[] = { 1, 0, 0, 1 };
            SENSOR_TRACKING;
        };
        class VisualSensorComponent {
            componentType = "VisualSensorComponent";
            SENSOR_RANGE(8000,8000);
            typeRecognitionDistance = 2000;
            angleRangeHorizontal = 26;
            angleRangeVertical = 20;
            aimDown = 1;
            animDirection = "";
            nightRangeCoef = 0;
            maxFogSeeThrough = 0.94;
            allowsMarking = 1;
            color[] = { 1, 1, 0.5, 0.8 };
            SENSOR_TRACKING;
        };
        class PassiveRadarSensorComponent {
            componentType = "PassiveRadarSensorComponent";
            SENSOR_RANGE(32000,32000);
            typeRecognitionDistance = 32000;
            angleRangeHorizontal = 360;
            angleRangeVertical = 360;
            animDirection = "";
            aimDown = 0;
            allowsMarking = 0;
            color[] = { 0.5, 1, 0.5, 0.5 };
            SENSOR_TRACKING;
        };
        class AntiRadiationSensorComponent {
            componentType = "PassiveRadarSensorComponent";
            SENSOR_RANGE(32000,32000);
            typeRecognitionDistance = 32000;
            angleRangeHorizontal = 360;
            angleRangeVertical = 180;
            maxTrackableATL = 100;
            maxTrackableSpeed = 60;
            animDirection = "";
            aimDown = 0;
            allowsMarking = 1;
            color[] = { 0.5, 1, 0.5, 0.5 };
            groundNoiseDistanceCoef = -1;
            maxGroundNoiseDistance = -1;
            minSpeedThreshold = 0;
            maxSpeedThreshold = 0;
            minTrackableSpeed = -1e+010;
            minTrackableATL = -1e+010;
        };
        class LaserSensorComponent {
            componentType = "LaserSensorComponent";
            SENSOR_RANGE(32000,32000);
            typeRecognitionDistance = 0;
            angleRangeHorizontal = 180;
            angleRangeVertical = 180;
            animDirection = "";
            aimDown = 90;
            allowsMarking = 1;
            color[] = { 1, 1, 1, 0 };
            SENSOR_TRACKING;
        };
        class NVSensorComponent {
            componentType = "NVSensorComponent";
            SENSOR_RANGE(6000,6000);
            typeRecognitionDistance = 0;
            angleRangeHorizontal = 180;
            angleRangeVertical = 180;
            animDirection = "";
            aimDown = 0;
            allowsMarking = 1;
            color[] = { 1, 1, 1, 0 };
            SENSOR_TRACKING;
        };
        class DataLinkSensorComponent {
            componentType = "DataLinkSensorComponent";
            SENSOR_RANGE(32000,32000);
            typeRecognitionDistance = 0;
            angleRangeHorizontal = 360;
            angleRangeVertical = 360;
            animDirection = "";
            aimDown = 0;
            allowsMarking = 1;
            color[] = { 1, 1, 1, 0 };
            SENSOR_TRACKING;
        };
    };
};
