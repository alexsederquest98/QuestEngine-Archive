#pragma once
#include "Event.h"
// keycodes too

#include <sstream>

// TODO: UPDATE THESE WHEN I HAVE KEYCODES IMPLEMENTED
namespace Quest
{
	class KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent() = default;

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent() = default;

		EVENT_INFO_FILL(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		EVENT_INFO_FILL(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		EVENT_INFO_FILL(KeyTyped)
	};
}