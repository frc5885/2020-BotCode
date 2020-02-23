/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "ctre/Phoenix.h"
#include <frc2/command/SubsystemBase.h>

#include <frc/util/color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

class ColorWheelSubsystem : public frc2::SubsystemBase
{
public:
    ColorWheelSubsystem();

    // public methods
public:
    // Set motor speed and direction
    void SetSpeed(double motorSpeed);
    frc::Color GetColor();
    frc::Color GetRawColor();

    // Will be called periodically whenever the CommandScheduler runs.
    void Periodic() override;

    // properties
private:
    // Components (e.g. motor controllers and sensors) should generally be
    // declared private and exposed only through public methods.
    std::shared_ptr<WPI_TalonSRX> m_motor;

    static constexpr auto kI2cPort = frc::I2C::Port::kOnboard;

    // Color Sensor
    rev::ColorSensorV3 m_colorSensor{kI2cPort};

    // Color matcher
    rev::ColorMatch m_colorMatcher;

    // Current color
    frc::Color detectedColor;
	
    //motor speed (-1 -> 1)
    double m_motorSpeed;
};
