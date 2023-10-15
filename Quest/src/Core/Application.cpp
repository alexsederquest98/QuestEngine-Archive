#include "qepch.h"
#include "Application.h"

namespace Quest
{
	void eventTest1()
	{
		QE_CORE_DEBUG("event1");
	}

	void eventTest2()
	{
		QE_CORE_DEBUG("event2");
	}

	Ref<EventManager> Application::s_EventManager = CreateRef<EventManager>();

	bool Application::s_Instantiated = false;

	Quest::Application::Application(ApplicationSpecification spec)
	{
		QE_CORE_ASSERT_MSG(!s_Instantiated, "Only 1 Application class may be used.");
		s_Instantiated = true;

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
			QE_CORE_INFO("Application::Run()");
		}
	}

	void Application::Test(Event& e)
	{
		QE_CORE_INFO("Application Test: {0}", e.data);
	}

	void Application::Close()
	{
		m_Running = false;
	}

}