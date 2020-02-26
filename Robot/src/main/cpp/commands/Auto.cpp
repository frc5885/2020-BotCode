/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Auto.h"

Auto::Auto(DriveSubsystem *drive)
{
    printf("**********************************************");
    AddCommands(
        // Drive forward the specified distance
        DriveDistance(3.0_s, 0.5, drive));
}