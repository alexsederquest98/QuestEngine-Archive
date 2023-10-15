#pragma once
#include "Event.h"
#include "Core/KeyCodes.h"

#include <sstream>

// TODO: UPDATE THESE WHEN I HAVE KEYCODES IMPLEMENTED
namespace Quest
{
	class KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return m_KeyCode; }
	protected:
		KeyEvent(const KeyCode keycode)
			: m_KeyCode(keycode)
		{
		}

		KeyCode m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode keycode, const uint16 repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount)
		{
		}

		uint16 GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return stream.str();
		}

		EVENT_INFO_FILL(KeyPressed)

	private:
		uint16 m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode)
			: KeyEvent(keycode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyReleasedEvent: " << m_KeyCode;
			return stream.str();
		}

		EVENT_INFO_FILL(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode)
			: KeyEvent(keycode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyTypedEvent: " << m_KeyCode;
			return stream.str();
		}

		EVENT_INFO_FILL(KeyTyped)
	};
}