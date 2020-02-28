/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "Constants.h"
#include "commands/AutoShooterCommand.h"
#include "commands/AutoConveyerCommand.h"

class AutoShooterCmdGroup
    : public frc2::CommandHelper<frc2::ParallelCommandGroup, AutoShooterCmdGroup>
{
public:
    AutoShooterCmdGroup(ShooterSubsystem *shooter, ConveyerSubsystem *conveyer);
}