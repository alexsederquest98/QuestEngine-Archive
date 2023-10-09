#include "SandboxApp.h"

#include <Quest.h>
#include <QuestEntrypoint.h>

SandboxApp::SandboxApp(Quest::Application::ApplicationSpecification spec)
	: Quest::Application(spec), m_Specification(spec)
{
	//QE_APP_INFO("Sandbox Application Constructor");
}

SandboxApp::~SandboxApp()
{

}

Quest::UniquePointer<Quest::Application> Quest::CreateApplication(Application::ApplicationSpecification spec) {
	return Quest::CreateUniquePointer<SandboxApp>(spec);
} 