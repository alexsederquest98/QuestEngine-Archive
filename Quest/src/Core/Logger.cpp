#include "qepch.h"
#include "Core/Logger.h"


namespace Quest
{
	std::shared_ptr<spdlog::logger> Logger::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ApplicationLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_EngineLogger = spdlog::stdout_color_mt("QUEST");
		s_EngineLogger->set_level(spdlog::level::trace);

		s_ApplicationLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ApplicationLogger->set_level(spdlog::level::trace);
	}
}