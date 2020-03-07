/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/ShooterCommand.h"

ShooterCommand::ShooterCommand(ShooterSubsystem* subsystem)
    : m_subsystem{subsystem} {}


// ***** public methods *****

// Called just before this Command runs the first time
void ShooterCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ShooterCommand::Execute()
{
    // speed is set from left trigger
    // g_controller1->GetState();
 
    double motorSpeed = 1.2 * g_controller1->GetLeftTrig();
    m_subsystem->SetSpeeds(motorSpeed, motorSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterCommand::IsFinished()
{
    return false;
}
