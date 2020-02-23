/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/ColorWheelCommand.h"
#include <frc/DriverStation.h>

ColorWheelCommand::ColorWheelCommand(ColorWheelSubsystem *subsystem)
    : m_subsystem{subsystem}
    , m_counter(0)
    , m_prevColor(frc::Color(0,0,0))
    , m_targetColor(kGreenTarget) {}

// ***** public methods *****

// Called just before this Command runs the first time
void ColorWheelCommand::Initialize()
{
    m_colorMap['R'] = kRedTarget;
    m_colorMap['G'] = kGreenTarget;
    m_colorMap['B'] = kBlueTarget;
    m_colorMap['Y'] = kYellowTarget;
}

// Called repeatedly when this Command is scheduled to run
void ColorWheelCommand::Execute()
{
    m_gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

    // Stage 1
    // do nothing

    // Stage 2
    if (m_gameData.length() == 0)
    {
        frc::Color curColor = m_subsystem->GetColor();

        if (m_counter <= 6)
        {
            m_subsystem->SetSpeed(0.4);

            if (curColor == m_targetColor && !(m_prevColor == curColor))
                m_counter++;
        }

        m_prevColor = curColor;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool ColorWheelCommand::IsFinished()
{
    return false;
}
