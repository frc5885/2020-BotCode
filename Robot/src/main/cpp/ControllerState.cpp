/*
 * ControllerState.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: WiredCats
 */
#include <ButtonState.h>
#include <ControllerState.h>
#include <Definitions.h>

ControllerState::ControllerState(int port)
	: m_controller(port)
{

}

ControllerState::~ControllerState()
{
	// TODO Auto-generated destructor stub
}
float ControllerState::GetLeftY() const
{
	return GetAdjustedJoystickValue(m_leftY, LEFT);
}
float ControllerState::GetLeftX() const
{
	return GetAdjustedJoystickValue(m_leftX, LEFT);
}
bool ControllerState::GetLeftJoystickButton() const
{
	return m_leftJoystickButton.IsPressed();
}
float ControllerState::GetRightY() const
{
	return GetAdjustedJoystickValue(m_rightY, RIGHT);
}
float ControllerState::GetRightX() const
{
	return GetAdjustedJoystickValue(m_rightX, RIGHT);
}
bool ControllerState::GetRightJoystickButton() const
{
	return m_rightJoystickButton.IsPressed();
}
bool ControllerState::GetRightBumper() const
{
	return m_rightBumper.IsPressed();
}
bool ControllerState::GetLeftBumper() const
{
	return m_leftBumper.IsPressed();
}
bool ControllerState::GetButtonA() const
{
	return m_buttonA.IsPressed();
}
bool ControllerState::GetButtonB() const
{
	return m_buttonB.IsPressed();
}
bool ControllerState::GetButtonX() const
{
	return m_buttonX.IsPressed();
}
bool ControllerState::GetButtonY() const
{
	return m_buttonY.IsPressed();
}
bool ControllerState::GetButtonBack() const
{
	return m_buttonBack.IsPressed();
}
bool ControllerState::GetButtonStart() const
{
	return m_buttonStart.IsPressed();
}
unsigned int ControllerState::GetPov() const
{
	return m_pov;
}
float ControllerState::GetRightTrig() const
{
	return m_rightTrig;
}
float ControllerState::GetLeftTrig() const
{
	return m_leftTrig;
}
float ControllerState::GetRumbleVibrate() const
{
	return m_rumbleVibrate;
}
float ControllerState::GetRumbleRumble() const
{
	return m_rumbleRumble;
}

void ControllerState::SetRumbles(int _rumble, float _rate) const
{
	//m_controller.SetRumble((int)0,0.5);

	//m_controller.SetRumble((Joystick.RumbleType)(0), _rate);
}

// Get current controller state
void ControllerState::GetState()
{
	m_leftJoystickButton.ToggleState(m_controller.GetRawButton(JOYSTICK_LEFT_BUTTON));//Left joystick button
	m_leftY = m_controller.GetRawAxis(JOYSTICK_LEFT_Y); //Left joystick y-value
	m_leftX = m_controller.GetRawAxis(JOYSTICK_LEFT_X); // Left joystick X-value
	m_rightY = m_controller.GetRawAxis(JOYSTICK_RIGHT_Y)*(-1); //Right joystick
	m_rightX = m_controller.GetRawAxis(JOYSTICK_RIGHT_X)*(-1); //Right joystick
	m_rightJoystickButton.ToggleState(m_controller.GetRawButton(JOYSTICK_RIGHT_BUTTON));//Right joystick button
	m_rightBumper.ToggleState(m_controller.GetRawButton(BUMPER_RIGHT));
	m_leftBumper.ToggleState(m_controller.GetRawButton(BUMPER_LEFT)); // Left Bumper
	m_buttonA.ToggleState(m_controller.GetRawButton(BUTTON_A)); //Button A
	m_buttonB.ToggleState(m_controller.GetRawButton(BUTTON_B));//Button B
	m_buttonX.ToggleState(m_controller.GetRawButton(BUTTON_X));//Button X
	m_buttonY.ToggleState(m_controller.GetRawButton(BUTTON_Y));//Button Y
	m_buttonBack.ToggleState(m_controller.GetRawButton(BUTTON_BACK));  //Back Button
	m_buttonStart.ToggleState(m_controller.GetRawButton(BUTTON_START)); //Start Button
	m_pov = m_controller.GetPOV(); //D-pad (takes angle values from 0 to 360 degrees by increments of 45 degreesd)
	m_rightTrig = m_controller.GetRawAxis(TRIGGER_RIGHT);//Throttle (speed of motors)
	m_leftTrig = m_controller.GetRawAxis(TRIGGER_LEFT);
	m_rumbleVibrate = m_controller.GetRawAxis(RUMBLE_VIBRATE);// This rumble vibrates
	m_rumbleRumble = m_controller.GetRawAxis(RUMBLE_RUMBLE);  // This rumble is more violent

	// initial bias for joysticks
	SetInitialJoystickVariables();
}

void ControllerState::SetInitialJoystickVariables()
{
	if (!m_joystickVarsInit)
	{
//		m_initLeftX = (m_leftX < 0.0) ? m_leftX - JOYSTICK_OFFSET : m_leftX + JOYSTICK_OFFSET;
//		m_initLeftY = (m_leftY < 0.0) ? m_leftY- JOYSTICK_OFFSET : m_leftY + JOYSTICK_OFFSET;
//		m_initRightX = (m_rightX < 0.0) ? m_rightX - JOYSTICK_OFFSET : m_rightX + JOYSTICK_OFFSET;
//		m_initRightY = (m_rightY < 0.0) ? m_rightY - JOYSTICK_OFFSET : m_rightY + JOYSTICK_OFFSET;
		m_joystickVarsInit = true;
	}
}

void ControllerState::ForceButtonState(int button, bool pressed)
{
	// temp code,needs to be expanded for all buttons
	switch (button)
	{
	case BUTTON_X:
		m_buttonX.ForceState(pressed);
		break;

	case BUTTON_Y:
		m_buttonY.ForceState(pressed);
		break;

	case BUTTON_A:
		m_buttonA.ForceState(pressed);
		break;

	case BUTTON_B:
		m_buttonB.ForceState(pressed);
		break;

	default:
		break;
	}
}

 void ControllerState::InitializeButtonStates()
{
	// 'un-press' all buttons - call this in TeleopInit()
	ForceButtonState(BUTTON_X, false);
	ForceButtonState(BUTTON_Y, false);
	ForceButtonState(BUTTON_A, false);
	ForceButtonState(BUTTON_B, false);
}

float ControllerState::GetAdjustedJoystickValue(float rawValue, RobotSide side) const
{
	float adjustedValue = rawValue;
//	float limit = 0.0;
//
//	if (side == LEFT)
//	{
//		limit = (fabs(m_initLeftY) > fabs(m_initLeftX)) ?
//				 fabs(m_initLeftY) : fabs(m_initLeftX);
//	}
//	else
//	{
//		limit = (fabs(m_initRightY) > fabs(m_initRightX)) ?
//			     fabs(m_initRightY) : fabs(m_initRightX);
//	}
//
//	if (fabs(rawValue) < limit)
//	{
//		adjustedValue = 0.0;
//	}

	return adjustedValue;
}

// our xbox controllers on ports 0 and 1
std::unique_ptr<ControllerState> g_controller0, g_controller1;
