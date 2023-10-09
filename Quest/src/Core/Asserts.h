#include "Log.h"

#define QE_ENABLE_ASSERTS
#ifdef QE_ENABLE_ASSERTS
#define QE_CORE_ASSERT(expr)						\
	{													\
		if (!(expr))									\
		{												\
			QE_CORE_FATAL("Assertion failed at line {0} in {1}", __LINE__, __FILE__);		\
			QE_DEBUG_BREAK(); \
		}												\
	}

#define QE_CORE_ASSERT_MSG(expr, msg)							\
	{																\
		if (!(expr))												\
		{															\
			QE_CORE_FATAL("Assertion failed at line {0} in {1}: {2}", __LINE__, __FILE__, (msg));		\
			QE_DEBUG_BREAK(); \
		}															\
	}

#define QE_APP_ASSERT(expr)								\
	{													\
		if (!(expr))									\
		{												\
			QE_APP_FATAL("Assertion failed at line {0} in {1}", __LINE__, __FILE__);		\
			QE_DEBUG_BREAK(); \
		}												\
	}

#define QE_APP_ASSERT_MSG(expr, msg)								\
	{																\
		if (!(expr))												\
		{															\
			QE_APP_FATAL("Assertion failed at line {0} in {1}: {2}", __LINE__, __FILE__, (msg));		\
			QE_DEBUG_BREAK(); \
		}															\
	}

#else
#define QE_CORE_ASSERT(expr)
#define QE_CORE_ASSERT_MSG(expr, msg)
#define QE_APP_ASSERT(expr)
#define QE_APP_ASSERT_MSG(expr, msg)
#endif