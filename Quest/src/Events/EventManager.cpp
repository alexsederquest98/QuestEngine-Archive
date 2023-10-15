#include "EventManager.h"

namespace Quest
{
	void EventManager::Subscribe(EventType type, EventCallbackFunc callback)
	{
		m_Subscribers[type].push_back(std::move(callback));
	}

	void EventManager::FireEvent(Event& e)
	{
		auto iter = m_Subscribers.find(e.GetEventType());
		if (iter != m_Subscribers.end())
			for (auto& callback : iter->second)
				callback(e);
	}
}