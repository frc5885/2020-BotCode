/*
 * Definitions.h
 *
 *  Created on: Feb 6, 2016
 *      Author: WiredCats
 */

#pragma once

//these is the register on the x-box 360 controller

//these are used with GetRawAxis
#define JOYSTICK_RIGHT_X (4)
#define JOYSTICK_RIGHT_Y (5)
#define JOYSTICK_RIGHT_BUTTON (10)
//these are also used with GetRawAxis
#define JOYSTICK_LEFT_X (0)
#define JOYSTICK_LEFT_Y (1)
#define JOYSTICK_LEFT_BUTTON (9)

//these are used with GetRawButton for the XBox controller
#define BUTTON_A (1)
#define BUTTON_B (2)
#define BUTTON_X (3)
#define BUTTON_Y (4)
#define BUTTON_START (8)
#define BUTTON_BACK (7)

// these are used with GetRawButton for the Logitech joystick
#define LOGITECH_X (0)
#define LOGITECH_Y (1)
#define BUTTON_3 (3)	// climb down
#define BUTTON_4 (4)	// lock climb motor
#define BUTTON_5 (5)	// climb up

//this is used with GetPOV
#define D_PAD (0)

//The PMW ports
#define SPARK 0

//this is also used with GetRawAxis
#define TRIGGER_RIGHT (3)
#define TRIGGER_LEFT (2)

//this is also used with GetRawButton
#define BUMPER_RIGHT (6)
#define BUMPER_LEFT (5)

//we gotta figure this one out
#define RUMBLE_VIBRATE (0)
#define RUMBLE_RUMBLE (1)

// Output channels for RoboRio
#define MOTOR_REAR_LEFT (3)   // Initialize the Talon as device 1. Use the roboRIO web
#define MOTOR_FRONT_LEFT (4)
#define MOTOR_FRONT_RIGHT (2)
#define MOTOR_REAR_RIGHT (1)// interface to change the device number on the talon
#define MOTOR_GEAR_TEST (5)
#define MOTOR_SCISSOR_1 (7)
#define MOTOR_SCISSOR_2 (8)
#define MOTOR_SCOOP (9)
#define CONTROLLER (0)
#define JOYSTICK (1)

// DIO pins
#define DIO_LEFT_WHEEL_ENCODER_A 2
#define DIO_LEFT_WHEEL_ENCODER_B 3
#define DIO_RIGHT_WHEEL_ENCODER_A 0
#define DIO_RIGHT_WHEEL_ENCODER_B 1

#define DIO_RED_LEDS_1 15
#define DIO_RED_LEDS_2 18
#define DIO_GREEN_LEDS_1 16
#define DIO_GREEN_LEDS_2 19
#define DIO_BLUE_LEDS_1 17
#define DIO_BLUE_LEDS_2 20

#define DIO_AUTO_GO_STRAIGHT 10
#define DIO_AUTO_GEAR_STRAIGHT 11
#define DIO_AUTO_BOILER_LEFT 12
#define DIO_AUTO_BOILER_RIGHT 13
#define DIO_AUTO_TURN_RIGHT 5
#define DIO_AUTO_TURN_LEFT 6
#define DIO_AUTO_SHOOT 7

#define JOYSTICK_OFFSET 0.03

#define SIDE_DISTANCE 29.7	// distance from side wall for start of auto

enum RobotSide
{
	LEFT,
	RIGHT
};

extern bool Equals (double value1, double value2, double tolerance);
