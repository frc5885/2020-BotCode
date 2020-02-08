/*
 * ButtonState.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: WiredCats
 */

#include <ButtonState.h>

ButtonState::ButtonState() {
	// TODO Auto-generated constructor stub

}

ButtonState::~ButtonState() {
	// TODO Auto-generated destructor stub
}

void ButtonState::ToggleState(bool pressed)
{
	if (pressed) // If the button is down
	{
		if (m_wasReleased) // If it was previously up
		{
			m_isPressed = !m_isPressed; // Toggle state
			m_wasReleased = false; // Toggle released to off
		}
	}
	else // If the button is up
	{
		m_wasReleased = true; // Toggle released to on
	}
}

bool ButtonState::IsPressed() const
{
	return m_isPressed;
}

void ButtonState::ForceState(bool pressed)
{
	// force new button state
	m_isPressed = pressed;

	// set this so the next button press will change the state again
	m_wasReleased = false;
}
