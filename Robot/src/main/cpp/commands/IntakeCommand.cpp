/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/IntakeCommand.h"

IntakeCommand::IntakeCommand(IntakeSubsystem* subsystem)
    : m_subsystem{subsystem} {}


// ***** public methods *****

// Called just before this Command runs the first time
void IntakeCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void IntakeCommand::Execute()
{
    // speed is set from right trigger on controller 1
    // direction is set from Y(forward) or B(reverse) buttons on controller 1
    g_controller1->GetState();

    bool bumper_state = g_controller1->m_controller.GetRawButtonPressed(BUMPER_RIGHT);

    if (bumper_state)
        m_subsystem->SetPivotSpeed(0.5);
    else
        m_subsystem->SetPivotSpeed(-0.5);

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCommand::IsFinished()
{
    return false;
}
