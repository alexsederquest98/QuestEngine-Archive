#include "qepch.h"
#include "Log.h"


namespace Quest
{
	SharedPointer<qlog::Logger> Log::s_CoreLogger = CreateSharedPointer<qlog::Logger>();
	SharedPointer<qlog::Logger> Log::s_ClientLogger = CreateSharedPointer<qlog::Logger>();


	void Log::Init()
	{
		s_CoreLogger->Init();
		s_CoreLogger->SetName("Quest");
		s_CoreLogger->Log(qlog::Logger::LogLevel::INFO, "Quest Logger Initialized.");

		s_ClientLogger->Init();
		s_ClientLogger->SetName("Client");
		s_ClientLogger->Log(qlog::Logger::LogLevel::INFO, "Client Logger Initialized.");
	}
}