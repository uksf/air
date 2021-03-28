class CfgCloudlets {
    class BodyTrail;
    class BodyTrailMed;
    class GVAR(BodyTrail) : BodyTrail {
        lifeTime = 0.0002;
        lifeTimeVar = 0.0001;
        size[] = { 1.5 };
        sizeVar = 0.75;
        colorCoef[] = { 1, 1, 1, "(accelY interpolate [80,250,0,1]) * ((altitude*altitude) interpolate [400,10000,2,0.5])" };
    };
    class GVAR(BodyTrailMed) : BodyTrailMed {
        lifeTime = 0.0001;
        lifeTimeVar = 5e-005;
        size[] = { 1.5 };
        sizeVar = 0.75;
        colorCoef[] = { 1, 1, 1, "(accelY interpolate [80,250,0,1]) * ((altitude*altitude) interpolate [400,10000,2,0.5])" };
    };
};
class BodyVortices;
class GVAR(BodyVortices) : BodyVortices {
    class BodyTrail1 {
        simulation = "particles";
        type = QGVAR(BodyTrail);
        qualityLevel = 2;
        enabled = "accelY interpolate [79.9999999,80,-1,1]";
    };
    class BodyTrail1Med {
        simulation = "particles";
        type = QGVAR(BodyTrailMed);
        qualityLevel = 1;
        enabled = "accelY interpolate [79.9999999,80,-1,1]";
    };
};
