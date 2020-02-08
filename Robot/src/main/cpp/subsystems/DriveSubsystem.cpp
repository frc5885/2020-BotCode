/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
    : m_leftSpeed(0)
    , m_rightSpeed(0)
{
   // motor controllers
   m_leftFrontMotor = std::make_shared<WPI_TalonSRX>(LF_CAN_ID);
   m_leftRearMotor = std::make_shared<WPI_TalonSRX>(LR_CAN_ID);
   m_rightFrontMotor = std::make_shared<WPI_TalonSRX>(RF_CAN_ID);
   m_rightRearMotor = std::make_shared<WPI_TalonSRX>(RR_CAN_ID);

   // speed controllers
   m_leftController = std::make_shared<frc::SpeedControllerGroup>(*m_leftFrontMotor, *m_leftRearMotor);
//   AddChild("Left Speed Controller", m_leftController);
   m_rightController = std::make_shared<frc::SpeedControllerGroup>(*m_rightFrontMotor, *m_rightRearMotor);
//   AddChild("Right Speed Controller", m_rightController);

   // differential drive
   m_drive = std::make_shared<frc::DifferentialDrive>(*m_leftController, *m_rightController);
//   AddChild("Differential Drive", m_drive);
   m_drive->SetSafetyEnabled(true);
   m_drive->SetExpiration(0.1);
   m_drive->SetMaxOutput(1.0);
}

void DriveSubsystem::SetLeftSpeed(double motorSpeed)
{
    if (motorSpeed > 1.0)
    {
        motorSpeed = 1.0;
    }

    if (motorSpeed < -1.0)
    {
        motorSpeed = -1.0;
    }

    m_leftSpeed = motorSpeed;
}

void DriveSubsystem::SetRightSpeed(double motorSpeed)
{
    if (motorSpeed > 1.0)
    {
        motorSpeed = 1.0;
    }

    if (motorSpeed < -1.0)
    {
        motorSpeed = -1.0;
    }

    m_rightSpeed = motorSpeed;
}

void DriveSubsystem::Periodic()
{
//    printf("left speed = %3.2f right speed = %3.2f\n", m_leftSpeed, m_rightSpeed);
    m_drive->TankDrive(m_leftSpeed, m_rightSpeed);
}
