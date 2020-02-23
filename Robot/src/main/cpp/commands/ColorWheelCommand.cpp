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
    , m_maxCounts(7)
    , m_prevColor(frc::Color(0,0,0))
    , m_targetColor(kGreenTarget)
    , m_gameData("")
{
}


// ***** public methods *****

// Called just before this Command runs the first time
void ColorWheelCommand::Initialize()
{
    m_colorMap['R'] = kRedTarget;
    m_colorMap['G'] = kGreenTarget;
    m_colorMap['B'] = kBlueTarget;
    m_colorMap['Y'] = kYellowTarget;

    m_counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void ColorWheelCommand::Execute()
{
    if (!g_controller1->m_controller.GetRawButton(BUTTON_Y))
    {
        if (m_counter >= m_maxCounts)
        {
            m_counter = 0;
        }
        
        m_subsystem->SetSpeed(0.0);
        return;
    }

    m_gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

    printf("%d\n", m_gameData[0]);

    if (m_gameData.length() == 0)
    {
        printf("No game data\n");
        // Stage 2
        m_maxCounts = 7; // stage 2 - spin wheel 3 times
        m_targetColor = kGreenTarget;   // always use green for counting
    }
    else
    {
        // Stage 3
        
        m_maxCounts = 1; // stage 3 - index to colour
        auto colourFound = m_colorMap.find(m_gameData[0]); // should be  one of R,G,B,Y

        if (colourFound != m_colorMap.end())
        {
            m_targetColor = colourFound->second;
        }
    }

    frc::Color curColor = m_subsystem->GetColor();

    printf("Counter: %d max: %d\n", m_counter, m_maxCounts);

    if (m_counter < m_maxCounts)
    {
        m_subsystem->SetSpeed(0.4);

        if (curColor == m_targetColor && !(m_prevColor == curColor))
            m_counter++;
    } 
    else
    {
        m_subsystem->SetSpeed(0.0);
    }
    
    m_prevColor = curColor;
}

// Make this return true when this Command no longer needs to run execute()
bool ColorWheelCommand::IsFinished()
{
    return false;
}
