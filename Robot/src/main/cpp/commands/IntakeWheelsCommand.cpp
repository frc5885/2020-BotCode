/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/IntakeWheelsCommand.h"

IntakeWheelsCommand::IntakeWheelsCommand(IntakeWheelsSubsystem* subsystem)
    : m_subsystem{subsystem} {}


// ***** public methods *****

// Called just before this Command runs the first time
void IntakeWheelsCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void IntakeWheelsCommand::Execute()
{
    // speed is set from right trigger on controller 1
    // direction is set from Y(forward) or B(reverse) buttons on controller 1
    g_controller1->GetState();
 
    m_subsystem->SetSpeed(g_controller1->GetRightTrig());

    if (g_controller1->m_controller.GetRawButtonPressed(BUTTON_Y))
    {
        m_subsystem->SetDirection(DIRECTION_FWD);
    }
    else if (g_controller1->m_controller.GetRawButtonPressed(BUTTON_B))
    {
        m_subsystem->SetDirection(DIRECTION_REV);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeWheelsCommand::IsFinished()
{
    return false;
}
