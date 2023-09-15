#include <Quest.h>
#include <QuestEntrypoint.h>

class Sandbox : public Quest::Application {
public:
	Sandbox(Quest::Application::ApplicationSpecification spec)
	: Application(spec), m_Specification(spec)
	{
		//PushLayer(new SandboxLayer());
		//PushLayer(new Sandbox2D());
		QE_APP_INFO("Sandbox Application Constructor");
	}

	~Sandbox() {

	}
private:
	Application::ApplicationSpecification m_Specification;
};

Quest::Application* Quest::CreateApplication(Application::ApplicationSpecification spec) {
	return new Sandbox(spec);
} 