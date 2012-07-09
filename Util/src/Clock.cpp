/*---------------------------------------------------------------------------
// Clock
//
// Autor: Luis Valente
//
// Medição de tempo.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include "../inc/Clock.h"

namespace JRFXGL
{

	namespace Util
	{

	//---------------
	// CLASSES
	//---------------

	/**
	 *
	 */
	Clock::Clock ()
	{ 
		
	#ifdef WIN32
		 __int64 timeResolution = 0;
		 QueryPerformanceFrequency((LARGE_INTEGER*) &timeResolution);
		 mCountsPerSecond = 1.0f / (float) timeResolution;
	#else
		 mTimeSpeed = 1.0f;
	#endif
		reset (); 
	}



	} // end-namespace Sys
} // end-namespace Gluff

