#include "qepch.h"
#include "Application.h"
#include "Debug/Profiler.h"

namespace Quest
{
	Ref<EventManager> Application::s_EventManager = CreateRef<EventManager>();

	bool Application::s_Instantiated = false;
	Application* Application::s_Instance = nullptr;

	Quest::Application::Application(ApplicationSpecification spec)
	{
		QE_CORE_ASSERT_MSG(!s_Instantiated, "Only 1 Application class may be used.");
		s_Instantiated = true;
		s_Instance = this;

		m_Window = Window::Create(WindowSpecification(spec.AppName));
		m_Window->SetEventCallback(QE_BIND_EVENT_FUNC(OnEvent));

		s_EventManager->Subscribe(EventType::MouseMoved, QE_BIND_EVENT_FUNC(OnMouseMoved));
		s_EventManager->Subscribe(EventType::WindowClose, QE_BIND_EVENT_FUNC(OnWindowClose));

		QE_CORE_INFO("Application Initialized");
	}

	Application::~Application()
	{
		s_Instantiated = false;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			//QE_CORE_INFO("Application::Run()");
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
	}

	void Application::OnWindowClose(Event& e)
	{
		WindowCloseEvent event = static_cast<WindowCloseEvent&>(e);
		QE_CORE_DEBUG("WindowCloseEvent hit");
		m_Running = false;
	}

	void Application::OnMouseMoved(Event& e)
	{
		MouseMovedEvent event = static_cast<MouseMovedEvent&>(e);
		QE_CORE_DEBUG("{0}, {1}", event.GetX(), event.GetY());
	}

	void Application::Close()
	{
		m_Running = false;
	}

}