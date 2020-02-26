/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveDistance.h"

DriveDistance::DriveDistance(units::time::second_t time, double speed, DriveSubsystem *subsystem)
    : m_subsystem{subsystem},
      m_speed(speed),
      m_maxTime(time)
{
    AddRequirements({subsystem});
}

void DriveDistance::Initialize()
{
    printf("trigger");
    m_timer.Reset();
    m_timer.Start();
    m_subsystem->SetLeftSpeed(0.5);
    m_subsystem->SetRightSpeed(0.5);
}

void DriveDistance::End(bool interrupted)
{
    m_subsystem->SetLeftSpeed(0.0);
    m_subsystem->SetRightSpeed(0.0);
    printf("end");
}

bool DriveDistance::IsFinished()
{
    printf("is finished?");
    return m_timer.Get() <= m_maxTime;
}