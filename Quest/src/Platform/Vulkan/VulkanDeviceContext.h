#pragma once

#include "Renderer/IDeviceContext.h"

struct GLFWwindow;

namespace Quest
{
	class VulkanDeviceContext : public IDeviceContext
	{
	public:
		VulkanDeviceContext(GLFWwindow* window);

		virtual void Init() override;
		virtual void Shutdown() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}