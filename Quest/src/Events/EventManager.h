#pragma once
#include "Core/Base.h"
#include "Event.h"
#include "ApplicationEvent.h"
#include "WindowEvent.h"
#include "KeyEvent.h"

#include <vector>

namespace Quest
{
	/*
		Very simple event manager for now
		It accumulates events during the main loop in Application and then it dispatches them all sequentially at the end of the main loop

	*/
	class EventManager
	{
	public:
		EventManager() {}
		void Subscribe(EventType type, EventFunc callback);
		void FireEvent(Event& e);
	private:
		std::unordered_map<EventType, std::vector<EventFunc>> m_Subscribers;
	};
}