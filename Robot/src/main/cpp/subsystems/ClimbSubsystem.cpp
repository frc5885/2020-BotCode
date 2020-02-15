/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/ClimbSubsystem.h"

ClimbSubsystem::ClimbSubsystem()
    : m_motorSpeed(0.0)
{
   // motor controller
   m_motor = std::make_shared<WPI_TalonSRX>(CLIMB_CAN_ID);
   m_motor->SetSafetyEnabled(true);
   m_motor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void ClimbSubsystem::SetSpeed(double motorSpeed)
{
    if (motorSpeed > 1.0)
    {
        motorSpeed = 1.0;
    }

    if (motorSpeed < -1.0)
    {
        motorSpeed = -1.0;
    }

    if (std::abs(motorSpeed) < .05)
    {
        motorSpeed = 0.0;
    }

    m_motorSpeed = motorSpeed;
}

void ClimbSubsystem::Periodic()
{
    m_motor->Set(m_motorSpeed);
}
