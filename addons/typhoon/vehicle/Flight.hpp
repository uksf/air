landingSpeed = 260;
acceleration = 300;
maxSpeed = 2100;
altFullForce = 13000;
altNoForce = 19800;
gearUpTime = 5;
gearDownTime = 5;
vtol = 0;
rudderInfluence = 0.2;
elevatorControlsSensitivityCoef = 4;
aileronControlsSensitivityCoef = 4;
rudderControlsSensitivityCoef = 4;

draconicForceXCoef = 10;
draconicForceYCoef = 2;
draconicForceZCoef = 0.05;
draconicTorqueXCoef[] = { 4, 5.1, 6.1, 7, 7.7, 8.3, 9, 9.1, 9.2, 9.2, 9.2 };
draconicTorqueYCoef[] = { 1, 1.2, 1.4, 0.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

envelope[] = { 0, 1, 1.4, 1.8, 2.2, 2.6, 3.4, 4.4, 5.6, 7, 8.4, 9.2, 9.4, 9.2, 8.8, 8.4, 8 };
thrustCoef[] = { 1.19, 1.19, 1.19, 1.19, 1.233, 1.275, 1.318, 1.36, 1.36, 1.275, 1.148, 1.02, 0.85, 0.595, 0.255, 0 };
elevatorCoef[] = { 0.5, 0.6, 0.7, 0.65, 0.6, 0.55, 0.5, 0.45, 0.4, 0.35, 0.3, 0.25, 0.22, 0.2, 0.18, 0.16 };
aileronCoef[] = { 0.6, 1, 1.1, 1.15, 1.2, 1.2, 1.15, 1.1, 1.05, 1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.45 };
rudderCoef[] = { 0.5, 1.8, 2.6, 2.75, 2.8, 2.85, 2.9, 2.95, 2.98, 3.01, 2.7, 1.1, 0.9, 0.7, 0.5, 0.3 };

airFrictionCoefs0[] = { 0, 0, 0 };
airFrictionCoefs1[] = { 0.1, 0.05, 0.006 };
airFrictionCoefs2[] = { 0.001, 0.0005, 0.00006 };
angleOfIndicence = "rad 1";
landingAoa = "rad 10";
flapsFrictionCoef = 0.4;
airBrake = 1;
airBrakeFrictionCoef = 3;
brakeDistance = 200;
wheelSteeringSensitivity = 2;
maxOmega = 2000;
