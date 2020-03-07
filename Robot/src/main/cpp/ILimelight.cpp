
#include <math.h>
#include "Constants.h"
#include "ILimelight.h"

// ***** Public Methods *****
 
// Limelight Gets
double ILimelight::GetHorizontalAngle()
{
    return GetNetworkTable()->GetEntry("tx").GetDouble(0);
}

double ILimelight::GetVerticalAngle()
{
    return GetNetworkTable()->GetEntry("ty").GetDouble(0);
}

double ILimelight::GetSkewAngle()
{
    return GetNetworkTable()->GetEntry("ts").GetDouble(0);
}

double ILimelight::GetDistanceToTarget()
{
    double trueAngle = kDeg2Rad*(k_limelightAngle + GetVerticalAngle());
//    printf("Ang: %3.2f\n", trueAngle);
    return (k_targetHeight / tan(trueAngle));
}

bool ILimelight::TargetIsVisible()
{
    return GetNetworkTable()->GetEntry("tv").GetBoolean(0);
}

// Limelight Sets
void ILimelight::SetLedMode(const LedMode &mode)
{
    GetNetworkTable()->PutNumber("ledMode", mode);
}


// ***** Private Methods *****

// Limelight Network Table
std::shared_ptr<nt::NetworkTable> ILimelight::GetNetworkTable()
{
    return nt::NetworkTableInstance::GetDefault().GetTable("limelight");
}
