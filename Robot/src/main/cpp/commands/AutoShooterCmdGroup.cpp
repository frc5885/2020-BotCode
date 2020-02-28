/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Auto.h"

AutoShooterCmdGroup::AutoShooterCmdGroup(ShooterSubsystem *shooter, ConveyerSubsystem *conveyer)
{
    AddCommands(
        AutoShooterCommand(5.0_s, .9, shooter),
        AutoConveyerCommand(3.0_s, 2.0_s, .75, conveyer));
}