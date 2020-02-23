/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class IntakeCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeCommand> 
{
public:
    /**
     * Creates a new IntakeCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit IntakeCommand(IntakeSubsystem* subsystem);

    // scheduler handers for various states
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

private:
    IntakeSubsystem* m_subsystem;
    frc2::Timer m_pivotTimer;
    bool m_pivotDownTimerStarted, m_pivotUpTimerStarted;

    // pivot constants
    static constexpr double m_kPivotUpMotorSpeed = 0.6;     // -1 -> 1
    static constexpr double m_kPivotDownMotorSpeed = -0.15;  // -1 -> 1
    static constexpr units::time::second_t m_kPivotTimerDownTime = 1.0_s;    // seconds
    static constexpr units::time::second_t m_kPivotTimerUpTime = 1.0_s;      // seconds

    // intake wheels constants
    static constexpr double m_kForwardWheelSpeed = .4; // 0 -> 1
    static constexpr double m_kReverseWheelSpeed = -.75;  // 0 -> 1
};
