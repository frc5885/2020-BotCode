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
    : m_subsystem{subsystem}
    , m_pivotTimerStarted(false)
    , m_pivotDown(false)
    , m_inIntakeMode(true)
 {
 }

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
    g_controller1->GetState();
    ControlPivot();
    ControlWheels();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCommand::IsFinished()
{
    return false;
}


// Private methods
void IntakeCommand::ControlPivot()
{
    if (g_controller1->GetRightBumper() != m_pivotDown)
    {
        // button pressed, state changed
        m_pivotDown = !m_pivotDown; // toggle the state

        // start the timer
        m_pivotTimer.Reset();
        m_pivotTimer.Start();
        m_pivotTimerStarted = true;
    }

    // set the appropriate motor speed and motor on time
    double motorSpeed = (m_pivotDown) ? m_kPivotDownMotorSpeed : m_kPivotUpMotorSpeed;
    auto pivotTime = (m_pivotDown) ? m_kPivotTimerDownTime : m_kPivotTimerUpTime;

    if (m_pivotTimerStarted)
    {
        if (m_pivotTimer.Get() < pivotTime)
        {
            // run the pivot motor, but only for specified time
            m_subsystem->SetPivotSpeed(motorSpeed);
        }
        else
        {
            m_pivotTimer.Reset();
            m_pivotTimerStarted = false;
        }
    }
    else
    {
        m_subsystem->SetPivotSpeed(0.0);
    }
}

void IntakeCommand::ControlWheels()
{
    double wheelSpeed = 0.0;

    // direction is set from X (forward) or A (reverse) buttons on controller 1
    if (g_controller1->m_controller.GetRawButton(BUTTON_X))
    {
        wheelSpeed = m_kForwardWheelSpeed;
    }
    else if (g_controller1->m_controller.GetRawButton(BUTTON_A))
    {
        wheelSpeed = m_kReverseWheelSpeed;
    }

    m_subsystem->SetWheelSpeed(wheelSpeed);
}
