/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ControllerState.h"
#include "RobotContainer.h"

RobotContainer::RobotContainer() 
    : m_autonomousCommand(&m_exampleSubsystem) 
    , m_driveCommand(&m_driveSubsystem)
{
    // Initialize all of your commands and subsystems here

    // Configure the button bindings
    ConfigureButtonBindings();
}


// ***** public methods *****

frc2::Command *RobotContainer::GetAutonomousCommand()
{
    // An example command will be run in autonomous
    return &m_autonomousCommand;
}

frc2::Command *RobotContainer::GetDriveCommand()
{
    // teleop drive command
    return &m_driveCommand;
}


// ***** private methods *****
void RobotContainer::ConfigureButtonBindings() 
{
    // Initialize classes for xbox controllers
    g_controller0 = std::make_unique<ControllerState>(0);
    g_controller1 = std::make_unique<ControllerState>(1);
    g_controller0->InitializeButtonStates();
    g_controller1->InitializeButtonStates();
}
