#pragma once

#include "Base.h"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

// might be problematic
//#undef ERROR

namespace Quest
{
	class Logger
	{
	public:
		#pragma push_macro("ERROR")
		#undef ERROR // defined in Windows.h which I believe is included somewhere in spdlog

		enum class LogLevel
		{
			TRACE = 0, DEBUG, INFO, WARN, ERROR, CRITICAL
		};
		#pragma pop_macro("ERROR")


		static void Init();

		static void SetApplicationName(std::string_view name);
		static void SetCoreLogLevel(LogLevel level);
		static void SetApplicationLogLevel(LogLevel level);
		static void ResetCoreLogLevel();
		static void ResetApplicationLogLevel();
		static void SetLoggersToDefaults();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetApplicationLogger() { return s_ApplicationLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ApplicationLogger;
	};
}

// Engine logging macros
#define QE_CORE_TRACE(...) ::Quest::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define QE_CORE_DEBUG(...) ::Quest::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define QE_CORE_INFO(...) ::Quest::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define QE_CORE_WARN(...) ::Quest::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define QE_CORE_ERROR(...) ::Quest::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define QE_CORE_CRITICAL(...) ::Quest::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// Application logging macros
#define QE_APP_TRACE(...) ::Quest::Logger::GetApplicationLogger()->trace(__VA_ARGS__)
#define QE_APP_DEBUG(...) ::Quest::Logger::GetApplicationLogger()->debug(__VA_ARGS__)
#define QE_APP_INFO(...) ::Quest::Logger::GetApplicationLogger()->info(__VA_ARGS__)
#define QE_APP_WARN(...) ::Quest::Logger::GetApplicationLogger()->warn(__VA_ARGS__)
#define QE_APP_ERROR(...) ::Quest::Logger::GetApplicationLogger()->error(__VA_ARGS__)
#define QE_APP_CRITICAL(...) ::Quest::Logger::GetApplicationLogger()->critical(__VA_ARGS__)