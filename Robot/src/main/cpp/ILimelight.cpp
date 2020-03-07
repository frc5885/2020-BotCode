#include "ILimelight.h"

#include <math.h>

// ***** Public Methods *****
 
// Limelight Gets
double ILimelight::GetHorizontalOffset()
{
    return GetNetworkTable()->GetEntry("ty").GetDouble(0);
}

double ILimelight::GetVerticalOffset()
{
    return GetNetworkTable()->GetEntry("tx").GetDouble(0);
}

double ILimelight::GetDistanceToTarget()
{
    double trueAngle = GetRadians(k_limelightAngle - GetNetworkTable()->GetEntry("ty").GetDouble(0));
    return k_targetHeight / tan(trueAngle);
}

bool ILimelight::GetVisibleTarget()
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

double ILimelight::GetRadians(double degree)
{
    return (degree * 3.14159265) / 180;
}
