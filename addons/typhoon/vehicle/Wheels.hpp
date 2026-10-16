class Wheels : Wheels {
    class Wheel_1 : Wheel_1 {
        width = 0.16;
        mass = 25;
        MOI = 0.7;
        dampingRate = 0.25;
        longitudinalStiffnessPerUnitGravity = 2000;
        frictionVsSlipGraph[] = {{0, 0.6}, {0.2, 1}, {0.6, 0.8}};
        sprungMass = 3410;
        springStrength = 60000;
        springDamperRate = 30000;
        maxCompression = 0.15;
        maxDroop = 0.1;
    };
    class Wheel_2 : Wheel_2 {
        width = 0.2;
        mass = 50;
        MOI = 3.3;
        dampingRate = 0.25;
        maxBrakeTorque = 10000;
        longitudinalStiffnessPerUnitGravity = 2500;
        frictionVsSlipGraph[] = {{0, 0.6}, {0.2, 1}, {0.6, 0.8}};
        sprungMass = 3795;
        springStrength = 60000;
        springDamperRate = 30000;
        maxCompression = 0.1;
        maxDroop = 0.05;
    };
    class Wheel_3 : Wheel_3 {
        width = 0.2;
        mass = 50;
        MOI = 3.3;
        dampingRate = 0.25;
        maxBrakeTorque = 10000;
        longitudinalStiffnessPerUnitGravity = 2500;
        frictionVsSlipGraph[] = {{0, 0.6}, {0.2, 1}, {0.6, 0.8}};
        sprungMass = 3795;
        springStrength = 60000;
        springDamperRate = 30000;
        maxCompression = 0.1;
        maxDroop = 0.05;
    };
};
