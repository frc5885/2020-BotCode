/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/AutoShooterCommand.h"

AutoShooterCommand::AutoShooterCommand(units::time::second_t maxTime, double speed, 
    ShooterSubsystem* subsystem)
    : m_subsystem{subsystem}
    , m_speed(speed)
    , m_maxTime(maxTime)
{
}


// ***** public methods *****

// Called just before this Command runs the first time
void AutoShooterCommand::Initialize()
{
    printf("shooter intialize\n");
    m_timer.Reset();
    m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoShooterCommand::Execute()
{
    // speed is set from left trigger
    g_controller1->GetState();
    m_subsystem->SetSpeed(m_speed);
}

void AutoShooterCommand::End(bool interrupted)
{
    m_subsystem->SetSpeed(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoShooterCommand::IsFinished()
{
   return (m_timer.Get() > m_maxTime);
}
