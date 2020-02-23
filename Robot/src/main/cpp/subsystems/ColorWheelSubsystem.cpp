/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/util/color.h>

#include "Constants.h"
#include "subsystems/ColorWheelSubsystem.h"

ColorWheelSubsystem::ColorWheelSubsystem()
    : m_motorSpeed(0.0)
{
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);

    m_motor = std::make_shared<WPI_TalonSRX>(COLOR_WHEEL_CAN_ID);
    m_motor->SetSafetyEnabled(true);
    m_motor->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
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

frc::Color ColorWheelSubsystem::GetColor()
{
    double confidence = 0.0;
    return m_colorMatcher.MatchClosestColor(detectedColor, confidence);
}

frc::Color ColorWheelSubsystem::GetRawColor()
{
    return m_colorSensor.GetColor();
}

void ColorWheelSubsystem::Periodic()
{
    m_motor->Set(m_motorSpeed);
    detectedColor = m_colorSensor.GetColor();
}


