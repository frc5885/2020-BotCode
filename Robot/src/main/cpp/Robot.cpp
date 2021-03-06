/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() 
{
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() 
{
    // m_autonomousCommand = m_container.GetAutonomousCommand();

    // if (m_autonomousCommand != nullptr) 
    // {
    //     m_autonomousCommand->Schedule();
    // }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() 
{
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    // if (m_autonomousCommand != nullptr) 
    // {
    //     m_autonomousCommand->Cancel();
    //     m_autonomousCommand = nullptr;
    // }

    m_driveCommand = m_container.GetDriveCommand();

    if (m_driveCommand != nullptr)
    {
        m_driveCommand->Schedule();
    }

    m_intakeCommand = m_container.GetIntakeCommand();

    if (m_intakeCommand != nullptr)
    {
        m_intakeCommand->Schedule();
    }

    m_conveyerCommand = m_container.GetConveyerCommand();

    if (m_conveyerCommand != nullptr)
    {
        m_conveyerCommand->Schedule();
    }

    m_shooterCommand = m_container.GetShooterCommand();

    if (m_shooterCommand != nullptr)
    {
        m_shooterCommand->Schedule();
    }

    m_climbCommand = m_container.GetClimbCommand();

    if (m_climbCommand != nullptr)
    {
        m_climbCommand->Schedule();
    }

    m_colorWheelCommand = m_container.GetColorWheelCommand();

    if (m_colorWheelCommand != nullptr)
    {
        m_colorWheelCommand->Schedule();
    }

    // m_testCommand = m_container.GetShooterCommand();

    // if (m_testCommand != nullptr)
    // {
    //     m_testCommand->Schedule();
    // }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() 
{
    
}

void Robot::TestInit()
{
    // m_testCommand = m_container.GetShooterCommand();

    // if (m_testCommand != nullptr)
    // {
    //     m_testCommand->Schedule();
    // }
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic()
{

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
