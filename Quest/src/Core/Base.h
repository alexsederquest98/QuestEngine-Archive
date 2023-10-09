#pragma once
#include <iostream>

#include "QuestTypes.h"

#define QE_EXPAND_MACRO(x) x
#define QE_STRINGIFY_MACRO(x) #x

#if defined(_MSC_VER)
	#define QE_DEBUG_BREAK() __debugbreak()
#elif defined(__clang__)
	#define QE_DEBUG_BREAK() __builtin_debugtrap()
#else
	#define QE_DEBUG_BREAK()
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

#include "Log.h"
#include "Asserts.h"