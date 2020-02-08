#pragma once

class ButtonState
{
public:
	ButtonState();
	virtual ~ButtonState();

private:
	bool m_wasReleased = true;
	bool m_isPressed = false;

public:
	void ToggleState (bool pressed);
	bool IsPressed()const;
	void ForceState(bool pressed);
};
