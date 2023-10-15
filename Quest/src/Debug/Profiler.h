#pragma once

// Set up some defines to toggle profiling later
#include <optick.h>

#define QE_PROFILE_FRAME(...)		OPTICK_FRAME(__VA_ARGS__)
#define QE_PROFILE_FUNCTION(...)	OPTICK_EVENT(__VA_ARGS__)
#define QE_PROFILE_THREAD(...)		OPTICK_THREAD(__VA_ARGS__)
#define QE_PROFILE_TAG(NAME, ...)	OPTICK_TAG(NAME, __VA_ARGS__)


/*
	Use QE_PROFILE_FRAME() once in the main loop at the top to begin a capture frame
	Use QE_PROFILE_FUNCTION() as the main profiling macro. This can profile functions and scopes.
	Use QE_PROFILE_THREAD() for profiling different threads
	Use QE_PROFILE_TAG("name", var/constant) to profile the changes to a specific variable 
*/