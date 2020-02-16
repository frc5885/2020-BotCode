/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "ControllerState.h"
#include "commands/IntakeCommand.h"

IntakeCommand::IntakeCommand(IntakeSubsystem *subsystem)
    : m_subsystem{subsystem},
      m_pivotDownTimerStarted(false),
      m_pivotUpTimerStarted(false) {}

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

    if (g_controller1->m_controller.GetRawButton(BUTTON_X))
    {
        wheelsFwd = true;
    }
    else if (g_controller1->m_controller.GetRawButton(BUTTON_A))
    {
        wheelsFwd = false;
    }

    printf("%3.4f", static_cast<double>(m_pivotTimer.Get()));
    printf("%d", (int)g_controller1->m_controller.GetRawButton(BUMPER_RIGHT));

    // turn on the intake wheels and pivot the intake
    // if we want to run the intake wheels...
    if (g_controller1->m_controller.GetRawButton(BUMPER_RIGHT))
    {
        printf("Marker 1\n");
        // turn on intake wheels
        double speed = (wheelsFwd) ? m_kForwardWheelSpeed : m_kReverseWheelSpeed;
        m_subsystem->SetWheelSpeed(speed);

        if (!m_pivotDownTimerStarted)
        {
            printf("Marker 2\n");
            // start the timer
            m_pivotTimer.Reset();
            m_pivotTimer.Start();
            m_pivotDownTimerStarted = true;
        }

        // lower pivot
        if (m_pivotDownTimerStarted)
        {
            printf("Marker 3\n");
            if (m_pivotTimer.Get() < m_kPivotTimerDownTime)
            {
                printf("Marker 3-1\n");
                // run the pivot motor, but only for specified time
                m_subsystem->SetPivotSpeed(m_kPivotDownMotorSpeed);
            }
            else
            {
                printf("Marker 3-2\n");
                m_subsystem->SetPivotSpeed(0.0);
            }
        }
    }
    else
    {
        m_subsystem->SetWheelSpeed(0.0);
        printf("Marker 4\n");
        // if the button was previously pressed...
        if (m_pivotDownTimerStarted)
        {
            printf("Marker 5");
            m_pivotDownTimerStarted = false;    // turn off down timer
            m_pivotTimer.Reset();
            m_pivotUpTimerStarted = true;
        }

        if (m_pivotUpTimerStarted)
        {
            printf("Marker 6\n");
            if (m_pivotTimer.Get() < m_kPivotTimerUpTime)
            {
                printf("Marker 6-1\n");
                // run the pivot motor, but only for specified time
                m_subsystem->SetPivotSpeed(m_kPivotUpMotorSpeed);
            }
            else
            {
                printf("Marker 6-2\n");
                m_subsystem->SetPivotSpeed(0.0);
                m_pivotUpTimerStarted = false;
                m_pivotTimer.Stop();
            }
        }
    }
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCommand::IsFinished()
{
    return false;
}
