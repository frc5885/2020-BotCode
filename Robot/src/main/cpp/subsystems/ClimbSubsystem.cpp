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
    m_motorOne = std::make_shared<WPI_TalonSRX>(CLIMB_ONE_CAN_ID);
    //m_motorOne->SetInverted(true);
    m_motorOne->SetSafetyEnabled(true);
    m_motorOne->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

    m_motorTwo = std::make_shared<WPI_TalonSRX>(CLIMB_TWO_CAN_ID);
    //m_motorTwo->SetInverted(true);
    m_motorTwo->SetSafetyEnabled(true);
    m_motorTwo->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
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
    if (std::abs(m_motorSpeed) < .05)
    {
        m_motorOne->Set(0.0);
        m_motorTwo->Set(0.0);
    }
    else
    {
        m_motorOne->Set(m_motorSpeed);
        m_motorTwo->Set(ControlMode::Follower, CLIMB_ONE_CAN_ID);
    }
}
