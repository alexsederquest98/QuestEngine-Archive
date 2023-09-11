#pragma once

#include <string>

namespace Quest
{
	class Application
	{
	public:
		Application(const std::string& name = "Quest Application");
		~Application();

		void Run();
	private:
	};
}