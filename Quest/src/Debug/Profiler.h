#pragma once

// Set up some defines to toggle profiling later

#define QE_PROFILE_FRAME(...)
#define QE_PROFILE_FUNCTION(...)	
#define QE_PROFILE_THREAD(...)		
#define QE_PROFILE_TAG(NAME, ...)	


/*
	Use QE_PROFILE_FRAME() once in the main loop at the top to begin a capture frame
	Use QE_PROFILE_FUNCTION() as the main profiling macro. This can profile functions and scopes.
	Use QE_PROFILE_THREAD() for profiling different threads
	Use QE_PROFILE_TAG("name", var/constant) to profile the changes to a specific variable 
*/