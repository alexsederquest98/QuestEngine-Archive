#pragma once
#include <Quest.h>

class SandboxApp : public Quest::Application
{
public:
	SandboxApp(Quest::Application::ApplicationSpecification spec);
	~SandboxApp();
private:
	Application::ApplicationSpecification m_Specification;
};