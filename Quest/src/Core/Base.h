#pragma once
#include <iostream>

#include "Logger.h"

namespace Quest
{

}

#define QE_EXPAND_MACRO(x) x
#define QE_STRINGIFY_MACRO(x) #x

#define QE_ENABLE_ASSERTS
#ifdef QE_ENABLE_ASSERTS
	#define QE_CORE_ASSERT(expr)						\
	{													\
		if (!(expr))									\
		{												\
			QE_CORE_CRITICAL("Assertion failed.");		\
		}												\
	}

	#define QE_CORE_ASSERT_MSG(expr, msg)							\
	{																\
		if (!(expr))												\
		{															\
			QE_CORE_CRITICAL("Assertion failed. {0}", (msg));		\
		}															\
	}

#define QE_APP_ASSERT(expr)								\
	{													\
		if (!(expr))									\
		{												\
			QE_APP_CRITICAL("Assertion failed.");		\
		}												\
	}

#define QE_APP_ASSERT_MSG(expr, msg)								\
	{																\
		if (!(expr))												\
		{															\
			QE_APP_CRITICAL("Assertion failed. {0}", (msg));		\
		}															\
	}

#else

#endif