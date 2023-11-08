#pragma once
#include "Renderer/IRenderDevice.h"

namespace Quest
{
	class OpenGLRenderDevice : public IRenderDevice
	{
	public:
		OpenGLRenderDevice(const RenderDeviceSpecification& spec);
		~OpenGLRenderDevice() override;

		// Temporary drawing functions
		void DrawFrame() override;

		void WaitForDeviceToFinishExecuting() override;

		void FramebufferResize() override;
	};
}