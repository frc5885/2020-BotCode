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
    double GetHorizontalOffset();
    double GetVerticalOffset();
    double GetDistanceToTarget();
    bool GetVisibleTarget();

    // Limelight Sets
    void SetLedMode(const LedMode &mode);

private:
     // Limelight Network Table
     std::shared_ptr<nt::NetworkTable> GetNetworkTable();

     // DEG to RAD
     double GetRadians(double degree);

     // Limelight Mounted Angle
     double k_limelightAngle = 60.0;

     // Target Height
     // 2.49555 -> Target Height
     // 0.965   -> Limelight Height
     double k_targetHeight = 2.49555 - 0.965;
};