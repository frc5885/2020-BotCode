/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem()
    : m_topMotorSpeed(0.0)
    , m_bottomMotorSpeed(0.0)
{
   // motor controllers
   m_topMotor = std::make_shared<WPI_TalonSRX>(TOP_SHOOTER_TOP_CAN_ID);
   m_topMotor->SetSafetyEnabled(true);
   m_topMotor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);

   m_bottomMotor = std::make_shared<WPI_TalonSRX>(BOTTOM_SHOOTER_CAN_ID);
   m_bottomMotor->SetSafetyEnabled(true);
   m_bottomMotor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

void ShooterSubsystem::SetSpeed(double motorSpeed)
{
    if (motorSpeed > 1.0)
    {
        motorSpeed = 1.0;
    }

    if (motorSpeed < -1.0)
    {
        motorSpeed = -1.0;
    }

    m_topMotorSpeed = -motorSpeed;
    m_bottomMotorSpeed = motorSpeed;

    printf("Speed set\n");
}

void ShooterSubsystem::Periodic()
{
    m_topMotor->Set(m_topMotorSpeed);
    m_bottomMotor->Set(m_bottomMotorSpeed);

    printf("Top motor = %3.2f bottom motor = %3.2f\n", m_topMotorSpeed, m_bottomMotorSpeed);
}
