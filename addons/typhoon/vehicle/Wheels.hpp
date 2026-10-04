// PhysX gear for airplaneX, on the Buzzard's wheel classes and the Wheel_N_center/_rim points the
// model recipe adds. Real Typhoon tyres: nose about 0.47 m, mains about 0.73 m across. Springs and
// dampers keep the vanilla jets' ratios to sprung mass (100x and 20x). Sprung masses follow the
// centre of mass at the model origin: the nose wheel is 2.49 m ahead of it and the mains 1.12 m
// behind, so the nose carries about 31%. Brakes, rolling damping and tyre grip are the F/A-181's,
// an aircraft of the same mass; the Buzzard's free-rolling values let the jet coast at idle.
// The real nose wheel has no brake.
class Wheels : Wheels {
    class Wheel_1 : Wheel_1 {
        width = 0.16;
        mass = 25;
        MOI = 0.7;
        dampingRate = 0.25;
        longitudinalStiffnessPerUnitGravity = 2000;
        frictionVsSlipGraph[] = {{0, 0.6}, {0.2, 1}, {0.6, 0.8}};
        sprungMass = 3410;
        springStrength = 341000;
        springDamperRate = 68200;
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
        springStrength = 379500;
        springDamperRate = 75900;
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
        springStrength = 379500;
        springDamperRate = 75900;
        maxCompression = 0.1;
        maxDroop = 0.05;
    };
};
