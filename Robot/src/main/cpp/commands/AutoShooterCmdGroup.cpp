/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoShooterCmdGroup.h"

AutoShooterCmdGroup::AutoShooterCmdGroup(ShooterSubsystem *shooter, ConveyerSubsystem *conveyer)
{
    units::time::second_t shooterTime = 12.0_s;          // change this time, as required
    units::time::second_t shooterWindupTime = 4.0_s;    // change this time, as required
    units::time::second_t conveyerTime = shooterTime - shooterWindupTime;

    double upperShooterMotorSpeed = .80;     // 0 -> 1
    double lowerShooterMotorSpeed = .80;     // 0 -> 1
    double conveyerMotorSpeed = .20;         // 0 -> 1

    m_pShooterCommand = std::make_unique<AutoShooterCommand>(shooterTime, 
        upperShooterMotorSpeed, lowerShooterMotorSpeed, shooter);

    m_pConveyerCommand = std::make_unique<AutoConveyerCommand>(conveyerTime, 
        shooterWindupTime, conveyerMotorSpeed, conveyer);

    AddCommands(*m_pShooterCommand, *m_pConveyerCommand);
}

bool AutoShooterCmdGroup::IsFinished()
{
    return (g_autoShooterCommandFinished && g_autoConveyerCommandFinished);
}
