/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeWheelsSubsystem.h"

class IntakeWheelsCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeWheelsCommand> 
{
public:
    /**
     * Creates a new IntakeWheelsCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit IntakeWheelsCommand(IntakeWheelsSubsystem* subsystem);

    // scheduler handers for various states
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

private:
    IntakeWheelsSubsystem* m_subsystem;
};
