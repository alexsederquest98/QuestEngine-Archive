#include "qepch.h"
#include "Log.h"


namespace Quest
{
	Ref<qlog::Logger> Log::s_CoreLogger = CreateRef<qlog::Logger>();
	Ref<qlog::Logger> Log::s_ClientLogger = CreateRef<qlog::Logger>();


	void Log::Init()
	{
		s_CoreLogger->Init();
		s_CoreLogger->SetName("Quest");
		s_CoreLogger->Log(qlog::Logger::LogLevel::CRITICAL, "Quest Logger Initialized.");

		s_ClientLogger->Init();
		s_ClientLogger->SetName("Client");
		s_ClientLogger->Log(qlog::Logger::LogLevel::CRITICAL, "Client Logger Initialized.");
	}
}