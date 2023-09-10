#include <Quest.h>

int main(int argc, char** argv)
{;
	Quest::Logger::Init();
	QE_APP_TRACE("Trace");
	QE_APP_DEBUG("Debug");
	QE_APP_INFO("Info");
	QE_APP_WARN("Warn");
	QE_APP_ERROR("Error");
	QE_APP_CRITICAL("Critical");
	return 0;
}

//class Sandbox : public Quest::Application {
//public:
//	Sandbox(Quest::ApplicationCommandLineArgs args)
//	: Application("Sandbox", args)
//	{
//		//PushLayer(new SandboxLayer());
//		PushLayer(new Sandbox2D());
//	}
//
//	~Sandbox() {
//
//	}
//};
//
//Quest::Application* Quest::CreateApplication(ApplicationCommandLineArgs args) {
//	return new Sandbox(args);
//} 