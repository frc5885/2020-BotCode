/*
 * ControllerState.h
 *
 *  Created on: Feb 6, 2016
 *      Author: WiredCats
 */
#pragma once
#include "Definitions.h"
#include "frc/Joystick.h"
#include "ButtonState.h"

class ControllerState
{
public:
	ControllerState(int port);
	virtual ~ControllerState();

// Properties
public:
	frc::Joystick m_controller;//X-Box Controller

private:
	float m_leftY = 0.0; //Left joystick y-value
	float m_leftX = 0.0; // Left joystick X-value
	ButtonState m_leftJoystickButton; // left joystick button
	float m_rightY = 0.0; //Right joystick y-value
	float m_rightX = 0.0; //Right joystick x-value
	ButtonState m_rightJoystickButton; // Right joystick button
	ButtonState m_rightBumper;
	ButtonState m_leftBumper; // Left Bumper
	ButtonState m_buttonA; //Button A
	ButtonState m_buttonB; //Button B
	ButtonState m_buttonX; //Button X
	ButtonState m_buttonY; //Button Y
	ButtonState m_buttonBack; //Back Button
	ButtonState m_buttonStart; //Start Button
	unsigned int m_pov = 0; //D-pad
	float m_rightTrig = 0.0;//Throttle (speed of motors)
	float m_leftTrig = 0.0;
    float m_rumbleVibrate = 0.0; // This rumble vibrates
    float m_rumbleRumble = 0.0; // This rumble is more violent

    //Initial Controller State
    float m_initLeftX = 0.0;
    float m_initLeftY = 0.0;
    float m_initRightX = 0.0;
    float m_initRightY = 0.0;
    bool m_joystickVarsInit = false;

//Accessors Get Only!
public:
    float GetLeftY()const;
    float GetLeftX()const;
    bool GetLeftJoystickButton()const;
    float GetRightY()const;
    float GetRightX()const;
    bool GetRightJoystickButton()const;
    bool GetRightBumper()const;
    bool GetLeftBumper()const;
    bool GetButtonA()const;
    bool GetButtonB()const;
    bool GetButtonX()const;
    bool GetButtonY()const;
    bool GetButtonBack()const;
    bool GetButtonStart()const;
    unsigned int GetPov()const;
    float GetRightTrig()const;
    float GetLeftTrig()const;
    float GetRumbleVibrate()const;
    float GetRumbleRumble()const;
    void SetRumbles(double value);

//Methods
public:
    //Get current controller state
    void GetState();
    void ForceButtonState(int button, bool pressed);

    // Initialize all buttons to 'un-pressed'
    void InitializeButtonStates();
    
    // Sets the initial joystick variables on first read of controller state
    void SetInitialJoystickVariables();
private:
    float GetAdjustedJoystickValue(float rawValue, RobotSide side)const;
};

// Our xbox controllers
extern std::unique_ptr<ControllerState> g_controller0, g_controller1;

// return +-1 based on whether a number > or < 0
inline double SignOf(double value)
{
    return (value < 0.0 ? -1.0 : 1.0);
}

//this is a method that will give you the absolute value whenever you need it
//(used multiple times in the program)
inline bool Equals(double value1, double value2, double tolerance)
{
    return (fabs(value1 - value2) < tolerance);
}
