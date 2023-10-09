#pragma once

#include "Base.h"
#include "Utility/Logger/Logger.h"

namespace Quest
{
	class Log
	{
	public:
		static void Init();

		inline static SharedPointer<qlog::Logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static SharedPointer<qlog::Logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static SharedPointer<qlog::Logger> s_CoreLogger;
		static SharedPointer<qlog::Logger> s_ClientLogger;
	};
}

// Engine logging macros
// #define QE_CORE_TRACE(...) ::Quest::Logger::GetCoreLogger()->trace(__VA_ARGS__)
// #define QE_CORE_DEBUG(...) ::Quest::Logger::GetCoreLogger()->debug(__VA_ARGS__)
// #define QE_CORE_INFO(...) ::Quest::Logger::GetCoreLogger()->info(__VA_ARGS__)
// #define QE_CORE_WARN(...) ::Quest::Logger::GetCoreLogger()->warn(__VA_ARGS__)
// #define QE_CORE_ERROR(...) ::Quest::Logger::GetCoreLogger()->error(__VA_ARGS__)
// #define QE_CORE_CRITICAL(...) ::Quest::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// // Application logging macros
// #define QE_APP_TRACE(...) ::Quest::Logger::GetApplicationLogger()->trace(__VA_ARGS__)
// #define QE_APP_DEBUG(...) ::Quest::Logger::GetApplicationLogger()->debug(__VA_ARGS__)
// #define QE_APP_INFO(...) ::Quest::Logger::GetApplicationLogger()->info(__VA_ARGS__)
// #define QE_APP_WARN(...) ::Quest::Logger::GetApplicationLogger()->warn(__VA_ARGS__)
// #define QE_APP_ERROR(...) ::Quest::Logger::GetApplicationLogger()->error(__VA_ARGS__)
// #define QE_APP_CRITICAL(...) ::Quest::Logger::GetApplicationLogger()->critical(__VA_ARGS__)

// Engine Logging Macros
#define QE_CORE_FATAL(...) ::Quest::Log::GetCoreLogger()->Log(qlog::Logger::LogLevel::FATAL, __VA_ARGS__);
#define QE_CORE_ERROR(...) ::Quest::Log::GetCoreLogger()->Log(qlog::Logger::LogLevel::ERROR, __VA_ARGS__);
#define QE_CORE_WARN(...) ::Quest::Log::GetCoreLogger()->Log(qlog::Logger::LogLevel::WARN, __VA_ARGS__);
#define QE_CORE_INFO(...) ::Quest::Log::GetCoreLogger()->Log(qlog::Logger::LogLevel::INFO, __VA_ARGS__);
#define QE_CORE_DEBUG(...) ::Quest::Log::GetCoreLogger()->Log(qlog::Logger::LogLevel::DEBUG, __VA_ARGS__);
#define QE_CORE_TRACE(...) ::Quest::Log::GetCoreLogger()->Log(qlog::Logger::LogLevel::TRACE, __VA_ARGS__);

// Client Logging Macros
#define QE_FATAL(...) ::Quest::Log::GetClientLogger()->Log(qlog::Logger::LogLevel::FATAL, __VA_ARGS__);
#define QE_ERROR(...) ::Quest::Log::GetClientLogger()->Log(qlog::Logger::LogLevel::ERROR, __VA_ARGS__);
#define QE_WARN(...) ::Quest::Log::GetClientLogger()->Log(qlog::Logger::LogLevel::WARN, __VA_ARGS__);
#define QE_INFO(...) ::Quest::Log::GetClientLogger()->Log(qlog::Logger::LogLevel::INFO, __VA_ARGS__);
#define QE_DEBUG(...) ::Quest::Log::GetClientLogger()->Log(qlog::Logger::LogLevel::DEBUG, __VA_ARGS__);
#define QE_TRACE(...) ::Quest::Log::GetClientLogger()->Log(qlog::Logger::LogLevel::TRACE, __VA_ARGS__);