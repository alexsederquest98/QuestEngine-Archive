#include "../src/Core/Base.h"
#include "../src/Core/Application.h"

extern Quest::Application* Quest::CreateApplication(Application::ApplicationSpecification spec);

int main(int argc, char** argv)
{
	Quest::Logger::Init();
	QE_CORE_CRITICAL("Initializing Quest Engine...");

	Quest::Application::ApplicationSpecification appSpec
	{
		.AppName = "Quest Application",
		.ArgCount = argc,
		.Arguments = argv,
	};

	Quest::Application* app = Quest::CreateApplication(appSpec);
	app->Run();
	delete app;

	return 0;
}