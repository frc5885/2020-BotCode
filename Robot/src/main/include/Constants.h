/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

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
    LF_CAN_ID = 3,
    LR_CAN_ID = 4,
    RF_CAN_ID = 1,
    RR_CAN_ID = 2,

    // P2020
    // LF_CAN_ID = 5,
    // LR_CAN_ID = 6,
    // RF_CAN_ID = 3,
    // RR_CAN_ID = 4,
    INTAKE_WHEELS_CAN_ID = 11,
    TOP_SHOOTER_TOP_CAN_ID = 8,
    BOTTOM_SHOOTER_CAN_ID = 7
};

enum
{
    DIRECTION_FWD = 1,
    DIRECTION_REV = -1
};