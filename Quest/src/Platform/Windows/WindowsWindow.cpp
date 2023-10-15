#include "qepch.h"
#include "WindowsWindow.h"

#include "Core/Application.h"

#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Quest
{
	// Error function for GLFW
	static void GLFWErrorCallback(int error, const char* description)
	{
		QE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	WindowsWindow::WindowsWindow(const WindowSpecification& spec)
	{
		Init(spec);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowSpecification& spec)
	{
		m_WindowData.m_Title = spec.Title;
		m_WindowData.m_Width = spec.Width;
		m_WindowData.m_Height = spec.Height;
		m_WindowData.m_VSync = true;

		QE_CORE_INFO("Creating Windows Window: {0} - ({1}), {2})", m_WindowData.m_Title, m_WindowData.m_Width, m_WindowData.m_Height);

		// Initialize GLFW
		int success = glfwInit();
		QE_CORE_ASSERT_MSG(success, "Failed to initialize GLFW :(");

		glfwSetErrorCallback(GLFWErrorCallback);
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // for Vulkan

		m_Window = glfwCreateWindow((int)m_WindowData.m_Width, (int)m_WindowData.m_Height, m_WindowData.m_Title.c_str(), nullptr, nullptr);

		glfwSetWindowUserPointer(m_Window, &m_WindowData);

		// GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.m_Width = width;
				data.m_Height = height;

				WindowResizeEvent event(width, height);
				Application::GetEventManager()->FireEvent(event);
				//data.m_EventCallback(event);
			}
		);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				Application::GetEventManager()->FireEvent(event);
			}
		);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					Application::GetEventManager()->FireEvent(event);
					//data.m_EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					Application::GetEventManager()->FireEvent(event);
					//data.m_EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					Application::GetEventManager()->FireEvent(event);
					//data.m_EventCallback(event);
					break;
				}
				}
			}
		);

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				Application::GetEventManager()->FireEvent(event);
				//data.m_EventCallback(event);
			}
		);

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					Application::GetEventManager()->FireEvent(event);
					//data.m_EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					Application::GetEventManager()->FireEvent(event);
					//data.m_EventCallback(event);
					break;
				}
				}
			}
		);

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				Application::GetEventManager()->FireEvent(event);
				//data.m_EventCallback(event);
			}
		);

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				Application::GetEventManager()->FireEvent(event);
				//data.m_EventCallback(event);
			}
		);

	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		// swap buffers
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFunc& callback)
	{
		m_WindowData.m_EventCallback = callback;
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		m_WindowData.m_VSync = enabled;

		// swapchain stuff for vsync
	}
}