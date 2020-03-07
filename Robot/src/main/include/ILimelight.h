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
    bool GetVisibleTarget();
    
    // Limelight Sets
    void SetLedMode(const LedMode &mode);

private:
     // Limelight Network Table
     std::shared_ptr<nt::NetworkTable> GetNetworkTable();
};