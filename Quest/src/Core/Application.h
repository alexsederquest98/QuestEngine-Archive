#pragma once

#include <string>

#include "Base.h"

// This forward dec of main is so that I can set it as a friend to the Application class.
// Since main is a friend, I can call the private Run() function from main and only main.
int main(int argc, char** argv);

namespace Quest
{
	class Application
	{
	public:
		struct ApplicationSpecification
		{
			std::string AppName;
			int ArgCount = 0;
			char** Arguments = nullptr;

			// Allow indexing the struct to get arguments
			const char* operator[](int index) const
			{
				QE_CORE_ASSERT(index < ArgCount);
				return Arguments[index];
			}
		};

		Application(ApplicationSpecification spec);
		~Application();

		void Close();
	private:
		void Run();
	private:
		bool m_Running = true;

		// Only allow 1 application to exist
		static bool s_Instantiated;
		friend int ::main(int argc, char** argv);
	};

	// Defined in the client
	UniquePointer<Application> CreateApplication(Application::ApplicationSpecification spec);
}