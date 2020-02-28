/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/AutoConveyerCommand.h"

AutoConveyerCommand::AutoConveyerCommand(units::time::second_t maxTime, 
        units::time::second_t delayTime, double speed, ConveyerSubsystem *subsystem)
    : m_subsystem{subsystem}
    , m_speed(speed)
    , m_maxTime(maxTime)
    , m_maxDelayTime(delayTime)
    , m_started(false)
{
}


// ***** public methods *****

// Called just before this Command runs the first time
void AutoConveyerCommand::Initialize()
{
    m_delayTimer.Reset();
    m_delayTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoConveyerCommand::Execute()
{
    if (m_delayTimer.Get() < m_maxDelayTime)
    {
        return; // not ready yet
    }

    if (!m_started)
    {
        m_timer.Reset();
        m_timer.Start();
        m_started = true;
    }

    m_subsystem->SetSpeed(m_speed);
}

void AutoConveyerCommand::End(bool interrupted)
{
    printf("Stopped conveyor\n");
    m_subsystem->SetSpeed(0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoConveyerCommand::IsFinished()
{
    return (m_timer.Get() > m_maxTime);
}
