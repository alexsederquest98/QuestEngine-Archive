#pragma once
#include <iostream>

#include "QuestTypes.h"
#include "Logger.h"

#define QE_EXPAND_MACRO(x) x
#define QE_STRINGIFY_MACRO(x) #x

#if defined(_MSC_VER)
	#define QE_DEBUG_BREAK() __debugbreak()
#elif defined(__clang__)
	#define QE_DEBUG_BREAK() __builtin_debugtrap()
#else
	#define QE_DEBUG_BREAK()
#endif

#define QE_ENABLE_ASSERTS
#ifdef QE_ENABLE_ASSERTS
	#define QE_CORE_ASSERT(expr)						\
	{													\
		if (!(expr))									\
		{												\
			QE_CORE_CRITICAL("Assertion failed at line {0} in {1}", __LINE__, __FILE__);		\
			QE_DEBUG_BREAK(); \
		}												\
	}

	#define QE_CORE_ASSERT_MSG(expr, msg)							\
	{																\
		if (!(expr))												\
		{															\
			QE_CORE_CRITICAL("Assertion failed at line {0} in {1}: {2}", __LINE__, __FILE__, (msg));		\
			QE_DEBUG_BREAK(); \
		}															\
	}

	#define QE_APP_ASSERT(expr)								\
	{													\
		if (!(expr))									\
		{												\
			QE_APP_CRITICAL("Assertion failed at line {0} in {1}", __LINE__, __FILE__);		\
			QE_DEBUG_BREAK(); \
		}												\
	}

	#define QE_APP_ASSERT_MSG(expr, msg)								\
	{																\
		if (!(expr))												\
		{															\
			QE_APP_CRITICAL("Assertion failed at line {0} in {1}: {2}", __LINE__, __FILE__, (msg));		\
			QE_DEBUG_BREAK(); \
		}															\
	}

#else
	#define QE_CORE_ASSERT(expr)
	#define QE_CORE_ASSERT_MSG(expr, msg)
	#define QE_APP_ASSERT(expr)
	#define QE_APP_ASSERT_MSG(expr, msg)
#endif

namespace Quest
{
	// Smart pointer wrappers
	template <typename T>
	using SharedPointer = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr SharedPointer<T> CreateSharedPointer(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using UniquePointer = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr UniquePointer<T> CreateUniquePointer(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	void ABORT_EXECUTION();
	void ABORT_EXECUTION_MSG(std::string_view msg);
}