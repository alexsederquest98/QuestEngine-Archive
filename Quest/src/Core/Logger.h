#pragma once

#include "Base.h"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)


namespace Quest
{
	class Logger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetApplicationLogger() { return s_ApplicationLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
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