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
    : m_pivotDownTimerStarted(false)
    , m_pivotUpTimerStarted(false)
    , m_subsystem{subsystem} {}


// ***** public methods *****

// Called just before this Command runs the first time
void IntakeCommand::Initialize()
{
    m_pivotTimer.Reset();
}

// Called repeatedly when this Command is scheduled to run
void IntakeCommand::Execute()
{
    // all motor speeds are hard-coded (see header file for values)

    // direction is set from X (forward) or A (reverse) buttons on controller 1
    g_controller1->GetState();

    // set wheel direction based on X or A button being pressed
    bool wheelsFwd = false;

    if (g_controller1->m_controller.GetRawButtonPressed(BUTTON_X))
    {
        m_subsystem->SetWheelDirection(1);
        wheelsFwd = true;
    }
    else if (g_controller1->m_controller.GetRawButtonPressed(BUTTON_A))
    {
        m_subsystem->SetWheelDirection(-1);
        wheelsFwd = false;
    }

    // turn on the intake wheels and pivot the intake
    bool bumperPressed = g_controller1->m_controller.GetRawButtonPressed(BUMPER_RIGHT);

    // if we want to run the intake wheels...
    if (bumperPressed)
    {
        // turn on intake wheels
        double speed = (wheelsFwd) ? m_kForwardWheelSpeed : m_kReverseWheelSpeed;
        m_subsystem->SetWheelSpeed(speed);

        if (!m_pivotDownTimerStarted)
        {
            // start the timer
            m_pivotTimer.Reset();
            m_pivotTimer.Start();
            m_pivotDownTimerStarted = true;
        }

        // lower pivot
        if (m_pivotDownTimerStarted)
        {
            if (m_pivotTimer.Get() < m_kPivotTimerDownTime)
            {
                // run the pivot motor, but only for specified time
                m_subsystem->SetPivotSpeed(m_kPivotDownMotorSpeed);
            }
            else
            {
                m_subsystem->SetPivotSpeed(0.0);
            }
        }
    }
    else
    {
        // if the button was previously pressed...
        if (m_pivotDownTimerStarted)
        {
            m_pivotDownTimerStarted = false;    // turn off down timer
            m_pivotTimer.Reset();
            m_pivotTimer.Start();
            m_pivotUpTimerStarted = true;
        }

        if (m_pivotUpTimerStarted)
        {
            if (m_pivotTimer.Get() < m_kPivotTimerUpTime)
            {
                // run the pivot motor, but only for specified time
                m_subsystem->SetPivotSpeed(m_kPivotUpMotorSpeed);
            }
            else
            {
                m_subsystem->SetPivotSpeed(0.0);
                m_pivotUpTimerStarted = false;
            }
        }
    } 
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCommand::IsFinished()
{
    return false;
}
