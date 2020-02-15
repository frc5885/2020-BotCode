/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem()
    : m_motorSpeed(0.0), m_motorDirection(0), m_pivotSpeed(0.0)
{
   // motor controller
   m_motor = std::make_shared<WPI_TalonSRX>(INTAKE_WHEELS_CAN_ID);
   m_motor->SetSafetyEnabled(true);
   m_motor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

   m_pivot_motor = std::make_shared<WPI_TalonSRX>(INTAKE_PIVOT_CAN_ID);
   m_pivot_motor->SetSafetyEnabled(true);
   m_pivot_motor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void IntakeSubsystem::SetPivotSpeed(double pivotSpeed)
{
    if (pivotSpeed > 0.5)
    {
        pivotSpeed = 0.5;
    }

    if (pivotSpeed < -0.5)
    {
        pivotSpeed = -0.5;
    }

    m_pivotSpeed = pivotSpeed;
}

void IntakeSubsystem::SetSpeed(double motorSpeed)
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

void IntakeSubsystem::SetDirection(int direction)
{
    m_motorDirection = (direction >= 0) ? 1 : -1;
}

void IntakeSubsystem::Periodic()
{
    m_motor->Set(m_motorSpeed * m_motorDirection);
    m_pivot_motor->Set(m_pivotSpeed);
}
