//---------------------------------------------------------------------------
#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// Stopwatch
//
// Autor: Luis Valente
//
// Medição de tempo.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include "Clock.h"

namespace JRFXGL
{

	namespace Util
	{


	//---------------
	// CLASSES
	//---------------


	/////////////////////////////////////////////////////////////////////////////////////
	//
	//  Stopwatch
	//
	//  Descrição:
	//     - Representa um cronômetro simples.
	//
	//

	class Stopwatch
	{
	  public:
	  
		 Stopwatch ();
		 
	  public:
	  
		void reset ()
		  { mClock.reset (); mElapsedTime = 0; mIsPaused = false; }	 

		 
		float getElapsedSeconds () const 
		  { return getElapsedMilliseconds () * 0.001f ; }


		float getElapsedMilliseconds () const 
		{
			if (mIsPaused)
				return mElapsedTime;
			else
				return mElapsedTime + mClock.getMilliseconds ();	
		}
		
		 
		void start ()
		 { mIsPaused = false; }
		 

		void pause ()
		{
		  if (mIsPaused == false)
			mElapsedTime += mClock.getMilliseconds ();

		  mIsPaused  = true;		 
		}
		
		void resume ()
		  { mIsPaused = false; mClock.reset (); }

		
		void setTime (float time)
		  { mElapsedTime = time ; mClock.reset (); }

		 
		void setTimeSpeed (float speed)
		  { mClock.setTimeSpeed (speed); }
		  
		bool isPaused () const
		 { return mIsPaused; }

	  private:

		 Clock mClock;
		 float mElapsedTime;		 
		 bool  mIsPaused;
		 
	};	  


	} // end-namespace Util
} // end-namespace JRFXGL


//---------------------------------------------------------------------------
#endif


