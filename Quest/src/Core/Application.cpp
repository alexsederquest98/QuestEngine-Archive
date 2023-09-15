#include "qepch.h"
#include "Application.h"

namespace Quest
{
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

	void Application::Close()
	{
		m_Running = false;
	}

}