/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "ctre/Phoenix.h"
#include <frc2/command/SubsystemBase.h>

class ShooterSubsystem : public frc2::SubsystemBase 
{
public:
    ShooterSubsystem();

// public methods
public:
    // Set motor speed and direction
    void SetSpeed(double motorSpeed);

    // Will be called periodically whenever the CommandScheduler runs.
    void Periodic() override;

// properties
 private:
    // Components (e.g. motor controllers and sensors) should generally be
    // declared private and exposed only through public methods.
     std::shared_ptr<WPI_TalonSRX> m_topMotor;
     std::shared_ptr<WPI_TalonSRX> m_bottomMotor;

     //motor speeds (-1 -> 1)
     double m_topMotorSpeed, m_bottomMotorSpeed;
};
