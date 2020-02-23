/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTableEntry.h>

#include "RobotContainer.h"

class Robot : public frc::TimedRobot {
public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestInit() override;
    void TestPeriodic() override;

private:
    // Have it null by default so that if testing teleop it
    // doesn't have undefined behavior and potentially crash.
    frc2::Command* m_autonomousCommand = nullptr;

    // teleop command for tank drive
    frc2::Command *m_driveCommand = nullptr;

    // teleop intake command
    frc2::Command *m_intakeCommand = nullptr;

    // teleop conveyer command
    frc2::Command *m_conveyerCommand = nullptr;

    // teleop shooter command
    frc2::Command *m_shooterCommand = nullptr;

    // teleop climb command 
    frc2::Command *m_climbCommand = nullptr;

    RobotContainer m_container;
};
