//---------------------------------------------------------------------------
#ifndef __CLOCK_H__
#define __CLOCK_H__
//---------------------------------------------------------------------------

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
#ifdef WIN32
#include <windows.h>
#endif

#include <SDL.h>
#include <sys/time.h>
#include "Error.h"

#ifdef _MSC_VER
  #pragma warning (push)
  #pragma warning (disable : 4244)
#endif


namespace JRFXGL
{ 
	namespace Util
	{


	//---------------
	// CLASSES
	//---------------


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Clock
	//
	//  Descrição:
	//     - Representa um relógio simples.
	//
	//

	class Clock
	{
	  public:
	  
		 Clock ();
		 
	  public:
	  
		 void reset ()
			{ 
			#ifdef WIN32
				mStartTime = 0;
				QueryPerformanceCounter((LARGE_INTEGER*) &mStartTime);
			#else
				gettimeofday(&mStartTime, NULL); 
			#endif
			}
			
		 float getMilliseconds () const
		 { 
			#ifdef WIN32
			 __int64 currentTime = 0;
			 QueryPerformanceCounter((LARGE_INTEGER*) &currentTime);
			 return (currentTime - mStartTime) * mCountsPerSecond * 1000.0f;
			#else
                         struct timeval t_time;
                         gettimeofday(&t_time, NULL);
			 return (float) (1000.0f * (float)(t_time.tv_sec - mStartTime.tv_sec)
                                      + (0.001f  * (float)(t_time.tv_usec - mStartTime.tv_usec)) ) * mTimeSpeed; 
			#endif
		 }
			
		 float getSeconds () const
			{ 
			#ifdef WIN32
			 __int64 currentTime = 0;
			 QueryPerformanceCounter((LARGE_INTEGER*) &currentTime);
			 return (currentTime - mStartTime) * mCountsPerSecond;
			#else
				return getMilliseconds () * 0.001f;
			#endif
			}		
		 
		 void setTimeSpeed (float speed)
			{ 
			#ifndef WIN32
				mTimeSpeed = speed; 
			#endif
			}		 

	  private:
	  
		#ifdef WIN32
		 float mCountsPerSecond;
		 __int64 mStartTime;	
		#else
		 struct timeval mStartTime;
		 float mTimeSpeed;
		#endif

	};	  


	} // end-namespace Util
} // end-namespace JRFXGL



#ifdef _MSC_VER
  #pragma warning (pop)  
#endif


//---------------------------------------------------------------------------
#endif

