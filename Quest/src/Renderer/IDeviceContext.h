#pragma once
#include "Core/Base.h"

namespace Quest
{
	class IDeviceContext
	{
	public:
		virtual ~IDeviceContext() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual void SwapBuffers() = 0;

		static Ref<IDeviceContext> Create(void* window);
	};
}