/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/ConveyerCommand.h"

ConveyerCommand::ConveyerCommand(ConveyerSubsystem *subsystem)
    : m_subsystem{subsystem} {}

// ***** public methods *****

// Called just before this Command runs the first time
void ConveyerCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ConveyerCommand::Execute()
{
    m_subsystem->SetSpeed((int)g_controller1->GetLeftY() * 0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool ConveyerCommand::IsFinished()
{
    return false;
}
