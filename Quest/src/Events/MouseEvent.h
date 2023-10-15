#pragma once
#include "Event.h"
#include "Core/MouseCodes.h"

#include <sstream>

namespace Quest
{
	class MouseButtonEvent : public Event
	{
	public:
		MouseCode GetMouseButton() const { return m_Button; }
	protected:
		MouseButtonEvent(const MouseCode button)
			: m_Button(button)
		{
		}

		MouseCode m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseCode button)
			: MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonPressedEvent: " << m_Button;
			return stream.str();
		}

		EVENT_INFO_FILL(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseCode button)
			: MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonReleasedEvent: " << m_Button;
			return stream.str();
		}

		EVENT_INFO_FILL(MouseButtonReleased)
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y)
			: m_MouseX(x), m_MouseY(y)
		{
		}

		float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return stream.str();
		}

		EVENT_INFO_FILL(MouseMoved)

	protected:
		float m_MouseX;
		float m_MouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float xOffset, const float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset)
		{
		}

		float GetXOffset() const { return m_XOffset; }
		float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return stream.str();
		}

		EVENT_INFO_FILL(MouseScrolled)

	private:
		float m_XOffset;
		float m_YOffset;
	};
}