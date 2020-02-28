/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ConveyerSubsystem.h"

class AutoConveyerCommand
    : public frc2::CommandHelper<frc2::CommandBase, AutoConveyerCommand>
{
public:
    /**
     * Creates a new ShooterCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit AutoConveyerCommand(units::time::second_t maxTime, 
        units::time::second_t delayTime, double speed, ConveyerSubsystem *subsystem);

    // scheduler handers for various states
    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;

private:
    ConveyerSubsystem *m_subsystem;
    double m_speed;
    units::time::second_t m_maxTime, m_maxDelayTime;
    frc2::Timer m_timer, m_delayTimer;
    bool m_started;
};
