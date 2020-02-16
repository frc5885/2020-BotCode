/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/ColorWheelCommand.h"

ColorWheelCommand::ColorWheelCommand(ColorWheelSubsystem *subsystem)
    : m_subsystem{subsystem} {}

// ***** public methods *****

// Called just before this Command runs the first time
void ColorWheelCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ColorWheelCommand::Execute()
{
    // speed is set from right trigger on controller 1
    // direction is set from Y(forward) or B(reverse) buttons on controller 1
    g_controller1->GetState();

    m_subsystem->SetSpeed(g_controller1->GetLeftBumper());
}

// Make this return true when this Command no longer needs to run execute()
bool ColorWheelCommand::IsFinished()
{
    return false;
}
