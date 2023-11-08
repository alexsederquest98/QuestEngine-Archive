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
			Ref<Window> window;
		};

		virtual ~IRenderDevice() = default;

		// Temporary drawing functions
		virtual void DrawFrame() = 0;

		virtual void WaitForDeviceToFinishExecuting() = 0;

		virtual void FramebufferResize() = 0;

		static Ref<IRenderDevice> Create(const RenderDeviceSpecification& spec);
		static API GetAPI() { return s_API; }
	protected:
		Ref<Window> m_Window;
	private:
		static API s_API;
	};
}