#include "qepch.h"
#include "Core/Base.h"

void Quest::ABORT_EXECUTION()
{
	exit(0);
}

void Quest::ABORT_EXECUTION_MSG(std::string_view msg)
{
	//QE_CORE_CRITICAL("Quest is aborting execution: {0}", msg);
	exit(0);
}
