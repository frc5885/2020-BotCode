/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimbSubsystem.h"

class ClimbCommand
    : public frc2::CommandHelper<frc2::CommandBase, ClimbCommand> 
{
public:
    /**
     * Creates a new ClimbCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit ClimbCommand(ClimbSubsystem* subsystem);

    // scheduler handers for various states
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

private:
    ClimbSubsystem* m_subsystem;
};
