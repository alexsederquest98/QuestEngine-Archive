#include "../src/Core/Base.h"
#include "../src/Core/Application.h"

extern Quest::UniquePointer<Quest::Application> Quest::CreateApplication(Quest::Application::ApplicationSpecification spec);

int main(int argc, char** argv)
{
	Quest::Logger::Init();
	QE_CORE_CRITICAL("Initializing Quest Engine...");

	QE_CORE_ASSERT_MSG(5 == 43, "you suck");

	Quest::UniquePointer<Quest::Application> app = Quest::CreateApplication({
		.AppName = "Quest Application",
		.ArgCount = argc,
		.Arguments = argv,
	});

	app->Run();

	return 0;
}