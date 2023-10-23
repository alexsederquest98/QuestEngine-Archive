#pragma once
#include "Core/Base.h"
#include "Core/Window.h"

namespace Quest
{
	class GraphicsDevice
	{
	public:
		struct GraphicsDeviceSpecification
		{
			Ref<Window> window;
		};

		virtual ~GraphicsDevice() = default;

		// Temporary drawing functions
		virtual void DrawFrame() = 0;

		virtual void WaitForDeviceToFinishExecuting() = 0;

		virtual void FramebufferResize() = 0;

		static Scope<GraphicsDevice> Create(const GraphicsDeviceSpecification& spec);
	protected:
		Ref<Window> m_Window;
	};
}