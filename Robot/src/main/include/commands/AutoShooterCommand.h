/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ShooterSubsystem.h"

extern bool g_autoShooterCommandFinished;

class AutoShooterCommand
    : public frc2::CommandHelper<frc2::CommandBase, AutoShooterCommand> 
{
public:
    /**
     * Creates a new AutoShooterCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit AutoShooterCommand(units::time::second_t maxTime, double speed, 
        ShooterSubsystem* subsystem);

    // scheduler handers for various states
    void Initialize() override;
    void Execute() override;
    void End(bool interrupted) override;
    bool IsFinished() override;
    
private:
    ShooterSubsystem* m_subsystem;
    double m_speed;
    units::time::second_t m_maxTime;
    frc2::Timer m_timer;
};
