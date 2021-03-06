/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/util/Color.h>

#include "subsystems/ColorWheelSubsystem.h"

class ColorWheelCommand
    : public frc2::CommandHelper<frc2::CommandBase, ColorWheelCommand>
{
public:
    /**
     * Creates a new IntakeCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    explicit ColorWheelCommand(ColorWheelSubsystem *subsystem);

    // scheduler handers for various states
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;

private:
    ColorWheelSubsystem *m_subsystem;

    // char -> color map
    std::unordered_map<char, frc::Color> m_colorMap;

    int m_counter;      // counts number of times target colour is found
    int m_maxCounts;    // max. number of colour counts (1 or 7)
    frc::Color m_prevColor;
    frc::Color m_targetColor;

    std::string m_gameData;
};
