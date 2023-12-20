#pragma once
#include "Core/Base.h"
#include "Core/Window.h"

namespace Quest
{
	class IRenderDevice
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1, Vulkan = 2
		};

		struct RenderDeviceSpecification
		{
			RefPtr<Window> window;
		};

		virtual ~IRenderDevice() = default;

		// Temporary drawing functions
		virtual void DrawFrame() = 0;

		virtual void WaitForDeviceToFinishExecuting() = 0;

		virtual void FramebufferResize(uint32_t width, uint32_t height) = 0;

		static RefPtr<IRenderDevice> Create(const RenderDeviceSpecification& spec);
		static API GetAPI() { return s_API; }
	protected:
		RefPtr<Window> m_Window;
	private:
		static API s_API;
	};
}