#include "qepch.h"

#include "OpenGLDeviceContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Quest
{
	OpenGLDeviceContext::OpenGLDeviceContext(GLFWwindow* window)
		: m_WindowHandle(window)
	{
	}

	void OpenGLDeviceContext::Init()
	{
		QE_CORE_ASSERT_MSG(m_WindowHandle, "Window is NULL");
		glfwMakeContextCurrent(m_WindowHandle);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		QE_CORE_ASSERT_MSG(status, "Failed to initialize Glad");
		gladLoadGL();

		// Check to make sure the version of OpenGL is 4.6 capable
		// spdlog needs to have the GLUbyte casted to a "const char*" for it to work properly now
		QE_CORE_INFO("OpenGL Version Information:");
		QE_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		QE_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		QE_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLDeviceContext::Shutdown()
	{

	}

	void OpenGLDeviceContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}