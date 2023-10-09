#include "qepch.h"
#include "Application.h"

#include <string>

#include <iostream>

namespace Quest
{
	bool Application::s_Instantiated = false;

	Quest::Application::Application(ApplicationSpecification spec)
	{
		QE_CORE_ASSERT_MSG(!s_Instantiated, "Only 1 Application class may be used.");
		s_Instantiated = true;

		//std::string buffer = std::format("Hi {0}, How are your {1}?", "Bob", "toes");
		//std::cout << buffer << std::endl;
		

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
		}
	}

	void Application::Close()
	{
		m_Running = false;
	}

}