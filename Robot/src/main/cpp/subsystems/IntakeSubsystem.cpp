/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem()
    : m_pivotSpeed(0.0)
    , m_wheelSpeed(0.0)
    , m_wheelDirection(0)
{
   // motor controller
   m_wheelMotor = std::make_shared<WPI_TalonSRX>(INTAKE_WHEELS_CAN_ID);
   m_wheelMotor->SetSafetyEnabled(true);
   m_wheelMotor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

   m_pivotMotor = std::make_shared<WPI_TalonSRX>(INTAKE_PIVOT_CAN_ID);
   m_pivotMotor->SetSafetyEnabled(true);
   m_pivotMotor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
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

void IntakeSubsystem::SetWheelSpeed(double speed)
{
    if (speed > 1.0)
    {
        speed = 1.0;
    }

    if (speed < -1.0)
    {
        speed = -1.0;
    }

    m_wheelSpeed = speed;
}

void IntakeSubsystem::Periodic()
{
    m_wheelMotor->Set(m_wheelSpeed);
    m_pivotMotor->Set(m_pivotSpeed);
}
