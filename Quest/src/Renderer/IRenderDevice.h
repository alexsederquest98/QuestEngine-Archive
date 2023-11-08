#pragma once
#include "Core/Base.h"
#include "Core/Window.h"

namespace Quest
{
	class IRenderDevice
	{
	public:
		struct RenderDeviceSpecification
		{
			Ref<Window> window;
		};

		virtual ~IRenderDevice() = default;

		// Temporary drawing functions
		virtual void DrawFrame() = 0;

		virtual void WaitForDeviceToFinishExecuting() = 0;

		virtual void FramebufferResize() = 0;

		static Scope<IRenderDevice> Create(const RenderDeviceSpecification& spec);
	protected:
		Ref<Window> m_Window;
	};
}