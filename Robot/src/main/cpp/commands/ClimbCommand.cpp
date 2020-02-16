/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/ClimbCommand.h"

ClimbCommand::ClimbCommand(ClimbSubsystem* subsystem)
    : m_subsystem{subsystem} {}


// ***** public methods *****

// Called just before this Command runs the first time
void ClimbCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ClimbCommand::Execute()
{
    // speed is set from right joystick Y on controller 1
    g_controller1->GetState();
 
    m_subsystem->SetSpeed(g_controller1->GetRightY());
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbCommand::IsFinished()
{
    return false;
}
