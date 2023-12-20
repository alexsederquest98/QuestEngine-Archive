#include "qepch.h"
#include "Log.h"


namespace Quest
{
	RefPtr<qlog::Logger> Log::s_CoreLogger = CreateRef<qlog::Logger>();
	RefPtr<qlog::Logger> Log::s_ClientLogger = CreateRef<qlog::Logger>();


	void Log::Init()
	{
		s_CoreLogger->Init();
		s_CoreLogger->SetName("Quest");
		s_CoreLogger->SetFileName("QuestCore.qlog");
		s_CoreLogger->SetFileLogging(true);
		s_CoreLogger->Log(qlog::Logger::LogLevel::CRITICAL, "Quest Logger Initialized.");

		s_ClientLogger->Init();
		s_ClientLogger->SetName("Client");
		s_ClientLogger->SetFileName("QuestClient.qlog");
		s_ClientLogger->SetFileLogging(true);
		s_ClientLogger->Log(qlog::Logger::LogLevel::CRITICAL, "Client Logger Initialized.");
	}
}