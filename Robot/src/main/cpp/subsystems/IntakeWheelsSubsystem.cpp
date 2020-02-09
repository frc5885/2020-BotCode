/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/IntakeWheelsSubsystem.h"

IntakeWheelsSubsystem::IntakeWheelsSubsystem()
    : m_motorSpeed(0.0)
    , m_motorDirection(0)
{
   // motor controller
   m_motor = std::make_shared<WPI_TalonSRX>(INTAKE_WHEELS_CAN_ID);
   m_motor->SetSafetyEnabled(true);
   m_motor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void IntakeWheelsSubsystem::SetSpeed(double motorSpeed)
{
    if (motorSpeed > 1.0)
    {
        motorSpeed = 1.0;
    }

    if (motorSpeed < -1.0)
    {
        motorSpeed = -1.0;
    }

    m_motorSpeed = motorSpeed;
}

void IntakeWheelsSubsystem::SetDirection(int direction)
{
    m_motorDirection = (direction >= 0) ? 1 : -1;
}

void IntakeWheelsSubsystem::Periodic()
{
    m_motor->Set(m_motorSpeed * m_motorDirection);
}
