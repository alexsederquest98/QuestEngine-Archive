#include "qepch.h"
#include "Core/Logger.h"


namespace Quest
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ApplicationLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("QUEST");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ApplicationLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ApplicationLogger->set_level(spdlog::level::trace);
	}

	void Logger::SetApplicationName(std::string_view name)
	{
		s_ApplicationLogger = spdlog::stdout_color_mt(name.data());
	}

	void Logger::SetCoreLogLevel(LogLevel level)
	{
		#pragma push_macro("ERROR")
		#undef ERROR // defined in Windows.h which I believe is included somewhere in spdlog
		switch (level)
		{
		case LogLevel::TRACE:		s_CoreLogger->set_level(spdlog::level::trace); break;
		case LogLevel::DEBUG:		s_CoreLogger->set_level(spdlog::level::debug); break;
		case LogLevel::INFO:		s_CoreLogger->set_level(spdlog::level::info); break;
		case LogLevel::WARN:		s_CoreLogger->set_level(spdlog::level::warn); break;
		case LogLevel::ERROR:		s_CoreLogger->set_level(spdlog::level::err); break;
		case LogLevel::CRITICAL:	s_CoreLogger->set_level(spdlog::level::critical); break;
		}
		#pragma pop_macro("ERROR")
	}

	void Logger::SetApplicationLogLevel(LogLevel level)
	{
		#pragma push_macro("ERROR")
		#undef ERROR // defined in Windows.h which I believe is included somewhere in spdlog
		switch (level)
		{
		case LogLevel::TRACE:		s_ApplicationLogger->set_level(spdlog::level::trace); break;
		case LogLevel::DEBUG:		s_ApplicationLogger->set_level(spdlog::level::debug); break;
		case LogLevel::INFO:		s_ApplicationLogger->set_level(spdlog::level::info); break;
		case LogLevel::WARN:		s_ApplicationLogger->set_level(spdlog::level::warn); break;
		case LogLevel::ERROR:		s_ApplicationLogger->set_level(spdlog::level::err); break;
		case LogLevel::CRITICAL:	s_ApplicationLogger->set_level(spdlog::level::critical); break;
		}
		#pragma pop_macro("ERROR")
	}

	void Logger::ResetCoreLogLevel()
	{
		s_CoreLogger->set_level(spdlog::level::trace);
	}

	void Logger::ResetApplicationLogLevel()
	{
		s_ApplicationLogger->set_level(spdlog::level::trace);
	}

	void Logger::SetLoggersToDefaults()
	{
		s_CoreLogger = spdlog::stdout_color_mt("QUEST");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ApplicationLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ApplicationLogger->set_level(spdlog::level::trace);
	}
}