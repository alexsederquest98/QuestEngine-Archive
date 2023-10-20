#pragma once
#include "Core/QuestTypes.h"
#include "Event.h"

#include <sstream>

namespace Quest
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_INFO_FILL(WindowClose)
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint16 width, uint16 height)
			: m_Width(width), m_Height(height)
		{
		}

		uint16 GetWidth() const { return m_Width; }
		uint16 GetHeight() const { return m_Height; }
		
		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return stream.str();
		}

		EVENT_INFO_FILL(WindowResize)

	private:
		uint16 m_Width;
		uint16 m_Height;
	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() = default;

		EVENT_INFO_FILL(WindowFocus)
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() = default;

		EVENT_INFO_FILL(WindowLostFocus)
	};

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent() = default;

		EVENT_INFO_FILL(WindowMoved)
	};
}