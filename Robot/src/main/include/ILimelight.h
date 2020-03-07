#pragma once
#include <networktables/NetworkTableInstance.h>
#include "Definitions.h"

class ILimelight
{
// Constructor / destructor
public:
    ILimelight() = default;
    ~ILimelight() = default;

// Methods
public:
    // Limelight Gets
    double GetHorizontalAngle();
    double GetVerticalAngle();
    double GetSkewAngle();
    double GetDistanceToTarget();
    bool TargetIsVisible();

    // Limelight Sets
    void SetLedMode(const LedMode &mode);

private:
     // Limelight Network Table
     std::shared_ptr<nt::NetworkTable> GetNetworkTable();

     // Limelight Mounted Angle
     double k_limelightAngle = 17.525;

     // Target Height
     // 98 -> Target Height
     // 38 -> Limelight Height
     double k_targetHeight = 60.0;  // 98-38
};