#pragma once
#include "Renderer/IDeviceContext.h"

struct GLFWwindow;

namespace Quest
{
	class OpenGLDeviceContext : public IDeviceContext
	{
	public:
		OpenGLDeviceContext(GLFWwindow* window);

		virtual void Init() override;
		virtual void Shutdown() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}