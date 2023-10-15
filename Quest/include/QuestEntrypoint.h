#pragma once

#include "../src/Core/Base.h"
#include "../src/Core/Application.h"

extern Quest::Scope<Quest::Application> Quest::CreateApplication(Quest::Application::ApplicationSpecification spec);

int main(int argc, char** argv)
{
	Quest::Log::Init();
	QE_CORE_INFO("Initializing Quest Engine...");
	

	Quest::Scope<Quest::Application> app = Quest::CreateApplication({
		.AppName = "Quest Application",
		.ArgCount = argc,
		.Arguments = argv,
	});

	app->Run();

	return 0;
}