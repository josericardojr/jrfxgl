//---------------------------------------------------------------------------
#ifndef __FRAMECOUNTER_H__
#define __FRAMECOUNTER_H__
//---------------------------------------------------------------------------

/*---------------------------------------------------------------------------
// FrameCounter
//
// Autor: Luis Valente
//
// Medição de desempenho.
//
// ------------------------ */

//---------------
// INCLUDES
//---------------
#include <climits>
#include <iostream>
#include <string>

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
	//  FrameCounter
	//
	//  Descrição:
	//     - Representa um contador de quadros por segundo.
	//
	//


	class FrameCounter
	{
	  public:
	  
		 FrameCounter ();
		 
	  public:
	  
		// Reiniciar o contador
		void reset ()
		 { mClock.reset (); mTotalTime = mNumSamples = 0.0f; mCounter = mTotalFps = mCurrentFps = mBestFps = 0; mWorstFps = INT_MAX; }
			
			
		// Atualizar o contador, deve ser chamado toda vez em que se quiser marcar
		// um quadro
		void update ()
		{ 
		  mTotalTime += mClock.getMilliseconds ();
		  mCounter++;

		  if (mTotalTime >= 1000.0f)
		  {
			mCurrentFps = mCounter;
			mCounter   = 0;
			mTotalTime = 0.0f;

			if (mCurrentFps > mBestFps)
			mBestFps = mCurrentFps;

			if (mCurrentFps < mWorstFps && mCurrentFps > 1)
			mWorstFps = mCurrentFps;

			mTotalFps += mCurrentFps;
			mNumSamples++;
		  }


		  mClock.reset ();		
		}
			
		 
			
		 // Retornar o total de quadros por segundo calculado
		 int getFramesPerSecond ()
			{ return mCurrentFps; }
			
		 int getBestFps ()
			{ return mBestFps; }
			
		 int getWorstFps ()
			{ return mWorstFps; }  				
			
		 float getAverageFps ()
			{ return mNumSamples == 0 ? 0.0f : mTotalFps / mNumSamples; }
			
	  private:  
		 
		 float mTotalTime;
		 int   mCounter;
		 int   mCurrentFps;
		 
		 int   mBestFps;
		 int   mWorstFps;
		 
		 int    mTotalFps;
		 float  mNumSamples;
		 
		 Clock mClock;
		 

				
	};




	} // end-namespace Util

} // end-namespace JRFXGL

//---------------------------------------------------------------------------
#endif

