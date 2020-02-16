/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "commands/DriveCommand.h"
#include "subsystems/DriveSubsystem.h"

#include "commands/IntakeCommand.h"
#include "subsystems/IntakeSubsystem.h"

#include "commands/ShooterCommand.h"
#include "subsystems/ShooterSubsystem.h"

#include "commands/ColorWheelCommand.h"
#include "subsystems/ColorWheelSubsystem.h"

#include "commands/ConveyerCommand.h"
#include "subsystems/ConveyerSubsystem.h"

#include "commands/ClimbCommand.h"
#include "subsystems/ClimbSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer 
{
public:
    RobotContainer();

// public methods
public:
    frc2::Command* GetAutonomousCommand();
    frc2::Command* GetDriveCommand();
    frc2::Command *GetIntakeCommand();
    frc2::Command *GetShooterCommand();
    frc2::Command *GetColorWheelCommand();
    frc2::Command *GetConveyerCommand();
    frc2::Command *GetClimbCommand();

    // private properties
private:
    // The robot's subsystems and commands are defined here...
    ExampleSubsystem m_exampleSubsystem;
    ExampleCommand m_autonomousCommand;

    DriveSubsystem m_driveSubsystem;
    DriveCommand m_driveCommand;

    IntakeSubsystem m_intakeSubsystem;
    IntakeCommand m_intakeCommand;

    ShooterSubsystem m_shooterSubsystem;
    ShooterCommand m_shooterCommand;

    ColorWheelSubsystem m_colorWheelSubsystem;
    ColorWheelCommand m_colorWheelCommand;

    ConveyerSubsystem m_conveyerSubsystem;
    ConveyerCommand m_conveyerCommand;

    ClimbSubsystem m_climbSubsystem;
    ClimbCommand m_climbCommand;

    // private methods
private:
    void ConfigureButtonBindings();
};
