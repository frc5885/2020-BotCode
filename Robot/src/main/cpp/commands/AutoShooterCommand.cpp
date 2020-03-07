/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/AutoShooterCommand.h"

bool g_autoShooterCommandFinished = false;

AutoShooterCommand::AutoShooterCommand(units::time::second_t maxTime, double upperSpeed, 
    double lowerSpeed, ShooterSubsystem* subsystem)
    : m_subsystem{subsystem}
    , m_upperSpeed(upperSpeed)
    , m_lowerSpeed(lowerSpeed)
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
    g_autoShooterCommandFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoShooterCommand::Execute()
{
    m_subsystem->SetSpeeds(m_upperSpeed, m_lowerSpeed);
}

void AutoShooterCommand::End(bool interrupted)
{
    m_subsystem->SetSpeeds(0.0, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoShooterCommand::IsFinished()
{
   bool finished = (m_timer.Get() > m_maxTime);

   if (finished)
   {
       g_autoShooterCommandFinished = true;
   }

   return finished;
}
