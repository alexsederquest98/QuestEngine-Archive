#pragma once

#include "Core/Window.h"

#include <string_view>
#include <GLFW/glfw3.h>

namespace Quest
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowSpecification& spec);
		virtual ~WindowsWindow();

		void AttachContext(Ref<IDeviceContext> context) override;

		void OnUpdate() override;

		std::string GetTitle() const override { return m_WindowData.m_Title; }
		uint32 GetWidth() const override { return m_WindowData.m_Width; }
		uint32 GetHeight() const override { return m_WindowData.m_Height; }
		bool IsVSync() const override { return m_WindowData.m_VSync; }
		void* GetNativeWindow() const override { return m_Window; }

		void SetEventCallback(const EventCallbackFunc& callback) override;
		void SetVSync(bool enabled) override;
		void SetTitle(std::string_view title) override;

		float GetTime() const override { return (float)glfwGetTime(); }

		void PauseWindow() override;

	private:
		void Init(const WindowSpecification& spec);
		void Shutdown();
	private:
		GLFWwindow* m_Window;
		Ref<IDeviceContext> m_Context;

		struct WindowData
		{
			std::string m_Title;
			uint32 m_Width;
			uint32 m_Height;
			bool m_VSync;

			EventCallbackFunc m_EventCallback;
		};

		WindowData m_WindowData;
	};
}