#pragma once
#include "Core/Base.h"
#include "Event.h"
#include "ApplicationEvent.h"
#include "WindowEvent.h"
#include "KeyEvent.h"
#include "MouseEvent.h"

#include <vector>

namespace Quest
{
	/*
		Very simple event manager for now
		Systems subscribe to event types with their respective callback functions
		Then when an event is fired, it will call the callbacks associated to the event types
	*/
	class EventManager
	{
	public:
		EventManager() {}
		void Subscribe(EventType type, EventCallbackFunc callback);
		void FireEvent(Event& e);
	private:
		std::unordered_map<EventType, std::vector<EventCallbackFunc>> m_Subscribers;
	};
}