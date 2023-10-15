#pragma once

#include "Core/Base.h"

#include <string>
#include <functional>

namespace Quest
{
	// Lamda function binding for the callback function for the event
	#define QE_BIND_EVENT_FUNC(func) [this](Event& e) { return this->func(std::forward<Event&>(e)); }

	// Event enum for internal events
	enum class EventType : uint8
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// Macro for filling out virtual methods for derived events
	#define EVENT_INFO_FILL(type) EventType GetEventType() const override { return EventType::type;} \
									std::string GetName() const override { return #type; }

	// Base event class
	// Other events should all inherit from this
	class Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual std::string GetName() const = 0;
		virtual std::string ToString() const { return GetName(); } // should override with a proper ToString specific to the event
		
		// for later
		bool Handled = false;
	};

	// Convienent typedef to avoid changing it once and forgetting to update everywhere
	using EventCallbackFunc = std::function<void(Event& e)>;
}