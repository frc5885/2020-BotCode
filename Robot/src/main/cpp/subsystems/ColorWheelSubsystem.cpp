/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/ColorWheelSubsystem.h"

ColorWheelSubsystem::ColorWheelSubsystem()
    : m_motorSpeed(0.0)
{
    // motor controller
    m_motor = std::make_shared<WPI_TalonSRX>(COLOR_WHEEL_CAN_ID);
    m_motor ->SetSafetyEnabled(true);
    m_motor ->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void ColorWheelSubsystem::SetSpeed(double motorSpeed)
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

void ColorWheelSubsystem::Periodic()
{
    m_motor->Set(m_motorSpeed);
}
