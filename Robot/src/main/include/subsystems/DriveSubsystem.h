/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "ctre/Phoenix.h"
#include "frc/SpeedControllerGroup.h"
#include "frc/drive/DifferentialDrive.h"
#include "Definitions.h"
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableInstance.h>
#include "ILimelight.h"

class DriveSubsystem : public frc2::SubsystemBase 
{
public:
    DriveSubsystem();

// public methods
public:
    // Set left and right motor speeds
    void SetLeftSpeed(double leftSpeed);
    void SetRightSpeed(double rightSpeed);

    // Will be called periodically whenever the CommandScheduler runs.
    void Periodic() override;
    
    // Limelight Gets
    double GetLimeHorizontalOffset();
    double GetLimeVerticalOffset();
    bool GetLimeVisibleTarget();
    
    // Limelight Sets
    void SetLimeLedMode(LedMode ledMode);

    // properties
private:
    // Components (e.g. motor controllers and sensors) should generally be
    // declared private and exposed only through public methods.
     std::shared_ptr<WPI_TalonSRX> m_leftFrontMotor;
     std::shared_ptr<WPI_TalonSRX> m_leftRearMotor;
     std::shared_ptr<frc::SpeedControllerGroup> m_leftController;
     std::shared_ptr<WPI_TalonSRX> m_rightFrontMotor;
     std::shared_ptr<WPI_TalonSRX> m_rightRearMotor;
     std::shared_ptr<frc::SpeedControllerGroup> m_rightController;
     std::shared_ptr<frc::DifferentialDrive> m_drive;

    // Class with 'friendly' Limelight functions
    ILimelight m_limelight;

    // left / right motor speeds (-1 -> 1)
     double m_leftSpeed, m_rightSpeed;
};
