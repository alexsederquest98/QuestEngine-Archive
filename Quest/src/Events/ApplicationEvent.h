#pragma once
#include "Event.h"

namespace Quest
{
	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		EVENT_INFO_FILL(AppTick)
	};

	class AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_INFO_FILL(AppUpdate)
	};

	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_INFO_FILL(AppRender)
	};
}