/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/util/color.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

// CAN bus IDs for Talon controllers
enum
{
    // Pedro
    // LF_CAN_ID = 3,
    // LR_CAN_ID = 4,
    // RF_CAN_ID = 1,
    // RR_CAN_ID = 2,
    COLOR_WHEEL_CAN_ID = 5,

    // P2020
    LF_CAN_ID = 5,
    LR_CAN_ID = 6,
    RF_CAN_ID = 3,
    RR_CAN_ID = 4,
    INTAKE_WHEELS_CAN_ID = 13,
    INTAKE_PIVOT_CAN_ID = 10, // *** TO-DO ***
    TOP_SHOOTER_TOP_CAN_ID = 8,
    BOTTOM_SHOOTER_CAN_ID = 7,
    TOP_CONVEYOR_CAN_ID = 9,
    LOWER_CONVEYOR_CAN_ID = 12,
    CLIMB_ONE_CAN_ID = 11,
    CLIMB_TWO_CAN_ID = 14,
    // COLOR_WHEEL_CAN_ID = 15
};

enum
{
    DIRECTION_FWD = 1,
    DIRECTION_REV = -1
};

// Color Calibration **TODO**
static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);